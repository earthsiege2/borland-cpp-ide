//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef Event1H
#define Event1H
//---------------------------------------------------------------------------
#include <Db.hpp>
#include <Classes.hpp>
#include <DBTables.hpp>
#include <IBCtrls.h>
#include "ibreg.h"
#include "ibctrls.h"
//---------------------------------------------------------------------------
class TdmEvents : public TDataModule
{
__published:    // IDE-managed Components 
    TDatabase *Database1;
    TStoredProc *StoredProc1;
    TIBEventAlerter *IBEventAlerter1;
    void __fastcall IBEventAlerter1EventAlert(TObject *Sender,
      AnsiString EventName, long EventCount, bool &CancelAlerts);
    void __fastcall dmEventsCreate(TObject *Sender);
private:        // User declarations
public:         // User declarations
    virtual __fastcall TdmEvents(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TdmEvents *dmEvents;
//---------------------------------------------------------------------------
#endif
