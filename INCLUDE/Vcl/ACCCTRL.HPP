// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'AccCtrl.pas' rev: 5.00

#ifndef AccCtrlHPP
#define AccCtrlHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
#include <accCtrl.h>

namespace Accctrl
{
//-- type declarations -------------------------------------------------------
typedef _TRUSTEE_A *P_TRUSTEE_;

typedef _TRUSTEE_A  TRUSTEE;

typedef _TRUSTEE_A *PTRUSTEE;

typedef _TRUSTEE_A  TRUSTEE_;

typedef _TRUSTEE_A *PTRUSTEE_;

typedef EXPLICIT_ACCESS_A *PEXPLICIT_ACCESS_;

typedef EXPLICIT_ACCESS_A  EXPLICIT_ACCESS;

typedef EXPLICIT_ACCESS_A *PEXPLICIT_ACCESS;

typedef ACTRL_ACCESS_ENTRYA *PACTRL_ACCESS_ENTRY;

typedef ACTRL_ACCESS_ENTRY_LISTA *PACTRL_ACCESS_ENTRY_LIST;

typedef ACTRL_PROPERTY_ENTRYA *PACTRL_PROPERTY_ENTRY;

typedef ACTRL_ACCESSA *PACTRL_ACCESS;

typedef PACTRL_ACCESSA *PPACTRL_ACCESS;

typedef ACTRL_ACCESSA  ACTRL_AUDIT;

typedef ACTRL_ACCESSA *PACTRL_AUDIT;

typedef PACTRL_AUDITA *PPACTRL_AUDIT;

typedef TRUSTEE_ACCESSA *PTRUSTEE_ACCESS;

typedef ACTRL_ACCESS_INFOA *PACTRL_ACCESS_INFO;

typedef PACTRL_ACCESS_INFOA *PPACTRL_ACCESS_INFO;

typedef ACTRL_CONTROL_INFOA *PACTRL_CONTROL_INFO;

typedef PACTRL_CONTROL_INFOA *PPACTRL_CONTROL_INFO;

//-- var, const, procedure ---------------------------------------------------
#define ACCCTRL_DEFAULT_PROVIDER "Windows NT Access Provider"

}	/* namespace Accctrl */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Accctrl;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// AccCtrl
