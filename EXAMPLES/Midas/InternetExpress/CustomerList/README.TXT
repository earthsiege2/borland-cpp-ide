InternetExpress Demos

This directory contains three demo applications.

rdmCustomerData_bcb.bpr
  This sample MIDAS remote data module provides and resolves
  data used by the CustomerList examples.

CustomerList.bpr
  This web application displays a customer list.  Clicking
  on a link displays a master detail form allowing users
  to view and modify order data.  See additional
  comments at the top of CustomerListWebModule.cpp.

CustomerList_Custom.bpr
  This web application started out the same as CustomerList.bpr
  then was modified to use the InternetExpress custom components
  in the inexcustom sample directory.    See additional
  comments at the top of CustomerListWebModule_Custom.cpp.

CustomerList_Custom Setup
  Setup the same as CustomerList except you will also need to
  copy *.gif from the inetxcustom directory to your virtual
  directory.

CustomerList Setup

  1) You'll need a webserver and a virtual directory to put
  the executable (CustomerList.exe)
  and the web midas java script.  The virtual directory will need
  to allow execute and read access.

  2) Copy source\webmidas\*.js to the virtual directory.  Modify
  the project options of CustomerList.dpr so that the output directory
  is the virtual directory.  Build CustomerList.exe.

  3) Build and run (to register) the remote data module rdmCustomerData_bcb.exe.

  4) Use DCOMCNFG to allow the remote data module to be launched
  by the web server.  For IIS this means giving the IUSER_ guest
  account launch permissions.  Select rdmCustomerData_bcb object and
  click the Properties... button.  Select the Security page.  Select
  Use custom launch permissions.  Edit.  Add IUSER_(machinename).  Select
  Allow Launch.

  While your editing rdmCustomerData_bcb properties you may also want 
  to change the Identify to interactive user so that
  you can shut down the remote data module using the task manager.

  5) Access the web module by entering the name of you virtual
  directory URL followed by the name of the exe:

  For example: http://localhost/webpub/demo/CustomerList.exe

  If you have trouble getting the pages to display, verify that
  the java script files are available and that DCOM security is
  set up correctly.  

  Neither of these projects build with packages or dynamic RTL.
  However, if you change these options be sure the any DLL's 
  (including packages) required by customerlist.exe and rdmCustomerData_bcb.exe
  are available on the system path.
  DLL dependencies were removed from these projects by unchecking
  Project/Options/Packages/"Build with Runtime Packages" and 
  Project/Options/Linker/"Use dynamic RTL".  

  CGI applications can be run from the command line.  This is a 
  simple way to test and debug without using a Web Server.  The 
  action marked as "default" in you webmodule actions wil be executed.
  
  Note that IE 5 will provide more informative error messages when
  "Show friendly HTTP messages" is unchecked in 
  IE5's Tools/Internet Options/Advanced/Browsing.
  
  You can also use the scripttest.html file in the troubleshoot
  sample directory to verify that the InternetExpress 
  JavaScript include files are available from your web server.



