//---------------------------------------------------------------------------
#ifndef VersionInfoSampleUnitH
#define VersionInfoSampleUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "VersionInfoComponent.h"
#include "VersionInfoUI.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TVersionInfo *VersionInfo1;
    TVersionInfoLegalCopyrightLabel *VersionInfoLegalCopyrightLabel1;
    TVersionInfoFileDescriptionLabel *VersionInfoFileDescriptionLabel1;
    TVersionInfoProductNameLabel *VersionInfoProductNameLabel1;
    TVersionInfoFileVersionLabel *VersionInfoFileVersionLabel1;
    TButton *btOK;
    void __fastcall btOKClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
   __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
 