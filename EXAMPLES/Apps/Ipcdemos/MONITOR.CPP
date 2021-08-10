//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFILE("readme.txt");
USEFORM("MONFORM.cpp", MonitorForm);
USEFORM("TRCVIEW.cpp", TraceForm);
USEUNIT("IPCTHRD.cpp");
USEFORM("ABOUT.CPP", AboutBox);
//---------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    Application->Initialize();
    Application->CreateForm(__classid(TMonitorForm), &MonitorForm);
    Application->CreateForm(__classid(TTraceForm), &TraceForm);
    Application->Run();

    return 0;
}
//---------------------------------------------------------------------------
