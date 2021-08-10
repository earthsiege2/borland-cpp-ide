//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1996 by Borland International
//   intldemo.h
//----------------------------------------------------------------------------
#ifndef __INTLDEMO_H
#define __INTLDEMO_H

//Menu IDs
#define CM_FILELIST             300

#define CM_LOCALEC              310
#define CM_LOCALEUS             311
#define CM_LOCALEUK             312
#define CM_LOCALEFRENCH         313
#define CM_LOCALEGERMAN         314

#define CM_LANGUAGEENGLISH      320
#define CM_LANGUAGEFRENCH       321
#define CM_LANGUAGEGERMAN       322

#define CM_ISALNUM              400
#define CM_ISALPHA              401
#define CM_ISASCII              402
#define CM_ISCNTRL              403
#define CM_ISDIGIT              404
#define CM_ISGRAPH              405
#define CM_ISLOWER              406
#define CM_ISPRINT              407
#define CM_ISPUNCT              408
#define CM_ISSPACE              409
#define CM_ISUPPER              410
#define CM_ISXDIGIT             411

#define CM_SHOWVALUES           500

//Dialog and control IDs

#define LIST_DIALOG             100
#define ID_LOCALEWINDOW         101
#define ID_FILEVIEWER           200

#define ID_FILELISTBOX          100

#define ID_SORTBUT              102
#define ID_TOLOWERBUT           103
#define ID_VIEWBUTTON           104

// bitmap button IDs
#define IDB_VIEW ID_VIEWBUTTON + 1000
#define IDB_LVIEW IDB_VIEW + 1000
#define IDB_VIEWD IDB_LVIEW + 1000
#define IDB_LVIEWD IDB_VIEWD + 1000
#define IDB_VIEWF IDB_LVIEWD + 1000
#define IDB_LVIEWF IDB_VIEWF + 1000

#define IDB_TOLOWER ID_TOLOWERBUT + 1000
#define IDB_LTOLOWER IDB_TOLOWER + 1000
#define IDB_TOLOWERD IDB_LTOLOWER + 1000
#define IDB_LTOLOWERD IDB_TOLOWERD + 1000
#define IDB_TOLOWERF IDB_LTOLOWERD + 1000
#define IDB_LTOLOWERF IDB_TOLOWERF + 1000

#define IDB_SORT ID_SORTBUT + 1000
#define IDB_LSORT IDB_SORT + 1000
#define IDB_SORTD IDB_LSORT + 1000
#define IDB_LSORTD IDB_SORTD + 1000
#define IDB_SORTF IDB_LSORTD + 1000
#define IDB_LSORTF IDB_SORTF + 1000

//String IDS
#define IDS_APPNAME             1
#define IDS_LOCALETITLE         16
#define IDS_DECIMALPOINT        17
#define IDS_THOUSANDSSEP        18
#define IDS_GROUPING            19
#define IDS_INTCURRSYMBOL       20
#define IDS_CURRENCYSYMBOL      21
#define IDS_MONDECIMALPOINT     22
#define IDS_MONTHOUSANDSSEP     23
#define IDS_MONGROUPING         24
#define IDS_POSITIVESIGN        25
#define IDS_NEGATIVESIGN        26
#define IDS_INTFRACDIGITS       27
#define IDS_FRACDIGITS          28
#define IDS_PCSPRECEDES         29
#define IDS_PSEPBYSPACE         30
#define IDS_NCSPRECEDES         31
#define IDS_NSEPBYSPACE         32
#define IDS_PSIGNPOSN           33
#define IDS_N_SIGN_POSN         34
#define IDS_YES                 35
#define IDS_NO                  36
#define IDS_NOT_DEFINED         37

#define IDS_CHARACTER           48

//Message IDs
#define WM_VALWNDCLOSE WM_USER + 1

#endif //__INTLDEMO_H
