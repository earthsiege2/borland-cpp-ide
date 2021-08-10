/////////////////////////////////////////////////////////////////////////////
// AXFORM.H - Base class used by Active Forms
//
// $Revision:   1.6.1.0  $
// $Date:   04 Jan 2000 15:34:54  $
//
// Copyright (c) 1998,2000 Borland International
/////////////////////////////////////////////////////////////////////////////
#ifndef __AXFORM_H
#define __AXFORM_H

#include <forms.hpp>

// TActiveForm: Base class for a VCL Form exposed as an OCX Control
//
class TActiveForm : public Forms::TCustomActiveForm
{
  typedef Forms::TCustomActiveForm inherited;
public:
  __fastcall virtual TActiveForm(HWND ParentWindow): Forms::TCustomActiveForm(ParentWindow) {}
  __fastcall virtual TActiveForm(TComponent* AOwner): Forms::TCustomActiveForm(AOwner) {}
};


#endif	//	__AXFORM_H
