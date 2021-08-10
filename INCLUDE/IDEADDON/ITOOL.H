/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

   itool.h
   Created: 09/27/95
   Copyright (c) 1995, Borland International
   $Header:   Y:/ADMIN/BRIDE/ADDON/DELIVER/INTERFAC/ITOOL.H_V   1.22   16 Jan 1997 14:47:32   JDOUGLAS  $
   $Revision:   1.22  $

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
#include <ideaddon\istatus.h>
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
   TLT_Callback = -1
};

enum ToolTypes
{
    TT_UserBase = -6,
         TT_DepChecker,
    TT_Transfer,
    TT_Viewer,
    TT_Translator
};

#define TIFlag_TargetTranslator     0x00000001L
#define TIFlag_ReadOnly             0x00000100L       // tool can't be renamed or removed
#define TIFlag_OnLocalMenu          0x00001000L
#define TIFlag_OnToolsMenu          0x00002000L
#define TIFlag_OnFileOpenMenu       0x00010000L
#define TIFlag_OnFileNewMenu        0x00020000L

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
   virtual ToolReturn BCWADDON_CMETHOD Execute(
                        IPolyString * cmdLine,
                        ProjectNode * nodeArray,
                        int numNodes ) = 0;
};

//.............................................................................
class IToolInfo : public IUnknown
{
 public:
   virtual ToolTypes BCWADDON_CMETHOD GetTypes() = 0;
   virtual void BCWADDON_CMETHOD SetTypes( ToolTypes types ) = 0;

   virtual IPolyString * BCWADDON_CMETHOD GetName() = 0;
   virtual void BCWADDON_CMETHOD SetName( IPolyString * name ) = 0;

   virtual IPolyString * BCWADDON_CMETHOD GetPath() = 0;
   virtual void BCWADDON_CMETHOD SetPath( IPolyString * path ) = 0;

   virtual unsigned BCWADDON_CMETHOD GetFlags() = 0;
   virtual void BCWADDON_CMETHOD SetFlags( unsigned flags ) = 0;

   virtual IPolyString * BCWADDON_CMETHOD GetMenuName() = 0;
   virtual void BCWADDON_CMETHOD SetMenuName( IPolyString * menuName ) = 0;

   virtual IPolyString * BCWADDON_CMETHOD GetHelpHint() = 0;
   virtual void BCWADDON_CMETHOD SetHelpHint( IPolyString * helpHint ) = 0;

   virtual IPolyString * BCWADDON_CMETHOD GetDefCmdLine() = 0;
   virtual void BCWADDON_CMETHOD SetDefCmdLine( IPolyString * defCmdLine ) = 0;

   //
   // IDEHOOK CHANGES:
   // - This was a union of 'appliesTo' and 'translateFrom' in 'ToolInfo'
   //
   virtual IPolyString * BCWADDON_CMETHOD GetSupportedTypes() = 0;
   virtual void BCWADDON_CMETHOD SetSupportedTypes( IPolyString * supported ) = 0;

   //
   // 'DefaultFor' objects will use this tool as the default tool.
   // e.g. ".c;.cpp"
   //
   virtual IPolyString * BCWADDON_CMETHOD GetDefaultForTypes() = 0;
   virtual void BCWADDON_CMETHOD SetDefaultForTypes( IPolyString * defaultForTypes ) = 0;

   virtual IPolyString * BCWADDON_CMETHOD GetTranslateTo() = 0;

   //
   // SetTranslateTo()
   // Tip: Don't stick a semi-colon at the end of the translateTo file
   // type or the ide's make engine will not properly recognize the existence
   // of the output file.
   //
   virtual void BCWADDON_CMETHOD SetTranslateTo( IPolyString * translateTo ) = 0;

   //
   // IDEHOOK_CHANGES:
   // - This used to be called a ToolLaunchId
   //
   virtual ToolLaunchType BCWADDON_CMETHOD GetLaunchType() = 0;

   virtual void BCWADDON_CMETHOD SetImplementor( IToolImplementor * implementor ) = 0;
   virtual IToolImplementor * BCWADDON_CMETHOD GetImplementor( void ) = 0;
};


//
// flags for SetDependencyChekerID
//
#define MAKE_DEP_Collector  2
#define MAKE_DEP_Auto       3
#define MAKE_DEP_TimeStamp  4
#define MAKE_DEP_Child      7

//
// An IToolInfo2 pointer can be received through QueryInterface() on the
// IToolInfo pointer returned from IToolServer::QueryToolInfo().
// IToolInfo2 supports the IToolInfo methods plus two new ones.
//
class IToolInfo2 : IToolInfo {
 public:
   //
   // Use SetDependencyCheckerID to change set the dependency checking scheme
   // for a tool you are about to add using IToolServer::ToolAdd()
   //
   virtual void BCWADDON_CMETHOD SetDependencyCheckerID( int id ) = 0;
   //
   // Reserved for future use...
   //
   virtual int BCWADDON_CMETHOD GetDependencyCheckerID() = 0;
};


//
// Addon's can use this interface to retrieve an interface to the status dialog
// while a tool is being invoked. Call this from IToolImplementor::Execute function.
//

class IToolInfo3 : public IToolInfo2
{
  public:
    virtual IStatusDialog* BCWADDON_CMETHOD GetStatusDialog() = 0;
};


//.............................................................................
//
// IToolServer
//
// IDEHOOK CHANGES:
// -  'ToolRegisterImplementor' is no longer provided. See 'SetImplementor'
//    in the IToolInfo interface definition above.
// -  New Methods:
//       'CreateToolInfoInstance'
//
//.............................................................................
class IToolServer : public IUnknown
{

 public:
   //
   // The caller of 'CreateToolInfoInstance' is responsible for calling
   // IToolInfo's 'Release' method when the interface is no longer needed.
   //
   virtual IToolInfo * BCWADDON_CMETHOD CreateToolInfoInstance() = 0;

   //
   // Install a tool into the user's project
   //
   // IDEHOOK CHANGES:
   // -  Now takes an IToolInfo pointer instead of a ToolInfo struct. Use
   //    'CreateToolInfoInstance' to get an IToolInfo pointer. You can re-use
   //    the IToolInfo object for subsequent 'ToolAdd' calls before
   //    'Release'ing it if you like ('ToolAdd' will not reset its properties
   //    to default settings, however).
   //
   //  Use ToolAdd to update an existing tool with new information such
   //  as new paths, new implementor, etc..
   //
   //  Now returns the ToolObj of the tool if the operation was successful
   //  or 0 if not.
   //
   virtual ToolObj BCWADDON_CMETHOD ToolAdd( IToolInfo * toolInfo ) = 0;

   //
   // Query the existance of a tool in the current project
   //
   virtual ToolObj BCWADDON_CMETHOD ToolFind( IPolyString * name ) = 0;

   //
   // Remove a tool from the current project
   //
   // IDEHOOK_CHANGES:
   // -  Now takes a ToolObj instead of a name string. This used to do the
   //    equivelant of a call to 'ToolFind' for every call to this method,
   //    so now, call 'ToolFind' first if you don't already have the ToolObj.
   //
   virtual void BCWADDON_CMETHOD ToolRemove( ToolObj tool ) = 0;

   //
   // Query the detailed information of a tool
   //
   // IDEHOOK CHANGES:
   // -  Now returns an IToolInfo pointer instead of taking a reference to
   //    a ToolInfo struct. The caller is responsible for calling 'Release'
   //    on through the IToolInfo pointer when it is no longer needed.
   //
   virtual IToolInfo * BCWADDON_CMETHOD QueryToolInfo( ToolObj ) = 0;

   //
   // Invoke any tool in the IDE. If 'ProjectNode' is zero, the
   // tool is invoked on the 'currently selected object' in the
   // IDE, as determined by the IDE.
   //
   virtual ToolReturn BCWADDON_CMETHOD ToolInvoke(
                           ToolObj,
                           ProjectNode = 0,
                           IPolyString * cmdLineOverride = NULL ) = 0;


   //
   // This version of 'ToolInvoke' takes a file name instead of a project
   // node.
   //
   virtual ToolReturn BCWADDON_CMETHOD ToolInvokeName(
                            ToolObj,
                            IPolyString * fileName,
                            IPolyString * cmdLineOverride = 0 ) = 0;

};




#endif // __ITOOL_H
