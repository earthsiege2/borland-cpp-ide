#ifndef __IIDEUI_H_
#define __IIDEUI_H_

#include <windows.h>
#include <objbase.h>
#include <ideaddon\iideui.uid>
#include <ideaddon\common.h>

class IIdeUI : public IUnknown
{
  public:
    //
    // Addons can call this to post the hourglass cursor
    //
    virtual void BCWADDON_CMETHOD StartWait() = 0;
    //
    // This routine will remove the hourglass cursor.
    // 
    virtual void BCWADDON_CMETHOD StopWait() = 0;
    //
    // Addons call this to enforce the desired state of the hourglass
    // cursor. For example, when displaying a dialog which forces the 
    // hourglass off. 
    //
    virtual void BCWADDON_CMETHOD RespectWait() = 0;

    //
    // The following functions will display the various flavors of the 
    // IDE's messageboxes. 
    //
    virtual short BCWADDON_CMETHOD 
    ErrorBox(HWND parent, const char* msg) = 0;

    virtual int BCWADDON_CMETHOD   
    GetYesNoBox(HWND parent, const char* msg) = 0;

    virtual int BCWADDON_CMETHOD   
    DoOkCancelBox(HWND parent, const char* msg) = 0;

    virtual int BCWADDON_CMETHOD 
    InfoBox(HWND parent, const char* msg) = 0;
};


#endif // __IIDEUI_H_
