/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

  iproj.h
  Created: 09/06/95
  Copyright (c) 1995, Borland International
  $Revision:   1.15  $

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
#include <ideaddon\IProj.uid>
#include <ideaddon\IProjNod.uid>
#include <ideaddon\IProjEvt.uid>
#include <ideaddon\common.h>    // ProjectNode

enum ProjectNodeFlags {
  PNF_Default = 0x0000,
  PNF_PreserveCase = 0x0001
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
  virtual IPolyString * GetName() = 0;
  virtual IPolyString * GetNodeType() = 0;
  virtual IPolyString * GetDescription() = 0;
  virtual IPolyString * GetInputLocation() = 0;
  virtual IPolyString * GetOutputLocation() = 0;
  virtual ProjectNode GetParent() = 0;
  virtual ProjectNode GetFirstChild() = 0;
  virtual ProjectNode GetNextSibling() = 0;
};

//.............................................................................
class IProjectClient : public IUnknown 
{

 public:
  //
  // OpenNotify() is called every time a project is successfully opened.
  //
  virtual void OpenNotify( IPolyString * projectName ) = 0;

  //
  // CloseNotify() is called whenever a project has been closed.
  //
  virtual void CloseNotify() = 0;

  //
  // NodeDeleteNotify() is called whenever a node has been deleted.
  //
  virtual void NodeDeleteNotify( ProjectNode node ) = 0;

  //
  // NodeAddNotify() is called whenever a node has been added.
  // 
  // IDEHOOK CHANGES:
  //   - This event did not exist in IDEHOOK.
  //
  virtual void NodeAddNotify( ProjectNode node ) = 0;
  
  //
  // NodeMoveNotify() is called whenever a node is moved
  // 
  // IDEHOOK CHANGES:
  //   - This event did not exist in IDEHOOK.
  //
  virtual void NodeMoveNotify( ProjectNode node, ProjectNode oldParent ) = 0;
  
  //
  // NodeChangeNotify() whenever a nodes attributes have been changed
  // 
  // IDEHOOK CHANGES:
  //   - This event did not exist in IDEHOOK.
  //
  virtual void NodeChangeNotify( ProjectNode node ) = 0;
  
  //
  // NodeCopyNotify() notification that a node has been added via a copy command
  // If the node was referenced copied, reference will be TRUE, otherwise FALSE
  // 
  // IDEHOOK CHANGES:
  //   - This event did not exist in IDEHOOK.
  //
  virtual void NodeCopyNotify( ProjectNode newNode, ProjectNode newParent, BOOL reference ) = 0;
  
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
  //   - This event did not exist in IDEHOOK.
  //
  virtual BOOL HandleAddNodeUI() = 0;

  //
  // DependencyQueryResponder() is called in response to the ProjectServer
  // method: QueryDependencies().
  //
  virtual void DependencyQueryResponder( ProjectNode node, 
                            IPolyString * outputName ) = 0;

};

//.............................................................................
class IProjectServer : public IUnknown
{
 public:
  //
  // Call this with your implementation of IProjectClient if you wish
  // to receive Project events. 
  //
  virtual void RegisterProjectClient( IProjectClient * pc ) = 0; 
  
  //
  // Call this to stop receiving project events.
  // This method will call Release() on your IProjectClient object.
  //
  virtual void UnregisterProjectClient( IProjectClient * pc ) = 0;
  
  //
  // Test for the default project, which is loaded when no other 
  // project is specified.
  //
  virtual BOOL IsDefaultProject() = 0;
  

  //
  // Adds a node to the project tree. If 'parent' is 0, then the node
  // is added as a second level node (as a dependent of the .ide node).
  // If 'type' is 0, then 'name' is assumed to be a file name, and the 
  // extension is used as the node type. For example:
  // 
  //   To add a file:
  //     NodeAdd( parent, "foo.cpp" ); // OR:
  //     NodeAdd( parent, "foo", ".cpp" );
  // 
  //   To add a SourcePool:
  //     NodeAdd( parent, "The Shared Sources", "SourcePool" );
  // 
  // A fourth argument specifies flags for the node. Currently, only one
  // flag is defined: PNF_PreserveCase. WARNING: This should only be used
  // for custom node types, not for known node types such as .cpp nodes. 
  // Using this flag for known node types will have undefined results.
  //
  virtual ProjectNode NodeAdd(  ProjectNode parent,
                      IPolyString *name, 
                      IPolyString *type = 0,
                      ProjectNodeFlags flags = PNF_Default ) = 0;

  //
  // Find any instance of a node in the tree:
  //
  virtual ProjectNode NodeFind( IPolyString * name ) = 0;

  //
  // Removes a node and all its dependencies from the tree:
  // 
  // IDEHOOK CHANGES:
  //   - In IDEHOOK this method always returned a NULL ProjectNode.
  //
  virtual void NodeRemove( ProjectNode node ) = 0;

  //
  // Returns the top level (.ide) node in the project tree.
  //
  virtual ProjectNode QueryTopNode() = 0;

  //
  // Returns an IProjectNodeInfo for the specified node. The caller is
  // responsible for calling IProjectNodeInfo::Release() when finished
  // with the interface.
  //
  // IDEHOOK CHANGES:
  //   - The ProjectNodeInfo struct no longer exists, instead, get
  //    the info by calling methods of IProjectNodeInfo.
  //
  virtual IProjectNodeInfo * QueryNodeInfo( ProjectNode node ) = 0;

  //
  // Return all the dependencies of a particular node via the callback
  // 'QueryDependenciesResponder' in IProjectClient. 
  //
  virtual void QueryDependencies(  ProjectNode node, 
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
  //   - NodePropertyFind now returns a pointer to 'data' and
  //    returns the data size in the 'dataSize' arg.
  //
  virtual void NodePropertySet(  ProjectNode node, 
                        IPolyString * propertyName,
                        void * data,
                        UINT dataSize ) = 0;

  virtual void * NodePropertyFind( ProjectNode node,
                        IPolyString * propertyName,
                        UINT * dataSize ) = 0;


  virtual void NodePropertyRemove( ProjectNode node,
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
  //   - The ProjectNode array is now returned.
  //   - The numNodes arg is now an int pointer instead of reference.
  //
  virtual ProjectNode * QuerySelectedNodes( int * numNodes ) = 0; 
};

#endif
