// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeFunci.pas' rev: 6.00

#ifndef TeeFunciHPP
#define TeeFunciHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeEngine.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teefunci
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TBasicTeeFunction;
class PASCALIMPLEMENTATION TBasicTeeFunction : public Teengine::TTeeFunction 
{
	typedef Teengine::TTeeFunction inherited;
	
public:
	#pragma option push -w-inl
	/* TTeeFunction.Create */ inline __fastcall virtual TBasicTeeFunction(Classes::TComponent* AOwner) : Teengine::TTeeFunction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TBasicTeeFunction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TAddTeeFunction;
class PASCALIMPLEMENTATION TAddTeeFunction : public Teengine::TTeeFunction 
{
	typedef Teengine::TTeeFunction inherited;
	
public:
	virtual double __fastcall Calculate(Teengine::TChartSeries* SourceSeries, int FirstIndex, int LastIndex);
	virtual double __fastcall CalculateMany(Classes::TList* SourceSeriesList, int ValueIndex);
public:
	#pragma option push -w-inl
	/* TTeeFunction.Create */ inline __fastcall virtual TAddTeeFunction(Classes::TComponent* AOwner) : Teengine::TTeeFunction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TAddTeeFunction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TManySeriesTeeFunction;
class PASCALIMPLEMENTATION TManySeriesTeeFunction : public Teengine::TTeeFunction 
{
	typedef Teengine::TTeeFunction inherited;
	
protected:
	virtual double __fastcall CalculateValue(const double AResult, const double AValue) = 0 ;
	
public:
	virtual double __fastcall CalculateMany(Classes::TList* SourceSeriesList, int ValueIndex);
public:
	#pragma option push -w-inl
	/* TTeeFunction.Create */ inline __fastcall virtual TManySeriesTeeFunction(Classes::TComponent* AOwner) : Teengine::TTeeFunction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TManySeriesTeeFunction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TSubtractTeeFunction;
class PASCALIMPLEMENTATION TSubtractTeeFunction : public TManySeriesTeeFunction 
{
	typedef TManySeriesTeeFunction inherited;
	
protected:
	virtual double __fastcall CalculateValue(const double AResult, const double AValue);
public:
	#pragma option push -w-inl
	/* TTeeFunction.Create */ inline __fastcall virtual TSubtractTeeFunction(Classes::TComponent* AOwner) : TManySeriesTeeFunction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TSubtractTeeFunction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TMultiplyTeeFunction;
class PASCALIMPLEMENTATION TMultiplyTeeFunction : public TManySeriesTeeFunction 
{
	typedef TManySeriesTeeFunction inherited;
	
protected:
	virtual double __fastcall CalculateValue(const double AResult, const double AValue);
public:
	#pragma option push -w-inl
	/* TTeeFunction.Create */ inline __fastcall virtual TMultiplyTeeFunction(Classes::TComponent* AOwner) : TManySeriesTeeFunction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TMultiplyTeeFunction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDivideTeeFunction;
class PASCALIMPLEMENTATION TDivideTeeFunction : public TManySeriesTeeFunction 
{
	typedef TManySeriesTeeFunction inherited;
	
protected:
	virtual double __fastcall CalculateValue(const double AResult, const double AValue);
public:
	#pragma option push -w-inl
	/* TTeeFunction.Create */ inline __fastcall virtual TDivideTeeFunction(Classes::TComponent* AOwner) : TManySeriesTeeFunction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TDivideTeeFunction(void) { }
	#pragma option pop
	
};


class DELPHICLASS THighTeeFunction;
class PASCALIMPLEMENTATION THighTeeFunction : public Teengine::TTeeFunction 
{
	typedef Teengine::TTeeFunction inherited;
	
public:
	virtual double __fastcall Calculate(Teengine::TChartSeries* SourceSeries, int FirstIndex, int LastIndex);
	virtual double __fastcall CalculateMany(Classes::TList* SourceSeriesList, int ValueIndex);
public:
	#pragma option push -w-inl
	/* TTeeFunction.Create */ inline __fastcall virtual THighTeeFunction(Classes::TComponent* AOwner) : Teengine::TTeeFunction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~THighTeeFunction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TLowTeeFunction;
class PASCALIMPLEMENTATION TLowTeeFunction : public Teengine::TTeeFunction 
{
	typedef Teengine::TTeeFunction inherited;
	
public:
	virtual double __fastcall Calculate(Teengine::TChartSeries* SourceSeries, int FirstIndex, int LastIndex);
	virtual double __fastcall CalculateMany(Classes::TList* SourceSeriesList, int ValueIndex);
public:
	#pragma option push -w-inl
	/* TTeeFunction.Create */ inline __fastcall virtual TLowTeeFunction(Classes::TComponent* AOwner) : Teengine::TTeeFunction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TLowTeeFunction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TAverageTeeFunction;
class PASCALIMPLEMENTATION TAverageTeeFunction : public Teengine::TTeeFunction 
{
	typedef Teengine::TTeeFunction inherited;
	
public:
	virtual double __fastcall Calculate(Teengine::TChartSeries* SourceSeries, int FirstIndex, int LastIndex);
	virtual double __fastcall CalculateMany(Classes::TList* SourceSeriesList, int ValueIndex);
public:
	#pragma option push -w-inl
	/* TTeeFunction.Create */ inline __fastcall virtual TAverageTeeFunction(Classes::TComponent* AOwner) : Teengine::TTeeFunction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TAverageTeeFunction(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teefunci */
using namespace Teefunci;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeFunci
