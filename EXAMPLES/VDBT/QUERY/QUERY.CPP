// (C) Copyright 1996, Borland International
//
// query.cpp - VDBT PITTquery example
/*******************************************************************************
This example demonstrates how hook up to a database table and then navigate
through it using the VDBT PITquery object and the COM classes.  The user can
navigate through the table using the Main Menu items or via the keyboard.  Only
one record will be displayed at a time.


	SETTING UP TO USE AN EVENT HANDLER

	Visual Database Tools uses event sources and event sinks (or 	handlers) to
   encapsulate everything necessary for repsonding	to event.  The general 	steps
   are:
	1.  Identify the source that will be the source of the events you wish to 
   	 handle, in this particular example, TDataSource.  This is done in the
       MainCreateMsg function.
	2.  Define the event sink to handle the event.  This is done as part of the
   	 EventHandler class.
	3.  Connect the event sink to the event handler.  This is done as part of
		 The EventHandle constructor.
	4.  Connect the event source to the event sink.  This is done in the
		 MainCreateMsg function.


The BIOLIFE table in the diveplan database is used by default.  A different
database and table can be specified on as command line arguments.

The files needed to build this program are:

query.cpp			Source file for application
query.rc				Resource file for application
query.ico			Icon file for application
query16/32.def		module definition file for 16bit and 32bit target respectively
makefile				makefile for command-line tools build
query.ide			BCW 5.0 project file to build both 32bit and 16bit	targets.
*******************************************************************************/

#define INITGUID
#include <windowsx.h>
#include "resource.h"
//pragma hdrstop used here because bdtc.h unavoidably initializes data that will
//prevent pre-compiled headers from being used. 
#pragma hdrstop
#include <vdbt\bdtc.h>

//******************************************************************************

#define NOTUSED( x )		((void)(long) (x))

#define DATABASENAME "DivePlan"
#define SQLTEXT "Select * from \"biolife.db\""

#define MAIN_CLASS_NAME	"Main Class"

//******************************************************************************
// function prototypes

BOOL RegisterMainClass( HINSTANCE hInstance );

HWND CreateMainWindow( HINSTANCE hInstance, LPSTR lpszCmdLine, int cmdShow );

extern "C" LRESULT CALLBACK _export MainWndProc( HWND hwnd, UINT msg,
																WPARAM wParam, LPARAM lParam );
void MainCreateMsg( HWND hwnd, LPSTR lpszCmdLine );

void MainPaintMsg( HWND hwnd );

void GetAndDrawGraphic( HDC hdc, PITField field, int top, int left, int width,
																						 int height );

void GetAndDisplayMemo( HDC hdc, PITField field, int top, int left, int width,
																						 int height );

void DrawPrettyText(HDC hdc, PITAnyString PrintString, int top, int left,
																		int width,	int height);
 

BOOL MainCommandMsg( HWND hwnd, WPARAM wParam, LPARAM lParam );

void MainKeyDownMsg( HWND hwnd, WPARAM wParam );

void MainDestroyMsg( HWND hwnd );

//******************************************************************************

int PASCAL WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,
																LPSTR lpszCmdLine, int cmdShow )
{
	if (! hPrevInstance)
		if (! RegisterMainClass(hInstance))
			return 0;

	CreateMainWindow(hInstance, lpszCmdLine, cmdShow);

	MSG msg;
	while (GetMessage(&msg, (HWND) 0, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}

//******************************************************************************

BOOL RegisterMainClass( HINSTANCE hInstance )
{
	WNDCLASS wndClass;

	wndClass.style = CS_HREDRAW | CS_VREDRAW;
	wndClass.lpfnWndProc = MainWndProc;
	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = sizeof(PITQuery) + sizeof(PPITField) 
   								+ sizeof(PITDataSource);
	wndClass.hInstance = hInstance;
	wndClass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MAIN));
	wndClass.hCursor = LoadCursor((HINSTANCE) 0, IDC_ARROW);
	wndClass.hbrBackground = (HBRUSH) (COLOR_WINDOW+1);
	wndClass.lpszMenuName = MAKEINTRESOURCE(IDM_MAIN);
	wndClass.lpszClassName = MAIN_CLASS_NAME;

	return RegisterClass(&wndClass);
}

//******************************************************************************

HWND CreateMainWindow( HINSTANCE hInstance, LPSTR lpszCmdLine, int cmdShow )
{
	char	szTitle[30 + 1];
	HWND	hwnd;

	LoadString(hInstance, IDS_MAINTITLE, szTitle, 30);
	hwnd = CreateWindow(MAIN_CLASS_NAME, szTitle, WS_TILEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		(HWND) 0, (HMENU) 0, hInstance, lpszCmdLine);

	if (hwnd)
	{
		ShowWindow(hwnd, cmdShow);
		UpdateWindow(hwnd);
	}

	return hwnd;
}

//******************************************************************************

extern "C" LRESULT CALLBACK _export MainWndProc(HWND hwnd, UINT msg,
																	WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
		case WM_CREATE:
			MainCreateMsg( hwnd, (LPSTR)((LPCREATESTRUCT) lParam)->lpCreateParams);
			break;

		case WM_PAINT:
			MainPaintMsg(hwnd);
			break;

		case WM_COMMAND:
			if (! MainCommandMsg(hwnd, wParam, lParam))
				return DefWindowProc(hwnd, msg, wParam, lParam);
			break;

		case WM_KEYDOWN:
			MainKeyDownMsg(hwnd, wParam);
			break;

		case WM_DESTROY:
			MainDestroyMsg(hwnd);
			PostQuitMessage(0);
			break;

		default:
			return DefWindowProc(hwnd, msg, wParam, lParam);
	}

	return 0L;
}

/*******************************************************************************
OnDataChange
  When the data changes (the user has navigated to a new record) it invalidates
  the right hand side of the window and force a repaint.  The left hand side of
  the windows does not need to be repainted because it holds data the is static
  the entire time the app is running.
*******************************************************************************/
void STDAPICALLTYPE _export OnDataChange( long data, PITDataSource, PITField )
{
	HWND hwnd = (HWND) data;
	if (hwnd)
	{
		RECT rc;
		GetClientRect( hwnd, &rc );
		rc.left = rc.right/2;
		InvalidateRect( hwnd, &rc, TRUE );
	}
}


/*******************************************************************************
MainCreateMsg.
	This initializes the main window and the database table.  Things to note are
   the create of the TTable object, the try block that opens the database table,
   the create of the datasource object and the attachment to the OnDataChange
   event.
*******************************************************************************/
void MainCreateMsg(HWND hwnd, LPSTR lpszCmdLine)
{
	// Parse the command line for the alias and sql query.

	LPSTR databaseName = DATABASENAME;
	LPSTR sqlText = SQLTEXT;
	if (*lpszCmdLine)
	{
		LPSTR space = strchr( lpszCmdLine, ' ');
		if (space)
		{
			*space = '\0';
			sqlText = space+1;
			databaseName = lpszCmdLine;
		}
	}

	// Update the window's title bar with the database name and sql query.

	char	szTitle[30 + 100 + 1];
	int len = GetWindowText( hwnd, szTitle, sizeof(szTitle) );
	wsprintf( szTitle+len, " - :%s:%s", databaseName, sqlText );
	SetWindowText( hwnd, szTitle );

	// Create the PITQuery object.

	PITQuery query = CreateITQuery();
	if (query)
	{
		// Put the database name and SQLText properties, execute the query.

		try
		{
			PITAnyString d = CreateITAnyString();
			d->put_AsStringBuf( databaseName );
			query->put_DatabaseName( d );
			d->Release();

			PITAnyString s = CreateITAnyString();
			s->put_AsStringBuf( sqlText );
			PITStrings sql = query->get_SQL();
			sql->put_Text( s );
			sql->Release();
			s->Release();

			query->Open();
		}
		catch (BDTException e)
		{
			e.Show( "processing WM_CREATE" );
			query->Release();
			query = NULL;
		}
		SetWindowLong( hwnd, 0, (LONG) query );

		if (query)
		{
			// Allocate space to hold the field object pointers.

			int count = query->get_FieldCount();
			PPITField fields = new PITField [ count ];
			int i;
			for (i = 0; i < count; i++)
				fields[i] = query->get_Fields( i );
			SetWindowLong( hwnd, 4, (LONG) fields );

			// Create a datasource object and attach to the OnDataChange event.

			PITDataSource datasource = CreateITDataSource();
			if (datasource)
			{
				datasource->put_DataSet( query );
				datasource->AttachOnDataChange( OnDataChange, (long) hwnd );
				SetWindowLong( hwnd, 8, (LONG) datasource );
			}
		}
	}
}

/*******************************************************************************
MainPaintMsg
	This function will repaint the window with the (static) table field
	names on the left side and the (dynamic) field entries on the right.
	The table name.
*******************************************************************************/
void MainPaintMsg(HWND hwnd)
{
	PAINTSTRUCT ps;
	RECT rc;

	BeginPaint( hwnd, &ps );
	GetClientRect( hwnd, &rc );

	PITQuery query = (PITQuery) GetWindowLong( hwnd, 0 );
	if (query)
	{
		int count = query->get_FieldCount();
		if (count)
		{
			int width = rc.right/2;
			int height = rc.bottom/count;

			PPITField fields = (PPITField) GetWindowLong( hwnd, 4 );
			if (fields)
			{
				// Paint the field names on the left side of the window, the
				// field values on the right side of the window.

				int i;
				for (i = 0; i < count; i++)
				{
					if (fields[i])
					{
						PITAnyString n = fields[i]->get_FieldName();
						DrawPrettyText( ps.hdc, n, i*height, 0, width, height );                  
						n->Release();

						if (fields[i]->get_DataType() == ftGraphic)
						{
							GetAndDrawGraphic( ps.hdc, fields[i], width, i*height,
                     														width, height );
						}
                  else if (fields[i]->get_DataType() == ftMemo)
                  {
							GetAndDisplayMemo( ps.hdc, fields[i], i*height, width,
                     														width, height );
                  }
						else
						{
							PITAnyString t = fields[i]->get_Text();
							DrawPrettyText(ps.hdc, t, i*height, width, width, height);
							t->Release();
						}
					}
				}
			}
		}
	}

	EndPaint(hwnd, &ps);
}

/*******************************************************************************
GetAndDrawGraphic
	This will function will accurately display a graphic field that is in the
   current record.   Note that the SaveToBitmap method will save the bitmap from
   the graphic field to the hbitmap and hpalette handles.
*******************************************************************************/
void GetAndDrawGraphic( HDC hdc, PITField field, int x, int y, int w, int h )
{
	// Use the SaveToBitmap method to get the bitmap and palette handles.

	HBITMAP hbm = 0;
	HPALETTE hpal = 0;
	field->SaveToBitmap( &hbm, &hpal );
	if (hbm)
	{
		HDC hdcTemp = CreateCompatibleDC( hdc );
		if (hdcTemp)
		{
			BITMAP bm;
			GetObject( hbm, sizeof(BITMAP), &bm );
			HBITMAP hbmPrev = SelectBitmap( hdcTemp, hbm );
			StretchBlt( hdc, x, y, w, h,
							hdcTemp, 0, 0, bm.bmWidth, bm.bmHeight, SRCCOPY );
			SelectBitmap( hdcTemp, hbmPrev );
			DeleteDC( hdcTemp );
		}
		DeleteBitmap( hbm );
	}
	if (hpal)
		DeletePalette( hpal );
}

/*******************************************************************************
GetAndDisplayMemo
	This function will accurately display a memo field that is in the current
   record.   Note that the DrawPrettyText function will perform word-wrap so
   that as much of the memo as possible will be displayed.
*******************************************************************************/
void GetAndDisplayMemo( HDC hdc, PITField field, int top, int left, int width,
																						int height )
{
	// create a stream for the memo
	PITMemoryStream stream = CreateITMemoryStream();
	if (stream)
	{
		// save the memo to the stream
		field->SaveToStream( stream );
		stream->put_Position( 0 );
		PITStrings strings = CreateITStrings();
		if (strings)
		{
			strings->LoadFromStream( stream );
			PITAnyString t = strings->get_Text();
			if (t)
			{
			   DrawPrettyText(hdc, t, top, left, width, height);
				t->Release();
			}
			strings->Release();
		}

		stream->Release();
	}
}

void DrawPrettyText(HDC hdc, PITAnyString PrintString, int top, int left,
																			int width, int height)
{
				RECT rc;
				rc.left = left;
				rc.top = top;
				rc.right = rc.left + width;
				rc.bottom = rc.top + height;
				DrawText( hdc, PrintString->get_Buffer(), PrintString->get_Length(),
            			 &rc, DT_TOP | DT_LEFT | DT_WORDBREAK | DT_NOPREFIX );
}

/*******************************************************************************
MainCommandMsg
	This handles all of the commands that come for the Main Menu to navigate
   through the table. All other WM_COMMAND messages are passed onto Windows.
*******************************************************************************/
BOOL MainCommandMsg(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	NOTUSED( lParam );
	// Process navigation commands from the menu.

	PITQuery query = (PITQuery) GetWindowLong( hwnd, 0 );
	if (query)
	{
		switch (GET_WM_COMMAND_ID(wParam, lParam))
		{
			case IDM_NAV_FIRST:
				query->First();
				break;
			case IDM_NAV_PRIORSET:
				query->MoveBy(-5);
				break;
			case IDM_NAV_PRIOR:
				query->Prior();
				break;
			case IDM_NAV_NEXT:
				query->Next();
				break;
			case IDM_NAV_NEXTSET:
				query->MoveBy(5);
				break;
			case IDM_NAV_LAST:
				query->Last();
				break;
			default:
				return FALSE;
		}

		return TRUE;
	}

	return FALSE;
}

/*******************************************************************************
MainKeyDownMsg
	This handle all of the keyboard messages that will be used to navigate 	the
   table.  All other WM_KEYDOWN messages are passed onto Windows.
*******************************************************************************/
void MainKeyDownMsg(HWND hwnd, WPARAM wParam)
{
	// Process navigation commands from the keyboard.

	PITQuery query = (PITQuery) GetWindowLong( hwnd, 0 );
	if (query)
	{
		switch (wParam)
		{
			case VK_HOME:
				query->First();
				break;
			case VK_PRIOR:
				query->MoveBy(-5);
				break;
			case VK_UP:
				query->Prior();
				break;
			case VK_DOWN:
				query->Next();
				break;
			case VK_NEXT:
				query->MoveBy(5);
				break;
			case VK_END:
				query->Last();
				break;
		}
	}
}

/*******************************************************************************
MainDestroyMsg
	This destroys the datasource object, the handler object and then the table
   object.
*******************************************************************************/
void MainDestroyMsg( HWND hwnd )
{
	// Release the query, the fields, and the datasource.

	PITQuery query = (PITQuery) GetWindowLong( hwnd, 0 );
	SetWindowLong( hwnd, 0, 0 );
	if (query)
	{
		PPITField fields = (PPITField) GetWindowLong( hwnd, 4 );
		SetWindowLong( hwnd, 4, 0 );
		if (fields)
		{
			int count = query->get_FieldCount();
			int i;
			for (i = 0; i < count; i++)
				fields[i]->Release();

			delete [] fields;
		}

		PITDataSource datasource = (PITDataSource) GetWindowLong( hwnd, 8 );
		SetWindowLong( hwnd, 8, 0 );
		if (datasource)
			datasource->Release();

		query->Release();
	}
}

//******************************************************************************
