/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

  iprset.h
  Created: 06/20/96
  Author: Slim Heilpern
  Copyright (c) 1995, Borland International
  $Revision:   1.0  $

  IPrinterSettings
   
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/  
#ifndef __IPRSET_H
#define __IPRSET_H

#include <windows.h>
#include <objbase.h>
#include <ideaddon\iprset.uid>
#include <ideaddon\common.h>

//
// IPrinterSettings 
// 
//   GetPrintDialogSettings() 
//     return value can be one of the following:
//       - a pointer to a Windows PRINTDLG struct if the user has 
//        modified the default settings through the 'Print Setup' 
//        dialog box in BCW. See the Win32 API doc for a full 
//        description of this struct.
//       - NULL, if the user has not modified the default settings
// 
//     The returned PRINTDLG lifetime is controlled by BCW, copy it to 
//     your own storage area if you need to hold on to it.
// 
//   GetPageDialogSettings() currenlty always returns NULL and is reserved
//   for future use.
//
//   
class IPrinterSettings : public IUnknown {
 public:
  virtual LPPRINTDLG BCWADDON_CMETHOD GetPrintDialogSettings() = 0;
  virtual LPPAGESETUPDLG BCWADDON_CMETHOD GetPageDialogSettings() = 0;
};


#endif    //__IPRSET_H
