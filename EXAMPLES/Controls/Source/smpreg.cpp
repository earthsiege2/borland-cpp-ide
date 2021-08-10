//---------------------------------------------------------------------------


#pragma hdrstop

#include "smpreg.h"

//---------------------------------------------------------------------------

#include "trayicon.h"
#include "piereg.h"
#include "perfgrap.h"
#include "cspin.h"
#include "cgrid.h"
#include "cgauges.h"
#include "cdiroutl.h"
#include "ccalendr.h"

/*
  TTrayIcon registration
*/

namespace Smpreg
{
   void __fastcall PACKAGE Register()
   {
     TComponentClass classes[8] = {__classid(TTrayIcon), __classid(TPerformanceGraph),
                                   __classid(TCSpinButton), __classid(TCSpinEdit),
                                   __classid(TCColorGrid), __classid(TCGauge),
                                   __classid(TCDirectoryOutline), __classid(TCCalendar)};

     ActivateClassGroup(__classid(Controls::TControl));

     GroupDescendentsWith(__classid(TTrayIcon), __classid(Controls::TControl));
     GroupDescendentsWith(__classid(TPerformanceGraph), __classid(Controls::TControl));
     GroupDescendentsWith(__classid(TCSpinButton), __classid(Controls::TControl));
     GroupDescendentsWith(__classid(TCSpinEdit), __classid(Controls::TControl));
     GroupDescendentsWith(__classid(TCColorGrid), __classid(Controls::TControl));
     GroupDescendentsWith(__classid(TCGauge), __classid(Controls::TControl));
     GroupDescendentsWith(__classid(TCDirectoryOutline), __classid(Controls::TControl));
     GroupDescendentsWith(__classid(TCCalendar), __classid(Controls::TControl));

     RegisterComponents(LoadStr(Tab_101), classes, (sizeof(classes)/sizeof(classes[0])) - 1);
  }
}




#pragma package(smart_init)
 