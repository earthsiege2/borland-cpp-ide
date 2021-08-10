//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.4  $
//
// Windows MCI (Media Control Interface) encapsulation classes.
//----------------------------------------------------------------------------
#if !defined(OWL_MCI_H)
#define OWL_MCI_H

#if !defined(OWL_WINDOW_H)
# include <owl/window.h>
#endif
#if !defined(_INC_MMSYSTEM)
# include <mmsystem.h>
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

class _OWLCLASS TMci;

//
// class TMciHiddenWindow
// ~~~~~ ~~~~~~~~~~~~~~~~
// A private TWindow derivative used by TMci to capture events.
//
class _OWLCLASS TMciHiddenWindow : public TWindow {
  public:
    TMciHiddenWindow(TMci&, TModule* = 0);

    TResult MciNotify(TParam1, TParam2);

  private:
    TMci& Mci;

  DECLARE_RESPONSE_TABLE(TMciHiddenWindow);
};

//
// class TMci
// ~~~~~ ~~~~
// Wrapper for the MCI multimedia services.
//
class _OWLCLASS TMci {
  public:
    // Constructors and destructors
    //
    TMci();
    virtual ~TMci();

    // Available commands on any MCI device
    //
    uint32  Open(MCI_OPEN_PARMS, uint32 command = 0);
    uint32  Close();
    uint32  Play(MCI_PLAY_PARMS, uint32 flags = 0);
    uint32  Stop(uint32 flags = 0);
    uint32  Pause(uint32 flags = 0);
    uint32  Resume(uint32 flags = 0);
    uint32  Seek(MCI_SEEK_PARMS, uint32 flags = 0);
    uint32  Seek(uint32 to, uint32 flags = 0);
    uint32  Load(const char far* fileName, uint32 flags = 0);

    // Virtual function to override in derived classes to know when
    // an MCI event is finished.
    //
    virtual TResult MciNotify(TParam1, TParam2);

    // State information
    //
    bool    IsBusy() const;
    void    SetBusy(bool);

    // General wrappers and properties
    //
    uint32  SendCommand(uint msg, uint32 command, uint32 param);
    uint    GetDeviceId() const;
    uint32  GetCallback() const;
    static uint32 SendCommand(uint deviceId, uint msg, uint32 command, uint32 param);

  private:
    void     SetBusyIfNeeded(uint32 command);

    uint     DeviceId;                    // Id for the MCI device
    bool     WaitingForNotification;      // Flag for asynchronous busy
    TWindow* Window;                      // Owner
};

//
// class TMciWaveAudio
// ~~~~~ ~~~~~~~~~~~~~
// Wrapper to play .WAV files.
//
class _OWLCLASS TMciWaveAudio : public TMci {
  public:
    TMciWaveAudio(const char far* elementName = 0, const char far* deviceName = 0,
      uint16 id = 0);

    uint32 Play(uint32 flags = 0, uint32 from = 0, uint32 to = 0);
};

// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>

//----------------------------------------------------------------------------
// Inline implementations
//

//
// Return the ID of the open MCI device.
//
inline uint TMci::GetDeviceId() const {
  return DeviceId;
}

//
// Return true if the MCI is currently busy doing something.
//
inline bool TMci::IsBusy() const {
  return WaitingForNotification;
}

//
// Sets the busy flag for the MCI device.
//
inline void TMci::SetBusy(bool b) {
  WaitingForNotification = b;
}

#endif  // OWL_MCI_H
