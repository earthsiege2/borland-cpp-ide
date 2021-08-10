//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1995 by Borland International, All Rights Reserved
//
// Declares TSpeedPage and TBitBltPage for use with TPropertySheet.
//----------------------------------------------------------------------------
#if !defined(PROPDLGS_H)
#define PROPDLGS_H

#if !defined(OWL_PROPSHT_H)
# include <owl/propsht.h>
#endif
#if !defined(OWL_SLIDER_H)
# include <owl/slider.h>
#endif
#if !defined(OWL_RADIOBUT_H)
# include <owl/radiobut.h>
#endif
#if !defined(OWL_CHECKBOX_H)
# include <owl/checkbox.h>
#endif
#if !defined(OWL_STATIC_H)
# include <owl/static.h>
#endif

//
// class TSpeedPage
// ~~~~~ ~~~~~~~~~~
// A property page to manage the speed of the TAboutWindow.
//
class TSpeedPage : public TPropertyPage {
  public:
    TSpeedPage(int factor, int delta, int delay,
               TPropertySheet* parent, TResId resId,
               const char far* title = 0, TResId iconRes = 0,
               TModule* module = 0);

    // Override virtuals
    //
    void SetupWindow();
    void CleanupWindow();

    // These data members are public to simply usage.
    // A real application would make these private with accessors.
    //
    int FactorValue;
    int DeltaValue;
    int DelayValue;

  private:
    // Forward help message to main window
    //
    void      EvHelp(HELPINFO*);

    TStatic*  RandomFactorPlace;
    THSlider* RandomFactor;
    TStatic*  DeltaPlace;
    THSlider* Delta;
    TStatic*  DelayPlace;
    THSlider* Delay;

  DECLARE_RESPONSE_TABLE(TSpeedPage);
  DECLARE_HELPCONTEXT(TSpeedPage);
};

//
// class TBitBltPage
// ~~~~~ ~~~~~~~~~~~
// A property page to determine how the TAboutWindow bitblts the image
// to the screen. Either using destructive blits or sprite/transparent
// blits.
//
class TBitBltPage : public TPropertyPage {
  public:
    TBitBltPage(bool blitterBlocks, bool sound,
                TPropertySheet* parent, TResId resId,
                const char far* title = 0, TResId iconRes = 0,
                TModule* module = 0);

    // Override virtuals
    //
    void SetupWindow();
    void CleanupWindow();

    // This data member is public to simply usage.
    // A real application would make this private with accessors.
    //
    bool BlitterBlocks;
    bool EnableSound;

  private:
    // Forward help message to main window
    //
    void EvHelp(HELPINFO*);
    void BnDestructiveClicked();
    void BnSpriteClicked();

    TRadioButton* Destructive;
    TRadioButton* Sprite;
    TCheckBox*    Sound;

  DECLARE_RESPONSE_TABLE(TBitBltPage);
  DECLARE_HELPCONTEXT(TBitBltPage);
};


//
// declare Globals
//
extern int RandomMax;
extern int AbsoluteDelta;

#endif // PROPDLGS_H
