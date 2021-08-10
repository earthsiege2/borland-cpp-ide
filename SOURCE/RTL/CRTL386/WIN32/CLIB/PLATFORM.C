#include <windows.h>

#define WIN32   0
#define WIN32S  1
#define DOS32   2

unsigned int _ostype;

static void PlatformDetect(void)
{
#pragma startup PlatformDetect 1

    if (GetProcAddress(GetModuleHandle ("kernel32.dll"), "Borland32"))
        _ostype = DOS32;
    else if (GetVersion() & 0x80000000)
        _ostype = WIN32S;
    else
        _ostype = WIN32;
}   
        