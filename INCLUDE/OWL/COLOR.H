//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.3  $
//
// Definition of class TColor [Backward compatible header]
//----------------------------------------------------------------------------
#if !defined(OWL_COLOR_H)
#define OWL_COLOR_H

#if defined(NO_OWL2_COMPAT)
# pragma message owl/color.h has been replaced by winsys/color.h
#endif
#if !defined(OWL_DEFS_H)
# include <owl/defs.h>
#endif
#if !defined(WINSYS_COLOR_H)
# include <winsys/color.h>
#endif

//
// For compatiblity only. See MkRGB in winsys/color.h
//
#define OWLRGB(r,g,b) \
 ((COLORREF)(((uint8)(uint16)(r) | ((uint16)(g)<<8)) | \
                                   (((uint32)(uint8)(uint16)(b))<<16)))
#endif  //  OWL_COLOR_H
