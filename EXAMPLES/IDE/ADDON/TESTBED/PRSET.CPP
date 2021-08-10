/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

  prset.cpp
  Created: 06/20/96
   
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/  
#include "aoexpch.h"
#pragma hdrstop

#include <ideaddon\iprset.h>
#include "prset.h"

//.............................................................................
PrinterSettingsTest::PrinterSettingsTest() { }

//.............................................................................
PrinterSettingsTest::~PrinterSettingsTest() { }

//.............................................................................
BOOL PrinterSettingsTest::Init() {
  OutStr( "PrinterSettingsTest::Init()" );
  return TRUE;
}
//.............................................................................
void PrinterSettingsTest::UnInit() {
  OutStr( "PrinterSettingsTest::UnInit()" );
}  
//.............................................................................
const char * PrinterSettingsTest::GetName() {
  return "Printer Settings Test";
}
//.............................................................................
const char * PrinterSettingsTest::GetTestDescription( int testNum ) {
  switch ( testNum ) {
    case 1: 
      return "Looks for IDE default printer override settings";
  }
  return "This test not implemented.";
}  
//.............................................................................
void PrinterSettingsTest::DoTest( int testNum ) {
  switch ( testNum ) {
    case 1: {
      IPrinterSettings * printer = GET_INTERFACE( IPrinterSettings );
      if ( printer ) {
        LPPRINTDLG ppdlg = printer->GetPrintDialogSettings();
        PRINTDLG pdlg;
        if ( !ppdlg ) {
          OutStr( "no print setting overrides" );
        }
        else {
          pdlg = *ppdlg;
          LPDEVNAMES lpDevNames = (LPDEVNAMES)GlobalLock( pdlg.hDevNames );
          OutStr( FormatStr( "device: %s", (char *)lpDevNames + lpDevNames->wDeviceOffset ) );
          OutStr( FormatStr( "driver: %s", (char *)lpDevNames + lpDevNames->wDriverOffset ) );
          OutStr( FormatStr( "port: %s", (char *)lpDevNames + lpDevNames->wOutputOffset ) );
          GlobalUnlock( pdlg.hDevNames );
        }
        printer->Release();
      }
      break;
    }   
    default: {
      OutStr( FormatStr( "Test #%d Not Implemented!", testNum ) );
    }
  }
}
