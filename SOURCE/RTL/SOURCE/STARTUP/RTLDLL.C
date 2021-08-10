/*-----------------------------------------------------------------------*
 * filename - rtldll.c
 *
 * function(s)
 *      DllEntryPoint     - default DLL initialization for the RTLDLL
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1999, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.5 $ */


#include <windows.h>
#include <ctype.h>
#include <_process.h>
#include <version.h>  /* for VERSION_STRING */

#ifdef _BUILDRTLDLL

/* This function simply checks for an Env var and if it's set, displays a
   MessageBox containing information about where the RTLDLL is located and its
   version.  Also the name of the EXE that loaded it is in the title.  If the
   user wishes not to proceed (because, say, an RTLDLL from the wrong path
   was loaded), the <Cancel> button can be pressed to fail the entire load.

 */
static BOOL CheckForRTLDLLVersionEnvVar(HINSTANCE hInst)
{
    char *p;
    char val[100];

    if (GetEnvironmentVariable("SHOW_RTLDLL_VERSION", val, sizeof(val)))
    {
        const char *title = "Borland C++Builder RTLDLL Information Screen";
        char buf[512];
        char fpath[256];
        char exe[256];
        int mbRet;
        int sys = 0;
        int msg = 1;

        /* Check for the var being set to '2' or "System" */
        if (val[0] == '2' || toupper(val[0]) == 'S')
            sys = 1;

        /* if set to '0' then disable everything */
        if (val[0] == '0')
            return TRUE;

        if (GetModuleFileName(hInst, fpath, sizeof(fpath)) == 0)
            wsprintf(fpath, "<GetModuleFileName(%08X) failed: %d>", hInst,
                            GetLastError());

        GetModuleFileName(GetModuleHandle(NULL), exe, sizeof(exe));

        if (sys)
        {
            char SysDir[512];
            char comp[256];
            char *q;

            GetSystemDirectory(SysDir, sizeof(SysDir));
            strcpy(comp, fpath);
            q = strrchr(comp, '\\');
            if (q)
                *q = '\0';
            if (stricmp(comp, SysDir) != 0)
                msg = 0;
        }

        if (msg)
        {
            wsprintf(buf, "Application: %s\n"
                          "RTLDLL:      %s\n"
                          "RTL Version: %s\n\n"
                          "Continue Loading the RTLDLL?",
                          exe, fpath, VERSION_STRING);

            if (MessageBox(NULL, buf, title, MB_TASKMODAL|MB_OKCANCEL) == IDOK)
                return TRUE;
            else
                return FALSE;
        }
    }

    return TRUE;
}

/* This is the RTLDLL's main DllEntryPoint handler.
*/

BOOL  WINAPI DllEntryPoint(HINSTANCE hInst,
                           DWORD ul_reason_being_called,
                           LPVOID lpReserved)
{
    BOOL ret = TRUE;

    if (ul_reason_being_called == DLL_PROCESS_ATTACH)
        ret = CheckForRTLDLLVersionEnvVar(hInst);

    return ret;
}

#endif /* _BUILDRTLDLL */
