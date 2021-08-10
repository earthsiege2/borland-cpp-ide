/*-----------------------------------------------------------------------*
 * filename - textmode.c
 *
 * function(s)
 *        textmode - changes the current video mode to newmode
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1987, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.4.2.1 $        */

#include <_video.h>
#include <conio.h>

/*---------------------------------------------------------------------*

Name            textmode - changes the current video mode to newmode

Usage           void textmode(int newmode);

Prototype in    conio.h

Description     textmode selects a specific text mode.

                You can give the text mode (the argument mode) by
                using a symbolic constant from the enumeration
                type text_modes (defined in CONIO.H); if you use
                these constants, you must #include <conio.h>

                The text_mode type constants, their numeric
                values, and the modes they specify are given in
                the following table.

                ------------------------------------------------
                 Symbolic       Text mode
                 constant
                ------------------------------------------------

                 LAST           Previous text mode
                 BW40           Black & white, 40 columns
                 C40            Color, 40 columns
                 BW80           Black & white, 80 columns
                 C80            Color, 80 columns
                 MONO           Monochrome, 80 columns
                 C4350          Color, 43 lines/EGA, 50 lines/VGA

                When textmode is called, the current window is
                reset to the entire screen, and the current text
                attributes are reset to normal, corresponding to
                a call to normvideo.

                Specifying LAST to textmode causes the most-
                recently-selected text mode to be reselected.
                This feature is really only useful when you want
                to return to text mode after using a graphics
                mode.

Return value    None

*---------------------------------------------------------------------*/

void _RTLENTRY _EXPFUNC textmode( int newmode )
  {
  if( newmode == LASTMODE )  newmode = _video.currmode;
  _crtinit( newmode );
  _video.attribute = _video.normattr;
  }
