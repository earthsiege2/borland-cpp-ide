Copyright Borland International
ObjectWindows (C) 1997

Title: ISAPI Extension Example

Keywords: ISAPI HTTP internet server extensions

ISAPI lets you write interactive web pages without the high overhead
that CGI imposes.  CGI starts a new process for each client, but ISAPI
does not.

ISAPI extensions are implemented in DLLs.  This example project
produces a DLL called SimpleEx (simple extension.)  To see the DLL
work, you need a web server.  Consult your web server documentation
for details about installing ISAPI extensions.  Typically, however, 
you simply copy the DLL to the directory where the server expects 
extensions, restart the server, and then use the name of the DLL in
a URL, for example:

  http://myserver/scripts/SimpleEx.dll

The example includes the following files:

  ISAPIEXT.CPP          reusable OWL classes for creating
  ISAPIEXT.H            ISAPI server extensions

  ISAPISTR.H            additional classes for ISAPI streams

  SIMPLEEX.CPP          the code for a server extension
                        built from the classes in ISAPIEXT

  SIMPLEEX.IDE          for building from the IDE
  MAKEFILE              for building from the command line

This example was written by Michael Sawczyn.









