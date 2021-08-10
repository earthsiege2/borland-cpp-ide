//----------------------------------------------------------------------------
// IdeHook - (C) Copyright 1994 by Borland International
//----------------------------------------------------------------------------
#include "windows.h"

int FAR PASCAL LibMain( HINSTANCE , WORD ,WORD wHeapSize, LPSTR )
{
   if ( wHeapSize )
      UnlockData( 0 );
   return 1;
}

// End of file

