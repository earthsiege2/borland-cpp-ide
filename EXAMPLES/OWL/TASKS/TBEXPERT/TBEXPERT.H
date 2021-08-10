//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1995 by Borland International, All Rights Reserved
//
// Filename:    TBExpert.h
//
// Date:        27-Sep-95
//
// Description:
//----------------------------------------------------------------------------
#if !defined(TBExpert_H)
#define TBExpert_H

#if !defined(OWL_LAYOUTWI_H)
# include <owl/layoutwi.h>
#endif
#if !defined(OWL_LISTWIND_H)
# include <owl/listwind.h>
#endif
#if !defined(OWL_IMAGELST_H)
# include <owl/imagelst.h>
#endif
#if !defined(OWL_GADGETWI_H)
# include <owl/gadgetwi.h>
#endif
#if !defined(OWL_TIMEGADG_H)
# include <owl/timegadg.h>
#endif
#if !defined(OWL_MODEGAD_H)
# include <owl/modegad.h>
#endif
#if !defined(OWL_BUTTONGA_H)
# include <owl/buttonga.h>
#endif
#if !defined(OWL_TEXTGADG_H)
# include <owl/textgadg.h>
#endif
#include <fstream.h>
#include <dir.h>

#include "TBExpert.rh"

class TTBExpertWindow;
class TGadgetFactory;


//
// class TBExpertApplication
// ~~~~~ ~~~~~~~~~~~~~~~~~~
class TTBExpertApp : public TApplication {
  public:
    TTBExpertApp();
   ~TTBExpertApp();
    void InitMainWindow();

  private:
    void GenerateDefines(ofstream&);
    void GenerateDeclarations(ofstream&);
    void GenerateCode(ofstream&);
};


//
// class TStatusManager
// ~~~~~ ~~~~~~~~~~~~~~
class TStatusManager : public TLayoutWindow {
  public:
    enum TStatus {
      BeforeDrag,
      BeginDrag,
      Dragging,
      EndDrag,
      ModifyGadget,
    };

    TStatusManager(TWindow* parent);
   ~TStatusManager();

    void SetupWindow();
    bool EvEraseBkgnd(HDC);

    void SetDragStatus(TStatus status, int factoryIndex = 0);

  private:
    void ModifyGadgetFactory(int factoryIndex);
    void SetLayoutMetrics();
    void SetBeforeDrag();
    void SetBeginDrag();
    void SetDragging();
    void SetEndDrag();

    TWindow* Window;
    TStatus  Status;
    TStatus  PrevStatus;
    TTBExpertWindow* TBExpertWindow;

  DECLARE_RESPONSE_TABLE(TStatusManager);
};


//
// class TDynamicButtonGadget
// ~~~~~ ~~~~~~~~~~~~~~~~~~~~
class TDynamicButtonGadget : public TButtonGadget {
  public:
    TDynamicButtonGadget(const char* pathToDib,
                         int    id,
                         TType  type = Command,
                         bool   enabled = false, // initial state before cmd enabling
                         TState state = Up,
                         bool   sharedGlyph = false);
   ~TDynamicButtonGadget();
    TDib* GetGlyphDib();

  private:
    char* PathToDib;
};


//
// class TGadgetManager
// ~~~~~ ~~~~~~~~~~~~~~
class TGadgetManager : public TGadgetWindow {
  public:
    TGadgetManager(TWindow*        parent = 0,
                   TTileDirection  direction = Horizontal,
                   TFont*          font = new TGadgetWindowFont,
                   TModule*        module = 0);
   ~TGadgetManager();

    void SetupWindow();

  private:
    TGadget*        LastGadget;
    TStatusManager* StatusManager;

    void EvKillFocus(THandle hWndGetFocus);
    void EvLButtonDown(uint modKeys, TPoint& point);
    void EvMouseMove(uint modKeys, TPoint& point);

  DECLARE_RESPONSE_TABLE(TGadgetManager);
};


//
// class TGadgetManagerPlaceHolder
// ~~~~~ ~~~~~~~~~~~~~~~~~~~~~~~~~
class TGadgetManagerPlaceHolder : public TLayoutWindow {
  public:
    TGadgetManagerPlaceHolder(TWindow* parent);
   ~TGadgetManagerPlaceHolder();

    void SetupWindow();
    TResult EvCommand(uint id, THandle hWndCtl, uint notifyCode);
    void    EvCommandEnable(TCommandEnabler& ce);
    bool    EvEraseBkgnd(HDC);

    void CreateGadgetManager();
    void DeleteGadgetManager();

  private:
    TGadgetManager* Manager;

  DECLARE_RESPONSE_TABLE(TGadgetManagerPlaceHolder);
};


//
// class TBExpertWindow
// ~~~~~ ~~~~~~~~~~~~~
class TTBExpertWindow : public TLayoutWindow {
  public:
    TTBExpertWindow();
   ~TTBExpertWindow();

    void SetupWindow();
    void CleanupWindow();

    // handle dragging
    //
    void EvLButtonUp(uint modKeys, TPoint& point);
    void EvMouseMove(uint modKeys, TPoint& point);
    void LvnBeginDrag(TListWindow*, TLwNotify& notify);
    void LvnKnownBeginDrag(TLwNotify& notify);
    void LvnDynamicBeginDrag(TLwNotify& notify);

    TStatusManager* GetStatusManager();

  private:
    void SetupKnownListWindow();
    void SetDynamicDir(const char* dir);
    void GadgetDropped(TListWindow* window, char* gadgetName, int item);
    TResult EvDoneModifyingGadget(TParam1, TParam2);

    TListWindow*    KnownListWindow;
    TImageList*     KnownImageList;
    TListWindow*    DynamicListWindow;
    TImageList*     DynamicImageList;
    TStatusManager* StatusManager;
    TGadgetManagerPlaceHolder* GadgetManagerHolder;

    // data members used for dragging
    //
    TImageList*     DragImage;
    TRect           DragOffset;
    TListWindow*    DragListWindow;
    int             DragItem;

  DECLARE_RESPONSE_TABLE(TTBExpertWindow);
};


//
// class TGadgetFactory
// ~~~~~ ~~~~~~~~~~~~~~
class TGadgetFactory {
  public:
    enum TGadgetType {
      Separator, Mode, Time, Text, Button
    };

    // Various constructors
    //
    TGadgetFactory(int id, TGadget::TBorderStyle); // time gadget
    TGadgetFactory(int id, TGadget::TBorderStyle, int data);
    TGadgetFactory(int id, TGadget::TBorderStyle, int key, const char* text);
    TGadgetFactory(int id, TGadget::TBorderStyle, TTextGadget::TAlign, uint, const char*);
    TGadgetFactory(int id, TGadget::TBorderStyle, TButtonGadget::TType,
                   TButtonGadget::TState, const char*);

   ~TGadgetFactory();

    // Accessors
    //
    int  GetId();
    void SetId(int id);

    const char* GetResId();
    void SetResId(const char* resId);

    int  GetBorderStyle();
    void SetBorderStyle(int style);

    // Text
    //
    int  GetAlign();
    void SetAlign(int);

    uint GetNumChars();
    void SetNumChars(uint numChars);

    const char* GetGadgetText();
    void SetGadgetText(const char* text);

    // Mode
    //
    int  GetKey();
    void SetKey(int key);

    // Button
    //
    int  GetButtonType();
    void SetButtonType(int type);

    int  GetButtonState();
    void SetButtonState(int state);

    // Generating code
    //
    TGadget* CreateGadget(int index);
    void GenerateCode(ofstream& f);
    void GenerateDefine(ofstream& f);

    TGadgetType GetType();

  private:
    void Init(int id, TGadget::TBorderStyle, const char* resId);
    void GenerateProperId(ofstream& f);

    TGadgetType Type;

    // TGadget
    //
    int                   Id;
    char*                 ResId;
    TGadget::TBorderStyle BorderStyle;

    // Separator
    //
    int Width;

    // Text
    //
    TTextGadget::TAlign  Align;
    uint                 NumChars;
    char*                GadgetText;

    // Mode
    //
    int Key;

    // Button
    //
    TButtonGadget::TType  ButtonType;
    TButtonGadget::TState ButtonState;
    char*                 PathToBmp;
};

//----------------------------------------------------------------------------
// Inline implementations
//
inline TStatusManager*
TTBExpertWindow::GetStatusManager()
{
  return StatusManager;
}

inline TGadgetFactory::TGadgetType
TGadgetFactory::GetType()
{
  return Type;
}

inline int
TGadgetFactory::GetId()
{
  return Id;
}

inline const char*
TGadgetFactory::GetResId()
{
  return ResId;
}

inline int
TGadgetFactory::GetBorderStyle()
{
  return (int)BorderStyle;
}

// Text
//
inline int
TGadgetFactory::GetAlign()
{
  return (int)Align;
}

inline uint
TGadgetFactory::GetNumChars()
{
  return NumChars;
}

inline const char*
TGadgetFactory::GetGadgetText()
{
  return GadgetText;
}

// Mode
//
inline int
TGadgetFactory::GetKey()
{
  return Key;
}

// Button
//
inline int
TGadgetFactory::GetButtonType()
{
  return (int)ButtonType;
}

inline int
TGadgetFactory::GetButtonState()
{
  return (int)ButtonState;
}


//----------------------------------------------------------------------------
// Globals
//
extern TGadgetFactory** GadgetFactories;
extern int CountOfGadgetFactories;

const int MaxGadgetFactories = 100;
const int DummyGadgetIdBase = 400;
const int KnownListWindowId = 101;
const int DynamicListWindowId = 102;

const int WUM_DONEMODIFYINGGADGET = WM_USER + 0x875;

extern char OriginalDir[MAXPATH];
extern char CurrentDir[MAXPATH];

extern bool Generate;

struct TGeneratedNames {
  char* FrameInstance;
  char* ControlBarInstance;

  TGeneratedNames();
 ~TGeneratedNames();
};

extern TGeneratedNames Names;

#endif


