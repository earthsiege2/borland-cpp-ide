#ifndef __ISTATUS_H_
#define __ISTATUS_H_

#include <windows.h>
#include <objbase.h>
#include <ideaddon\common.h>
#include <ideaddon\itoolinf.uid>

//
// This interface gives addon's access to the IDE's status dialog.
// Addon's can retrieve a pointer to this interface via IToolInfo3::GetStatusDialog.
// Note: This must be done from IToolImplementor::Execute.
//

enum StatusDialogRow {
   StatusDialogRow1,
   StatusDialogRow2,
   StatusDialogRow3
};



class IStatusDialog : public IUnknown
{
   public:
     virtual void BCWADDON_CMETHOD
     SetCaption( IPolyString* caption ) = 0;

     virtual void BCWADDON_CMETHOD
     SetMainStatus( IPolyString* text ) = 0;

     virtual void BCWADDON_CMETHOD
     SetStat( StatusDialogRow row, unsigned value ) = 0;

     virtual void BCWADDON_CMETHOD
     SetStatusRowText( StatusDialogRow row, IPolyString* text ) = 0;

     virtual void BCWADDON_CMETHOD
     SetStatusRowTitle( StatusDialogRow row, IPolyString* title ) = 0;
};


#endif // __ISTATUS_H_
