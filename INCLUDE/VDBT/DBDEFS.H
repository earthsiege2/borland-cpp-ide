//--------------------------------------------------------
// DBDEFS.H generated from BDT50CTL.VBX
// Copywright (c) 1996, Borland International
//--------------------------------------------------------


//
// Mangle the class and function names so we can have mulitpale versions of the
// same classes and functions in one .LIB file.
//
#if defined( __DLL__ ) && ! defined( __FLAT__ )
#  if defined( _RTLDLL )
#    define TDBControl     dTDBControl
#    define TDBCheckBox    dTDBCheckBox
#    define TDBComboBox    dTDBComboBox
#    define TDBEdit        dTDBEdit
#    define TDBGrid        dTDBGrid
#    define TDBImage       dTDBImage
#    define TDBListBox     dTDBListBox
#    define TDBLookupCombo dTDBLookupCombo
#    define TDBLookupList  dTDBLookupList
#    define TDBMemo        dTDBMemo
#    define TDBNavigator   dTDBNavigator
#    define TDBRadioGroup  dTDBRadioGroup
#    define TDBText        dTDBText
#  else _RTLDLL
#    define TDBControl     uTDBControl
#    define TDBCheckBox    uTDBCheckBox
#    define TDBComboBox    uTDBComboBox
#    define TDBEdit        uTDBEdit
#    define TDBGrid        uTDBGrid
#    define TDBImage       uTDBImage
#    define TDBListBox     uTDBListBox
#    define TDBLookupCombo uTDBLookupCombo
#    define TDBLookupList  uTDBLookupList
#    define TDBMemo        uTDBMemo
#    define TDBNavigator   uTDBNavigator
#    define TDBRadioGroup  uTDBRadioGroup
#    define TDBText        uTDBText
#  endif _RTLDLL
#elif defined( _RTLDLL )
#  define TDBControl     iTDBControl
#  define TDBCheckBox    iTDBCheckBox
#  define TDBComboBox    iTDBComboBox
#  define TDBEdit        iTDBEdit
#  define TDBGrid        iTDBGrid
#  define TDBImage       iTDBImage
#  define TDBListBox     iTDBListBox
#  define TDBLookupCombo iTDBLookupCombo
#  define TDBLookupList  iTDBLookupList
#  define TDBMemo        iTDBMemo
#  define TDBNavigator   iTDBNavigator
#  define TDBRadioGroup  iTDBRadioGroup
#  define TDBText        iTDBText
#endif

//--------------------------------------------------------
// TDBControl (VB3, Base class)
//--------------------------------------------------------

#define Prop_TDBControl_Name 0
#define Prop_TDBControl_Index 1
#define Prop_TDBControl_Left 2
#define Prop_TDBControl_Top 3
#define Prop_TDBControl_Width 4
#define Prop_TDBControl_Height 5
#define Prop_TDBControl_Visible 6
#define Prop_TDBControl_Tag 7
#define Prop_TDBControl_DragMode 8
#define Prop_TDBControl_DragIcon 9
#define Prop_TDBControl_MousePointer 10
#define Prop_TDBControl_Enabled 11
#define Prop_TDBControl_HelpContextID 12
#define Prop_TDBControl_TabIndex 13
#define Prop_TDBControl_TabStop 14
#define Prop_TDBControl_About 15
#define Prop_TDBControl_Align 16
#define Prop_TDBControl_DataSource 17

//--------------------------------------------------------
// TDBText (VB3, subclassed from STATIC)
//--------------------------------------------------------

// properties
#define Prop_TDBText_DataField 18
#define Prop_TDBText_DataChanged 19
#define Prop_TDBText_ForeColor 20
#define Prop_TDBText_BackColor 21
#define Prop_TDBText_FontName 22
#define Prop_TDBText_FontBold 23
#define Prop_TDBText_FontItalic 24
#define Prop_TDBText_FontStrikethru 25
#define Prop_TDBText_FontUnderline 26
#define Prop_TDBText_FontSize 27
#define Prop_TDBText_BorderStyle 28
#define Prop_TDBText_Caption 29
#define Prop_TDBText_Alignment 30
#define Prop_TDBText_AutoSize 31
#define Prop_TDBText_Transparent 32
#define Prop_TDBText_WordWrap 33

// events
#define Event_TDBText_Click 0
#define Event_TDBText_DragOver 1
#define Event_TDBText_DragDrop 2
#define Event_TDBText_EndDrag 3
#define Event_TDBText_DblClick 4
#define Event_TDBText_MouseDown 5
#define Event_TDBText_MouseMove 6
#define Event_TDBText_MouseUp 7

//--------------------------------------------------------
// TDBRadioGroup (VB3, subclassed from BUTTON)
//--------------------------------------------------------

// properties
#define Prop_TDBRadioGroup_DataField 18
#define Prop_TDBRadioGroup_DataChanged 19
#define Prop_TDBRadioGroup_ForeColor 20
#define Prop_TDBRadioGroup_BackColor 21
#define Prop_TDBRadioGroup_FontName 22
#define Prop_TDBRadioGroup_FontBold 23
#define Prop_TDBRadioGroup_FontItalic 24
#define Prop_TDBRadioGroup_FontStrikethru 25
#define Prop_TDBRadioGroup_FontUnderline 26
#define Prop_TDBRadioGroup_FontSize 27
#define Prop_TDBRadioGroup_Caption 28
#define Prop_TDBRadioGroup_Columns 29
#define Prop_TDBRadioGroup_ItemIndex 30
#define Prop_TDBRadioGroup_Items 31
#define Prop_TDBRadioGroup_ReadOnly 32
#define Prop_TDBRadioGroup_Value 33
#define Prop_TDBRadioGroup_Values 34

// events
#define Event_TDBRadioGroup_Click 0
#define Event_TDBRadioGroup_DragOver 1
#define Event_TDBRadioGroup_DragDrop 2
#define Event_TDBRadioGroup_EndDrag 3
#define Event_TDBRadioGroup_DblClick 4
#define Event_TDBRadioGroup_GotFocus 5
#define Event_TDBRadioGroup_LostFocus 6
#define Event_TDBRadioGroup_Change 7

//--------------------------------------------------------
// TDBNavigator (VB3)
//--------------------------------------------------------

// properties
#define Prop_TDBNavigator_BtnFirst 18
#define Prop_TDBNavigator_BtnPrevious 19
#define Prop_TDBNavigator_BtnNext 20
#define Prop_TDBNavigator_BtnLast 21
#define Prop_TDBNavigator_BtnInsert 22
#define Prop_TDBNavigator_BtnDelete 23
#define Prop_TDBNavigator_BtnEdit 24
#define Prop_TDBNavigator_BtnPost 25
#define Prop_TDBNavigator_BtnCancel 26
#define Prop_TDBNavigator_BtnRefresh 27
#define Prop_TDBNavigator_ClickButton 28
#define Prop_TDBNavigator_ConfirmDelete 29

// events
#define Event_TDBNavigator_Click 0
#define Event_TDBNavigator_DragOver 1
#define Event_TDBNavigator_DragDrop 2
#define Event_TDBNavigator_EndDrag 3
#define Event_TDBNavigator_DblClick 4
#define Event_TDBNavigator_GotFocus 5
#define Event_TDBNavigator_LostFocus 6
#define Event_TDBNavigator_ReSize 7

//--------------------------------------------------------
// TDBMemo (VB3, subclassed from EDIT)
//--------------------------------------------------------

// properties
#define Prop_TDBMemo_DataField 18
#define Prop_TDBMemo_DataChanged 19
#define Prop_TDBMemo_ForeColor 20
#define Prop_TDBMemo_BackColor 21
#define Prop_TDBMemo_FontName 22
#define Prop_TDBMemo_FontBold 23
#define Prop_TDBMemo_FontItalic 24
#define Prop_TDBMemo_FontStrikethru 25
#define Prop_TDBMemo_FontUnderline 26
#define Prop_TDBMemo_FontSize 27
#define Prop_TDBMemo_Alignment 28
#define Prop_TDBMemo_AutoDisplay 29
#define Prop_TDBMemo_BorderStyle 30
#define Prop_TDBMemo_Lines 31
#define Prop_TDBMemo_MaxLength 32
#define Prop_TDBMemo_Modified 33
#define Prop_TDBMemo_Name 34
#define Prop_TDBMemo_ReadOnly 35
#define Prop_TDBMemo_ScrollBars 36
#define Prop_TDBMemo_SelLength 37
#define Prop_TDBMemo_SelStart 38
#define Prop_TDBMemo_SelText 39
#define Prop_TDBMemo_WantReturns 40
#define Prop_TDBMemo_WantTabs 41
#define Prop_TDBMemo_WordWrap 42

// events
#define Event_TDBMemo_Click 0
#define Event_TDBMemo_DragOver 1
#define Event_TDBMemo_DragDrop 2
#define Event_TDBMemo_EndDrag 3
#define Event_TDBMemo_DblClick 4
#define Event_TDBMemo_KeyDown 5
#define Event_TDBMemo_KeyPress 6
#define Event_TDBMemo_KeyUp 7
#define Event_TDBMemo_GotFocus 8
#define Event_TDBMemo_LostFocus 9
#define Event_TDBMemo_MouseDown 10
#define Event_TDBMemo_MouseMove 11
#define Event_TDBMemo_MouseUp 12
#define Event_TDBMemo_Change 13

//--------------------------------------------------------
// TDBLookupList (VB3, subclassed from LISTBOX)
//--------------------------------------------------------

// properties
#define Prop_TDBLookupList_DataField 18
#define Prop_TDBLookupList_DataChanged 19
#define Prop_TDBLookupList_ForeColor 20
#define Prop_TDBLookupList_BackColor 21
#define Prop_TDBLookupList_FontName 22
#define Prop_TDBLookupList_FontBold 23
#define Prop_TDBLookupList_FontItalic 24
#define Prop_TDBLookupList_FontStrikethru 25
#define Prop_TDBLookupList_FontUnderline 26
#define Prop_TDBLookupList_FontSize 27
#define Prop_TDBLookupList_BorderStyle 28
#define Prop_TDBLookupList_Caption 29
#define Prop_TDBLookupList_DisplayValue 30
#define Prop_TDBLookupList_FieldCount 31
#define Prop_TDBLookupList_IntegralHeight 32
#define Prop_TDBLookupList_ItemHeight 33
#define Prop_TDBLookupList_ItemIndex 34
#define Prop_TDBLookupList_LookupHctl 35
#define Prop_TDBLookupList_LookupDisplay 36
#define Prop_TDBLookupList_LookupField 37
#define Prop_TDBLookupList_LookupSource 38
#define Prop_TDBLookupList_LookupIndex 39
#define Prop_TDBLookupList_Options 40
#define Prop_TDBLookupList_ReadOnly 41
#define Prop_TDBLookupList_SelectedField 42
#define Prop_TDBLookupList_SelectedIndex 43
#define Prop_TDBLookupList_Sorted 44
#define Prop_TDBLookupList_Style 45
#define Prop_TDBLookupList_TopIndex 46
#define Prop_TDBLookupList_Value 47

// events
#define Event_TDBLookupList_Click 0
#define Event_TDBLookupList_DragOver 1
#define Event_TDBLookupList_DragDrop 2
#define Event_TDBLookupList_EndDrag 3
#define Event_TDBLookupList_DblClick 4
#define Event_TDBLookupList_KeyDown 5
#define Event_TDBLookupList_KeyPress 6
#define Event_TDBLookupList_KeyUp 7
#define Event_TDBLookupList_GotFocus 8
#define Event_TDBLookupList_LostFocus 9

//--------------------------------------------------------
// TDBLookupCombo (VB3, subclassed from COMBOBOX)
//--------------------------------------------------------

// properties
#define Prop_TDBLookupCombo_DataField 18
#define Prop_TDBLookupCombo_DataChanged 19
#define Prop_TDBLookupCombo_ForeColor 20
#define Prop_TDBLookupCombo_BackColor 21
#define Prop_TDBLookupCombo_FontName 22
#define Prop_TDBLookupCombo_FontBold 23
#define Prop_TDBLookupCombo_FontItalic 24
#define Prop_TDBLookupCombo_FontStrikethru 25
#define Prop_TDBLookupCombo_FontUnderline 26
#define Prop_TDBLookupCombo_FontSize 27
#define Prop_TDBLookupCombo_AutoSelect 28
#define Prop_TDBLookupCombo_Caption 29
#define Prop_TDBLookupCombo_DisplayValue 30
#define Prop_TDBLookupCombo_DropDownCount 31
#define Prop_TDBLookupCombo_DropDownWidth 32
#define Prop_TDBLookupCombo_ItemHeight 33
#define Prop_TDBLookupCombo_ItemIndex 34
#define Prop_TDBLookupCombo_LookupHctl 35
#define Prop_TDBLookupCombo_LookupDisplay 36
#define Prop_TDBLookupCombo_LookupField 37
#define Prop_TDBLookupCombo_LookupSource 38
#define Prop_TDBLookupCombo_LookupIndex 39
#define Prop_TDBLookupCombo_MaxLength 40
#define Prop_TDBLookupCombo_Options 41
#define Prop_TDBLookupCombo_ReadOnly 42
#define Prop_TDBLookupCombo_SelLength 43
#define Prop_TDBLookupCombo_SelStart 44
#define Prop_TDBLookupCombo_SelText 45
#define Prop_TDBLookupCombo_Sorted 46
#define Prop_TDBLookupCombo_Style 47
#define Prop_TDBLookupCombo_Value 48

// events
#define Event_TDBLookupCombo_Click 0
#define Event_TDBLookupCombo_DragOver 1
#define Event_TDBLookupCombo_DragDrop 2
#define Event_TDBLookupCombo_EndDrag 3
#define Event_TDBLookupCombo_DblClick 4
#define Event_TDBLookupCombo_KeyDown 5
#define Event_TDBLookupCombo_KeyPress 6
#define Event_TDBLookupCombo_KeyUp 7
#define Event_TDBLookupCombo_GotFocus 8
#define Event_TDBLookupCombo_LostFocus 9
#define Event_TDBLookupCombo_MouseDown 10
#define Event_TDBLookupCombo_MouseMove 11
#define Event_TDBLookupCombo_MouseUp 12
#define Event_TDBLookupCombo_Change 13
#define Event_TDBLookupCombo_DropDown 14

//--------------------------------------------------------
// TDBListBox (VB3, subclassed from LISTBOX)
//--------------------------------------------------------

// properties
#define Prop_TDBListBox_DataField 18
#define Prop_TDBListBox_DataChanged 19
#define Prop_TDBListBox_ForeColor 20
#define Prop_TDBListBox_BackColor 21
#define Prop_TDBListBox_FontName 22
#define Prop_TDBListBox_FontBold 23
#define Prop_TDBListBox_FontItalic 24
#define Prop_TDBListBox_FontStrikethru 25
#define Prop_TDBListBox_FontUnderline 26
#define Prop_TDBListBox_FontSize 27
#define Prop_TDBListBox_Action 28
#define Prop_TDBListBox_BorderStyle 29
#define Prop_TDBListBox_Canvas 30
#define Prop_TDBListBox_Caption 31
#define Prop_TDBListBox_IntegralHeight 32
#define Prop_TDBListBox_ItemData 33
#define Prop_TDBListBox_ItemHeight 34
#define Prop_TDBListBox_ItemIndex 35
#define Prop_TDBListBox_Items 36
#define Prop_TDBListBox_ReadOnly 37
#define Prop_TDBListBox_Sorted 38
#define Prop_TDBListBox_Style 39
#define Prop_TDBListBox_TopIndex 40
#define Prop_TDBListBox_Value 41

// events
#define Event_TDBListBox_Click 0
#define Event_TDBListBox_DragOver 1
#define Event_TDBListBox_DragDrop 2
#define Event_TDBListBox_EndDrag 3
#define Event_TDBListBox_DblClick 4
#define Event_TDBListBox_KeyDown 5
#define Event_TDBListBox_KeyPress 6
#define Event_TDBListBox_KeyUp 7
#define Event_TDBListBox_GotFocus 8
#define Event_TDBListBox_LostFocus 9
#define Event_TDBListBox_MouseDown 10
#define Event_TDBListBox_MouseMove 11
#define Event_TDBListBox_MouseUp 12
#define Event_TDBListBox_MeasureItem 13
#define Event_TDBListBox_DrawItem 14

//--------------------------------------------------------
// TDBImage (VB3)
//--------------------------------------------------------

// properties
#define Prop_TDBImage_DataField 18
#define Prop_TDBImage_DataChanged 19
#define Prop_TDBImage_ForeColor 20
#define Prop_TDBImage_BackColor 21
#define Prop_TDBImage_AutoDisplay 22
#define Prop_TDBImage_AutoSize 23
#define Prop_TDBImage_BorderStyle 24
#define Prop_TDBImage_Caption 25
#define Prop_TDBImage_Center 26
#define Prop_TDBImage_Name 27
#define Prop_TDBImage_Picture 28
#define Prop_TDBImage_ReadOnly 29
#define Prop_TDBImage_Stretch 30

// events
#define Event_TDBImage_Click 0
#define Event_TDBImage_DragOver 1
#define Event_TDBImage_DragDrop 2
#define Event_TDBImage_EndDrag 3
#define Event_TDBImage_DblClick 4
#define Event_TDBImage_KeyDown 5
#define Event_TDBImage_KeyPress 6
#define Event_TDBImage_KeyUp 7
#define Event_TDBImage_GotFocus 8
#define Event_TDBImage_LostFocus 9
#define Event_TDBImage_MouseDown 10
#define Event_TDBImage_MouseMove 11
#define Event_TDBImage_MouseUp 12

//--------------------------------------------------------
// TDBEdit (VB3, subclassed from EDIT)
//--------------------------------------------------------

// properties
#define Prop_TDBEdit_DataField 18
#define Prop_TDBEdit_DataChanged 19
#define Prop_TDBEdit_ForeColor 20
#define Prop_TDBEdit_BackColor 21
#define Prop_TDBEdit_FontName 22
#define Prop_TDBEdit_FontBold 23
#define Prop_TDBEdit_FontItalic 24
#define Prop_TDBEdit_FontStrikethru 25
#define Prop_TDBEdit_FontUnderline 26
#define Prop_TDBEdit_FontSize 27
#define Prop_TDBEdit_AutoSelect 28
#define Prop_TDBEdit_AutoSize 29
#define Prop_TDBEdit_BorderStyle 30
#define Prop_TDBEdit_CharCase 31
#define Prop_TDBEdit_Caption 32
#define Prop_TDBEdit_MaxLength 33
#define Prop_TDBEdit_Modified 34
#define Prop_TDBEdit_PasswordChar 35
#define Prop_TDBEdit_ReadOnly 36
#define Prop_TDBEdit_SelLength 37
#define Prop_TDBEdit_SelStart 38
#define Prop_TDBEdit_SelText 39

// events
#define Event_TDBEdit_Click 0
#define Event_TDBEdit_DragOver 1
#define Event_TDBEdit_DragDrop 2
#define Event_TDBEdit_EndDrag 3
#define Event_TDBEdit_DblClick 4
#define Event_TDBEdit_KeyDown 5
#define Event_TDBEdit_KeyPress 6
#define Event_TDBEdit_KeyUp 7
#define Event_TDBEdit_GotFocus 8
#define Event_TDBEdit_LostFocus 9
#define Event_TDBEdit_MouseDown 10
#define Event_TDBEdit_MouseMove 11
#define Event_TDBEdit_MouseUp 12
#define Event_TDBEdit_Change 13

//--------------------------------------------------------
// TDBCheckBox (VB3, subclassed from BUTTON)
//--------------------------------------------------------

// properties
#define Prop_TDBCheckBox_DataField 18
#define Prop_TDBCheckBox_DataChanged 19
#define Prop_TDBCheckBox_ForeColor 20
#define Prop_TDBCheckBox_BackColor 21
#define Prop_TDBCheckBox_FontName 22
#define Prop_TDBCheckBox_FontBold 23
#define Prop_TDBCheckBox_FontItalic 24
#define Prop_TDBCheckBox_FontStrikethru 25
#define Prop_TDBCheckBox_FontUnderline 26
#define Prop_TDBCheckBox_FontSize 27
#define Prop_TDBCheckBox_Alignment 28
#define Prop_TDBCheckBox_AllowGrayed 29
#define Prop_TDBCheckBox_Checked 30
#define Prop_TDBCheckBox_Caption 31
#define Prop_TDBCheckBox_ReadOnly 32
#define Prop_TDBCheckBox_State 33
#define Prop_TDBCheckBox_ValueChecked 34
#define Prop_TDBCheckBox_ValueUnChecked 35

// events
#define Event_TDBCheckBox_Click 0
#define Event_TDBCheckBox_DragOver 1
#define Event_TDBCheckBox_DragDrop 2
#define Event_TDBCheckBox_EndDrag 3
#define Event_TDBCheckBox_KeyDown 4
#define Event_TDBCheckBox_KeyPress 5
#define Event_TDBCheckBox_KeyUp 6
#define Event_TDBCheckBox_GotFocus 7
#define Event_TDBCheckBox_LostFocus 8
#define Event_TDBCheckBox_MouseDown 9
#define Event_TDBCheckBox_MouseMove 10
#define Event_TDBCheckBox_MouseUp 11

//--------------------------------------------------------
// TDBComboBox (VB3, subclassed from COMBOBOX)
//--------------------------------------------------------

// properties
#define Prop_TDBComboBox_DataField 18
#define Prop_TDBComboBox_DataChanged 19
#define Prop_TDBComboBox_ForeColor 20
#define Prop_TDBComboBox_BackColor 21
#define Prop_TDBComboBox_FontName 22
#define Prop_TDBComboBox_FontBold 23
#define Prop_TDBComboBox_FontItalic 24
#define Prop_TDBComboBox_FontStrikethru 25
#define Prop_TDBComboBox_FontUnderline 26
#define Prop_TDBComboBox_FontSize 27
#define Prop_TDBComboBox_Action 28
#define Prop_TDBComboBox_Canvas 29
#define Prop_TDBComboBox_Caption 30
#define Prop_TDBComboBox_DropDownCount 31
#define Prop_TDBComboBox_DropDownWidth 32
#define Prop_TDBComboBox_ItemData 33
#define Prop_TDBComboBox_ItemHeight 34
#define Prop_TDBComboBox_ItemIndex 35
#define Prop_TDBComboBox_Items 36
#define Prop_TDBComboBox_MaxLength 37
#define Prop_TDBComboBox_ReadOnly 38
#define Prop_TDBComboBox_SelLength 39
#define Prop_TDBComboBox_SelStart 40
#define Prop_TDBComboBox_SelText 41
#define Prop_TDBComboBox_Sorted 42
#define Prop_TDBComboBox_Style 43

// events
#define Event_TDBComboBox_Click 0
#define Event_TDBComboBox_DragOver 1
#define Event_TDBComboBox_DragDrop 2
#define Event_TDBComboBox_EndDrag 3
#define Event_TDBComboBox_DblClick 4
#define Event_TDBComboBox_KeyDown 5
#define Event_TDBComboBox_KeyPress 6
#define Event_TDBComboBox_KeyUp 7
#define Event_TDBComboBox_GotFocus 8
#define Event_TDBComboBox_LostFocus 9
#define Event_TDBComboBox_Change 10
#define Event_TDBComboBox_MeasureItem 11
#define Event_TDBComboBox_DrawItem 12
#define Event_TDBComboBox_DropDown 13

