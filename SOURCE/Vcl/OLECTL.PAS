
{*******************************************************}
{                                                       }
{       Borland Delphi Runtime Library                  }
{       OLE Controls interface unit                     }
{                                                       }
{       Copyright (C) 1996,99 Inprise Corporation       }
{                                                       }
{*******************************************************}

unit OleCtl;

{$WEAKPACKAGEUNIT}

interface

(*$HPPEMIT '' *)
(*$HPPEMIT '#include <ocidl.h>' *)
(*$HPPEMIT '#include <olectl.h>' *)
(*$HPPEMIT '' *)

uses Windows, Messages, Ole2;

const

{ OLE control status codes }

  {$EXTERNALSYM CTL_E_ILLEGALFUNCTIONCALL}
  CTL_E_ILLEGALFUNCTIONCALL       = $800A0000 + 5;
  {$EXTERNALSYM CTL_E_OVERFLOW}
  CTL_E_OVERFLOW                  = $800A0000 + 6;
  {$EXTERNALSYM CTL_E_OUTOFMEMORY}
  CTL_E_OUTOFMEMORY               = $800A0000 + 7;
  {$EXTERNALSYM CTL_E_DIVISIONBYZERO}
  CTL_E_DIVISIONBYZERO            = $800A0000 + 11;
  {$EXTERNALSYM CTL_E_OUTOFSTRINGSPACE}
  CTL_E_OUTOFSTRINGSPACE          = $800A0000 + 14;
  {$EXTERNALSYM CTL_E_OUTOFSTACKSPACE}
  CTL_E_OUTOFSTACKSPACE           = $800A0000 + 28;
  {$EXTERNALSYM CTL_E_BADFILENAMEORNUMBER}
  CTL_E_BADFILENAMEORNUMBER       = $800A0000 + 52;
  {$EXTERNALSYM CTL_E_FILENOTFOUND}
  CTL_E_FILENOTFOUND              = $800A0000 + 53;
  {$EXTERNALSYM CTL_E_BADFILEMODE}
  CTL_E_BADFILEMODE               = $800A0000 + 54;
  {$EXTERNALSYM CTL_E_FILEALREADYOPEN}
  CTL_E_FILEALREADYOPEN           = $800A0000 + 55;
  {$EXTERNALSYM CTL_E_DEVICEIOERROR}
  CTL_E_DEVICEIOERROR             = $800A0000 + 57;
  {$EXTERNALSYM CTL_E_FILEALREADYEXISTS}
  CTL_E_FILEALREADYEXISTS         = $800A0000 + 58;
  {$EXTERNALSYM CTL_E_BADRECORDLENGTH}
  CTL_E_BADRECORDLENGTH           = $800A0000 + 59;
  {$EXTERNALSYM CTL_E_DISKFULL}
  CTL_E_DISKFULL                  = $800A0000 + 61;
  {$EXTERNALSYM CTL_E_BADRECORDNUMBER}
  CTL_E_BADRECORDNUMBER           = $800A0000 + 63;
  {$EXTERNALSYM CTL_E_BADFILENAME}
  CTL_E_BADFILENAME               = $800A0000 + 64;
  {$EXTERNALSYM CTL_E_TOOMANYFILES}
  CTL_E_TOOMANYFILES              = $800A0000 + 67;
  {$EXTERNALSYM CTL_E_DEVICEUNAVAILABLE}
  CTL_E_DEVICEUNAVAILABLE         = $800A0000 + 68;
  {$EXTERNALSYM CTL_E_PERMISSIONDENIED}
  CTL_E_PERMISSIONDENIED          = $800A0000 + 70;
  {$EXTERNALSYM CTL_E_DISKNOTREADY}
  CTL_E_DISKNOTREADY              = $800A0000 + 71;
  {$EXTERNALSYM CTL_E_PATHFILEACCESSERROR}
  CTL_E_PATHFILEACCESSERROR       = $800A0000 + 75;
  {$EXTERNALSYM CTL_E_PATHNOTFOUND}
  CTL_E_PATHNOTFOUND              = $800A0000 + 76;
  {$EXTERNALSYM CTL_E_INVALIDPATTERNSTRING}
  CTL_E_INVALIDPATTERNSTRING      = $800A0000 + 93;
  {$EXTERNALSYM CTL_E_INVALIDUSEOFNULL}
  CTL_E_INVALIDUSEOFNULL          = $800A0000 + 94;
  {$EXTERNALSYM CTL_E_INVALIDFILEFORMAT}
  CTL_E_INVALIDFILEFORMAT         = $800A0000 + 321;
  {$EXTERNALSYM CTL_E_INVALIDPROPERTYVALUE}
  CTL_E_INVALIDPROPERTYVALUE      = $800A0000 + 380;
  {$EXTERNALSYM CTL_E_INVALIDPROPERTYARRAYINDEX}
  CTL_E_INVALIDPROPERTYARRAYINDEX = $800A0000 + 381;
  {$EXTERNALSYM CTL_E_SETNOTSUPPORTEDATRUNTIME}
  CTL_E_SETNOTSUPPORTEDATRUNTIME  = $800A0000 + 382;
  {$EXTERNALSYM CTL_E_SETNOTSUPPORTED}
  CTL_E_SETNOTSUPPORTED           = $800A0000 + 383;
  {$EXTERNALSYM CTL_E_NEEDPROPERTYARRAYINDEX}
  CTL_E_NEEDPROPERTYARRAYINDEX    = $800A0000 + 385;
  {$EXTERNALSYM CTL_E_SETNOTPERMITTED}
  CTL_E_SETNOTPERMITTED           = $800A0000 + 387;
  {$EXTERNALSYM CTL_E_GETNOTSUPPORTEDATRUNTIME}
  CTL_E_GETNOTSUPPORTEDATRUNTIME  = $800A0000 + 393;
  {$EXTERNALSYM CTL_E_GETNOTSUPPORTED}
  CTL_E_GETNOTSUPPORTED           = $800A0000 + 394;
  {$EXTERNALSYM CTL_E_PROPERTYNOTFOUND}
  CTL_E_PROPERTYNOTFOUND          = $800A0000 + 422;
  {$EXTERNALSYM CTL_E_INVALIDCLIPBOARDFORMAT}
  CTL_E_INVALIDCLIPBOARDFORMAT    = $800A0000 + 460;
  {$EXTERNALSYM CTL_E_INVALIDPICTURE}
  CTL_E_INVALIDPICTURE            = $800A0000 + 481;
  {$EXTERNALSYM CTL_E_PRINTERERROR}
  CTL_E_PRINTERERROR              = $800A0000 + 482;
  {$EXTERNALSYM CTL_E_CANTSAVEFILETOTEMP}
  CTL_E_CANTSAVEFILETOTEMP        = $800A0000 + 735;
  {$EXTERNALSYM CTL_E_SEARCHTEXTNOTFOUND}
  CTL_E_SEARCHTEXTNOTFOUND        = $800A0000 + 744;
  {$EXTERNALSYM CTL_E_REPLACEMENTSTOOLONG}
  CTL_E_REPLACEMENTSTOOLONG       = $800A0000 + 746;

  {$EXTERNALSYM CTL_E_CUSTOM_FIRST}
  CTL_E_CUSTOM_FIRST = $800A0000 + 600;

{ IClassFactory2 status codes }

  {$EXTERNALSYM CLASS_E_NOTLICENSED}
  CLASS_E_NOTLICENSED = CLASSFACTORY_E_FIRST + 2;

{ IConnectionPoint status codes }

  {$EXTERNALSYM CONNECT_E_FIRST}
  CONNECT_E_FIRST = $80040200;
  {$EXTERNALSYM CONNECT_E_LAST}
  CONNECT_E_LAST  = $8004020F;
  {$EXTERNALSYM CONNECT_S_FIRST}
  CONNECT_S_FIRST = $00040200;
  {$EXTERNALSYM CONNECT_S_LAST}
  CONNECT_S_LAST  = $0004020F;

  {$EXTERNALSYM CONNECT_E_NOCONNECTION}
  CONNECT_E_NOCONNECTION  = CONNECT_E_FIRST + 0;
  {$EXTERNALSYM CONNECT_E_ADVISELIMIT}
  CONNECT_E_ADVISELIMIT   = CONNECT_E_FIRST + 1;
  {$EXTERNALSYM CONNECT_E_CANNOTCONNECT}
  CONNECT_E_CANNOTCONNECT = CONNECT_E_FIRST + 2;
  {$EXTERNALSYM CONNECT_E_OVERRIDDEN}
  CONNECT_E_OVERRIDDEN    = CONNECT_E_FIRST + 3;

{ DllRegisterServer/DllUnregisterServer status codes }

  {$EXTERNALSYM SELFREG_E_FIRST}
  SELFREG_E_FIRST = $80040200;
  {$EXTERNALSYM SELFREG_E_LAST}
  SELFREG_E_LAST  = $80040200;
  {$EXTERNALSYM SELFREG_S_FIRST}
  SELFREG_S_FIRST = $00040200;
  {$EXTERNALSYM SELFREG_S_LAST}
  SELFREG_S_LAST  = $00040200;

  {$EXTERNALSYM SELFREG_E_TYPELIB}
  SELFREG_E_TYPELIB = SELFREG_E_FIRST + 0;
  {$EXTERNALSYM SELFREG_E_CLASS}
  SELFREG_E_CLASS   = SELFREG_E_FIRST + 1;

{ IPerPropertyBrowsing status codes }

  {$EXTERNALSYM PERPROP_E_FIRST}
  PERPROP_E_FIRST = $80040200;
  {$EXTERNALSYM PERPROP_E_LAST}
  PERPROP_E_LAST  = $8004020F;
  {$EXTERNALSYM PERPROP_S_FIRST}
  PERPROP_S_FIRST = $00040200;
  {$EXTERNALSYM PERPROP_S_LAST}
  PERPROP_S_LAST  = $0004020F;

  {$EXTERNALSYM PERPROP_E_NOPAGEAVAILABLE}
  PERPROP_E_NOPAGEAVAILABLE = PERPROP_E_FIRST + 0;

{ Additional OLEMISC constants }

  {$EXTERNALSYM OLEMISC_INVISIBLEATRUNTIME}
  OLEMISC_INVISIBLEATRUNTIME = $00000400;
  {$EXTERNALSYM OLEMISC_ALWAYSRUN}
  OLEMISC_ALWAYSRUN          = $00000800;
  {$EXTERNALSYM OLEMISC_ACTSLIKEBUTTON}
  OLEMISC_ACTSLIKEBUTTON     = $00001000;
  {$EXTERNALSYM OLEMISC_ACTSLIKELABEL}
  OLEMISC_ACTSLIKELABEL      = $00002000;
  {$EXTERNALSYM OLEMISC_NOUIACTIVATE}
  OLEMISC_NOUIACTIVATE       = $00004000;
  {$EXTERNALSYM OLEMISC_ALIGNABLE}
  OLEMISC_ALIGNABLE          = $00008000;
  {$EXTERNALSYM OLEMISC_SIMPLEFRAME}
  OLEMISC_SIMPLEFRAME        = $00010000;
  {$EXTERNALSYM OLEMISC_SETCLIENTSITEFIRST}
  OLEMISC_SETCLIENTSITEFIRST = $00020000;
  {$EXTERNALSYM OLEMISC_IMEMODE}
  OLEMISC_IMEMODE            = $00040000;

{ Additional OLEIVERB constants }

  {$EXTERNALSYM OLEIVERB_PROPERTIES}
  OLEIVERB_PROPERTIES = -7;

{ Additional variant type tags for property sets }

  {$EXTERNALSYM VT_STREAMED_PROPSET}
  VT_STREAMED_PROPSET = 73;  { Stream contains a property set }
  {$EXTERNALSYM VT_STORED_PROPSET}
  VT_STORED_PROPSET   = 74;  { Storage contains a property set }
  {$EXTERNALSYM VT_BLOB_PROPSET}
  VT_BLOB_PROPSET     = 75;  { Blob contains a property set }

{ Variant type tags that are just aliases for others }

  {$EXTERNALSYM VT_COLOR}
  VT_COLOR          = VT_I4;
  {$EXTERNALSYM VT_XPOS_PIXELS}
  VT_XPOS_PIXELS    = VT_I4;
  {$EXTERNALSYM VT_YPOS_PIXELS}
  VT_YPOS_PIXELS    = VT_I4;
  {$EXTERNALSYM VT_XSIZE_PIXELS}
  VT_XSIZE_PIXELS   = VT_I4;
  {$EXTERNALSYM VT_YSIZE_PIXELS}
  VT_YSIZE_PIXELS   = VT_I4;
  {$EXTERNALSYM VT_XPOS_HIMETRIC}
  VT_XPOS_HIMETRIC  = VT_I4;
  {$EXTERNALSYM VT_YPOS_HIMETRIC}
  VT_YPOS_HIMETRIC  = VT_I4;
  {$EXTERNALSYM VT_XSIZE_HIMETRIC}
  VT_XSIZE_HIMETRIC = VT_I4;
  {$EXTERNALSYM VT_YSIZE_HIMETRIC}
  VT_YSIZE_HIMETRIC = VT_I4;
  {$EXTERNALSYM VT_TRISTATE}
  VT_TRISTATE       = VT_I2;
  {$EXTERNALSYM VT_OPTEXCLUSIVE}
  VT_OPTEXCLUSIVE   = VT_BOOL;
  {$EXTERNALSYM VT_FONT}
  VT_FONT           = VT_DISPATCH;
  {$EXTERNALSYM VT_PICTURE}
  VT_PICTURE        = VT_DISPATCH;
  {$EXTERNALSYM VT_HANDLE}
  VT_HANDLE         = VT_I4;

{ Reflected window message IDs }

  {$EXTERNALSYM OCM__BASE}
  OCM__BASE = WM_USER + $1C00;

  {$EXTERNALSYM OCM_COMMAND}
  OCM_COMMAND           = OCM__BASE + WM_COMMAND;
  {$EXTERNALSYM OCM_CTLCOLORBTN}
  OCM_CTLCOLORBTN       = OCM__BASE + WM_CTLCOLORBTN;
  {$EXTERNALSYM OCM_CTLCOLOREDIT}
  OCM_CTLCOLOREDIT      = OCM__BASE + WM_CTLCOLOREDIT;
  {$EXTERNALSYM OCM_CTLCOLORDLG}
  OCM_CTLCOLORDLG       = OCM__BASE + WM_CTLCOLORDLG;
  {$EXTERNALSYM OCM_CTLCOLORLISTBOX}
  OCM_CTLCOLORLISTBOX   = OCM__BASE + WM_CTLCOLORLISTBOX;
  {$EXTERNALSYM OCM_CTLCOLORMSGBOX}
  OCM_CTLCOLORMSGBOX    = OCM__BASE + WM_CTLCOLORMSGBOX;
  {$EXTERNALSYM OCM_CTLCOLORSCROLLBAR}
  OCM_CTLCOLORSCROLLBAR = OCM__BASE + WM_CTLCOLORSCROLLBAR;
  {$EXTERNALSYM OCM_CTLCOLORSTATIC}
  OCM_CTLCOLORSTATIC    = OCM__BASE + WM_CTLCOLORSTATIC;
  {$EXTERNALSYM OCM_DRAWITEM}
  OCM_DRAWITEM          = OCM__BASE + WM_DRAWITEM;
  {$EXTERNALSYM OCM_MEASUREITEM}
  OCM_MEASUREITEM       = OCM__BASE + WM_MEASUREITEM;
  {$EXTERNALSYM OCM_DELETEITEM}
  OCM_DELETEITEM        = OCM__BASE + WM_DELETEITEM;
  {$EXTERNALSYM OCM_VKEYTOITEM}
  OCM_VKEYTOITEM        = OCM__BASE + WM_VKEYTOITEM;
  {$EXTERNALSYM OCM_CHARTOITEM}
  OCM_CHARTOITEM        = OCM__BASE + WM_CHARTOITEM;
  {$EXTERNALSYM OCM_COMPAREITEM}
  OCM_COMPAREITEM       = OCM__BASE + WM_COMPAREITEM;
  {$EXTERNALSYM OCM_HSCROLL}
  OCM_HSCROLL           = OCM__BASE + WM_HSCROLL;
  {$EXTERNALSYM OCM_VSCROLL}
  OCM_VSCROLL           = OCM__BASE + WM_VSCROLL;
  {$EXTERNALSYM OCM_PARENTNOTIFY}
  OCM_PARENTNOTIFY      = OCM__BASE + WM_PARENTNOTIFY;

{ TControlInfo.dwFlags masks }

  {$EXTERNALSYM CTRLINFO_EATS_RETURN}
  CTRLINFO_EATS_RETURN = 1;  { Control doesn't send Return to container }
  {$EXTERNALSYM CTRLINFO_EATS_ESCAPE}
  CTRLINFO_EATS_ESCAPE = 2;  { Control doesn't send Escape to container }

{ IOleControlSite.TransformCoords flags }

  {$EXTERNALSYM XFORMCOORDS_POSITION}
  XFORMCOORDS_POSITION            = 1;
  {$EXTERNALSYM XFORMCOORDS_SIZE}
  XFORMCOORDS_SIZE                = 2;
  {$EXTERNALSYM XFORMCOORDS_HIMETRICTOCONTAINER}
  XFORMCOORDS_HIMETRICTOCONTAINER = 4;
  {$EXTERNALSYM XFORMCOORDS_CONTAINERTOHIMETRIC}
  XFORMCOORDS_CONTAINERTOHIMETRIC = 8;

{ IPropertyPageSite.OnStatusChange flags }

  {$EXTERNALSYM PROPPAGESTATUS_DIRTY}
  PROPPAGESTATUS_DIRTY    = 1;  { Values in page have changed }
  {$EXTERNALSYM PROPPAGESTATUS_VALIDATE}
  PROPPAGESTATUS_VALIDATE = 2;  { Appropriate time to validate/apply }

{ Picture attributes }

  {$EXTERNALSYM PICTURE_SCALABLE}
  PICTURE_SCALABLE    = 1;
  {$EXTERNALSYM PICTURE_TRANSPARENT}
  PICTURE_TRANSPARENT = 2;

{ TPictDesc.picType values }

  {$EXTERNALSYM PICTYPE_UNINITIALIZED}
  PICTYPE_UNINITIALIZED = -1;
  {$EXTERNALSYM PICTYPE_NONE}
  PICTYPE_NONE          = 0;
  {$EXTERNALSYM PICTYPE_BITMAP}
  PICTYPE_BITMAP        = 1;
  {$EXTERNALSYM PICTYPE_METAFILE}
  PICTYPE_METAFILE      = 2;
  {$EXTERNALSYM PICTYPE_ICON}
  PICTYPE_ICON          = 3;
  {$EXTERNALSYM PICTYPE_ENHMETAFILE}
  PICTYPE_ENHMETAFILE   = 4;

{ Standard dispatch ID constants }

  {$EXTERNALSYM DISPID_AUTOSIZE}
  DISPID_AUTOSIZE      = -500;
  {$EXTERNALSYM DISPID_BACKCOLOR}
  DISPID_BACKCOLOR     = -501;
  {$EXTERNALSYM DISPID_BACKSTYLE}
  DISPID_BACKSTYLE     = -502;
  {$EXTERNALSYM DISPID_BORDERCOLOR}
  DISPID_BORDERCOLOR   = -503;
  {$EXTERNALSYM DISPID_BORDERSTYLE}
  DISPID_BORDERSTYLE   = -504;
  {$EXTERNALSYM DISPID_BORDERWIDTH}
  DISPID_BORDERWIDTH   = -505;
  {$EXTERNALSYM DISPID_DRAWMODE}
  DISPID_DRAWMODE      = -507;
  {$EXTERNALSYM DISPID_DRAWSTYLE}
  DISPID_DRAWSTYLE     = -508;
  {$EXTERNALSYM DISPID_DRAWWIDTH}
  DISPID_DRAWWIDTH     = -509;
  {$EXTERNALSYM DISPID_FILLCOLOR}
  DISPID_FILLCOLOR     = -510;
  {$EXTERNALSYM DISPID_FILLSTYLE}
  DISPID_FILLSTYLE     = -511;
  {$EXTERNALSYM DISPID_FONT}
  DISPID_FONT          = -512;
  {$EXTERNALSYM DISPID_FORECOLOR}
  DISPID_FORECOLOR     = -513;
  {$EXTERNALSYM DISPID_ENABLED}
  DISPID_ENABLED       = -514;
  {$EXTERNALSYM DISPID_HWND}
  DISPID_HWND          = -515;
  {$EXTERNALSYM DISPID_TABSTOP}
  DISPID_TABSTOP       = -516;
  {$EXTERNALSYM DISPID_TEXT}
  DISPID_TEXT          = -517;
  {$EXTERNALSYM DISPID_CAPTION}
  DISPID_CAPTION       = -518;
  {$EXTERNALSYM DISPID_BORDERVISIBLE}
  DISPID_BORDERVISIBLE = -519;

  {$EXTERNALSYM DISPID_REFRESH}
  DISPID_REFRESH  = -550;
  {$EXTERNALSYM DISPID_DOCLICK}
  DISPID_DOCLICK  = -551;
  {$EXTERNALSYM DISPID_ABOUTBOX}
  DISPID_ABOUTBOX = -552;

  {$EXTERNALSYM DISPID_CLICK}
  DISPID_CLICK      = -600;
  {$EXTERNALSYM DISPID_DBLCLICK}
  DISPID_DBLCLICK   = -601;
  {$EXTERNALSYM DISPID_KEYDOWN}
  DISPID_KEYDOWN    = -602;
  {$EXTERNALSYM DISPID_KEYPRESS}
  DISPID_KEYPRESS   = -603;
  {$EXTERNALSYM DISPID_KEYUP}
  DISPID_KEYUP      = -604;
  {$EXTERNALSYM DISPID_MOUSEDOWN}
  DISPID_MOUSEDOWN  = -605;
  {$EXTERNALSYM DISPID_MOUSEMOVE}
  DISPID_MOUSEMOVE  = -606;
  {$EXTERNALSYM DISPID_MOUSEUP}
  DISPID_MOUSEUP    = -607;
  {$EXTERNALSYM DISPID_ERROREVENT}
  DISPID_ERROREVENT = -608;

  {$EXTERNALSYM DISPID_AMBIENT_BACKCOLOR}
  DISPID_AMBIENT_BACKCOLOR         = -701;
  {$EXTERNALSYM DISPID_AMBIENT_DISPLAYNAME}
  DISPID_AMBIENT_DISPLAYNAME       = -702;
  {$EXTERNALSYM DISPID_AMBIENT_FONT}
  DISPID_AMBIENT_FONT              = -703;
  {$EXTERNALSYM DISPID_AMBIENT_FORECOLOR}
  DISPID_AMBIENT_FORECOLOR         = -704;
  {$EXTERNALSYM DISPID_AMBIENT_LOCALEID}
  DISPID_AMBIENT_LOCALEID          = -705;
  {$EXTERNALSYM DISPID_AMBIENT_MESSAGEREFLECT}
  DISPID_AMBIENT_MESSAGEREFLECT    = -706;
  {$EXTERNALSYM DISPID_AMBIENT_SCALEUNITS}
  DISPID_AMBIENT_SCALEUNITS        = -707;
  {$EXTERNALSYM DISPID_AMBIENT_TEXTALIGN}
  DISPID_AMBIENT_TEXTALIGN         = -708;
  {$EXTERNALSYM DISPID_AMBIENT_USERMODE}
  DISPID_AMBIENT_USERMODE          = -709;
  {$EXTERNALSYM DISPID_AMBIENT_UIDEAD}
  DISPID_AMBIENT_UIDEAD            = -710;
  {$EXTERNALSYM DISPID_AMBIENT_SHOWGRABHANDLES}
  DISPID_AMBIENT_SHOWGRABHANDLES   = -711;
  {$EXTERNALSYM DISPID_AMBIENT_SHOWHATCHING}
  DISPID_AMBIENT_SHOWHATCHING      = -712;
  {$EXTERNALSYM DISPID_AMBIENT_DISPLAYASDEFAULT}
  DISPID_AMBIENT_DISPLAYASDEFAULT  = -713;
  {$EXTERNALSYM DISPID_AMBIENT_SUPPORTSMNEMONICS}
  DISPID_AMBIENT_SUPPORTSMNEMONICS = -714;
  {$EXTERNALSYM DISPID_AMBIENT_AUTOCLIP}
  DISPID_AMBIENT_AUTOCLIP          = -715;

{ Dispatch ID constants for fonts }

  {$EXTERNALSYM DISPID_FONT_NAME}
  DISPID_FONT_NAME    = 0;
  {$EXTERNALSYM DISPID_FONT_SIZE}
  DISPID_FONT_SIZE    = 2;
  {$EXTERNALSYM DISPID_FONT_BOLD}
  DISPID_FONT_BOLD    = 3;
  {$EXTERNALSYM DISPID_FONT_ITALIC}
  DISPID_FONT_ITALIC  = 4;
  {$EXTERNALSYM DISPID_FONT_UNDER}
  DISPID_FONT_UNDER   = 5;
  {$EXTERNALSYM DISPID_FONT_STRIKE}
  DISPID_FONT_STRIKE  = 6;
  {$EXTERNALSYM DISPID_FONT_WEIGHT}
  DISPID_FONT_WEIGHT  = 7;
  {$EXTERNALSYM DISPID_FONT_CHARSET}
  DISPID_FONT_CHARSET = 8;

{ Dispatch ID constants for pictures }

  {$EXTERNALSYM DISPID_PICT_HANDLE}
  DISPID_PICT_HANDLE = 0;
  {$EXTERNALSYM DISPID_PICT_HPAL}
  DISPID_PICT_HPAL   = 2;
  {$EXTERNALSYM DISPID_PICT_TYPE}
  DISPID_PICT_TYPE   = 3;
  {$EXTERNALSYM DISPID_PICT_WIDTH}
  DISPID_PICT_WIDTH  = 4;
  {$EXTERNALSYM DISPID_PICT_HEIGHT}
  DISPID_PICT_HEIGHT = 5;
  {$EXTERNALSYM DISPID_PICT_RENDER}
  DISPID_PICT_RENDER = 6;

type

  PTextMetricOle = PTextMetricW;
  TTextMetricOle = TTextMetricW;

  TOleColor = Longint;

  {$EXTERNALSYM OLE_XPOS_PIXELS}
  OLE_XPOS_PIXELS  = Longint;
  {$EXTERNALSYM OLE_YPOS_PIXELS}
  OLE_YPOS_PIXELS  = Longint;
  {$EXTERNALSYM OLE_XSIZE_PIXELS}
  OLE_XSIZE_PIXELS = Longint;
  {$EXTERNALSYM OLE_YSIZE_PIXELS}
  OLE_YSIZE_PIXELS = Longint;

  {$EXTERNALSYM OLE_XPOS_HIMETRIC}
  OLE_XPOS_HIMETRIC  = Longint;
  {$EXTERNALSYM OLE_YPOS_HIMETRIC}
  OLE_YPOS_HIMETRIC  = Longint;
  {$EXTERNALSYM OLE_XSIZE_HIMETRIC}
  OLE_XSIZE_HIMETRIC = Longint;
  {$EXTERNALSYM OLE_YSIZE_HIMETRIC}
  OLE_YSIZE_HIMETRIC = Longint;

  {$EXTERNALSYM OLE_XPOS_CONTAINER}
  OLE_XPOS_CONTAINER  = Single;
  {$EXTERNALSYM OLE_YPOS_CONTAINER}
  OLE_YPOS_CONTAINER  = Single;
  {$EXTERNALSYM OLE_XSIZE_CONTAINER}
  OLE_XSIZE_CONTAINER = Single;
  {$EXTERNALSYM OLE_YSIZE_CONTAINER}
  OLE_YSIZE_CONTAINER = Single;

  OLE_TRISTATE = (triUnchecked, triChecked, triGray);

  {$EXTERNALSYM OLE_OPTEXCLUSIVE}
  OLE_OPTEXCLUSIVE = Bool;

  {$EXTERNALSYM OLE_CANCELBOOL}
  OLE_CANCELBOOL = Bool;

  {$EXTERNALSYM OLE_ENABLEDEFAULTBOOL}
  OLE_ENABLEDEFAULTBOOL = Bool;

  {$EXTERNALSYM OLE_HANDLE}
  OLE_HANDLE = Longint;

{ Registration function types }

  TDLLRegisterServer = function: HResult stdcall;
  TDLLUnregisterServer = function: HResult stdcall;

{ TPointF structure }

  PPointF = ^TPointF;
  {$EXTERNALSYM tagPOINTFX}
  tagPOINTFX = record
    x: Single;
    y: Single;
  end;
  TPointF = tagPOINTFX;
  {$EXTERNALSYM POINTF}
  POINTF = tagPOINTFX;

{ TControlInfo structure }

  PControlInfo = ^TControlInfo;
  {$EXTERNALSYM tagCONTROLINFO}
  tagCONTROLINFO = record
    cb: Longint;
    hAccel: HAccel;
    cAccel: Word;
    dwFlags: Longint;
  end;
  TControlInfo = tagCONTROLINFO;
  {$EXTERNALSYM CONTROLINFO}
  CONTROLINFO = tagCONTROLINFO;

{ Forward declarations }

  {$EXTERNALSYM IOleControl}
  IOleControl = class;
  {$EXTERNALSYM IOleControlSite}
  IOleControlSite = class;
  {$EXTERNALSYM ISimpleFrameSite}
  ISimpleFrameSite = class;
  {$EXTERNALSYM IPersistStreamInit}
  IPersistStreamInit = class;
  {$EXTERNALSYM IPropertyNotifySink }
  IPropertyNotifySink = class;
  {$EXTERNALSYM IProvideClassInfo }
  IProvideClassInfo = class;
  {$EXTERNALSYM IConnectionPointContainer}
  IConnectionPointContainer = class;
  {$EXTERNALSYM IEnumConnectionPoints}
  IEnumConnectionPoints = class;
  {$EXTERNALSYM IConnectionPoint}
  IConnectionPoint = class;
  {$EXTERNALSYM IEnumConnections}
  IEnumConnections = class;
  {$EXTERNALSYM IClassFactory2 }
  IClassFactory2 = class;
  {$EXTERNALSYM ISpecifyPropertyPages }
  ISpecifyPropertyPages = class;
  {$EXTERNALSYM IPerPropertyBrowsing}
  IPerPropertyBrowsing = class;
  {$EXTERNALSYM IPropertyPageSite}
  IPropertyPageSite = class;
  {$EXTERNALSYM IPropertyPage }
  IPropertyPage = class;
  {$EXTERNALSYM IPropertyPage2 }
  IPropertyPage2 = class;
  {$EXTERNALSYM IFont }
  IFont = class;
  {$EXTERNALSYM IFontDisp}
  IFontDisp = class;
  {$EXTERNALSYM IPicture}
  IPicture = class;
  {$EXTERNALSYM IPictureDisp}
  IPictureDisp = class;

{ IOleControl interface }

  {$EXTERNALSYM IOleControl}
  IOleControl = class(IUnknown)
  public
    function GetControlInfo(var ci: TControlInfo): HResult; virtual; stdcall; abstract;
    function OnMnemonic(msg: PMsg): HResult; virtual; stdcall; abstract;
    function OnAmbientPropertyChange(dispid: TDispID): HResult; virtual; stdcall; abstract;
    function FreezeEvents(bFreeze: BOOL): HResult; virtual; stdcall; abstract;
  end;

{ IOleControlSite interface }

  {$EXTERNALSYM IOleControlSite}
  IOleControlSite = class(IUnknown)
  public
    function OnControlInfoChanged: HResult; virtual; stdcall; abstract;
    function LockInPlaceActive(fLock: BOOL): HResult; virtual; stdcall; abstract;
    function GetExtendedControl(var disp: IDispatch): HResult; virtual; stdcall; abstract;
    function TransformCoords(var ptlHimetric: TPoint; var ptfContainer: TPointF;
      flags: Longint): HResult; virtual; stdcall; abstract;
    function TranslateAccelerator(msg: PMsg; grfModifiers: Longint): HResult;
       virtual; stdcall; abstract;
    function OnFocus(fGotFocus: BOOL): HResult; virtual; stdcall; abstract;
    function ShowPropertyFrame: HResult; virtual; stdcall; abstract;
  end;

{ ISimpleFrameSite interface }

  {$EXTERNALSYM ISimpleFrameSite}
  ISimpleFrameSite = class(IUnknown)
  public
    function PreMessageFilter(wnd: HWnd; msg, wp, lp: Integer;
      var res: Integer; var Cookie: Longint): HResult;
      virtual; stdcall; abstract;
    function PostMessageFilter(wnd: HWnd; msg, wp, lp: Integer;
      var res: Integer; Cookie: Longint): HResult;
      virtual; stdcall; abstract;
  end;

{ IPersistStreamInit interface }

  {$EXTERNALSYM IPersistStreamInit}
  IPersistStreamInit = class(IPersistStream)
  public
    function InitNew: HResult; virtual; stdcall; abstract;
  end;

{ IPropertyNotifySink interface }

  {$EXTERNALSYM IPropertyNotifySink }
  IPropertyNotifySink = class(IUnknown)
  public
    function OnChanged(dispid: TDispID): HResult; virtual; stdcall; abstract;
    function OnRequestEdit(dispid: TDispID): HResult; virtual; stdcall; abstract;
  end;

{ IProvideClassInfo interface }

  {$EXTERNALSYM IProvideClassInfo }
  IProvideClassInfo = class(IUnknown)
  public
    function GetClassInfo(var ti: ITypeInfo): HResult; virtual; stdcall; abstract;
  end;

{ IConnectionPointContainer interface }

  {$EXTERNALSYM IConnectionPointContainer}
  IConnectionPointContainer = class(IUnknown)
  public
    function EnumConnectionPoints(var Enum: IEnumConnectionPoints): HResult;
      virtual; stdcall; abstract;
    function FindConnectionPoint(const iid: TIID;
      var cp: IConnectionPoint): HResult; virtual; stdcall; abstract;
  end;

{ IEnumConnectionPoints interface }

  {$EXTERNALSYM IEnumConnectionPoints}
  IEnumConnectionPoints = class(IUnknown)
  public
    function Next(celt: Longint; var elt;
      pceltFetched: PLongint): HResult; virtual; stdcall; abstract;
    function Skip(celt: Longint): HResult; virtual; stdcall; abstract;
    function Reset: HResult; virtual; stdcall; abstract;
    function Clone(var Enum: IEnumConnectionPoints): HResult;
      virtual; stdcall; abstract;
  end;

{ IConnectionPoint interface }

  {$EXTERNALSYM IConnectionPoint}
  IConnectionPoint = class(IUnknown)
  public
    function GetConnectionInterface(var iid: TIID): HResult; virtual; stdcall; abstract;
    function GetConnectionPointContainer(var cpc: IConnectionPointContainer): HResult;
      virtual; stdcall; abstract;
    function Advise(unkSink: IUnknown; var dwCookie: Longint): HResult; virtual; stdcall; abstract;
    function Unadvise(dwCookie: Longint): HResult; virtual; stdcall; abstract;
    function EnumConnections(var Enum: IEnumConnections): HResult; virtual; stdcall; abstract;
  end;

{ TConnectData structure }

  PConnectData = ^TConnectData;
  {$EXTERNALSYM tagCONNECTDATA}
  tagCONNECTDATA = record
    pUnk: IUnknown;
    dwCookie: Longint;
  end;
  TConnectData = tagCONNECTDATA;
  {$EXTERNALSYM CONNECTDATA}
  CONNECTDATA = tagCONNECTDATA;

{ IEnumConnections interface }

  {$EXTERNALSYM IEnumConnections}
  IEnumConnections = class(IUnknown)
  public
    function Next(celt: Longint; var elt;
      pceltFetched: PLongint): HResult; virtual; stdcall; abstract;
    function Skip(celt: Longint): HResult; virtual; stdcall; abstract;
    function Reset: HResult; virtual; stdcall; abstract;
    function Clone(var Enum: IEnumConnections): HResult; virtual; stdcall; abstract;
  end;

{ TLicInfo structure }

  PLicInfo = ^TLicInfo;
  {$EXTERNALSYM tagLICINFO}
  tagLICINFO = record
    cbLicInfo: Longint;
    fRuntimeKeyAvail: BOOL;
    fLicVerified: BOOL;
  end;
  TLicInfo = tagLICINFO;
  {$EXTERNALSYM LICINFO}
  LICINFO = tagLICINFO;

{ IClassFactory2 interface }

  {$EXTERNALSYM IClassFactory2 }
  IClassFactory2 = class(IClassFactory)
    function GetLicInfo(var licInfo: TLicInfo): HResult; virtual; stdcall; abstract;
    function RequestLicKey(dwResrved: Longint; var bstrKey: TBStr): HResult;
      virtual; stdcall; abstract;
    function CreateInstanceLic(unkOuter: IUnknown; unkReserved: IUnknown;
      const iid: TIID; bstrKey: TBStr; var vObject): HResult; virtual; stdcall; abstract;
  end;

{ TCAUUID structure - a counted array of TGUID }

  PGUIDList = ^TGUIDList;
  TGUIDList = array[0..65535] of TGUID;

  PCAGUID = ^TCAGUID;
  TCAGUID = record
    cElems: Longint;
    pElems: PGUIDList;
  end;

{ TCAPOleStr structure - a counted array of POleStr }

  PCAPOleStr = ^TCAPOleStr;
  TCAPOleStr = record
    cElems: Longint;
    pElems: POleStrList;
  end;

{ TCALongint - a counted array of Longint }

  PLongintList = ^TLongintList;
  TLongintList = array[0..65535] of Longint;

  PCALongint = ^TCALongint;
  TCALongint = record
    cElems: Longint;
    pElems: PLongintList;
  end;

{ TOCPFIParams - parameters for OleCreatePropertyFrameIndirect }

  POCPFIParams = ^TOCPFIParams;
  {$EXTERNALSYM tagOCPFIPARAMS}
  tagOCPFIPARAMS = record
    cbStructSize: Longint;
    hWndOwner: HWnd;
    x: Integer;
    y: Integer;
    lpszCaption: POleStr;
    cObjects: Longint;
    pObjects: Pointer;
    cPages: Longint;
    pPages: Pointer;
    lcid: TLCID;
    dispidInitialProperty: TDispID;
  end;
  TOCPFIParams = tagOCPFIPARAMS;
  {$EXTERNALSYM OCPFIPARAMS}
  OCPFIPARAMS = tagOCPFIPARAMS;

{ TPropPageInfo structure - information about a property page }

  PPropPageInfo = ^TPropPageInfo;
  {$EXTERNALSYM tagPROPPAGEINFO}
  tagPROPPAGEINFO = record
    cb: Longint;
    pszTitle: POleStr;
    size: TSize;
    pszDocString: POleStr;
    pszHelpFile: POleStr;
    dwHelpContext: Longint;
  end;
  TPropPageInfo = tagPROPPAGEINFO;
  {$EXTERNALSYM PROPPAGEINFO}
  PROPPAGEINFO = tagPROPPAGEINFO;

{ ISpecifyPropertyPages interface }

  {$EXTERNALSYM ISpecifyPropertyPages }
  ISpecifyPropertyPages = class(IUnknown)
  public
    function GetPages(var pages: TCAGUID): HResult; virtual; stdcall; abstract;
  end;

{ IPerPropertyBrowsing interface }

  {$EXTERNALSYM IPerPropertyBrowsing}
  IPerPropertyBrowsing = class(IUnknown)
  public
    function GetDisplayString(dispid: TDispID; var bstr: TBStr): HResult;
      virtual; stdcall; abstract;
    function MapPropertyToPage(dispid: TDispID; var clsid: TCLSID): HResult;
      virtual; stdcall; abstract;
    function GetPredefinedStrings(dispid: TDispID; var caStringsOut: TCAPOleStr;
      var caCookiesOut: TCALongint): HResult; virtual; stdcall; abstract;
    function GetPredefinedValue(dispid: TDispID; dwCookie: Longint;
      var varOut: Variant): HResult; virtual; stdcall; abstract;
  end;

{ IPropertyPageSite interface }

  {$EXTERNALSYM IPropertyPageSite}
  IPropertyPageSite = class(IUnknown)
  public
    function OnStatusChange(flags: Longint): HResult; virtual; stdcall; abstract;
    function GetLocaleID(var localeID: TLCID): HResult; virtual; stdcall; abstract;
    function GetPageContainer(var unk: IUnknown): HResult; virtual; stdcall; abstract;
    function TranslateAccelerator(msg: PMsg): HResult; virtual; stdcall; abstract;
  end;

{ IPropertyPage interface }

  {$EXTERNALSYM IPropertyPage }
  IPropertyPage = class(IUnknown)
  public
    function SetPageSite(pageSite: IPropertyPageSite): HResult; virtual; stdcall; abstract;
    function Activate(hwndParent: HWnd; const rc: TRect; bModal: BOOL): HResult;
      virtual; stdcall; abstract;
    function Deactivate: HResult; virtual; stdcall; abstract;
    function GetPageInfo(var pageInfo: TPropPageInfo): HResult; virtual; stdcall; abstract;
    function SetObjects(cObjects: Longint; unk: IUnknown): HResult; virtual; stdcall; abstract;
    function Show(nCmdShow: Integer): HResult; virtual; stdcall; abstract;
    function Move(const rect: TRect): HResult; virtual; stdcall; abstract;
    function IsPageDirty: HResult; virtual; stdcall; abstract;
    function Apply: HResult; virtual; stdcall; abstract;
    function Help(pszHelpDir: POleStr): HResult; virtual; stdcall; abstract;
    function TranslateAccelerator(msg: PMsg): HResult; virtual; stdcall; abstract;
  end;

{ IPropertyPage2 interface }

  {$EXTERNALSYM IPropertyPage2 }
  IPropertyPage2 = class(IPropertyPage)
  public
    function EditProperty(dispid: TDispID): HResult; virtual; stdcall; abstract;
  end;

{ IFont interface }

  {$EXTERNALSYM IFont }
  IFont = class(IUnknown)
  public
    function get_Name(var name: TBStr): HResult; virtual; stdcall; abstract;
    function put_Name(name: TBStr): HResult; virtual; stdcall; abstract;
    function get_Size(var size: TCurrency): HResult; virtual; stdcall; abstract;
    function put_Size(size: TCurrency): HResult; virtual; stdcall; abstract;
    function get_Bold(var bold: BOOL): HResult; virtual; stdcall; abstract;
    function put_Bold(bold: BOOL): HResult; virtual; stdcall; abstract;
    function get_Italic(var italic: BOOL): HResult; virtual; stdcall; abstract;
    function put_Italic(italic: BOOL): HResult; virtual; stdcall; abstract;
    function get_Underline(var underline: BOOL): HResult; virtual; stdcall; abstract;
    function put_Underline(underline: BOOL): HResult; virtual; stdcall; abstract;
    function get_Strikethrough(var strikethrough: BOOL): HResult; virtual; stdcall; abstract;
    function put_Strikethrough(strikethrough: BOOL): HResult; virtual; stdcall; abstract;
    function get_Weight(var weight: Smallint): HResult; virtual; stdcall; abstract;
    function put_Weight(weight: Smallint): HResult; virtual; stdcall; abstract;
    function get_Charset(var charset: Smallint): HResult; virtual; stdcall; abstract;
    function put_Charset(charset: Smallint): HResult; virtual; stdcall; abstract;
    function get_hFont(var font: HFont): HResult; virtual; stdcall; abstract;
    function Clone(var font: IFont): HResult; virtual; stdcall; abstract;
    function IsEqual(fontOther: IFont): HResult; virtual; stdcall; abstract;
    function SetRatio(cyLogical, cyHimetric: Longint): HResult; virtual; stdcall; abstract;
    function QueryTextMetrics(var tm: TTextMetricOle): HResult; virtual; stdcall; abstract;
    function AddRefHfont(font: HFont): HResult; virtual; stdcall; abstract;
    function ReleaseHfont(font: HFont): HResult; virtual; stdcall; abstract;
  end;

{ IFontDisp interface }

  {$EXTERNALSYM IFontDisp}
  IFontDisp = class(IDispatch);

{ TFontDesc structure }

  PFontDesc = ^TFontDesc;
  {$EXTERNALSYM tagFONTDESC}
  tagFONTDESC = record
    cbSizeofstruct: Integer;
    lpstrName: POleStr;
    cySize: Comp;
    sWeight: Smallint;
    sCharset: Smallint;
    fItalic: BOOL;
    fUnderline: BOOL;
    fStrikethrough: BOOL;
  end;
  TFontDesc = tagFONTDESC;
  {$EXTERNALSYM FONTDESC}
  FONTDESC = tagFONTDESC;

{ IPicture interface }

  {$EXTERNALSYM IPicture}
  IPicture = class(IUnknown)
  public
    function get_Handle(var handle: OLE_HANDLE): HResult;  virtual; stdcall; abstract;
    function get_hPal(var handle: OLE_HANDLE): HResult; virtual; stdcall; abstract;
    function get_Type(var typ: Smallint): HResult; virtual; stdcall; abstract;
    function get_Width(var width: OLE_XSIZE_HIMETRIC): HResult; virtual; stdcall; abstract;
    function get_Height(var height: OLE_YSIZE_HIMETRIC): HResult; virtual; stdcall; abstract;
    function Render(dc: HDC; x, y, cx, cy: Longint;
      xSrc: OLE_XPOS_HIMETRIC; ySrc: OLE_YPOS_HIMETRIC;
      cxSrc: OLE_XSIZE_HIMETRIC; cySrc: OLE_YSIZE_HIMETRIC;
      const rcWBounds: TRect): HResult; virtual; stdcall; abstract;
    function set_hPal(hpal: OLE_HANDLE): HResult; virtual; stdcall; abstract;
    function get_CurDC(var dcOut: HDC): HResult; virtual; stdcall; abstract;
    function SelectPicture(dcIn: HDC; var hdcOut: HDC;
      var bmpOut: OLE_HANDLE): HResult; virtual; stdcall; abstract;
    function get_KeepOriginalFormat(var fkeep: BOOL): HResult; virtual; stdcall; abstract;
    function put_KeepOriginalFormat(fkeep: BOOL): HResult; virtual; stdcall; abstract;
    function PictureChanged: HResult; virtual; stdcall; abstract;
    function SaveAsFile(stream: IStream; fSaveMemCopy: BOOL;
      var cbSize: Longint): HResult; virtual; stdcall; abstract;
    function get_Attributes(dwAttr: Longint): HResult; virtual; stdcall; abstract;
  end;

{ IPictureDisp interface }

  {$EXTERNALSYM IPictureDisp}
  IPictureDisp = class(IDispatch);

{ TPictDesc structure }

  PPictDesc = ^TPictDesc;
  {$EXTERNALSYM tagPICTDESC}
  tagPICTDESC = record
    cbSizeofstruct: Integer;
    picType: Integer;
    case Integer of
      PICTYPE_BITMAP: (
        hbitmap: THandle;       { Bitmap }
        hpal: THandle);         { Accompanying palette }
      PICTYPE_METAFILE: (
        hMeta: THandle;         { Metafile }
        xExt, yExt: Integer);   { Extent }
      PICTYPE_ICON: (
        hIcon: THandle);        { Icon }
  end;
  TPictDesc = tagPICTDESC;
  {$EXTERNALSYM PICTDESC}
  PICTDESC = tagPICTDESC;

const

{ Standard interface IDs }

  {$EXTERNALSYM IID_IPropertyNotifySink}
  IID_IPropertyNotifySink: TGUID = (
    D1:$9BFBBC02;D2:$EFF1;D3:$101A;D4:($84,$ED,$00,$AA,$00,$34,$1D,$07));
  {$EXTERNALSYM IID_IClassFactory2}
  IID_IClassFactory2: TGUID = (
    D1:$B196B28F;D2:$BAB4;D3:$101A;D4:($B6,$9C,$00,$AA,$00,$34,$1D,$07));
  {$EXTERNALSYM IID_IProvideClassInfo}
  IID_IProvideClassInfo: TGUID = (
    D1:$B196B283;D2:$BAB4;D3:$101A;D4:($B6,$9C,$00,$AA,$00,$34,$1D,$07));
  {$EXTERNALSYM IID_IConnectionPointContainer}
  IID_IConnectionPointContainer: TGUID = (
    D1:$B196B284;D2:$BAB4;D3:$101A;D4:($B6,$9C,$00,$AA,$00,$34,$1D,$07));
  {$EXTERNALSYM IID_IEnumConnectionPoints}
  IID_IEnumConnectionPoints: TGUID = (
    D1:$B196B285;D2:$BAB4;D3:$101A;D4:($B6,$9C,$00,$AA,$00,$34,$1D,$07));
  {$EXTERNALSYM IID_IConnectionPoint}
  IID_IConnectionPoint: TGUID = (
    D1:$B196B286;D2:$BAB4;D3:$101A;D4:($B6,$9C,$00,$AA,$00,$34,$1D,$07));
  {$EXTERNALSYM IID_IEnumConnections}
  IID_IEnumConnections: TGUID = (
    D1:$B196B287;D2:$BAB4;D3:$101A;D4:($B6,$9C,$00,$AA,$00,$34,$1D,$07));
  {$EXTERNALSYM IID_IOleControl}
  IID_IOleControl: TGUID = (
    D1:$B196B288;D2:$BAB4;D3:$101A;D4:($B6,$9C,$00,$AA,$00,$34,$1D,$07));
  {$EXTERNALSYM IID_IOleControlSite}
  IID_IOleControlSite: TGUID = (
    D1:$B196B289;D2:$BAB4;D3:$101A;D4:($B6,$9C,$00,$AA,$00,$34,$1D,$07));
  {$EXTERNALSYM IID_ISimpleFrameSite}
  IID_ISimpleFrameSite: TGUID = (
    D1:$742B0E01;D2:$14E6;D3:$101B;D4:($91,$4E,$00,$AA,$00,$30,$0C,$AB));
  {$EXTERNALSYM IID_IPersistStreamInit}
  IID_IPersistStreamInit: TGUID = (
    D1:$7FD52380;D2:$4E07;D3:$101B;D4:($AE,$2D,$08,$00,$2B,$2E,$C7,$13));
  {$EXTERNALSYM IID_IPropertyFrame}
  IID_IPropertyFrame: TGUID = (
    D1:$B196B28A;D2:$BAB4;D3:$101A;D4:($B6,$9C,$00,$AA,$00,$34,$1D,$07));
  {$EXTERNALSYM IID_ISpecifyPropertyPages}
  IID_ISpecifyPropertyPages: TGUID = (
    D1:$B196B28B;D2:$BAB4;D3:$101A;D4:($B6,$9C,$00,$AA,$00,$34,$1D,$07));
  {$EXTERNALSYM IID_IPerPropertyBrowsing}
  IID_IPerPropertyBrowsing: TGUID = (
    D1:$376BD3AA;D2:$3845;D3:$101B;D4:($84,$ED,$08,$00,$2B,$2E,$C7,$13));
  {$EXTERNALSYM IID_IPropertyPageSite}
  IID_IPropertyPageSite: TGUID = (
    D1:$B196B28C;D2:$BAB4;D3:$101A;D4:($B6,$9C,$00,$AA,$00,$34,$1D,$07));
  {$EXTERNALSYM IID_IPropertyPage}
  IID_IPropertyPage: TGUID = (
    D1:$B196B28D;D2:$BAB4;D3:$101A;D4:($B6,$9C,$00,$AA,$00,$34,$1D,$07));
  {$EXTERNALSYM IID_IPropertyPage2}
  IID_IPropertyPage2: TGUID = (
    D1:$01E44665;D2:$24AC;D3:$101B;D4:($84,$ED,$08,$00,$2B,$2E,$C7,$13));
  {$EXTERNALSYM IID_IFont}
  IID_IFont: TGUID = (
    D1:$BEF6E002;D2:$A874;D3:$101A;D4:($8B,$BA,$00,$AA,$00,$30,$0C,$AB));
  {$EXTERNALSYM IID_IFontDisp}
  IID_IFontDisp: TGUID = (
    D1:$BEF6E003;D2:$A874;D3:$101A;D4:($8B,$BA,$00,$AA,$00,$30,$0C,$AB));
  {$EXTERNALSYM IID_IPicture}
  IID_IPicture: TGUID = (
    D1:$7BF80980;D2:$BF32;D3:$101A;D4:($8B,$BB,$00,$AA,$00,$30,$0C,$AB));
  {$EXTERNALSYM IID_IPictureDisp}
  IID_IPictureDisp: TGUID = (
    D1:$7Bf80981;D2:$BF32;D3:$101A;D4:($8B,$BB,$00,$AA,$00,$30,$0C,$AB));

{ Standard class IDs }

  CLSID_CFontPropPage: TGUID = (
    D1:$2542f180;D2:$3532;D3:$1069;D4:($a2,$cd,$00,$aa,$00,$34,$b5,$0b));
  CLSID_CColorPropPage: TGUID = (
    D1:$ddf5a600;D2:$b9c0;D3:$101a;D4:($af,$1a,$00,$aa,$00,$34,$b5,$0b));
  CLSID_CPicturePropPage: TGUID = (
    D1:$fc7af71d;D2:$fc74;D3:$101a;D4:($84,$ed,$08,$00,$2b,$2e,$c7,$13));
  CLSID_PersistPropset: TGUID = (
    D1:$fb8f0821;D2:$0164;D3:$101b;D4:($84,$ed,$08,$00,$2b,$2e,$c7,$13));
  CLSID_ConvertVBX: TGUID = (
    D1:$fb8f0822;D2:$0164;D3:$101b;D4:($84,$ed,$08,$00,$2b,$2e,$c7,$13));
  CLSID_StdFont: TGUID = (
    D1:$fb8f0823;D2:$0164;D3:$101b;D4:($84,$ed,$08,$00,$2b,$2e,$c7,$13));
  CLSID_StdPicture: TGUID = (
    D1:$fb8f0824;D2:$0164;D3:$101b;D4:($84,$ed,$08,$00,$2b,$2e,$c7,$13));

{ Property frame APIs }

{$EXTERNALSYM OleCreatePropertyFrame}
function OleCreatePropertyFrame(hwndOwner: HWnd; x, y: Integer;
  lpszCaption: POleStr; cObjects: Integer; pObjects: Pointer;
  cPages: Integer; pPageCLSIDs: Pointer; lcid: TLCID; dwReserved: Longint;
  pvReserved: Pointer): HResult; stdcall;

{$EXTERNALSYM OleCreatePropertyFrameIndirect}
function OleCreatePropertyFrameIndirect(var Params: TOCPFIParams): HResult; stdcall;

{ Standard type APIs }

{$EXTERNALSYM OleTranslateColor}
function OleTranslateColor(clr: TOleColor; hpal: HPalette;
 var colorref: TColorRef): HResult; stdcall;

{$EXTERNALSYM OleCreateFontIndirect}
function OleCreateFontIndirect(var FontDesc: TFontDesc; const iid: TIID;
  var vObject): HResult; stdcall;

{$EXTERNALSYM OleCreatePictureIndirect}
function OleCreatePictureIndirect(var PictDesc: TPictDesc; const iid: TIID;
  fOwn: BOOL; var vObject): HResult; stdcall;

{$EXTERNALSYM OleLoadPicture}
function OleLoadPicture(stream: IStream; lSize: Longint; fRunmode: BOOL;
  const iid: TIID; var vObject): HResult; stdcall;

{$EXTERNALSYM OleIconToCursor}
function OleIconToCursor(hinstExe: THandle; hIcon: THandle): HCursor; stdcall;

implementation

const
  olepro32 = 'olepro32.dll';

{ Externals from olepro32.dll }

function OleCreatePropertyFrame;            external olepro32 name 'OleCreatePropertyFrame';
function OleCreatePropertyFrameIndirect;    external olepro32 name 'OleCreatePropertyFrameIndirect';
function OleTranslateColor;                 external olepro32 name 'OleTranslateColor';
function OleCreateFontIndirect;             external olepro32 name 'OleCreateFontIndirect';
function OleCreatePictureIndirect;          external olepro32 name 'OleCreatePictureIndirect';
function OleLoadPicture;                    external olepro32 name 'OleLoadPicture';
function OleIconToCursor;                   external olepro32 name 'OleIconToCursor';

end.
