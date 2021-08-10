/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

  iide.h
  Created: 10/11/95
  Copyright (c) 1995, Borland International
  $Revision:   1.12  $

  IDE Interface 
  
  Will return an interface pointer for any addon server interface through 
  QueryInterface().
   
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/  

#ifndef _IIDE_H_
#define _IIDE_H_

#include <windows.h>
#include <objbase.h>
#include <ideaddon\IIde.uid>
#include <ideaddon\ipolystr.h>
#include <ideaddon\ivfile.h>
#include <ideaddon\iview.h>


//.............................................................................
class IIdeServer : public IUnknown {
 public:
  virtual IPolyString * ProductBinDirectory() = 0;
  virtual IPolyString * ProductRootDirectory() = 0;
  virtual IPolyString * ProductHelpDirectory() = 0;
  //
  // ProcessWaitingMessages() can be used inside a tight loop in place
  // of using a Peek/translate/dispatch message routine, which would produce 
  // undesirable when running iside the IDE. 
  //
  virtual BOOL ProcessWaitingMessages() = 0;
  
  //
  // The IDE server object also serves as a factory for these objects:
  //
  virtual IPolyString  * CreatePolyString() = 0;
  virtual IVirtualFile * CreateVirtualFile() = 0;
  virtual IViewType  * CreateViewType() = 0;
};


#endif  //  _IIDE_H_
