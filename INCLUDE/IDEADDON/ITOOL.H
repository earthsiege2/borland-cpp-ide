/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

  itool.h
  Created: 09/27/95
  Copyright (c) 1995, Borland International
  $Revision:   1.15  $

  Tool Interface

  This interface is one of several being brought forward from BC4.x IdeHook
  interface. 
  
  There are a few changes: 

  The "ToolInfo" struct has been replaced with an interface, IToolInfo.

  The major change in the Tool interface involves a new mechanism for 
  registering tool entry points for non-standalone tools. Instead of 
  submitting an array of entry points that are methods on your derived
  'ToolClient' class, you now derive a class from IToolImplementor for 
  each of this kind of tool and register a pointer to it using the
  'SetImplementor' method of the IToolInfo interface. This and the other
  IToolInfo information you provide is then submitted to IToolServer through
  its 'ToolAdd' method.

  PolyStrings are used instead of char pointers.

  For other minor changes, see 'IDEHOOK CHANGES' comments.
   
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/  

#ifndef __ITOOL_H
#define __ITOOL_H

#include <objbase.h>
#include <ideaddon\common.h>
#include <ideaddon\ipolystr.h>
#include <ideaddon\itool.uid>
#include <ideaddon\itoolinf.uid>
#include <ideaddon\itoolexe.uid>

enum ToolLaunchType
{
  //
  // 'StandAlone' refers to tools that run as seperate tasks and 'Callback'
  // refers to tools that are launched through the 'IToolImplementor::Execute'
  // Method (See IToolImplementor, below).
  //
  TLT_StandAlone,  
  TLT_Callback  = -1
};

enum ToolTypes
{
   TT_UserBase = -6,
   TT_DepChecker,
   TT_Transfer,
   TT_Viewer,
   TT_Translator
};

#define TIFlag_TargetTranslator   0x00000001L
#define TIFlag_ReadOnly        0x00000100L     // tool can't be renamed or removed
#define TIFlag_OnLocalMenu       0x00001000L
#define TIFlag_OnToolsMenu       0x00002000L

enum ToolReturn 
{
    TR_NotHandled = -1,
    TR_Success, 
    TR_Warnings, 
    TR_Errors, 
    TR_FatalError 
};


//.............................................................................
//
// IToolImplementor
// 
// Derive a class from this interface for each tool for which you wish to 
// register an entry point. The entry point will be the 'Execute' method.
// 
// Use the 'SetImplementor' method of IToolInfo to register your 
// IToolImplementor interface with IToolServer through its 'AddTool' method.
// 
// Warning! Please see the warning in ISCRIPT.H concerning calling through the 
// IScriptServer interface from within the IToolImplementor::Execute() method. 
//
//.............................................................................
class IToolImplementor : public IUnknown 
{
 public:
  virtual ToolReturn Execute( 
                IPolyString * cmdLine, 
                ProjectNode * nodeArray, 
                int numNodes ) = 0;
};

//.............................................................................
class IToolInfo : public IUnknown
{
 public:
  virtual ToolTypes GetTypes() = 0;
  virtual void SetTypes( ToolTypes types ) = 0;

  virtual IPolyString * GetName() = 0;
  virtual void SetName( IPolyString * name ) = 0;

  virtual IPolyString * GetPath() = 0;
  virtual void SetPath( IPolyString * path ) = 0;

  virtual unsigned GetFlags() = 0;
  virtual void SetFlags( unsigned flags ) = 0;

  virtual IPolyString * GetMenuName() = 0;
  virtual void SetMenuName( IPolyString * menuName ) = 0;

  virtual IPolyString * GetHelpHint() = 0;
  virtual void SetHelpHint( IPolyString * helpHint ) = 0;

  virtual IPolyString * GetDefCmdLine() = 0;
  virtual void SetDefCmdLine( IPolyString * defCmdLine ) = 0;
  
  //
  // IDEHOOK CHANGES:
  // - This was a union of 'appliesTo' and 'translateFrom' in 'ToolInfo'
  //
  virtual IPolyString * GetSupportedTypes() = 0;
  virtual void SetSupportedTypes( IPolyString * supported ) = 0;

  //
  // 'DefaultFor' objects will use this tool as the default tool.
  // e.g. ".c;.cpp"
  //
  virtual IPolyString * GetDefaultForTypes() = 0;
  virtual void SetDefaultForTypes( IPolyString * defaultForTypes ) = 0;

  virtual IPolyString * GetTranslateTo() = 0;
  
  //
  // SetTranslateTo()
  // Tip: Don't stick a semi-colon at the end of the translateTo file
  // type or the ide's make engine will not properly recognize the existence
  // of the output file.
  //
  virtual void SetTranslateTo( IPolyString * translateTo ) = 0;

  //
  // IDEHOOK_CHANGES:
  // - This used to be called a ToolLaunchId
  //
  virtual ToolLaunchType GetLaunchType() = 0;

  virtual void SetImplementor( IToolImplementor * implementor ) = 0;
  virtual IToolImplementor * GetImplementor( void ) = 0; 
};



//.............................................................................
// 
// IToolServer
//
// IDEHOOK CHANGES:
// -  'ToolRegisterImplementor' is no longer provided. See 'SetImplementor'
//   in the IToolInfo interface definition above.
// -  New Methods: 
//     'CreateToolInfoInstance'
//
//.............................................................................
class IToolServer : public IUnknown 
{

 public:
  //
  // The caller of 'CreateToolInfoInstance' is responsible for calling
  // IToolInfo's 'Release' method when the interface is no longer needed.
  //
  virtual IToolInfo * CreateToolInfoInstance() = 0;

  //
  // Install a tool into the user's project
  // 
  // IDEHOOK CHANGES:
  // -  Now takes an IToolInfo pointer instead of a ToolInfo struct. Use 
  //   'CreateToolInfoInstance' to get an IToolInfo pointer. You can re-use 
  //   the IToolInfo object for subsequent 'ToolAdd' calls before 
  //   'Release'ing it if you like ('ToolAdd' will not reset its properties
  //   to default settings, however).
  //
  //  Use ToolAdd to update an existing tool with new information such
  //  as new paths, new implementor, etc..
  //
  //  Now returns the ToolObj of the tool if the operation was successful
  //  or 0 if not.
  //
  virtual ToolObj ToolAdd( IToolInfo * toolInfo ) = 0;

  //
  // Query the existance of a tool in the current project
  //
  virtual ToolObj ToolFind( IPolyString * name ) = 0;

  //
  // Remove a tool from the current project
  //
  // IDEHOOK_CHANGES:
  // -  Now takes a ToolObj instead of a name string. This used to do the 
  //   equivelant of a call to 'ToolFind' for every call to this method,
  //   so now, call 'ToolFind' first if you don't already have the ToolObj.
  // 
  virtual void ToolRemove( ToolObj tool ) = 0;

  //
  // Query the detailed information of a tool
  //
  // IDEHOOK CHANGES:
  // -  Now returns an IToolInfo pointer instead of taking a reference to
  //   a ToolInfo struct. The caller is responsible for calling 'Release'
  //   on through the IToolInfo pointer when it is no longer needed.
  // 
  virtual IToolInfo * QueryToolInfo( ToolObj ) = 0;

  //                                         
  // Invoke any tool in the IDE. If 'ProjectNode' is zero, the  
  // tool is invoked on the 'currently selected object' in the  
  // IDE, as determined by the IDE.                   
  //                                         
  virtual ToolReturn ToolInvoke( 
                  ToolObj, 
                  ProjectNode = 0,
                  IPolyString * cmdLineOverride = NULL ) = 0;

  
  //
  // This version of 'ToolInvoke' takes a file name instead of a project
  // node.
  //
  virtual ToolReturn ToolInvokeName(
                   ToolObj, 
                   IPolyString * fileName,
                   IPolyString * cmdLineOverride = 0 ) = 0;

};




#endif // __ITOOL_H
