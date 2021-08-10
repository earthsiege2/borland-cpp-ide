
{*******************************************************}
{                                                       }
{       Borland Delphi Run-time Library                 }
{       Win32 Pen API Interface Unit                    }
{                                                       }
{       Copyright (c) 1985-1999, Microsoft Corporation  }
{                                                       }
{       Translator: Inprise Corporation                 }
{                                                       }
{*******************************************************}

unit PenWin;

{$WEAKPACKAGEUNIT}

{ Pen Windows functions, types, and definitions  }

{ "FBC" in the comments means that the feature exists only for
  backward compatibility. It should not be used by new applications. }

interface

uses Windows, Messages, MMSystem;

{ Enabled Alphabet: }

const
  ALC_DEFAULT              = $00000000;  { nothing }
{$EXTERNALSYM ALC_DEFAULT}
  ALC_LCALPHA              = $00000001;  { a..z }
{$EXTERNALSYM ALC_LCALPHA}
  ALC_UCALPHA              = $00000002;  { A..Z }
{$EXTERNALSYM ALC_UCALPHA}
  ALC_NUMERIC              = $00000004;  { 0..9 }
{$EXTERNALSYM ALC_NUMERIC}
  ALC_PUNC                 = $00000008;  { !-;`"?()&.,; and backslash }
{$EXTERNALSYM ALC_PUNC}
  ALC_MATH                 = $00000010;  // %^*()-+={}<>,/.
{$EXTERNALSYM ALC_MATH}
  ALC_MONETARY             = $00000020;  { ,.$ or local }
{$EXTERNALSYM ALC_MONETARY}
  ALC_OTHER                = $00000040;  { @#|_~[] }
{$EXTERNALSYM ALC_OTHER}
  ALC_ASCII                = $00000080;  { restrict to 7-bit chars 20..7f }
{$EXTERNALSYM ALC_ASCII}
  ALC_WHITE                = $00000100;  { white space }
{$EXTERNALSYM ALC_WHITE}
  ALC_NONPRINT             = $00000200;  { sp tab ret ctrl glyphs }
{$EXTERNALSYM ALC_NONPRINT}
  ALC_DBCS                 = $00000400;  { allow DBCS variety of SBCS }
{$EXTERNALSYM ALC_DBCS}
  ALC_JIS1                 = $00000800;  { kanji JPN, ShiftJIS 1 only }
{$EXTERNALSYM ALC_JIS1}
  ALC_GESTURE              = $00004000;  { gestures }
{$EXTERNALSYM ALC_GESTURE}
  ALC_USEBITMAP            = $00008000;  { use rc.rgbfAlc to enable chars }
{$EXTERNALSYM ALC_USEBITMAP}
  ALC_HIRAGANA             = $00010000;  { hiragana JPN }
{$EXTERNALSYM ALC_HIRAGANA}
  ALC_KATAKANA             = $00020000;  { katakana JPN }
{$EXTERNALSYM ALC_KATAKANA}
  ALC_KANJI                = $00040000;  { kanji JPN, ShiftJIS 1+2+3 }
{$EXTERNALSYM ALC_KANJI}
  ALC_GLOBALPRIORITY       = $10000000;
{$EXTERNALSYM ALC_GLOBALPRIORITY}
  ALC_OEM                  = $0FF80000;  { OEM recognizer-specific }
{$EXTERNALSYM ALC_OEM}
  ALC_RESERVED             = $E0003000;  { avail for future use }
{$EXTERNALSYM ALC_RESERVED}
  ALC_NOPRIORITY           = $00000000;  { for alcPriority = none }
{$EXTERNALSYM ALC_NOPRIORITY}
  ALC_ALPHA                = ALC_LCALPHA or ALC_UCALPHA;
{$EXTERNALSYM ALC_ALPHA}
  ALC_ALPHANUMERIC         = ALC_ALPHA or ALC_NUMERIC;
{$EXTERNALSYM ALC_ALPHANUMERIC}
  ALC_SYSMINIMUM = ALC_ALPHANUMERIC or ALC_PUNC or ALC_WHITE or ALC_GESTURE;
{$EXTERNALSYM ALC_SYSMINIMUM}
  ALC_ALL = ALC_SYSMINIMUM or ALC_MATH or ALC_MONETARY or ALC_OTHER or ALC_NONPRINT;
{$EXTERNALSYM ALC_ALL}
  ALC_KANJISYSMINIMUM = ALC_SYSMINIMUM or ALC_HIRAGANA or ALC_KATAKANA or ALC_JIS1;
{$EXTERNALSYM ALC_KANJISYSMINIMUM}
  ALC_KANJIALL = ALC_ALL or ALC_HIRAGANA or ALC_KATAKANA or ALC_KANJI;
{$EXTERNALSYM ALC_KANJIALL}

{ box edit styles: }

  BXS_NONE                 = $0000;  { none }
{$EXTERNALSYM BXS_NONE}
  BXS_RECT                 = $0001;  { use rectangle instead of cusp }
{$EXTERNALSYM BXS_RECT}
  BXS_BOXCROSS             = $0004;  { use cross at box center }
{$EXTERNALSYM BXS_BOXCROSS}
  BXS_MASK                 = $0007;  { mask for above }
{$EXTERNALSYM BXS_MASK}

{ Public Bitmaps : }

  OBM_SKBBTNUP                = 32767;
{$EXTERNALSYM OBM_SKBBTNUP}
  OBM_SKBBTNDOWN              = 32766;
{$EXTERNALSYM OBM_SKBBTNDOWN}
  OBM_SKBBTNDISABLED          = 32765;
{$EXTERNALSYM OBM_SKBBTNDISABLED}

  OBM_ZENBTNUP                = 32764;
{$EXTERNALSYM OBM_ZENBTNUP}
  OBM_ZENBTNDOWN              = 32763;
{$EXTERNALSYM OBM_ZENBTNDOWN}
  OBM_ZENBTNDISABLED          = 32762;
{$EXTERNALSYM OBM_ZENBTNDISABLED}

  OBM_HANBTNUP                = 32761;
{$EXTERNALSYM OBM_HANBTNUP}
  OBM_HANBTNDOWN              = 32760;
{$EXTERNALSYM OBM_HANBTNDOWN}
  OBM_HANBTNDISABLED          = 32759;
{$EXTERNALSYM OBM_HANBTNDISABLED}

  OBM_KKCBTNUP                = 32758;
{$EXTERNALSYM OBM_KKCBTNUP}
  OBM_KKCBTNDOWN              = 32757;
{$EXTERNALSYM OBM_KKCBTNDOWN}
  OBM_KKCBTNDISABLED          = 32756;
 {$EXTERNALSYM OBM_KKCBTNDISABLED}

  OBM_SIPBTNUP                = 32755;
{$EXTERNALSYM OBM_SIPBTNUP}
  OBM_SIPBTNDOWN              = 32754;
{$EXTERNALSYM OBM_SIPBTNDOWN}
  OBM_SIPBTNDISABLED          = 32753;
{$EXTERNALSYM OBM_SIPBTNDISABLED}

  OBM_PTYBTNUP                = 32752;
{$EXTERNALSYM OBM_PTYBTNUP}
  OBM_PTYBTNDOWN              = 32751;
{$EXTERNALSYM OBM_PTYBTNDOWN}
  OBM_PTYBTNDISABLED          = 32750;
{$EXTERNALSYM OBM_PTYBTNDISABLED}

{ Default pen cursor to indicate writing, points northwest }
  IDC_PEN             = MAKEINTRESOURCE(32631);
{$EXTERNALSYM IDC_PEN}

{ alternate select cursor: upsidedown standard arrow, points southeast }
  IDC_ALTSELECT       = MAKEINTRESOURCE(32501);
{$EXTERNALSYM IDC_ALTSELECT}

{ special SYV values: }
  SYV_NULL                    = $00000000;
{$EXTERNALSYM SYV_NULL}
  SYV_UNKNOWN                 = $00000001;
{$EXTERNALSYM SYV_UNKNOWN}
  SYV_EMPTY                   = $00000003;
{$EXTERNALSYM SYV_EMPTY}
  SYV_BEGINOR                 = $00000010;
{$EXTERNALSYM SYV_BEGINOR}
  SYV_ENDOR                   = $00000011;
{$EXTERNALSYM SYV_ENDOR}
  SYV_OR                      = $00000012;
{$EXTERNALSYM SYV_OR}
  SYV_SOFTNEWLINE             = $00000020;
{$EXTERNALSYM SYV_SOFTNEWLINE}
  SYV_SPACENULL               = $00010000;    { SyvCharacterToSymbol('\0') }
{$EXTERNALSYM SYV_SPACENULL}

{ SYV values for gestures: }
  SYV_SELECTFIRST             = $0002FFC0;    { . means circle in following }
{$EXTERNALSYM SYV_SELECTFIRST}
  SYV_LASSO                   = $0002FFC1;    { lasso o-tap }
{$EXTERNALSYM SYV_LASSO}
  SYV_SELECTLEFT              = $0002FFC2;    { no glyph }
{$EXTERNALSYM SYV_SELECTLEFT}
  SYV_SELECTRIGHT             = $0002FFC3;    { no glyph }
{$EXTERNALSYM SYV_SELECTRIGHT}
  SYV_SELECTLAST              = $0002FFCF;    { 16 SYVs reserved for selection }
{$EXTERNALSYM SYV_SELECTLAST}

  SYV_CLEARCHAR               = $0002FFD2;    { d. }
{$EXTERNALSYM SYV_CLEARCHAR}
  SYV_HELP                    = $0002FFD3;    { no glyph }
{$EXTERNALSYM SYV_HELP}
  SYV_KKCONVERT               = $0002FFD4;    { k. }
{$EXTERNALSYM SYV_KKCONVERT}
  SYV_CLEAR                   = $0002FFD5;    { d. }
{$EXTERNALSYM SYV_CLEAR}
  SYV_INSERT                  = $0002FFD6;    { ^. }
{$EXTERNALSYM SYV_INSERT}
  SYV_CONTEXT                 = $0002FFD7;    { m. }
{$EXTERNALSYM SYV_CONTEXT}
  SYV_EXTENDSELECT            = $0002FFD8;    { no glyph }
{$EXTERNALSYM SYV_EXTENDSELECT}
  SYV_UNDO                    = $0002FFD9;    { u. }
{$EXTERNALSYM SYV_UNDO}
  SYV_COPY                    = $0002FFDA;    { c. }
{$EXTERNALSYM SYV_COPY}
  SYV_CUT                     = $0002FFDB;    { x. }
{$EXTERNALSYM SYV_CUT}
  SYV_PASTE                   = $0002FFDC;    { p. }
{$EXTERNALSYM SYV_PASTE}
  SYV_CLEARWORD               = $0002FFDD;    { no glyph }
{$EXTERNALSYM SYV_CLEARWORD}
  SYV_USER                    = $0002FFDE;    { reserved }
{$EXTERNALSYM SYV_USER}
  SYV_CORRECT                 = $0002FFDF;    { check. }
{$EXTERNALSYM SYV_CORRECT}

  SYV_BACKSPACE               = $00020008;    { no glyph }
{$EXTERNALSYM SYV_BACKSPACE}
  SYV_TAB                     = $00020009;    { t. }
{$EXTERNALSYM SYV_TAB}
  SYV_RETURN                  = $0002000D;    { n. }
{$EXTERNALSYM SYV_RETURN}
  SYV_SPACE                   = $00020020;    { s. }
{$EXTERNALSYM SYV_SPACE}

{ Application specific gestures, Circle a-z and Circle A-Z: }
  SYV_APPGESTUREMASK          = $00020000;
{$EXTERNALSYM SYV_APPGESTUREMASK}
  SYV_CIRCLEUPA               = $000224B6;    { map into Unicode space }
{$EXTERNALSYM SYV_CIRCLEUPA}
  SYV_CIRCLEUPZ               = $000224CF;    {  for circled letters }
{$EXTERNALSYM SYV_CIRCLEUPZ}
  SYV_CIRCLELOA               = $000224D0;
{$EXTERNALSYM SYV_CIRCLELOA}
  SYV_CIRCLELOZ               = $000224E9;
{$EXTERNALSYM SYV_CIRCLELOZ}

{ SYV definitions for shapes: }
  SYV_SHAPELINE               = $00040001;
{$EXTERNALSYM SYV_SHAPELINE}
  SYV_SHAPEELLIPSE            = $00040002;
{$EXTERNALSYM SYV_SHAPEELLIPSE}
  SYV_SHAPERECT               = $00040003;
{$EXTERNALSYM SYV_SHAPERECT}
  SYV_SHAPEMIN                = SYV_SHAPELINE; { alias }
{$EXTERNALSYM SYV_SHAPEMIN}
  SYV_SHAPEMAX                = SYV_SHAPERECT; { alias }
{$EXTERNALSYM SYV_SHAPEMAX}

{ SYV classes: }
  SYVHI_SPECIAL               = 0;
{$EXTERNALSYM SYVHI_SPECIAL}
  SYVHI_ANSI                  = 1;
{$EXTERNALSYM SYVHI_ANSI}
  SYVHI_GESTURE               = 2;
{$EXTERNALSYM SYVHI_GESTURE}
  SYVHI_KANJI                 = 3;
{$EXTERNALSYM SYVHI_KANJI}
  SYVHI_SHAPE                 = 4;
{$EXTERNALSYM SYVHI_SHAPE}
  SYVHI_UNICODE               = 5;
{$EXTERNALSYM SYVHI_UNICODE}
  SYVHI_VKEY                  = 6;
{$EXTERNALSYM SYVHI_VKEY}


{ IEdit Pop-up Menu Command Items }

  IEM_UNDO                    = 1;         { Undo }
{$EXTERNALSYM IEM_UNDO}
  IEM_CUT                     = 2;         { Cut }
{$EXTERNALSYM IEM_CUT}
  IEM_COPY                    = 3;         { Copy }
{$EXTERNALSYM IEM_COPY}
  IEM_PASTE                   = 4;         { Paste }
{$EXTERNALSYM IEM_PASTE}
  IEM_CLEAR                   = 5;         { Clear }
{$EXTERNALSYM IEM_CLEAR}
  IEM_SELECTALL               = 6;         { Select All Strokes }
{$EXTERNALSYM IEM_SELECTALL}
  IEM_ERASE                   = 7;         { Use Eraser }
{$EXTERNALSYM IEM_ERASE}
  IEM_PROPERTIES              = 8;         { DoProperties }
{$EXTERNALSYM IEM_PROPERTIES}
  IEM_LASSO                   = 9;         { Use Lasso }
{$EXTERNALSYM IEM_LASSO}
  IEM_RESIZE                  = 10;        { Resize }
{$EXTERNALSYM IEM_RESIZE}

  IEM_USER                        = 100;   { first menu item# available to app }
{$EXTERNALSYM IEM_USER}

{ IEdit Style Attributes }
  IES_BORDER                  = $0001;   { ctl has a border }
{$EXTERNALSYM IES_BORDER}
  IES_HSCROLL                 = $0002;   { ctl is horizontally scrollable }
{$EXTERNALSYM IES_HSCROLL}
  IES_VSCROLL                 = $0004;   { ctl is vertically scrollable }
{$EXTERNALSYM IES_VSCROLL}
  IES_OWNERDRAW               = $0008;   { ctl will be drawn by parent window }
{$EXTERNALSYM IES_OWNERDRAW}


{ PenData API constants: }

{ ANIMATEINFO callback options: }
  AI_CBSTROKE                 = $FFFF;  { Animate callback after every stroke }
{$EXTERNALSYM AI_CBSTROKE}

{ ANIMATEINFO options: }
  AI_SKIPUPSTROKES            = $0001;  { ignore upstrokes in animation }
{$EXTERNALSYM AI_SKIPUPSTROKES}

{ CompressPenData() API options: }
  CMPD_COMPRESS               = $0001;
{$EXTERNALSYM CMPD_COMPRESS}
  CMPD_DECOMPRESS             = $0002;
{$EXTERNALSYM CMPD_DECOMPRESS}

{ CreatePenDataRegion types: }
  CPDR_BOX                    = 1;      { bounding box }
{$EXTERNALSYM CPDR_BOX}
  CPDR_LASSO                  = 2;      { lasso }
{$EXTERNALSYM CPDR_LASSO}

{ CreatePenData (CPD) and Pen Hardware (PHW) Flags; }
{ The order of PHW flags is important: }
  CPD_DEFAULT                 = $047F;  { CPD_TIME | PHW_ALL }
{$EXTERNALSYM CPD_DEFAULT}
  CPD_USERBYTE                = $0100;  { alloc 8 bits/stroke }
{$EXTERNALSYM CPD_USERBYTE}
  CPD_USERWORD                = $0200;  { alloc 16 bits/stroke }
{$EXTERNALSYM CPD_USERWORD}
  CPD_USERDWORD               = $0300;  { alloc 32 bits/stroke }
{$EXTERNALSYM CPD_USERDWORD}
  CPD_TIME                    = $0400;  { maintain abs time info per stroke }
{$EXTERNALSYM CPD_TIME}

{ DrawPenDataEx() flags/options: }
  DPD_HDCPEN                  = $0001;  { use pen selected in HDC }
{$EXTERNALSYM DPD_HDCPEN}
  DPD_DRAWSEL                 = $0002;  { draw the selection }
{$EXTERNALSYM DPD_DRAWSEL}

{ ExtractPenDataPoints options (EPDP_xx): }
  EPDP_REMOVE                 = $0001;  { Remove points from the pendata }
{$EXTERNALSYM EPDP_REMOVE}

{ ExtractPenDataStrokes options and modifiers (EPDS_xx): }
  EPDS_SELECT                 = 1;      { selected strokes }
{$EXTERNALSYM EPDS_SELECT}
  EPDS_STROKEINDEX            = 2;      { index }
{$EXTERNALSYM EPDS_STROKEINDEX}
  EPDS_USER                   = 3;      { user-specific value }
{$EXTERNALSYM EPDS_USER}
  EPDS_PENTIP                 = 4;      { complete pentip }
{$EXTERNALSYM EPDS_PENTIP}
  EPDS_TIPCOLOR               = 5;      { pentip color }
{$EXTERNALSYM EPDS_TIPCOLOR}
  EPDS_TIPWIDTH               = 6;      { pentip width }
{$EXTERNALSYM EPDS_TIPWIDTH}
  EPDS_TIPNIB                 = 7;      { pentip nib style }
{$EXTERNALSYM EPDS_TIPNIB}
  EPDS_INKSET                 = 8;      { inkset match }
{$EXTERNALSYM EPDS_INKSET}

  EPDS_EQ                     = $0000;  { default: same as }
{$EXTERNALSYM EPDS_EQ}
  EPDS_LT                     = $0010;  { all strokes less than }
{$EXTERNALSYM EPDS_LT}
  EPDS_GT                     = $0020;  { all strokes greater than }
{$EXTERNALSYM EPDS_GT}
  EPDS_NOT                    = $0040;  { all strokes not matching }
{$EXTERNALSYM EPDS_NOT}
  EPDS_NE                     = $0040;  { alias }
{$EXTERNALSYM EPDS_NE}
  EPDS_GTE                    = $0050;  { alias for NOT LT }
{$EXTERNALSYM EPDS_GTE}
  EPDS_LTE                    = $0060;  { alias for NOT GT }
{$EXTERNALSYM EPDS_LTE}
  EPDS_REMOVE                 = $8000;  { remove matching strokes from source }
{$EXTERNALSYM EPDS_REMOVE}

{ GetPenDataAttributes options (GPA_xx): }
  GPA_MAXLEN                  = 1;  { length of longest stroke }
{$EXTERNALSYM GPA_MAXLEN}
  GPA_POINTS                  = 2;  { total number of points }
{$EXTERNALSYM GPA_POINTS}
  GPA_PDTS                    = 3;  { PDTS_xx bits }
{$EXTERNALSYM GPA_PDTS}
  GPA_RATE                    = 4;  { get sampling rate }
{$EXTERNALSYM GPA_RATE}
  GPA_RECTBOUND               = 5;  { bounding rect of all points }
{$EXTERNALSYM GPA_RECTBOUND}
  GPA_RECTBOUNDINK            = 6;  { ditto, adj for fat ink }
{$EXTERNALSYM GPA_RECTBOUNDINK}
  GPA_SIZE                    = 7;  { size of pendata in bytes }
{$EXTERNALSYM GPA_SIZE}
  GPA_STROKES                 = 8;  { total number of strokes }
{$EXTERNALSYM GPA_STROKES}
  GPA_TIME                    = 9;  { absolute time at creation of pendata }
{$EXTERNALSYM GPA_TIME}
  GPA_USER                    = 10; { number of user bytes available: 0, 1, 2, 4 }
{$EXTERNALSYM GPA_USER}
  GPA_VERSION                 = 11; { version number of pendata }
{$EXTERNALSYM GPA_VERSION}

{ GetStrokeAttributes options (GSA_xx): }
  GSA_PENTIP                  = 1;  { get stroke pentip (color, width, nib) }
{$EXTERNALSYM GSA_PENTIP}
  GSA_PENTIPCLASS             = 2;  { same as GSA_PENTIP }
{$EXTERNALSYM GSA_PENTIPCLASS}
  GSA_USER                    = 3;  { get stroke user value }
{$EXTERNALSYM GSA_USER}
  GSA_USERCLASS               = 4;  { get stroke's class user value }
{$EXTERNALSYM GSA_USERCLASS}
  GSA_TIME                    = 5;  { get time of stroke }
{$EXTERNALSYM GSA_TIME}
  GSA_SIZE                    = 6;  { get size of stroke in points and bytes }
{$EXTERNALSYM GSA_SIZE}
  GSA_SELECT                  = 7;  { get selection status of stroke }
{$EXTERNALSYM GSA_SELECT}
  GSA_DOWN                    = 8;  { get up/down state of stroke }
{$EXTERNALSYM GSA_DOWN}
  GSA_RECTBOUND               = 9;  { get the bounding rectangle of the stroke }
{$EXTERNALSYM GSA_RECTBOUND}

{ GetStrokeTableAttributes options (GSA_xx): }
  GSA_PENTIPTABLE             = 10; { get table-indexed pentip }
{$EXTERNALSYM GSA_PENTIPTABLE}
  GSA_SIZETABLE               = 11; { get count of Stroke Class Table entries }
{$EXTERNALSYM GSA_SIZETABLE}
  GSA_USERTABLE               = 12; { get table-indexed user value }
{$EXTERNALSYM GSA_USERTABLE}

  IX_END                      = $FFFF;  { to or past last available index }
{$EXTERNALSYM IX_END}

{ PenTip: }
  PENTIP_NIBDEFAULT           = (0);            { default pen tip nib style }
{$EXTERNALSYM PENTIP_NIBDEFAULT}
  PENTIP_HEIGHTDEFAULT        = (0);            { default pen tip nib height }
{$EXTERNALSYM PENTIP_HEIGHTDEFAULT}
  PENTIP_OPAQUE               = $FF;            { default opaque ink }
{$EXTERNALSYM PENTIP_OPAQUE}
  PENTIP_HILITE               = $80;
{$EXTERNALSYM PENTIP_HILITE}
  PENTIP_TRANSPARENT          = (0);
{$EXTERNALSYM PENTIP_TRANSPARENT}

{ General PenData API return values (PDR_xx): }
  PDR_NOHIT                   = 3;      { hit test failed }
{$EXTERNALSYM PDR_NOHIT}
  PDR_HIT                     = 2;      { hit test succeeded }
{$EXTERNALSYM PDR_HIT}
  PDR_OK                      = 1;      { success }
{$EXTERNALSYM PDR_OK}
  PDR_CANCEL                  = 0;      { callback cancel or impasse }
{$EXTERNALSYM PDR_CANCEL}

  PDR_ERROR                   = -1;     { parameter or unspecified error }
{$EXTERNALSYM PDR_ERROR}
  PDR_PNDTERR                 = -2;     { bad pendata }
{$EXTERNALSYM PDR_PNDTERR}
  PDR_VERSIONERR              = -3;     { pendata version error }
{$EXTERNALSYM PDR_VERSIONERR}
  PDR_COMPRESSED              = -4;     { pendata is compressed }
{$EXTERNALSYM PDR_COMPRESSED}
  PDR_STRKINDEXERR            = -5;     { stroke index error }
{$EXTERNALSYM PDR_STRKINDEXERR}
  PDR_PNTINDEXERR             = -6;     { point index error }
{$EXTERNALSYM PDR_PNTINDEXERR}
  PDR_MEMERR                  = -7;     { memory error }
{$EXTERNALSYM PDR_MEMERR}
  PDR_INKSETERR               = -8;     { bad inkset }
{$EXTERNALSYM PDR_INKSETERR}
  PDR_ABORT                   = -9;     { pendata has become invalid, e.g. }
{$EXTERNALSYM PDR_ABORT}
  PDR_NA                      = -10;    { option not available (pw kernel) }
{$EXTERNALSYM PDR_NA}
  PDR_USERDATAERR             = -16;    { user data error }
{$EXTERNALSYM PDR_USERDATAERR}
  PDR_SCALINGERR              = -17;    { scale error }
{$EXTERNALSYM PDR_SCALINGERR}
  PDR_TIMESTAMPERR            = -18;    { timestamp error }
{$EXTERNALSYM PDR_TIMESTAMPERR}
  PDR_OEMDATAERR              = -19;    { OEM data error }
{$EXTERNALSYM PDR_OEMDATAERR}
  PDR_SCTERR                  = -20;    { SCT error (full) }
{$EXTERNALSYM PDR_SCTERR}

{ PenData Scaling (PDTS): }
  PDTS_LOMETRIC               = 0;      { 0.01mm }
{$EXTERNALSYM PDTS_LOMETRIC}
  PDTS_HIMETRIC               = 1;      { 0.001mm }
{$EXTERNALSYM PDTS_HIMETRIC}
  PDTS_HIENGLISH              = 2;      { 0.001" }
{$EXTERNALSYM PDTS_HIENGLISH}
  PDTS_STANDARDSCALE          = 2;      { PDTS_HIENGLISH   alias }
{$EXTERNALSYM PDTS_STANDARDSCALE}
  PDTS_DISPLAY                = 3;      { display pixel }
{$EXTERNALSYM PDTS_DISPLAY}
  PDTS_ARBITRARY              = 4;      { app-specific scaling }
{$EXTERNALSYM PDTS_ARBITRARY}
  PDTS_SCALEMASK              = $000F;  { scaling values in low nibble }
{$EXTERNALSYM PDTS_SCALEMASK}

{ CompactPenData API trim options: }
  PDTT_DEFAULT                = $0000;
{$EXTERNALSYM PDTT_DEFAULT}
  PDTT_PENINFO                = $0100;
{$EXTERNALSYM PDTT_PENINFO}
  PDTT_UPPOINTS               = $0200;
{$EXTERNALSYM PDTT_UPPOINTS}
  PDTT_OEMDATA                = $0400;
{$EXTERNALSYM PDTT_OEMDATA}
  PDTT_COLLINEAR              = $0800;
{$EXTERNALSYM PDTT_COLLINEAR}
  PDTT_COLINEAR               = $0800;  { alt sp alias }
{$EXTERNALSYM PDTT_COLINEAR}
  PDTT_DECOMPRESS             = $4000;  { decompress the data }
{$EXTERNALSYM PDTT_DECOMPRESS}
  PDTT_COMPRESS               = $8000;
{$EXTERNALSYM PDTT_COMPRESS}
  PDTT_ALL                    = $0F00;  { PENINFO|UPPOINTS|OEMDATA|COLLINEAR }
{$EXTERNALSYM PDTT_ALL}

  PHW_NONE                    = $0000;  { no OEMdata }
{$EXTERNALSYM PHW_NONE}
  PHW_PRESSURE                = $0001;  { report pressure in OEMdata if avail }
{$EXTERNALSYM PHW_PRESSURE}
  PHW_HEIGHT                  = $0002;  { ditto height }
{$EXTERNALSYM PHW_HEIGHT}
  PHW_ANGLEXY                 = $0004;  { ditto xy angle }
{$EXTERNALSYM PHW_ANGLEXY}
  PHW_ANGLEZ                  = $0008;  { ditto z angle }
{$EXTERNALSYM PHW_ANGLEZ}
  PHW_BARRELROTATION          = $0010;  { ditto barrel rotation }
{$EXTERNALSYM PHW_BARRELROTATION}
  PHW_OEMSPECIFIC             = $0020;  { ditto OEM-specific value }
{$EXTERNALSYM PHW_OEMSPECIFIC}
  PHW_PDK                     = $0040;  { report per-point PDK_xx in OEM data }
{$EXTERNALSYM PHW_PDK}
  PHW_ALL                     = $007F;  { report everything }
{$EXTERNALSYM PHW_ALL}

{ compact pen data trim options: matches PDTT_values (see above) }
  PDTS_COMPRESS2NDDERIV       = $0010;  { compress using 2nd deriv }
{$EXTERNALSYM PDTS_COMPRESS2NDDERIV}
  PDTS_COMPRESSMETHOD         = $00F0;  { sum of compress method flags }
{$EXTERNALSYM PDTS_COMPRESSMETHOD}
  PDTS_NOPENINFO              = $0100;  { removes PENINFO struct from header }
{$EXTERNALSYM PDTS_NOPENINFO}
  PDTS_NOUPPOINTS             = $0200;  { remove up pts }
{$EXTERNALSYM PDTS_NOUPPOINTS}
  PDTS_NOOEMDATA              = $0400;  { remove OEM data }
{$EXTERNALSYM PDTS_NOOEMDATA}
  PDTS_NOCOLLINEAR            = $0800;  { remove successive identical pts }
{$EXTERNALSYM PDTS_NOCOLLINEAR}
  PDTS_NOCOLINEAR             = $0800;  { alt sp alias }
{$EXTERNALSYM PDTS_NOCOLINEAR}
  PDTS_NOTICK                 = $1000;  { remove timing info (2.0) }
{$EXTERNALSYM PDTS_NOTICK}
  PDTS_NOUSER                 = $2000;  { remove user info (2.0) }
{$EXTERNALSYM PDTS_NOUSER}
  PDTS_NOEMPTYSTROKES         = $4000;  { remove empty strokes (2.0) }
{$EXTERNALSYM PDTS_NOEMPTYSTROKES}
  PDTS_COMPRESSED             = $8000;  { perform lossless compression }
{$EXTERNALSYM PDTS_COMPRESSED}

{ SetStrokeAttributes options (SSA_xx): }
  SSA_PENTIP                  = 1;      { set stroke tip (color, width, nib) }
{$EXTERNALSYM SSA_PENTIP}
  SSA_PENTIPCLASS             = 2;      { set stroke's class pentip }
{$EXTERNALSYM SSA_PENTIPCLASS}
  SSA_USER                    = 3;      { set stroke user value }
{$EXTERNALSYM SSA_USER}
  SSA_USERCLASS               = 4;      { set stroke's class user value }
{$EXTERNALSYM SSA_USERCLASS}
  SSA_TIME                    = 5;      { set time of stroke }
{$EXTERNALSYM SSA_TIME}
  SSA_SELECT                  = 6;      { set selection status of stroke }
{$EXTERNALSYM SSA_SELECT}
  SSA_DOWN                    = 7;      { set up/down state of stroke }
{$EXTERNALSYM SSA_DOWN}

{ SetStrokeTableAttributes options (SSA_xx): }
  SSA_PENTIPTABLE             = 8;      { set table-indexed pentip }
{$EXTERNALSYM SSA_PENTIPTABLE}
  SSA_USERTABLE               = 9;      { set table-indexed user value }
{$EXTERNALSYM SSA_USERTABLE}

{ PenTip flag bits: }
  TIP_ERASECOLOR              = 1;      { erase specific color pentip.rgb }
{$EXTERNALSYM TIP_ERASECOLOR}

{ TrimPenData() API options: }
  TPD_RECALCSIZE              = $0000;  { no trim, used for resize calc }
{$EXTERNALSYM TPD_RECALCSIZE}
  TPD_USER                    = $0080;  { per-stroke user info }
{$EXTERNALSYM TPD_USER}
  TPD_TIME                    = $0100;  { per-stroke timing info }
{$EXTERNALSYM TPD_TIME}
  TPD_UPPOINTS                = $0200;  { x-y data up points }
{$EXTERNALSYM TPD_UPPOINTS}
  TPD_COLLINEAR               = $0400;  { colinear and coincident points }
{$EXTERNALSYM TPD_COLLINEAR}
  TPD_COLINEAR                = $0400;  { alt sp alias }
{$EXTERNALSYM TPD_COLINEAR}
  TPD_PENINFO                 = $0800;  { PenInfo struct and all OEM }
{$EXTERNALSYM TPD_PENINFO}
  TPD_PHW                     = $1000;  { OEM & pdk except stroke tick or user }
{$EXTERNALSYM TPD_PHW}
  TPD_OEMDATA                 = $1000;  { ditto }
{$EXTERNALSYM TPD_OEMDATA}
  TPD_EMPTYSTROKES            = $2000;  { strokes with zero points }
{$EXTERNALSYM TPD_EMPTYSTROKES}
  TPD_EVERYTHING              = $3FFF;  { everything (incl PHW_xx) except down pts }
{$EXTERNALSYM TPD_EVERYTHING}

{ Dictionary: }

  cbDictPathMax               = 255;
{$EXTERNALSYM cbDictPathMax}
  DIRQ_QUERY                  = 1;
{$EXTERNALSYM DIRQ_QUERY}
  DIRQ_DESCRIPTION            = 2;
{$EXTERNALSYM DIRQ_DESCRIPTION}
  DIRQ_CONFIGURE              = 3;
{$EXTERNALSYM DIRQ_CONFIGURE}
  DIRQ_OPEN                   = 4;
{$EXTERNALSYM DIRQ_OPEN}
  DIRQ_CLOSE                  = 5;
{$EXTERNALSYM DIRQ_CLOSE}
  DIRQ_SETWORDLISTS           = 6;
{$EXTERNALSYM DIRQ_SETWORDLISTS}
  DIRQ_STRING                 = 7;
{$EXTERNALSYM DIRQ_STRING}
  DIRQ_SUGGEST                = 8;
{$EXTERNALSYM DIRQ_SUGGEST}
  DIRQ_ADD                    = 9;
{$EXTERNALSYM DIRQ_ADD}
  DIRQ_DELETE                 = 10;
{$EXTERNALSYM DIRQ_DELETE}
  DIRQ_FLUSH                  = 11;
{$EXTERNALSYM DIRQ_FLUSH}
  DIRQ_RCCHANGE               = 12;
{$EXTERNALSYM DIRQ_RCCHANGE}
  DIRQ_SYMBOLGRAPH            = 13;
{$EXTERNALSYM DIRQ_SYMBOLGRAPH}
  DIRQ_INIT                   = 14;
{$EXTERNALSYM DIRQ_INIT}
  DIRQ_CLEANUP                = 15;
{$EXTERNALSYM DIRQ_CLEANUP}
  DIRQ_COPYRIGHT              = 16;
{$EXTERNALSYM DIRQ_COPYRIGHT}
  DIRQ_USER                   = 4096;
{$EXTERNALSYM DIRQ_USER}

{ Pen driver: }

  BITPENUP                    = $8000;
{$EXTERNALSYM BITPENUP}

{ Pen Driver messages: }
  DRV_SetPenDriverEntryPoints         = DRV_RESERVED+1;
{$EXTERNALSYM DRV_SetPenDriverEntryPoints}
  DRV_SetEntryPoints                  = DRV_RESERVED+1; { alias }
{$EXTERNALSYM DRV_SetEntryPoints}
  DRV_RemovePenDriverEntryPoints      = DRV_RESERVED+2;
{$EXTERNALSYM DRV_RemovePenDriverEntryPoints}
  DRV_RemoveEntryPoints               = DRV_RESERVED+2; { alias }
{$EXTERNALSYM DRV_RemoveEntryPoints}
  DRV_SetPenSamplingRate              = DRV_RESERVED+3;
{$EXTERNALSYM DRV_SetPenSamplingRate}
  DRV_SetPenSamplingDist              = DRV_RESERVED+4;
{$EXTERNALSYM DRV_SetPenSamplingDist}
  DRV_GetName                         = DRV_RESERVED+5;
{$EXTERNALSYM DRV_GetName}
  DRV_GetVersion                      = DRV_RESERVED+6;
{$EXTERNALSYM DRV_GetVersion}
  DRV_GetPenInfo                      = DRV_RESERVED+7;
{$EXTERNALSYM DRV_GetPenInfo}
  DRV_PenPlayStart                    = DRV_RESERVED+8;
{$EXTERNALSYM DRV_PenPlayStart}
  DRV_PenPlayBack                     = DRV_RESERVED+9;
{$EXTERNALSYM DRV_PenPlayBack}
  DRV_PenPlayStop                     = DRV_RESERVED+10;
{$EXTERNALSYM DRV_PenPlayStop}
  DRV_GetCalibration                  = DRV_RESERVED+11;
{$EXTERNALSYM DRV_GetCalibration}
  DRV_SetCalibration                  = DRV_RESERVED+12;
{$EXTERNALSYM DRV_SetCalibration}
  DRV_Reserved1                       = DRV_RESERVED+13;
{$EXTERNALSYM DRV_Reserved1}
  DRV_Reserved2                       = DRV_RESERVED+14;
{$EXTERNALSYM DRV_Reserved2}
  DRV_Query                           = DRV_RESERVED+15;
{$EXTERNALSYM DRV_Query}
  DRV_GetPenSamplingRate              = DRV_RESERVED+16;
{$EXTERNALSYM DRV_GetPenSamplingRate}
  DRV_Calibrate                       = DRV_RESERVED+17;
{$EXTERNALSYM DRV_Calibrate}

{ Pen Driver Playback constants: }
  PLAY_VERSION_10_DATA     = 0;
{$EXTERNALSYM PLAY_VERSION_10_DATA}
  PLAY_VERSION_20_DATA     = 1;
{$EXTERNALSYM PLAY_VERSION_20_DATA}

{ Pen Driver return values: }
  DRV_FAILURE                 = $00000000;
{$EXTERNALSYM DRV_FAILURE}
  DRV_SUCCESS                 = $00000001;
{$EXTERNALSYM DRV_SUCCESS}
  DRV_BADPARAM1               = $FFFFFFFF;
{$EXTERNALSYM DRV_BADPARAM1}
  DRV_BADPARAM2               = $FFFFFFFE;
{$EXTERNALSYM DRV_BADPARAM2}
  DRV_BADSTRUCT               = $FFFFFFFD;
{$EXTERNALSYM DRV_BADSTRUCT}

{ Pen Driver register messages flags: }
  PENREG_DEFAULT              = $00000002;
{$EXTERNALSYM PENREG_DEFAULT}
  PENREG_WILLHANDLEMOUSE      = $00000001;
{$EXTERNALSYM PENREG_WILLHANDLEMOUSE}

  MAXOEMDATAWORDS             = 6;            { rgwOemData[MAXOEMDATAWORDS] }
{$EXTERNALSYM MAXOEMDATAWORDS}

  RC_LDEFAULTFLAGS            = $80000000;
{$EXTERNALSYM RC_LDEFAULTFLAGS}

{ Pen Collection Mode termination conditions: }
{ (note update doc for PCMINFO struct if change these) }
  PCM_PENUP                   = $00000001;    { stop on penup }
{$EXTERNALSYM PCM_PENUP}
  PCM_RANGE                   = $00000002;    { stop on leaving range }
{$EXTERNALSYM PCM_RANGE}
  PCM_INVERT                  = $00000020;    { stop on tap of opposite end }
{$EXTERNALSYM PCM_INVERT}
  PCM_RECTEXCLUDE             = $00002000;    { click in exclude rect }
{$EXTERNALSYM PCM_RECTEXCLUDE}
  PCM_RECTBOUND               = $00004000;    { click outside bounds rect }
{$EXTERNALSYM PCM_RECTBOUND}
  PCM_TIMEOUT                 = $00008000;    { no activity for timeout ms }
{$EXTERNALSYM PCM_TIMEOUT}
{ new for 2.0: }
  PCM_RGNBOUND                = $00010000;    { click outside bounding region }
{$EXTERNALSYM PCM_RGNBOUND}
  PCM_RGNEXCLUDE              = $00020000;    { click in exclude region }
{$EXTERNALSYM PCM_RGNEXCLUDE}
  PCM_DOPOLLING               = $00040000;    { polling mode }
{$EXTERNALSYM PCM_DOPOLLING}
  PCM_TAPNHOLD                = $00080000;    { check for Tap And Hold }
{$EXTERNALSYM PCM_TAPNHOLD}
  PCM_ADDDEFAULTS             = RC_LDEFAULTFLAGS; { $80000000 }
{$EXTERNALSYM PCM_ADDDEFAULTS}

{ Pen Device Capabilities: }
  PDC_INTEGRATED              = $00000001;    { display=digitizer }
{$EXTERNALSYM PDC_INTEGRATED}
  PDC_PROXIMITY               = $00000002;    { detect non-contacting pen }
{$EXTERNALSYM PDC_PROXIMITY}
  PDC_RANGE                   = $00000004;    { event on out-of-range }
{$EXTERNALSYM PDC_RANGE}
  PDC_INVERT                  = $00000008;    { pen opposite end detect }
{$EXTERNALSYM PDC_INVERT}
  PDC_RELATIVE                = $00000010;    { pen driver coords }
{$EXTERNALSYM PDC_RELATIVE}
  PDC_BARREL1                 = $00000020;    { barrel button 1 present }
{$EXTERNALSYM PDC_BARREL1}
  PDC_BARREL2                 = $00000040;    { ditto 2 }
{$EXTERNALSYM PDC_BARREL2}
  PDC_BARREL3                 = $00000080;    { ditto 3 }
{$EXTERNALSYM PDC_BARREL3}

{ Pen Driver Kit states: }
  PDK_NULL                    = $0000;  { default to no flags set }
{$EXTERNALSYM PDK_NULL}
  PDK_UP                      = $0000;  { PDK_NULL alias }
{$EXTERNALSYM PDK_UP}
  PDK_DOWN                    = $0001;  { pentip switch ON due to contact }
{$EXTERNALSYM PDK_DOWN}
  PDK_BARREL1                 = $0002;  { barrel1 switch depressed }
{$EXTERNALSYM PDK_BARREL1}
  PDK_BARREL2                 = $0004;  { ditto 2 }
{$EXTERNALSYM PDK_BARREL2}
  PDK_BARREL3                 = $0008;  { ditto 3 }
{$EXTERNALSYM PDK_BARREL3}
  PDK_SWITCHES                = $000F;  { sum of down + barrels 1,2,3 }
{$EXTERNALSYM PDK_SWITCHES}
  PDK_UNUSED10                = $0020;
{$EXTERNALSYM PDK_UNUSED10}
  PDK_UNUSED20                = $0040;
{$EXTERNALSYM PDK_UNUSED20}
  PDK_INVERTED                = $0080;  { other end of pen used as tip }
{$EXTERNALSYM PDK_INVERTED}
  PDK_PENIDMASK               = $0F00;  { bits 8..11 physical pen id (0..15) }
{$EXTERNALSYM PDK_PENIDMASK}
  PDK_UNUSED1000              = $1000;
{$EXTERNALSYM PDK_UNUSED1000}
  PDK_INKSTOPPED              = $2000;  { Inking stopped }
{$EXTERNALSYM PDK_INKSTOPPED}
  PDK_OUTOFRANGE              = $4000;  { pen left range (OEM data invalid) }
{$EXTERNALSYM PDK_OUTOFRANGE}
  PDK_DRIVER                  = $8000;  { pen (not mouse) event }
{$EXTERNALSYM PDK_DRIVER}
  PDK_TIPMASK                 = $0001;  { mask for testing PDK_DOWN }
{$EXTERNALSYM PDK_TIPMASK}

{ OEM-specific values for Pen Driver: }
  PDT_NULL                    = 0;
{$EXTERNALSYM PDT_NULL}
  PDT_PRESSURE                = 1;      { pressure supported }
{$EXTERNALSYM PDT_PRESSURE}
  PDT_HEIGHT                  = 2;      { height above tablet }
{$EXTERNALSYM PDT_HEIGHT}
  PDT_ANGLEXY                 = 3;      { xy (horiz) angle supported }
{$EXTERNALSYM PDT_ANGLEXY}
  PDT_ANGLEZ                  = 4;      { z (vert) angle supported }
{$EXTERNALSYM PDT_ANGLEZ}
  PDT_BARRELROTATION          = 5;      { barrel is rotated }
{$EXTERNALSYM PDT_BARRELROTATION}
  PDT_OEMSPECIFIC             = 16;     { max }
{$EXTERNALSYM PDT_OEMSPECIFIC}

{ Denotes the ID of the current packet }
  PID_CURRENT                 = -1;
{$EXTERNALSYM PID_CURRENT}

{ Handwriting Recognizer: }

{ GetResultsHRC options: }
  GRH_ALL                     = 0;      { get all results }
{$EXTERNALSYM GRH_ALL}
  GRH_GESTURE                 = 1;      { get only gesture results }
{$EXTERNALSYM GRH_GESTURE}
  GRH_NONGESTURE              = 2;      { get all but gesture results }
{$EXTERNALSYM GRH_NONGESTURE}

{ Gesture sets for EnableGestureSetHRC (bit flags): }
  GST_SEL                     = $00000001;    { sel & lasso }
{$EXTERNALSYM GST_SEL}
  GST_CLIP                    = $00000002;    { cut copy paste }
{$EXTERNALSYM GST_CLIP}
  GST_WHITE                   = $00000004;    { sp tab ret }
{$EXTERNALSYM GST_WHITE}
  GST_KKCONVERT               = $00000008;    { kkconvert }
{$EXTERNALSYM GST_KKCONVERT}
  GST_EDIT                    = $00000010;    { insert correct undo clear }
{$EXTERNALSYM GST_EDIT}
  GST_SYS                     = $00000017;    { all of the above }
{$EXTERNALSYM GST_SYS}
  GST_CIRCLELO                = $00000100;    { lowercase circle }
{$EXTERNALSYM GST_CIRCLELO}
  GST_CIRCLEUP                = $00000200;    { uppercase circle }
{$EXTERNALSYM GST_CIRCLEUP}
  GST_CIRCLE                  = $00000300;    { all circle }
{$EXTERNALSYM GST_CIRCLE}
  GST_ALL                     = $00000317;    { all of the above }
{$EXTERNALSYM GST_ALL}

{ General HRC API return values (HRCR_xx): }
  HRCR_NORESULTS              = 4;      { No possible results  to be found }
{$EXTERNALSYM HRCR_NORESULTS}
  HRCR_COMPLETE               = 3;      { finished recognition }
{$EXTERNALSYM HRCR_COMPLETE}
  HRCR_GESTURE                = 2;      { recognized gesture }
{$EXTERNALSYM HRCR_GESTURE}
  HRCR_OK                     = 1;      { success }
{$EXTERNALSYM HRCR_OK}
  HRCR_INCOMPLETE             = 0;      { recognizer is processing input }
{$EXTERNALSYM HRCR_INCOMPLETE}
  HRCR_ERROR                  = -1;     { invalid param or unspecified error }
{$EXTERNALSYM HRCR_ERROR}
  HRCR_MEMERR                 = -2;     { memory error }
{$EXTERNALSYM HRCR_MEMERR}
  HRCR_INVALIDGUIDE           = -3;     { invalid GUIDE struct }
{$EXTERNALSYM HRCR_INVALIDGUIDE}
  HRCR_INVALIDPNDT            = -4;     { invalid pendata }
{$EXTERNALSYM HRCR_INVALIDPNDT}
  HRCR_UNSUPPORTED            = -5;     { recognizer does not support feature }
{$EXTERNALSYM HRCR_UNSUPPORTED}
  HRCR_CONFLICT               = -6;     { training conflict }
{$EXTERNALSYM HRCR_CONFLICT}
  HRCR_HOOKED                 = -8;     { hookasaurus ate the result }
{$EXTERNALSYM HRCR_HOOKED}

{ system wordlist for AddWordsHWL: }
  HWL_SYSTEM                  = (1);       { magic value means system wordlist }
{$EXTERNALSYM HWL_SYSTEM}

{ inkset returns: }
  ISR_ERROR                   = -1;     { Memory or other error }
{$EXTERNALSYM ISR_ERROR}
  ISR_BADINKSET               = -2;     { bad source inkset }
{$EXTERNALSYM ISR_BADINKSET}
  ISR_BADINDEX                = -3;     { bad inkset index }
{$EXTERNALSYM ISR_BADINDEX}
  MAXHOTSPOT                  = 8;      { max number of hotspots possible }
{$EXTERNALSYM MAXHOTSPOT}

{ ProcessHRC time constants: }
  PH_MAX                      = $FFFFFFFF;    { recognize rest of ink }
{$EXTERNALSYM PH_MAX}
  PH_DEFAULT                  = $FFFFFFFE;    { reasonable time }
{$EXTERNALSYM PH_DEFAULT}
  PH_MIN                      = $FFFFFFFD;    { minimum time }
{$EXTERNALSYM PH_MIN}

{ ResultsHookHRC options: }
  RHH_STD                     = 0;      { GetResultsHRC }
{$EXTERNALSYM RHH_STD}
  RHH_BOX                     = 1;      { GetBoxResultsHRC }
{$EXTERNALSYM RHH_BOX}

{ SetWordlistCoercionHRC options: }
  SCH_NONE                    = 0;      { turn off coercion }
{$EXTERNALSYM SCH_NONE}
  SCH_ADVISE                  = 1;      { macro is hint only }
{$EXTERNALSYM SCH_ADVISE}
  SCH_FORCE                   = 2;      { some result is forced from macro }
{$EXTERNALSYM SCH_FORCE}

{ Symbol Context Insert Modes }
  SCIM_INSERT                 = 0;      { insert }
{$EXTERNALSYM SCIM_INSERT}
  SCIM_OVERWRITE              = 1;      { overwrite }
{$EXTERNALSYM SCIM_OVERWRITE}

{ SetResultsHookHREC options: }
  SRH_HOOKALL                 = 1;      { hook all recognizers }
{$EXTERNALSYM SRH_HOOKALL}

{ SetInternationalHRC options: }
  SSH_RD                      = 1;      { to right and down (English) }
{$EXTERNALSYM SSH_RD}
  SSH_RU                      = 2;      { to right and up }
{$EXTERNALSYM SSH_RU}
  SSH_LD                      = 3;      { to left and down (Hebrew) }
{$EXTERNALSYM SSH_LD}
  SSH_LU                      = 4;      { to left and up }
{$EXTERNALSYM SSH_LU}
  SSH_DL                      = 5;      { down and to the left (Chinese) }
{$EXTERNALSYM SSH_DL}
  SSH_DR                      = 6;      { down and to the right (Chinese) }
{$EXTERNALSYM SSH_DR}
  SSH_UL                      = 7;      { up and to the left }
{$EXTERNALSYM SSH_UL}
  SSH_UR                      = 8;      { up and to the right }
{$EXTERNALSYM SSH_UR}

  SIH_ALLANSICHAR             = 1;      { use all ANSI }
{$EXTERNALSYM SIH_ALLANSICHAR}

{ TrainHREC options: }
  TH_QUERY                    = 0;      { query the user if conflict }
{$EXTERNALSYM TH_QUERY}
  TH_FORCE                    = 1;      { ditto no query }
{$EXTERNALSYM TH_FORCE}
  TH_SUGGEST                  = 2;      { abandon training if conflict }
{$EXTERNALSYM TH_SUGGEST}

{ Return values for WCR_TRAIN Function }
  TRAIN_NONE                  = $0000;
{$EXTERNALSYM TRAIN_NONE}
  TRAIN_DEFAULT               = $0001;
{$EXTERNALSYM TRAIN_DEFAULT}
  TRAIN_CUSTOM                = $0002;
{$EXTERNALSYM TRAIN_CUSTOM}
  TRAIN_BOTH                  = TRAIN_DEFAULT or TRAIN_CUSTOM;
{$EXTERNALSYM TRAIN_BOTH}

{ Control values for TRAINSAVE }
  TRAIN_SAVE                  = 0;      { save changes that have been made }
{$EXTERNALSYM TRAIN_SAVE}
  TRAIN_REVERT                = 1;      { discard changes that have been made }
{$EXTERNALSYM TRAIN_REVERT}
  TRAIN_RESET                 = 2;      { use factory settings }
{$EXTERNALSYM TRAIN_RESET}

{ ConfigRecognizer and ConfigHREC options: }
  WCR_RECOGNAME               = 0;      { ConfigRecognizer 1.0 }
{$EXTERNALSYM WCR_RECOGNAME}
  WCR_QUERY                   = 1;
{$EXTERNALSYM WCR_QUERY}
  WCR_CONFIGDIALOG            = 2;
{$EXTERNALSYM WCR_CONFIGDIALOG}
  WCR_DEFAULT                 = 3;
{$EXTERNALSYM WCR_DEFAULT}
  WCR_RCCHANGE                = 4;
{$EXTERNALSYM WCR_RCCHANGE}
  WCR_VERSION                 = 5;
{$EXTERNALSYM WCR_VERSION}
  WCR_TRAIN                   = 6;
{$EXTERNALSYM WCR_TRAIN}
  WCR_TRAINSAVE               = 7;
{$EXTERNALSYM WCR_TRAINSAVE}
  WCR_TRAINMAX                = 8;
{$EXTERNALSYM WCR_TRAINMAX}
  WCR_TRAINDIRTY              = 9;
{$EXTERNALSYM WCR_TRAINDIRTY}
  WCR_TRAINCUSTOM             = 10;
{$EXTERNALSYM WCR_TRAINCUSTOM}
  WCR_QUERYLANGUAGE           = 11;
{$EXTERNALSYM WCR_QUERYLANGUAGE}
  WCR_USERCHANGE              = 12;
{$EXTERNALSYM WCR_USERCHANGE}

{ ConfigHREC options: }
  WCR_PWVERSION               = 13;     { ver of PenWin recognizer supports }
{$EXTERNALSYM WCR_PWVERSION}
  WCR_GETALCPRIORITY          = 14;     { get recognizer's ALC priority }
{$EXTERNALSYM WCR_GETALCPRIORITY}
  WCR_SETALCPRIORITY          = 15;     { set recognizer's ALC priority }
{$EXTERNALSYM WCR_SETALCPRIORITY}
  WCR_GETANSISTATE            = 16;     { get ALLANSICHAR state }
{$EXTERNALSYM WCR_GETANSISTATE}
  WCR_SETANSISTATE            = 17;     { set ALLANSICHAR if T }
{$EXTERNALSYM WCR_SETANSISTATE}
  WCR_GETHAND                 = 18;     { get writing hand }
{$EXTERNALSYM WCR_GETHAND}
  WCR_SETHAND                 = 19;     { set writing hand }
{$EXTERNALSYM WCR_SETHAND}
  WCR_GETDIRECTION            = 20;     { get writing direction }
{$EXTERNALSYM WCR_GETDIRECTION}
  WCR_SETDIRECTION            = 21;     { set writing direction }
{$EXTERNALSYM WCR_SETDIRECTION}
  WCR_INITRECOGNIZER          = 22;     { init recognizer and set user name }
{$EXTERNALSYM WCR_INITRECOGNIZER}
  WCR_CLOSERECOGNIZER         = 23;     { close recognizer }
{$EXTERNALSYM WCR_CLOSERECOGNIZER}
  WCR_PRIVATE                 = 1024;
{$EXTERNALSYM WCR_PRIVATE}

{ sub-functions of WCR_USERCHANGE }
  CRUC_NOTIFY                 = 0;      { user name change }
{$EXTERNALSYM CRUC_NOTIFY}
  CRUC_REMOVE                 = 1;      { user name deleted }
{$EXTERNALSYM CRUC_REMOVE}

{ Word List Types: }
  WLT_STRING                  = 0;      { one string }
{$EXTERNALSYM WLT_STRING}
  WLT_STRINGTABLE             = 1;      { array of strings }
{$EXTERNALSYM WLT_STRINGTABLE}
  WLT_EMPTY                   = 2;      { empty wordlist }
{$EXTERNALSYM WLT_EMPTY}
  WLT_WORDLIST                = 3;      { handle to a wordlist }
{$EXTERNALSYM WLT_WORDLIST}


{ IEdit Background Options }

  IEB_DEFAULT                 = 0;      { default (use COLOR_WINDOW) }
{$EXTERNALSYM IEB_DEFAULT}
  IEB_BRUSH                   = 1;      { paint background with brush }
{$EXTERNALSYM IEB_BRUSH}
  IEB_BIT_UL                  = 2;      { bitmap, upper-left aligned }
{$EXTERNALSYM IEB_BIT_UL}
  IEB_BIT_CENTER              = 3;      { bitmap, centered in control }
{$EXTERNALSYM IEB_BIT_CENTER}
  IEB_BIT_TILE                = 4;      { bitmap, tiled repeatedly in ctl }
{$EXTERNALSYM IEB_BIT_TILE}
  IEB_BIT_STRETCH             = 5;      { bitmap, stretched to fit ctl }
{$EXTERNALSYM IEB_BIT_STRETCH}
  IEB_OWNERDRAW               = 6;      { parent window will draw background }
{$EXTERNALSYM IEB_OWNERDRAW}

{ IEdit Drawing Options }
  IEDO_NONE                   = $0000;  { no drawing }
{$EXTERNALSYM IEDO_NONE}
  IEDO_FAST                   = $0001;  { ink drawn as fast as possible (def) }
{$EXTERNALSYM IEDO_FAST}
  IEDO_SAVEUPSTROKES          = $0002;  { save upstrokes }
{$EXTERNALSYM IEDO_SAVEUPSTROKES}
  IEDO_RESERVED               = $FFFC;  { reserved bits }
{$EXTERNALSYM IEDO_RESERVED}

{ IEdit Input Options }
  IEI_MOVE                    = $0001;  { move ink into ctl }
{$EXTERNALSYM IEI_MOVE}
  IEI_RESIZE                  = $0002;  { resize ink to fit within ctl }
{$EXTERNALSYM IEI_RESIZE}
  IEI_CROP                    = $0004;  { discard ink outside of ctl }
{$EXTERNALSYM IEI_CROP}
  IEI_DISCARD                 = $0008;  { discard all ink if any outside ctl }
{$EXTERNALSYM IEI_DISCARD}
  IEI_RESERVED                = $FFF0;  { reserved }
{$EXTERNALSYM IEI_RESERVED}

{ IEdit IE_GETINK options }
  IEGI_ALL                    = $0000;  { get all ink from control }
{$EXTERNALSYM IEGI_ALL}
  IEGI_SELECTION              = $0001;  { get selected ink from control }
{$EXTERNALSYM IEGI_SELECTION}

{ IEdit IE_SETMODE/IE_GETMODE (mode) options }
  IEMODE_READY                = 0;      { default inking, moving, sizing mode }
{$EXTERNALSYM IEMODE_READY}
  IEMODE_ERASE                = 1;      { erasing Mode }
{$EXTERNALSYM IEMODE_ERASE}
  IEMODE_LASSO                = 2;      { lasso selection mode }
{$EXTERNALSYM IEMODE_LASSO}

{ IEdit    Notification Bits }
  IEN_NULL                    = $0000;  { null notification }
{$EXTERNALSYM IEN_NULL}
  IEN_PDEVENT                 = $0001;  { notify about pointing device events }
{$EXTERNALSYM IEN_PDEVENT}
  IEN_PAINT                   = $0002;  { send painting-related notifications }
{$EXTERNALSYM IEN_PAINT}
  IEN_FOCUS                   = $0004;  { send focus-related notifications }
{$EXTERNALSYM IEN_FOCUS}
  IEN_SCROLL                  = $0008;  { send scrolling notifications }
{$EXTERNALSYM IEN_SCROLL}
  IEN_EDIT                    = $0010;  { send editing/change notifications }
{$EXTERNALSYM IEN_EDIT}
  IEN_PROPERTIES              = $0020;  { send properties dialog notification }
{$EXTERNALSYM IEN_PROPERTIES}
  IEN_RESERVED                = $FF80;  { reserved }
{$EXTERNALSYM IEN_RESERVED}

{ IEdit Return Values }
  IER_OK                      = 0;      { success }
{$EXTERNALSYM IER_OK}
  IER_NO                      = 0;      { ctl cannot do request }
{$EXTERNALSYM IER_NO}
  IER_YES                     = 1;      { ctl can do request }
{$EXTERNALSYM IER_YES}
  IER_ERROR                   = -1;     { unspecified error; operation failed }
{$EXTERNALSYM IER_ERROR}
  IER_PARAMERR                = -2;     { bogus lParam value, bad handle, etc }
{$EXTERNALSYM IER_PARAMERR}
  IER_OWNERDRAW               = -3;     { can't set drawopts in ownerdraw ctl }
{$EXTERNALSYM IER_OWNERDRAW}
  IER_SECURITY                = -4;     { security protection disallows action }
{$EXTERNALSYM IER_SECURITY}
  IER_SELECTION               = -5;     { nothing selected in control }
{$EXTERNALSYM IER_SELECTION}
  IER_SCALE                   = -6;     { merge:  incompatible scaling factors }
{$EXTERNALSYM IER_SCALE}
  IER_MEMERR                  = -7;     { memory error }
{$EXTERNALSYM IER_MEMERR}
  IER_NOCOMMAND               = -8;     { tried IE_GETCOMMAND w/no command }
{$EXTERNALSYM IER_NOCOMMAND}
  IER_NOGESTURE               = -9;     { tried IE_GETGESTURE w/no gesture }
{$EXTERNALSYM IER_NOGESTURE}
  IER_NOPDEVENT               = -10;    { tried IE_GETPDEVENT but no event }
{$EXTERNALSYM IER_NOPDEVENT}
  IER_NOTINPAINT              = -11;    { tried IE_GETPAINTSTRUCT but no paint }
{$EXTERNALSYM IER_NOTINPAINT}
  IER_PENDATA                 = -12;    { can't do request with NULL hpd in ctl }
{$EXTERNALSYM IER_PENDATA}

{ IEdit Recognition Options }
  IEREC_NONE                  = $0000;  { No recognition }
{$EXTERNALSYM IEREC_NONE}
  IEREC_GESTURE               = $0001;  { Gesture recognition }
{$EXTERNALSYM IEREC_GESTURE}
{$DEFINE IEREC_ALL}
  IEREC_RESERVED              = $FFFE;  { Reserved }
{$EXTERNALSYM IEREC_RESERVED}

{ IEdit Security Options }
  IESEC_NOCOPY                = $0001;  { copying disallowed }
{$EXTERNALSYM IESEC_NOCOPY}
  IESEC_NOCUT                 = $0002;  { cutting disallowed }
{$EXTERNALSYM IESEC_NOCUT}
  IESEC_NOPASTE               = $0004;  { pasting disallowed }
{$EXTERNALSYM IESEC_NOPASTE}
  IESEC_NOUNDO                = $0008;  { undoing disallowed }
{$EXTERNALSYM IESEC_NOUNDO}
  IESEC_NOINK                 = $0010;  { inking  disallowed }
{$EXTERNALSYM IESEC_NOINK}
  IESEC_NOERASE               = $0020;  { erasing disallowed }
{$EXTERNALSYM IESEC_NOERASE}
  IESEC_NOGET                 = $0040;  { IE_GETINK message verboten }
{$EXTERNALSYM IESEC_NOGET}
  IESEC_NOSET                 = $0080;  { IE_SETINK message verboten }
{$EXTERNALSYM IESEC_NOSET}
  IESEC_RESERVED              = $FF00;  { reserved }
{$EXTERNALSYM IESEC_RESERVED}

{ IEdit IE_SETFORMAT/IE_GETFORMAT options }
  IESF_ALL                    = $0001;  { set/get stk fmt of all ink }
{$EXTERNALSYM IESF_ALL}
  IESF_SELECTION              = $0002;  { set/get stk fmt of selected ink }
{$EXTERNALSYM IESF_SELECTION}
  IESF_STROKE                 = $0004;  { set/get stk fmt of specified stroke }
{$EXTERNALSYM IESF_STROKE}

  IESF_TIPCOLOR               = $0008;  { set color }
{$EXTERNALSYM IESF_TIPCOLOR}
  IESF_TIPWIDTH               = $0010;  { set width }
{$EXTERNALSYM IESF_TIPWIDTH}
  IESF_PENTIP                 = IESF_TIPCOLOR or IESF_TIPWIDTH;
{$EXTERNALSYM IESF_PENTIP}


{ IEdit IE_SETINK options }
  IESI_REPLACE                = $0000;  { replace ink in control }
{$EXTERNALSYM IESI_REPLACE}
  IESI_APPEND                 = $0001;  { append ink to existing control ink }
{$EXTERNALSYM IESI_APPEND}

{ Ink Edit Control (IEdit) definitions }
{ IEdit Notifications }
  IN_PDEVENT          = (IEN_PDEVENT shl 8) or 0; { pointing device event occurred }
{$EXTERNALSYM IN_PDEVENT}
  IN_ERASEBKGND       = (IEN_NULL shl 8) or 1; { control needs bkgnd erased }
{$EXTERNALSYM IN_ERASEBKGND}
  IN_PREPAINT         = (IEN_PAINT shl 8) or 2; { before control paints its ink }
{$EXTERNALSYM IN_PREPAINT}
  IN_PAINT            = (IEN_NULL shl 8) or 3; { control needs to be painted }
{$EXTERNALSYM IN_PAINT}
  IN_POSTPAINT        = (IEN_PAINT shl 8) or 4; { after control has painted }
{$EXTERNALSYM IN_POSTPAINT}
  IN_MODECHANGED      = (IEN_EDIT shl 8) or 5; { mode changed }
{$EXTERNALSYM IN_MODECHANGED}
  IN_CHANGE           = (IEN_EDIT shl 8) or 6; { contents changed & painted }
{$EXTERNALSYM IN_CHANGE}
  IN_UPDATE           = (IEN_EDIT shl 8) or 7; { contents changed & !painted }
{$EXTERNALSYM IN_UPDATE}
  IN_SETFOCUS         = (IEN_FOCUS shl 8) or 8; { IEdit is getting focus }
{$EXTERNALSYM IN_SETFOCUS}
  IN_KILLFOCUS        = (IEN_FOCUS shl 8) or 9; { IEdit is losing focus }
{$EXTERNALSYM IN_KILLFOCUS}
  IN_MEMERR           = (IEN_NULL shl 8) or 10; { memory error }
{$EXTERNALSYM IN_MEMERR}
  IN_HSCROLL          = (IEN_SCROLL shl 8) or 11; { horz scrolled, not painted }
{$EXTERNALSYM IN_HSCROLL}
  IN_VSCROLL          = (IEN_SCROLL shl 8) or 12; { vert scrolled, not painted }
{$EXTERNALSYM IN_VSCROLL}
  IN_GESTURE          = (IEN_EDIT shl 8) or 13; { user has gestured on control }
{$EXTERNALSYM IN_GESTURE}
  IN_COMMAND          = (IEN_EDIT shl 8) or 14; { command selected from menu }
{$EXTERNALSYM IN_COMMAND}
  IN_CLOSE            = (IEN_NULL shl 8) or 15; { I-Edit is being closed }
{$EXTERNALSYM IN_CLOSE}
  IN_PROPERTIES       = (IEN_PROPERTIES shl 8) or 16; { properties dialog }
{$EXTERNALSYM IN_PROPERTIES}

{ PenIn[k]put API constants }

{ Default Processing }
  LRET_DONE                   = 1;
{$EXTERNALSYM LRET_DONE}
  LRET_ABORT                  = -1;
{$EXTERNALSYM LRET_ABORT}
  LRET_HRC                    = -2;
{$EXTERNALSYM LRET_HRC}
  LRET_HPENDATA               = -3;
{$EXTERNALSYM LRET_HPENDATA}
  LRET_PRIVATE                = -4;
{$EXTERNALSYM LRET_PRIVATE}

{ Inkput: }
  PCMR_OK                     = 0;
{$EXTERNALSYM PCMR_OK}
  PCMR_ALREADYCOLLECTING      = -1;
{$EXTERNALSYM PCMR_ALREADYCOLLECTING}
  PCMR_INVALIDCOLLECTION      = -2;
{$EXTERNALSYM PCMR_INVALIDCOLLECTION}
  PCMR_EVENTLOCK              = -3;
{$EXTERNALSYM PCMR_EVENTLOCK}
  PCMR_INVALID_PACKETID       = -4;
{$EXTERNALSYM PCMR_INVALID_PACKETID}
  PCMR_TERMTIMEOUT            = -5;
{$EXTERNALSYM PCMR_TERMTIMEOUT}
  PCMR_TERMRANGE              = -6;
{$EXTERNALSYM PCMR_TERMRANGE}
  PCMR_TERMPENUP              = -7;
{$EXTERNALSYM PCMR_TERMPENUP}
  PCMR_TERMEX                 = -8;
{$EXTERNALSYM PCMR_TERMEX}
  PCMR_TERMBOUND              = -9;
{$EXTERNALSYM PCMR_TERMBOUND}
  PCMR_APPTERMINATED          = -10;
{$EXTERNALSYM PCMR_APPTERMINATED}
  PCMR_TAP                    = -11;    { alias PCMR_TAPNHOLD_LAST }
{$EXTERNALSYM PCMR_TAP}
  PCMR_SELECT                 = -12;    { ret because of tap & hold }
{$EXTERNALSYM PCMR_SELECT}
  PCMR_OVERFLOW               = -13;
{$EXTERNALSYM PCMR_OVERFLOW}
  PCMR_ERROR                  = -14;    { parameter or unspecified error }
{$EXTERNALSYM PCMR_ERROR}
  PCMR_DISPLAYERR             = -15;    { inking only }
{$EXTERNALSYM PCMR_DISPLAYERR}
  PCMR_TERMINVERT             = -16;    { termination due to tapping opposite end of pen }
{$EXTERNALSYM PCMR_TERMINVERT}

  PII_INKCLIPRECT             = $0001;
{$EXTERNALSYM PII_INKCLIPRECT}
  PII_INKSTOPRECT             = $0002;
{$EXTERNALSYM PII_INKSTOPRECT}
  PII_INKCLIPRGN              = $0004;
{$EXTERNALSYM PII_INKCLIPRGN}
  PII_INKSTOPRGN              = $0008;
{$EXTERNALSYM PII_INKSTOPRGN}
  PII_INKPENTIP               = $0010;
{$EXTERNALSYM PII_INKPENTIP}
  PII_SAVEBACKGROUND          = $0020;
{$EXTERNALSYM PII_SAVEBACKGROUND}
  PII_CLIPSTOP                = $0040;
{$EXTERNALSYM PII_CLIPSTOP}

  PIT_RGNBOUND                = $0001;
{$EXTERNALSYM PIT_RGNBOUND}
  PIT_RGNEXCLUDE              = $0002;
{$EXTERNALSYM PIT_RGNEXCLUDE}
  PIT_TIMEOUT                 = $0004;
{$EXTERNALSYM PIT_TIMEOUT}
  PIT_TAPNHOLD                = $0008;
{$EXTERNALSYM PIT_TAPNHOLD}


{ Misc RC Definitions: }

  CL_NULL                     = 0;
{$EXTERNALSYM CL_NULL}
  CL_MINIMUM                  = 1;      { minimum confidence level }
{$EXTERNALSYM CL_MINIMUM}
  CL_MAXIMUM                  = 100;    { max (require perfect recog) }
{$EXTERNALSYM CL_MAXIMUM}
  cwRcReservedMax             = 8;      { rc.rgwReserved[cwRcReservedMax] }
{$EXTERNALSYM cwRcReservedMax}
  ENUM_MINIMUM                = 1;
{$EXTERNALSYM ENUM_MINIMUM}
  ENUM_MAXIMUM                = 4096;
{$EXTERNALSYM ENUM_MAXIMUM}

  HKP_SETHOOK                 = 0;      { SetRecogHook() }
{$EXTERNALSYM HKP_SETHOOK}
  HKP_UNHOOK                  = $FFFF;
{$EXTERNALSYM HKP_UNHOOK}

  HWR_RESULTS                 = 0;
{$EXTERNALSYM HWR_RESULTS}
  HWR_APPWIDE                 = 1;
{$EXTERNALSYM HWR_APPWIDE}

  iSycNull                    = -1;
{$EXTERNALSYM iSycNull}
  LPDFNULL                    = 0;      { nil }
{$EXTERNALSYM LPDFNULL}
  MAXDICTIONARIES             = 16;     { rc.rglpdf[MAXDICTIONARIES] }
{$EXTERNALSYM MAXDICTIONARIES}
  wPntAll                     = $FFFF;
{$EXTERNALSYM wPntAll}
  cbRcLanguageMax             = 44;     { rc.lpLanguage[cbRcLanguageMax] }
{$EXTERNALSYM cbRcLanguageMax}
  cbRcUserMax                 = 32;     { rc.lpUser[cbRcUserMax] }
{$EXTERNALSYM cbRcUserMax}
  cbRcrgbfAlcMax              = 32;     { rc.rgbfAlc[cbRcrgbfAlcMax] }
{$EXTERNALSYM cbRcrgbfAlcMax}
  RC_WDEFAULT                 = $FFFF;
{$EXTERNALSYM RC_WDEFAULT}
  RC_LDEFAULT                 = $FFFFFFFF;
{$EXTERNALSYM RC_LDEFAULT}
  RC_WDEFAULTFLAGS            = $8000;
{$EXTERNALSYM RC_WDEFAULTFLAGS}
//  RC_LDEFAULTFLAGS            = $80000000; defined above

{ CorrectWriting() API constants: }
{ LOWORD values: }
  CWR_REPLACECR               = $0001;  { replace carriage ret (\r) with space }
{$EXTERNALSYM CWR_REPLACECR}
  CWR_STRIPCR                 = CWR_REPLACECR; { alias for backward compatibility }
{$EXTERNALSYM CWR_STRIPCR}
  CWR_STRIPLF                 = $0002;  { strip linefeed (\n) }
{$EXTERNALSYM CWR_STRIPLF}
  CWR_REPLACETAB              = $0004;  { replace tab with space (\t) }
{$EXTERNALSYM CWR_REPLACETAB}
  CWR_STRIPTAB                = CWR_REPLACETAB; { alias for backward compatibility }
{$EXTERNALSYM CWR_STRIPTAB}
  CWR_SINGLELINEEDIT          = CWR_REPLACECR or CWR_STRIPLF or CWR_REPLACETAB; { all of the above }
{$EXTERNALSYM CWR_SINGLELINEEDIT}
  CWR_INSERT                  = $0008;  { use "Insert Text" instead of "Edit Text" in the title }
{$EXTERNALSYM CWR_INSERT}
  CWR_TITLE                   = $0010;  { interpret dwParam as title string }
{$EXTERNALSYM CWR_TITLE}
  CWR_KKCONVERT               = $0020;  { JPN initiate IME }
{$EXTERNALSYM CWR_KKCONVERT}
  CWR_SIMPLE                  = $0040;  { simple dialog (lens) }
{$EXTERNALSYM CWR_SIMPLE}
  CWR_HEDIT                   = $0080;  { HEDIT CorrectWriting }
{$EXTERNALSYM CWR_HEDIT}
  CWR_KEYBOARD                = $0100;  { keyboard lens }
{$EXTERNALSYM CWR_KEYBOARD}
  CWR_BOXES                   = $0200;  { bedit lens }
{$EXTERNALSYM CWR_BOXES}

{ HIWORD values: keyboard types }
  CWRK_DEFAULT                = 0;      { default keyboard type }
{$EXTERNALSYM CWRK_DEFAULT}
  CWRK_BASIC                  = 1;      { basic keyboard }
{$EXTERNALSYM CWRK_BASIC}
  CWRK_FULL                   = 2;      { full keyboard }
{$EXTERNALSYM CWRK_FULL}
  CWRK_NUMPAD                 = 3;      { numeric keyboard }
{$EXTERNALSYM CWRK_NUMPAD}
  CWRK_TELPAD                 = 4;      { Telephone type keyboard }
{$EXTERNALSYM CWRK_TELPAD}

  GPMI_OK                     = 0;
{$EXTERNALSYM GPMI_OK}
  GPMI_INVALIDPMI             = $8000;
{$EXTERNALSYM GPMI_INVALIDPMI}

{ inkwidth limits }
  INKWIDTH_MINIMUM            = 0;          { 0 invisible, 1..15 pixel widths }
{$EXTERNALSYM INKWIDTH_MINIMUM}
  INKWIDTH_MAXIMUM            = 15;         { max width in pixels }
{$EXTERNALSYM INKWIDTH_MAXIMUM}

{ Get/SetPenMiscInfo: }
{ PMI_RCCHANGE is for WM_GLOBALRCCHANGE compatability only: }
  PMI_RCCHANGE                = 0;      { invalid for Get/SetPenMiscInfo }
{$EXTERNALSYM PMI_RCCHANGE}
  PMI_BEDIT                   = 1;      { boxed edit info }
{$EXTERNALSYM PMI_BEDIT}
  PMI_IMECOLOR                = 2;      { input method editor color }
{$EXTERNALSYM PMI_IMECOLOR}
  PMI_CXTABLET                = 3;      { tablet width }
{$EXTERNALSYM PMI_CXTABLET}
  PMI_CYTABLET                = 4;      { tablet height }
{$EXTERNALSYM PMI_CYTABLET}
  PMI_PENTIP                  = 6;      { pen tip: color, width, nib }
{$EXTERNALSYM PMI_PENTIP}
  PMI_ENABLEFLAGS             = 7;      { PWE_xx enablements }
{$EXTERNALSYM PMI_ENABLEFLAGS}
  PMI_TIMEOUT                 = 8;      { handwriting timeout }
{$EXTERNALSYM PMI_TIMEOUT}
  PMI_TIMEOUTGEST             = 9;      { gesture timeout }
{$EXTERNALSYM PMI_TIMEOUTGEST}
  PMI_TIMEOUTSEL              = 10;     { select (press&hold) timeout }
{$EXTERNALSYM PMI_TIMEOUTSEL}
  PMI_SYSFLAGS                = 11;     { component load configuration }
{$EXTERNALSYM PMI_SYSFLAGS}
  PMI_INDEXFROMRGB            = 12;     { color table index from RGB }
{$EXTERNALSYM PMI_INDEXFROMRGB}
  PMI_RGBFROMINDEX            = 13;     { RGB from color table index }
{$EXTERNALSYM PMI_RGBFROMINDEX}
  PMI_SYSREC                  = 14;     { handle to system recognizer }
{$EXTERNALSYM PMI_SYSREC}
  PMI_TICKREF                 = 15;     { reference absolute time }
{$EXTERNALSYM PMI_TICKREF}
  PMI_SAVE                    = $1000;  { save setting to file }
{$EXTERNALSYM PMI_SAVE}

{ Set/GetPenMiscInfo/PMI_ENABLEFLAGS flags: }
  PWE_AUTOWRITE               = $0001;  { pen functionality where IBeam }
{$EXTERNALSYM PWE_AUTOWRITE}
  PWE_ACTIONHANDLES           = $0002;  { action handles in controls }
{$EXTERNALSYM PWE_ACTIONHANDLES}
  PWE_INPUTCURSOR             = $0004;  { show cursor while writing }
{$EXTERNALSYM PWE_INPUTCURSOR}
  PWE_LENS                    = $0008;  { allow lens popup }
{$EXTERNALSYM PWE_LENS}

{ GetPenMiscInfo/PMI_SYSFLAGS flags: }
  PWF_RC1                     = $0001;  { Windows for Pen 1.0 RC support }
{$EXTERNALSYM PWF_RC1}
  PWF_PEN                     = $0004;  { pen drv loaded & hdwe init'd }
{$EXTERNALSYM PWF_PEN}
  PWF_INKDISPLAY              = $0008;  { ink-compatible display drv loaded }
{$EXTERNALSYM PWF_INKDISPLAY}
  PWF_RECOGNIZER              = $0010;  { system recognizer installed }
{$EXTERNALSYM PWF_RECOGNIZER}
  PWF_BEDIT                   = $0100;  { boxed edit support }
{$EXTERNALSYM PWF_BEDIT}
  PWF_HEDIT                   = $0200;  { free input edit support }
{$EXTERNALSYM PWF_HEDIT}
  PWF_IEDIT                   = $0400;  { ink edit support }
{$EXTERNALSYM PWF_IEDIT}
  PWF_ENHANCED                = $1000;  { enh features (gest, 1ms timing) }
{$EXTERNALSYM PWF_ENHANCED}
  PWF_FULL    = PWF_RC1 or PWF_PEN or PWF_INKDISPLAY or PWF_RECOGNIZER or
                PWF_BEDIT or PWF_HEDIT or PWF_IEDIT or PWF_ENHANCED;
{$EXTERNALSYM PWF_FULL}

{ SetPenAppFlags API constants: }
  RPA_DEFAULT                 = $0001;  { = RPA_HEDIT }
{$EXTERNALSYM RPA_DEFAULT}
  RPA_HEDIT                   = $0001;  { convert EDIT to HEDIT }
{$EXTERNALSYM RPA_HEDIT}
  RPA_KANJIFIXEDBEDIT         = $0002;
{$EXTERNALSYM RPA_KANJIFIXEDBEDIT}
  RPA_DBCSPRIORITY            = $0004;  { assume DBCS has priority (Japan) }
{$EXTERNALSYM RPA_DBCSPRIORITY}

  PMIR_OK                     = 0;
{$EXTERNALSYM PMIR_OK}
  PMIR_INDEX                  = -1;
{$EXTERNALSYM PMIR_INDEX}
  PMIR_VALUE                  = -2;
{$EXTERNALSYM PMIR_VALUE}
  PMIR_INVALIDBOXEDITINFO     = -3;
{$EXTERNALSYM PMIR_INVALIDBOXEDITINFO}
  PMIR_INIERROR               = -4;
{$EXTERNALSYM PMIR_INIERROR}
  PMIR_ERROR                  = -5;
{$EXTERNALSYM PMIR_ERROR}
  PMIR_NA                     = -6;
{$EXTERNALSYM PMIR_NA}

  SPMI_OK                     = 0;
{$EXTERNALSYM SPMI_OK}
  SPMI_INVALIDBOXEDITINFO     = 1;
{$EXTERNALSYM SPMI_INVALIDBOXEDITINFO}
  SPMI_INIERROR               = 2;
{$EXTERNALSYM SPMI_INIERROR}
  SPMI_INVALIDPMI             = $8000;
{$EXTERNALSYM SPMI_INVALIDPMI}

{ RC Options and Flags: }

{ RC Direction: }
  RCD_DEFAULT                 = 0;      { def none }
{$EXTERNALSYM RCD_DEFAULT}
  RCD_LR                      = 1;      { left to right like English }
{$EXTERNALSYM RCD_LR}
  RCD_RL                      = 2;      { right to left like Arabic }
{$EXTERNALSYM RCD_RL}
  RCD_TB                      = 3;      { top to bottom like Japanese }
{$EXTERNALSYM RCD_TB}
  RCD_BT                      = 4;      { bottom to top like some Chinese }
{$EXTERNALSYM RCD_BT}

{ RC International Preferences: }
  RCIP_ALLANSICHAR            = $0001;  { all ANSI chars }
{$EXTERNALSYM RCIP_ALLANSICHAR}
  RCIP_MASK                   = $0001;
{$EXTERNALSYM RCIP_MASK}

{ RC Options: }
  RCO_NOPOINTEREVENT          = $00000001;    { no recog tap, tap/hold }
{$EXTERNALSYM RCO_NOPOINTEREVENT}
  RCO_SAVEALLDATA             = $00000002;    { save pen data like upstrokes }
{$EXTERNALSYM RCO_SAVEALLDATA}
  RCO_SAVEHPENDATA            = $00000004;    { save pen data for app }
{$EXTERNALSYM RCO_SAVEHPENDATA}
  RCO_NOFLASHUNKNOWN          = $00000008;    { no ? cursor on unknown }
{$EXTERNALSYM RCO_NOFLASHUNKNOWN}
  RCO_TABLETCOORD             = $00000010;    { tablet coords used in RC }
{$EXTERNALSYM RCO_TABLETCOORD}
  RCO_NOSPACEBREAK            = $00000020;    { no space break recog -> dict }
{$EXTERNALSYM RCO_NOSPACEBREAK}
  RCO_NOHIDECURSOR            = $00000040;    { display cursor during inking }
{$EXTERNALSYM RCO_NOHIDECURSOR}
  RCO_NOHOOK                  = $00000080;    { disallow ink hook (passwords) }
{$EXTERNALSYM RCO_NOHOOK}
  RCO_BOXED                   = $00000100;    { valid rc.guide provided }
{$EXTERNALSYM RCO_BOXED}
  RCO_SUGGEST                 = $00000200;    { for dict suggest }
{$EXTERNALSYM RCO_SUGGEST}
  RCO_DISABLEGESMAP           = $00000400;    { disable gesture mapping }
{$EXTERNALSYM RCO_DISABLEGESMAP}
  RCO_NOFLASHCURSOR           = $00000800;    { no cursor feedback }
{$EXTERNALSYM RCO_NOFLASHCURSOR}
  RCO_BOXCROSS                = $00001000;    { show + at boxedit center }
{$EXTERNALSYM RCO_BOXCROSS}
  RCO_COLDRECOG               = $00008000;    { result is from cold recog }
{$EXTERNALSYM RCO_COLDRECOG}
  RCO_SAVEBACKGROUND          = $00010000;    { Save background from ink }
{$EXTERNALSYM RCO_SAVEBACKGROUND}
  RCO_DODEFAULT               = $00020000;    { do default gesture processing }
{$EXTERNALSYM RCO_DODEFAULT}

{ RC Orientation of Tablet: }
  RCOR_NORMAL                 = 1;      { tablet not rotated }
{$EXTERNALSYM RCOR_NORMAL}
  RCOR_RIGHT                  = 2;      { rotated 90 deg anticlockwise }
{$EXTERNALSYM RCOR_RIGHT}
  RCOR_UPSIDEDOWN             = 3;      { rotated 180 deg }
{$EXTERNALSYM RCOR_UPSIDEDOWN}
  RCOR_LEFT                   = 4;      { rotated 90 deg clockwise }
{$EXTERNALSYM RCOR_LEFT}

{ RC Preferences: }
  RCP_LEFTHAND                = $0001;  { left handed input }
{$EXTERNALSYM RCP_LEFTHAND}
  RCP_MAPCHAR                 = $0004;  { fill in syg.lpsyc (ink) for training }
{$EXTERNALSYM RCP_MAPCHAR}

{ RCRESULT wResultsType values: }
  RCRT_DEFAULT                = $0000;  { normal ret }
{$EXTERNALSYM RCRT_DEFAULT}
  RCRT_UNIDENTIFIED           = $0001;  { result contains unidentified results }
{$EXTERNALSYM RCRT_UNIDENTIFIED}
  RCRT_GESTURE                = $0002;  { result is a gesture }
{$EXTERNALSYM RCRT_GESTURE}
  RCRT_NOSYMBOLMATCH          = $0004;  { nothing recognized (no ink match) }
{$EXTERNALSYM RCRT_NOSYMBOLMATCH}
  RCRT_PRIVATE                = $4000;  { recognizer-specific symbol }
{$EXTERNALSYM RCRT_PRIVATE}
  RCRT_NORECOG                = $8000;  { no recog attempted, only data ret }
{$EXTERNALSYM RCRT_NORECOG}
  RCRT_ALREADYPROCESSED       = $0008;  { GestMgr hooked it }
{$EXTERNALSYM RCRT_ALREADYPROCESSED}
  RCRT_GESTURETRANSLATED      = $0010;  { GestMgr translated it to ANSI value }
{$EXTERNALSYM RCRT_GESTURETRANSLATED}
  RCRT_GESTURETOKEYS          = $0020;  { ditto to set of virtual keys }
{$EXTERNALSYM RCRT_GESTURETOKEYS}

{ RC Result Return Mode specification: }
  RRM_STROKE                  = 0;      { return results after each stroke }
{$EXTERNALSYM RRM_STROKE}
  RRM_SYMBOL                  = 1;      { per symbol (e.g. boxed edits) }
{$EXTERNALSYM RRM_SYMBOL}
  RRM_WORD                    = 2;      { on recog of a word }
{$EXTERNALSYM RRM_WORD}
  RRM_NEWLINE                 = 3;      { on recog of a line break }
{$EXTERNALSYM RRM_NEWLINE}
  RRM_COMPLETE                = 16;     { on PCM_xx specified completion }
{$EXTERNALSYM RRM_COMPLETE}

  TPT_CLOSEST                 = $0001;   { Assign to the closest target }
{$EXTERNALSYM TPT_CLOSEST}
  TPT_INTERSECTINK            = $0002;   { target with intersecting ink }
{$EXTERNALSYM TPT_INTERSECTINK}
  TPT_TEXTUAL                 = $0004;   { apply textual heuristics }
{$EXTERNALSYM TPT_TEXTUAL}
  TPT_DEFAULT                 = TPT_TEXTUAL or TPT_INTERSECTINK or TPT_CLOSEST;
{$EXTERNALSYM TPT_DEFAULT}

{ Virtual Event Layer: }
  VWM_MOUSEMOVE               = $0001;
{$EXTERNALSYM VWM_MOUSEMOVE}
  VWM_MOUSELEFTDOWN           = $0002;
{$EXTERNALSYM VWM_MOUSELEFTDOWN}
  VWM_MOUSELEFTUP             = $0004;
{$EXTERNALSYM VWM_MOUSELEFTUP}
  VWM_MOUSERIGHTDOWN          = $0008;
{$EXTERNALSYM VWM_MOUSERIGHTDOWN}
  VWM_MOUSERIGHTUP            = $0010;
{$EXTERNALSYM VWM_MOUSERIGHTUP}

{ Messages and Defines }

  WM_RCRESULT                 = WM_PENWINFIRST+1;   { $381 }
{$EXTERNALSYM WM_RCRESULT}
  WM_HOOKRCRESULT             = WM_PENWINFIRST+2;   { $382 }
{$EXTERNALSYM WM_HOOKRCRESULT}
  WM_PENMISCINFO              = WM_PENWINFIRST+3;   { $383 }
{$EXTERNALSYM WM_PENMISCINFO}
  WM_GLOBALRCCHANGE           = WM_PENWINFIRST+3;   { alias }
{$EXTERNALSYM WM_GLOBALRCCHANGE}
  WM_SKB                      = WM_PENWINFIRST+4;   { $384 }
{$EXTERNALSYM WM_SKB}
  WM_PENCTL                   = WM_PENWINFIRST+5;   { $385 }
{$EXTERNALSYM WM_PENCTL}
  WM_HEDITCTL                 = WM_PENWINFIRST+5;   { FBC: alias }
{$EXTERNALSYM WM_HEDITCTL}

{ WM_HEDITCTL (WM_PENCTL) wParam options: }
  HE_GETRC                    = 3;      { FBC: get RC from HEDIT/BEDIT control }
{$EXTERNALSYM HE_GETRC}
  HE_SETRC                    = 4;      { FBC: ditto set }
{$EXTERNALSYM HE_SETRC}
  HE_GETINFLATE               = 5;      { FBC: get inflate rect }
{$EXTERNALSYM HE_GETINFLATE}
  HE_SETINFLATE               = 6;      { FBC: ditto set }
{$EXTERNALSYM HE_SETINFLATE}
  HE_GETUNDERLINE             = 7;      { get underline mode }
{$EXTERNALSYM HE_GETUNDERLINE}
  HE_SETUNDERLINE             = 8;      { ditto set }
{$EXTERNALSYM HE_SETUNDERLINE}
  HE_GETINKHANDLE             = 9;      { get handle to captured ink }
{$EXTERNALSYM HE_GETINKHANDLE}
  HE_SETINKMODE               = 10;     { begin HEDIT cold recog mode }
{$EXTERNALSYM HE_SETINKMODE}
  HE_STOPINKMODE              = 11;     { end cold recog mode }
{$EXTERNALSYM HE_STOPINKMODE}
  HE_GETRCRESULTCODE          = 12;     { FBC: result of recog after HN_ENDREC }
{$EXTERNALSYM HE_GETRCRESULTCODE}
  HE_DEFAULTFONT              = 13;     { switch BEDIT to def font }
{$EXTERNALSYM HE_DEFAULTFONT}
  HE_CHARPOSITION             = 14;     { BEDIT byte offset -> char position }
{$EXTERNALSYM HE_CHARPOSITION}
  HE_CHAROFFSET               = 15;     { BEDIT char position -> byte offset }
{$EXTERNALSYM HE_CHAROFFSET}
  HE_GETBOXLAYOUT             = 20;     { get BEDIT layout }
{$EXTERNALSYM HE_GETBOXLAYOUT}
  HE_SETBOXLAYOUT             = 21;     { ditto set }
{$EXTERNALSYM HE_SETBOXLAYOUT}
  HE_GETRCRESULT              = 22;     { FBC: get RCRESULT after HN_RCRESULT }
{$EXTERNALSYM HE_GETRCRESULT}
  HE_KKCONVERT                = 30;     { JPN start kana-kanji conversion }
{$EXTERNALSYM HE_KKCONVERT}
  HE_GETKKCONVERT             = 31;     { JPN get KK state }
{$EXTERNALSYM HE_GETKKCONVERT}
  HE_CANCELKKCONVERT          = 32;     { JPN cancel KK conversion }
{$EXTERNALSYM HE_CANCELKKCONVERT}
  HE_FIXKKCONVERT             = 33;     { JPN force KK result }
{$EXTERNALSYM HE_FIXKKCONVERT}
  HE_GETKKSTATUS              = 34;     { JPN get KK UI state }
{$EXTERNALSYM HE_GETKKSTATUS}
  HE_KKNOCONVERT              = 35;     { JPN revert conversion }
{$EXTERNALSYM HE_KKNOCONVERT}
  HE_SETIMEDEFAULT            = 36;     { JPN set a range of DCS }
{$EXTERNALSYM HE_SETIMEDEFAULT}
  HE_GETIMEDEFAULT            = 37;     { JPN get a range of DCS }
{$EXTERNALSYM HE_GETIMEDEFAULT}
  HE_ENABLEALTLIST            = 40;     { en/disable dropdown recog alt's }
{$EXTERNALSYM HE_ENABLEALTLIST}
  HE_SHOWALTLIST              = 41;     { show dropdown (assume enabled) }
{$EXTERNALSYM HE_SHOWALTLIST}
  HE_HIDEALTLIST              = 42;     { hide dropdown alternatives }
{$EXTERNALSYM HE_HIDEALTLIST}
  HE_GETLENSTYPE              = 43;     { get lens type: CWR_ and CWRK_ flags }
{$EXTERNALSYM HE_GETLENSTYPE}
  HE_SETLENSTYPE              = 44;     { set lens type: CWR_ and CWRK_ flags }
{$EXTERNALSYM HE_SETLENSTYPE}

{ JPN Kana-to-Kanji conversion subfunctions: }
  HEKK_DEFAULT                = 0;      { def }
{$EXTERNALSYM HEKK_DEFAULT}
  HEKK_CONVERT                = 1;      { convert in place }
{$EXTERNALSYM HEKK_CONVERT}
  HEKK_CANDIDATE              = 2;      { start conversion dialog }
{$EXTERNALSYM HEKK_CANDIDATE}
  HEKK_DBCSCHAR               = 3;      { convert to DBCS }
{$EXTERNALSYM HEKK_DBCSCHAR}
  HEKK_SBCSCHAR               = 4;      { convert to SBCS }
{$EXTERNALSYM HEKK_SBCSCHAR}
  HEKK_HIRAGANA               = 5;      { convert to hiragana }
{$EXTERNALSYM HEKK_HIRAGANA}
  HEKK_KATAKANA               = 6;      { convert to katakana }
{$EXTERNALSYM HEKK_KATAKANA}

{ JPN Return value of HE_GETKKSTATUS }
  HEKKR_PRECONVERT            = 1;      { in pre conversion mode }
{$EXTERNALSYM HEKKR_PRECONVERT}
  HEKKR_CONVERT               = 2;      { in mid conversion mode }
{$EXTERNALSYM HEKKR_CONVERT}
  HEKKR_TEMPCONFIRM           = 3;      { in post conversion mode }
{$EXTERNALSYM HEKKR_TEMPCONFIRM}

{ HE_STOPINKMODE (stop cold recog) options: }
  HEP_NORECOG                 = 0;      { don't recog ink }
{$EXTERNALSYM HEP_NORECOG}
  HEP_RECOG                   = 1;      { recog ink }
{$EXTERNALSYM HEP_RECOG}
  HEP_WAITFORTAP              = 2;      { recog after tap in window }
{$EXTERNALSYM HEP_WAITFORTAP}

{ WM_PENCTL notifications: }
  HN_ENDREC                   = 4;      { recog complete }
{$EXTERNALSYM HN_ENDREC}
  HN_DELAYEDRECOGFAIL         = 5;      { HE_STOPINKMODE (cold recog) failed }
{$EXTERNALSYM HN_DELAYEDRECOGFAIL}
  HN_RESULT                   = 20;     { HEDIT/BEDIT has received new ink/recognition result }
{$EXTERNALSYM HN_RESULT}
  HN_RCRESULT                 = HN_RESULT;
{$EXTERNALSYM HN_RCRESULT}
  HN_ENDKKCONVERT             = 30;     { JPN KK conversion complete }
{$EXTERNALSYM HN_ENDKKCONVERT}
  HN_BEGINDIALOG              = 40;     { Lens/EditText/garbage detection dialog }
{$EXTERNALSYM HN_BEGINDIALOG}
{  is about to come up on this hedit/bedit }
  HN_ENDDIALOG                = 41;     { Lens/EditText/garbage detection dialog }
{$EXTERNALSYM HN_ENDDIALOG}
{  has just been destroyed }

{ Messages common with other controls: }

  IE_GETMODIFY          = EM_GETMODIFY;        { gets the mod'n (dirty) bit }
{$EXTERNALSYM IE_GETMODIFY}
  IE_SETMODIFY          = EM_SETMODIFY;        { sets the mod'n (dirty) bit }
{$EXTERNALSYM IE_SETMODIFY}
  IE_CANUNDO            = EM_CANUNDO;          { queries whether can undo }
{$EXTERNALSYM IE_CANUNDO}
  IE_UNDO               = EM_UNDO;             { undo }
{$EXTERNALSYM IE_UNDO}
  IE_EMPTYUNDOBUFFER    = EM_EMPTYUNDOBUFFER;  { clears IEDIT undo buffer }
{$EXTERNALSYM IE_EMPTYUNDOBUFFER}
  IE_MSGFIRST           = WM_USER+150;         { $496 = 1174 }
{$EXTERNALSYM IE_MSGFIRST}

{ IEdit common messages: }
  IE_GETINK                 = IE_MSGFIRST+0;    { gets ink from the control }
{$EXTERNALSYM IE_GETINK}
  IE_SETINK                 = IE_MSGFIRST+1;    { sets ink into the control }
{$EXTERNALSYM IE_SETINK}
  IE_GETPENTIP              = IE_MSGFIRST+2;    { gets the cur def ink pentip }
{$EXTERNALSYM IE_GETPENTIP}
  IE_SETPENTIP              = IE_MSGFIRST+3;    { sets the cur def ink pentip }
{$EXTERNALSYM IE_SETPENTIP}
  IE_GETERASERTIP           = IE_MSGFIRST+4;    { gets the cur eraser pentip }
{$EXTERNALSYM IE_GETERASERTIP}
  IE_SETERASERTIP           = IE_MSGFIRST+5;    { sets the cur eraser pentip }
{$EXTERNALSYM IE_SETERASERTIP}
  IE_GETBKGND               = IE_MSGFIRST+6;    { gets the bkgnd options }
{$EXTERNALSYM IE_GETBKGND}
  IE_SETBKGND               = IE_MSGFIRST+7;    { sets the bkgnd options }
{$EXTERNALSYM IE_SETBKGND}
  IE_GETGRIDORIGIN          = IE_MSGFIRST+8;    { gets the bkgnd grid origin }
{$EXTERNALSYM IE_GETGRIDORIGIN}
  IE_SETGRIDORIGIN          = IE_MSGFIRST+9;    { sets the bkgnd grid origin }
{$EXTERNALSYM IE_SETGRIDORIGIN}
  IE_GETGRIDPEN             = IE_MSGFIRST+10;   { gets the bkgnd grid pen }
{$EXTERNALSYM IE_GETGRIDPEN}
  IE_SETGRIDPEN             = IE_MSGFIRST+11;   { sets the bkgnd grid pen }
{$EXTERNALSYM IE_SETGRIDPEN}
  IE_GETGRIDSIZE            = IE_MSGFIRST+12;   { gets the bkgnd grid size }
{$EXTERNALSYM IE_GETGRIDSIZE}
  IE_SETGRIDSIZE            = IE_MSGFIRST+13;   { sets the bkgnd grid size }
{$EXTERNALSYM IE_SETGRIDSIZE}
  IE_GETMODE                = IE_MSGFIRST+14;   { gets the current pen mode }
{$EXTERNALSYM IE_GETMODE}
  IE_SETMODE                = IE_MSGFIRST+15;   { sets the current pen mode }
{$EXTERNALSYM IE_SETMODE}
  IE_GETINKRECT             = IE_MSGFIRST+16;   { gets the rectbound of the ink }
{$EXTERNALSYM IE_GETINKRECT}

{ IEdit-specific messages: }
  IE_GETAPPDATA             = IE_MSGFIRST+34;   { gets the user-defined datum }
{$EXTERNALSYM IE_GETAPPDATA}
  IE_SETAPPDATA             = IE_MSGFIRST+35;   { sets the user-defined data }
{$EXTERNALSYM IE_SETAPPDATA}
  IE_GETDRAWOPTS            = IE_MSGFIRST+36;   { gets the ink draw options }
{$EXTERNALSYM IE_GETDRAWOPTS}
  IE_SETDRAWOPTS            = IE_MSGFIRST+37;   { sets the ink options }
{$EXTERNALSYM IE_SETDRAWOPTS}
  IE_GETFORMAT              = IE_MSGFIRST+38;   { gets format of stroke(s) }
{$EXTERNALSYM IE_GETFORMAT}
  IE_SETFORMAT              = IE_MSGFIRST+39;   { sets format of stroke(s) }
{$EXTERNALSYM IE_SETFORMAT}
  IE_GETINKINPUT            = IE_MSGFIRST+40;   { gets the ink input option }
{$EXTERNALSYM IE_GETINKINPUT}
  IE_SETINKINPUT            = IE_MSGFIRST+41;   { sets the ink input option }
{$EXTERNALSYM IE_SETINKINPUT}
  IE_GETNOTIFY              = IE_MSGFIRST+42;   { gets the notification bits }
{$EXTERNALSYM IE_GETNOTIFY}
  IE_SETNOTIFY              = IE_MSGFIRST+43;   { sets the notification bits }
{$EXTERNALSYM IE_SETNOTIFY}
  IE_GETRECOG               = IE_MSGFIRST+44;   { gets recognition options }
{$EXTERNALSYM IE_GETRECOG}
  IE_SETRECOG               = IE_MSGFIRST+45;   { sets recognition options }
{$EXTERNALSYM IE_SETRECOG}
  IE_GETSECURITY            = IE_MSGFIRST+46;   { gets the security options }
{$EXTERNALSYM IE_GETSECURITY}
  IE_SETSECURITY            = IE_MSGFIRST+47;   { sets the security options }
{$EXTERNALSYM IE_SETSECURITY}
  IE_GETSEL                 = IE_MSGFIRST+48;   { gets sel status of a stroke }
{$EXTERNALSYM IE_GETSEL}
  IE_SETSEL                 = IE_MSGFIRST+49;   { sets sel status of a stroke }
{$EXTERNALSYM IE_SETSEL}
  IE_DOCOMMAND              = IE_MSGFIRST+50;   { send command to IEdit }
{$EXTERNALSYM IE_DOCOMMAND}
  IE_GETCOMMAND             = IE_MSGFIRST+51;   { gets user command }
{$EXTERNALSYM IE_GETCOMMAND}
  IE_GETCOUNT               = IE_MSGFIRST+52;   { gets count of strks in I-Edit }
{$EXTERNALSYM IE_GETCOUNT}
  IE_GETGESTURE             = IE_MSGFIRST+53;   { gets details on user gesture }
{$EXTERNALSYM IE_GETGESTURE}
  IE_GETMENU                = IE_MSGFIRST+54;   { gets handle to pop-up menu }
{$EXTERNALSYM IE_GETMENU}
  IE_GETPAINTDC             = IE_MSGFIRST+55;   { gets the HDC for painting }
{$EXTERNALSYM IE_GETPAINTDC}
  IE_GETPDEVENT             = IE_MSGFIRST+56;   { gets details of last pd event }
{$EXTERNALSYM IE_GETPDEVENT}
  IE_GETSELCOUNT            = IE_MSGFIRST+57;   { gets count of selected strks }
{$EXTERNALSYM IE_GETSELCOUNT}
  IE_GETSELITEMS            = IE_MSGFIRST+58;   { gets indices of all sel strks }
{$EXTERNALSYM IE_GETSELITEMS}
  IE_GETSTYLE               = IE_MSGFIRST+59;   { gets IEdit control styles }
{$EXTERNALSYM IE_GETSTYLE}

{ (H)Edit Control: }

{ CTLINITHEDIT.dwFlags values }
  CIH_NOGDMSG               = $0001;  { disable garbage detection message box for this edit }
{$EXTERNALSYM CIH_NOGDMSG}
  CIH_NOACTIONHANDLE        = $0002;  { disable action handles for this edit }
{$EXTERNALSYM CIH_NOACTIONHANDLE}
  CIH_NOEDITTEXT            = $0004;  { disable Lens/Edit/Insert text for this edit }
{$EXTERNALSYM CIH_NOEDITTEXT}
  CIH_NOFLASHCURSOR         = $0008;  { don't flash cursor on tap-n-hold in this (h)edit }
{$EXTERNALSYM CIH_NOFLASHCURSOR}

{ Boxed Edit Control: }

{ box edit alternative list: }
  HEAL_DEFAULT                = -1;     { AltList def value for lParam }
{$EXTERNALSYM HEAL_DEFAULT}

{ box edit Info: }
  BEI_FACESIZE                = 32;     { max size of font name, = LF_FACESIZE }
{$EXTERNALSYM BEI_FACESIZE}
  BEIF_BOXCROSS               = $0001;
{$EXTERNALSYM BEIF_BOXCROSS}

{ box edit size: }
  BESC_DEFAULT                = 0;
{$EXTERNALSYM BESC_DEFAULT}
  BESC_ROMANFIXED             = 1;
{$EXTERNALSYM BESC_ROMANFIXED}
  BESC_KANJIFIXED             = 2;
{$EXTERNALSYM BESC_KANJIFIXED}
  BESC_USERDEFINED            = 3;
{$EXTERNALSYM BESC_USERDEFINED}

{ CTLINITBEDIT.wFlags values }
  CIB_NOGDMSG               = $0001;  { disable garbage detection message box for this bedit }
{$EXTERNALSYM CIB_NOGDMSG}
  CIB_NOACTIONHANDLE        = $0002;  { disable action handles for this bedit }
{$EXTERNALSYM CIB_NOACTIONHANDLE}
  CIB_NOFLASHCURSOR         = $0004;  { don't flash cursor on tap-n-hold in this bedit }
 {$EXTERNALSYM CIB_NOFLASHCURSOR}
  CIB_NOWRITING             = $0010;  { disallow pen input into control }
{$EXTERNALSYM CIB_NOWRITING}

  BXD_CELLWIDTH               = 12;
{$EXTERNALSYM BXD_CELLWIDTH}
  BXD_CELLHEIGHT              = 16;
{$EXTERNALSYM BXD_CELLHEIGHT}
  BXD_BASEHEIGHT              = 13;
{$EXTERNALSYM BXD_BASEHEIGHT}
  BXD_BASEHORZ                = 0;
{$EXTERNALSYM BXD_BASEHORZ}
  BXD_MIDFROMBASE             = 0;
{$EXTERNALSYM BXD_MIDFROMBASE}
  BXD_CUSPHEIGHT              = 2;
{$EXTERNALSYM BXD_CUSPHEIGHT}
  BXD_ENDCUSPHEIGHT           = 4;
{$EXTERNALSYM BXD_ENDCUSPHEIGHT}

  BXDK_CELLWIDTH              = 32;
{$EXTERNALSYM BXDK_CELLWIDTH}
  BXDK_CELLHEIGHT             = 32;
{$EXTERNALSYM BXDK_CELLHEIGHT}
  BXDK_BASEHEIGHT             = 28;
{$EXTERNALSYM BXDK_BASEHEIGHT}
  BXDK_BASEHORZ               = 0;
{$EXTERNALSYM BXDK_BASEHORZ}
  BXDK_MIDFROMBASE            = 0;
{$EXTERNALSYM BXDK_MIDFROMBASE}
  BXDK_CUSPHEIGHT             = 28;
{$EXTERNALSYM BXDK_CUSPHEIGHT}
  BXDK_ENDCUSPHEIGHT          = 10;
{$EXTERNALSYM BXDK_ENDCUSPHEIGHT}

{ IME colors for bedit }
  COLOR_BE_INPUT                 = 0;
{$EXTERNALSYM COLOR_BE_INPUT}
  COLOR_BE_INPUT_TEXT            = 1;
{$EXTERNALSYM COLOR_BE_INPUT_TEXT}
  COLOR_BE_CONVERT               = 2;
{$EXTERNALSYM COLOR_BE_CONVERT}
  COLOR_BE_CONVERT_TEXT          = 3;
{$EXTERNALSYM COLOR_BE_CONVERT_TEXT}
  COLOR_BE_CONVERTED             = 4;
{$EXTERNALSYM COLOR_BE_CONVERTED}
  COLOR_BE_CONVERTED_TEXT        = 5;
{$EXTERNALSYM COLOR_BE_CONVERTED_TEXT}
  COLOR_BE_UNCONVERT             = 6;
{$EXTERNALSYM COLOR_BE_UNCONVERT}
  COLOR_BE_UNCONVERT_TEXT        = 7;
{$EXTERNALSYM COLOR_BE_UNCONVERT_TEXT}
  COLOR_BE_CURSOR                = 8;
{$EXTERNALSYM COLOR_BE_CURSOR}
  COLOR_BE_CURSOR_TEXT           = 9;
{$EXTERNALSYM COLOR_BE_CURSOR_TEXT}
  COLOR_BE_PRECONVERT            = 10;
{$EXTERNALSYM COLOR_BE_PRECONVERT}
  COLOR_BE_PRECONVERT_TEXT       = 11;
{$EXTERNALSYM COLOR_BE_PRECONVERT_TEXT}
  MAXIMECOLORS                   = 12;
{$EXTERNALSYM MAXIMECOLORS}

  WM_PENMISC                  = WM_PENWINFIRST+6;   { $386 }
{$EXTERNALSYM WM_PENMISC}

{ WM_PENMISC message constants: }
  PMSC_BEDITCHANGE            = 1;      { broadcast when BEDIT changes }
{$EXTERNALSYM PMSC_BEDITCHANGE}
  PMSC_PENUICHANGE            = 2;      { JPN broadcast when PENUI changes }
{$EXTERNALSYM PMSC_PENUICHANGE}
  PMSC_SUBINPCHANGE           = 3;      { JPN broadcast when SUBINPUT changes }
{$EXTERNALSYM PMSC_SUBINPCHANGE}
  PMSC_KKCTLENABLE            = 4;      { JPN }
{$EXTERNALSYM PMSC_KKCTLENABLE}
  PMSC_GETPCMINFO             = 5;      { query the window's PCMINFO }
{$EXTERNALSYM PMSC_GETPCMINFO}
  PMSC_SETPCMINFO             = 6;      { set the window's PCMINFO }
{$EXTERNALSYM PMSC_SETPCMINFO}
  PMSC_GETINKINGINFO          = 7;      { query the window's INKINGINFO }
{$EXTERNALSYM PMSC_GETINKINGINFO}
  PMSC_SETINKINGINFO          = 8;      { set the window's INKINGINFO }
{$EXTERNALSYM PMSC_SETINKINGINFO}
  PMSC_GETHRC                 = 9;      { query the window's HRC }
{$EXTERNALSYM PMSC_GETHRC}
  PMSC_SETHRC                 = 10;     { set the window's HRC }
{$EXTERNALSYM PMSC_SETHRC}
  PMSC_GETSYMBOLCOUNT         = 11;     { count of symbols in result recd by window }
{$EXTERNALSYM PMSC_GETSYMBOLCOUNT}
  PMSC_GETSYMBOLS             = 12;     { ditto symbols }
{$EXTERNALSYM PMSC_GETSYMBOLS}
  PMSC_SETSYMBOLS             = 13;     { ditto set symbols }
{$EXTERNALSYM PMSC_SETSYMBOLS}
  PMSC_LOADPW                 = 15;     { broadcast load state on penwin }
{$EXTERNALSYM PMSC_LOADPW}
  PMSC_INKSTOP                = 16;
{$EXTERNALSYM PMSC_INKSTOP}

{ PMSCL_xx lParam values for PMSC_xx: }
  PMSCL_UNLOADED              = 0;      { penwin just unloaded }
{$EXTERNALSYM PMSCL_UNLOADED}
  PMSCL_LOADED                = 1;      { penwin just loaded }
{$EXTERNALSYM PMSCL_LOADED}
  PMSCL_UNLOADING             = 2;      { penwin about to unload }
{$EXTERNALSYM PMSCL_UNLOADING}

  WM_CTLINIT                  = WM_PENWINFIRST+7;   { $387 }
{$EXTERNALSYM WM_CTLINIT}

{ WM_CTLINIT message constants: }
  CTLINIT_HEDIT               = 1;
{$EXTERNALSYM CTLINIT_HEDIT}
  CTLINIT_BEDIT               = 7;
{$EXTERNALSYM CTLINIT_BEDIT}
  CTLINIT_IEDIT               = 9;
{$EXTERNALSYM CTLINIT_IEDIT}
  CTLINIT_MAX                 = 10;
{$EXTERNALSYM CTLINIT_MAX}

  WM_PENEVENT                 = WM_PENWINFIRST+8;   { $388 }
{$EXTERNALSYM WM_PENEVENT}

{ WM_PENEVENT message values for wParam: }
  PE_PENDOWN                  = 1;      { pen tip down }
{$EXTERNALSYM PE_PENDOWN}
  PE_PENUP                    = 2;      { pen tip went from down to up }
{$EXTERNALSYM PE_PENUP}
  PE_PENMOVE                  = 3;      { pen moved without a tip transition }
{$EXTERNALSYM PE_PENMOVE}
  PE_TERMINATING              = 4;      { Peninput about to terminate }
{$EXTERNALSYM PE_TERMINATING}
  PE_TERMINATED               = 5;      { Peninput terminated }
{$EXTERNALSYM PE_TERMINATED}
  PE_BUFFERWARNING            = 6;      { Buffer half full. }
{$EXTERNALSYM PE_BUFFERWARNING}
  PE_BEGININPUT               = 7;      { begin default input }
{$EXTERNALSYM PE_BEGININPUT}
  PE_SETTARGETS               = 8;      { set target data structure (TARGINFO) }
{$EXTERNALSYM PE_SETTARGETS}
  PE_BEGINDATA                = 9;      { init message to all targets }
{$EXTERNALSYM PE_BEGINDATA}
  PE_MOREDATA                 = 10;     { target gets more data }
{$EXTERNALSYM PE_MOREDATA}
  PE_ENDDATA                  = 11;     { termination message to all targets }
{$EXTERNALSYM PE_ENDDATA}
  PE_GETPCMINFO               = 12;     { get input collection info }
{$EXTERNALSYM PE_GETPCMINFO}
  PE_GETINKINGINFO            = 13;     { get inking info }
{$EXTERNALSYM PE_GETINKINGINFO}
  PE_ENDINPUT                 = 14;     { Input termination message to window }
{$EXTERNALSYM PE_ENDINPUT}
{ starting default input }
  PE_RESULT                   = 15;     { sent after ProcessHRC but before GetResultsHRC }
{$EXTERNALSYM PE_RESULT}

type
  HTRG = Integer;
{$EXTERNALSYM HTRG}
  HPCM = Integer;
{$EXTERNALSYM HPCM}
  HPENDATA = Integer;
{$EXTERNALSYM HPENDATA}
  HREC = Integer;
{$EXTERNALSYM HREC}


{ Types }

{ Simple: }
type
  ALC = Longint;                                { Enabled Alphabet }
{$EXTERNALSYM ALC}
  CL = Integer;                              { Confidence Level }
{$EXTERNALSYM CL}
  HKP = UINT;                                { Hook Parameter }
{$EXTERNALSYM HKP}
  REC = Integer;                             { recognition result }
{$EXTERNALSYM REC}
  SYV = Longint;                                { Symbol Value }
{$EXTERNALSYM SYV}

{ Pointer Types: }
type
  PALC = ^ALC;                                      { ptr to ALC }
  LPALC = PALC;
{$EXTERNALSYM LPALC}
  POEM = Pointer;                                   { alias }
  LPOEM = POEM;
{$EXTERNALSYM LPOEM}
  PSYV = ^SYV;                                      { ptr to SYV }
  LPSYV = PSYV;
{$EXTERNALSYM LPSYV}
  PHPENDATA = ^HPENDATA;                            { ptr to HPENDATA }
  LPHPENDATA = PHPENDATA;
{$EXTERNALSYM LPHPENDATA}

{ Function Prototypes: }
  ENUMPROC = function(p1: PSYV; p2: Integer; p3: Integer): Integer stdcall;
  TFNEnumProc = ENUMPROC;
{$EXTERNALSYM ENUMPROC}
  PFNLPDF = ^TFNLPDF;
  LPDF = function(p1: Integer; p2, p3: Pointer; p4: Integer;
    p5, p6: DWORD): Integer stdcall;
  TFNLPDF = LPDF;
  {$EXTERNALSYM LPDF}
  RCYIELDPROC = function: BOOL stdcall;
  TFNRCYieldProc = RCYIELDPROC;
  {$EXTERNALSYM RCYIELDPROC}

{ Structures: }

  PAbsTime = ^TAbsTime;
  tagABSTIME = packed record    { 2.0 absolute date/time }
    sec: DWORD;    { number of seconds since 1/1/1970, ret by CRTlib time() fn }
    ms: UINT;      { additional offset in ms, 0..999 }
  end;
{$EXTERNALSYM tagABSTIME}
  TAbsTime = tagABSTIME;
  ABSTIME = tagABSTIME;
{$EXTERNALSYM ABSTIME}
  LPABSTIME = PAbsTime;
{$EXTERNALSYM LPABSTIME}

  PCtlInitHEdit = ^TCtlInitHEdit;
  tagCTLINITHEDIT = packed record { 2.0 init struct for (h)edit }
    cbSize: DWORD;              { sizeof(CTLINITHEDIT) }
    hwnd: HWND;                 { (h)edit window handle }
    id: Integer;                    { its id }
    dwFlags: DWORD;             { CIE_xx }
    dwReserved: DWORD;          { for future use }
  end;
{$EXTERNALSYM tagCTLINITHEDIT}
  TCtlInitHEdit = tagCTLINITHEDIT;
  CTLINITHEDIT = tagCTLINITHEDIT;
{$EXTERNALSYM CTLINITHEDIT}
  LPCTLINITHEDIT = PCtlInitHEdit;
{$EXTERNALSYM LPCTLINITHEDIT}

  PBoxLayout = ^TBoxLayout;
  tagBOXLAYOUT = packed record  { 1.0 box edit layout }
    cyCusp: Integer;                { pixel height of box (BXS_RECT) or cusp }
    cyEndCusp: Integer;             { pixel height of cusps at extreme ends }
    style: UINT;                { BXS_xx style }
    dwReserved1: DWORD;         { reserved }
    dwReserved2: DWORD;         { reserved }
    dwReserved3: DWORD;         { reserved }
  end;
{$EXTERNALSYM tagBOXLAYOUT}
  TBoxLayout = tagBOXLAYOUT;
  BOXLAYOUT = TBoxLayout;
{$EXTERNALSYM BOXLAYOUT}
  LPBOXLAYOUT = PBoxLayout;
{$EXTERNALSYM LPBOXLAYOUT}

  PIMEColors = ^TIMEColors;
  tagIMECOLORS = packed record  { 2.0 IME undetermined string color info. }
    cColors: Integer;               { count of colors to be set/get }
    lpnElem: PINT;             { address of array of elements }
    lprgbIme: ^COLORREF;        { address of array of RGB values }
  end;
{$EXTERNALSYM tagIMECOLORS}
  TIMEColors = tagIMECOLORS;
  IMECOLORS = tagIMECOLORS;
{$EXTERNALSYM IMECOLORS}
  LPIMECOLORS = PIMEColors;
{$EXTERNALSYM LPIMECOLORS}

  PCtlInitBEdit = ^TCtlInitBEdit;
  tagCTLINITBEDIT = packed record { 2.0 init struct for box edit }
    cbSize: DWORD;              { sizeof(CTLINITBEDIT) }
    hwnd: HWND;                 { box edit window handle }
    id: Integer;                    { its id }
    wSizeCategory: WORD;        { BESC_xx }
    wFlags: WORD;               { CIB_xx }
    dwReserved: DWORD;          { for future use }
  end;
{$EXTERNALSYM tagCTLINITBEDIT}
  TCtlInitBEdit = tagCTLINITBEDIT;
  CTLINITBEDIT = tagCTLINITBEDIT;
{$EXTERNALSYM CTLINITBEDIT}
  LPCTLINITBEDIT = PCtlInitBEdit;
{$EXTERNALSYM LPCTLINITBEDIT}

  PBoxEditInfo = ^TBoxEditInfo;
  tagBOXEDITINFO = packed record { 1.1 box edit Size Info }
    cxBox: Integer;                 { width of a single box }
    cyBox: Integer;                 { ditto height }
    cxBase: Integer;                { in-box x-margin to guideline }
    cyBase: Integer;                { in-box y offset from top to baseline }
    cyMid: Integer;                 { 0 or distance from baseline to midline }
    boxlayout: TBoxLayout;       { embedded BOXLAYOUT structure }
    wFlags: UINT;               { BEIF_xx }
    szFaceName: packed array[0..BEI_FACESIZE-1] of BYTE;{ font face name }
    wFontHeight: UINT;          { font height }
    rgwReserved: packed array[0..7] of UINT;{ for future use }
  end;
{$EXTERNALSYM tagBOXEDITINFO}
  TBoxEditInfo = tagBOXEDITINFO;
  BOXEDITINFO = tagBOXEDITINFO;
{$EXTERNALSYM BOXEDITINFO}
  LPBOXEDITINFO = PBoxEditInfo;
{$EXTERNALSYM LPBOXEDITINFO}

  PRectOfs = ^TRectOfs;
  tagRECTOFS = packed record    { 1.0 rectangle offset for nonisometric inflation }
    dLeft: Integer;                 { inflation leftwards from left side }
    dTop: Integer;                  { ditto upwards from top }
    dRight: Integer;                { ditto rightwards from right }
    dBottom: Integer;               { ditto downwards from bottom }
  end;
{$EXTERNALSYM tagRECTOFS}
  TRectOfs = tagRECTOFS;
  RECTOFS = tagRECTOFS;
{$EXTERNALSYM RECTOFS}
  LPRECTOFS = PRectOfs;
{$EXTERNALSYM LPRECTOFS}

  PPenDataHeader = ^TPenDataHeader;
  tagPENDATAHEADER = packed record { 1.0 main pen data header }
    wVersion: UINT;             { pen data format version }
    cbSizeUsed: UINT;           { size of pendata mem block in bytes }
    cStrokes: UINT;             { number of strokes (incl up-strokes) }
    cPnt: UINT;                 { count of all points }
    cPntStrokeMax: UINT;        { length (in points) of longest stroke }
    rectBound: TRect;            { bounding rect of all down points }
    wPndts: UINT;               { PDTS_xx bits }
    nInkWidth: Integer;             { ink width in pixels }
    rgbInk: DWORD;              { ink color }
  end;
{$EXTERNALSYM tagPENDATAHEADER}
  TPenDataHeader = tagPENDATAHEADER;
  PENDATAHEADER = tagPENDATAHEADER;
{$EXTERNALSYM PENDATAHEADER}
  LPPENDATAHEADER = PPenDataHeader;
{$EXTERNALSYM LPPENDATAHEADER}

  PStrokeInfo = ^TStrokeInfo;
  tagSTROKEINFO = packed record { 1.0 stroke header }
    cPnt: UINT;                 { count of points in stroke }
    cbPnts: UINT;               { size of stroke in bytes }
    wPdk: UINT;                 { state of stroke }
    dwTick: DWORD;              { time at beginning of stroke }
  end;
{$EXTERNALSYM tagSTROKEINFO}
  TStrokeInfo = tagSTROKEINFO;
  STROKEINFO = tagSTROKEINFO;
{$EXTERNALSYM STROKEINFO}
  LPSTROKEINFO = PStrokeInfo;
{$EXTERNALSYM LPSTROKEINFO}

  PPenTip = ^TPenTip;
  tagPENTIP = packed record     { 2.0 Pen Tip characteristics }
    cbSize: DWORD;              { sizeof(PENTIP) }
    btype: BYTE;                { pen type/nib (calligraphic nib, etc.) }
    bwidth: BYTE;               { width of Nib (typically = nInkWidth) }
    bheight: BYTE;              { height of Nib }
    bOpacity: BYTE;             { 0=transparent, $80=hilite, $FF=opaque }
    rgb: COLORREF;              { pen color }
    dwFlags: DWORD;             { TIP_xx flags }
    dwReserved: DWORD;          { for future expansion }
  end;
{$EXTERNALSYM tagPENTIP}
  TPenTip = tagPENTIP;
  PENTIP = tagPENTIP;
{$EXTERNALSYM PENTIP}
  LPPENTIP = PPenTip;
{$EXTERNALSYM LPPENTIP}

  ANIMATEPROC = function(p1: HPENDATA; p2, p3: UINT; p4: PUINT;
    p5: LPARAM): BOOL stdcall;
{$EXTERNALSYM ANIMATEPROC}
  TFNAnimateProc = ANIMATEPROC;

  PAnimateInfo = ^TAnimateInfo;
  tagANIMATEINFO = packed record { 2.0 Animation parameters }
    cbSize: DWORD;              { sizeof(ANIMATEINFO) }
    uSpeedPct: UINT;            { speed percent to animate at }
    uPeriodCB: UINT;            { time between calls to callback in ms }
    fuFlags: UINT;              { animation flags }
    lParam: LPARAM;             { value to pass to callback }
    dwReserved: DWORD;          { reserved }
  end;
{$EXTERNALSYM tagANIMATEINFO}
  TAnimateInfo = tagANIMATEINFO;
  ANIMATEINFO = tagANIMATEINFO;
{$EXTERNALSYM ANIMATEINFO}
  LPANIMATEINFO = PAnimateInfo;
{$EXTERNALSYM LPANIMATEINFO}

  POEMPenInfo = ^TOEMPenInfo;
  tagOEMPENINFO = packed record { 1.0 OEM pen/tablet hdwe info }
    wPdt: UINT;                 { pen data type }
    wValueMax: UINT;            { largest val ret by device }
    wDistinct: UINT;            { number of distinct readings possible }
  end;
{$EXTERNALSYM tagOEMPENINFO}
  TOEMPenInfo = tagOEMPENINFO;
  OEMPENINFO = tagOEMPENINFO;
{$EXTERNALSYM OEMPENINFO}
  LPOEMPENINFO = POEMPenInfo;
{$EXTERNALSYM LPOEMPENINFO}

  PPenPacket = ^TPenPacket;
  tagPENPACKET = packed record
    wTabletX: UINT;             { x in raw coords }
    wTabletY: UINT;             { ditto y }
    wPDK: UINT;                 { state bits }
    rgwOemData: packed array[0..MAXOEMDATAWORDS-1] of UINT;{ OEM-specific data }
  end;
{$EXTERNALSYM tagPENPACKET}
  TPenPacket = tagPENPACKET;
  PENPACKET = tagPENPACKET;
{$EXTERNALSYM PENPACKET}
  LPPENPACKET = PPenPacket;
{$EXTERNALSYM LPPENPACKET}

  POEMPenPacket = ^TOEMPenPacket;
  tagOEMPENPACKET = packed record
    wTabletX: UINT;             { x in raw coords }
    wTabletY: UINT;             { ditto y }
    wPDK: UINT;                 { state bits }
    rgwOemData: packed array[0..MAXOEMDATAWORDS-1] of UINT;{ OEM-specific data }
    dwTime: DWORD;
  end;
{$EXTERNALSYM tagOEMPENPACKET}
  TOEMPenPacket = tagOEMPENPACKET;
  OEMPENPACKET = tagOEMPENPACKET;
{$EXTERNALSYM OEMPENPACKET}
  LPOEMPENPACKET = POEMPenPacket;
{$EXTERNALSYM LPOEMPENPACKET}

  PPenInfo = ^TPenInfo;
  tagPENINFO = packed record    { 1.0 pen/tablet hdwe info }
    cxRawWidth: UINT;           { max x coord and tablet width in 0.001" }
    cyRawHeight: UINT;          { ditto y, height }
    wDistinctWidth: UINT;       { number of distinct x values tablet ret }
    wDistinctHeight: UINT;      { ditto y }
    nSamplingRate: Integer;         { samples / second }
    nSamplingDist: Integer;         { min distance to move before generating event }
    lPdc: Longint;                 { Pen Device Capabilities }
    cPens: Integer;                 { number of pens supported }
    cbOemData: Integer;             { width of OEM data packet }
    rgoempeninfo: packed array[0..MAXOEMDATAWORDS-1] of TOEMPenInfo;{ supported OEM data types }
    rgwReserved: packed array[0..6] of UINT;{ for internal use }
    fuOEM: UINT;                { which OEM data, timing, PDK_xx to report }
  end;
{$EXTERNALSYM tagPENINFO}
  TPenInfo = tagPENINFO;
  PENINFO = tagPENINFO;
{$EXTERNALSYM PENINFO}
  LPPENINFO = PPenInfo;
{$EXTERNALSYM LPPENINFO}

  PCalbStruct = ^TCalbStruct;
  tagCALBSTRUCT = packed record { 1.0 pen calibration }
    wOffsetX: Integer;
    wOffsetY: Integer;
    wDistinctWidth: Integer;
    wDistinctHeight: Integer;
  end;
{$EXTERNALSYM tagCALBSTRUCT}
  TCalbStruct = tagCALBSTRUCT;
  CALBSTRUCT = tagCALBSTRUCT;
{$EXTERNALSYM CALBSTRUCT}
  LPCALBSTRUCT = PCalbStruct;
{$EXTERNALSYM LPCALBSTRUCT}

  LPFNRAWHOOK = function(PenPacket: PPenPacket): BOOL stdcall;
{$EXTERNALSYM LPFNRAWHOOK}
  TFNRawHook = LPFNRAWHOOK;

{ Handwriting Recognizer: }

type
  HRC = Integer;
{$EXTERNALSYM HRC}
  HRCRESULT = Integer;
{$EXTERNALSYM HRCRESULT}
  HWL = Integer;
{$EXTERNALSYM HWL}
  HRECHOOK = Integer;
{$EXTERNALSYM HRECHOOK}
  HINKSET = Integer;
{$EXTERNALSYM HINKSET}

  PHRC = ^HRC;
  LPHRC = PHRC;
{$EXTERNALSYM LPHRC}
  PHRCRESULT = ^HRCRESULT;
  LPHRCRESULT = PHRCRESULT;
{$EXTERNALSYM LPHRCRESULT}
  PHWL = ^HWL;
  LPHWL = PHWL;
{$EXTERNALSYM LPHWL}

  HRCRESULTHOOKPROC = function(p1: HREC; p2: HRC; p3, p4, p5: UINT;
    p6: Pointer): BOOL stdcall;
{$EXTERNALSYM HRCRESULTHOOKPROC}
  TFNHRCResultHookProc = HRCRESULTHOOKPROC;

{ Inksets: }

  LPHINKSET = ^HINKSET;                                    { ptr to HINKSET }
{$EXTERNALSYM LPHINKSET}

  PInterval = ^TInterval;
  tagINTERVAL = packed record   { 2.0 interval structure for inksets }
    atBegin: TAbsTime;           { begining of 1-ms granularity interval }
    atEnd: TAbsTime;             { 1 ms past end of interval }
  end;
{$EXTERNALSYM tagINTERVAL}
  TInterval = tagINTERVAL;
  INTERVAL = tagINTERVAL;
{$EXTERNALSYM INTERVAL}
  LPINTERVAL = PInterval;
{$EXTERNALSYM LPINTERVAL}

  PBoxResults = ^TBoxResults;
  tagBOXRESULTS = packed record { 2.0 }
    indxBox: UINT;
    hinksetBox: HINKSET;
    rgSyv: packed array[0..0] of SYV;
  end;
{$EXTERNALSYM tagBOXRESULTS}
  TBoxResults = tagBOXRESULTS;
  BOXRESULTS = tagBOXRESULTS;
{$EXTERNALSYM BOXRESULTS}
  LPBOXRESULTS = PBoxResults;
{$EXTERNALSYM LPBOXRESULTS}

  PGuide = ^TGuide;
  tagGUIDE = packed record      { 1.0 guide structure }
    xOrigin: Integer;               { left edge of first box (screen coord)) }
    yOrigin: Integer;               { ditto top edge }
    cxBox: Integer;                 { width of a single box }
    cyBox: Integer;                 { ditto height }
    cxBase: Integer;                { in-box x-margin to guideline }
    cyBase: Integer;                { in-box y offset from top to baseline }
    cHorzBox: Integer;              { count of boxed columns }
    cVertBox: Integer;              { ditto rows }
    cyMid: Integer;                 { 0 or distance from baseline to midline }
  end;
{$EXTERNALSYM tagGUIDE}
  TGuide = tagGUIDE;
  GUIDE = tagGUIDE;
{$EXTERNALSYM GUIDE}
  LPGUIDE = PGuide;
{$EXTERNALSYM LPGUIDE}

  PCtlInitIEdit = ^TCtlInitIEdit;
  tagCTLINITIEDIT = packed record { 2.0 init struct for Ink Edit }
    cbSize: DWORD;              { sizeof(CTLINITIEDIT) }
    hwnd: HWND;                 { IEdit window handle }
    id: Integer;                    { its ID }
    ieb: WORD;                  { IEB_* (background) bits }
    iedo: WORD;                 { IEDO_* (draw options) bits }
    iei: WORD;                  { IEI_* (ink input) bits }
    ien: WORD;                  { IEN_* (notification) bits }
    ierec: WORD;                { IEREC_* (recognition) bits }
    ies: WORD;                  { IES_* (style) bits }
    iesec: WORD;                { IESEC_* (security) bits }
    pdts: WORD;                 { initial pendata scale factor (PDTS_*) }
    hpndt: HPENDATA;            { initial pendata (or NULL if none) }
    hgdiobj: HGDIOBJ;           { background brush or bitmap handle }
    hpenGrid: HPEN;             { pen to use in drawing grid }
    ptOrgGrid: TPoint;          { grid lines point of origin }
    wVGrid: WORD;               { vertical gridline spacing }
    wHGrid: WORD;               { horizontal gridline spacing }
    dwApp: DWORD;               { application-defined data }
    dwReserved: DWORD;          { reserved for future use }
  end;
{$EXTERNALSYM tagCTLINITIEDIT}
  TCtlInitIEdit = tagCTLINITIEDIT;
  CTLINITIEDIT = tagCTLINITIEDIT;
{$EXTERNALSYM CTLINITIEDIT}
  LPCTLINITIEDIT = PCtlInitIEdit;
{$EXTERNALSYM LPCTLINITIEDIT}

  PPDEvent = ^TPDEvent;
  tagPDEVENT = packed record    { 2.0 }
    cbSize: DWORD;              { sizeof(PDEVENT) }
    hwnd: HWND;                 { window handle of I-Edit }
    wm: UINT;                   { WM_* (window message) of event }
    wParam: WPARAM;             { wParam of message }
    lParam: LPARAM;             { lParam of message }
    pt: TPoint;                  { event pt in I-Edit client co-ords }
    fPen: BOOL;                 { TRUE if pen (or other inking device) }
    lExInfo: Longint;              { GetMessageExtraInfo() return value }
    dwReserved: DWORD;          { for future use }
  end;
{$EXTERNALSYM tagPDEVENT}
  TPDEvent = tagPDEVENT;
  PDEVENT = tagPDEVENT;
{$EXTERNALSYM PDEVENT}
  LPPDEVENT = PPDEvent;
{$EXTERNALSYM LPPDEVENT}

  PStrkFmt = ^TStrkFmt;
  tagSTRKFMT = packed record    { 2.0 }
    cbSize: DWORD;              { sizeof(STRKFMT) }
    iesf: UINT;                 { stroke format flags and return bits }
    iStrk: UINT;                { stroke index if IESF_STROKE }
    tip: TPenTip;                { ink tip attributes }
    dwUser: DWORD;              { user data for strokes }
    dwReserved: DWORD;          { for future use }
  end;
{$EXTERNALSYM tagSTRKFMT}
  TStrkFmt = tagSTRKFMT;
  STRKFMT = tagSTRKFMT;
{$EXTERNALSYM STRKFMT}
  LPSTRKFMT = PStrkFmt;
{$EXTERNALSYM LPSTRKFMT}

  PPCMInfo = ^TPCMInfo;
  tagPCMINFO = packed record    { 2.0 Pen Collection Mode Information }
    cbSize: DWORD;              { sizeof(PCMINFO) }
    dwPcm: DWORD;               { PCM_xxx flags }
    rectBound: TRect;            { if finish on pendown outside this rect }
    rectExclude: TRect;          { if finish on pendown inside this rect }
    hrgnBound: HRGN;            { if finish on pendown outside this region }
    hrgnExclude: HRGN;          { if finish on pendown inside this region }
    dwTimeout: DWORD;           { if finish after timeout, this many ms }
  end;
{$EXTERNALSYM tagPCMINFO}
  TPCMInfo = tagPCMINFO;
  PCMINFO = tagPCMINFO;
{$EXTERNALSYM PCMINFO}
  LPPCMINFO = PPCMInfo;
{$EXTERNALSYM LPPCMINFO}

  PInkingInfo = ^TInkingInfo;
  tagINKINGINFO = packed record { 2.0 Pen Inking Information }
    cbSize: DWORD;              { sizeof(INKINGINFO) }
    wFlags: UINT;               { One of the PII_xx flags }
    tip: TPenTip;                { Pen type, size and color }
    rectClip: TRect;             { Clipping rect for the ink }
    rectInkStop: TRect;          { Rect in which a pen down stops inking }
    hrgnClip: HRGN;             { Clipping region for the ink }
    hrgnInkStop: HRGN;          { Region in which a pen down stops inking }
  end;
{$EXTERNALSYM tagINKINGINFO}
  TInkingInfo = tagINKINGINFO;
  INKINGINFO = tagINKINGINFO;
{$EXTERNALSYM INKINGINFO}
  LPINKINGINFO = PInkingInfo;
{$EXTERNALSYM LPINKINGINFO}

  PSYC = ^TSYC;
  tagSYC = packed record        { 1.0 Symbol Correspondence for Ink }
    wStrokeFirst: UINT;         { first stroke, inclusive }
    wPntFirst: UINT;            { first point in first stroke, inclusive }
    wStrokeLast: UINT;          { last stroke, inclusive }
    wPntLast: UINT;             { last point in last stroke, inclusive }
    fLastSyc: BOOL;             { T: no more SYCs follow for current SYE }
  end;
{$EXTERNALSYM tagSYC}
  TSYC = tagSYC;
  SYC = tagSYC;
{$EXTERNALSYM SYC}
  LPSYC = PSYC;
{$EXTERNALSYM LPSYC}

  PSYE = ^TSYE;
  tagSYE = packed record        { 1.0 Symbol Element }
    syv: SYV;                   { symbol value }
    lRecogVal: Longint;            { for internal use by recognizer }
    cl: CL;                     { confidence level }
    iSyc: Integer;                  { SYC index }
  end;
{$EXTERNALSYM tagSYE}
  TSYE = tagSYE;
  SYE = tagSYE;
{$EXTERNALSYM SYE}
  LPSYE = PSYE;
{$EXTERNALSYM LPSYE}

  PSYG = ^TSYG;
  tagSYG = packed record        { 1.0 Symbol Graph }
    rgpntHotSpots: packed array[0..MAXHOTSPOT-1] of TPoint;{ hot spots (max 8) }
    cHotSpot: Integer;              { number of valid hot spots in rgpntHotSpots }
    nFirstBox: Integer;             { row-major index to box of 1st char in result }
    lRecogVal: Longint;            { reserved for use by recoognizer }
    lpsye: PSYE;               { nodes of symbol graph }
    cSye: Integer;                  { number of SYEs in symbol graph }
    lpsyc: PSYC;               { ptr to corresp symbol ink }
    cSyc: Integer;                  { ditto count }
  end;
{$EXTERNALSYM tagSYG}
  TSYG = tagSYG;
  SYG = tagSYG;
{$EXTERNALSYM SYG}
  LPSYG = PSYG;
{$EXTERNALSYM LPSYG}

  PRC = ^TRC;
  tagRC = packed record         { 1.0 Recognition Context (RC) }
    hrec: HREC;                 { handle of recognizer to use }
    hwnd: HWND;                 { window to send results to }
    wEventRef: UINT;            { index into ink buffer }
    wRcPreferences: UINT;       { flags: RCP_xx Preferences }
    lRcOptions: Longint;           { RCO_xx options }
    lpfnYield: TFNRCYieldProc;     { procedure called during Yield() }
    lpUser: packed array[0..cbRcUserMax-1] of BYTE;{ current writer }
    wCountry: UINT;             { country code }
    wIntlPreferences: UINT;     { flags: RCIP_xx }
    lpLanguage: packed array[0..cbRcLanguageMax-1] of Char;{ language strings }
    rglpdf: packed array[0..MAXDICTIONARIES-1] of PFNLPDF;{ list of dictionary functions }
    wTryDictionary: UINT;       { max enumerations to search }
    clErrorLevel: CL;           { level where recognizer should reject input }
    alc: ALC;                   { enabled alphabet }
    alcPriority: ALC;           { prioritizes the ALC_ codes }
    rgbfAlc: packed array[0..cbRcrgbfAlcMax-1] of BYTE;{ bit field for enabled characters }
    wResultMode: UINT;          { RRM_xx when to send (asap or when complete) }
    wTimeOut: UINT;             { recognition timeout in ms }
    lPcm: Longint;                 { flags: PCM_xx for ending recognition }
    rectBound: TRect;            { bounding rect for inking (def:screen coords) }
    rectExclude: TRect;          { pen down inside this terminates recognition }
    guide: TGuide;               { struct: defines guidelines for recognizer }
    wRcOrient: UINT;            { RCOR_xx orientation of writing wrt tablet }
    wRcDirect: UINT;            { RCD_xx direction of writing }
    nInkWidth: Integer;             { ink width 0 (none) or 1..15 pixels }
    rgbInk: COLORREF;           { ink color }
    dwAppParam: DWORD;          { for application use }
    dwDictParam: DWORD;         { for app use to be passed on to dictionaries }
    dwRecognizer: DWORD;        { for app use to be passed on to recognizer }
    rgwReserved: packed array[0..cwRcReservedMax-1] of UINT;{ reserved for future use by Windows }
  end;
{$EXTERNALSYM tagRC}
  TRC = tagRC;
  RC = tagRC;
{$EXTERNALSYM RC}
  LPRC = PRC;
{$EXTERNALSYM LPRC}

  PRCResult = ^TRCResult;
  tagRCRESULT = packed record   { 1.0 Recognition Result }
    syg: TSYG;                   { symbol graph }
    wResultsType: UINT;         { see RCRT_xx }
    cSyv: Integer;                  { count of symbol values }
    lpsyv: PSYV;               { NULL-term ptr to recog's best guess }
    hSyv: THandle;               { globally-shared handle to lpsyv mem }
    nBaseLine: Integer;             { 0 or baseline of input writing }
    nMidLine: Integer;              { ditto midline }
    hpendata: HPENDATA;         { pen data mem }
    rectBoundInk: TRect;         { ink data bounds }
    pntEnd: TPoint;              { pt that terminated recog }
    lprc: PRC;                 { recog context used }
  end;
{$EXTERNALSYM tagRCRESULT}
  TRCResult = tagRCRESULT;
  RCRESULT = tagRCRESULT;
{$EXTERNALSYM RCRESULT}
  LPRCRESULT = PRCResult;
{$EXTERNALSYM LPRCRESULT}

  LPFUNCRESULTS = function(p1: PRCResult; p2: REC): Integer stdcall;
{$EXTERNALSYM LPFUNCRESULTS}
  TFNFuncResults = LPFUNCRESULTS;

  PTarget = ^TTarget;
  tagTARGET = packed record     { 2.0 Geometry for a single target. }
    dwFlags: DWORD;             { individual target flags }
    idTarget: DWORD;            { TARGINFO.rgTarget[] index }
    htrgTarget: HTRG;           { HANDLE32 equiv }
    rectBound: TRect;           { Bounding rect of the target }
    dwData: DWORD;              { data collection info per target }
    rectBoundInk: TRect;        { Reserved for internal use, must be zero }
    rectBoundLastInk: TRect;    { Reserved for internal use, must be zero }
  end;
{$EXTERNALSYM tagTARGET}
  TTarget = tagTARGET;
  TARGET = tagTARGET;
{$EXTERNALSYM TARGET}
  LPTARGET = PTarget;
{$EXTERNALSYM LPTARGET}

  PTargInfo = ^TTargInfo;
  tagTARGINFO = packed record   { 2.0 A set of targets }
    cbSize: DWORD;              { sizeof(TARGINFO) }
    dwFlags: DWORD;             { flags }
    htrgOwner: HTRG;            { HANDLE32 equiv }
    cTargets: WORD;             { count of targets }
    iTargetLast: WORD;          { last target, used by TargetPoints API }
{ if TPT_TEXTUAL flag is set }
    rgTarget: packed array[0..0] of TTarget;{ variable-length array of targets }
  end;
{$EXTERNALSYM tagTARGINFO}
  TTargInfo = tagTARGINFO;
  TARGINFO = tagTARGINFO;
{$EXTERNALSYM TARGINFO}
  LPTARGINFO = PTargInfo;
{$EXTERNALSYM LPTARGINFO}

  PInpParams = ^TInpParams;
  tagINPPARAMS = packed record  { 2.0 }
    cbSize: DWORD;              { sizeof(INPPARAMS) }
    dwFlags: DWORD;
    hpndt: HPENDATA;
    target: TTarget;             { target structure }
  end;
{$EXTERNALSYM tagINPPARAMS}
  TInpParams = tagINPPARAMS;
  INPPARAMS = tagINPPARAMS;
{$EXTERNALSYM INPPARAMS}
  LPINPPARAMS = PInpParams;
{$EXTERNALSYM LPINPPARAMS}

  PSKBInfo = ^TSKBInfo;
  tagSKBINFO = packed record
    handle: HWnd;
    nPad: Word;
    fVisible: Bool;
    fMinimized: Bool;
    hect: TRect;
    dwReserved: Longint;
  end;
{$EXTERNALSYM tagSKBINFO}
  TSKBInfo = tagSKBINFO;
  SKBINFO = tagSKBINFO;
{$EXTERNALSYM SKBINFO}
  LPSKBINFO = PSKBInfo;
{$EXTERNALSYM LPSKBINFO}

{ Utility Functions }

{ Misc }
function FPenUpX(X: Integer): BOOL;
{$EXTERNALSYM FPenUpX}
function GetWEventRef: Word;
{$EXTERNALSYM GetWEventRef}

{ ALC: }
function MpAlcB(lprc: PRC; i: Word): PByte;
{$EXTERNALSYM MpAlcB}
function MpIbf(i: Word): Byte;
{$EXTERNALSYM MpIbf}
procedure SetAlcBitAnsi(lprc: PRC; i: Word);
{$EXTERNALSYM SetAlcBitAnsi}
procedure ResetAlcBitAnsi(lprc: PRC; i: Word);
{$EXTERNALSYM ResetAlcBitAnsi}
function IsAlcBitAnsi(lprc: PRC; i: Word): Boolean;
{$EXTERNALSYM IsAlcBitAnsi}

{ draw 2.0 pendata using internal stroke formats: }
function DrawPenDataFmt(hdc: HDC; lprect: PRect; hpndt: THandle): Integer;
{$EXTERNALSYM DrawPenDataFmt}

{ Handwriting Recognizer: }

{ Intervals: }

{ difference of two absolute times (at2 > at1 for positive result): }
function dwDiffAT(at1, at2: TAbsTime): Integer;
{$EXTERNALSYM dwDiffAT}

{ comparison of two absolute times (TRUE if at1 < at2): }
function FLTAbsTime(at1, at2: TAbsTime): Boolean;
{$EXTERNALSYM FLTAbsTime}

function FLTEAbsTime(at1, at2: TAbsTime): Boolean;
{$EXTERNALSYM FLTEAbsTime}

function FEQAbsTime(at1, at2: TAbsTime): Boolean;
{$EXTERNALSYM FEQAbsTime}

{ test if abstime is within an interval: }
function FAbsTimeInInterval(at: TAbsTime; lpi: PInterval): Boolean;
{$EXTERNALSYM FAbsTimeInInterval}

{ test if interval (lpiT) is within an another interval (lpiS): }
function FIntervalInInterval(lpiT, lpiS: PInterval): Boolean;
{$EXTERNALSYM FIntervalInInterval}

{ test if interval (lpiT) intersects another interval (lpiS): }
function FIntervalXInterval(lpiT, lpiS: PInterval): Boolean;
{$EXTERNALSYM FIntervalXInterval}

{ duration of an PInterval in ms: }
function dwDurInterval(lpi: PInterval): Integer;
{$EXTERNALSYM dwDurInterval}

{ fill a pointer to an ABSTIME structure from a count of seconds and ms: }
procedure MakeAbsTime(var lpat: TAbsTime; sec, ms: Integer);
{$EXTERNALSYM MakeAbsTime}

{ SYV functions: }

function FIsSpecial(syv: DWORD): Boolean;
{$EXTERNALSYM FIsSpecial}
function FIsAnsi(syv: DWORD): Boolean;
{$EXTERNALSYM FIsAnsi}
function FIsGesture(syv: DWORD): Boolean;
{$EXTERNALSYM FIsGesture}
function FIsKanji(syv: DWORD): Boolean;
{$EXTERNALSYM FIsKanji}
function FIsShape(syv: DWORD): Boolean;
{$EXTERNALSYM FIsShape}
function FIsUniCode(syv: DWORD): Boolean;
{$EXTERNALSYM FIsUniCode}
function FIsVKey(syv: DWORD): Boolean;
{$EXTERNALSYM FIsVKey}

function ChSyvToAnsi(syv: DWORD): Byte;
{$EXTERNALSYM ChSyvToAnsi}
function WSyvToKanji(syv: DWORD): Word;
{$EXTERNALSYM WSyvToKanji}
function SyvCharacterToSymbol(c: Char): DWORD;
{$EXTERNALSYM SyvCharacterToSymbol}
function SyvKanjiToSymbol(c: Char): DWORD;
{$EXTERNALSYM SyvKanjiToSymbol}

function FIsSelectGesture(syv: DWORD): Boolean;
{$EXTERNALSYM FIsSelectGesture}
function FIsStdGesture(syv: DWORD): Boolean;
{$EXTERNALSYM FIsStdGesture}
function FIsAnsiGesture(syv: DWORD): Boolean;
{$EXTERNALSYM FIsAnsiGesture}

function SubPenMsgFromWpLp(wp, lp: DWORD): Word;
{$EXTERNALSYM SubPenMsgFromWpLp}
function EventRefFromWpLp(wp, lp: DWORD): Word;
{$EXTERNALSYM EventRefFromWpLp}
function TerminationFromWpLp(wp, lp: DWORD): Integer;
{$EXTERNALSYM TerminationFromWpLp}

function HwndFromHtrg(trg: HTRG): HWND;
{$EXTERNALSYM HwndFromHtrg}
function HpcmFromWpLp(wp, lp: DWORD): Integer;
{$EXTERNALSYM HpcmFromWpLp}
function HtrgFromHwnd(hwnd: HWND): HTRG;
{$EXTERNALSYM HtrgFromHwnd}

{ APIs and Prototypes }

{ PenData: }
function AddPointsPenData(p1: HPENDATA; p2: PPoint; p3: Pointer;
  p4: PStrokeInfo): HPENDATA; stdcall;
{$EXTERNALSYM AddPointsPenData}
function CompressPenData(p1: HPENDATA; p2: UINT; p3: DWORD): Integer; stdcall;
{$EXTERNALSYM CompressPenData}
function CreatePenDataEx(p1: PPenInfo; p2: UINT; p3: UINT;
  p4: UINT): HPENDATA; stdcall;
{$EXTERNALSYM CreatePenDataEx}
function CreatePenDataRegion(p1: HPENDATA; p2: UINT): HRGN; stdcall;
{$EXTERNALSYM CreatePenDataRegion}
function DestroyPenData(p1: HPENDATA): BOOL; stdcall;
{$EXTERNALSYM DestroyPenData}
function DrawPenDataEx(p1: HDC; p2: PRect; p3: HPENDATA; p4: UINT; p5: UINT;
  p6: UINT; p7: UINT; p8: TFNAnimateProc; p9: PAnimateInfo;
  p10: UINT): Integer; stdcall;
{$EXTERNALSYM DrawPenDataEx}
function DuplicatePenData(p1: HPENDATA; p2: UINT): HPENDATA; stdcall;
{$EXTERNALSYM DuplicatePenData}
function ExtractPenDataPoints(p1: HPENDATA; p2: UINT; p3: UINT; p4: UINT;
  p5: PPoint; p6: Pointer; p7: UINT): Integer; stdcall;
{$EXTERNALSYM ExtractPenDataPoints}
function ExtractPenDataStrokes(p1: HPENDATA; p2: UINT; p3: LPARAM;
  p4: PHPENDATA; p5: UINT): Integer; stdcall;
{$EXTERNALSYM ExtractPenDataStrokes}
function GetPenDataAttributes(p1: HPENDATA; p2: Pointer; p3: UINT): Integer; stdcall;
{$EXTERNALSYM GetPenDataAttributes}
function GetPenDataInfo(p1: HPENDATA; p2: PPENDATAHEADER; p3: PPenInfo;
  p4: DWORD): BOOL; stdcall;
{$EXTERNALSYM GetPenDataInfo}
function GetPointsFromPenData(p1: HPENDATA; p2: UINT; p3: UINT; p4: UINT;
  p5: PPoint): BOOL; stdcall;
{$EXTERNALSYM GetPointsFromPenData}
function GetStrokeAttributes(p1: HPENDATA; p2: UINT; p3: Pointer;
  p4: UINT): Integer; stdcall;
{$EXTERNALSYM GetStrokeAttributes}
function GetStrokeTableAttributes(p1: HPENDATA; p2: UINT; p3: Pointer;
  p4: UINT): Integer; stdcall;
{$EXTERNALSYM GetStrokeTableAttributes}
function HitTestPenData(p1: HPENDATA; p2: PPoint; p3: UINT; p4: PUINT;
  p5: PUINT): Integer; stdcall;
{$EXTERNALSYM HitTestPenData}
function InsertPenData(p1: HPENDATA; p2: HPENDATA; p3: UINT): Integer; stdcall;
{$EXTERNALSYM InsertPenData}
function InsertPenDataPoints(p1: HPENDATA; p2: UINT; p3: UINT; p4: UINT;
  p5: PPoint; p6: Pointer): Integer; stdcall;
{$EXTERNALSYM InsertPenDataPoints}
function InsertPenDataStroke(p1: HPENDATA; p2: UINT; p3: PPoint; p4: Pointer;
  p5: PStrokeInfo): Integer; stdcall;
{$EXTERNALSYM InsertPenDataStroke}
function MetricScalePenData(p1: HPENDATA; p2: UINT): BOOL; stdcall;
{$EXTERNALSYM MetricScalePenData}
function OffsetPenData(p1: HPENDATA; p2: Integer; p3: Integer): BOOL; stdcall;
{$EXTERNALSYM OffsetPenData}
function PenDataFromBuffer(p1: PHPENDATA; p2: UINT; p3: PByte; p4: Longint;
  p5: PDWORD): Longint; stdcall;
{$EXTERNALSYM PenDataFromBuffer}
function PenDataToBuffer(p1: HPENDATA; p2: PByte; p3: Longint;
  p4: PDWORD): Longint; stdcall;
{$EXTERNALSYM PenDataToBuffer}
function RedisplayPenData(p1: HDC; p2: HPENDATA; p3: PPoint; p4: PPoint;
  p5: Integer; p6: DWORD): BOOL; stdcall;
{$EXTERNALSYM RedisplayPenData}
function RemovePenDataStrokes(p1: HPENDATA; p2: UINT; p3: UINT): Integer; stdcall;
{$EXTERNALSYM RemovePenDataStrokes}
function ResizePenData(p1: HPENDATA; p2: PRect): BOOL; stdcall;
{$EXTERNALSYM ResizePenData}
function SetStrokeAttributes(p1: HPENDATA; p2: UINT; p3: LPARAM;
  p4: UINT): Integer; stdcall;
{$EXTERNALSYM SetStrokeAttributes}
function SetStrokeTableAttributes(p1: HPENDATA; p2: UINT; p3: LPARAM;
  p4: UINT): Integer; stdcall;
{$EXTERNALSYM SetStrokeTableAttributes}
function TrimPenData(p1: HPENDATA; p2: DWORD; p3: DWORD): Integer; stdcall;
{$EXTERNALSYM TrimPenData}

{ Pen Hardware/Driver: }
function GetPenAsyncState(p1: UINT): BOOL; stdcall;
{$EXTERNALSYM GetPenAsyncState}
function IsPenEvent(p1: UINT; p2: Longint): BOOL; stdcall;
{$EXTERNALSYM IsPenEvent}

{ Handwriting Recognizer: }
function AddPenDataHRC(p1: HRC; p2: HPENDATA): Integer; stdcall;
{$EXTERNALSYM AddPenDataHRC}
function AddPenInputHRC(p1: HRC; p2: PPoint; p3: Pointer; p4: UINT;
  p5: PStrokeInfo): Integer; stdcall;
{$EXTERNALSYM AddPenInputHRC}
function AddWordsHWL(p1: HWL; p2: LPSTR; p3: UINT): Integer; stdcall;
{$EXTERNALSYM AddWordsHWL}
function ConfigHREC(p1: HREC; p2: UINT; p3: WPARAM; p4: LPARAM): Integer; stdcall;
{$EXTERNALSYM ConfigHREC}
function CreateCompatibleHRC(p1: HRC; p2: HREC): HRC; stdcall;
{$EXTERNALSYM CreateCompatibleHRC}
function CreateHWL(p1: HREC; p2: LPSTR; p3: UINT; p4: DWORD): HWL; stdcall;
{$EXTERNALSYM CreateHWL}
function CreateInksetHRCRESULT(p1: HRCRESULT; p2: UINT;
  p3: UINT): HINKSET; stdcall;
{$EXTERNALSYM CreateInksetHRCRESULT}
function CreatePenDataHRC(p1: HRC): HPENDATA; stdcall;
{$EXTERNALSYM CreatePenDataHRC}
function DestroyHRC(p1: HRC): Integer; stdcall;
{$EXTERNALSYM DestroyHRC}
function DestroyHRCRESULT(p1: HRCRESULT): Integer; stdcall;
{$EXTERNALSYM DestroyHRCRESULT}
function DestroyHWL(p1: HWL): Integer; stdcall;
{$EXTERNALSYM DestroyHWL}
function EnableGestureSetHRC(p1: HRC; p2: SYV; p3: BOOL): Integer; stdcall;
{$EXTERNALSYM EnableGestureSetHRC}
function EnableSystemDictionaryHRC(p1: HRC; p2: BOOL): Integer; stdcall;
{$EXTERNALSYM EnableSystemDictionaryHRC}
function EndPenInputHRC(p1: HRC): Integer; stdcall;
{$EXTERNALSYM EndPenInputHRC}
function GetAlphabetHRC(p1: HRC; p2: PALC; p3: PByte): Integer; stdcall;
{$EXTERNALSYM GetAlphabetHRC}
function GetAlphabetPriorityHRC(p1: HRC; p2: PALC; p3: PByte): Integer; stdcall;
{$EXTERNALSYM GetAlphabetPriorityHRC}
function GetAlternateWordsHRCRESULT(p1: HRCRESULT; p2: UINT; p3: UINT;
  p4: PHRCRESULT; p5: UINT): Integer; stdcall;
{$EXTERNALSYM GetAlternateWordsHRCRESULT}
function GetBoxMappingHRCRESULT(p1: HRCRESULT; p2, p3: UINT;
  p4: PUINT): Integer; stdcall;
{$EXTERNALSYM GetBoxMappingHRCRESULT}
function GetBoxResultsHRC(p1: HRC; p2, p3, p4: UINT;
  p5: PBoxResults; p6: BOOL): Integer; stdcall;
{$EXTERNALSYM GetBoxResultsHRC}
function GetGuideHRC(p1: HRC; p2: PGuide; p3: PUINT): Integer; stdcall;
{$EXTERNALSYM GetGuideHRC}
function GetHotspotsHRCRESULT(p1: HRCRESULT; p2: UINT; p3: PPoint;
  p4: UINT): Integer; stdcall;
{$EXTERNALSYM GetHotspotsHRCRESULT}
function GetHRECFromHRC(p1: HRC): HREC; stdcall;
{$EXTERNALSYM GetHRECFromHRC}
function GetInternationalHRC(p1: HRC; p2: PUINT; p3: LPSTR; p4: PUINT;
  p5: PUINT): Integer; stdcall;
{$EXTERNALSYM GetInternationalHRC}
function GetMaxResultsHRC(p1: HRC): Integer; stdcall;
{$EXTERNALSYM GetMaxResultsHRC}
function GetResultsHRC(p1: HRC; p2: UINT; p3: PHRCRESULT;
  p4: UINT): Integer; stdcall;
{$EXTERNALSYM GetResultsHRC}
function GetSymbolCountHRCRESULT(p1: HRCRESULT): Integer; stdcall;
{$EXTERNALSYM GetSymbolCountHRCRESULT}
function GetSymbolsHRCRESULT(p1: HRCRESULT; p2: UINT; p3: PSYV;
  p4: UINT): Integer; stdcall;
{$EXTERNALSYM GetSymbolsHRCRESULT}
function GetWordlistHRC(p1: HRC; p2: PHWL): Integer; stdcall;
{$EXTERNALSYM GetWordlistHRC}
function GetWordlistCoercionHRC(p1: HRC): Integer; stdcall;
{$EXTERNALSYM GetWordlistCoercionHRC}
function ProcessHRC(p1: HRC; p2: DWORD): Integer; stdcall;
{$EXTERNALSYM ProcessHRC}
function ReadHWL(p1: HWL; p2: HFILE): Integer; stdcall;
{$EXTERNALSYM ReadHWL}
function SetAlphabetHRC(p1: HRC; p2: ALC; p3: PByte): Integer; stdcall;
{$EXTERNALSYM SetAlphabetHRC}
function SetAlphabetPriorityHRC(p1: HRC; p2: ALC; p3: PByte): Integer; stdcall;
{$EXTERNALSYM SetAlphabetPriorityHRC}
function SetBoxAlphabetHRC(p1: HRC; p2: PALC; p3: UINT): Integer; stdcall;
{$EXTERNALSYM SetBoxAlphabetHRC}
function SetGuideHRC(p1: HRC; p2: PGuide; p3: UINT): Integer; stdcall;
{$EXTERNALSYM SetGuideHRC}
function SetInternationalHRC(p1: HRC; p2: UINT; p3: LPCSTR; p4: UINT;
  p5: UINT): Integer; stdcall;
{$EXTERNALSYM SetInternationalHRC}
function SetMaxResultsHRC(p1: HRC; p2: UINT): Integer; stdcall;
{$EXTERNALSYM SetMaxResultsHRC}
function SetResultsHookHREC(p1: HREC; var p2: TFNHRCResultHookProc): HRECHOOK; stdcall;
{$EXTERNALSYM SetResultsHookHREC}
function SetWordlistCoercionHRC(p1: HRC; p2: UINT): Integer; stdcall;
{$EXTERNALSYM SetWordlistCoercionHRC}
function SetWordlistHRC(p1: HRC; p2: HWL): Integer; stdcall;
{$EXTERNALSYM SetWordlistHRC}
function TrainHREC(p1: HREC; p2: PSYV; p3: UINT; p4: HPENDATA;
  p5: UINT): Integer; stdcall;
{$EXTERNALSYM TrainHREC}
function UnhookResultsHookHREC(p1: HREC; p2: HRECHOOK): Integer; stdcall;
{$EXTERNALSYM UnhookResultsHookHREC}
function WriteHWL(p1: HWL; p2: HFILE): Integer; stdcall;
{$EXTERNALSYM WriteHWL}

{ Recognizer Installation: }
function InstallRecognizer(p1: LPSTR): HREC; stdcall;
{$EXTERNALSYM InstallRecognizer}
function UninstallRecognizer(p1: HREC): Pointer; stdcall;
{$EXTERNALSYM UninstallRecognizer}

{ Inksets: }
function AddInksetInterval(p1: HINKSET; p2: PInterval): BOOL; stdcall;
{$EXTERNALSYM AddInksetInterval}
function CreateInkset(p1: UINT): HINKSET; stdcall;
{$EXTERNALSYM CreateInkset}
function DestroyInkset(p1: HINKSET): BOOL; stdcall;
{$EXTERNALSYM DestroyInkset}
function GetInksetInterval(p1: HINKSET; p2: UINT; p3: PInterval): Integer; stdcall;
{$EXTERNALSYM GetInksetInterval}
function GetInksetIntervalCount(p1: HINKSET): Integer; stdcall;
{$EXTERNALSYM GetInksetIntervalCount}

{ Symbol Values: }
function CharacterToSymbol(p1: LPSTR; p2: Integer; p3: PSYV): Integer; stdcall;
{$EXTERNALSYM CharacterToSymbol}
function SymbolToCharacter(p1: PSYV; p2: Integer; p3: LPSTR;
  p4: PINT): BOOL; stdcall;
{$EXTERNALSYM SymbolToCharacter}

{ Pen Input/Inking: }
function DoDefaultPenInput(p1: HWND; p2: UINT): Integer; stdcall;
{$EXTERNALSYM DoDefaultPenInput}
function GetPenInput(p1: HPCM; p2: PPoint; p3: Pointer; p4: UINT; p5: UINT;
  p6: PStrokeInfo): Integer; stdcall;
{$EXTERNALSYM GetPenInput}
function PeekPenInput(p1: HPCM; p2: UINT; p3: PPoint; p4: Pointer;
  p5: UINT): Integer; stdcall;
{$EXTERNALSYM PeekPenInput}
function StartInking(p1: HPCM; p2: UINT; p3: PInkingInfo): Integer; stdcall;
{$EXTERNALSYM StartInking}
function StartPenInput(p1: HWND; p2: UINT; p3: PPCMInfo;
  p4: PINT): HPCM; stdcall;
{$EXTERNALSYM StartPenInput}
function StopInking(p1: HPCM): Integer; stdcall;
{$EXTERNALSYM StopInking}
function StopPenInput(p1: HPCM; p2: UINT; p3: Integer): Integer; stdcall;
{$EXTERNALSYM StopPenInput}

{ Miscellaneous/Utilities: }
function BoundingRectFromPoints(p1: PPoint; p2: UINT;
  p3: PRect): Pointer; stdcall;
{$EXTERNALSYM BoundingRectFromPoints}
function DPtoTP(p1: PPoint; p2: Integer): BOOL; stdcall;
{$EXTERNALSYM DPtoTP}
function GetPenAppFlags: UINT; stdcall;
{$EXTERNALSYM GetPenAppFlags}
function SetPenAppFlags(p1: UINT; p2: UINT): Pointer; stdcall;
{$EXTERNALSYM SetPenAppFlags}
function GetPenMiscInfo(p1: WPARAM; p2: LPARAM): Longint; stdcall;
{$EXTERNALSYM GetPenMiscInfo}
function GetVersionPenWin: UINT; stdcall;
{$EXTERNALSYM GetVersionPenWin}
function SetPenMiscInfo(p1: WPARAM; p2: LPARAM): Longint; stdcall;
{$EXTERNALSYM SetPenMiscInfo}
function TPtoDP(p1: PPoint; p2: Integer): BOOL; stdcall;
{$EXTERNALSYM TPtoDP}
function CorrectWriting(p1: HWND; p2: LPSTR; p3: UINT; p4: Pointer; p5: DWORD;
  p6: DWORD): BOOL; stdcall;
{$EXTERNALSYM CorrectWriting}

{ Ink Targeting: }
function TargetPoints(p1: PTargInfo; p2: PPoint; p3: DWORD; p4: UINT;
  p5: PStrokeInfo): Integer; stdcall;
{$EXTERNALSYM TargetPoints}

{ Kanji }
function KKConvert(hwndConvert: HWND; hwndCaller: HWND; lpBuf: LPSTR;
  cbBuf: UINT; lpPnt: PPoint): BOOL; stdcall;
{$EXTERNALSYM KKConvert}

implementation

const
  penwin32 = 'penwin32.dll';

function AddInksetInterval;             external penwin32 name 'AddInksetInterval';
function AddPenDataHRC;                 external penwin32 name 'AddPenDataHRC';
function AddPenInputHRC;                external penwin32 name 'AddPenInputHRC';
function AddPointsPenData;              external penwin32 name 'AddPointsPenData';
function AddWordsHWL;                   external penwin32 name 'AddWordsHWL';
function BoundingRectFromPoints;        external penwin32 name 'BoundingRectFromPoints';
function CharacterToSymbol;             external penwin32 name 'CharacterToSymbol';
function CompressPenData;               external penwin32 name 'CompressPenData';
function ConfigHREC;                    external penwin32 name 'ConfigHREC';
function CorrectWriting;                external penwin32 name 'CorrectWriting';
function CreateCompatibleHRC;           external penwin32 name 'CreateCompatibleHRC';
function CreateHWL;                     external penwin32 name 'CreateHWL';
function CreateInkset;                  external penwin32 name 'CreateInkset';
function CreateInksetHRCRESULT;         external penwin32 name 'CreateInksetHRCRESULT';
function CreatePenDataEx;               external penwin32 name 'CreatePenDataEx';
function CreatePenDataHRC;              external penwin32 name 'CreatePenDataHRC';
function CreatePenDataRegion;           external penwin32 name 'CreatePenDataRegion';
function DestroyHRC;                    external penwin32 name 'DestroyHRC';
function DestroyHRCRESULT;              external penwin32 name 'DestroyHRCRESULT';
function DestroyHWL;                    external penwin32 name 'DestroyHWL';
function DestroyInkset;                 external penwin32 name 'DestroyInkset';
function DestroyPenData;                external penwin32 name 'DestroyPenData';
function DoDefaultPenInput;             external penwin32 name 'DoDefaultPenInput';
function DPtoTP;                        external penwin32 name 'DPtoTP';
function DrawPenDataEx;                 external penwin32 name 'DrawPenDataEx';
function DuplicatePenData;              external penwin32 name 'DuplicatePenData';
function EnableGestureSetHRC;           external penwin32 name 'EnableGestureSetHRC';
function EnableSystemDictionaryHRC;     external penwin32 name 'EnableSystemDictionaryHRC';
function EndPenInputHRC;                external penwin32 name 'EndPenInputHRC';
function ExtractPenDataPoints;          external penwin32 name 'ExtractPenDataPoints';
function ExtractPenDataStrokes;         external penwin32 name 'ExtractPenDataStrokes';
function GetAlphabetHRC;                external penwin32 name 'GetAlphabetHRC';
function GetAlphabetPriorityHRC;        external penwin32 name 'GetAlphabetPriorityHRC';
function GetAlternateWordsHRCRESULT;    external penwin32 name 'GetAlternateWordsHRCRESULT';
function GetBoxMappingHRCRESULT;        external penwin32 name 'GetBoxMappingHRCRESULT';
function GetBoxResultsHRC;              external penwin32 name 'GetBoxResultsHRC';
function GetGuideHRC;                   external penwin32 name 'GetGuideHRC';
function GetHotspotsHRCRESULT;          external penwin32 name 'GetHotspotsHRCRESULT';
function GetHRECFromHRC;                external penwin32 name 'GetHRECFromHRC';
function GetInksetInterval;             external penwin32 name 'GetInksetInterval';
function GetInksetIntervalCount;        external penwin32 name 'GetInksetIntervalCount';
function GetInternationalHRC;           external penwin32 name 'GetInternationalHRC';
function GetMaxResultsHRC;              external penwin32 name 'GetMaxResultsHRC';
function GetPenAppFlags;                external penwin32 name 'GetPenAppFlags';
function GetPenAsyncState;              external penwin32 name 'GetPenAsyncState';
function GetPenDataAttributes;          external penwin32 name 'GetPenDataAttributes';
function GetPenDataInfo;                external penwin32 name 'GetPenDataInfo';
function GetPenInput;                   external penwin32 name 'GetPenInput';
function GetPenMiscInfo;                external penwin32 name 'GetPenMiscInfo';
function GetPointsFromPenData;          external penwin32 name 'GetPointsFromPenData';
function GetResultsHRC;                 external penwin32 name 'GetResultsHRC';
function GetStrokeAttributes;           external penwin32 name 'GetStrokeAttributes';
function GetStrokeTableAttributes;      external penwin32 name 'GetStrokeTableAttributes';
function GetSymbolCountHRCRESULT;       external penwin32 name 'GetSymbolCountHRCRESULT';
function GetSymbolsHRCRESULT;           external penwin32 name 'GetSymbolsHRCRESULT';
function GetVersionPenWin;              external penwin32 name 'GetVersionPenWin';
function GetWordlistCoercionHRC;        external penwin32 name 'GetWordlistCoercionHRC';
function GetWordlistHRC;                external penwin32 name 'GetWordlistHRC';
function HitTestPenData;                external penwin32 name 'HitTestPenData';
function InsertPenData;                 external penwin32 name 'InsertPenData';
function InsertPenDataPoints;           external penwin32 name 'InsertPenDataPoints';
function InsertPenDataStroke;           external penwin32 name 'InsertPenDataStroke';
function InstallRecognizer;             external penwin32 name 'InstallRecognizer';
function IsPenEvent;                    external penwin32 name 'IsPenEvent';
function KKConvert;                     external penwin32 name 'KKConvert';
function MetricScalePenData;            external penwin32 name 'MetricScalePenData';
function OffsetPenData;                 external penwin32 name 'OffsetPenData';
function PeekPenInput;                  external penwin32 name 'PeekPenInput';
function PenDataFromBuffer;             external penwin32 name 'PenDataFromBuffer';
function PenDataToBuffer;               external penwin32 name 'PenDataToBuffer';
function ProcessHRC;                    external penwin32 name 'ProcessHRC';
function ReadHWL;                       external penwin32 name 'ReadHWL';
function RedisplayPenData;              external penwin32 name 'RedisplayPenData';
function RemovePenDataStrokes;          external penwin32 name 'RemovePenDataStrokes';
function ResizePenData;                 external penwin32 name 'ResizePenData';
function SetAlphabetHRC;                external penwin32 name 'SetAlphabetHRC';
function SetAlphabetPriorityHRC;        external penwin32 name 'SetAlphabetPriorityHRC';
function SetBoxAlphabetHRC;             external penwin32 name 'SetBoxAlphabetHRC';
function SetGuideHRC;                   external penwin32 name 'SetGuideHRC';
function SetInternationalHRC;           external penwin32 name 'SetInternationalHRC';
function SetMaxResultsHRC;              external penwin32 name 'SetMaxResultsHRC';
function SetPenAppFlags;                external penwin32 name 'SetPenAppFlags';
function SetPenMiscInfo;                external penwin32 name 'SetPenMiscInfo';
function SetResultsHookHREC;            external penwin32 name 'SetResultsHookHREC';
function SetStrokeAttributes;           external penwin32 name 'SetStrokeAttributes';
function SetStrokeTableAttributes;      external penwin32 name 'SetStrokeTableAttributes';
function SetWordlistCoercionHRC;        external penwin32 name 'SetWordlistCoercionHRC';
function SetWordlistHRC;                external penwin32 name 'SetWordlistHRC';
function StartInking;                   external penwin32 name 'StartInking';
function StartPenInput;                 external penwin32 name 'StartPenInput';
function StopInking;                    external penwin32 name 'StopInking';
function StopPenInput;                  external penwin32 name 'StopPenInput';
function SymbolToCharacter;             external penwin32 name 'SymbolToCharacter';
function TargetPoints;                  external penwin32 name 'TargetPoints';
function TPtoDP;                        external penwin32 name 'TPtoDP';
function TrainHREC;                     external penwin32 name 'TrainHREC';
function TrimPenData;                   external penwin32 name 'TrimPenData';
function UnhookResultsHookHREC;         external penwin32 name 'UnhookResultsHookHREC';
function UninstallRecognizer;           external penwin32 name 'UninstallRecognizer';
function WriteHWL;                      external penwin32 name 'WriteHWL';

function FPenUpX(X: Integer): BOOL;
begin
  Result := (X and BITPENUP) <> 0;
end;

function GetWEventRef: Word;
begin
  Result := Word(GetMessageExtraInfo);
end;

function MpAlcB(lprc: PRC; i: Word): PByte;
begin
  Result := @lprc^.rgbfAlc[ (i and $FF) shr 3 ];
end;

function MpIbf(i: Word): Byte;
begin
  Result := 1 shl (i and 7);
end;

procedure SetAlcBitAnsi(lprc: PRC; i: Word);
var
  P: PByte;
begin
  P := MpAlcB(lprc, i);
  P^ := P^ or MpIbf(i);
end;

procedure ResetAlcBitAnsi(lprc: PRC; i: Word);
var
  P: PByte;
begin
  P := MpAlcB(lprc, i);
  P^ := P^ and not MpIbf(i);
end;

function IsAlcBitAnsi(lprc: PRC; i: Word): Boolean;
begin
  Result := MpAlcB(lprc,i)^ and MpIbf(i) <> 0;
end;

function DrawPenDataFmt(hdc: HDC; lprect: PRect; hpndt: THandle): Integer;
begin
  Result := DrawPenDataEx(hdc, lprect, hpndt, 0, IX_END, 0, IX_END, nil, nil, 0);
end;

function dwDiffAT(at1, at2: TAbsTime): Integer;
begin
  Result := 1000 * (at2.sec - at1.sec) - (at1.ms + at2.ms);
end;

function FLTAbsTime(at1, at2: TAbsTime): Boolean;
begin
  Result := (at1.sec < at2.sec) or ((at1.sec = at2.sec) and (at1.ms < at2.ms));
end;

function FLTEAbsTime(at1, at2: TAbsTime): Boolean;
begin
  Result := (at1.sec < at2.sec) or ((at1.sec = at2.sec) and (at1.ms <= at2.ms));
end;

function FEQAbsTime(at1, at2: TAbsTime): Boolean;
begin
  Result := (at1.sec = at2.sec) and (at1.ms = at2.ms);
end;

function FAbsTimeInInterval(at: TAbsTime; lpi: PInterval): Boolean;
begin
  Result := FLTEAbsTime(lpi^.atBegin, at) and FLTEAbsTime(at, lpi^.atEnd);
end;

function FIntervalInInterval(lpiT, lpiS: PInterval): Boolean;
begin
  Result := FLTEAbsTime(lpiS^.atBegin, lpiT^.atBegin) and
    FLTEAbsTime(lpiT^.atEnd, lpiS^.atEnd);
end;

function FIntervalXInterval(lpiT, lpiS: PInterval): Boolean;
begin
  Result := (not FLTAbsTime(lpiT^.atEnd, lpiS^.atBegin)) or
     FLTAbsTime(lpiS^.atEnd, lpiT^.atBegin);
end;

function dwDurInterval(lpi: PInterval): Integer;
begin
  Result := dwDiffAT(lpi^.atBegin, lpi^.atEnd);
end;

procedure MakeAbsTime(var lpat: TAbsTime; sec, ms: Integer);
begin
  lpat.sec := sec + ms div 1000;
  lpat.ms := ms mod 1000;
end;

function FIsSpecial(syv: DWORD): Boolean;
begin
  Result := HiWord(syv) = SYVHI_SPECIAL;
end;

function FIsAnsi(syv: DWORD): Boolean;
begin
  Result := HiWord(syv) = SYVHI_ANSI;
end;

function FIsGesture(syv: DWORD): Boolean;
begin
  Result := HiWord(syv) = SYVHI_GESTURE;
end;

function FIsKanji(syv: DWORD): Boolean;
begin
  Result := HiWord(syv) = SYVHI_KANJI;
end;

function FIsShape(syv: DWORD): Boolean;
begin
  Result := HiWord(syv) = SYVHI_SHAPE;
end;

function FIsUniCode(syv: DWORD): Boolean;
begin
  Result := HiWord(syv) = SYVHI_UNICODE;
end;

function FIsVKey(syv: DWORD): Boolean;
begin
  Result := HiWord(syv) = SYVHI_VKEY;
end;

function ChSyvToAnsi(syv: DWORD): Byte;
begin
  Result := Byte(LOWORD(syv));
end;

function WSyvToKanji(syv: DWORD): Word;
begin
  Result := LOWORD(syv);
end;

function SyvCharacterToSymbol(c: Char): DWORD;
begin
  Result := Byte(c) or $10000;
end;

function SyvKanjiToSymbol(c: Char): DWORD;
begin
  Result := Byte(c) or $30000;
end;

function FIsSelectGesture(syv: DWORD): Boolean;
begin
  Result := (syv >= SYV_SELECTFIRST) and (syv <= SYV_SELECTLAST);
end;

function FIsStdGesture(syv: DWORD): Boolean;
begin
  Result := FIsSelectGesture(syv) or (syv = SYV_CLEAR) or (syv = SYV_HELP) or
    (syv = SYV_EXTENDSELECT) or (syv = SYV_UNDO) or (syv = SYV_COPY) or
    (syv = SYV_CUT) or (syv = SYV_PASTE) or (syv = SYV_CLEARWORD) or
    (syv = SYV_KKCONVERT) or (syv = SYV_USER) or (syv = SYV_CORRECT);
end;

function FIsAnsiGesture(syv: DWORD): Boolean;
begin
  Result := (syv = SYV_BACKSPACE) or (syv = SYV_TAB) or
    (syv = SYV_RETURN) or (syv = SYV_SPACE);
end;

function SubPenMsgFromWpLp(wp, lp: DWORD): Word;
begin
  Result := LOWORD(wp);
end;

function EventRefFromWpLp(wp, lp: DWORD): Word;
begin
  Result := HiWord(wp);
end;

function TerminationFromWpLp(wp, lp: DWORD): Integer;
begin
  Result := HiWord(wp);
end;

function HpcmFromWpLp(wp, lp: DWORD): Integer;
begin
  Result := HPCM(lp);
end;

function HwndFromHtrg(trg: HTRG): HWND;
begin
  Result := HWND(trg);
end;

function HtrgFromHwnd(hwnd: HWND): HTRG;
begin
  Result := HTRG(hwnd);
end;

end.
