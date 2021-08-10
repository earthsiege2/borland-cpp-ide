/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

	iide.h
	Created: 10/11/95
	Copyright (c) 1995, Borland International
	$Header:   Y:\admin\bride\addon\deliver\interfac\iide.h_v   1.16   18 Nov 1996 11:29:28   JDOUGLAS  $
	$Revision:   1.16  $

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
#include <ideaddon\common.h>


//.............................................................................
class IIdeServer : public IUnknown {
 public:
   virtual IPolyString * BCWADDON_CMETHOD ProductBinDirectory() = 0;
   virtual IPolyString * BCWADDON_CMETHOD ProductRootDirectory() = 0;
   virtual IPolyString * BCWADDON_CMETHOD ProductHelpDirectory() = 0;
   //
   // ProcessWaitingMessages() can be used inside a tight loop in place
   // of using a Peek/translate/dispatch message routine, which would produce 
   // undesirable when running iside the IDE. 
   //
   virtual BOOL BCWADDON_CMETHOD ProcessWaitingMessages() = 0;
   
   //
   // The IDE server object also serves as a factory for these objects:
   //
	virtual IPolyString  * BCWADDON_CMETHOD CreatePolyString() = 0;
	virtual IVirtualFile * BCWADDON_CMETHOD CreateVirtualFile() = 0;
	virtual IViewType	   * BCWADDON_CMETHOD CreateViewType() = 0;
};


#endif	//  _IIDE_H_
