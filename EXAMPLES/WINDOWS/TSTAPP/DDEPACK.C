#define  STRICT
#include <windows.h>
#pragma hdrstop
#include <dde.h>

//*******************************************************************
// DDEPack - used to encapsulate the 16bit/32bit dependent code
//	     involved in sending DDE acknowledgments.  This is required
//	     since WM_DDE_ACK messages used to encode a memory handle and
//	     status in a single LONG.  This cannot be easily done under
//	     WIN32, since memory handles are now 32bits wide.
//
// paramaters:
//             msg           - The DDE message type we are sending.
//             lowWord       - The low order word to pack.
//             hiWord        - The high order word to pack.
// returns:
//             A packed LONG suitable for sending.
//
//*******************************************************************
#pragma argsused
LONG DDEPack (WORD msg, UINT lowWord, UINT hiWord)
{
#if	defined(__WIN32__)
	return PackDDElParam (msg, lowWord, hiWord);
#else
	return (LPARAM)MAKELONG(lowWord, hiWord);
#endif
}

//*******************************************************************
// DDEUnpack - used to encapsulate the 16bit/32bit dependent code
//	       involved in unpacking DDE messages.  This is required
//	       since WM_DDE_ACK messages used to encode a memory handle and
//	       status in a single LONG.  This cannot be easily done under
//	       WIN32, since memory handles are now 32bits wide.
//
// paramaters:
//             msg            - The DDE message type we are receiving.
//	       lParam	      - The packed DDE message.
//             pLowWord       - A pointer to the low order word.
//             pHiWord        - A pointer to the high order word.
// returns:
//             Nothing.
//
//*******************************************************************
#pragma argsused
void DDEUnpack (WORD msg, LONG lParam, UINT *pLowWord, UINT *pHiWord)
{
#if	defined(__WIN32__)
	UnpackDDElParam (msg, lParam, pLowWord, pHiWord);
	FreeDDElParam (msg, lParam);
#else
	*pLowWord = LOWORD (lParam);
	*pHiWord = HIWORD (lParam);
#endif
}

//*******************************************************************
