//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 1999-2002 Borland Corp.  All Rights Reserved.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------
#include "CustomersImplU.h"

#include <corba.h>
USEIDL("Customers.idl");
USEFORM("CustomersImplU.cpp", CustomersImpl); /* TDataModule: DesignClass */ /* Customers.idl: CORBAIdlFile */
USEUNIT("Any2Variant.cpp");
USEUNIT("Customers_c.cpp");
USEUNIT("Customers_s.cpp");
//---------------------------------------------------------------------------
#pragma argsused
USE_STD_NS
int main(int argc, char* argv[])
{
  try
  {
     // Initialize the ORB and BOA
     CORBA::ORB_var orb = CORBA::ORB_init(argc, argv);
     CORBA::BOA_var boa = orb->BOA_init(argc, argv);
     TCustomersImpl* customers_CustomersObject = new TCustomersImpl(NULL);
     CBuilder_tie_Customers<TCustomersImpl> tie_customers_CustomersObject(*customers_CustomersObject, "CustomersObject", true);
     boa->obj_is_ready(&tie_customers_CustomersObject);
     // Wait for incoming requests
     cout << "Customers Server is waiting for requests..." << endl;
     boa->impl_is_ready();
  }
  catch(const CORBA::Exception& e)
  {
     cerr << e << endl;
     return(1);
  }
  return 0;
}
//---------------------------------------------------------------------------
