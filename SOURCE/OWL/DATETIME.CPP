//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1993, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.3  $
//
// Implementation of date/time helpers, mostly for Win16
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_DEFS_H)
# include <owl/defs.h>
#endif
#include <stdio.h>
#include <dos.h>

#if !defined(BI_PLAT_WIN32)

//
// Convert date and time structures to 64-bit FILETIME structure
// multiply seconds by 10^7 and adjust offset to Jan. 1, 1601
// adjustment from Jan.1, 1970 = 116,444,736,000,000,000 = 0x019DB1DED53E8000
// This code is for Win32 and OLE2 compatibility when using Win16
//
void
DateTimeToFileTime(struct date* dosd, struct time* dost, FILETIME FAR* pft)
{
  union {
    long udt;
    int  w[2];
  } u;
  u.udt = dostounix(dosd, dost);
  _BL = dost->ti_hund;
  _AX = u.w[0];
  _CX = u.w[1];
  asm mov  di,200
  asm mul  di
  asm mov  bh,0
  asm add  bx,bx
  asm add  ax,bx
  asm adc  dl,dh
  asm xchg ax,cx
  asm mov  bx,dx
  asm mul  di
  asm add  bx,ax
  asm mov  si,0
  asm adc  si,dx
  asm les  di,pft
  asm mov  ax,50000
  asm xchg ax,cx
  asm mul  cx
  asm add  ax,0x8000
  asm adc  dx,0
  asm mov  es:[di],ax
  asm xchg ax,dx
  asm xchg ax,bx
  asm mul  cx
  asm add  ax,bx
  asm adc  dx,0
  asm add  ax,0xD53E
  asm adc  dx,0
  asm mov  es:[di+2],ax
  asm xchg ax,dx
  asm xchg ax,si
  asm mul  cx
  asm add  ax,si
  asm adc  dx,0
  asm add  ax,0xB1DE
  asm adc  dx,0x019D
  asm mov  es:[di+4],ax
  asm mov  es:[di+6],dx
}

//
// Convert FILETIME structure to date and time structures
//
bool
FileTimeToDateTime(FILETIME FAR* pft, struct date* dosd, struct time* dost)
{
  union {
    long udt;
    int  w[2];
  } u;
  asm les  di,pft
  asm mov  dx,es:[di+6]
  asm mov  ax,es:[di+4]
  asm sub  ax,0xB1DE
  asm sbb  dx,0x019D
  asm jnc OK
  return false;
OK:
  asm mov  cx,50000
  asm div  cx
  asm xchg bx,ax
  asm mov  ax,es:[di+2]
  asm sub  ax,0xD53E
  asm sbb  dx,0
  asm div  cx
  asm xchg si,ax
  asm mov  ax,es:[di]
  asm sub  ax,(0x8000-5000)
  asm sbb  dx,0
  asm div  cx
  asm mov  dx,bx
  asm xchg ax,si
  asm mov  cx,200
  asm div  cx
  asm xchg ax,si
  asm div  cx
  asm shr  dx,1
  asm push dx
  u.w[0] = _AX;
  u.w[1] = _SI;
  unixtodos(u.udt, dosd, dost);
  asm pop  ax
  dost->ti_hund = _AL;
  return true;
}

//
// Win32/OLE2 compatible FILETIME support for 16-bit applications
// These functions to be incorporated into TDateTime class
//
int
FormatDateTime(struct date filed, struct time filet, void far* dest, int textlen)
{
  char buf[40];
  if (!textlen) {
    DateTimeToFileTime(&filed, &filet, (FILETIME FAR*)dest);
    return sizeof(FILETIME);
  }
  int len = sprintf(buf,"%d/%d/%d %02d:%02d:%02d.%02d",
                    filed.da_mon,filed.da_day,filed.da_year,
                    filet.ti_hour,filet.ti_min,filet.ti_sec,filet.ti_hund);
  if (textlen > len)
    textlen = len;
  memcpy(dest, buf, textlen);
  *((char far*)dest + textlen) = 0;
  return len;
}

#endif

//
// Public global function to format a file date+time string
//
int _OWLFUNC
FormatFileTime(FILETIME* pft, void far* dest, int textlen)
{
  char buf[40];
  int len;

  if (!textlen) {
    *(FILETIME FAR*)dest = *pft;
    return sizeof(FILETIME);
  }
#if defined(BI_PLAT_WIN32)
  SYSTEMTIME dt;
  FileTimeToSystemTime(pft, &dt);
  len = sprintf(buf,"%d/%d/%d %02d:%02d:%02d.%02d",
                dt.wMonth, dt.wDay, dt.wYear,
                dt.wHour, dt.wMinute, dt.wSecond, dt.wMilliseconds/10);
#else
  struct time filet;
  struct date filed;
  if (!(FileTimeToDateTime(pft, &filed, &filet)))
    return false;
  len = sprintf(buf,"%d/%d/%d %02d:%02d:%02d.%02d",
                filed.da_mon,filed.da_day,filed.da_year,
                filet.ti_hour,filet.ti_min,filet.ti_sec,filet.ti_hund);
#endif
  if (textlen > len)
    textlen = len;
  memcpy(dest, buf, textlen);
  *((char far*)dest + textlen) = 0;
  return len;
}
