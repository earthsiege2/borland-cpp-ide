// RDMCUSTOMERDATA_BCBIMPL.H : Declaration of the rdmCustomerData_bcb

#ifndef rdmCustomerData_bcbImplH
#define rdmCustomerData_bcbImplH

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>

#include "rdmCustomerDataTypeLib_bcb_TLB.h"
#include <Db.hpp>
#include <DBTables.hpp>
#include <Provider.hpp>
#include <atl/atlvcl.h>



// Forward ref. of IAppServer implementor


/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
class TrdmCustomerData_bcb : public TCRemoteDataModule
{
__published:  // IDE-managed Components
        TSession *Session1;
        TQuery *SelectCustNames;
        TQuery *SelectCustOrders;
        TTable *OrderItems;
        TDataSetProvider *CustNames;
        TDataSetProvider *CustOrders;
        TDataSource *SelectCustOrderSrc;
private:      // User declarations
public:       // User declarations
  __fastcall TrdmCustomerData_bcb(TComponent* Owner);

__published:
};


/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
extern PACKAGE TrdmCustomerData_bcb *rdmCustomerData_bcb;


/////////////////////////////////////////////////////////////////////////////
// TrdmCustomerData_bcbImpl     Implements IrdmCustomerData_bcb, default interface of rdmCustomerData_bcb
// ThreadingModel : Apartment
// Dual Interface : TRUE
// Event Support  : FALSE
// Default ProgID : Project1.rdmCustomerData_bcb
// Description    : 
/////////////////////////////////////////////////////////////////////////////
class ATL_NO_VTABLE TrdmCustomerData_bcbImpl: REMOTEDATAMODULE_IMPL(TrdmCustomerData_bcbImpl, rdmCustomerData_bcb, TrdmCustomerData_bcb, IrdmCustomerData_bcb)
{
public:

BEGIN_COM_MAP(TrdmCustomerData_bcbImpl)
  RDMOBJECT_COM_INTERFACE_ENTRIES(IrdmCustomerData_bcb)
END_COM_MAP()

  // Data used when registering Object 
  //
  DECLARE_THREADING_MODEL(otApartment);
  DECLARE_PROGID("rdmCustomerData_bcb.rdmCustomerData_bcb");
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


// IrdmCustomerData_bcb
protected:
};

#endif  // rdmCustomerData_bcbImplH

