//--------------------------------------------------------
// MHCD2001.H generated from MHCD200.VBX by
// VbxGen 1.0 - Borland International
//--------------------------------------------------------
#ifndef  __MHCD2001_H
#define __MHCD2001_H
#ifdef __OWL_OWLDEFS_H
  #include <owl\vbxctl.h>
#endif

//--------------------------------------------------------
// MhCardDeck (VB1)
//--------------------------------------------------------

// properties
#define Prop_MhCardDeck_CtlName 0
#define Prop_MhCardDeck_Index 1
#define Prop_MhCardDeck_Left 2
#define Prop_MhCardDeck_Top 3
#define Prop_MhCardDeck_Width 4
#define Prop_MhCardDeck_Height 5
#define Prop_MhCardDeck_Enabled 6
#define Prop_MhCardDeck_Visible 7
#define Prop_MhCardDeck_MousePointer 8
#define Prop_MhCardDeck_TabIndex 9
#define Prop_MhCardDeck_Autosize 10
#define Prop_MhCardDeck_CardBack 11
#define Prop_MhCardDeck_Value 12
#define Prop_MhCardDeck_Suit 13
#define Prop_MhCardDeck_DragIcon 14
#define Prop_MhCardDeck_DragMode 15
#define Prop_MhCardDeck_TabStop 16
#define Prop_MhCardDeck_Tag 17
#define Prop_MhCardDeck_BackColor 18
#define Prop_MhCardDeck_Parent 19
#define Prop_MhCardDeck_hWnd 20

// events
#define Event_MhCardDeck_Change 0
#define Event_MhCardDeck_Click 1
#define Event_MhCardDeck_DblClick 2
#define Event_MhCardDeck_DragDrop 3
#define Event_MhCardDeck_DragOver 4
#define Event_MhCardDeck_GotFocus 5
#define Event_MhCardDeck_KeyDown 6
#define Event_MhCardDeck_KeyPress 7
#define Event_MhCardDeck_KeyUp 8
#define Event_MhCardDeck_LostFocus 9
#define Event_MhCardDeck_MouseDown 10
#define Event_MhCardDeck_MouseMove 11
#define Event_MhCardDeck_MouseUp 12

// default form data
//
// Some VBX controls do not operate correctly when created without
// a form file.  This occurs when a program creates a control
// dynamically rather than as part of a dialog resource.  If this
// control exhibits problems in this mode, try creating it with the
// following form data:
//
// For OWL programs:
//
//   TVbxMhCardDeck* c = new TVbxMhCardDeck(..., sizeof(MhCardDeckData), MhCardDeckData);
//
// For C/C++ programs:
//
//   HFORMFILE file = VBXCreateFormFile(sizeof(MhCardDeckData), MhCardDeckData);
//   HCTL c = VBXCreate(..., file);
//   VBXDeleteFormFile(file);
//
// Note that the VBXGEN_DATA or MhCardDeck_DATA symbol must be
// defined in order to use the default form data.
//
extern BYTE MhCardDeckData[49L];
#if defined(VBXGEN_DATA) || defined(MhCardDeck_DATA)
  BYTE MhCardDeckData[49L]={
	 0x00,0x0a,0x4d,0x68,0x43,0x61,0x72,0x64,
	 0x44,0x65,0x63,0x6b,0x01,0x00,0x00,0x02,
	 0x06,0xff,0xff,0x07,0xff,0xff,0x08,0x00,
	 0x09,0x00,0x00,0x0a,0xff,0xff,0x0b,0x00,
	 0x0c,0x00,0x0d,0x00,0x0f,0x00,0x10,0x00,
	 0x00,0x11,0x00,0x12,0xff,0xff,0xff,0x00,
	 0xff,
  };
#endif

#ifdef __OWL_VBXCTL_H


// OWL class
class TVbxMhCardDeck : public TVbxControl {
  public:

    // constructors
	 TVbxMhCardDeck(TWindow* parent, int id, LPCSTR title,
        int x, int y, int w, int h,
        long initLen=0, void far* initData=0, TModule* module=0) :
      TVbxControl(parent, id, "MHCD200.VBX", "MhCardDeck",
          title, x, y, w, h, initLen, initData, module) {}

    TVbxMhCardDeck(TWindow* parent, int resourceId, TModule* module=0) :
		  TVbxControl(parent, resourceId, module) {}

#if 0
	 // event handlers
	 void EvChange(VBXEVENT FAR*)
    {
      // no arguments
    }

    void EvClick(VBXEVENT FAR*)
	 {
    	MessageBox("T.B.D", "Stand", MB_YESNO);
      // no arguments
    }

    void EvDblClick(VBXEVENT FAR*)
	 {
		MessageBox("T.B.D", "Stand", MB_YESNO);
		// no arguments
	 }

	 void EvDragDrop(VBXEVENT FAR*)
	 {
		// Source As Control,X As Integer,Y As Integer
	 }

	 void EvDragOver(VBXEVENT FAR*)
	 {
		// Source As Control,X As Integer,Y As Integer,State As Integer
	 }

	 void EvGotFocus(VBXEVENT FAR*)
	 {
		// no arguments
	 }

	 void EvKeyDown(VBXEVENT FAR*)
	 {
		// KeyCode As Integer,Shift As Integer
	 }

	 void EvKeyPress(VBXEVENT FAR*)
	 {
		// KeyAscii As Integer
	 }

	 void EvKeyUp(VBXEVENT FAR*)
	 {
		// KeyCode As Integer,Shift As Integer
	 }

	 void EvLostFocus(VBXEVENT FAR*)
	 {
		// no arguments
	 }

	 void EvMouseDown(VBXEVENT FAR*)
	 {
		// Button As Integer,Shift As Integer,X As Integer,Y As Integer
	 }

	 void EvMouseMove(VBXEVENT FAR*)
	 {
		// Button As Integer,Shift As Integer,X As Integer,Y As Integer
	 }

	 void EvMouseUp(VBXEVENT FAR*)
	 {
		// Button As Integer,Shift As Integer,X As Integer,Y As Integer
	 }

#endif
	 // enumerations
	 enum { // values for property MousePointer
		MousePointer_0_Default,
		MousePointer_1_Arrow,
		MousePointer_2_Cross,
		MousePointer_3_IBeam,
		MousePointer_4_Icon,
		MousePointer_5_Size,
		MousePointer_6_Size_NE_SW,
		MousePointer_7_Size_NS,
		MousePointer_8_Size_NW_SE,
		MousePointer_9_Size_WE,
		MousePointer_10_Up_Arrow,
		MousePointer_11_Hourglass,
		MousePointer_12_No_Drop,
	 };

	 enum { // values for property CardBack
		CardBack_0_Red_Checks,
		CardBack_1_Blue_Checks,
		CardBack_2_Red_Hatch,
		CardBack_3_Blue_Hatch,
		CardBack_4_Robot,
		CardBack_5_Roses,
		CardBack_6_Leaves_1,
		CardBack_7_Leaves_2,
		CardBack_8_Fish,
		CardBack_9_Conch,
		CardBack_10_Castle,
		CardBack_11_Beach,
		CardBack_12_Hand,
	 };
	 enum { // values for property Value
		Value_0_Back,
		Value_1_Ace,
		Value_2_Duece,
		Value_3_Three,
		Value_4_Four,
		Value_5_Five,
		Value_6_Six,
		Value_7_Seven,
		Value_8_Eight,
		Value_9_Nine,
		Value_10_Ten,
		Value_11_Jack,
		Value_12_Queen,
		Value_13_King,
	 };

	 enum { // values for property Suit
		Suit_0_Clubs,
		Suit_1_Diamonds,
		Suit_2_Hearts,
		Suit_3_Spades,
	 };

	 enum { // values for property DragMode
		DragMode_0_Manual,
		DragMode_1_Automatic,
	 };


	 // properties
	 BOOL GetPropCtlName(string& v) {return GetProp(0,v);}
    BOOL SetPropCtlName(string& v) {return SetProp(0,v);}

    BOOL GetPropIndex(int& v) {return GetProp(1,v);}
    BOOL SetPropIndex(int v) {return SetProp(1,v);}

	 BOOL GetPropLeft(long& v) {return GetProp(2,v);}
	 BOOL SetPropLeft(long v) {return SetProp(2,v);}

    BOOL GetPropTop(long& v) {return GetProp(3,v);}
    BOOL SetPropTop(long v) {return SetProp(3,v);}

    BOOL GetPropWidth(long& v) {return GetProp(4,v);}
    BOOL SetPropWidth(long v) {return SetProp(4,v);}

	 BOOL GetPropHeight(long& v) {return GetProp(5,v);}
    BOOL SetPropHeight(long v) {return SetProp(5,v);}

    BOOL GetPropEnabled(BOOL& v) {return GetProp(6,v);}
    BOOL SetPropEnabled(BOOL v) {return SetProp(6,v);}

    BOOL GetPropVisible(BOOL& v) {return GetProp(7,v);}
    BOOL SetPropVisible(BOOL v) {return SetProp(7,v);}

    BOOL GetPropMousePointer(ENUM& v) {return GetProp(8,v);}
    BOOL SetPropMousePointer(ENUM v) {return SetProp(8,v);}

    BOOL GetPropTabIndex(int& v) {return GetProp(9,v);}
    BOOL SetPropTabIndex(int v) {return SetProp(9,v);}

    BOOL GetPropAutosize(BOOL& v) {return GetProp(10,v);}
    BOOL SetPropAutosize(BOOL v) {return SetProp(10,v);}

    BOOL GetPropCardBack(ENUM& v) {return GetProp(11,v);}
    BOOL SetPropCardBack(ENUM v) {return SetProp(11,v);}

    BOOL GetPropValue(ENUM& v) {return GetProp(12,v);}
    BOOL SetPropValue(ENUM v) {return SetProp(12,v);}

    BOOL GetPropSuit(ENUM& v) {return GetProp(13,v);}
	 BOOL SetPropSuit(ENUM v) {return SetProp(13,v);}

    BOOL GetPropDragIcon(HPIC& v) {return GetProp(14,v);}
    BOOL SetPropDragIcon(HPIC v) {return SetProp(14,v);}

    BOOL GetPropDragMode(ENUM& v) {return GetProp(15,v);}
    BOOL SetPropDragMode(ENUM v) {return SetProp(15,v);}

    BOOL GetPropTabStop(BOOL& v) {return GetProp(16,v);}
    BOOL SetPropTabStop(BOOL v) {return SetProp(16,v);}

    BOOL GetPropTag(string& v) {return GetProp(17,v);}
    BOOL SetPropTag(string& v) {return SetProp(17,v);}

    BOOL GetPropBackColor(COLORREF& v) {return GetProp(18,v);}
    BOOL SetPropBackColor(COLORREF v) {return SetProp(18,v);}

    BOOL GetPropParent(int& v) {return GetProp(19,v);}
    BOOL SetPropParent(int v) {return SetProp(19,v);}

    BOOL GetProphWnd(int& v) {return GetProp(20,v);}
    BOOL SetProphWnd(int v) {return SetProp(20,v);}

#if 0
  DECLARE_RESPONSE_TABLE(TVbxMhCardDeck);
#endif
};

#if 0
// OWL response table
DEFINE_RESPONSE_TABLE1(TVbxMhCardDeck, TVbxControl)

  EV_VBXEVENTINDEX( IDC_MHCARDDECK2, Event_MhCardDeck_Change, EvChange ),
  EV_VBXEVENTINDEX( IDC_MHCARDDECK2, Event_MhCardDeck_Click, EvClick ),
  EV_VBXEVENTINDEX( IDC_MHCARDDECK2, Event_MhCardDeck_DblClick, EvDblClick ),
  EV_VBXEVENTINDEX( IDC_MHCARDDECK2, Event_MhCardDeck_DragDrop, EvDragDrop ),
  EV_VBXEVENTINDEX( IDC_MHCARDDECK2, Event_MhCardDeck_DragOver, EvDragOver ),
  EV_VBXEVENTINDEX( IDC_MHCARDDECK2, Event_MhCardDeck_GotFocus, EvGotFocus ),
  EV_VBXEVENTINDEX( IDC_MHCARDDECK2, Event_MhCardDeck_KeyDown, EvKeyDown ),
  EV_VBXEVENTINDEX( IDC_MHCARDDECK2, Event_MhCardDeck_KeyPress, EvKeyPress ),
  EV_VBXEVENTINDEX( IDC_MHCARDDECK2, Event_MhCardDeck_KeyUp, EvKeyUp ),
  EV_VBXEVENTINDEX( IDC_MHCARDDECK2, Event_MhCardDeck_LostFocus, EvLostFocus ),
  EV_VBXEVENTINDEX( IDC_MHCARDDECK2, Event_MhCardDeck_MouseDown, EvMouseDown ),
  EV_VBXEVENTINDEX( IDC_MHCARDDECK2, Event_MhCardDeck_MouseMove, EvMouseMove ),
  EV_VBXEVENTINDEX( IDC_MHCARDDECK2, Event_MhCardDeck_MouseUp, EvMouseUp ),
END_RESPONSE_TABLE;
#endif

#endif //__OWL_VBXCTL_H
#endif
