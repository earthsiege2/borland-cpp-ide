//----------------------------------------------------------------------------
// ObjectWindows
// (c) Copyright 1996, 1996 by Borland International, All Rights Reserved
//
// Declares the classes used in this example application:
//  TBlazerApp
//  TClientWindow      Has context sensitive help
//  TSpeedBallWindow   Has context menu
//  TAboutWindow       Has context sensitive help
//----------------------------------------------------------------------------
#if !defined(BLAZER_H)
#define BLAZER_H

#if !defined(OWL_APPLICAT_H)
# include <owl/applicat.h>
#endif
#if !defined(OWL_HLPMANAG_H)
# include <owl/hlpmanag.h>
#endif
#if !defined(OWL_RCNTFILE_H)
# include <owl/rcntfile.h>
#endif
#if !defined(OWL_PANESPLI_H)
# include <owl/panespli.h>
#endif
#if !defined(OWL_LISTWIND_H)
# include <owl/listwind.h>
#endif
#if !defined(OWL_TREEWIND_H)
# include <owl/treewind.h>
#endif
#if !defined(OWL_LAYOUTWI_H)
# include <owl/layoutwi.h>
#endif
#if !defined(OWL_DIBITMAP_H)
# include <owl/dibitmap.h>
#endif
#if !defined(OWL_SPLASHWI_H)
# include <owl/splashwi.h>
#endif
#if !defined(OWL_COMBOBOX_H)
# include <owl/combobox.h>
#endif
#include <cstring.h>

#include "blazer.rh"
#include "helpids.hh"

#if defined(BI_NAMESPACE)
namespace OWL {
#endif

class _OWLCLASS TMailer;
class _OWLCLASS TCelArray;
class _OWLCLASS TImageList;
class _OWLCLASS TStatusBar;
class _OWLCLASS THarbor;
class _OWLCLASS TWinGIdentity;
class _OWLCLASS TButton;
class _OWLCLASS TMciWaveAudio;

#if defined(BI_NAMESPACE)
} // namespace OWL
#endif

//
// Constants
//
const int TestImage  = 100;
const int TreeWindId = 101;
const int ListWindId = 102;
const int DrivesId   = 103;

//
// class TBlazerApp
// ~~~~~ ~~~~~~~~~~
// The main application class.
// Mixes in THelpFileManager for context sensitive help
// and TRecentFiles for managing a most-recently-used file list.
//
class TBlazerApp : public TApplication, public THelpFileManager, public TRecentFiles {
  public:
    TBlazerApp();
   ~TBlazerApp();

    // Override virtual functions
    //
    void InitMainWindow();
    void InitInstance();
    TMailer* GetMailer();

  private:
    void    CmFileSelect();
    void    CmHelpAbout();
    TResult CmMruSelected(TParam1 wp, TParam2);

    TMailer*       Mailer;
    THarbor*       Harbor;

  DECLARE_RESPONSE_TABLE(TBlazerApp);
};


//
// class TPaneTreeWindow
// ~~~~~ ~~~~~~~~~~~~~~~
class TPaneTreeWindow : public TTreeWindow {
  public:
    TPaneTreeWindow(TWindow* parent, int id, int x, int y, int w, int h,
                    TStyle style = twsNone, TModule* module = 0)
    :
      TTreeWindow(parent, id, x, y, w, h, style, module)
    {
    }

    bool CanClose2(TReasonToClose)
    {
      return false;
    }

};


//
// class TPaneListWindow
// ~~~~~ ~~~~~~~~~~~~~~~
class TPaneListWindow : public TListWindow {
  public:
    TPaneListWindow(TWindow* parent, int id, int x, int y, int w, int h,
      TModule* module = 0)
    :
      TListWindow(parent, id, x, y, w, h, module)
    {
    }

    bool CanClose2(TReasonToClose)
    {
      return false;
    }
};


//
// class TComboBoxAsGadget
// ~~~~~ ~~~~~~~~~~~~~~~~~
class TComboBoxAsGadget : public TComboBox {
  public:
    TComboBoxAsGadget(TWindow*        parent,
                      int             id,
                      int x, int y, int w, int h,
                      uint32          style,
                      uint            textLimit,
                      TModule*        module = 0)
    :
      TComboBox(parent, id, x, y, w, h, style, textLimit, module)
    {
    }

  private:
    void CbnSelChanged();

  DECLARE_RESPONSE_TABLE(TComboBoxAsGadget);
};



//
// class TClientWindow
// ~~~~~ ~~~~~~~~~~~~~
// The main SDI window.
// Has context sensitive help.
//
class TClientWindow : public TPaneSplitter {
  public:
    enum FileType {
      Directory, OpenDirectory
    };
    TClientWindow(TWindow* parent = 0);
   ~TClientWindow();

    void CbnDriveSelected();
    void CmFileSend();
    void CeFileSend(TCommandEnabler& ce);
    void CmContextSelect();
    void CeContextSelect(TCommandEnabler& ce);

  protected:
    void SetupWindow();
    void CleanupWindow();

    // Event handlers
    //
    void TvnSelChanged(TTwNotify far& notify);
    void LvnGetDispInfo(TLwDispInfoNotify& dispInfo);
    bool LvnBeginLabelEdit(TLwDispInfoNotify& dispInfo);
    void LvnEndLabelEdit(TLwDispInfoNotify& dispInfo);

  private:
    bool   AreFilesSelected();
    void   AddDirectory(const char* dir, TTreeNode&);
    string GetParentDirectory(TTreeNode&);

    // Data members
    //
    TPaneTreeWindow* TreeWind;
    TPaneListWindow* ListWind;
    TImageList*  Images;

  DECLARE_RESPONSE_TABLE(TClientWindow);
  DECLARE_HELPCONTEXT(TClientWindow);
};


//
// class TSpeedBallWindow
// ~~~~~ ~~~~~~~~~~~~~~~~
// Class to manage the bouncing ball using WinG.
// Has context-sensitive menu.
//
class TSpeedBallWindow : public TWindow {
  public:
    // Constructors
    //
    TSpeedBallWindow(TWindow* parent);

    // Overides
    //
    void SetupWindow();
    void CleanupWindow();
    bool IdleAction(long);
    void Paint(TDC&, bool, TRect&);

    // Event handlers
    //
    void EvSize(uint, TSize&);
    void EvPaletteChanged(HWND hWndPalChg);
    bool EvQueryNewPalette();

    // These data members are public to simplify usage.
    // A real application would make these private with accessors.
    //
    uint32        Delay;
    bool          EnableSound;
    bool          BlitterBlocks;
    TDiBitmap*    BallBitmap;

  private:
    // Varibales for tracking speed ball position, limit and delta.
    //
    int XLimit;
    int YLimit;
    int XDelta;
    int YDelta;
    int XPosition;
    int YPosition;

    // State variable for SpritBitBlt or CopyBitBlt.
    //
    TClientDC*      ClientDC;
    TPalette*       Palette;
    TDibDC*         BallDC;
    TDibDC*         DisplayDC;
    TDiBitmap*      DisplayBitmap;
    TMciWaveAudio*  WaveAudio;

  DECLARE_RESPONSE_TABLE(TSpeedBallWindow);
};

//
// class TAboutWindow
// ~~~~~ ~~~~~~~~~~~~
// Manages the About window.
// Has context-sensitive help.
//
class TAboutWindow : public TLayoutWindow {
  public:
    TAboutWindow(TWindow* parent);

    void SetupWindow();
    void CleanupWindow();

    void CmOk();
    void CmOptions();
    void CmHelp();

    void EvGetMinMaxInfo(MINMAXINFO far& minmaxinfo);

  private:
    TSpeedBallWindow* SpeedBall;
    TButton*          Ok;
    TButton*          Options;
    TButton*          Help;

  DECLARE_RESPONSE_TABLE(TAboutWindow);
  DECLARE_HELPCONTEXT(TAboutWindow);
};

//
// class TBlazerSplash
// ~~~~~ ~~~~~~~~~~~~~
class TBlazerSplash : public TSplashWindow {
  public:
    TBlazerSplash(TDib& dib,
                  int width,
                  int height,
                  int style = None,
                  uint timeOut = 0,       // in milliseconds
                  const char far* title = 0,
                  TModule* module = 0);
   ~TBlazerSplash();
    TMciWaveAudio* Engine;
};


//
// Global declarations
//
extern TStatusBar*    StatusBar;
extern TComboBox*     ListOfDrives;
extern TBlazerApp*    Application;
extern TClientWindow* ClientWindow;

#define HELPFILENAME "blazer.hlp"
#define INIFILENAME  "blazer.ini"

//
inline TMailer*
TBlazerApp::GetMailer()
{
  return Mailer;
}

#endif // BLAZER_H
