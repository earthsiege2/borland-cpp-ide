//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1991, 1994 by Borland International, All Rights Reserved
//
//   Internal object thunk creation & maintanance.
//----------------------------------------------------------------------------
#include <owl/owlpch.h>
#include <owl/window.h>
#include <dos.h>
#include <mem.h>
#if defined(BI_PLAT_WIN32)
# include <stddef.h>
#endif

LRESULT FAR PASCAL _export StdWndProc(HWND, uint, WPARAM, LPARAM);
TProcInstance StdWndProcInstance((FARPROC)StdWndProc);

//
// Creation window pointer for InitWndProc
//
TWindow* _OWLDATA CreationWindow = 0;

void _OWLFUNC
SetCreationWindow(TWindow* w)
{
  CreationWindow = w;
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
LRESULT CALLBACK __export
InitWndProc(HWND hWindow, uint message, WPARAM wParam, LPARAM lParam)
{
  // If there's no creation window, i.e. we'll be aliasing a resource,
  // then we can't do anything now.  Create() will take care of it later
  //
  if (!CreationWindow)
    return ::DefWindowProc(hWindow, message, wParam, lParam);

  // install "DefWindowProc" as the window function BEFORE we request the
  // subclassings; otherwise it looks like we subclassed "InitWndProc"
  //
  CreationWindow->HWindow = hWindow;
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
  CreationWindow = 0;

  // Set the thunk as the window proc, & call it with this first message.
  //
  SetWindowLong(hWindow, GWL_WNDPROC, uint32(thunk));
  return (*(WNDPROC)(thunk))(hWindow, message, wParam, lParam);
}

//
// Win32 version of the instance thunking mechanism
//
#if defined(BI_PLAT_WIN32)

struct TInstanceThunk {
  char     Call;
  int      Offset;
  PROC     WndProcPtr;
  TWindow* Window;
  char     Code[6];
};

static const int  CODEDISP = offsetof(TInstanceThunk, Code) -
                             offsetof(TInstanceThunk, WndProcPtr);

WNDPROC
CreateInstanceThunk(TWindow* w)
{
  TInstanceThunk*  thunk = new TInstanceThunk;

  thunk->Call = 0xE8;         // CALL rel32
  thunk->Offset = CODEDISP;   // relative displacement to Code[5]
  thunk->WndProcPtr = StdWndProcInstance;
  thunk->Window = w;

  //
  // POP ECX
  //
  // pop return address of call into ecx (address of member "WndProcPtr")
  //
  thunk->Code[0] = 0x59;

  //
  // MOV EAX,[ECX+4]
  //
  // load "Window" into ebx
  //
  thunk->Code[1] = 0x8B;     // MOV r32,r/m32
  thunk->Code[2] = 0x41;     // eax,disp8[ECX]
  thunk->Code[3] = 0x04;     // +4

  //
  // JMP [ECX]
  //
  // jump to window function StdWndProc
  //
  thunk->Code[4] = 0xFF;     // JMP r/m32
  thunk->Code[5] = 0x21;     // [ECX]

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
  void far* WndProcPtr;
  struct TInstanceThunk Thunks[34];
};

static uint16              ThunkBlockList = 0;
static TInstanceThunk far* ThunkFreeList = 0;

WNDPROC
CreateInstanceThunk(TWindow* w)
{
  char                blockCode[5];
  TThunkBlock far*    block;
  TInstanceThunk far* thunk;
  WNDPROC             objInstance;

  // POP BX
  blockCode[0] = 0x5b;

  // LES BX, CS:[BX]
  blockCode[1] = 0x2e;
  blockCode[2] = 0xc4;
  blockCode[3] = 0x1f;

  // JMP FAR StdWndProc
  blockCode[4] = 0xea;

  if (!ThunkFreeList) {
    block = (TThunkBlock far*)GlobalLock(GlobalAlloc(GMEM_FIXED | GMEM_SHARE | GMEM_NOT_BANKED,
                                         sizeof(TThunkBlock)));
    block->Next = ThunkBlockList;
    memcpy(block->Code, blockCode, 5);
    block->WndProcPtr = (void far*)StdWndProcInstance;
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
FreeInstanceThunk(WNDPROC p)
{
  TInstanceThunk far* thunk = (TInstanceThunk far*)MK_FP(AllocCSToDSAlias(FP_SEG(p)),
                                                       FP_OFF(p));

  thunk->ptr.Next = ThunkFreeList;
  FreeSelector(FP_SEG(thunk));
  ThunkFreeList = (TInstanceThunk far*)p;
}

#endif  // BI_PLAT_XXX
