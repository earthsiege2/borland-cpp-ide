/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

   imsgsys.h
   Copyright (c) 1987, 1996 Borland International Inc.  All Rights Reserved.
   $Revision:   1.9  $
   
   IMessageSystem is used to post messages to the IDE's message window.
    
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/ 
#ifndef __IMSGSYS_H
#define __IMSGSYS_H

#include <ideaddon\Imsgsys.uid>
#include <ideaddon\ipolystr.h>

#define ADDON_MESSAGE_FATAL    0
#define ADDON_MESSAGE_ERROR    1
#define ADDON_MESSAGE_WARNING  2
#define ADDON_MESSAGE_ABORT    3
#define ADDON_MESSAGE_BREAK    4
#define ADDON_MESSAGE_STRING    5
#define ADDON_MESSAGE_INFO      6

struct IToolInstance : public IUnknown 
{
  //
  // return 1 if tool is aborted, otherwise 0 is returned
  //
  virtual BOOL Abort() = 0;
};


//.............................................................................

DECLARE_HANDLE   (HMSGITEM);

struct IMessageFolder : IUnknown {
  virtual HMSGITEM NewFileMessage(IPolyString* pFileName, IPolyString* pMsg) = 0;
  virtual void     NewMessage(  HMSGITEM      hMsgItem,
                                IPolyString*  pMsg,
                                IPolyString*  pFileName = 0,
                                unsigned long msgLine = 0,
                                short        msgColumn = 0,
                                unsigned      msgType = ADDON_MESSAGE_STRING) = 0;
  virtual void    EnableTransferUI(IToolInstance* pTool) = 0;
};

struct IMessageSystem : public IUnknown {
  //
  // IID_IMessageSystem
  //
  virtual IMessageFolder* NewFolder(IPolyString* name
                                  , IPolyString* pTab = 0) = 0;
};



#endif // __IMSGSYS_H
