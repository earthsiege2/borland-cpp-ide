// ---------------------------------------------------------------------------
// Copyright (C) 1994 Borland International
// CppOcf1.h
// ---------------------------------------------------------------------------
#if !defined(CPPOCF1_H)
#define CPPOCF1_H
#include "CppOcf1.rh"

//
// Global defines
//
#define APPSTRING   "CppOcf1"
#define MENUNAME    "CppOcf1Menu"
#define CLASSNAME   "CppOcf1Class"
#define TITLE       "CppOcf1 Window"
#define VIEWCLASSNAME "ViewClass"


//
// extern for global variables
//
//extern HINSTANCE     _hInstance;
//extern TOcRegistrar* OcRegistrar;
//extern TOcApp*       OcApp;
//extern TOcDocument*  OcDoc;
//extern TOcView*      OcView;


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
void MainWnd_OnCommand(HWND hwnd, int id, HWND hwndCtl, uint codeNotify);
long MainWnd_OnOcEvent(HWND hwnd, WPARAM, LPARAM);
void MainWnd_OnSize(HWND hwnd, UINT state, int cx, int cy);
const char far* MainWnd_OnOcViewTitle(HWND hwnd);


//
// View window functions
//
long CALLBACK _export ViewWndProc(HWND, uint, WPARAM, LPARAM);
bool ViewWnd_OnCreate(HWND hwnd, CREATESTRUCT FAR* lpCreateStruct);
void ViewWnd_OnClose(HWND hwnd);
void ViewWnd_OnDestroy(HWND);
void ViewWnd_OnPaint(HWND hwnd);
long ViewWnd_OnOcEvent(HWND hwnd, WPARAM, LPARAM);
void ViewWnd_OnSize(HWND hwnd, UINT state, int cx, int cy);
bool ViewWnd_OnOcViewClose(HWND hwnd);


#endif

