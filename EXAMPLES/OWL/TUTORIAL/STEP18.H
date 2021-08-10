//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1994 by Borland International
//   Tutorial application -- step18.h
//----------------------------------------------------------------------------
#if !defined(STEP18_H)
#define STEP18_H

class _USERCLASS TDrawDocument;

class TDrawApp : public TApplication, public TOcModule {
  public:
    TDrawApp();

  protected:
    TMDIClient* Client;
    int         DocMode;
    TView*      View;

    // Override methods of TApplication
    void InitInstance();
    void InitMainWindow();

    // Event handlers
    void EvNewView(TView& view);
    void EvCloseView(TView& view);
    void EvDropFiles(TDropInfo dropInfo);
    void CmAbout();

  private:
    // Automation entry points
    void SetShow(bool visible);
    bool GetShow();
    TDrawDocument* AddDoc();
    TDrawDocument* OpenDoc(const char far* name = 0);
    const char far* GetPath();
    // method of TModule ==> const char far* GetName()

  DECLARE_RESPONSE_TABLE(TDrawApp);

  DECLARE_AUTOAGGREGATE(TDrawApp)
    AUTOPROP  (Visible, GetShow,SetShow,      bool, )
    AUTOFUNC0 (NewDoc,  OpenDoc, TAutoObject<TDrawDocument>, )
    AUTOFUNC1 (OpenDoc, OpenDoc, TAutoObject<TDrawDocument>,TAutoString,)
    AUTOPROPRO(AppName, GetName, TAutoString, )
    AUTOPROPRO(FullName,GetPath, TAutoString, )
};

#endif
