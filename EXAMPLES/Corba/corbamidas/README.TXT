//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 1999 Inprise Corp.  All Rights Reserved.
//---------------------------------------------------------------------------
CustomersServer

This project is a CORBA server that implements the Customers interface in
customer.idl. The parameters of type any are used to pass MIDAS data packets.  
The implementation class (TCustomerImpl) converts data packets between
any and VARIANT.


CustomersClient

This project is a CORBA client that sends requests to the CustomersServer.
Like the CustomerServer, it converts data packets between any and VARIANT. 
The Refresh button retrieves a data packet containing the customers table.  
The Apply button is enabled after the data in the grid has been edited 
(row deleted, inserted, or cell edited).  When the Apply button is selected, 
a delta data packet describing the edits is sent to the server for resolution
against the customers table.

