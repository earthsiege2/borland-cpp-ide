/*  bivbx.h

    Defines structs and functions for dealing with VBX controls.

*/
/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1993, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#ifndef __BIVBX_H
#define __BIVBX_H

#define STRICT
#include <windows.h>

#ifdef __cplusplus
  extern "C" {            /* Assume C declarations for C++ */
#endif

#include <pshpack1.h>

#ifndef __VBX_H

  #if ! defined(__DDEML_H) && ! defined(_HSZ_DEFINED)
    #define _HSZ_DEFINED
    typedef LPSTR          HSZ;
  #endif
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
BOOL WINAPI VBXInit(HINSTANCE instance, LPCSTR classPrefix);
void WINAPI VBXTerm(void);
BOOL WINAPI VBXEnableDLL(HINSTANCE instApp, HINSTANCE instDLL);

/* Controls */
HCTL WINAPI VBXGetHctl(HWND window);
HWND WINAPI VBXGetHwnd(HCTL control);
HCTL WINAPI VBXCreate(HWND windowParent, UINT id,
                                  LPCSTR library, LPCSTR cls,
                                  LPCSTR title, DWORD style,
                                  int x, int y, int w, int h,
                                  HFORMFILE file);

/* Dialogs */
BOOL WINAPI VBXInitDialog(HWND window, HINSTANCE instance, LPSTR id);

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

BOOL   WINAPI VBXGetArrayProp(HCTL control, int index, int element, LPVOID value);
BOOL   WINAPI VBXGetArrayPropByName(HCTL control, LPSTR name, int element, LPVOID value);
int    WINAPI VBXGetNumProps(HCTL control);
BOOL   WINAPI VBXGetProp(HCTL control, int index, LPVOID value);
ERR    WINAPI VBXGetPropByName(HCTL control, LPSTR name, LPVOID value);
int    WINAPI VBXGetPropIndex(HCTL control, LPCSTR name);
int    WINAPI VBXGetPropNameBuf(HCTL control, int index, LPSTR buffer, int len);
USHORT WINAPI VBXGetPropType(HCTL control, int index);
BOOL   WINAPI VBXIsArrayProp(HCTL control, int index);
BOOL   WINAPI VBXSetArrayProp(HCTL control, int index, int element, LONG value);
BOOL   WINAPI VBXSetArrayPropByName(HCTL control, LPSTR name, int element, LONG value);
BOOL   WINAPI VBXSetProp(HCTL control, int index, LONG value);
ERR    WINAPI VBXSetPropByName(HCTL control, LPSTR name, LONG value);

/* Events */
int    WINAPI VBXGetEventIndex(HCTL control, LPCSTR name);
int    WINAPI VBXGetEventNameBuf(HCTL control, int index, LPSTR buffer, int len);
int    WINAPI VBXGetNumEvents(HCTL control);

/* methods */
BOOL   WINAPI VBXMethodAddItem(HCTL control, int index, LPCSTR item);
BOOL   WINAPI VBXMethodDrag(HCTL control, int action);
BOOL   WINAPI VBXMethodMove(HCTL control, long x, long y, long w, long h);
BOOL   WINAPI VBXMethodRefresh(HCTL control);
BOOL   WINAPI VBXMethodRemoveItem(HCTL control, int item);

/* pixel/twips conversions */
SHORT  WINAPI VBXTwp2PixY(LONG twips);
SHORT  WINAPI VBXTwp2PixX(LONG twips);
LONG   WINAPI VBXPix2TwpY(SHORT pixels);
LONG   WINAPI VBXPix2TwpX(SHORT pixels);

/* dynamic strings (HSZ) */
HSZ    WINAPI VBXCreateCString(HANDLE segment, LPSTR string);
HSZ    WINAPI VBXDestroyCString(HSZ string);
int    WINAPI VBXGetCStringBuf(HSZ string, LPSTR buffer, int len);
int    WINAPI VBXGetCStringLength(HSZ string);
int    WINAPI VBXLockCStringBuf(HSZ string, LPSTR buffer, int len);
VOID   WINAPI VBXUnlockCString(HSZ string);
       
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
} PICTURE;

#define PICTURE_EMPTY       0
#define PICTURE_BMP         1
#define PICTURE_META        2
#define PICTURE_ICON        3

HPIC   WINAPI VBXCreatePicture(PICTURE FAR * picture);
VOID   WINAPI VBXDestroyPicture(HPIC pic);
HPIC   WINAPI VBXGetPicture(HPIC pic, PICTURE FAR * picture);
ERR    WINAPI VBXGetPictureFromClipboard(HPIC FAR *pic, HANDLE data, WORD format);
HPIC   WINAPI VBXReferencePicture(HPIC pic);

/* Basic language strings (HLSTR) */
HLSTR  WINAPI VBXCreateBasicString(LPVOID buffer, USHORT len);
VOID   WINAPI VBXDestroyBasicString(HLSTR string);
int    WINAPI VBXGetBasicStringBuf(HLSTR string, LPSTR buffer, int len);
USHORT WINAPI VBXGetBasicStringLength(HLSTR string);
ERR    WINAPI VBXSetBasicString(HLSTR far *string, LPVOID buffer, USHORT len);

/* form files */
HFORMFILE WINAPI VBXCreateFormFile(LONG len, LPVOID data);
BOOL      WINAPI VBXDeleteFormFile(HFORMFILE file);

/*
 * obsolete functions - these functions are limited to 16-bit only
 * and should be replaced as follows:
 *
 * Old (16-bit only)          New (16-bit and 32-bit)
 * -----------------          -----------------------
 * VBXGetBasicStringPtr       VBXGetBasicStringBuf
 * VBXGetCStringPtr           VBXGetCStringBuf
 * VBXGetEventName            VBXGetEventNameBuf
 * VBXGetPropName             VBXGetPropNameBuf
 * VBXLockCString             VBXLockCStringBuf
 * VBXGetProp w/ELEMENTSTRUCT VBXGetArrayProp            
 * VBXSetProp w/ELEMENTSTRUCT VBXSetArrayProp
 * VBXMethod                  not supported
 *
 */

#if !defined(__FLAT__)

LPSTR  WINAPI VBXGetBasicStringPtr(HLSTR string);
LPSTR  WINAPI VBXGetCStringPtr(HSZ string);
LPCSTR WINAPI VBXGetEventName(HCTL control, int index);
LPCSTR WINAPI VBXGetPropName(HCTL control, int index);
LPSTR  WINAPI VBXLockCString(HSZ string);
BOOL   WINAPI VBXMethod(HCTL control, int method, long far * args);

typedef struct ELEMENTSTRUCT {
  LONG   Value;
  USHORT NumElems;
  struct {
    USHORT Type;
    LONG   Index;
  } Element[1];
} ELEMENTSTRUCT, FAR * LPELEMENTSTRUCT, NEAR * NPELEMENTSTRUCT;

#endif

#include <poppack.h>

#ifdef __cplusplus
  }
#endif

#endif  /* __BIVBX_H */

