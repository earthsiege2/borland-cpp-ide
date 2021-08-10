//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   include\owl\module.h
//   Definition of class TModule.  TModule defines the
//   basic behavior for OWL libraries and applications.
//----------------------------------------------------------------------------
#if !defined(__OWL_MODULE_H)
#define __OWL_MODULE_H

#if !defined(__OWL_OWLDEFS_H)
  #include <owl\owldefs.h>
#endif
#if !defined(__OWL_POINT)
  #include <owl\point.h>
#endif
#if !defined(__OWL_EVENTHAN_H)
  #include <owl\eventhan.h>
#endif
#if !defined(__OWL_EXCEPT_H)
  #include <owl\except.h>
#endif

class _OWLCLASS TWindow;
class _OWLCLASS TDialog;

//
//  class TModule
//  ----- -------
//
class _OWLCLASS TModule : public TEventHandler, public TStreamableBase {
  public:
    class _OWLCLASS_RTL TXInvalidModule : public TXOwl {
      public:
        TXInvalidModule();
        TXOwl* Clone();
        void Throw();
    };

    //
    // Constructors & destructor
    //
    TModule(const char far* name, BOOL shouldLoad = TRUE);
    TModule(const char far* name, HINSTANCE hInstance);
    TModule(const char far* name, HINSTANCE hInstance, const char far* cmdLine);
    virtual ~TModule();

    //
    // Finish-up initialization of a module
    //
    void          InitModule(HINSTANCE hInstance, const char far* cmdLine);

    operator      HINSTANCE() const {return HInstance;}
    BOOL operator ==(const TModule& other) const
                    {return HInstance == other.HInstance;}
    BOOL          IsLoaded() const {return HInstance > HINSTANCE(32);}

    //
    // Get & set members. Use these instead of directly accessing members
    //
    const char far* GetName() const {return Name;}
    void          SetName(const char far* name);

    HINSTANCE     GetInstance() const {return HInstance;}
    void          SetInstance(HINSTANCE hInstance);

    //
    // Module wide error handler. Called when fatal exceptions are caught.
    //
    virtual int   Error(xmsg& x, unsigned captionResId, unsigned promptResId=0);

    //
    // Windows HINSTANCE related API functions encapsulated
    //
    int           GetModuleFileName(char far* buff, int maxChars)
                    {return ::GetModuleFileName(HInstance, buff, maxChars);}

    FARPROC       GetProcAddress(const char far* fcnName) const
                    {return ::GetProcAddress(HInstance, fcnName);}

  #if !defined(__WIN32__)
    int           GetModuleUsage() const {return ::GetModuleUsage(HInstance);}
    int           GetInstanceData(void* data, int len) const
                    {return ::GetInstanceData(HInstance, (BYTE*)data, len);}
  #endif

    HRSRC         FindResource(TResId id, const char far* type) const
                    {return ::FindResource(HInstance, id, type);}
    HGLOBAL       LoadResource(HRSRC hRsrc) const
                    {return ::LoadResource(HInstance, hRsrc);}
    DWORD         SizeofResource(HRSRC hRsrc) const
                    {return ::SizeofResource(HInstance, hRsrc);}

  #if !defined(__WIN32__)
    int           AccessResource(HRSRC hRsrc) const
                    {return ::AccessResource(HInstance, hRsrc);}
    HGLOBAL       AllocResource(HRSRC hRsrc, DWORD size) const
                    {return ::AllocResource(HInstance, hRsrc, size);}
    RSRCHDLRPROC  SetResourceHandler(const char far* type, RSRCHDLRPROC loadProc) const
                    {return ::SetResourceHandler(HInstance, type, loadProc);}
  #endif

    int           LoadString(UINT id, char far* buf, int maxChars) const;
    HBITMAP       LoadBitmap(TResId id) const
                    {return ::LoadBitmap(HInstance, id);}
    BOOL          GetClassInfo(const char far* name, WNDCLASS far* wndclass) const
                    {return ::GetClassInfo(HInstance, name, wndclass);}
    HACCEL        LoadAccelerators(TResId id) const
                    {return ::LoadAccelerators(HInstance, id);}
    HMENU         LoadMenu(TResId id) const
                    {return ::LoadMenu(HInstance, id);}
    HCURSOR       LoadCursor(TResId id) const
                    {return ::LoadCursor(HInstance, id);}
    HICON         LoadIcon(const char far* name) const
                    {return ::LoadIcon(HInstance, name);}
  #if !defined(__WIN32__)
    HCURSOR       CopyCursor(HCURSOR hCursor) const
                    {return ::CopyCursor(HInstance, hCursor);}
    HICON         CopyIcon(HICON hIcon) const
                    {return ::CopyIcon(HInstance, hIcon);}
  #else
    HICON         CopyIcon(HICON hIcon) const {return ::CopyIcon(hIcon);}
  #endif
                    
  protected:    
    char far* Name;
    HINSTANCE HInstance;

  private:    
    BOOL      ShouldFree;
    
    //
    // hidden to prevent accidental copying or assignment
    //
    TModule(const TModule&);
    TModule& operator =(const TModule&);
    friend ostream& _OWLFUNC operator <<(ostream& os, const TModule& m);

  //
  // Obsolete members for Owl 1 compatibility
  //
  public:
    char far* lpCmdLine;    // Use argv & argc for portability
    TStatus   Status;       // Use exceptions

    TWindow*  ValidWindow(TWindow* win) {return win;}
    TWindow*  MakeWindow(TWindow* win);
    int       ExecDialog(TDialog* dialog);

    virtual void  Error(int errorCode);

    HWND      GetClientHandle(HWND hWnd);
    TWindow*  GetParentObject(HWND hWndParent);

    BOOL      LowMemory() {return FALSE;}
    void      RestoreMemory() {}

  DECLARE_STREAMABLE(_OWLCLASS, TModule, 1);
};

//
// Global pointer to the current module
//
extern TModule* Module;

//
// Exported pointers from OWL modules, implemented in GLOBAL.CPP
//
class _OWLCLASS TDocTemplate;
extern "C" {      // unmanagled to allow loading via LoadLibrary

TDocTemplate** _export PASCAL GetDocTemplateHead(int version);

TModule** _export PASCAL GetModulePtr(int version);

}

//
// Public functions in appdict.cpp that manage the application dictionary--
// updating app dictionary & getting the current application
//
class _OWLCLASS TApplication;
void          _OWLFUNC AddApplicationObject(TApplication* app);
void          _OWLFUNC DeleteApplicationObject();
TApplication* _OWLFUNC GetApplicationObject();

//
// Main entry point for an Owl application
//
int OwlMain(int argc, char* argv[]);

#endif  // __OWL_MODULE_H
