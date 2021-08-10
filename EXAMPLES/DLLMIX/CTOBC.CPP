//----------------------------------------------------------------------------
// Mixing BC++ built 32-bit DLL's with non-BC applications.
// Copyright (c) 1996 by Borland International, All Rights Reserved
//
// This application tests calling into a 32-bit DLL built with Borland C++. The
// code has been conditionalized to be built with either Borland or Microsoft
// tools and was verified with Borland C++ 5.0 and Microsoft Visual C++ 4.1.
//----------------------------------------------------------------------------
#include <windows.h>
#include <stdio.h>      // stdio.h
#include "CToBC.rh"
#include "bcdll.h"      // functions from bcdll.dll

BOOL CALLBACK DlgProc(HWND hDlg, UINT msg, WPARAM wP, LPARAM lP);

const char testDll[] = "BCDLL.DLL";

#if defined(__BORLANDC__)
   const char toolSet[] = "Borland C++";
#elif defined(_MSC_VER)
   const char toolSet[] = "Visual C++";
#else
   const char toolSet[] = "Unknown tool set";
#endif

bool			(__stdcall *bcMessage)(const char * msg);
long 			(__cdecl   *bcMultiply)(short s, int i);
long double	(__stdcall *bcAverage)(double d, float f);
void 			(__cdecl   *bcExceptionTest)(void);
void 			(__stdcall *bcUnhandledException)(void);

///////////////////////////////////////////////////////////////////////////////
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, int)
	{
   //
   // Load the Dynamic Link LIbrary bcdll.dll
   //
   HINSTANCE hLib = LoadLibrary(testDll);
   if((unsigned)hLib<=HINSTANCE_ERROR)
   	{
      char bfr[40];
      wsprintf(bfr, "Failure loading library: %s", testDll);
      MessageBox(NULL, bfr, toolSet, MB_OK|MB_APPLMODAL);
      return 1;
      }

   //
   // Get all the entry points for the functions we wish to test. Typedef's can
   // be used to simplify casting the retrun value from GetProcAddress.
   //
   bcMessage = (bool(__stdcall*)(const char*)) GetProcAddress(hLib, "Message");
   bcMultiply = (long(__cdecl*)(short, int)) GetProcAddress(hLib, "_Multiply");
   bcAverage = (long double(__stdcall*)(double, float)) GetProcAddress(hLib, "Average");
   bcExceptionTest = (void(__cdecl*)()) GetProcAddress(hLib, "_ExceptionTest");
   bcUnhandledException = (void(__stdcall*)()) GetProcAddress(hLib, "UnhandledException");

   //
   // GetProcAddress returns null on failure
   //
   if( bcMessage == NULL || bcMultiply == NULL || bcAverage == NULL
   		|| bcExceptionTest == NULL || bcUnhandledException == NULL)
		{
      MessageBox(NULL, "Failure locating procedures.", toolSet,
            MB_OK|MB_APPLMODAL);
      return 1;
      }

   //
   // Create a modal dialog as the application main window.
   //
	DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), NULL, (DLGPROC)DlgProc);

   if((unsigned)hLib>HINSTANCE_ERROR)
   	FreeLibrary(hLib);
   return 0;
   }

//
// Data used by DlgProc
//
static short s;
static int i;
static long lAns;
static float f;
static double d;
static long double ldAns;
static char bfr [100];

//
// Main window procedure
//
BOOL APIENTRY DlgProc(HWND hDlg, UINT msg, WPARAM wP, LPARAM /* lP */)
	{
   switch (msg)
   	{
      case WM_INITDIALOG:
         sprintf(bfr, "Calling from %s to a Borland C++ DLL", toolSet);
         SetWindowText(hDlg, bfr);
      	return true;

      case WM_COMMAND:
      	switch(wP)
         	{
      		case IDC_BTN_MESSAGE:   // Verify pointer and buffer handling
               sprintf(bfr, "A message from %s", toolSet);
               bcMessage(bfr);
               return true;

      		case IDC_BTN_MULTIPLY:  // Verify calling convention match
               s = 55;
            	i = -1024;
         		lAns = bcMultiply(s, i);
               sprintf(bfr, "%d * %d = %ld", s, i, lAns);
               MessageBox(hDlg, bfr, toolSet, MB_OK|MB_APPLMODAL);
            	return true;

      		case IDC_BTN_AVERAGE:   // Verify handling of real numbers
            	d = 6232.001;
               f = 128.327;
            	ldAns = bcAverage(d, f);
               sprintf(bfr, "The average of %5f and %5f is %5Lf", d, f, ldAns);
      			MessageBox(hDlg, bfr, toolSet, MB_OK|MB_APPLMODAL);
            	return true;

      		case IDC_BTN_EXCEPTION: // Verify EH isolated in DLL
            	bcExceptionTest();
            	return true;

      		case IDC_BTN_UNHANDLED: // Verify handling exceptions from the DLL
            	try{  // The DLL will throw a C++ exception for type char *
            		bcUnhandledException();
                  }
               catch(char *msg)  // A BC-compiled app will recognize the type
                  {
                  sprintf(bfr, "Application caught exception thrown from DLL: %s", msg);
                  MessageBox(hDlg, bfr, toolSet, MB_OK|MB_APPLMODAL);
                  }
               catch(...)  // A non-BC app will catch an un-typed exception
               	{
                  MessageBox(hDlg, "Application caught exception thrown from DLL",
                  		toolSet, MB_OK|MB_APPLMODAL);
                  }
            	return true;

      		case IDOK:
      		case IDCANCEL:
            	EndDialog(hDlg, 0);
            	return true;
            }
         break;
      }
   return false;
	}
