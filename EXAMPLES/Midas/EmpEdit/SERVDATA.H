// EMPSERVER_BCBIMPL.H : Declaration of the EmpServer_BCB

#ifndef __EMPSERVER_BCBIMPL_H_
#define __EMPSERVER_BCBIMPL_H_

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>

#include "EmpSrvr_TLB.H"
#include <Db.hpp>
#include <DBTables.hpp>
#include <Provider.hpp>
#include <atl/atlvcl.h>



// Forward ref. of IAppServer implementor


/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
class TEmpServer_BCB : public TCRemoteDataModule
{
__published:  // IDE-managed Components
        TQuery *EmpQuery;
        TDataSetProvider *EmpProvider;
        void __fastcall CRemoteDataModuleCreate(TObject *Sender);
        void __fastcall CRemoteDataModuleDestroy(TObject *Sender);
        void __fastcall EmpQueryAfterOpen(TDataSet *DataSet);
private:      // User declarations
public:       // User declarations
  __fastcall TEmpServer_BCB(TComponent* Owner);

__published:
};


/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
extern PACKAGE TEmpServer_BCB *EmpServer_BCB;


/////////////////////////////////////////////////////////////////////////////
// TEmpServer_BCBImpl     Implements IEmpServer_BCB, default interface of EmpServer_BCB
// ThreadingModel : Neutral
// Dual Interface : TRUE
// Event Support  : FALSE
// Default ProgID : EmpSrvr.EmpServer_BCB
// Description    : Borland Sample Application Server
/////////////////////////////////////////////////////////////////////////////
class ATL_NO_VTABLE TEmpServer_BCBImpl: REMOTEDATAMODULE_IMPL(TEmpServer_BCBImpl, EmpServer_BCB, TEmpServer_BCB, IEmpServer_BCB)
{
public:

BEGIN_COM_MAP(TEmpServer_BCBImpl)
  RDMOBJECT_COM_INTERFACE_ENTRIES(IEmpServer_BCB)
END_COM_MAP()

  // Data used when registering Object 
  //
  DECLARE_PROGID("EmpSrvr.EmpServer_BCB");
  DECLARE_DESCRIPTION("Borland Sample Application Server");

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


// IEmpServer_BCB
protected:
};

#endif  // __EMPSERVER_BCBIMPL_H_ 

