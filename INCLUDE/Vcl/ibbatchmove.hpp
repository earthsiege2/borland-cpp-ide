// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IBBatchMove.pas' rev: 5.00

#ifndef IBBatchMoveHPP
#define IBBatchMoveHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <IBTable.hpp>	// Pascal unit
#include <IBDatabase.hpp>	// Pascal unit
#include <IBCustomDataSet.hpp>	// Pascal unit
#include <IB.hpp>	// Pascal unit
#include <StdVCL.hpp>	// Pascal unit
#include <Db.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Ibbatchmove
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TBatchMode { batAppend, batUpdate, batAppendUpdate, batDelete, batCopy };
#pragma option pop

class DELPHICLASS TIBBatchMove;
class PASCALIMPLEMENTATION TIBBatchMove : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	bool FIBLoaded;
	Ibtable::TIBTable* FDestination;
	Ibcustomdataset::TIBCustomDataSet* FSource;
	TBatchMode FMode;
	bool FAbortOnKeyViol;
	bool FAbortOnProblem;
	bool FTransliterate;
	int FRecordCount;
	int FMovedCount;
	int FKeyViolCount;
	int FProblemCount;
	int FChangedCount;
	Classes::TStrings* FMappings;
	AnsiString FKeyViolTableName;
	AnsiString FProblemTableName;
	AnsiString FChangedTableName;
	int FCommitCount;
	void __fastcall SetMappings(Classes::TStrings* Value);
	void __fastcall SetSource(Ibcustomdataset::TIBCustomDataSet* Value);
	void __fastcall InternalExecute(TBatchMode BatchMode, Word FieldCount);
	
protected:
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation
		);
	
public:
	__fastcall virtual TIBBatchMove(Classes::TComponent* AOwner);
	__fastcall virtual ~TIBBatchMove(void);
	void __fastcall Execute(void);
	__property int ChangedCount = {read=FChangedCount, nodefault};
	__property int KeyViolCount = {read=FKeyViolCount, nodefault};
	__property int MovedCount = {read=FMovedCount, nodefault};
	__property int ProblemCount = {read=FProblemCount, nodefault};
	
__published:
	__property bool AbortOnKeyViol = {read=FAbortOnKeyViol, write=FAbortOnKeyViol, default=1};
	__property bool AbortOnProblem = {read=FAbortOnProblem, write=FAbortOnProblem, default=1};
	__property int CommitCount = {read=FCommitCount, write=FCommitCount, default=0};
	__property AnsiString ChangedTableName = {read=FChangedTableName, write=FChangedTableName};
	__property Ibtable::TIBTable* Destination = {read=FDestination, write=FDestination};
	__property AnsiString KeyViolTableName = {read=FKeyViolTableName, write=FKeyViolTableName};
	__property Classes::TStrings* Mappings = {read=FMappings, write=SetMappings};
	__property TBatchMode Mode = {read=FMode, write=FMode, default=0};
	__property AnsiString ProblemTableName = {read=FProblemTableName, write=FProblemTableName};
	__property int RecordCount = {read=FRecordCount, write=FRecordCount, default=0};
	__property Ibcustomdataset::TIBCustomDataSet* Source = {read=FSource, write=SetSource};
	__property bool Transliterate = {read=FTransliterate, write=FTransliterate, default=1};
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Ibbatchmove */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Ibbatchmove;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IBBatchMove
