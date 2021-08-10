//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop            
USERES("dclsmpedit60.res");
USEUNIT("basebindings.cpp");
USEUNIT("bufferlist.cpp");
USEFORM("bufferlistform.cpp", BufferListFrm);
USEUNIT("baseclss.cpp");
USEFORM("savekeymacro.cpp", SaveKeyMacroDlg);
USERC("strs.rc");
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "strs.res"
//---------------------------------------------------------------------------
//   Package source.
//---------------------------------------------------------------------------
int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void*)
{
        return 1;
}                            
//---------------------------------------------------------------------------
