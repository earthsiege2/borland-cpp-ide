// ---------------------------------------------------------------------------
// Copyright (C) 1994 Borland International
// CppOcf2.h
// ---------------------------------------------------------------------------
#if !defined(CppOcf2_H)
#define CppOcf2_H
#include "CppOcf2.rh"

//
// Global defines
//
#define APPSTRING   "CppOcf2"
#define MENUNAME    "CppOcf2Menu"
#define CLASSNAME   "CppOcf2Class"
#define TITLE       "CppOcf2 Window"
#define VIEWCLASSNAME "SrvrViewClass"


//
// extern for global variables
//
//extern HINSTANCE     _hInstance;
//extern TOcRegistrar* OcRegistrar;
//extern TOcApp*       OcApp;
//extern TOcDocument*  OcDoc;
//extern TOcRemView*   OcRemView;


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
bool MainWnd_OnOcAppShutDown(HWND hwnd);


//
// View window functions
//
long CALLBACK _export ViewWndProc(HWND, uint, WPARAM, LPARAM);
bool ViewWnd_OnCreate(HWND hwnd, CREATESTRUCT FAR* lpCreateStruct);
void ViewWnd_OnClose(HWND hwnd);
void ViewWnd_OnDestroy(HWND);
void ViewWnd_OnPaint(HWND hwnd);
void ViewWnd_OnSize(HWND hwnd, UINT state, int cx, int cy);
void ViewWnd_OnTimer(HWND hwnd, UINT id);
long ViewWnd_OnOcEvent(HWND hwnd, WPARAM, LPARAM);
bool ViewWnd_OnOcViewClose(HWND hwnd);


#endif

