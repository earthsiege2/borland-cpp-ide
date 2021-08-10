//----------------------------------------------------------------------------
// IdeHook - (C) Copyright 1994 by Borland International
//----------------------------------------------------------------------------
#ifndef __IDEHOOKT_H
#define __IDEHOOKT_H

#ifndef __STDDEF_H
#  include <stddef.h>
#endif


//  Some generic defines and types

#ifndef _UNIQUE_COOKIE
#  define _UNIQUE_COOKIE(name)    typedef const struct name##__ _near* name
#  define _UNIQUE_COOKIE32(name)  typedef const struct name##__ _far* name
#endif

#define _HOOKCLASS _huge
#define _HOOKEP	   _pascal _loadds


//  Tool enums and helper structs

_UNIQUE_COOKIE32( ToolObj );         // ToolObj is not persistent
_UNIQUE_COOKIE32( ToolLaunchId );
_UNIQUE_COOKIE32( ProjectNode );     // ProjectNode is persistent

#define DEFAULT_LAUNCH_ID  ToolLaunchId(0)
#define CALLBACK_LAUNCH_ID ToolLaunchId(-1)

enum ToolTypes
{
    Transfer = -4,
    Viewer,
    Translator,
};

enum ToolFlags
{
    TargetTranslator = 0x0001,
    OnLocalMenu      = 0x1000,
    OnToolsMenu      = 0x2000,
};

struct ToolInfo
{
    ToolTypes        toolType;
    const char *     name;
    const char *     path;
    ToolFlags        flags;
    const char *     menuName;
    const char *     helpHint;
    const char *     defCmdLine;
    union {
        const char *appliesTo;
        const char *translateFrom;
        };
    const char *    defaultFor;
    const char *    translateTo;
    ToolLaunchId    launchId;
};
    
enum ToolReturn 
{
     NotHandled = -1,
     Success, 
     Warnings, 
     Errors, 
     FatalError 
};

class _HOOKCLASS ToolClient;

struct ToolInvokeArgs
{
    const char * cmdLine;
    ProjectNode *nodeArray;
    int          numNodes;
};

typedef ToolReturn _HOOKEP 
                (ToolClient::*ToolMethod)( ToolInvokeArgs * );

struct ToolRegisterPack
{
    const char *      toolName;
    ToolMethod          toolMethod;
    unsigned long     resv1;
};


//  Project helper types

struct ProjectNodeInfo
{
    const char *    name;
    const char *    nodeType;
    const char *    description;
    const char *    inputLocation;
    const char *    outputLocation;
    ProjectNode     parent;
    ProjectNode     firstChild;
    ProjectNode     nextSibling;
};

//  Option set ids

enum OptionsStringIds
{
    OID_null,
    OID_RemoveAll = OID_null,
    OID_Include,
    OID_Library,
    OID_Source,
    OID_Intermediate,
    OID_Final,
    OID_Defines,
    OID_CmdlineOverride,

    OID_Invalid
};


//  Target expert types

enum TargetPlatforms
{
    Win16       =     0x0001,
    Win32       =     0x0002,
    Dos16       =     0x0008,
    DosOverlay  =     0x0010,
};

enum TargetStdLibs
{
    Framework = 0x0001,
    RTL       = 0x0004,
    BIDS      = 0x0002,
    OWL       = Framework,
    BWCC      = 0x0008,
    BGI       = BWCC,

    FloatingMath    = 0x0010,
    FloatingEmu     = 0x0020,
    FloatingStartup = 0x0040,

    Static          = 0x0100,
    Dynamic         = 0x0200,

    MultiThread     = 0x2000,

    Diagnostic      = 0x8000,
};

enum TargetModel
{
    Tiny     = 0x01,
    Small    = 0x02,
    Medium   = 0x04,
    Compact  = 0x08,
    Large    = 0x10,
    Huge     = 0x20,

    GUI      = 0x0100,
    Console  = 0x0200
};


//  Make stuff

enum MakeMode
{
    Make,
    Build,
    Translate
};

//  Editor stuff

_UNIQUE_COOKIE32( BufferId );
_UNIQUE_COOKIE32( ViewId   );

struct KeyStroke;

typedef int (*KeyHitHandler)(KeyStroke *);

enum KeyModifier
{
   NoModifier,
   Shift   = 0x0001,
   Control = 0x0002,
   Alt     = 0x0004
};

struct KeyStroke
{
    unsigned short  msg;
    unsigned short  key;
    KeyModifier     modifier;
    KeyHitHandler   handler;
};

#endif  __IDEHOOKT_H

// End of file

