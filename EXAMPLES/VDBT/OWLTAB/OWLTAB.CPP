// (C) Copyright 1996, Borland International
//
// Owltab.cpp - VDBT Ttable example
/*******************************************************************************
This example demonstrates how hook up to a database table and then
navigate through it using the VDBT Ttable object.  The user can navigate
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

owltab.cpp			Source file for application
owltab.rc			Resource file for application
owltab.ico			Icon file for application
owltab16/32.def	def file for 16bit target and 32bit target respectively
makefile				command-line build file
owltab.ide			BCW 5.0 project file for both the 16bit and 32bit target

*******************************************************************************/

#include <vdbt\bdto.h>
#include <windowsx.h>
#include "resource.h"

//******************************************************************************

#define NOTUSED( x )		((void)(long) (x))

#define DATABASENAME "DivePlan"
#define TABLENAME "biolife.db"

#define MAIN_CLASS_NAME	"Main Class"

//******************************************************************************
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
																						int height );
                                                                  
void DrawPrettyText( HDC hdc, string PrintString, int left, int top, int width,
																						int height );
                                                                  
BOOL MainCommandMsg( HWND hwnd, WPARAM wParam, LPARAM lParam );

void MainKeyDownMsg( HWND hwnd, WPARAM wParam );

void MainDestroyMsg( HWND hwnd );


#define EXTRA sizeof(TTable*) + sizeof(TDataSource*) + sizeof(EventHandler*)
#define SWL_TABLE 0
#define SWL_DATASOURCE 4
#define SWL_EVENTHANDLER 8


/*******************************************************************************
EventHandler
	This is the class that will handle the events that are generated
	by the TDataSource object.  OnDataChangeSink is the sink for the
	OnDataChangeEvent and the OnDataChange method will process all
	events passed to OnDataChangeSink by the TDataSource
	OnDataChangeSource object.
*******************************************************************************/

class EventHandler
{
private:
	HWND hwnd;
public:
	EventHandler( HWND h );
	// define the event sink to handle the event.  This is step #2 of
	// setting up to use an event handler for a VDBT event.
	TDataChangeSink OnDataChangeSink;
protected:
	void OnDataChange(TDataChangeSink& sink, TDataSource& sender, TField* field);
};
// the OnDataChangeSink constructor connects OnDataChangeSink with the
// event handler OnDataChange.  This performs stepd #3 for setting up
// to use an event handler for a VDBT event.
EventHandler::EventHandler( HWND h ):
  OnDataChangeSink( TDataChange_MFUNCTOR( *this, &EventHandler::OnDataChange ) )
{
	hwnd = h;
}

/*******************************************************************************
OnDataChange
  When the data changes (the user has navigated to a new record)
  invalidate the right hand side of the window and force a repaint.
  The left hand side of the windows does not need to be repainted
  because it holds data the is static the entire time the app is
  running.
*******************************************************************************/
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
	// allocate extra memor to hold the table, datasource and event handler
	// pointers.
	wndClass.cbWndExtra = EXTRA;
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
	MainCreateMsg.
		This initializes the main window and the database table.  Things
		to note are the create of the TTable object, the try block that
		opens the database table, the create of the datasource object
		and the attachment to the OnDataChange event.
*******************************************************************************/

void MainCreateMsg(HWND hwnd, LPSTR lpszCmdLine)
{
	// Parse the command line for the alias and table names.

	LPSTR databaseName = DATABASENAME;
	LPSTR tableName = TABLENAME;
	if (*lpszCmdLine)
	{
		LPSTR space = strchr( lpszCmdLine, ' ');
		if (space)
		{
			*space = '\0';
			tableName = space+1;
			databaseName = lpszCmdLine;
		}
	}

	// Update the window's title bar with the database and table names.

	char	szTitle[30 + 100 + 1];
	int len = GetWindowText( hwnd, szTitle, sizeof(szTitle) );
	wsprintf( szTitle+len, " - :%s:%s", databaseName, tableName );
	SetWindowText( hwnd, szTitle );

	// Create the TTable object.  This is the step #1 for setting up to use
	// an event handler for a VDBT event.

	TTable* table = new TTable;
	if (table)
	{
		// Put the database and table name properties, open the table.

		try
		{
			table->DatabaseName = string( databaseName );
			table->TableName = string( tableName );
			table->Open();
		}
		catch (BDTException e)
		{
			e.Show( "processing WM_CREATE" );
			delete table;
			table = NULL;
		}
		// put the pointer to the table object to the 0 offset (SWL_TABLE=0) of
      // the extra window memory of hwnd.
		SetWindowLong( hwnd, SWL_TABLE, (LONG) table );

		if (table)
		{
			// Create a datasource object and attach to the OnDataChange event.

			EventHandler* handler = new EventHandler( hwnd );
			if (handler)
			{
				TDataSource* datasource = new TDataSource;
				if (datasource)
				{
					datasource->DataSet = table;
					// The following line connects the event source,
					// datasource->OnDataChangeSource to the event sink,
					// handler->OnDataChangeSink.  The is the fourth and final step
					// for setting up to use an event handler for a VDBT event.

					datasource->OnDataChangeSource += handler->OnDataChangeSink;


					// put the pointer to the datasource object to the 4 offset
					// (SWL_DATASOURCE=4) of the extra window memory of hwnd.
					SetWindowLong( hwnd, SWL_DATASOURCE, (LONG) datasource );
				}
				// put the pointer to the event handler object to the 8 offset
				// (SWL_EVENTHANDLER=8) of the extra window memory of hwnd.
				SetWindowLong( hwnd, SWL_EVENTHANDLER, (LONG) handler );
			}
		}
	}
}


/*******************************************************************************
MainPaintMsg
	This function will repaint the window with the (static) table field
	names on the left side and the (dynamic) field entries on the right.
*******************************************************************************/

void MainPaintMsg(HWND hwnd)
{
	PAINTSTRUCT ps;
	RECT rc;

	BeginPaint( hwnd, &ps );
	GetClientRect( hwnd, &rc );

	// Retrieve the pointer to the table from the extra memory in hwnd
	TTable* table = (TTable*) GetWindowLong( hwnd, SWL_TABLE );

	
	if (table)
	{
		int count = table->FieldCount;
		if (count)
		{
			int width = rc.right/2;
			int height = rc.bottom/count;

			// Paint the field names on the left side of the window, the
			// field values on the right side of the window.

			int i;
			for (i = 0; i < count; i++)
			{
				string s = table->Fields[i]->FieldName;
				DrawPrettyText( ps.hdc, s, 0, i*height, width, height );

				if (table->Fields[i]->DataType == ftGraphic)
				{
					GetAndDrawGraphic( ps.hdc, TGraphicField(table->Fields[i]),
               									width, i*height, width, height );
				}
				else if (table->Fields[i]->DataType ==ftMemo)
            {
					GetAndDisplayMemo( ps.hdc, TMemoField(table->Fields[i]),
               												i*height, width, height );
            }
            else
				{
					s = table->Fields[i]->Text;
					DrawPrettyText( ps.hdc, s, width, i*height, width, height );
				}
			}
		}
	}

	EndPaint(hwnd, &ps);
}

/*******************************************************************************
GetAndDrawGraphic
	This will function will accurately display a graphic field that is
	in the current record.   Note that the SaveToBitmap method will
	save the bitmap from the graphic field to the hbitmap and hpalette
	handles.  
*******************************************************************************/

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

 
/*******************************************************************************
GetAndDisplayMemo
	This function will accurately display a memo field that is
	in the current record.   Note that the DrawPrettyText function will
   perform word-wrap so that as much of the memo as possible will be
   displayed.
*******************************************************************************/
void GetAndDisplayMemo( HDC hdc, TMemoField& memo, int top, int width,
								int height)
{
	TMemoryStream stream;
	memo.SaveToStream( stream );
	stream.Position = 0;
	TStrings strings;
	strings.LoadFromStream( stream );
	string s = strings.Text;
   DrawPrettyText( hdc, s, width, top, width, height );
}



/*******************************************************************************
DrawPrettyText
function will use DrawText to perform word-wrap so that as much of 
text to be displayed as possible is actually displayed in the available
rectangle.
*******************************************************************************/
void DrawPrettyText( HDC hdc, string PrintString, int left, int top, int width,
							int height )
{
	RECT rc;
	rc.left = left;
	rc.top = top;
	rc.right = rc.left + width;
	rc.bottom = rc.top + height;
	DrawText(hdc, PrintString.c_str(), PrintString.length(), &rc,
   			DT_TOP | DT_LEFT | DT_WORDBREAK | DT_NOPREFIX );
}

/*******************************************************************************
MainCommandMsg
	This handles all of the commands that come for the Main Menu
	to navigate through the table. All other WM_COMMAND messages are
	passed onto Windows.
*******************************************************************************/

BOOL MainCommandMsg(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	NOTUSED( lParam );
	// Process navigation commands from the menu.

	TTable* table = (TTable*) GetWindowLong( hwnd, SWL_TABLE );
	if (table)
	{
		switch (GET_WM_COMMAND_ID(wParam, lParam))
		{
			case IDM_NAV_FIRST:
				table->First();
				break;
			case IDM_NAV_PRIORSET:
				table->MoveBy(-5);
				break;
			case IDM_NAV_PRIOR:
				table->Prior();
				break;
			case IDM_NAV_NEXT:
				table->Next();
				break;
			case IDM_NAV_NEXTSET:
				table->MoveBy(5);
				break;
			case IDM_NAV_LAST:
				table->Last();
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
	This handle all of the keyboard messages that will be used to navigate
	the table.  All other WM_KEYDOWN messages are passed onto Windows.
*******************************************************************************/

void MainKeyDownMsg(HWND hwnd, WPARAM wParam)
{
	// Process navigation commands from the keyboard.

	TTable* table = (TTable*) GetWindowLong( hwnd, SWL_TABLE );
	if (table)
	{
		switch (wParam)
		{
			case VK_HOME:
				table->First();
				break;
			case VK_PRIOR:
				table->MoveBy(-5);
				break;
			case VK_UP:
				table->Prior();
				break;
			case VK_DOWN:
				table->Next();
				break;
			case VK_NEXT:
				table->MoveBy(5);
				break;
			case VK_END:
				table->Last();
				break;
		}
	}
}


/*******************************************************************************
MainDestroyMsg
	This destroys the datasource object, the handler object and then the
	table object.
*******************************************************************************/

void MainDestroyMsg( HWND hwnd )
{
	// Delete the table and the datasource.

	// Retrieve the pointer to the table from the extra memory in hwnd
	// and then clear the entry.
	TTable* table = (TTable*) GetWindowLong( hwnd, SWL_TABLE );
	SetWindowLong( hwnd, SWL_TABLE, 0 );
	if (table)
	{
		// Retrieve the pointer to the datasource from the extra memory in hwnd
		// and then clear the entry.
		TDataSource* datasource=(TDataSource*)GetWindowLong(hwnd, SWL_DATASOURCE);
		SetWindowLong( hwnd, SWL_DATASOURCE, 0 );
		if (datasource)
			delete datasource;

		// Retrieve the pointer to the event handler from the extra memory
		// in hwnd and then clear the entry.
		EventHandler* handler=(EventHandler*)GetWindowLong(hwnd, SWL_EVENTHANDLER);
		SetWindowLong( hwnd, SWL_EVENTHANDLER, 0 );
		if (handler)
			delete handler;

		delete table;
   }
}