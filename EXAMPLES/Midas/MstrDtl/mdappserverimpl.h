// MDAPPSERVERIMPL.H : Declaration of the MDAppServer

#ifndef __MDAPPSERVERIMPL_H_
#define __MDAPPSERVERIMPL_H_

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>

#include "MDSrvr_TLB.H"
#include <Db.hpp>
#include <DBTables.hpp>
#include <Provider.hpp>
#include <atl/atlvcl.h>

// Forward ref. of IAppServer implementor
//--------------------------------------------------------------------------
class TMDAppServer : public TCRemoteDataModule
{
__published:  // IDE-managed Components
        TDatabase *Database;
        TQuery *EmpProj;
        TQuery *Employee;
        TDataSetProvider *EmployeeProvider;
        TDataSetProvider *ProjectProvider;
        TQuery *Project;
        TDataSource *dsProject;
        TStringField *ProjectPROJ_ID;
        TStringField *ProjectPROJ_NAME;
        TMemoField *ProjectPROJ_DESC;
        TSmallintField *ProjectTEAM_LEADER;
        TStringField *ProjectPRODUCT;
        TSmallintField *EmpProjEMP_NO;
        TStringField *EmpProjPROJ_ID;
        TQuery *CascadeDeletes;
private:      // User declarations
public:       // User declarations
  __fastcall TMDAppServer(TComponent* Owner);

__published:
};
//---------------------------------------------------------------------------
extern PACKAGE TMDAppServer *MDAppServer;
//---------------------------------------------------------------------------
// TMDAppServerImpl     Implements IMDAppServer, default interface of MDAppServer
// ThreadingModel : Neutral
// Dual Interface : TRUE
// Event Support  : FALSE
// Default ProgID : MDSrvr.MDAppServer
// Description    : 
//---------------------------------------------------------------------------
class ATL_NO_VTABLE TMDAppServerImpl: REMOTEDATAMODULE_IMPL(TMDAppServerImpl, MDAppServer, TMDAppServer, IMDAppServer)
{
public:

BEGIN_COM_MAP(TMDAppServerImpl)
  RDMOBJECT_COM_INTERFACE_ENTRIES(IMDAppServer)
END_COM_MAP()

  // Data used when registering Object 
  //
  DECLARE_PROGID("MDSrvr.MDAppServer");
  DECLARE_DESCRIPTION("");

  // Function invoked to (un)register object
  //
  static HRESULT WINAPI UpdateRegistry(BOOL bRegister)
  {
    TRemoteDataModuleRegistrar regObj(GetObjectCLSID(), GetProgID(), GetDescription());
    // Disable these flags in order to disable use by socket or web connections.
    // Also set other flags to configure the behavior of your application server.
    // For more information, see atlmod.h and atlvcl.cpp.
    regObj.Singleton = false;
    regObj.EnableWeb = true;
    regObj.EnableSocket = true;
    return regObj.UpdateRegistry(bRegister);
  }


// IMDAppServer
protected: 
};

#endif  // __MDAPPSERVERIMPL_H_ 

