/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

   iproj.h
   Created: 09/06/95
   Copyright (c) 1995, Borland International
   $Header:   Y:/ADMIN/BRIDE/ADDON/DELIVER/INTERFAC/IPROJ.H_V   1.22   04 Mar 1997 14:56:44   JDOUGLAS  $
   $Revision:   1.22  $

   Project Interface

   This interface is one of several being brought forward from BC4.x IdeHook
   interface.

   There are a few changes and additions:

   The "ProjectNodeInfo" struct has been replaced with an interface.

   An NodeAddNotify, NodeChangeNotify, NodeMoveNotify and NodeCopyNotify
   events have been added.

   A HandleNodeAddUI event has been added to allow hooking a user request
   to add a node.

   PolyStrings are used instead of char pointers.

   For other minor changes, see 'IDEHOOK CHANGES' comments.


:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/

#ifndef _IPROJ_H_
#define _IPROJ_H_

#include <objbase.h>
#include <ideaddon\IPolyStr.h>
#include        <ideaddon\IProj.uid>
#include <ideaddon\IProjNod.uid>
#include        <ideaddon\IProjEvt.uid>
#include <ideaddon\common.h>     // ProjectNode

//
// Note, other node flags are available below and are used with
// the IProjectServer2 interface.
//
enum ProjectNodeFlags {
   PNF_Default = 0x0000,
   PNF_PreserveCase = 0x0001
};

//
// Used in calls to IProjectServer3::CopyNode and MoveNode to dictate
// placement of the copied\moved node in relation to another.
//
enum ProjectNodePlacement {
   PNP_FirstChild = 1,
   PNP_LastChild = 2,
   PNP_AfterSibling = 3,
   PNP_BeforeSibling = 4
};

//
// NOTES
//
// ProjectNode values are persistent between sessions.
//

//.............................................................................
class IProjectNodeInfo : public IUnknown
{
   //
   // A user of this interface gets a pointer to it by calling
   // the QueryNodeInfo() method of the IProjectServer interface.
   //
   // The user is responsible for calling the Release() method
   // when finished with the interface.
   //
 public:
   virtual IPolyString * BCWADDON_CMETHOD GetName() = 0;
   virtual IPolyString * BCWADDON_CMETHOD GetNodeType() = 0;
   virtual IPolyString * BCWADDON_CMETHOD GetDescription() = 0;
   virtual IPolyString * BCWADDON_CMETHOD GetInputLocation() = 0;
   virtual IPolyString * BCWADDON_CMETHOD GetOutputLocation() = 0;
   virtual ProjectNode BCWADDON_CMETHOD GetParent() = 0;
   virtual ProjectNode BCWADDON_CMETHOD GetFirstChild() = 0;
   virtual ProjectNode BCWADDON_CMETHOD GetNextSibling() = 0;
};

class IProjectNodeInfo2 : public IProjectNodeInfo
{
  public:
    //
    // Returns the translator associated with the node. Use
    // IToolServer::QueryToolInfo to get detailed information on the tool.
    // Use IProjectServer3::NodeSetTranslator to change it.
    //
    virtual ToolObj BCWADDON_CMETHOD GetTranslator() = 0;
};

//.............................................................................
class IProjectClient : public IUnknown
{

 public:
   //
   // OpenNotify() is called every time a project is successfully opened.
   //
   virtual void BCWADDON_CMETHOD OpenNotify( IPolyString * projectName ) = 0;

   //
   // CloseNotify() is called whenever a project has been closed.
   //
   virtual void BCWADDON_CMETHOD CloseNotify() = 0;

   //
   // NodeDeleteNotify() is called whenever a node has been deleted.
   //
   virtual void BCWADDON_CMETHOD NodeDeleteNotify( ProjectNode node ) = 0;

   //
   // NodeAddNotify() is called whenever a node has been added.
   //
   // IDEHOOK CHANGES:
   //    - This event did not exist in IDEHOOK.
   //
   virtual void BCWADDON_CMETHOD NodeAddNotify( ProjectNode node ) = 0;

   //
   // NodeMoveNotify() is called whenever a node is moved
   //
   // IDEHOOK CHANGES:
   //    - This event did not exist in IDEHOOK.
   //
   virtual void BCWADDON_CMETHOD NodeMoveNotify( ProjectNode node, ProjectNode oldParent ) = 0;

   //
   // NodeChangeNotify() whenever a nodes attributes have been changed
   //
   // IDEHOOK CHANGES:
   //    - This event did not exist in IDEHOOK.
   //
   virtual void BCWADDON_CMETHOD NodeChangeNotify( ProjectNode node ) = 0;

   //
   // NodeCopyNotify() notification that a node has been added via a copy command
   // If the node was referenced copied, reference will be TRUE, otherwise FALSE
   //
   // IDEHOOK CHANGES:
   //    - This event did not exist in IDEHOOK.
   //
   virtual void BCWADDON_CMETHOD NodeCopyNotify( ProjectNode newNode, ProjectNode newParent, BOOL reference ) = 0;

   //
   // This provides an opportnity to put up your own UI when
   // the end-user selects the AddNode command inside the project
   // manager. In most cases, clients should return FALSE when this
   // method is called!
   //
   // The first addon encountered that handles this event will block others
   // from receiving it. So this should only be used to override the behavior
   // of a node insert under a custom target!
   //
   // If you return TRUE to this, the normal UI will not come up. You must
   // do the actual work of adding the node through the ProjectServer.
   //
   // IDEHOOK CHANGES:
   //    - This event did not exist in IDEHOOK.
   //
   virtual BOOL BCWADDON_CMETHOD HandleAddNodeUI() = 0;

   //
   // DependencyQueryResponder() is called in response to the ProjectServer
   // method: QueryDependencies().
   //
   virtual void BCWADDON_CMETHOD DependencyQueryResponder( ProjectNode node,
                                          IPolyString * inputName ) = 0;

};

//.............................................................................
//
// IProjectSaveClient notifies the add-on when a project is about to be
// saved through BeforeSaveNotify() and once again after the project has
// been saved, through AfterSaveNotify(). If the user has auto-save turned
// off and cancels the save when prompted, the add-on will not get these
// events.
//
// One common use for this interface is to delete add-on tools from the project
// before the project is saved, since these tools tend to be undesirable if
// the project is loaded into BCW when the add-on isn't installed.
// In addition, if you don't prevent your tools from being added to the default
// project and then don't pull them every time the default project is saved
// (which happens whenever the first 'real' project is opened) they will be
// added to any new projects the user generates, even if your add-on is no
// longer installed.
//
// In order to receive these events, register your implementation of this
// class through IProjectServer2::RegisterProjectSaveClient(). Since this is
// a new interface, If you want to avoid crashing in BCW versions earlier than
// 5.01, be sure to query for the IProjectServer2 interface (you can use
// GET_INTERFACE( IProjectServer2 ) and check for a NULL return value) before
// calling RegisterProjectSaveClient().
//
class IProjectSaveClient : public IUnknown
{
 public:
   //
   // BeforeSaveNotify()
   // The project is about to be saved. Remove your tools now.
   //
   virtual void BCWADDON_CMETHOD BeforeSaveNotify() = 0;
   //
   // AfterSaveNotify()
   // The project has been saved, re-install your tools now.
   //
   virtual void BCWADDON_CMETHOD AfterSaveNotify() = 0;
};


//.............................................................................
class IProjectServer : public IUnknown
{
 public:
   //
   // Call this with your implementation of IProjectClient if you wish
   // to receive Project events.
   //
   virtual void BCWADDON_CMETHOD RegisterProjectClient( IProjectClient * pc ) = 0;

   //
   // Call this to stop receiving project events.
   // This method will call Release() on your IProjectClient object.
   //
   virtual void BCWADDON_CMETHOD UnregisterProjectClient( IProjectClient * pc ) = 0;

   //
   // Test for the default project, which is loaded when no other
   // project is specified.
   //
   virtual BOOL BCWADDON_CMETHOD IsDefaultProject() = 0;


   //
   // Adds a node to the project tree. If 'parent' is 0, then the node
   // is added as a second level node (as a dependent of the .ide node).
   // If 'type' is 0, then 'name' is assumed to be a file name, and the
   // extension is used as the node type. For example:
   //
   //    To add a file:
   //       NodeAdd( parent, "foo.cpp" ); // OR:
   //       NodeAdd( parent, "foo", ".cpp" );
   //
   //    To add a SourcePool:
   //       NodeAdd( parent, "The Shared Sources", "SourcePool" );
   //
   // A fourth argument specifies flags for the node. Currently, only one
   // flag is defined: PNF_PreserveCase. WARNING: This should only be used
   // for custom node types, not for known node types such as .cpp nodes.
   // Using this flag for internal node types will have undefined results.
   //
   virtual ProjectNode BCWADDON_CMETHOD NodeAdd(  ProjectNode parent,
                                 IPolyString *name,
                                 IPolyString *type = 0,
                                 ProjectNodeFlags flags = PNF_Default ) = 0;

   //
   // Find any instance of a node in the tree:
   //
   virtual ProjectNode BCWADDON_CMETHOD NodeFind( IPolyString * name ) = 0;

   //
   // Removes a node and all its dependencies from the tree:
   //
   // IDEHOOK CHANGES:
   //    - In IDEHOOK this method always returned a NULL ProjectNode.
   //
   virtual void BCWADDON_CMETHOD NodeRemove( ProjectNode node ) = 0;

   //
   // Returns the top level (.ide) node in the project tree.
   //
   virtual ProjectNode BCWADDON_CMETHOD QueryTopNode() = 0;

   //
   // Returns an IProjectNodeInfo for the specified node. The caller is
   // responsible for calling IProjectNodeInfo::Release() when finished
   // with the interface.
   //
   // IDEHOOK CHANGES:
   //    - The ProjectNodeInfo struct no longer exists, instead, get
   //      the info by calling methods of IProjectNodeInfo.
   //
   virtual IProjectNodeInfo * BCWADDON_CMETHOD QueryNodeInfo( ProjectNode node ) = 0;

   //
   // Return all the dependencies of a particular node via the callback
   // 'QueryDependenciesResponder' in IProjectClient.
   // Note: This method will only return the dependencies that are being
   // displayed in the project window. An addon will get different results
   // depending on the state of the option at Option|Project|Make|Autodependencies.
   // Use the function IProjectServer3::QueryAutoDependencies to get consistent
   // results regardless of the state of that option.
   //
   virtual void BCWADDON_CMETHOD QueryDependencies(  ProjectNode node,
                                                                                        IProjectClient *pClient ) = 0;

   //
   // NodePropertySet/Get/Remove lets you create and maintain
   // persistent named properties on any node in any project. The
   // 'propertyName' field must be unique to every property on a
   // given node. Because of this, it's recommended you use some
   // kind of trademark (such as a name or initials) so as to not
   // conflict with other addon vendors.
   //
   // IDEHOOK CHANGES:
   //    - NodePropertyFind now returns a pointer to 'data' and
   //      returns the data size in the 'dataSize' arg.
   //
   virtual void BCWADDON_CMETHOD NodePropertySet(    ProjectNode node,
                                    IPolyString * propertyName,
                                    void * data,
                                    UINT dataSize ) = 0;

   virtual void * BCWADDON_CMETHOD NodePropertyFind( ProjectNode node,
                                    IPolyString * propertyName,
                                    UINT * dataSize ) = 0;


   virtual void BCWADDON_CMETHOD NodePropertyRemove( ProjectNode node,
                                    IPolyString * propertyName ) = 0;


   //
   // Returns an array of selected ProjectNode's to the the caller. The number
   // of nodes in the array is returned in the numNodes arg. The array values
   // will be valid until this interface is released or a subsequent call to
   // this method is called through this interface.
   //
   // Note that actual selection updates are not reflected in the
   // array until a subsequent call to this method.
   //
   // IDEHOOK CHANGES:
   //    - The ProjectNode array is now returned.
   //    - The numNodes arg is now an int pointer instead of reference.
   //
   virtual ProjectNode * BCWADDON_CMETHOD QuerySelectedNodes( int * numNodes ) = 0;
};





//
// IProjectServer2
//
// This interface derives from IProjectServer and adds access to a rich set of
// node flags. Some of these flags should be used with caution, as noted. In
// general, these should only be used in
//
//
// Node Flags Notes:
//
// The CaseSensitive flag should not be added to anything except custom node
// types.
//
// When a make or build happens, dependent nodes are flagged by the IDE as
// read-only. If you turn off the read-only flag in the middle of an async make
// or build, the end-user can delete the node while it is being built, which can
// lead to a crash. So, remove the ReadOnlyNode flag only in cases when you are
// the provider of the translator tool.
//

#define PNF_Runtime             0x00000001
#define PNF_ToolGen             0x00000002
#define PNF_UserGen             0x00000004
#define PNF_Reference           0x00000008     // read only
#define PNF_CaseSensitive       0x00000010     // see cautionary note above!
#define PNF_ReadOnlyNode        0x00000020     // see cautionary note above!

#define PNF_RecursiveDependency 0x00000080     // read only
#define PNF_BuildDepends        0x00000100
#define PNF_BuildAlways         0x00000200
#define PNF_BuildNever          0x00000400
#define PNF_CantBuild           0x00000800     // read only
#define PNF_Touch               0x00001000     // write only, force node to be rebuilt on next make

#define PNF_AutoDepend          0x00002000     // node is temporary
#define PNF_Exclude             0x00004000     // don't build
#define PNF_FileBased           0x00008000

#define PNF_ExcludeDebugInfo    0x00010000L
#define PNF_DosOverlay          0x00020000L


//.............................................................................
class IProjectServer2 : public IProjectServer {
 public:
   //
   // NodeHasFlags()
   // Returns true if all specified flags are currently applied to node
   // (write-only flags are ignored)
   //
   virtual BOOL BCWADDON_CMETHOD
   NodeHasFlags( ProjectNode node, DWORD flags ) = 0;

   //
   // AddNodeFlags()
   // Adds all specified flags to node (read-only flags are ignored)
   //
   virtual void BCWADDON_CMETHOD
   AddNodeFlags( ProjectNode node, DWORD flags ) = 0;

   //
   // RemoveNodeFlags()
   // Removes all specified flags from node (read-only flags are ignored)
   //
   virtual void BCWADDON_CMETHOD
   RemoveNodeFlags( ProjectNode node, DWORD flags ) = 0;

   //
   // Begin receiving project save events.
   // See the comments above for IProjectSaveClient
   //
   virtual void BCWADDON_CMETHOD
   RegisterProjectSaveClient( IProjectSaveClient * client ) = 0;

   //
   // Stop receiving project save events.
   //
   virtual void BCWADDON_CMETHOD
   UnregisterProjectSaveClient( IProjectSaveClient * client ) = 0;


};


//
// IAutoDependencyPoster
//
// This interface allows addon's to give information to the IDE's project
// manager concerning the autodependencies of a specific project node.
// Normally the compiler supplies this information to the IDE, but addon's
// who wish to drop in their own tools can make use of this interface. Retrieve
// a pointer to this interface via IProjectServer3::GetAutoDepPoster().
//
// IMPORTANT NOTE: Be sure to call the Release method after posting the dependencies.
// Failure to do so will result in the list not being closed and updated in the
// project manager.
//
class IAutoDependencyPoster : public IUnknown
{
  public:
     virtual void BCWADDON_CMETHOD
     Post( int level, IPolyString* name, long age ) = 0;

     virtual void BCWADDON_CMETHOD
     PostCodeSize( long size, long lines ) = 0;

     virtual void BCWADDON_CMETHOD
     PostDataSize( long size ) = 0;

     virtual void BCWADDON_CMETHOD
     PostOutputAge( long age ) = 0;
};


//
// IProjectServer3
//
// This interface derives from IProjectServer2 to give addons finer
// control over specific nodes in a project, including the ability to
// move, copy and switch the translators for a specfic node. Also allows
// addons to specify whether or not a specific node is "dirty", meaning
// whether it will be translated during a make operation.
//

//.............................................................................
class IProjectServer3 : public IProjectServer2  {
  public:
    //
    // These functions give addons the ability to move or copy a specific
    // node within a project. The first parameter is the node to be
    // move\copy'd, the second and third parameter specify where the node
    // will be move\copy'd to. It is strongly recommended that addons first
    // call the appropriate NodeIsValid... function to ensure the operation
    // is valid. Failure to do so may result in crashing the IDE and corruption
    // of the project file.
    //
    virtual void BCWADDON_CMETHOD
    NodeMove( ProjectNode node,
              ProjectNode target,
              ProjectNodePlacement where = PNP_BeforeSibling
            ) = 0;

    virtual void BCWADDON_CMETHOD
    NodeCopy( ProjectNode node,
              ProjectNode target,
              ProjectNodePlacement where = PNP_BeforeSibling
            ) = 0;

    virtual bool BCWADDON_CMETHOD
    NodeIsValidMove( ProjectNode node,
                     ProjectNode target,
                     ProjectNodePlacement where = PNP_BeforeSibling
                   ) = 0;

    virtual bool BCWADDON_CMETHOD
    NodeIsValidCopy( ProjectNode node,
                     ProjectNode target,
                     ProjectNodePlacement where = PNP_BeforeSibling
                   ) = 0;

    //
    // The next two functions give addons control over whether a specific
    // node will be translated during a make sequence.
    //
    virtual void BCWADDON_CMETHOD
    NodeSetDirty( ProjectNode node ) = 0;

    virtual void BCWADDON_CMETHOD
    NodeClearDirty( ProjectNode node ) = 0;

    //
    // Allows an addon to change the translator for a specific node.
    //
    virtual void BCWADDON_CMETHOD
    NodeSetTranslator( ProjectNode node, ToolObj newTool ) = 0;

    //
    // Allows an addon to change the node type (extension) of a
    // specific node.
    //
    virtual void BCWADDON_CMETHOD
    NodeSetNodeType( ProjectNode node, IPolyString* newType ) = 0;

    //
    // This will return all the dependencies of a node via the client's
    // "QueryDependenciesResponder" function. These results will be
    // consistent regardless of the state of the option at
    // Option|Project|Make|Autodependencies.
    //
    virtual void BCWADDON_CMETHOD
    QueryAutoDependencies( ProjectNode node, IProjectClient* pClient ) = 0;

    //
    // This will return a IAutoDependencyPoster interface for the
    // specified node.
    //
    virtual IAutoDependencyPoster* BCWADDON_CMETHOD
    GetAutoDepPoster( ProjectNode node ) = 0;

};


//.............................................................................


#endif      // _IPROJ_H_




