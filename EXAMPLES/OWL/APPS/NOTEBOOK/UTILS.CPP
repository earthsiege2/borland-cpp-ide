//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1995 by Borland International, All Rights Reserved
//    utils.cpp - module for misc. non-class routines
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/window.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <sys/timeb.h>
#include <dir.h>

#include "utils.h"
//----------------------------------------------------------------------------
static char fmtbuff[1024];
//----------------------------------------------------------------------------
void alert(LPSTR caption, LPSTR message)
{
  MessageBox(NULL, message, caption, MB_OK | MB_ICONEXCLAMATION |
  	MB_TASKMODAL);
}
//----------------------------------------------------------------------------
void bugout(char *fmt, ...)
{
  char *p;

  p = (char *) &fmt;
  wvsprintf(fmtbuff, fmt, p+4);
  alert("BugOut", fmtbuff);
}
//----------------------------------------------------------------------------
void log(char *fmt, ...)
{
  char msg[120];
  char *p;
  FILE *fh;
  struct timeb t;
  int secs;

  p = (char *) &fmt;
  wvsprintf(msg, fmt, p+4);

  ftime(&t);
  secs = (int) (t.time % 1000);
  sprintf(fmtbuff, "@%d.%d: %s\n", secs, t.millitm, msg);

  fh = fopen(DEBUGLOG, "a");
  if (fh) {
    fwrite(fmtbuff, strlen(fmtbuff), 1, fh);
    fclose(fh);
  }
}
//----------------------------------------------------------------------------
