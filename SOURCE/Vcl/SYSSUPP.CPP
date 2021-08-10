//
// syssupp.cpp: System namespace support functions
//
// $Revision:   1.6  $
//

#pragma inline

#include <system.hpp>

// ensure near is visible to TASM
#if defined(near)
#undef near
#endif

namespace System
{
	AnsiString __fastcall LoadResourceString(ResourceString const * const rsrc)
	{
		AnsiString  result;
		AnsiString  *tmp = &result;
		asm
		{
			extrn   @System@LoadResString$qqrp20System@TResStringRec:near
			mov     edx, tmp
			mov     eax, rsrc
			call    @System@LoadResString$qqrp20System@TResStringRec
		}
		return result;
	}

	/* Links the FindDynaInst call the C++ compiler generates to
	   the pascal implementation living in system.pas
	*/
	#pragma argsused
	void * __fastcall FindDynaInst(void * vmt, int ID)
	{
		asm
		{
			extrn @System@@FindDynaInst$qqrv:near
			call @System@@FindDynaInst$qqrv
		}
		return (void*)_EAX;
	}

	#pragma argsused
	void __fastcall CheckSafecallResult(HRESULT hr)
	{
		asm
		{
			extrn	@System@@CheckAutoResult$qqrv:near
			call	@System@@CheckAutoResult$qqrv
		}
	}
}
