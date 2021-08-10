/*  bivbx.h

    Defines structs and functions for dealing with VBX controls.

*/
/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1993 by Borland International
 *      All Rights Reserved.
 *
 */

#ifndef __BIVBX_H
#define __BIVBX_H

#ifdef WIN32
  #error 16bit compilations only, do not build 32bit applications using VBX support
#endif

#define STRICT
#include <windows.h>

#ifdef __cplusplus
  extern "C" {            /* Assume C declarations for C++ */
#endif

#ifndef __VBX_H

  typedef LPSTR          HSZ;
  typedef unsigned char  ENUM;
  typedef LPVOID         HCTL;
  typedef short          SHORT;
  typedef unsigned short USHORT;
  typedef HANDLE         HFORMFILE;
  typedef USHORT         ERR;
  typedef WORD           HPIC;
  typedef LPVOID         HLSTR;

  #ifdef RC_INVOKED
    #define DLGINIT 240
  #else
    #define RT_DLGINIT MAKEINTRESOURCE(240)
  #endif

#endif

/* VBX Window Messages */
#define WM_VBXFIREEVENT 0x0360

/* VBX Event Structure */
typedef struct VBXEVENT {
  HCTL   Control;
  HWND   Window;
  int    ID;
  int    EventIndex;
  LPCSTR EventName;
  int    NumParams;
  LPVOID ParamList;
} VBXEVENT, FAR * LPVBXEVENT, NEAR * NPVBXEVENT;

/* macros for accessing event arguments */
#define VBX_EVENTARGNUM(event,type,index) \
  *(((type FAR * FAR *)(event)->ParamList)[(event)->NumParams - (index) - 1])
#define VBX_EVENTARGSTR(event,index) \
  (((HLSTR FAR *)(event)->ParamList)[(event)->NumParams - (index) - 1])
  
/* Initialization */
BOOL FAR _export PASCAL VBXInit(HINSTANCE instance, LPCSTR classPrefix);
void FAR _export PASCAL VBXTerm(void);
BOOL FAR _export PASCAL VBXEnableDLL(HINSTANCE instApp, HINSTANCE instDLL);

/* Controls */
HCTL FAR _export PASCAL VBXGetHctl(HWND window);
HWND FAR _export PASCAL VBXGetHwnd(HCTL control);
HCTL FAR _export PASCAL VBXCreate(HWND windowParent, UINT id,
                                  LPCSTR library, LPCSTR cls,
                                  LPCSTR title, DWORD style,
                                  int x, int y, int w, int h,
                                  HFORMFILE file);

/* Dialogs */
BOOL FAR _export PASCAL VBXInitDialog(HWND window, HINSTANCE instance, LPSTR id);

/* Properties */
#define PTYPE_CSTRING    0x01  /* HSZ */
#define PTYPE_SHORT      0x02  /* short */
#define PTYPE_LONG       0x03  /* LONG */
#define PTYPE_BOOL       0x04  /* BOOL */
#define PTYPE_COLOR      0x05  /* COLORREF or DWORD */
#define PTYPE_ENUM       0x06  /* BYTE */
#define PTYPE_REAL       0x07  /* float */
#define PTYPE_XPOS       0x08  /* LONG (twips) */
#define PTYPE_XSIZE      0x09  /* LONG (twips) */
#define PTYPE_YPOS       0x0A  /* LONG (twips) */
#define PTYPE_YSIZE      0x0B  /* LONG (twips) */
#define PTYPE_PICTURE    0x0C  /* HPIC */
#define PTYPE_BSTRING    0x0D  /* HLSTR */

int    FAR _export PASCAL VBXGetNumProps(HCTL control);
BOOL   FAR _export PASCAL VBXGetProp(HCTL control, int index, LPVOID value);
ERR    FAR _export PASCAL VBXGetPropByName(HCTL control, LPSTR name, LPVOID value);
int    FAR _export PASCAL VBXGetPropIndex(HCTL control, LPCSTR name);
LPCSTR FAR _export PASCAL VBXGetPropName(HCTL control, int index);
USHORT FAR _export PASCAL VBXGetPropType(HCTL control, int index);
BOOL   FAR _export PASCAL VBXIsArrayProp(HCTL control, int index);
BOOL   FAR _export PASCAL VBXSetProp(HCTL control, int index, LONG value);
ERR    FAR _export PASCAL VBXSetPropByName(HCTL control, LPSTR name, LONG value);

/* Events */
int    FAR _export PASCAL VBXGetEventIndex(HCTL control, LPCSTR name);
LPCSTR FAR _export PASCAL VBXGetEventName(HCTL control, int index);
int    FAR _export PASCAL VBXGetNumEvents(HCTL control);

/* methods */
BOOL FAR _export PASCAL VBXMethod(HCTL control, int method, long far * args);
BOOL FAR _export PASCAL VBXMethodAddItem(HCTL control, int index, LPCSTR item);
BOOL FAR _export PASCAL VBXMethodDrag(HCTL control, int action);
BOOL FAR _export PASCAL VBXMethodMove(HCTL control, long x, long y, long w, long h);
BOOL FAR _export PASCAL VBXMethodRefresh(HCTL control);
BOOL FAR _export PASCAL VBXMethodRemoveItem(HCTL control, int item);

/* pixel/twips conversions */
SHORT FAR _export PASCAL VBXTwp2PixY(LONG twips);
SHORT FAR _export PASCAL VBXTwp2PixX(LONG twips);
LONG  FAR _export PASCAL VBXPix2TwpY(SHORT pixels);
LONG  FAR _export PASCAL VBXPix2TwpX(SHORT pixels);

/* dynamic strings (HSZ) */
HSZ   FAR _export PASCAL VBXCreateCString(HANDLE segment, LPSTR string);
LPSTR FAR _export PASCAL VBXGetCStringPtr(HSZ string);
HSZ   FAR _export PASCAL VBXDestroyCString(HSZ string);
LPSTR FAR _export PASCAL VBXLockCString(HSZ string);
VOID  FAR _export PASCAL VBXUnlockCString(HSZ string);

/* color properties */
#define COLOR_SYSCOLOR          0x80000000L
#define MAKESYSCOLOR(iColor)    ((COLORREF)((iColor)|COLOR_SYSCOLOR))

/* pictures */
typedef struct PICTURE {
  BYTE Type;
  union {
    struct {
      HBITMAP  Bitmap;
      HPALETTE Palette;
    } Bitmap;
    struct {
      HANDLE Metafile;
      int xExtent;
      int yExtent;
    } Metafile;
    struct {
      HICON Icon;
    } Icon;
  } Data;
  BYTE unused0;
  BYTE unused1;
  BYTE unused2;
  BYTE unused3;
} PICTURE, FAR * LPPICTURE, NEAR * NPPICTURE;

#define PICTURE_EMPTY       0
#define PICTURE_BMP         1
#define PICTURE_META        2
#define PICTURE_ICON        3

HPIC FAR _export PASCAL VBXCreatePicture(LPPICTURE picture);
VOID FAR _export PASCAL VBXDestroyPicture(HPIC pic);
HPIC FAR _export PASCAL VBXGetPicture(HPIC pic, LPPICTURE picture);
ERR  FAR _export PASCAL VBXGetPictureFromClipboard(HPIC FAR *pic, HANDLE data, WORD format);
HPIC FAR _export PASCAL VBXReferencePicture(HPIC pic);

/* Basic language strings (HLSTR) */
HLSTR  FAR _export PASCAL VBXCreateBasicString(LPVOID buffer, USHORT len);
LPSTR  FAR _export PASCAL VBXGetBasicStringPtr(HLSTR string);
VOID   FAR _export PASCAL VBXDestroyBasicString(HLSTR string);
USHORT FAR _export PASCAL VBXGetBasicStringLength(HLSTR string);
ERR    FAR _export PASCAL VBXSetBasicString(HLSTR far *string, LPVOID buffer, USHORT len);

/* array property structure */
typedef struct ELEMENTSTRUCT {
  LONG   Value;
  USHORT NumElems;
  struct {
    USHORT Type;
    LONG   Index;
  } Element[1];
} ELEMENTSTRUCT, FAR * LPELEMENTSTRUCT, NEAR * NPELEMENTSTRUCT;

/* form files */
HFORMFILE FAR _export PASCAL VBXCreateFormFile(LONG len, LPVOID data);
BOOL      FAR _export PASCAL VBXDeleteFormFile(HFORMFILE file);

#ifdef __cplusplus
  }
#endif

#endif  /* __BIVBX_H */

