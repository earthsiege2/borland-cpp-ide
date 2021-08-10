// Type Library: INTLDEMO.OLB  Automated Locale Application
// Locale Application 1.0 {ABA228C1-BD21-101C-AF42-040224009C00}\409

#include <ocf/automacr.h>

class TLocaleApplication;
class TLocaleFrame;
class TLocaleWindow;

// TKIND_DISPATCH: TLocaleApplication 1.0 {ABA228C2-BD21-101C-AF42-040224009C00}\409 TLocaleApplication class

class TLocaleApplication : public TAutoProxy {
  public:
    TLocaleApplication() : TAutoProxy(0x409) {}
    // Application Object
    void GetApplication(TLocaleApplication&); // [id(1), propget]
    // Quit application
    void Quit(); // [id(2), method]
    // Locale window
    void GetWindow(TLocaleFrame&); // [id(3), propget]
};

// TKIND_DISPATCH: TLocaleFrame 1.0 {ABA228C3-BD21-101C-AF42-040224009C00}\409 TLocaleFrame class

class TLocaleFrame : public TAutoProxy {
  public:
    TLocaleFrame() : TAutoProxy(0x409) {}
    // Locale window
    void GetWindow(TLocaleWindow&); // [id(1), propget]
    void CLocale(); // [id(2), method]
    void USLocale(); // [id(3), method]
    void UKLocale(); // [id(4), method]
    void FrenchLocale(); // [id(5), method]
    void GermanLocale(); // [id(6), method]
    // Change user interface to English
    void EnglishLanguage(); // [id(7), method]
    // Change user interface to French
    void FrenchLanguage(); // [id(8), method]
    // Change user interface to German
    void GermanLanguage(); // [id(9), method]
};

// TKIND_DISPATCH: TLocaleWindow 1.0 {ABA228C4-BD21-101C-AF42-040224009C00}\409 TLocaleWindow class

class TLocaleWindow : public TAutoProxy {
  public:
    TLocaleWindow() : TAutoProxy(0x409) {}
    // IsAlnum
    void IsAlnum(); // [id(1), method]
    // IsAlpha
    void IsAlpha(); // [id(2), method]
    // IsAscii
    void IsAscii(); // [id(3), method]
    // IsCntrl
    void IsCntrl(); // [id(4), method]
    // IsDigit
    void IsDigit(); // [id(5), method]
    // IsGraph
    void IsGraph(); // [id(6), method]
    // IsLower
    void IsLower(); // [id(7), method]
    // IsPrint
    void IsPrint(); // [id(8), method]
    // IsPunct
    void IsPunct(); // [id(9), method]
    // IsSpace
    void IsSpace(); // [id(10), method]
    // IsUpper
    void IsUpper(); // [id(11), method]
    // IsXDigit
    void IsXDigit(); // [id(12), method]
};
