//----------------------------------------------------------------------------
// ObjectComponents - (C) Copyright 1994 by Borland International
// OLE registration test
//----------------------------------------------------------------------------
#include "ocf/ocreg.h"
#include "regtest.rh"

#if !defined(BI_PLAT_WIN16)
inline int GetTextExtent(HDC hDC, const char* buf, int len) {
  SIZE s;
  GetTextExtentPoint(hDC, buf, len, &s);
  return s.cx;  // return width portion
}
#endif

//____________________________________________________________________________
//
//  Example registration tables
//____________________________________________________________________________

REGISTRATION_FORMAT_BUFFER(100)

BEGIN_REGISTRATION(myappreg)
 REGDATA(clsid,      "{01234567-1234-5678-1122-334455667788}")
 REGDATA(progid,     "MySample.Application.1")
 REGDATA(description,"My Sample 1.0 Application")
 REGDATA(appname,    "My Sample 1.0")
 REGDATA(cmdline,    "/automation")
 REGDATA(version,    "1.2")
END_REGISTRATION

BEGIN_REGISTRATION(mydocreg)
 REGDATA(description,"My Sample 1.0 Document")
 REGDATA(extension,  "myd")
 REGDATA(directory,  "c:\temp")
 REGDATA(docfilter,  "*.drw;*.drx")
 REGDATA(debugger,   "tdw -l")
 REGDATA(clsid,      "{01234568-1234-5678-1122-334455667788}")
 REGDATA(progid,     "MySample.Document.1")
 REGDATA(menuname,   "Document")
 REGDATA(insertable,0)
 REGDATA(usage,    ocrMultipleUse)
 REGDATA(verb0,      "&Edit")
 REGDATA(verb1,      "&Open")
 REGDATA(verb2,      "&Play")
 REGVERBOPT(verb2, ocrGrayed, ocrOnContainerMenu | ocrNeverDirties)
 REGFORMAT(0, ocrEmbedSource,  ocrContent, ocrIStorage, ocrGet)
 REGFORMAT(1, ocrText,         ocrContent, ocrHGlobal,  ocrGetSet)
 REGFORMAT(2, ocrMetafilePict, ocrContent, ocrMfPict,   ocrGet)
 REGFORMAT(3, ocrRichText,     ocrContent, ocrHGlobal,  ocrGetSet)
 REGSTATUS(all,     ocrNoSpecialRendering)
 REGSTATUS(icon,    ocrOnlyIconic)
 REGSTATUS(content, ocrRecomposeOnResize)
 REGICON(1)
 REGITEM("CLSID\\<clsid>\\Conversion\\Readable\\Main","FormatX,FormatY")
END_REGISTRATION

BEGIN_REGISTRATION(mytplreg)
 REGDATA(description,"My Sample Draw View")
 REGDATA(filter,     "*.drw;*.drx")
 REGDATA(defaultext, "DVW")
 REGDATA(directory,  0)
END_REGISTRATION

TRegItem regAppName[2] = {{"appname",{myappreg["appname"]}}, {0,{0}}};

//____________________________________________________________________________
//
//  Example registration table processing
//____________________________________________________________________________

TRegList* MyRegClasses[] = { &myappreg, &mydocreg, 0 };

const char*
RegisterClasses(TRegList** regClasses, // null-term. array of reg lists
                HINSTANCE module,      // 0 defaults to current task
                ostream& out,          // open ostream to stream reg entries
                TLangId lang = LangSysDefault, // language for registration
                char* filter = 0,      // internal use to restrict entries
                TRegItem* defaults = regAppName)// optional registration default list
{
  // write registration file header
  //
  out << "REGEDIT\n";

  // loop to register each class
  //
  for ( ; *regClasses != 0; regClasses++) {
    try {
      ::OcRegisterClass(**regClasses, module, out, lang, filter, defaults);
    }
    catch (TXRegistry& xcpt) {
      return xcpt.Key;
    }
  }
  return 0;
}

int UnregisterClasses(TRegList** regClasses)
{
  int  errorCount = 0;
  for ( ; *regClasses != 0; regClasses++) {  // loop to unregister each class
    errorCount += OcUnregisterClass(**regClasses);
  }
  return errorCount;
}

//____________________________________________________________________________
//
//  Example code to exercise registration
//____________________________________________________________________________

#include <fstream.h>
#include <strstrea.h>

#define WM_USERSTAT (WM_USER + 100)

bool CALLBACK __export
DlgProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
  if (msg == WM_INITDIALOG) {
    return 1;
  } else if (msg == WM_COMMAND) {
    ::PostMessage(hDlg, WM_USERSTAT, wParam, lParam);
    return 1;
  } else if (msg == WM_CLOSE) {
    ::PostMessage(hDlg, WM_USERSTAT, IDABORT, 0);
    return 1;
  } else if (msg == WM_DESTROY) {
    ::PostMessage(hDlg, WM_USERSTAT, IDABORT, 0);
    return 1;
  }
  return 0;
}

int PASCAL
WinMain(HINSTANCE hInst, HINSTANCE/*prev*/, char far* /*cmdLine*/, int/*show*/)
{
  HWND hWnd = ::CreateDialog(hInst, MAKEINTRESOURCE(IDD_MAIN), 0, (DLGPROC)DlgProc);
  if (!hWnd) {
    ::MessageBox(0, "Could Not Create Dialog Box", "Error", MB_OK);
    return 1;
  }
  for (;;){
    try {
      MSG msg;
      int id = 0;
      while (!id && ::GetMessage(&msg, 0, 0, 0)) {
        if (msg.message == WM_USERSTAT)
          id = msg.wParam;
        else
          ::IsDialogMessage(hWnd, &msg);
      }
      if (id == IDABORT || id == IDOK)
        break;
      int errorCount = 0;
      const char* errorText = 0;
      switch (id) {
        case IDC_DISPLAY:  { // Show reg entries in listbox
          ::SendDlgItemMessage(hWnd, IDC_REGLIST, LB_RESETCONTENT, 0, 0);
          strstream strm;
          errorText = RegisterClasses(MyRegClasses, hInst, strm);
          if (errorText) {
            break;
          }
          char buf[512];
          strm.getline(buf, sizeof(buf)); // skip reg file header written above
          int maxlen = 0;
          HDC hDC = ::GetDC(hWnd);
          HFONT hFont = (HFONT)::SendDlgItemMessage(hWnd, IDC_REGLIST, WM_GETFONT,0,0);
          HFONT oldFont = (HFONT)::SelectObject(hDC, hFont);
          while (!strm.eof()) {
            strm.getline(buf, sizeof(buf));
            ::SendDlgItemMessage(hWnd, IDC_REGLIST, LB_ADDSTRING,
                                       0, (LPARAM)(char far*)buf);
            int n = (int)::GetTextExtent(hDC, buf, lstrlen(buf));
            if (n > maxlen)
              maxlen = n;
          }
          ::SelectObject(hDC, oldFont);
          ::ReleaseDC(hWnd, hDC);
          ::SendDlgItemMessage(hWnd, IDC_REGLIST, LB_SETHORIZONTALEXTENT,
                               maxlen, 0);
          break;
        }
        case IDC_REGISTER: { // Write all info to registry
          strstream strm;
          errorText = RegisterClasses(MyRegClasses, hInst, strm);
          if (errorText) {
            break;
          }
          try {
            OcRegistryUpdate(strm);
          }
          catch (TXRegistry& xcpt) {
            errorText = xcpt.Key;
          }
          break;
        }
        case IDC_UNREGISTER: { // Delete all info from registry
          errorCount = UnregisterClasses(MyRegClasses);
          break;
        }
        case IDC_WRITEFILE: { // Write registration file
          ofstream out;
          out.open("myapp.reg");
          errorText = RegisterClasses(MyRegClasses, hInst, out);
          out.close();
          break;
        }
        case IDC_VERIFY: { // Validate registration file with single check
          strstream strm;
          RegisterClasses(MyRegClasses, hInst, strm,LangSysDefault,"\001");
          errorCount = OcRegistryValidate(strm);
          break;
        }
        case IDC_COMPARE: { // Validate entire registration file
          strstream strm;
          RegisterClasses(MyRegClasses, hInst, strm);
          errorCount = OcRegistryValidate(strm);
          break;
        }
        default:
          continue;
      }
      char buf[40];
      ::GetDlgItemText(hWnd, id, buf, sizeof(buf)-1);
      ::SetDlgItemText(hWnd, IDC_OP, buf);
      if (!errorText)
        wsprintf(((char*)errorText = buf), "%d", errorCount);
      ::SetDlgItemText(hWnd, IDC_ERRORS, buf);
    }
    catch (TXBase& x) {
      ::MessageBox(0, x.why().c_str(), "OLE Exception", MB_OK);
    }
  }
  return 0;
}
