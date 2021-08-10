#if !defined(SOCKBOUT_H)
#define SOCKBOUT_H

#include <owl/defs.h>
#include "sockdemo.rh"                  // Definition of all resources.


class DlgSockDemoAbout : public TDialog {
  public:
    DlgSockDemoAbout (TWindow *parent, TResId resId = IDD_ABOUT, TModule *module = 0);
    virtual ~DlgSockDemoAbout ();
    void SetupWindow ();
};



class ProjectRCVersion {
  public:
    ProjectRCVersion (TModule *module);
    virtual ~ProjectRCVersion ();

    bool GetProductName (LPSTR &prodName);
    bool GetProductVersion (LPSTR &prodVersion);
    bool GetCopyright (LPSTR &copyright);
    bool GetDebug (LPSTR &debug);

  protected:
    LPBYTE     TransBlock;
    void far*  FVData;

  private:
    ProjectRCVersion (const ProjectRCVersion &);
    ProjectRCVersion & operator =(const ProjectRCVersion &);
};


#endif  // SOCKBOUT_H
