/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

 imsgsys.h   
 Copyright (c) 1987, 1996 Borland International Inc.  All Rights Reserved.
 $Header:   Y:\admin\bride\addon\deliver\interfac\imsgsys.h_v   1.14   18 Nov 1996 11:29:44   JDOUGLAS  $
 $Revision:   1.14  $

 IMessageSystem is used to post messages to the IDE's message window.
   
 Interfaces declared in this file:

 implemented by IDE
   IMessageFolder
   IMessageFolder2
   IMessageSystem

 implemented by IDE client
   IToolInstance

 Overview:
   IMessageSystem is an interface supported by IDE server. Client calls
   IMessageSystem::NewFolder to create a folder.  Client calls 
   IMessageFolder::NewFileMessage() or IMessageFolder::NewMessage() to
   display message in message window. 
   
   Client can also implement IToolInstance. IDE will notify client thru
   IToolInstance::Abort() function when user click cancel button in the
   compile box.  Client tool can abort the tool or do other processing in the
   Abort() function.
   
   New in BCW v5.01:
   A new version of IMessageFolder2 is now available. It adds the ability
   to supply help context info for a message and a mechanism which allows
   the IDE to auto scroll to an add-on error message.
   
   The add-on client can use the QUERY_INTERFACE macro to retrieve an 
   IMessageFolder2 interface from the IMessageFolder pointer returned by 
   IMessageSystem::NewFolder.
   
   An add-on editor can now hook user requests to open a file for editing
   in response to a warning or error message. To take advantage of this, 
   implement your version of IMessageClient, get an IMessageSystem2 pointer 
   (GET_INTERFACE( IMessageSystem2 )) and call its RegisterMessageClient()
   method. See further details under IMessageClient below.

:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/  
#ifndef __IMSGSYS_H
#define __IMSGSYS_H

#include <ideaddon\Imsgsys.uid>
#include <ideaddon\ipolystr.h>
#include <ideaddon\common.h>

#define ADDON_MESSAGE_FATAL     0
#define ADDON_MESSAGE_ERROR     1
#define ADDON_MESSAGE_WARNING   2
#define ADDON_MESSAGE_ABORT     3
#define ADDON_MESSAGE_BREAK     4
#define ADDON_MESSAGE_STRING    5
#define ADDON_MESSAGE_INFO      6

struct IToolInstance : public IUnknown 
{
  //
  //  Abort() is called by the IDE complile box to abort the tool when
  //  user click the cancel button.
  //      
  //  return 1 if tool is aborted, otherwise 0 is returned
  //
  virtual BOOL BCWADDON_CMETHOD Abort() = 0;
};


//.............................................................................

DECLARE_HANDLE   (HMSGITEM);

struct IMessageFolder : IUnknown {
  //
  // NewFileMessage() creates an expandable outline node in message window.
  //
  // IPolyString* pFileName : Specifies the filename to open when user double
  //                          clicks the message displayed in the message window.
  // IPolyString* pMsg      : Specifies the message to be displayed in the
  //                          message window
  //
  // Return:
  //
  //    HMSGITEM a message item handle that can be used as an argument in
  //    NewMessage() call.
  //
  virtual HMSGITEM BCWADDON_CMETHOD NewFileMessage(IPolyString* pFileName, IPolyString* pMsg) = 0;

  //
  //  NewMessage() displays a message in the message window. If
  //  NewFileMessage() is called already, 
  //
  //    HMSGITEM      hMsgItem : 
  //                  if hMsgItem is NULL, a  message is displayed at the
  //                  root level.
  //                  if hMsgItem is a valid handle returned by NewFileMessage()
  //                  , the new message is appended as a child node of 
  //                  the node created by NewFileMessage() that returns
  //                  hMsgItem.
  //
  //    IPolyString*  pMsg      : Specifies the message to be displayed.
  //    IPolyString*  pFileName : Specifies the filename to open when user
  //                              double click the message displayed in the
  //                              message window.
  //    unsigned long msgLine   : Specifies the line in pFileName to point the
  //                              the cursor to when the file is opened by
  //                              message window.
  //    short         msgColumn : Specifies the coloum in pFileName to point the
  //                              the cursor to when the file is opened by
  //                              message window.
  //    unsigned      msgType   : Specifies message type. This can be one of the
  //                              ADDON_MESSAGE_* listed in this file.
  //
  //
  virtual void BCWADDON_CMETHOD NewMessage(  
                     HMSGITEM hMsgItem,
                     IPolyString*  pMsg,
                     IPolyString*  pFileName = 0,
                     unsigned long msgLine = 0,
                     short         msgColumn = 0,
                     unsigned      msgType = ADDON_MESSAGE_STRING) = 0;

  //
  // EnableTransferUI() allows client to notify IDE to call
  // IToolInstance::Abort() when the cancel button is clicked in the compile
  // box.
  //
  virtual  void BCWADDON_CMETHOD EnableTransferUI(IToolInstance* pTool) = 0;
  
};


struct IMessageFolder2 : public IMessageFolder {
  //
  //  Create a new message. In addition to the args described above for
  //  IMessageFolder::NewMessage, this adds a help filename and context id.
  //
  virtual void BCWADDON_CMETHOD NewMessage2(  HMSGITEM      hMsgItem,
                                IPolyString*  pMsg,
                                IPolyString*  pFileName = 0,
                                unsigned long msgLine = 0,
                                short         msgColumn = 0,
                                unsigned      msgType = ADDON_MESSAGE_STRING,
                                unsigned long helpContextID = 0,
                                IPolyString*  pHelpfileName = 0) = 0;

  //
  // Notify message system that a series of messages are about to be
  // generated. This will allow the IDE to scroll the message window
  // to a fatal, error or warning message in the group.
  // Note: Only messages created after this call will be part of the 
  // group. 
  //
  virtual void BCWADDON_CMETHOD BeginAutoScrollGroup()=0;

  //
  // Notify message system that a message generating "session" is ending
  //
  virtual void BCWADDON_CMETHOD EndAutoScrollGroup()=0;

};



struct IMessageSystem : public IUnknown {
  // 
  // Create a message folder in message system.  This does not cause anything
  // to be displayed.
  //
  // IPolyString* name : Specifies the name of the tool, please use "Addon" for 
  // this (this will cause the Addon glyph to appear next to your messages).
  // 
  // IPolyString* pTab : Specifies the message window tab to display the message.
  // 
  // 
  virtual IMessageFolder* BCWADDON_CMETHOD NewFolder(IPolyString* name
                                  , IPolyString* pTab = 0) = 0;
};


struct IMessageClient : public IUnknown {
   //
   // IMessageClient is used to hook user requests to view or edit a file
   // in response to an error or warning message. 
   // 
   // 1) Implement a class derived from IMessageClient.
   // 2) Register your IMessageClient pointer through 
   // IMessageSystem2::RegisterMessageClient(), preferably at startup time. If
   // you register any time after the first message appears in the message
   // window, you may have lost your opportunity to handle messages.
   // 
   // Note: If more than one add-on tries to handle the same types of messages,
   // only one will prevail - the others won't ever receive the 
   // CanHandleMessage() call. Which add-on gets first crack at this is 
   // a matter of who registers first and can ultimately be dependant on 
   // which addon appears in the registry first. There is no way to guarantee
   // that your add-on will or won't be first and the order that you are called
   // is clearly undefined behavior. End users should be encouraged to install
   // only one third-party editor.
   // 
   
   // 
   // CanHandleMessage() will be called once for each unique type of message
   // handling request. Unique, in this case, means that it is the first
   // message request that has a particular 'handlerType' combined with a
   // particular 'action'.
   // 
   // Editors will want to handle messages with handler type "SourceEditor"
   // and possibly those with handler type "ToolClientNFM" and should 
   // return FALSE to any other CanHandleMessage() requests.
   // 
   // If the handler type is "SourceEditor", the file referred to by the 
   // message is a text file. However, messages with "ToolClientNFM" as the
   // designated handler are generated as "top level" messages by the project 
   // manager for everything it builds, makes or invokes. You may want to 
   // support viewing or editing the files associated with some of these 
   // messages, based on the file extension. 
   // 
   // There are currenly three 'action' strings that a SourceEditor should 
   // handle:
   //    "Edit" - open the file at the specified location for editing
   //    "View" - open the file at the specified location for viewing
   //    "Show" - If the file is already open in a buffer, position to the
   //             specified location. 
   //    
   // Note that Show requests come through in response to message window 
   // scrolling to match the currently selected message, while Edit and View
   // requests come about as a result of a user <ENTER>, double-click or
   // speed-menu action on a particular message.
   // 
   // Please see the testbed example msgcli.h and msgcli.cpp for an example
   // of simple implementation - you can also use the testbed example to spy
   // on the CanHandleMessage() and HandleMessage() callbacks. We also 
   // recommend taking a close look at how the BCW editor reacts to message 
   // handling requests.
   //
   virtual BOOL BCWADDON_CMETHOD CanHandleMessage( 
         IPolyString * handlerType, 
         IPolyString * action ) = 0;
   
   //
   // HandleMessage() will be called for all message request types that you 
   // responded TRUE to in CanHandleMessage(). 
   //
   virtual void BCWADDON_CMETHOD HandleMessage( 
         IPolyString * action,
         int column,
         int line,
         IPolyString * filePath ) = 0;
};


struct IMessageSystem2 : public IMessageSystem {
   virtual void BCWADDON_CMETHOD RegisterMessageClient( 
         IMessageClient * client ) = 0;
};



#endif // __IMSGSYS_H
