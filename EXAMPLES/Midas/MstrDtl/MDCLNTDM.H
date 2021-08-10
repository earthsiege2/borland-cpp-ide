//---------------------------------------------------------------------------

#ifndef MDClntDMH
#define MDClntDMH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Db.hpp>
#include <DBClient.hpp>
#include <MConnect.hpp>
#include <MidasCon.hpp>
#include <DB.hpp>
//---------------------------------------------------------------------------
class TDataModule1 : public TDataModule
{
__published:	// IDE-managed Components
        TClientDataSet *Project;
        TClientDataSet *EmpProj;
        TClientDataSet *Employee;
        TDataSource *EmployeesSource;
        TDataSource *EmpProjSource;
        TDataSource *ProjectSource;
        TSmallintField *EmpProjEMP_NO;
        TStringField *EmpProjPROJ_ID;
        TStringField *ProjectPROJ_ID;
        TStringField *ProjectPROJ_NAME;
        TMemoField *ProjectPROJ_DESC;
        TSmallintField *ProjectTEAM_LEADER;
        TStringField *ProjectPRODUCT;
        TDataSetField *ProjectEmpProj;
        TStringField *EmpProjEmpName;
        TDCOMConnection *DCOMConnection;
        void __fastcall ProjectReconcileError(
          TCustomClientDataSet *DataSet, EReconcileError *E,
          TUpdateKind UpdateKind, TReconcileAction &Action);
        void __fastcall DataModuleCreate(TObject *Sender);
        void __fastcall ProjectNewRecord(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
        __fastcall TDataModule1(TComponent* Owner);
        void __fastcall ApplyUpdates(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TDataModule1 *DataModule1;
//---------------------------------------------------------------------------
#endif
