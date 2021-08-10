// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeStore.pas' rev: 6.00

#ifndef TeeStoreHPP
#define TeeStoreHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Chart.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teestore
{
//-- type declarations -------------------------------------------------------
typedef bool __fastcall (__closure *TProcTeeCheckError)(const AnsiString Message);

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall LoadChartFromStreamCheck(Chart::TCustomChart* &AChart, Classes::TStream* AStream, TProcTeeCheckError ACheckError);
extern PACKAGE void __fastcall LoadChartFromStream(Chart::TCustomChart* &AChart, Classes::TStream* AStream);
extern PACKAGE void __fastcall LoadChartFromFileCheck(Chart::TCustomChart* &AChart, const AnsiString AName, TProcTeeCheckError ACheckError);
extern PACKAGE void __fastcall LoadChartFromFile(Chart::TCustomChart* &AChart, const AnsiString AName);
extern PACKAGE void __fastcall ConvertTeeFileToText(const AnsiString InputFile, const AnsiString OutputFile);
extern PACKAGE bool __fastcall HasNoMandatoryValues(Teengine::TChartSeries* ASeries);
extern PACKAGE void __fastcall SaveChartToStream(Chart::TCustomChart* AChart, Classes::TStream* AStream);
extern PACKAGE void __fastcall SaveChartToFile(Chart::TCustomChart* AChart, const AnsiString AName);
extern PACKAGE Teengine::TChartValueList* __fastcall NotMandatoryList(Teengine::TChartSeries* ASeries);

}	/* namespace Teestore */
using namespace Teestore;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeStore
