// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'MidReg.pas' rev: 6.00

#ifndef MidRegHPP
#define MidRegHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <LMidReg.hpp>	// Pascal unit
#include <DsnDb.hpp>	// Pascal unit
#include <TreeIntf.hpp>	// Pascal unit
#include <DMForm.hpp>	// Pascal unit
#include <DB.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <ObjBrkr.hpp>	// Pascal unit
#include <CorbaRdm.hpp>	// Pascal unit
#include <MtsRdm.hpp>	// Pascal unit
#include <SConnect.hpp>	// Pascal unit
#include <DataBkr.hpp>	// Pascal unit
#include <MidConst.hpp>	// Pascal unit
#include <DsnDBCst.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <DesignEditors.hpp>	// Pascal unit
#include <DesignIntf.hpp>	// Pascal unit
#include <DBConsts.hpp>	// Pascal unit
#include <DBReg.hpp>	// Pascal unit
#include <FldLinks.hpp>	// Pascal unit
#include <ShlObj.hpp>	// Pascal unit
#include <ComObj.hpp>	// Pascal unit
#include <ActiveX.hpp>	// Pascal unit
#include <Provider.hpp>	// Pascal unit
#include <DBClient.hpp>	// Pascal unit
#include <corbacon.hpp>	// Pascal unit
#include <MidasCon.hpp>	// Pascal unit
#include <MConnect.hpp>	// Pascal unit
#include <DSDesign.hpp>	// Pascal unit
#include <Variants.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Midreg
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TSimpleObjectBrokerSprig;
class PASCALIMPLEMENTATION TSimpleObjectBrokerSprig : public Lmidreg::TCustomObjectBrokerSprig 
{
	typedef Lmidreg::TCustomObjectBrokerSprig inherited;
	
public:
	virtual bool __fastcall AnyProblems(void);
public:
	#pragma option push -w-inl
	/* TComponentSprig.Create */ inline __fastcall virtual TSimpleObjectBrokerSprig(Classes::TPersistent* AItem)/* overload */ : Lmidreg::TCustomObjectBrokerSprig(AItem) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TSprig.Destroy */ inline __fastcall virtual ~TSimpleObjectBrokerSprig(void) { }
	#pragma option pop
	
};


class DELPHICLASS TWebConnectionSprig;
class PASCALIMPLEMENTATION TWebConnectionSprig : public Lmidreg::TStreamedConnectionSprig 
{
	typedef Lmidreg::TStreamedConnectionSprig inherited;
	
public:
	/* virtual class method */ virtual AnsiString __fastcall ParentProperty(TMetaClass* vmt);
	virtual bool __fastcall AnyProblems(void);
public:
	#pragma option push -w-inl
	/* TComponentSprig.Create */ inline __fastcall virtual TWebConnectionSprig(Classes::TPersistent* AItem)/* overload */ : Lmidreg::TStreamedConnectionSprig(AItem) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TSprig.Destroy */ inline __fastcall virtual ~TWebConnectionSprig(void) { }
	#pragma option pop
	
};


class DELPHICLASS TSocketConnectionSprig;
class PASCALIMPLEMENTATION TSocketConnectionSprig : public Lmidreg::TStreamedConnectionSprig 
{
	typedef Lmidreg::TStreamedConnectionSprig inherited;
	
public:
	/* virtual class method */ virtual AnsiString __fastcall ParentProperty(TMetaClass* vmt);
	virtual bool __fastcall AnyProblems(void);
public:
	#pragma option push -w-inl
	/* TComponentSprig.Create */ inline __fastcall virtual TSocketConnectionSprig(Classes::TPersistent* AItem)/* overload */ : Lmidreg::TStreamedConnectionSprig(AItem) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TSprig.Destroy */ inline __fastcall virtual ~TSocketConnectionSprig(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCOMConnectionSprig;
class PASCALIMPLEMENTATION TCOMConnectionSprig : public Lmidreg::TDispatchConnectionSprig 
{
	typedef Lmidreg::TDispatchConnectionSprig inherited;
	
public:
	virtual bool __fastcall AnyProblems(void);
public:
	#pragma option push -w-inl
	/* TComponentSprig.Create */ inline __fastcall virtual TCOMConnectionSprig(Classes::TPersistent* AItem)/* overload */ : Lmidreg::TDispatchConnectionSprig(AItem) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TSprig.Destroy */ inline __fastcall virtual ~TCOMConnectionSprig(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDCOMConnectionSprig;
class PASCALIMPLEMENTATION TDCOMConnectionSprig : public TCOMConnectionSprig 
{
	typedef TCOMConnectionSprig inherited;
	
public:
	/* virtual class method */ virtual AnsiString __fastcall ParentProperty(TMetaClass* vmt);
public:
	#pragma option push -w-inl
	/* TComponentSprig.Create */ inline __fastcall virtual TDCOMConnectionSprig(Classes::TPersistent* AItem)/* overload */ : TCOMConnectionSprig(AItem) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TSprig.Destroy */ inline __fastcall virtual ~TDCOMConnectionSprig(void) { }
	#pragma option pop
	
};


class DELPHICLASS TOLEnterpriseConnectionSprig;
class PASCALIMPLEMENTATION TOLEnterpriseConnectionSprig : public TCOMConnectionSprig 
{
	typedef TCOMConnectionSprig inherited;
	
public:
	#pragma option push -w-inl
	/* TComponentSprig.Create */ inline __fastcall virtual TOLEnterpriseConnectionSprig(Classes::TPersistent* AItem)/* overload */ : TCOMConnectionSprig(AItem) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TSprig.Destroy */ inline __fastcall virtual ~TOLEnterpriseConnectionSprig(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCorbaConnectionSprig;
class PASCALIMPLEMENTATION TCorbaConnectionSprig : public Lmidreg::TCustomRemoteServerSprig 
{
	typedef Lmidreg::TCustomRemoteServerSprig inherited;
	
public:
	virtual bool __fastcall AnyProblems(void);
public:
	#pragma option push -w-inl
	/* TComponentSprig.Create */ inline __fastcall virtual TCorbaConnectionSprig(Classes::TPersistent* AItem)/* overload */ : Lmidreg::TCustomRemoteServerSprig(AItem) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TSprig.Destroy */ inline __fastcall virtual ~TCorbaConnectionSprig(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall Register(void);

}	/* namespace Midreg */
using namespace Midreg;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// MidReg
