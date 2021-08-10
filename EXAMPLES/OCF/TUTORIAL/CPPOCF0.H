// ---------------------------------------------------------------------------
// Copyright (C) 1994 Borland International
// CppOcf0.h
// ---------------------------------------------------------------------------
#if !defined(CPPOCF0_H)
#define CPPOCF0_H
#include "CppOcf0.rh"

//
// Global defines
//
#define APPSTRING   "CppOcf0"
#define MENUNAME    "CppOcf0Menu"
#define CLASSNAME   "CppOcf0Class"
#define TITLE       "CppOcf0 Window"

//
// function prototypes
//
int PASCAL WinMain(HINSTANCE, HINSTANCE, char far*, int);
bool InitApplication(HINSTANCE);
bool InitInstance(HINSTANCE, int);


//
// Main Window functions
//
long CALLBACK _export MainWndProc(HWND, uint, WPARAM, LPARAM);
bool MainWnd_OnCreate(HWND hwnd, CREATESTRUCT FAR* lpCreateStruct);
void MainWnd_OnClose(HWND hwnd);
void MainWnd_OnDestroy(HWND);
void MainWnd_OnPaint(HWND hwnd);
void MainWnd_OnCommand(HWND hwnd, int id, HWND hwndCtl, uint codeNotify);

#endif

