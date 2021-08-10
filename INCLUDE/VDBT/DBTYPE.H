//------------------------------------------------------------------------------
// DBTYPE.H
// Copyrights (C) 1996 Borland International
// All Rights Reserved
//------------------------------------------------------------------------------

#if !defined(DBTYPE_H_)
#define DBTYPE_H_

#include <vdbt/dbpme.h>


//----------------------------------------------------------------------
// Foreward Declarations
//----------------------------------------------------------------------
class _DBAWARECLASS TDBControl;
class _DBAWARECLASS TDBCheckBox;
class _DBAWARECLASS TDBComboBox;
class _DBAWARECLASS TDBEdit;
class _DBAWARECLASS TDBGrid;
class _DBAWARECLASS TDBImage;
class _DBAWARECLASS TDBListBox;
class _DBAWARECLASS TDBLookupCombo;
class _DBAWARECLASS TDBLookupList;
class _DBAWARECLASS TDBMemo;
class _DBAWARECLASS TDBNavigator;
class _DBAWARECLASS TDBRadioGroup;
class _DBAWARECLASS TDBText;

//----------------------------------------------------------------------
// Enumarations
//----------------------------------------------------------------------
typedef enum {
  sbNone,
  sbVertical,
  sbHorizontal,
  sbBoth,
} TScrollBars;

typedef enum {
  cbUnchecked,
  cbChecked,
  cbGrayed,
} TCheckBoxState;

typedef enum {  // TDBCheckBox Alignment
  lrLeftJustify,
  lrRightJustify,
} TLeftRight;

typedef enum {  // DBEdit CharCase
  ecNormal,
  ecLowerCase,
  ecUpperCase,
} TEditCharCase;

typedef enum {  // DBtext WordWrap
  twTrue,
  twFalse,
} TTextWordWrap;

typedef enum {  // values for property Align
  alnNone,
  alnTop,
  alnBottom,
  alnLeft,
  alnRight,
  alnClient,
} TAlign;

typedef enum { // values for property Alignment
  taLeftJustify,
  taCenter,
  taRightJustify,
} TAlignment;

typedef enum { // values for property BorderStyle
  bsNone,
  bsSingle,
} TBorderStyle;

typedef enum { // values for property DragMode
  dmManual,
  dmAutomatic,
} TDragMode;

typedef enum { // values for property MousePointer
  crDefault,
  crArrow,
  crCross,
  crIBeam,
  crIcon,
  crSize,
  crSizeNESW,
  crSizeNS,
  crSizeNWSE,
  crSizeWE,
  crUpArrow,
  crHourglass,
  crNoDrop,
} TMousePointer;

typedef enum {
  lbStandard,
  lbOwnerDrawFixed,
  lbOwnerDrawVariable,
} TListBoxStyle;

typedef enum {
  csSimple,
  csDropDown,
  csDropDownList,
  csOwnerDrawFixed,
  csOwnerDrawVariable,
} TComboBoxStyle;

typedef enum {
  dsDragEnter,
  dsDragMove,
  dsDragLeave,
} TDragState;

typedef enum {
  nbFirst,
  nbPrior,
  nbNext,
  nbLast,
  nbInsert,
  nbDelete,
  nbEdit,
  nbPost,
  nbCancel,
  nbRefresh,
} TNavigateBtn;

typedef enum {
  btnOff,
  btnOn,
  btnDisabled,
} TBtnState;

typedef enum {
  mbLeft   = 0x01,
  mbRight  = 0x02,
  mbMiddle = 0x04,
} TMouseBtn;

struct _TMouseButton {
  unsigned short int mbLeft   : 1;
  unsigned short int mbRight  : 1;
  unsigned short int mbMiddle : 1;
  _TMouseButton( unsigned short int u ) { *this = *(_TMouseButton*)&u; }
  operator unsigned short int() { return *(unsigned short int*)this; }
};
typedef struct _TMouseButton TMouseButton;

typedef enum {
  ssShift = 0x01,
  ssCtrl  = 0x02,
  ssAlt   = 0x04,
} TShiftStt;

struct _TShiftState {
  unsigned short int ssShift : 1;
  unsigned short int ssCtrl  : 1;
  unsigned short int ssAlt   : 1;
  _TShiftState( unsigned short int u ) { *this = *(_TShiftState*)&u; }
  operator unsigned short int() { return *(unsigned short int*)this; }
};
typedef struct _TShiftState TShiftState;

typedef enum {
  odSelected = 0x01,
  odGrayed   = 0x02,
  odDisabled = 0x04,
  odChecked  = 0x08,
} TOwnerDrawStt;

struct _TOwnerDrawState {
  unsigned int odSelected : 1;
  unsigned int odGrayed   : 1;
  unsigned int odDisabled : 1;
  unsigned int odChecked  : 1;
  _TOwnerDrawState( unsigned short int u ) { *this = *(_TOwnerDrawState*)&u; }
  operator unsigned short int() { return *(unsigned short int*)this; }
};
typedef struct _TOwnerDrawState TOwnerDrawState;

typedef enum {
  oaDrawEntire = 0x01,
  oaSelect     = 0x02,
  odFocus      = 0x04,
} TOwnerDrawAct;

struct _TOwnerDrawAction {
  unsigned int oaDrawEntire : 1;
  unsigned int oaSelect     : 1;
  unsigned int oaFocus      : 1;
  _TOwnerDrawAction( unsigned short int u ) { *this = *(_TOwnerDrawAction*)&u; };
  operator unsigned short int() { return *(unsigned short int*)this; }
};
typedef struct _TOwnerDrawAction TOwnerDrawAction;

typedef enum {
  loColLines = 0x01,
  loRowLines = 0x02,
  loTitles   = 0x04,
} TDBLookupListOption;

struct _TDBLookupListOptions {
  unsigned int loColLines : 1;
  unsigned int loRowLines : 1;
  unsigned int loTitles   : 1;
  _TDBLookupListOptions( unsigned short int u ) { *this = *(_TDBLookupListOptions*)&u; };
  operator unsigned short int() { return *(unsigned short int*)this; }
};
typedef struct _TDBLookupListOptions TDBLookupListOptions;

typedef int Bool;

#endif DBTYPE_H_
