//-------------------------------------------------------------------------
// vclmin.h - includes min hdr files needed for a blank form and a button
//
// $Revision:   1.4.1.0.1.1  $
// Copyright (c) 1997, 2002 Borland Software Corporation
//-------------------------------------------------------------------------
#ifndef VCLMIN_H
#define VCLMIN_H

// Instruct VCL.H to not include Database related headers
//
#define INC_VCL
#if !defined(NO_VCLDB_HEADERS)
#define NO_VCLDB_HEADERS
#endif

#include <basepch0.h>

#endif // VCLMIN_H
