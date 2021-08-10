// Form interface definition
#include <ole2.h>

class IMyObj: public IUnknown
{
  virtual int __stdcall GoNext() = 0;
  virtual int __stdcall GoPrev() = 0;
};

extern "C" HWND __import __stdcall MakeTestForm(HWND hwndParent, LPUNKNOWN &pObj);
