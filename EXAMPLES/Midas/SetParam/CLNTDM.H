//---------------------------------------------------------------------------

#ifndef ClntDMH
#define ClntDMH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Db.hpp>
#include <DBClient.hpp>
#include <MConnect.hpp>
#include <MidasCon.hpp>
//---------------------------------------------------------------------------
class TDataModule1 : public TDataModule
{
__published:	// IDE-managed Components
        TClientDataSet *cdsEvents;
        TDataSource *dsEvents;
        TDCOMConnection *DCOMConnection;
private:	// User declarations
public:		// User declarations
        __fastcall TDataModule1(TComponent* Owner);
        void __fastcall FetchData(System::TDateTime StartDate, System::TDateTime EndDate);
};
//---------------------------------------------------------------------------
extern PACKAGE TDataModule1 *DataModule1;
//---------------------------------------------------------------------------
#endif
