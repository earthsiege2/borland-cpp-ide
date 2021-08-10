//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.7  $
//
// Internal window object thunk creation & maintanance.
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_WINDOW_H)
# include <owl/window.h>
#endif
#if !defined(SERVICES_MEMORY_H)
# include <services/memory.h>
#endif
#include <dos.h>
#if defined(BI_PLAT_WIN32)
# include <stddef.h>
#endif

OWL_DIAGINFO;
DIAG_DECLARE_GROUP(OwlWin);

//
// Creation window pointer for InitWndProc
//
TWindow* _OWLDATA CreationWindow = 0;

void _OWLFUNC
SetCreationWindow(TWindow* w)
{
  // Theoretically, there should always be only one non-zero
  // 'creationWindow' pointer. i.e. we never want to have a case where
  // we're holding on to a pointer waiting to be thunked, and this function 
  // is invoked with yet another valid pointer (Otherwise, we'll fail to 
  // thunk a HWND<->TWindow* pair.
  //
  PRECONDITION(CreationWindow == 0 || w == 0);
  TRACEX(OwlWin, 1, "SetCreationWindow: Old(" << (void*)CreationWindow <<\
                    "), New(" << (void*)w << ')');
  CreationWindow = w;
}

//
// Accessor of CreationWindow
//
TWindow* _OWLFUNC
GetCreationWindow() 
{
  return CreationWindow;
}

uint16 far _OWLFUNC
OWLGetVersion()
{
  return OWLVersion;
}

//
// Initial WndProc called when an Owl window is first created.
// Subclasses the window function by installing the thunk then calls the
// thunk to get this first message to the window.
//
/*OWL_EXPORT*/ TResult CALLBACK OWL_EXPORT16
TWindow::InitWndProc(TWindow::THandle hWnd, uint message, TParam1 param1,
                     TParam2 param2)
{
  // If there's no creation window, i.e. we'll be aliasing a resource, then we
  // can't do anything now.  Create() will take care of it later
  //
  if (!CreationWindow)
    return ::DefWindowProc(hWnd, message, param1, param2);

  // Install "DefWindowProc" as the window function BEFORE we request the
  // subclassings; otherwise it looks like we subclassed "InitWndProc"
  //
  CreationWindow->Handle = hWnd;
#if defined(BI_PLAT_WIN32)
  CreationWindow->DefaultProc = (WNDPROC)GetProcAddress(
      (HINSTANCE)GetModuleHandle("USER32"), "DefWindowProcA");
#else
  CreationWindow->DefaultProc = ::DefWindowProc;
#endif

  // Get the thunk & then zero out creation window so that it is not
  // inadvertently used.
  //
  WNDPROC thunk = CreationWindow->GetThunk();
  SetCreationWindow(0);

  // Set the thunk as the window proc, & call it with this first message.
  //
  ::SetWindowLong(hWnd, GWL_WNDPROC, uint32(thunk));
  return (*(WNDPROC)(thunk))(hWnd, message, param1, param2);
}

//
// Win32 version of the instance thunking mechanism
//
#if defined(BI_PLAT_WIN32)

#include <pshpack1.h>     // This struct MUST be packed

struct TInstanceThunk {
  uint8      Call;
  int        Offset;
  TThunkProc Proc;
  TWindow*   Window;
  uint8      Code[6];
};
#include <poppack.h>

static const int  CODEDISP = offsetof(TInstanceThunk, Code) -
                             offsetof(TInstanceThunk, Proc);

WNDPROC
CreateInstanceThunk(TWindow* w, TThunkProc thunkProc)
{
  TInstanceThunk*  thunk = new TInstanceThunk;

  thunk->Call = 0xE8u;        // CALL rel32
  thunk->Offset = CODEDISP;   // relative displacement to Code[5]
  thunk->Proc = thunkProc;
  thunk->Window = w;

  // POP ECX
  //
  // pop return address of call into ecx (address of member "Proc")
  //
  thunk->Code[0] = 0x59u;

  // MOV EAX,[ECX+4]
  //
  // load "Window" into ebx
  //
  thunk->Code[1] = 0x8Bu;     // MOV r32,r/m32
  thunk->Code[2] = 0x41u;     // eax,disp8[ECX]
  thunk->Code[3] = 0x04u;     // +4

  // JMP [ECX]
  //
  // jump to window function provided
  //
  thunk->Code[4] = 0xFFu;     // JMP r/m32
  thunk->Code[5] = 0x21u;     // [ECX]

  return (WNDPROC)thunk;
}

void
FreeInstanceThunk(WNDPROC proc)
{
  delete (TInstanceThunk*)proc;
}

//
// Win16 version of the instance thunking mechanism
//
#elif defined(BI_PLAT_WIN16)

//
// AllocCSToDSAlias was not declared in windows.h
//
extern "C" uint16 FAR PASCAL AllocCSToDSAlias(uint16);

struct TInstanceThunk {
  char   Code;
  uint16 Offset;

  union Ptr {
    struct TInstanceThunk far* Next;
    TWindow far*               Window;
  } ptr;
};

struct TThunkBlock {
  uint16    Next;
  char      Code[5];
  void far* Proc;
  struct TInstanceThunk Thunks[34];
};

static uint16              ThunkBlockList = 0;
static TInstanceThunk far* ThunkFreeList = 0;

WNDPROC
CreateInstanceThunk(TWindow* w, TThunkProc thunkProc)
{
  char                blockCode[5];
  TThunkBlock far*    block;
  TInstanceThunk far* thunk;
  WNDPROC             objInstance;

  // POP BX
  //
  blockCode[0] = 0x5b;

  // LES BX, CS:[BX]
  //
  blockCode[1] = 0x2e;
  blockCode[2] = 0xc4;
  blockCode[3] = 0x1f;

  // JMP FAR StdWndProc
  //
  blockCode[4] = 0xea;

  if (!ThunkFreeList) {

#if 1
    // Attempt to allocate the memory via an indirect call to 'GlobalAlloc'
    // This allows us to bypass memory trackers which will report that the 
    // memory was never freed. Indeed, the memory is never 'GlobalFree'ed
    // but that's because the DATA is turned into a CODE selector via
    // AllocCStoDSAlias and then cleaned up via a call to 'FreeSelector'.
    //
    typedef HGLOBAL   WINAPI (*pfnGblAlloc)(UINT, DWORD);
    typedef VOID FAR* WINAPI (*pfnGblLock) (HGLOBAL);

    static pfnGblAlloc gblAlloc =(pfnGblAlloc)GetProcAddress(GetModuleHandle("KERNEL"), "GlobalAlloc");
    static pfnGblLock  gblLock  =(pfnGblLock)GetProcAddress(GetModuleHandle("KERNEL"), "GlobalLock");

    CHECK(gblAlloc);
    CHECK(gblLock);

    HGLOBAL hndl = gblAlloc ? (*gblAlloc)(GMEM_FIXED | GMEM_SHARE | GMEM_NOT_BANKED,
                                          sizeof(TThunkBlock)) :
                              GlobalAlloc(GMEM_FIXED | GMEM_SHARE | GMEM_NOT_BANKED,
                                          sizeof(TThunkBlock));
    block = (TThunkBlock far*)(gblLock ? (*gblLock)(hndl) : GlobalLock(hndl));
#else

    block = (TThunkBlock far*)GlobalLock(GlobalAlloc(GMEM_FIXED | GMEM_SHARE | GMEM_NOT_BANKED,
                                         sizeof(TThunkBlock)));
#endif

    block->Next = ThunkBlockList;
    memcpy(block->Code, blockCode, 5);
    block->Proc = (void far*)thunkProc;
    thunk = block->Thunks;

    do {
      thunk->Code = 0xE8;
      thunk->Offset = (2 - 3) - FP_OFF(thunk);
      thunk->ptr.Next = ThunkFreeList;
      ThunkFreeList = thunk;
      thunk = (TInstanceThunk far*)MK_FP(
                    FP_SEG(thunk),
                    FP_OFF(thunk)+sizeof(TInstanceThunk)
                 );
    } while (FP_OFF(thunk) != sizeof(TThunkBlock));

    ThunkBlockList = FP_SEG(block);
    PrestoChangoSelector(FP_SEG(block), FP_SEG(block));
  }

  objInstance = (WNDPROC)ThunkFreeList;
  thunk = (TInstanceThunk far*)MK_FP(AllocCSToDSAlias(FP_SEG(ThunkFreeList)),
                                                      FP_OFF(ThunkFreeList));
  ThunkFreeList = thunk->ptr.Next;
  thunk->ptr.Window = (TWindow far*)w;
  FreeSelector(FP_SEG(thunk));
  return objInstance;
}

void
FreeInstanceThunk(WNDPROC proc)
{
  TInstanceThunk far* thunk =
    (TInstanceThunk far*)MK_FP(AllocCSToDSAlias(FP_SEG(proc)), FP_OFF(proc));

  thunk->ptr.Next = ThunkFreeList;
  FreeSelector(FP_SEG(thunk));
  ThunkFreeList = (TInstanceThunk far*)proc;
}

#endif  // BI_PLAT_XXX
