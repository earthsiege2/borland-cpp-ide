/*-----------------------------------------------------------------------*\
| OWLSock Demo For Windows v1.0                                           |
--------------------------------------------------------------------------|
| Written By:  Paul Pedriana                                              |
| Date:        May 7, 1995.                                               |
| Copyright:   Copyright (c) 1995 by Paul Pedriana.  All Rights Reserved. |
| UserID(s):   70541,3223                                                 |
|              70541.3223@compuserve.com                                  |
--------------------------------------------------------------------------|
| This OWLSock demo is an application that demonstrates some features     |
| of OWLSock.  It uses only asynchronous (non-blocking) Winsock calls,    |
| and uses OWLSock socket 'external' notification rather than internal    |
| notification.  External notification is the way most Winsock apps do    |
| FD_XXX notifications; see the OWLSock docs for more info.               |
--------------------------------------------------------------------------|
| Notes on this module:                                                   |
|    This module present the about box and some related information.      |
\*-----------------------------------------------------------------------*/

#include <owl/pch.h>
#if !defined(OWL_STATIC_H)
# include <owl/static.h>
#endif
#if defined(BI_PLAT_WIN16)
# include <ver.h>
#endif
#include "sockbout.h"


ProjectRCVersion::ProjectRCVersion (TModule *module)
{
    char    appFName[255];
    char    subBlockName[255];
    DWORD   fvHandle;
    UINT    vSize;

    FVData = 0;

    module->GetModuleFileName(appFName, sizeof(appFName));
    OemToAnsi(appFName, appFName);
    DWORD dwSize = ::GetFileVersionInfoSize(appFName, &fvHandle);
    if (dwSize) {
        FVData  = (void FAR *)new char[(UINT)dwSize];
        if (::GetFileVersionInfo(appFName, fvHandle, dwSize, FVData)) {
            // Copy string to buffer so if the -dc compiler switch (Put constant strings in code segments)
            // is on VerQueryValue will work under Win16.  This works around a problem in Microsoft's ver.dll
            // which writes to the string pointed to by subBlockName.
            strcpy(subBlockName, "\\VarFileInfo\\Translation"); 
            if (!::VerQueryValue(FVData, subBlockName, (void FAR* FAR*)&TransBlock, &vSize)) {
                delete FVData;
                FVData = 0;
            } else
                // Swap the words so wsprintf will print the lang-charset in the correct format.
                *(DWORD *)TransBlock = MAKELONG(HIWORD(*(DWORD *)TransBlock), LOWORD(*(DWORD *)TransBlock));
        }
    }
}


ProjectRCVersion::~ProjectRCVersion ()
{
    if (FVData)
        delete FVData;
}


bool ProjectRCVersion::GetProductName (LPSTR &prodName)
{
    UINT    vSize;
    char    subBlockName[255];

    wsprintf(subBlockName, "\\StringFileInfo\\%08lx\\%s", *(DWORD *)TransBlock, (LPSTR)"ProductName");
    return FVData ? ::VerQueryValue(FVData, subBlockName, (void FAR* FAR*)&prodName, &vSize) : false;
}


bool ProjectRCVersion::GetProductVersion (LPSTR &prodVersion)
{
    UINT    vSize;
    char    subBlockName[255];

    wsprintf(subBlockName, "\\StringFileInfo\\%08lx\\%s", *(DWORD *)TransBlock, (LPSTR)"ProductVersion");
    return FVData ? ::VerQueryValue(FVData, subBlockName, (void FAR* FAR*)&prodVersion, &vSize) : false;
}


bool ProjectRCVersion::GetCopyright (LPSTR &copyright)
{
    UINT    vSize;
    char    subBlockName[255];

    wsprintf(subBlockName, "\\StringFileInfo\\%08lx\\%s", *(DWORD *)TransBlock, (LPSTR)"LegalCopyright");
    return FVData ? ::VerQueryValue(FVData, subBlockName, (void FAR* FAR*)&copyright, &vSize) : false;
}


bool ProjectRCVersion::GetDebug (LPSTR &debug)
{
    UINT    vSize;
    char    subBlockName[255];

    wsprintf(subBlockName, "\\StringFileInfo\\%08lx\\%s", *(DWORD *)TransBlock, (LPSTR)"SpecialBuild");
    return FVData ? ::VerQueryValue(FVData, subBlockName, (void FAR* FAR*)&debug, &vSize) : false;
}

//********************************************************************************************
DlgSockDemoAbout::DlgSockDemoAbout (TWindow *parent, TResId resId, TModule *module)
    : TDialog(parent, resId, module)
{
}


DlgSockDemoAbout::~DlgSockDemoAbout (){
    Destroy();
}


void DlgSockDemoAbout::SetupWindow (){
    LPSTR prodName = 0, prodVersion = 0, copyright = 0, debug = 0;

    TStatic* versionCtrl = new TStatic(this, IDC_VERSION, 255);
    TStatic* copyrightCtrl = new TStatic(this, IDC_COPYRIGHT, 255);
    TStatic* debugCtrl = new TStatic(this, IDC_DEBUG, 255);

    TDialog::SetupWindow();

    ProjectRCVersion applVersion(GetModule());

    if (applVersion.GetProductName(prodName) && applVersion.GetProductVersion(prodVersion)) {
        char    buffer[255];
        char    versionName[128];

        buffer[0] = '\0';
        versionName[0] = '\0';

        versionCtrl->GetText(versionName, sizeof(versionName));
        wsprintf(buffer, "%s %s %s", prodName, versionName, prodVersion);

        versionCtrl->SetText(buffer);
    }

    if (applVersion.GetCopyright(copyright))
        copyrightCtrl->SetText(copyright);

    if (applVersion.GetDebug(debug))
        debugCtrl->SetText(debug);
}
