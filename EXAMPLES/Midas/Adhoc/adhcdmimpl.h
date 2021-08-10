// ADHCDMIMPL.H : Declaration of the AdHcDM

#ifndef __ADHCDMIMPL_H_
#define __ADHCDMIMPL_H_

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>

#include "adhcsrvr_TLB.H"
#include <Db.hpp>
#include <DBTables.hpp>
#include <Provider.hpp>
#include <atl/atlvcl.h>



// Forward ref. of IAppServer implementor


/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
class TAdHcDM : public TCRemoteDataModule
{
__published:  // IDE-managed Components
        TTable *Table;
        TDataSetProvider *AdHocProvider;
private:      // User declarations
public:       // User declarations
  __fastcall TAdHcDM(TComponent* Owner);

__published:
};


/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
extern PACKAGE TAdHcDM *AdHcDM;


/////////////////////////////////////////////////////////////////////////////
// TAdHcDMImpl     Implements IAdHcDM, default interface of AdHcDM
// ThreadingModel : Neutral
// Dual Interface : TRUE
// Event Support  : FALSE
// Default ProgID : adhcsrvr.AdHcDM
// Description    : 
/////////////////////////////////////////////////////////////////////////////
class ATL_NO_VTABLE TAdHcDMImpl: REMOTEDATAMODULE_IMPL(TAdHcDMImpl, AdHcDM, TAdHcDM, IAdHcDM)
{
public:

BEGIN_COM_MAP(TAdHcDMImpl)
  RDMOBJECT_COM_INTERFACE_ENTRIES(IAdHcDM)
END_COM_MAP()

  // Data used when registering Object 
  //
  DECLARE_PROGID("adhcsrvr.AdHcDM");
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


// IAdHcDM
protected: 
  STDMETHOD(GetDBNames(IStringsPtr* Value));
  STDMETHOD(GetTableNames(BSTR sAlias, IStringsPtr* TableNames));
  STDMETHOD(SetTable(BSTR DB, BSTR Table));
};

#endif  // __ADHCDMIMPL_H_ 

