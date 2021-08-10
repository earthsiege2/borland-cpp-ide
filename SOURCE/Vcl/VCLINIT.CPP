#pragma hdrstop
#include <windows.hpp>
#include <sysutils.hpp>
#include <typinfo.hpp>

extern HINSTANCE _hInstance;
extern char     __isDLL;
extern char     __isGUI;
extern char     __isVCLPackage; // in c0nt.asm

extern "C"
void __stdcall __InitVCL(void)
{
  VclInit(__isDLL, __isVCLPackage, long(_hInstance), __isGUI);
}

extern "C"
void __stdcall __ExitVCL(void)
{
  VclExit();
}


extern "C"
void __stdcall __LateVCLInit(void)
{
  #pragma startup __LateVCLInit 31
/*
    priority 31 happens after all of
    VCL (including sharemem if needed),
    and the entire C++ RTL get
    initializied but before any
    user C++ global class ctors do.
*/

  // Change TypInfo strings here.
  BooleanIdents[0] = "false";
  BooleanIdents[1] = "true";
  DotSep = "->";
}

