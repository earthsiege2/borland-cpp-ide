#include "stdafx.h"
#include "ctrltest.h"

// C++Builder and MFC both have BEGIN_MESSAGE_MAP and END_MESSAGE_MAP 
// macros.  They are performing analogous tasks but in entirely different ways.  
// The defines made by MFC must be removed prior to including VCL.H to avoid 
// compiler errors
#undef BEGIN_MESSAGE_MAP
#undef END_MESSAGE_MAP
#include <vcl.h>

#include "SimpleCB.h"

void CTestWindow::OnTestCppBuilder()
{
	TRACE0("running dialog built with Borland's C++ Builder\n");

   TForm1 *aForm = new TForm1(NULL);
   aForm->ShowModal();
}

// The purpose of the following code is to call the VCL initialization code 
// once during application startup.  
static void foo(){
   Application->Initialize();
}
#pragma startup foo
