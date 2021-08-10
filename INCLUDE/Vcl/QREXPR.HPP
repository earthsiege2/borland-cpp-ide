// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'QRExpr.pas' rev: 6.00

#ifndef QRExprHPP
#define QRExprHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <QR3Const.hpp>	// Pascal unit
#include <DBTables.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <DB.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Qrexpr
{
//-- type declarations -------------------------------------------------------
typedef TMetaClass*TQRLibraryItemClass;

class DELPHICLASS TQRLibraryEntry;
class PASCALIMPLEMENTATION TQRLibraryEntry : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	AnsiString FDescription;
	AnsiString FData;
	TMetaClass*FItem;
	AnsiString FName;
	AnsiString FVendor;
	
public:
	__property AnsiString Data = {read=FData, write=FData};
	__property AnsiString Description = {read=FDescription, write=FDescription};
	__property AnsiString Name = {read=FName, write=FName};
	__property AnsiString Vendor = {read=FVendor, write=FVendor};
	__property TMetaClass* Item = {read=FItem, write=FItem};
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TQRLibraryEntry(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TQRLibraryEntry(void) { }
	#pragma option pop
	
};


class DELPHICLASS TQRLibrary;
class PASCALIMPLEMENTATION TQRLibrary : public System::TObject 
{
	typedef System::TObject inherited;
	
protected:
	Classes::TStrings* Entries;
	virtual TQRLibraryEntry* __fastcall GetEntry(int Index);
	
public:
	__fastcall TQRLibrary(void);
	__fastcall virtual ~TQRLibrary(void);
	void __fastcall Add(TMetaClass* aItem, AnsiString AName, AnsiString ADescription, AnsiString AVendor, AnsiString AData);
	__property Classes::TStrings* EntryList = {read=Entries, write=Entries};
	__property TQRLibraryEntry* Entry[int Index] = {read=GetEntry};
};


#pragma option push -b-
enum TQREvOperator { opLess, opLessOrEqual, opGreater, opGreaterOrEqual, opEqual, opUnequal, opPlus, opMinus, opOr, opMul, opDiv, opAnd };
#pragma option pop

#pragma option push -b-
enum TQREvResultType { resInt, resDouble, resString, resBool, resError };
#pragma option pop

struct TQREvResult
{
	
	TQREvResultType Kind;
	union
	{
		struct 
		{
			bool booResult;
			
		};
		struct 
		{
			System::SmallStringBase<255>  strResult;
			
		};
		struct 
		{
			double dblResult;
			
		};
		struct 
		{
			int intResult;
			
		};
		
	};
} ;

class DELPHICLASS TQREvResultClass;
class PASCALIMPLEMENTATION TQREvResultClass : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	TQREvResult EvResult;
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TQREvResultClass(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TQREvResultClass(void) { }
	#pragma option pop
	
};


class DELPHICLASS TQRFiFo;
class PASCALIMPLEMENTATION TQRFiFo : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	bool FAggreg;
	Classes::TList* FiFo;
	int FNextItem;
	
public:
	__fastcall TQRFiFo(void);
	__fastcall virtual ~TQRFiFo(void);
	void __fastcall Put(System::TObject* Value);
	void __fastcall Start(void);
	System::TObject* __fastcall Get(void);
	System::TObject* __fastcall GetAndFree(void);
	__property bool Aggreg = {read=FAggreg, write=FAggreg, nodefault};
};


class DELPHICLASS TQREvElement;
class PASCALIMPLEMENTATION TQREvElement : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	bool FIsAggreg;
	
public:
	__fastcall virtual TQREvElement(void);
	virtual TQREvResult __fastcall Value(TQRFiFo* FiFo);
	virtual void __fastcall Reset(void);
	__property bool IsAggreg = {read=FIsAggreg, write=FIsAggreg, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TQREvElement(void) { }
	#pragma option pop
	
};


class DELPHICLASS TQREvElementFunction;
class PASCALIMPLEMENTATION TQREvElementFunction : public TQREvElement 
{
	typedef TQREvElement inherited;
	
protected:
	Classes::TList* ArgList;
	bool __fastcall ArgumentOK(TQREvElement* Value);
	TQREvResult __fastcall Argument(int Index);
	void __fastcall FreeArguments(void);
	void __fastcall GetArguments(TQRFiFo* FiFo);
	virtual void __fastcall Aggregate(void);
	virtual TQREvResult __fastcall Calculate();
	
public:
	__fastcall virtual TQREvElementFunction(void);
	__fastcall virtual ~TQREvElementFunction(void);
	virtual TQREvResult __fastcall Value(TQRFiFo* FiFo);
};


typedef TMetaClass*TQREvElementFunctionClass;

class DELPHICLASS TQREvElementWrapper;
class PASCALIMPLEMENTATION TQREvElementWrapper : public TQREvElement 
{
	typedef TQREvElement inherited;
	
private:
	TQREvElement* FEmbeddedFunction;
	
public:
	__fastcall TQREvElementWrapper(TQREvElement* AEmbeddedFunction);
	virtual TQREvResult __fastcall Value(TQRFiFo* FiFo);
	__property TQREvElement* EmbeddedFunction = {read=FEmbeddedFunction};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TQREvElementWrapper(void) { }
	#pragma option pop
	
};


class DELPHICLASS TQREvEmbeddedFunction;
class DELPHICLASS TQREvaluator;
class DELPHICLASS TQREvEnvironment;
class PASCALIMPLEMENTATION TQREvEnvironment : public Classes::TStringList 
{
	typedef Classes::TStringList inherited;
	
private:
	int PrepareCount;
	Classes::TList* OwnDataSets;
	Classes::TList* FDatasets;
	
protected:
	virtual void __fastcall DefineProperties(Classes::TFiler* Filer);
	void __fastcall ReadProperties(Classes::TReader* Reader);
	void __fastcall WriteProperties(Classes::TWriter* Writer);
	Classes::TList* __fastcall GetDatasets(void);
	void __fastcall SetDatasets(Classes::TList* Value);
	
public:
	__fastcall TQREvEnvironment(void);
	__fastcall virtual ~TQREvEnvironment(void);
	void __fastcall AddFunction(AnsiString AName, AnsiString AExpression);
	virtual void __fastcall Clear(void);
	void __fastcall DeleteFunction(AnsiString AName);
	void __fastcall Update(void);
	void __fastcall Prepare(void);
	void __fastcall UpdateConstant(AnsiString Name, const TQREvResult &Value);
	void __fastcall SetConstant(TQREvElement* Constant, const TQREvResult &Value);
	void __fastcall SetStringConstant(TQREvElement* Constant, AnsiString Value);
	void __fastcall SetIntegerConstant(TQREvElement* Constant, int Value);
	void __fastcall SetFloatConstant(TQREvElement* Constant, double Value);
	void __fastcall SetBooleanConstant(TQREvElement* Constant, bool Value);
	void __fastcall Unprepare(void);
	bool __fastcall Prepared(void);
	TQREvResult __fastcall Value(AnsiString Name);
	TQREvElement* __fastcall Element(AnsiString Name);
	TQREvElement* __fastcall GetConstant(AnsiString Name);
	__property Classes::TList* Datasets = {read=GetDatasets, write=SetDatasets};
};


class PASCALIMPLEMENTATION TQREvaluator : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Classes::TList* OwnDataSets;
	Classes::TList* FDataSets;
	TQRFiFo* FiFo;
	bool FPrepared;
	TQREvEnvironment* FEnvironment;
	TQREvResult __fastcall EvalEnvironment(AnsiString strVariable);
	TQREvResult __fastcall EvalFunctionExpr(const AnsiString strFunc);
	TQREvResult __fastcall EvalSimpleExpr(const AnsiString strSimplExpr);
	TQREvResult __fastcall EvalTerm(const AnsiString strTermExpr);
	TQREvResult __fastcall EvalFactor(AnsiString strFactorExpr);
	TQREvResult __fastcall EvalString(const AnsiString strString);
	TQREvResult __fastcall EvalConstant(const AnsiString strConstant);
	bool __fastcall GetAggregate(void);
	TQREvResult __fastcall Evaluate(const AnsiString strExpr);
	void __fastcall FindDelimiter(AnsiString strArg, int &Pos);
	void __fastcall SetAggregate(bool Value);
	void __fastcall TrimString(AnsiString &strString);
	
protected:
	virtual TQREvResult __fastcall EvalFunction(AnsiString strFunc, const AnsiString strArg);
	virtual TQREvResult __fastcall EvalVariable(AnsiString strVariable);
	bool __fastcall GetIsAggreg(void);
	Classes::TList* __fastcall GetDatasets(void);
	void __fastcall SetDatasets(Classes::TList* Value);
	
public:
	__fastcall TQREvaluator(void);
	__fastcall virtual ~TQREvaluator(void);
	TQREvResult __fastcall Calculate(const AnsiString StrExpr);
	TQREvResult __fastcall Value();
	AnsiString __fastcall AsString();
	int __fastcall AsInteger(void);
	Extended __fastcall AsFloat(void);
	bool __fastcall AsBoolean(void);
	Variant __fastcall AsVariant();
	void __fastcall Prepare(const AnsiString StrExpr);
	void __fastcall Reset(void);
	void __fastcall UnPrepare(void);
	void __fastcall DoAggregate(void);
	__property TQREvEnvironment* Environment = {read=FEnvironment, write=FEnvironment};
	__property bool IsAggreg = {read=GetIsAggreg, nodefault};
	__property bool Aggregate = {read=GetAggregate, write=SetAggregate, nodefault};
	__property Classes::TList* DataSets = {read=GetDatasets, write=SetDatasets};
	__property bool Prepared = {read=FPrepared, write=FPrepared, nodefault};
};


class PASCALIMPLEMENTATION TQREvEmbeddedFunction : public TQREvElement 
{
	typedef TQREvElement inherited;
	
private:
	TQREvaluator* Evaluator;
	AnsiString FExpression;
	bool FInEvaluate;
	
public:
	__fastcall TQREvEmbeddedFunction(AnsiString Expression);
	__fastcall virtual ~TQREvEmbeddedFunction(void);
	virtual TQREvResult __fastcall Value(TQRFiFo* FiFo);
	virtual void __fastcall Reset(void);
	TQREvElement* __fastcall Peek(int Index);
	AnsiString __fastcall Expression();
};


class DELPHICLASS TQREvElementArgumentEnd;
class PASCALIMPLEMENTATION TQREvElementArgumentEnd : public TQREvElement 
{
	typedef TQREvElement inherited;
	
public:
	#pragma option push -w-inl
	/* TQREvElement.Create */ inline __fastcall virtual TQREvElementArgumentEnd(void) : TQREvElement() { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TQREvElementArgumentEnd(void) { }
	#pragma option pop
	
};


class DELPHICLASS TQREvElementDataField;
class PASCALIMPLEMENTATION TQREvElementDataField : public TQREvElement 
{
	typedef TQREvElement inherited;
	
private:
	Db::TDataSet* FDataSet;
	int FFieldNo;
	Db::TField* FField;
	
public:
	__fastcall virtual TQREvElementDataField(Db::TField* aField);
	virtual TQREvResult __fastcall Value(TQRFiFo* FiFo);
public:
	#pragma option push -w-inl
	/* TQREvElement.Create */ inline __fastcall virtual TQREvElementDataField(void) : TQREvElement() { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TQREvElementDataField(void) { }
	#pragma option pop
	
};


class DELPHICLASS TQREvElementError;
class PASCALIMPLEMENTATION TQREvElementError : public TQREvElement 
{
	typedef TQREvElement inherited;
	
private:
	AnsiString FErrorMessage;
	
public:
	__fastcall TQREvElementError(AnsiString ErrorMessage);
	virtual TQREvResult __fastcall Value(TQRFiFo* FiFo);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TQREvElementError(void) { }
	#pragma option pop
	
};


class DELPHICLASS TQRFunctionLibrary;
class PASCALIMPLEMENTATION TQRFunctionLibrary : public TQRLibrary 
{
	typedef TQRLibrary inherited;
	
public:
	TQREvElement* __fastcall GetFunction(AnsiString Name);
public:
	#pragma option push -w-inl
	/* TQRLibrary.Create */ inline __fastcall TQRFunctionLibrary(void) : TQRLibrary() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TQRLibrary.Destroy */ inline __fastcall virtual ~TQRFunctionLibrary(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TQRFunctionLibrary* QRFunctionLibrary;
extern PACKAGE AnsiString __fastcall QREvResultToString(const TQREvResult &AValue);
extern PACKAGE int __fastcall QREvResultToInt(const TQREvResult &AValue);
extern PACKAGE Extended __fastcall QREvResultToFloat(const TQREvResult &AValue);
extern PACKAGE Variant __fastcall QREvResultToVariant(const TQREvResult &AValue);
extern PACKAGE TQREvEnvironment* __fastcall QRGlobalEnvironment(void);
extern PACKAGE void __fastcall UpdateConstant(TQREvElement* AConstant, const TQREvResult &Value);
extern PACKAGE void __fastcall RegisterQRFunction(TMetaClass* FunctionClass, AnsiString Name, AnsiString Description, AnsiString Vendor, AnsiString Arguments);

}	/* namespace Qrexpr */
using namespace Qrexpr;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// QRExpr
