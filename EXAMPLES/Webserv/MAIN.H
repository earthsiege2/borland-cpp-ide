//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 1999 Inprise Corp.  All Rights Reserved.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <SysUtils.hpp>
#include <Classes.hpp>
#include <HTTPApp.hpp>
#include <Db.hpp>
#include <DBTables.hpp>
#include <DBWeb.hpp>
#include <SysInit.hpp>
#include <System.hpp>
#include <Controls.hpp>
#include <Dialogs.hpp>
#include <DSProd.hpp>
#include <Forms.hpp>
#include <Graphics.hpp>
#include <JPeg.hpp>
#include <Messages.hpp>
#include <Windows.hpp>

//---------------------------------------------------------------------------
class TCInfoModule : public TWebModule
{
__published:	// IDE-managed Components
        TTable *Customer;
        TDataSource *CustSource;
        TTable *BioLife;
        TQuery *Query1;
        TPageProducer *CustomerList;
        TPageProducer *Root;
        TQueryTableProducer *CustomerOrders;
        TFloatField *BioLifeSpeciesNo;
        TStringField *BioLifeCategory;
        TStringField *BioLifeCommon_Name;
        TStringField *BioLifeSpeciesName;
        TFloatField *BioLifeLengthcm;
        TFloatField *BioLifeLength_In;
        TMemoField *BioLifeNotes;
        TGraphicField *BioLifeGraphic;
        TFloatField *CustomerCustNo;
        TStringField *CustomerCompany;
        TDataSetPageProducer *BioLifeProducer;
        void __fastcall RootHTMLTag(TObject *Sender, TTag Tag,
          const AnsiString TagString, TStrings *TagParams,
          AnsiString &ReplaceText);
        void __fastcall CustomerListHTMLTag(TObject *Sender, TTag Tag,
          const AnsiString TagString, TStrings *TagParams,
          AnsiString &ReplaceText);
        void __fastcall CustomerInfoModuleCustomerlistAction(
          TObject *Sender, TWebRequest *Request, TWebResponse *Response,
          bool &Handled);
        void __fastcall CustomerInfoModuleQueryActionAction(
          TObject *Sender, TWebRequest *Request, TWebResponse *Response,
          bool &Handled);
        void __fastcall CustomerInfoModuleRedirectAction(TObject *Sender,
          TWebRequest *Request, TWebResponse *Response, bool &Handled);
        void __fastcall CustomerInfoModuleGetImageAction(TObject *Sender,
          TWebRequest *Request, TWebResponse *Response, bool &Handled);
        void __fastcall CustomerInfoModuleBioLifeAction(TObject *Sender,
          TWebRequest *Request, TWebResponse *Response, bool &Handled);
        void __fastcall CustomerInfoModuleRootAction(TObject *Sender,
          TWebRequest *Request, TWebResponse *Response, bool &Handled);
        void __fastcall CustInfoModCreate(TObject *Sender);
        void __fastcall BioLifeNotesGetText(TField *Sender,
          AnsiString &Text, bool DisplayText);
        void __fastcall BioLifeGraphicGetText(TField *Sender,
          AnsiString &Text, bool DisplayText);
private:	// User declarations
public:		// User declarations
	__fastcall TCInfoModule(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TCInfoModule *CInfoModule;
//---------------------------------------------------------------------------
#endif
