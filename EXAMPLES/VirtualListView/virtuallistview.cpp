//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 2000-2002 Borland Corporation. All Rights Reserved.
//---------------------------------------------------------------------------
//      Example:        VirtualListView
//      File:           VirtualListView.cpp  
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("VirtualListView.res");
USEFORM("VListView.cpp", frmVirtualLView);
USE("ReadMe.txt", File);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TfrmVirtualLView), &frmVirtualLView);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------
