//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/defs.h>
#include <stdio.h>
#include <string.h>
#include <dos.h>
#include "externs.h"
#include "wcdefs.h"
#include "info.h"

void
CGetTime(int *hour, int *minute, int *second, int * sec100)
{
#if defined(BI_PLAT_WIN16)
  _AH = 0x2C;
  geninterrupt(0x21);
  *hour = _CH;
  *minute = _CL;
  *second = _DH;
  *sec100 = _DL;
#else
  SYSTEMTIME systime;
  ::GetSystemTime(&systime);
  *hour = systime.wHour;
  *minute = systime.wMinute;
  *second = systime.wSecond;
  *sec100 = systime.wMilliseconds * 10;  
#endif
}

void
DisplayTime()
{
  static bool colon = true;

  int hour1, min1, sec1, s100;
  double CurTime = ChessTime[RunColor].totaltime;
  CGetTime(&hour1, &min1, &sec1, &s100);
  CurTime += (s100 - ChessTime[RunColor].sec100) * 0.01 +
    (sec1 - ChessTime[RunColor].second) +
    (min1 - ChessTime[RunColor].minute) * 60.0 +
    (hour1 - ChessTime[RunColor].hour) * 3600.0;
  min1 = int(CurTime / 60.);
  sprintf(buf, "%2.2d%c%02d", min1, colon ? ':' : ' ', int(CurTime - min1 * 60.0));
  TInfo->SetTimerText(buf);
  colon = !colon;
}

void
InitTime(CLOCKTYPE* clock)
{
  memset(clock, 0, sizeof(CLOCKTYPE));  
}

void
StartTime(CLOCKTYPE* clock)
{
  CGetTime(&clock->hour, &clock->minute, &clock->second, &clock->sec100);
}

void
StopTime(CLOCKTYPE* clock)
{
  int hour1, min1, sec1, s100;
  CGetTime(&hour1, &min1, &sec1, &s100);
  if (hour1 < clock->hour)
    hour1 += 24;
  clock->totalhours += hour1 - clock->hour;
  clock->totmin += min1 - clock->minute;
  clock->totalsecs += sec1 - clock->second;
  clock->tots100 += s100 - clock->sec100;
  clock->number++;
  clock->totaltime = clock->totaltime + (s100 - clock->sec100) * 0.01 +
    (sec1 - clock->second) + (min1 - clock->minute) * 60.0 +
    (hour1 - clock->hour) * 3600.0;
  clock->hour = hour1;
  clock->minute = min1;
  clock->second = sec1;
  clock->sec100 = s100;
}
