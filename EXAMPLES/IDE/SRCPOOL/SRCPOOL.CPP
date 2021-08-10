// Borland C++ - (C) Copyright 1991, 1992 by Borland International
//
//  IDE SourcePool Example

#include <windows.h>

#ifdef __FLAT__
static char szName[] = "SrcPool32";
#else
static char szName[] = "SrcPool16";
#endif

int WINAPI WinMain( HINSTANCE, HINSTANCE, LPSTR, int )
{
	 return( ::MessageBox( 0, "IDE SourcePool example", szName, MB_OK ) );
}

