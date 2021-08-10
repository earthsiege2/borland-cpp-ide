//.............................................................................
//
// print.cpp
//
//............................................................................
// includes

#include <windows.h>
#include <stdarg.h>
#include <stdio.h>

#include "print.h"

//............................................................................

#ifdef __FLAT__
#define filename "FISHER32.TXT"
#else
#define filename "FISHER16.TXT"
#endif

//............................................................................

#define DBWinPrintf(lpstr) OutputDebugString(lpstr)

//............................................................................

#define MsgBoxPrintf(lpstr) MessageBox(GetFocus(), lpstr, "Diamond", MB_OK | MB_APPLMODAL)

//............................................................................

void FilePrintf(LPCSTR lpstr, int len)
{
	int hfile;

	hfile = _lopen(filename, OF_WRITE);
	if (hfile == HFILE_ERROR)
		hfile = _lcreat(filename, 0);
	else
		_llseek(hfile, 0L, 2);

	_lwrite(hfile, lpstr, len);
	_lclose(hfile);
}

//............................................................................

void EmptyFile( void )
{
	int hfile = _lcreat( filename, 0 );
	_lclose( hfile );
}

//............................................................................

void PrintMsg(WORD dest, LPCSTR format, ...)
{
	if (*format)
	{
		va_list argptr;
		LPSTR lpstr;
		int len;

		lpstr = new char[1024];

		va_start(argptr, format);
		len = vsprintf(lpstr, format, argptr);
		va_end(argptr);

		if (dest & TO_FILE)
			FilePrintf(lpstr, len);
		if (dest & TO_DBWIN)
			DBWinPrintf(lpstr);
		if (dest & TO_MSGBOX)
			MsgBoxPrintf(lpstr);

		delete lpstr;
	}
}

//.............................................................................
