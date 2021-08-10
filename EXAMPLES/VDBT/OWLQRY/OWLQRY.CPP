// (C) Copyright 1996, Borland International
//
// Owlqry.cpp - VDBT Tquery example
/*******************************************************************************
This example demonstrates how hook up to a database table and then
navigate through it using the VDBT Tquery object.  The user can navigate
through the table using the Main Menu items or via the keyboard. Only one
record will be displayed at a time.


	SETTING UP TO USE AN EVENT HANDLER

	Visual Database Tools uses event sources and event sinks (or
	handlers) to encapsulate everything necessary for repsonding
	to event.  The general 	steps are:
	1.  Identify the source that will be the source of the events
		 you wish to handle, in this particular example, TDataSource.  This is
		 done in the MainCreateMsg function.
	2.  Define the event sink to handle the event.  This is done as part of
		 the EventHandler class.
	3.  Connect the event sink to the event handler.  This is done as part of
		 The EventHandle constructor.
	4.  Connect the event source to the event sink.  This is done in the
		 MainCreateMsg function.


The BIOLIFE table in the diveplan database is used by default.  A different
database and table can be specified on as command line arguments.

The files needed to build this program are:

owlqry.cpp			Source file for application
owlqry.rc			Resource file for application
owlqry.ico			Icon file for application
owlqry16/32.def	def file for 16bit target and 32bit target respectively
makefile				makefile for command-line tools build
owlqry.ide			BCW 5.0 project file to build both 32bit and 16bit
						versions of owlqry.
*******************************************************************************/


#include <vdbt\bdto.h>
#include <windowsx.h>
#include "resource.h"

/******************************************************************************/

#define NOTUSED( x )		((void)(long) (x))

#define DATABASENAME "DivePlan"
#define SQLTEXT "Select * from \"biolife.db\""

#define MAIN_CLASS_NAME	"Main Class"

/******************************************************************************/
// function prototypes

BOOL RegisterMainClass( HINSTANCE hInstance );

HWND CreateMainWindow( HINSTANCE hInstance, LPSTR lpszCmdLine, int cmdShow );

extern "C" LRESULT CALLBACK _export MainWndProc( HWND hwnd, UINT msg,
																WPARAM wParam, LPARAM lParam );
                                                
void MainCreateMsg( HWND hwnd, LPSTR lpszCmdLine );

void MainPaintMsg( HWND hwnd );

void GetAndDrawGraphic( HDC hdc, TGraphicField& graphic, int x, int y, 
																					int w, int h );
                                                               
void GetAndDisplayMemo( HDC hdc, TMemoField& memo,int top, int width,
																						int height);

void DrawPrettyText(HDC hdc, string PrintString, int left, int top, int width,
																						int height);
                                                                  
BOOL MainCommandMsg( HWND hwnd, WPARAM wParam, LPARAM lParam );

void MainKeyDownMsg( HWND hwnd, WPARAM wParam );

void MainDestroyMsg( HWND hwnd );

#define EXTRA sizeof(TQuery*) + sizeof(TDataSource*) + sizeof(EventHandler*)
#define SWL_QUERY 0
#define SWL_DATASOURCE 4
#define SWL_EVENTHANDLER 8

/******************************************************************************/

class EventHandler
{
private:
	HWND hwnd;
public:
	EventHandler( HWND h );
	TDataChangeSink OnDataChangeSink;
protected:
	void OnDataChange( TDataChangeSink& sink, TDataSource& sender, TField* field );
};

EventHandler::EventHandler( HWND h ):
  OnDataChangeSink( TDataChange_MFUNCTOR( *this, &EventHandler::OnDataChange ) )
{
	hwnd = h;
}

void EventHandler::OnDataChange( TDataChangeSink&, TDataSource&, TField* )
{
	if (hwnd)
	{
		RECT rc;
		GetClientRect( hwnd, &rc );
		rc.left = rc.right/2;
		InvalidateRect( hwnd, &rc, TRUE );
	}
}

/******************************************************************************/

int PASCAL WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int cmdShow )
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

/******************************************************************************/

BOOL RegisterMainClass( HINSTANCE hInstance )
{
	WNDCLASS wndClass;

	wndClass.style = CS_HREDRAW | CS_VREDRAW;
	wndClass.lpfnWndProc = MainWndProc;
	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = EXTRA;
	wndClass.hInstance = hInstance;
	wndClass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MAIN));
	wndClass.hCursor = LoadCursor((HINSTANCE) 0, IDC_ARROW);
	wndClass.hbrBackground = (HBRUSH) (COLOR_WINDOW+1);
	wndClass.lpszMenuName = MAKEINTRESOURCE(IDM_MAIN);
	wndClass.lpszClassName = MAIN_CLASS_NAME;

	return RegisterClass(&wndClass);
}

/******************************************************************************/

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

/******************************************************************************/

extern "C" LRESULT CALLBACK _export MainWndProc(HWND hwnd, UINT msg,
																	WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
		case WM_CREATE:
			MainCreateMsg(hwnd, (LPSTR) ((LPCREATESTRUCT) lParam)->lpCreateParams);
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

/******************************************************************************/

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

	char	szTitle[30 + 200 + 1];
	int len = GetWindowText( hwnd, szTitle, sizeof(szTitle) );
	wsprintf( szTitle+len, " - :%s:%s", databaseName, sqlText );
	SetWindowText( hwnd, szTitle );

	// Create the TQuery object.

	TQuery* query = new TQuery;
	if (query)
	{
		// Put the database name and SQLText properties, execute the query.

		try
		{
			query->DatabaseName = string( databaseName );
			query->SQL->Text = string(sqlText);
			query->Open();
		}
		catch (BDTException e)
		{
			e.Show( "processing WM_CREATE" );
			delete query;
			query = NULL;
		}
		SetWindowLong( hwnd, SWL_QUERY, (LONG) query );

		if (query)
		{
			// Create a datasource object and attach to the OnDataChange event.

			EventHandler* handler = new EventHandler( hwnd );
			if (handler)
			{
				TDataSource* datasource = new TDataSource;
				if (datasource)
				{
					datasource->DataSet = query;
					datasource->OnDataChangeSource += handler->OnDataChangeSink;
					SetWindowLong( hwnd, SWL_DATASOURCE, (LONG) datasource );
				}
				SetWindowLong( hwnd, SWL_EVENTHANDLER, (LONG) handler );
			}
		}
	}
}

/******************************************************************************/

void MainPaintMsg(HWND hwnd)
{
	PAINTSTRUCT ps;
	RECT rc;

	BeginPaint( hwnd, &ps );
	GetClientRect( hwnd, &rc );

	TQuery* query = (TQuery*) GetWindowLong( hwnd, SWL_QUERY );
	if (query)
	{
		int count = query->FieldCount;
		if (count)
		{
			int width = rc.right/2;
			int height = rc.bottom/count;

			// Paint the field names on the left side of the window, the
			// field values on the right side of the window.

			int i;
			for (i = 0; i < count; i++)
			{
				string s = query->Fields[i]->FieldName;
            //DrawPrettyText sets up the rectangle to contain the text so that
            //DrawText can be used instead of TextOut.
            DrawPrettyText(ps.hdc, s, 0, i*height, width, height);

				if (query->Fields[i]->DataType == ftGraphic)
				{
					GetAndDrawGraphic( ps.hdc, TGraphicField(query->Fields[i]),
               						 width, i*height, width, height );
				}
				else if (query->Fields[i]->DataType == ftMemo)
				{
					GetAndDisplayMemo( ps.hdc, TMemoField(query->Fields[i]), i*height, width,
               																		height );
				}
				else
				{
					s = query->Fields[i]->Text;
               DrawPrettyText(ps.hdc, s, width, i*height, width, height);
				}
			}
		}
	}

	EndPaint(hwnd, &ps);
}

/******************************************************************************/

void GetAndDrawGraphic( HDC hdc, TGraphicField& graphic, int x, int y, int w,
								int h )
{
	// Use the SaveToBitmap method to get the bitmap and palette handles.

	HBITMAP hbm = 0;
	HPALETTE hpal = 0;
	graphic.SaveToBitmap( hbm, hpal );
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

/******************************************************************************/

void GetAndDisplayMemo( HDC hdc, TMemoField& memo, int top, int width,
								int height)
{
	TMemoryStream stream;
	memo.SaveToStream( stream );
	stream.Position = 0;
	TStrings strings;
	strings.LoadFromStream( stream );
	string s = strings.Text;
   DrawPrettyText(hdc, s, width, top, width, height);
}

/******************************************************************************/

void DrawPrettyText(HDC hdc, string PrintString, int left, int top, int width,
							int height)
{
	RECT rc;
	rc.left = left;
	rc.top = top;
	rc.right = rc.left + width;
	rc.bottom = rc.top + height;
	DrawText(hdc, PrintString.c_str(), PrintString.length(), &rc, DT_TOP | DT_LEFT | DT_WORDBREAK | DT_NOPREFIX );
}

/******************************************************************************/

BOOL MainCommandMsg(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	NOTUSED( lParam );
	// Process navigation commands from the menu.

	TQuery* query = (TQuery*) GetWindowLong( hwnd, SWL_QUERY );
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

/******************************************************************************/

void MainKeyDownMsg(HWND hwnd, WPARAM wParam)
{
	// Process navigation commands from the keyboard.

	TQuery* query = (TQuery*) GetWindowLong( hwnd, SWL_QUERY );
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

/******************************************************************************/

void MainDestroyMsg( HWND hwnd )
{
	// Delete the query and the datasource.

	TQuery* query = (TQuery*) GetWindowLong( hwnd, SWL_QUERY );
	SetWindowLong( hwnd, SWL_QUERY, 0 );
	if (query)
	{
		TDataSource* datasource = (TDataSource*) GetWindowLong( hwnd, SWL_DATASOURCE );
		SetWindowLong( hwnd, SWL_DATASOURCE, 0 );
		if (datasource)
			delete datasource;

		EventHandler* handler=(EventHandler*)GetWindowLong(hwnd, SWL_EVENTHANDLER);
		SetWindowLong( hwnd, SWL_EVENTHANDLER, 0 );
		if (handler)
			delete handler;

		delete query;
	}
}
/******************************************************************************/


