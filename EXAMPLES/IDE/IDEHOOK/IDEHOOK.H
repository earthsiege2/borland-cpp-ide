//----------------------------------------------------------------------------
// IdeHook - (C) Copyright 1994 by Borland International
//----------------------------------------------------------------------------

///////////////////////////////////////////////////////////////////////
//  IdeHook can be used to customize and enhance the functionality
//  of the Borland C++ Integrated Development Environment.
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
//  FEATURE OVERVIEW:
///////////////////////////////////////////////////////////////////////
//
//  With IdeHook.h (and the accompanying .obj file) users can
//  incorporate many powerful features seamlessly into the IDE.
//  For example:
//      1) Install tools onto the 'Tools' menu
//      2) Install tools onto the SpeedMenu of specific node types
//      3) Provide an implementation of tools through call-backs into a .DLL
//      4) Monitor IDE events (such as Project Open and Close) and
//          perform customized actions on these events
//
//  IdeHook gives users access to the following areas of the IDE:
//
//  1)  Tool Server      Lets you install, query and invoke
//                          any tool in the IDE.
//  2)  Project Manager  Gives you full access to the dependency tree
//                          of the currently open project, including the
//                          ability to add new nodes, query the tree, and
//                          get and set persistent properties in the project.
//  3)  TargetExpert     Allows callers to create and query targets
//                          on any platform.
//  4)  StyleSheets      Gives access to the setting and getting of
//                          options on any node in the project tree.
//  5)  Make             Gives access to the make engine, including
//                          make notifications.
//
///////////////////////////////////////////////////////////////////////
//  HOW TO USE IDEHOOK:
///////////////////////////////////////////////////////////////////////
//
//  IdeHook is easy to use:
//
//      1)  Create one or more .CPP modules that include a customized
//             version IDEHOOK.H to perform your specific functionality.
//      2)  Create a .DLL module using you own modules and the IDEHOOK.OBJ
//             file provided with IDEHOOK.
//      3)  In the end-users Windows directory, modify BCW.INI to
//             add the following section and key-value(s):
//                [AddOns]
//                addon000=<yourdll.dll>
//          In this section, <yourdll.dll> is the name of the .DLL you
//          created in Step 2 of this procedure.
//
//  There are a few examples included to help you get on your way.
//
///////////////////////////////////////////////////////////////////////
//  TIPS AND CAVEATS
///////////////////////////////////////////////////////////////////////
//
//  It is important to remember some things when using IdeHook:
//
//  1)  You can use the IDE to make your addon (the examples were
//      done that way). However, you must modify your BCW.INI whenever
//      you test the addon. Because of this, you must remember to
//      *remove* the addon item when you are not testing.
//
//  2)  To debug your addon, you must use the standalone debugger (TDW.EXE)
//      on BCW.EXE, then load your addon into the debugger using the 'name'
//      field in the Load Modules dialog box (press F3 in TDW).
//
//  3)  Link order is *very* important when making the .DLL. Always
//      use the following order:
//          <yourLibMainModule>
//          idehook.obj
//          <your modules...>
//
//  4)  If you GP the IDE, the IDE will *not* unload your .DLL. You
//      must either use a .DLL unloader program or restart Windows.
//
//  5)  The IDE expects the key/value pairs of the [addons] section of
//      BCW.INI to be in numeric sequential order. It important that you
//      respect other addon vendors in this regard. For example, by the
//      time your addon is installed at an end-user sight, there might be
//      several addons already installed; BCW.INI might have the following:
//          [AddOns]
//          addon000=somedll.dll
//          addon001=another.dll
//          addon002=evenmore.dll
//      It is *your* responsibility to install your addon at the end of
//      this list (as 'addon003'). It is even more important to keep the
//      addons sequential when you uninstall your addon. If there have
//      been other addons installed after yours, you must decrement the
//      numbers back to maintain a non-interrupted numeric sequence.
//
///////////////////////////////////////////////////////////////////////
#ifndef __IDEHOOK_H
#define __IDEHOOK_H

#ifndef __IDEHOOKT_H
#  include "idehookt.h"
#endif

///////////////////////////////////////////////////////////////////////
//  CLIENTS AND SERVERS
///////////////////////////////////////////////////////////////////////
//
//  The IDE is built on an API exchange architecture. The APIs are
//  well defined and understood by all parties; the implementors
//  of these APIs are responsible for registering themselves as
//  such and servicing requests for the given API.
//
//  IdeHook exposes serveral IDE servers:
//
//      ToolServer
//      ProjectServer
//      TargetExpert
//      OptionSetServer
//      MakeServer
//
//  In order to gain access to these servers, each one comes with a
//  'requestor' that implements the proper request and release sequence:
//
//      Server                  Requestor
//      ----------------        ------------------
//      ToolServer              ToolReq
//      ProjectServer           ProjectReq
//      TargetExpert            TargetExpertReq
//      OptionSetServer         OptionSetReq
//      MakeServer              MakeReq
//
//  To get a service, just instantiate its requestor:
//
//      {
//          ToolReq     toolServer;         // This gets a ToolServer
//
//          toolServer->ToolInvoke( ... );  // Call the server
//
//      }                                   // Release the tool server
//
//
//  NOTE: Some servers provide a 'client' class which you must implement
//  and register with the server in order to get call backs for event
//  notifications, tool invocations, or query responders.
//
////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////
//                                                              //
//      TOOL CLIENT/SERVER                                      //
//                                                              //
//////////////////////////////////////////////////////////////////

//
//  ToolClient
//
//    Use this class as a shell for your implementation of tool call-backs.
//
class _HOOKCLASS ToolClient
{

};

//
//  ToolServer
//
//      This is the IDE's tool server, use it to query, add, remove,
//      and invoke any tool in the IDE.
//
//      There are two types of tool installing:
//
//          1)  'Installing' a tool into the user's project. Tools
//              installed in this manner appear on either the IDE Tool
//              menu or on the SpeedMenu of a specific node type. These
//              tools are implemented as either standalone .EXEs or as
//              call-backs into your addon .DLLs. Tools installed like
//              this are done on a project-by-project basis.
//
//          2)  'Registering' the implementor of a call-back style tool that
//              was installed in Step 1). This only needs to be done
//              once per instance of BCW.EXE.
//
class _HOOKCLASS ToolServer
{
public:

    //
    //  Register one or many tool call-back implementors
    //
    virtual void     _HOOKEP    ToolRegisterImplementor
                                (
                                    ToolClient *,
                                    ToolRegisterPack *
                                ) = 0;

    //
    //  Install a tool into the user's project
    //
    virtual ToolObj    _HOOKEP    ToolAdd
                                (
                                    ToolInfo *
                                ) = 0;

    //
    //  Query the existance of a tool in the current project
    //
    virtual ToolObj    _HOOKEP    ToolFind
                                (
                                    const char * name 
                                ) = 0;

    //
    //  Remove a tool from the current project
    //
    virtual void    _HOOKEP    ToolRemove
                                (
                                    const char * name
                                ) = 0;

    //
    //  Query the detailed information of a tool
    //
    virtual void    _HOOKEP    QueryToolInfo
                                ( 
                                    ToolObj,
                                    ToolInfo &
                                 ) = 0;

    //                                                              //
    //  Invoke any tool in the IDE. If 'ProjectNode' is zero, the   //
    //  tool is invoked on the 'currently selected object' in the   //
    //  IDE, as determined by the IDE.                              //
    //                                                              //
	 virtual ToolReturn _HOOKEP    ToolInvoke
                                (
                                    ToolObj,
                                    ProjectNode = 0,
                                    const char * cmdLineOverride = 0
                                ) = 0;

    virtual ToolReturn _HOOKEP    ToolInvoke
                                (
                                    ToolObj,
                                    const char * edName,
                                    const char * cmdLineOverride = 0
                                ) = 0;

};


//////////////////////////////////////////////////////////////////
//                                                              //
//      PROJECT SERVER/CLIENT                                   //
//                                                              //
//////////////////////////////////////////////////////////////////

//
//  ProjectClient
//
//      Client class for notification of project events and
//      query call-backs.
//
//      For example, if you wish to get notified of every
//      Project Open event, derive and implement this class,
//      then register by calling the method
//      ProjectServer::RegisterProjectClient.
//

class _HOOKCLASS ProjectClient
{
public:

    //
    //  Project Open notify event: This is called every time
    //  a user successfully opens a project.
    //
    virtual void _HOOKEP   OpenNotify
                                    (
                                        const char * name 
                                    ) = 0;
    
    //
    //  Project Close notify event: This is called every time
    //  a user closes a project (either explicitly using
    //  Project|Close Project, or by opening another project).
    //
    virtual void _HOOKEP   CloseNotify() = 0;

    //
    //  Node delete event: This is called every time the
    //  user explicitly deletes a node.
    //
    virtual void _HOOKEP   NodeDeleteNotify
                                    (
                                        ProjectNode
                                    ) = 0;

    //
    //  This is used as a call back to the method
    //  ProjectServer::QueryDependencies.
    //
    virtual void _HOOKEP   DependencyQueryResponder
                                    (
                                        ProjectNode ,
                                        const char * outputName
                                    ) = 0;
};


//
//  ProjectServer
//
//      Provides access to the current project's dependency tree.
//
//      The 'ProjectNode' cookie passed around in this (and others)
//      is a persistent 32-bit entity across sessions. You can safely
//      store this value in your own supplemental files, then refer to
//      the value during later sessions.
//
class _HOOKCLASS ProjectServer
{
public:

    //
    //  Register your implementation of a project client
    //
    virtual void            _HOOKEP    RegisterProjectClient
                            (
                                ProjectClient *
                            ) = 0;

    //
    //  Release your implementation of a project client
    //
    virtual void             _HOOKEP    UnregisterProjectClient
                            (
                                ProjectClient *
                            ) = 0;
      
    //
    //  Add a node to the project tree. If 'parent' is 0, then the node
    //  is added as a second level node (as a dependent of the [.ide]
    //  node). If 'type' is 0, then 'name' is assumed to be a file name,
    //  and the extension is used as the node type. For example:
    //
    //      To add a file:
    //          NodeAdd( parent, "foo.cpp" );   // OR:
    //          NodeAdd( parent, "foo", ".cpp" );
    //
    //      To add a SourcePool:
    //          NodeAdd( parent, "The Shared Sources", "SourcePool" );
    //
    virtual ProjectNode     _HOOKEP    NodeAdd
                            (
                                ProjectNode  parent,
                                const char * name, 
                                const char * type = 0
                            ) = 0;

    //
    //  Find any instance of a node in the tree
    //
    virtual ProjectNode    _HOOKEP    NodeFind
                            (
                                const char * name 
                            ) = 0;

    //
    //  Remove a node and all its dependencies from the tree
    //
    virtual ProjectNode    _HOOKEP    NodeRemove
                            (
                                ProjectNode 
                            ) = 0;

    //
    //  Return the top level [.ide] node from the tree
    //
    virtual ProjectNode    _HOOKEP    QueryTopNode() = 0;
    
    //
    //  Query detailed information about a given node in the tree
    //
    virtual void            _HOOKEP    QueryNodeInfo
                            (
                                ProjectNode,
                                ProjectNodeInfo &
                            ) = 0;

    //
    //  Query the dependencies of a given node in the tree. (This
    //  method 'collapses' SourcePool nodes by recursing into
    //  them as if they were not there.) This function calls every
    //  dependency found with the ProjectClient::DependencyQueryResponder()
    //  method when it's called with both the 'ProjectNode' and output
    //  location for that node.
    //
    virtual void            _HOOKEP    QueryDependencies
                            (
                                ProjectNode,
                                ProjectClient *
                            ) = 0;


    //
    //  NodePropertySet/Get/Remove lets you create and maintain
    //  persistent named properties on any node in any project. The
    //  'propertyName' field must be unique to every property on a
    //  given node. Because of this, it's recommended you use some
    //  kind of trademark (such as a name or initials) so as to not
    //  conflict with other addon vendors.
    //
    virtual void            _HOOKEP    NodePropertySet
                            (
                                ProjectNode     node,
                                const char *    propertyName,
                                void *          data,
                                size_t          dataSize
                            ) = 0;

    virtual size_t            _HOOKEP    NodePropertyFind
                            (
                                ProjectNode     node,
                                const char *    propertyName,
                                const void * &  data
                            ) = 0;

    virtual void            _HOOKEP    NodePropertyRemove
                            (
                                ProjectNode     node,
                                const char *    propertyName
                            ) = 0;


    //
    //  Return the user's currently selected nodes in the project
    //
    virtual int             _HOOKEP    QuerySelectedNodes
                            (
                                ProjectNode * & nodeArray,
                                int &           numNodes
                            ) = 0;

};


//////////////////////////////////////////////////////////////////
//                                                              //
//      OPTIONSET SERVER                                        //
//                                                              //
//////////////////////////////////////////////////////////////////

//
//  OptionSetServer
//
//      Access certain local overrides on node's project options.
//      The options available are given in an enum in IDEHOOKT.H
//      called OptionsStringIds.
//
class _HOOKCLASS OptionSetServer
{
public:

    //
    //  Set the node's local override for the given option
    //
    virtual void   _HOOKEP    OptionApply
                                        ( 
                                            ProjectNode         node,
                                            OptionsStringIds    oid,
                                            const char *        value
                                        ) = 0;

    //
    //  Get the node's local override for the given option
    //
    virtual size_t _HOOKEP    OptionGet
                                        ( 
                                            ProjectNode         node,
                                            OptionsStringIds    oid,
                                            const char * &      value
                                        ) = 0;

    //
    //  Remove the node's local override for the given option. This
    //  removes *all* local overrides if oid == OID_RemoveAll.
    //
    virtual void   _HOOKEP    OptionRemove
                                        (
                                            ProjectNode         node,
                                            OptionsStringIds    oid
                                        ) = 0;
};

//////////////////////////////////////////////////////////////////
//                                                              //
//      TARGET EXPERT                                           //
//                                                              //
//////////////////////////////////////////////////////////////////

//
//  TargetExpert
//
//      Allows for adding and querying target nodes in the
//      dependency tree. The TargetExpert expert automatically
//      creates the proper library skeleton and sets the proper
//      options for the given platform, memory model, and so on.
//
class _HOOKCLASS TargetExpert
{
public:

    //
    //  Add a target into the project dependency tree
    //
    virtual ProjectNode _HOOKEP    TargetAdd
                                        (
                                            const char *    name,
                                            TargetPlatforms platform,
                                            TargetStdLibs   libs,
                                            TargetModel     image,
                                            ProjectNode     parent = 0,
                                            const char *    type = 0
                                        ) = 0;

    //
    //  Query if a ProjectNode is actually a target
    //
    virtual int         _HOOKEP    NodeIsTarget
                                        (
                                            ProjectNode
                                        ) = 0;

    //
    //  Climb 'up' the dependency tree and return the node's target
    //
    virtual ProjectNode _HOOKEP    FindNodesTarget
                                        (
                                            ProjectNode
                                        ) = 0;

    //
    //  Query whether a given node (target or not) supports the
    //  given platform, libraries and/or image. If any of the
    //  query parameters are 0, then that attribute is not part
    //  of the query. For example:
    //
    //      To see if a node is a Win32 compile:
    //          QuerySupports( node, Win32, 0, 0 );
    //
    //      To see if a node is an OWL node:
    //          QuerySupports( node, 0, OWL, 0 );
    //
    //      To see if a node is a large model Dos overly with BGI:
    //          QuerySupports( node, DosOverlay, BGI, Large );
    //
    virtual int         _HOOKEP    QuerySupports
                                        (
                                            ProjectNode     node,
                                            TargetPlatforms platform,
                                            TargetStdLibs   libs,
                                            TargetModel     image
                                        ) = 0;
    
};


//////////////////////////////////////////////////////////////////
//                                                              //
//      MAKE                                                    //
//                                                              //
//////////////////////////////////////////////////////////////////

class _HOOKCLASS MakeClient
{
public:
    virtual void MakeBeginNotify() = 0;
    virtual void MakeEndNotify()   = 0;
};

class _HOOKCLASS MakeServer
{
public:
    virtual void        _HOOKEP    RegisterMakeClient
                                (
                                    MakeClient *
                                ) = 0;

    virtual void        _HOOKEP    UnRegisterMakeClient
                                (
                                    MakeClient *
                                ) = 0;

    virtual void        _HOOKEP    MakeNodes
                                (
                                    MakeMode,
                                    ProjectNode *, 
                                    int numNodes = 1 
                                 ) = 0;

    virtual long        _HOOKEP     NodeInputAge
                                (
                                    ProjectNode
                                ) = 0;

    virtual long        _HOOKEP     NodeOutputAge
                                (
                                    ProjectNode
                                ) = 0;

};


//////////////////////////////////////////////////////////////////
//                                                              //
//      EDITOR                                                  //
//                                                              //
//////////////////////////////////////////////////////////////////

class _HOOKCLASS EditorServer
{
public:

    //
    //  This first section is taken from the BRIEF macro language guide,
    //  where these routines are documented. The few differences from
    //  those semantics are listed here. String manipulation routines
    //  are not listed because the caller may use RTL functions.
    //

  virtual int _HOOKEP       beginning_of_line() = 0;

  virtual int _HOOKEP       backspace() = 0;

  //
  //  This version ignores buffer_name and system
  //
  virtual BufferId _HOOKEP  create_buffer
                                (
                                    char  * buffer_name,
                                    char  * file_name,
                                    int        system = 0
                                ) = 0;

  virtual int _HOOKEP       delete_block() = 0;

    //
    //  Delete a buffer from memory if there are no windows containing
    //  views on the buffer
    //
  virtual int _HOOKEP       delete_buffer
                                (
                                    BufferId buffer_id
                                ) = 0;

  virtual int _HOOKEP       delete_char
                                (
                                    int num_to_delete = 1
                                ) = 0;

  virtual void _HOOKEP      delete_line() = 0;

  virtual void _HOOKEP      delete_to_eol() = 0;

  virtual long _HOOKEP      distance_to_tab() = 0;

  virtual int _HOOKEP       down() = 0;

  virtual void _HOOKEP      drop_anchor
                                (
                                    char mark_type = 1
                                ) = 0;

  virtual int _HOOKEP       end_of_buffer() = 0;

  virtual int _HOOKEP       end_of_line() = 0;

  virtual int _HOOKEP       end_of_window() = 0;

  virtual int _HOOKEP       goto_line
                                (
                                    long line
                                ) = 0;

  virtual int _HOOKEP       goto_old_line
                                (
                                    long line
                                ) = 0;

  virtual BufferId _HOOKEP inq_buffer
                                (
                                    char  * fileName = 0
                                ) = 0;

    //
    //  Returns the length of the current line in characters
    //
  virtual int _HOOKEP       inq_line_length() = 0;

  virtual int _HOOKEP       inq_modified() = 0;

  virtual void _HOOKEP      inq_names
                                (
                                    char  * full_name = 0,
                                    char  * extension = 0,
                                    char  * buffer_name = 0
                                ) = 0;

  virtual int _HOOKEP       inq_position
                                (
                                    long  *  line = 0,
                                    long  *  col = 0
                                ) = 0;

  virtual int _HOOKEP       inq_views
                                (
                                    BufferId buffer_id = 0
                                ) = 0;

    //
    //  Add only the control string
    //
  virtual void _HOOKEP      insert
                                (
                                    char  * control_string
                                ) = 0;

  virtual int _HOOKEP       left() = 0;

  virtual int _HOOKEP       move_abs
                                (
                                    long line = 0,
                                    long column = 0
                                ) = 0;

  virtual int _HOOKEP       move_rel
                                (
                                    long num_lines = 0,
                                    long num_columns = 0
                                ) = 0;

  virtual BufferId _HOOKEP  next_buffer
                                (
                                    int system_too = 0
                                ) = 0;

  virtual int _HOOKEP       next_char
                                (
                                    int num_chars = 1
                                ) = 0;

  virtual int _HOOKEP       page_down() = 0;

  virtual int _HOOKEP       page_up() = 0;

  virtual int _HOOKEP       prev_char
                                (
                                    int num_chars = 1
                                ) = 0;

  virtual void _HOOKEP      raise_anchor() = 0;

    //
    //  NOTE: Be sure to call free_string() with the value returned here.
    //
  virtual char * _HOOKEP    read
                                (
                                    int length = 0
                                ) = 0;

  virtual int _HOOKEP       read_file
                                (
                                    char  * filename
                                ) = 0;

  virtual void _HOOKEP      refresh() = 0;

  virtual int _HOOKEP       right() = 0;

  virtual int _HOOKEP       search_back
                                (
                                    const char* pattern,
                                    int         regex   = 1,
                                    int         caseSen = 1,
                                    int         block   = 0,
                                    long  *     total_length = 0,
                                    int         grep    = 0
                                ) = 0;

  virtual int _HOOKEP       search_fwd
                                (
                                    const char *    pattern,
                                    int             regex   = 1,
                                    int             caseSen = 1,
                                    int             block   = 0,
                                    long *          total_length = 0,
                                    int             grep    = 0
                                ) = 0;

  virtual BufferId _HOOKEP  set_buffer
                                (
                                    BufferId buffer_id
                                ) = 0;

  virtual void _HOOKEP      set_top_left
                                (
                                    long        top_line = 0,
                                    long        left_col = 0,
                                    ViewId      window_id = 0,
                                    long        line = 0,
                                    long        col = 0,
                                    BufferId    buffer_id = 0
                                ) = 0;

  virtual int _HOOKEP       top_of_buffer() = 0;

  virtual int _HOOKEP       top_of_window() = 0;

  virtual int _HOOKEP       translate
                                (
                                    char  * pattern,
                                    char  * replacment,
                                    int     global_flag,
                                    int     regex   = 1,
                                    int     caseSen = 1,
                                    int     block   = 0,
                                    int     forward = 1,
                                    int     grep    = 0
                                ) = 0;

  virtual int _HOOKEP       up() = 0;

  virtual int _HOOKEP       write_buffer() = 0;

  //----------------------------------------------------------------
  //  This section consists of additional routines that cannot
  //  be built with the BRIEF primitives.
  //

  //
  //  Free storage allocated by calls to read
  //
  virtual void _HOOKEP      free_string
                                (
                                    char  * str      //  string to free 
                                ) = 0;

  //
  //  show_buffer moves an MDI window on the current buffer to the
  //  top of the window stack. If no such window exists, one is created.
  //
  virtual void _HOOKEP      show_buffer() = 0;

  virtual int _HOOKEP       save_buffer() = 0;

  virtual int _HOOKEP       register_keyhit_handlers
                                ( 
                                    KeyStroke   *   keyStrokes,
                                    int             numKeyStrokes
                                ) = 0;
};


////////////////////////////////////////////////////
//  Service implementation                        //
//                                                //
//  See the notes above for usage information.    //
////////////////////////////////////////////////////

extern void *   QueryService( int );
extern void     ReleaseService( int, void * );

template <class T, int id>
class __Req
{
public:
    __Req() : _id( id )     { _server = (T *)QueryService( id ); }
    ~__Req()                { if( _server ) 
                                ReleaseService( id, (void *)_server ); }
    operator T  * ()        { return( _server ); }
    T  * operator -> ()     { return( _server ); }
    int operator ! ()       { return( !_server ); }

private:
    T  * _server;
    int     _id;
};


#define SRVR_PROJECT        1
#define SRVR_TOOL           2
#define SRVR_OPTIONSET      3
#define SRVR_TARGETEXPERT   4
#define SRVR_MAKE           5
#define SRVR_EDITOR         6

////////////////////////////////////////////////////
//  Service usage...                              //
//                                                //
//  Use the following typedefs when you are       //
//  accessing a service, when you are coming into //
//  the scope the __Req where the service is      //
//  made, or when going out of the scope where    //
//  the service is released.                      //
////////////////////////////////////////////////////

typedef __Req<ProjectServer,  SRVR_PROJECT >     ProjectReq;
typedef __Req<ToolServer,     SRVR_TOOL    >     ToolReq;
typedef __Req<OptionSetServer,SRVR_OPTIONSET >   OptionSetReq;
typedef __Req<TargetExpert,   SRVR_TARGETEXPERT> TargetExpertReq;
typedef __Req<MakeServer,     SRVR_MAKE >        MakeReq;
typedef __Req<EditorServer,   SRVR_EDITOR >      EditorReq;


#endif  __IDEHOOK_H

// End of file

