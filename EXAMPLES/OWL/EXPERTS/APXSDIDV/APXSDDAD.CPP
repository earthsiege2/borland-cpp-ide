//----------------------------------------------------------------------------
//  Project ApxSdiDv
//  Borland International
//  Copyright © 1996. All Rights Reserved.
//
//  SUBSYSTEM:    ApxSdiDv Application
//  FILE:         apxsddad.cpp
//  AUTHOR:       
//
//  OVERVIEW
//  ~~~~~~~~
//  Source file for implementation of TApxSdiDvAboutDlg (TDialog).
//
//----------------------------------------------------------------------------

#include <owl/pch.h>
#include <stdio.h>
#if defined(BI_PLAT_WIN16)
# include <ver.h>
#endif

#include "apxsddva.h"
#include "apxsddad.h"


TProjectRCVersion::TProjectRCVersion(TModule* module)
{
  uint32  fvHandle;
  uint    vSize;
  char    appFName[255];
  TAPointer<char> subBlockName = new char[255];

  FVData = 0;

  module->GetModuleFileName(appFName, sizeof appFName);
  OemToAnsi(appFName, appFName);
  uint32 dwSize = ::GetFileVersionInfoSize(appFName, &fvHandle);
  if (dwSize) {
    FVData  = (void far *)new char[(uint)dwSize];
    if (::GetFileVersionInfo(appFName, fvHandle, dwSize, FVData)) {
      // Copy string to buffer so if the -dc compiler switch(Put constant strings in code segments)
      // is on VerQueryValue will work under Win16.  This works around a problem in Microsoft's ver.dll
      // which writes to the string pointed to by subBlockName.
      //
      strcpy(subBlockName, "\\VarFileInfo\\Translation");
      if (!::VerQueryValue(FVData, subBlockName,(void far* far*)&TransBlock, &vSize)) {
        delete[] FVData;
        FVData = 0;
      }
      else
        // Swap the words so sprintf will print the lang-charset in the correct format.
        //
        *(uint32 *)TransBlock = MAKELONG(HIWORD(*(uint32 *)TransBlock), LOWORD(*(uint32 *)TransBlock));
    }
  }
}


TProjectRCVersion::~TProjectRCVersion()
{
  if (FVData)
    delete[] FVData;
}


bool TProjectRCVersion::GetProductName(LPSTR& prodName)
{
  uint    vSize;
  TAPointer<char> subBlockName = new char[255];

  if (FVData) {
    sprintf(subBlockName, "\\StringFileInfo\\%08lx\\%s", *(uint32 *)TransBlock,(LPSTR)"ProductName");
    return FVData ? ::VerQueryValue(FVData, subBlockName,(void far* far*)&prodName, &vSize) : false;
  } else
    return false;
}


bool TProjectRCVersion::GetProductVersion(LPSTR& prodVersion)
{
  uint    vSize;
  TAPointer<char> subBlockName = new char[255];

  if (FVData) {
    sprintf(subBlockName, "\\StringFileInfo\\%08lx\\%s", *(uint32 *)TransBlock,(LPSTR)"ProductVersion");
    return FVData ? ::VerQueryValue(FVData, subBlockName,(void far* far*)&prodVersion, &vSize) : false;
  } else
    return false;
}


bool TProjectRCVersion::GetCopyright(LPSTR& copyright)
{
  uint    vSize;
  TAPointer<char> subBlockName = new char[255];

  if (FVData) {
    sprintf(subBlockName, "\\StringFileInfo\\%08lx\\%s", *(uint32 *)TransBlock,(LPSTR)"LegalCopyright");
    return FVData ? ::VerQueryValue(FVData, subBlockName,(void far* far*)&copyright, &vSize) : false;
  } else
    return false;
}


bool TProjectRCVersion::GetDebug(LPSTR& debug)
{
  uint    vSize;
  TAPointer<char> subBlockName = new char[255];

  if (FVData) {
    sprintf(subBlockName, "\\StringFileInfo\\%08lx\\%s", *(uint32 *)TransBlock,(LPSTR)"SpecialBuild");
    return FVData ? ::VerQueryValue(FVData, subBlockName,(void far* far*)&debug, &vSize) : false;
  } else
    return false;
}


//{{TApxSdiDvAboutDlg Implementation}}


//--------------------------------------------------------
// TApxSdiDvAboutDlg
// ~~~~~~~~~~
// Construction/Destruction handling.
//
TApxSdiDvAboutDlg::TApxSdiDvAboutDlg(TWindow* parent, TResId resId, TModule* module)
:
  TDialog(parent, resId, module)
{
  // INSERT>> Your constructor code here.
}


TApxSdiDvAboutDlg::~TApxSdiDvAboutDlg()
{
  Destroy();

  // INSERT>> Your destructor code here.
}


void TApxSdiDvAboutDlg::SetupWindow()
{
  LPSTR prodName = 0, prodVersion = 0, copyright = 0, debug = 0;

  // Get the static text for the value based on VERSIONINFO.
  //
  TStatic* versionCtrl = new TStatic(this, IDC_VERSION, 255);
  TStatic* copyrightCtrl = new TStatic(this, IDC_COPYRIGHT, 255);
  TStatic* debugCtrl = new TStatic(this, IDC_DEBUG, 255);

  TDialog::SetupWindow();

  // Process the VERSIONINFO.
  //
  TProjectRCVersion applVersion(GetModule());

  // Get the product name and product version strings.
  //
  if (applVersion.GetProductName(prodName) && applVersion.GetProductVersion(prodVersion)) {
    // IDC_VERSION is the product name and version number, the initial value of IDC_VERSION is
    // the word Version(in whatever language) product name VERSION product version.
    //
    char buffer[255];
    char versionName[128];

    buffer[0] = '\0';
    versionName[0] = '\0';

    versionCtrl->GetText(versionName, sizeof versionName);
    sprintf(buffer, "%s %s %s", prodName, versionName, prodVersion);

    versionCtrl->SetText(buffer);
  }

  // Get the legal copyright string.
  //
  if (applVersion.GetCopyright(copyright))
    copyrightCtrl->SetText(copyright);

  // Only get the SpecialBuild text if the VERSIONINFO resource is there.
  //
  if (applVersion.GetDebug(debug))
    debugCtrl->SetText(debug);
}
