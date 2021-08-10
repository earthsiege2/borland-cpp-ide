/*--------------------------------------------------------

       WINAPI.CPP -- CodeGuard Demo Program

The purpose of this example is to demonstrate common CodeGuard
errors. By selecting menu commands various CodeGuard errors will
be produced. In an attempt to aid understanding of program flow,
within the example, a message box is displayed from every function.
THESE ARE NOT CODEGUARD-PRODUCED MESSAGEBOXES and are presented BY
THIS CODEGUARD DEMO solely to help follow the example.

The DEMO message boxes are presented in the form of:
  Title: (name of current source module)
  FunctionName: (name of current funtion)
  Problem demonstrated: (brief description of the demonstrated problem)


 --------------------------------------------------------*/
#define STRICT
#include <windows.h>
#include <string.h>
#include <stdio.h>
#include <io.h>


#include "winapi.rh"

#include "filescg.h"
#include "pointcg.h"
#include "exceptcg.h"
#include "memcg.h"

#include "testdll.h"

#pragma warn -aus

// Some data in DGROUP to demonstrate overruns/underruns.
char  pad1[21];  // pad the buffer which we intend to overrun
char  buf_d[21];
char  pad2[21]; // pad the buffer

char HelpText[]=
"\n\rCodeGuard Demo Program\n\r\n\r\
Warning: This application illustrates some results of bad programming\n\r\
practices. Your system can be destabilized. Be sure to close other\n\r\
important applications before making selections from the menu.";


HINSTANCE ghInstance;

long FAR PASCAL _export WndProc (HWND, UINT, UINT, LONG) ;
#pragma argsused
int PASCAL WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    LPSTR lpszCmdParam, int nCmdShow)
{
   static char szAppName[] = "CG Demo Window" ;
   HWND        hwnd ;
   MSG         msg ;
   WNDCLASS    wndclass ;

   ghInstance = hInstance;
   if (!hPrevInstance)
   {
      wndclass.style         = CS_HREDRAW | CS_VREDRAW ;
      wndclass.lpfnWndProc   = WndProc ;
      wndclass.cbClsExtra    = 0 ;
      wndclass.cbWndExtra    = 0 ;
      wndclass.hInstance     = hInstance ;
      wndclass.hIcon         = LoadIcon (NULL, IDI_APPLICATION) ;
      wndclass.hCursor       = LoadCursor (NULL, IDC_ARROW) ;
      wndclass.hbrBackground = (HBRUSH)GetStockObject (WHITE_BRUSH) ;
      wndclass.lpszMenuName  = MAKEINTRESOURCE( CG_MENU );
      wndclass.lpszClassName = szAppName ;
      RegisterClass (&wndclass) ;
    }

    hwnd = CreateWindow (szAppName,          // window class name
          "CodeGuard Demo Program",          // window caption
          WS_OVERLAPPEDWINDOW,               // window style
          CW_USEDEFAULT,                     // initial x position
          CW_USEDEFAULT,                     // initial y position
          CW_USEDEFAULT,                     // initial x size
          CW_USEDEFAULT,                     // initial y size
          NULL,                              // parent window handle
          NULL,                              // window menu handle
          hInstance,                         // program instance handle
          NULL) ;                            // creation parameters

     ShowWindow (hwnd, nCmdShow) ;
     UpdateWindow (hwnd) ;

     while (GetMessage (&msg, NULL, 0, 0))
     {
        TranslateMessage (&msg) ;
        DispatchMessage (&msg) ;
     }
     return msg.wParam ;
     }

char array[1000];
BITMAPINFO bmi;

long FAR PASCAL _export WndProc (HWND hwnd, UINT message, UINT wParam,
                                                          LONG lParam)
{
     HDC         hdc ;
     PAINTSTRUCT ps ;
     RECT    rect ;
     int startoffset = 0;
     int heightoftext = 0;
     TEXTMETRIC Metrics;

     char buffer[12];
     switch (message)
     {
          case WM_COMMAND:
            switch( wParam )
            {
            // File handles...
              case  CM_BADHANDLE:
                FilesCG();
                return 0;
              case  CM_RTLMIXH:
                FilesMixCG();  // mixing RTL File Handles
                return 0;
              case  CM_FSTREAMS:
                FStreamsCG();  // mixing RTL File Streams
                return 0;
           // Pointers...
              case  CM_MIXTYPES:
                PointersMixTypes();
                return 0;
              case  CM_RTLMIXP:
                PointersMixCG();  // mixing RTL Pointers
                return 0;
              case  CM_OVERRUN:
                PointersCG();
                return 0;
              case  CM_SOVERRUN:
                StackPointersCG();
                return 0;
              case  CM_BADDELETE:
                PointersBadDelete();
                return 0;
              case  CM_BADLOCAL:
                PointersBadLocal();
                return 0;
            // Memory...
              case  CM_LOCALALLOC:
                LocalAllocCG();
                return 0;
              case  CM_GLOBALALLOC:
                GlobalAllocCG();
                return 0;
              case  CM_WINMODULE:
                WinModuleCG();
                return 0;
            // Exceptions...
              case  CM_GPFAULT1:
                GPExceptCG1();
                return 0;
              case  CM_GPFAULT2:
                GPExceptCG2();
                return 0;
           // Function failures...
              case CM_SETDIBITS:
                MessageBox(NULL,"Windows API failure", "WINAPI.CPP", MB_OK );
                SetDIBits( (HDC)NULL, (HBITMAP)NULL, 0, 0, array, &bmi, 0 );
                return 0;
              case CM_SSCANF:
                MessageBox(NULL,"RTL function failure", "WIN16.CPP", MB_OK );
                sscanf(buffer, "%*d", 1 );
                return 0;
              case  CM_ABOUT:
                MessageBox(hwnd,"               Version 2.0", "CodeGuard Demo Program", MB_OK );
                return 0;
              case  CM_CODEGUARDHELP:
                WinHelp(hwnd, "codegard.hlp",HELP_CONTENTS, 0L );
                return 0;
              default:
                break;
            }

          case WM_PAINT:
            hdc = BeginPaint( hwnd, &ps) ;
            GetTextMetrics( hdc, &Metrics );
            heightoftext = Metrics.tmHeight * 5;   // 5 lines for help message
            GetClientRect(hwnd,&rect);
            startoffset = rect.bottom / 2;         // start in middle
            rect.top = startoffset - heightoftext; // adjust for height of text
            DrawText(hdc,HelpText,strlen(HelpText), &rect, DT_CENTER | DT_WORDBREAK | DT_VCENTER  );
            EndPaint (hwnd, &ps) ;
            return 0 ;

          case WM_DESTROY:
            PostQuitMessage (0) ;
            return 0 ;
          }

     return DefWindowProc (hwnd, message, wParam, lParam) ;
  }

