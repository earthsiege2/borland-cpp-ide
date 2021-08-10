SimpleEcho Example
===================

 Server
 ------
  ISAPI_SimpleEcho.bpr
  CGI_SimpleEcho.bpr

 Client
 ------
  SimpleEchoClient.bpr


USAGE
=====


 ISAPI_SimpleEcho.bpr
 CGI_SimpleEcho.bpr
 --------------------
  Select Project | Build All

  Copy ISAPI_SimpleEcho.dll to c:\inetpub\scripts
  (For the CGI project copy CGI_SimpleEcho.exe instead)

  From a web Browser verify the server is present
  "http://localhost/scripts/ISAPI_SimpleEcho.dll"

  For the CGI project use the following URL instead:
  "http://localhost/scripts/CGI_SimpleEcho.exe"

  From the Default page of the Service, you can navigate through the
  exposed PortTypes and select the WSDL of the EchoService (named
  InteropTestPortType).


 SimpleEchoClient.bpr
 --------------------
  Open up the Project file
  Project | Build All
  Project | Run
  In the "Server URL" combo box select the server to use.
  Press SetRioURL button
  Enter Data into the "Send Data" fields
  Press the Button the relates to the Method to call
  the result should appear in the "Receive Data" field


Information
===========
  The Echo Services are based on the base service of Round 2 of the SOAPBuilders
  Interoperability Lab (see http://www.whitemesa.com/interop.htm ). It was
  created using the WSDLImport Wizard with the 'Generate Server Implementation'
  option enabled.

  The Client's interface was imported from the Server again using the WSDL
  Import wizard.

