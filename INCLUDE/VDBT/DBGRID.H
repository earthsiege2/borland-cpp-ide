//--------------------------------------------------------
// DBGRID.H generated from VTSSONLY.VBX
// Copyrights (C) 1996 Borland International
//--------------------------------------------------------

#if !defined(DBGRID_H_)
#define  DBGRID_H_

#include <vdbt/dbcontrl.h>

//--------------------------------------------------------
// DBGrid (VB3)
//--------------------------------------------------------

// properties
#define Prop_TDBGrid_Name 0
#define Prop_TDBGrid_Enabled 1
#define Prop_TDBGrid_Height 2
#define Prop_TDBGrid_HelpContextID 3
#define Prop_TDBGrid_hWnd 4
#define Prop_TDBGrid_Index 5
#define Prop_TDBGrid_Left 6
#define Prop_TDBGrid_Parent 7
#define Prop_TDBGrid_TabOrder 8
#define Prop_TDBGrid_TabStop 9
#define Prop_TDBGrid_Tag 10
#define Prop_TDBGrid_Top 11
#define Prop_TDBGrid_Visible 12
#define Prop_TDBGrid_Width 13
#define Prop_TDBGrid_ReadFile 14
#define Prop_TDBGrid_SS 15
#define Prop_TDBGrid_WriteFile 17
#define Prop_TDBGrid_BackColor 18
#define Prop_TDBGrid_BorderStyle 19
#define Prop_TDBGrid_Col 20
#define Prop_TDBGrid_Row 21
#define Prop_TDBGrid_ShowHScrollBar 22
#define Prop_TDBGrid_Text 23
#define Prop_TDBGrid_Number 24
#define Prop_TDBGrid_Formula 25
#define Prop_TDBGrid_FixedCol 26
#define Prop_TDBGrid_FixedCols 27
#define Prop_TDBGrid_FixedRow 28
#define Prop_TDBGrid_FixedRows 29
#define Prop_TDBGrid_ShowGridLines 30
#define Prop_TDBGrid_ShowRowHeading 31
#define Prop_TDBGrid_ShowSelections 32
#define Prop_TDBGrid_LeftCol 33
#define Prop_TDBGrid_MaxCol 34
#define Prop_TDBGrid_MaxRow 35
#define Prop_TDBGrid_TopRow 36
#define Prop_TDBGrid_AllowResize 37
#define Prop_TDBGrid_AllowSelections 38
#define Prop_TDBGrid_AllowFormulas 39
#define Prop_TDBGrid_AllowInCellEditing 40
#define Prop_TDBGrid_ShowVScrollBar 41
#define Prop_TDBGrid_AllowFillRange 42
#define Prop_TDBGrid_AllowMoveRange 43
#define Prop_TDBGrid_SelStartCol 44
#define Prop_TDBGrid_SelStartRow 45
#define Prop_TDBGrid_SelEndCol 46
#define Prop_TDBGrid_SelEndRow 47
#define Prop_TDBGrid_ExtraColor 48
#define Prop_TDBGrid_EditName 49
#define Prop_TDBGrid_FileName 50
#define Prop_TDBGrid_AutoRecalc 51
#define Prop_TDBGrid_AllowAppLaunch 53
#define Prop_TDBGrid_PrintGridLines 54
#define Prop_TDBGrid_PrintRowHeading 55
#define Prop_TDBGrid_PrintHCenter 56
#define Prop_TDBGrid_PrintVCenter 57
#define Prop_TDBGrid_PrintLeftToRight 58
#define Prop_TDBGrid_PrintHeader 59
#define Prop_TDBGrid_PrintFooter 60
#define Prop_TDBGrid_PrintLeftMargin 61
#define Prop_TDBGrid_PrintTopMargin 62
#define Prop_TDBGrid_PrintRightMargin 63
#define Prop_TDBGrid_PrintBottomMargin 64
#define Prop_TDBGrid_PrintArea 65
#define Prop_TDBGrid_PrintTitles 66
#define Prop_TDBGrid_PrintNoColor 67
#define Prop_TDBGrid_Selection 68
#define Prop_TDBGrid_DataSource 69
#define Prop_TDBGrid_DataChanged 70
#define Prop_TDBGrid_TableName 71
#define Prop_TDBGrid_DataField 72
#define Prop_TDBGrid_DataFields 73
#define Prop_TDBGrid_DoCancelEdit 74
#define Prop_TDBGrid_DoSelChange 75
#define Prop_TDBGrid_DoStartEdit 76
#define Prop_TDBGrid_DoEndEdit 77
#define Prop_TDBGrid_DoStartRecalc 78
#define Prop_TDBGrid_DoEndRecalc 79
#define Prop_TDBGrid_DoClick 80
#define Prop_TDBGrid_DoDblClick 81
#define Prop_TDBGrid_DataSetMaxRow 82
#define Prop_TDBGrid_DataFieldChanged 83
#define Prop_TDBGrid_DataFieldNumber 84
#define Prop_TDBGrid_DataFieldCount 85
#define Prop_TDBGrid_DataRowCount 86
#define Prop_TDBGrid_DataSetColumnNames 87
#define Prop_TDBGrid_DataSetMaxCol 88
#define Prop_TDBGrid_ShowColHeading 89
#define Prop_TDBGrid_PrintColHeading 90
#define Prop_TDBGrid_DataSetColumnWidths 91
#define Prop_TDBGrid_About_Formula_One 92
#define Prop_TDBGrid_Entry 93
#define Prop_TDBGrid_DataRowsBuffered 94
#define Prop_TDBGrid_DataRowBase 95
#define Prop_TDBGrid_DoDataRowLoad 96
#define Prop_TDBGrid_DoDataNewRow 97
#define Prop_TDBGrid_Repaint 98
#define Prop_TDBGrid_AllowArrows 99
#define Prop_TDBGrid_AllowTabs 100
#define Prop_TDBGrid_FormattedText 101
#define Prop_TDBGrid_MousePointer 102
#define Prop_TDBGrid_RowMode 103
#define Prop_TDBGrid_DataConnected 104
#define Prop_TDBGrid_DataAutoAddNew 105
#define Prop_TDBGrid_AllowDelete 106
#define Prop_TDBGrid_DataHdrField 107
#define Prop_TDBGrid_EnableProtection 108
#define Prop_TDBGrid_WriteExcel4 109
#define Prop_TDBGrid_DataSetColumnFormats 110
#define Prop_TDBGrid_DragIcon 111
#define Prop_TDBGrid_DragMode 112
#define Prop_TDBGrid_MinCol 113
#define Prop_TDBGrid_MinRow 114
#define Prop_TDBGrid_DoTopLeftChanged 115
#define Prop_TDBGrid_AllowEditHeaders 116
#define Prop_TDBGrid_Application_Designer 117

// events
#define Event_TDBGrid_Click 0
#define Event_TDBGrid_DblClick 1
#define Event_TDBGrid_DragDrop 2
#define Event_TDBGrid_DragOver 3
#define Event_TDBGrid_GotFocus 4
#define Event_TDBGrid_KeyDown 5
#define Event_TDBGrid_KeyPress 6
#define Event_TDBGrid_KeyUp 7
#define Event_TDBGrid_LostFocus 8
#define Event_TDBGrid_CancelEdit 9
#define Event_TDBGrid_SelChange 10
#define Event_TDBGrid_StartEdit 11
#define Event_TDBGrid_EndEdit 12
#define Event_TDBGrid_StartRecalc 13
#define Event_TDBGrid_EndRecalc 14
#define Event_TDBGrid_DataRowLoad 15
#define Event_TDBGrid_DataNewRow 16
#define Event_TDBGrid_TopLeftChanged 17


//----------------------------------------------------------------------
// Event Response Table Macros
//----------------------------------------------------------------------
#define EV_VBXEVENT_GRID_DRAGDROP \
  {WM_VBXBASE+Event_TDBGrid_DragDrop,0,(TAnyDispatcher)::DragEvent_Dispatch}

#define EV_VBXEVENT_GRID_DRAGOVER \
  {WM_VBXBASE+Event_TDBGrid_DragOver,0,(TAnyDispatcher)::DragOver_Dispatch}


class _DBAWARECLASS TDBGrid : public TVbxControl {
  DBPMECLASS( TDBGrid );

  public:

    // constructors
    TDBGrid(TWindow*, int, LPCSTR, int, int, int, int, TModule* =0);
    TDBGrid(TWindow* parent, int resourceId, TModule* =0);

  public:
    // Properties
    DECLARE_DB_PROP_RW2( string,   Name );
    DECLARE_DB_PROP_RW0( Bool,     Enabled,        Prop_TDBGrid_Enabled );
    DECLARE_DB_PROP_RW0( long,     Height,         Prop_TDBGrid_Height );
    DECLARE_DB_PROP_RW0( long,     HelpContext,    Prop_TDBGrid_HelpContextID );
    DECLARE_DB_PROP_RW0( int,      ComponentIndex, Prop_TDBGrid_Index );
    DECLARE_DB_PROP_RW0( long,     Left,           Prop_TDBGrid_Left );
    DECLARE_DB_PROP_RW0( int,      TabOrder,       Prop_TDBGrid_TabOrder );
    DECLARE_DB_PROP_RW0( Bool,     TabStop,        Prop_TDBGrid_TabStop );
    DECLARE_DB_PROP_RW2( string,   Tag );
    DECLARE_DB_PROP_RW0( long,     Top,            Prop_TDBGrid_Top );
    DECLARE_DB_PROP_RW0( Bool,     Visible,        Prop_TDBGrid_Visible );
    DECLARE_DB_PROP_RW0( long,     Width,          Prop_TDBGrid_Width );
    DECLARE_DB_PROP_RW0( COLORREF, BackColor,      Prop_TDBGrid_BackColor );
    DECLARE_DB_PROP_RW0( ENUM,     BorderStyle,    Prop_TDBGrid_BorderStyle );
    DECLARE_DB_PROP_RW2( TDataSource, DataSource );
    DECLARE_DB_PROP_RW2( TField,      DataField );
    DECLARE_DB_PROP_RW0( ENUM,     Cursor,         Prop_TDBGrid_MousePointer );
    DECLARE_DB_PROP_RW0( HPIC,     DragIcon,       Prop_TDBGrid_DragIcon );
    DECLARE_DB_PROP_RW0( ENUM,     DragMode,       Prop_TDBGrid_DragMode );
// Options Flags
    DECLARE_DB_PROP_RW0( Bool,     ColumnResize,   Prop_TDBGrid_AllowResize  );
    DECLARE_DB_PROP_RW0( Bool,     Titles,         Prop_TDBGrid_ShowRowHeading );
    DECLARE_DB_PROP_RW0( Bool,     Indicators,     Prop_TDBGrid_ShowColHeading );
    DECLARE_DB_PROP_RW0( Bool,     Lines,          Prop_TDBGrid_ShowGridLines );
    DECLARE_DB_PROP_RW0( Bool,     Tabs,           Prop_TDBGrid_AllowTabs );
    DECLARE_DB_PROP_RW0( Bool,     Editing,        Prop_TDBGrid_AllowInCellEditing );

  private:
    void FireOnClick()
    {
      OnClickSource( *this );
    }
    void FireOnDragDrop( TVbxControl& Source, SHORT x, SHORT y )
    {
      OnDragDropSource( *this, Source, x, y );
    }
    void FireOnDragOver( TVbxControl& Source, SHORT x, SHORT y, TDragState State )
    {
      OnDragOverSource( *this, Source, x, y, State );
    }
    void FireOnDblClick()
    {
      OnDblClickSource( *this );
    }
    void FireOnEnter()
    {
      OnEnterSource( *this );
    }
    void FireOnExit()
    {
      OnExitSource( *this );
    }
    void FireOnKeyDown( SHORT *Key, TShiftState State )
    {
      OnKeyDownSource( *this, Key, State );
    }
    void FireOnKeyPress( SHORT Key )
    {
      OnKeyPressSource( *this, Key );
    }
    void FireOnKeyUp( SHORT *Key, TShiftState State )
    {
      OnKeyUpSource( *this, Key, State );
    }

  public:
    // Event Source
    DECLARE_SOURCE( OnClick,    TDBGridNotify );
    DECLARE_SOURCE( OnDragDrop, TDBGridDrag );
    DECLARE_SOURCE( OnDragOver, TDBGridDragOver );
    DECLARE_SOURCE( OnDblClick, TDBGridNotify );
    DECLARE_SOURCE( OnEnter,    TDBGridNotify );
    DECLARE_SOURCE( OnExit,     TDBGridNotify );
    DECLARE_SOURCE( OnKeyDown,  TDBGridKey );
    DECLARE_SOURCE( OnKeyPress, TDBGridKeyPress );
    DECLARE_SOURCE( OnKeyUp,    TDBGridKey );

    // Event Handlers
    DECLARE_DB_EVENT( OnClick,    TNotifyEvent );
    DECLARE_DB_EVENT( OnDblClick, TNotifyEvent );
    DECLARE_DB_EVENT( OnDragOver, TDragOverEvent );
    DECLARE_DB_EVENT( OnDragDrop, TDragEvent );
    DECLARE_DB_EVENT( OnEnter,    TNotifyEvent );
    DECLARE_DB_EVENT( OnExit,     TNotifyEvent );
    DECLARE_DB_EVENT( OnKeyDown,  TKeyEvent );
    DECLARE_DB_EVENT( OnKeyPress, TKeyPressEvent );
    DECLARE_DB_EVENT( OnKeyUp,    TKeyEvent );

  protected:
    char far* GetClassName();

#ifdef __OWL_VBXCTL_H
  DECLARE_RESPONSE_TABLE( TDBGrid );
#endif __OWL_VBXCTL_H
};

// Inlines
// Properties
DEFINE_DB_PROP_DATASOURCE( TDBGrid )
DEFINE_DB_PROP_DATAFIELD( TDBGrid, _TDBGrid )
DEFINE_DB_PROP_STRING( TDBGrid, _TDBGrid, Name );
DEFINE_DB_PROP_STRING( TDBGrid, _TDBGrid, Tag );

// Methods
inline char far* TDBGrid::GetClassName()
{
  return "DBGRID";
}

#endif DBGRID_H_
