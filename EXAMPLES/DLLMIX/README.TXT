Calling 32-bit DLL's built with Borland C++ from non-BC Apps
============================================================
Currently, Borland C++ supports calling a DLL compiled with Borland C++ from
applications created with other tools only if they are dynamically bound to the
DLL. This is achieved by the application calling LoadLibrary at run-time to load
the DLL and then calling GetProcAddress to retrieve the entry points for the
functions exported from the DLL.

Static binding is not supported. From a C or C++ application, static binding is
achieved by linking import records (either import libraries or entries in the
IMPORTS section of the application's Module Definition File) to the calling
application. Using Delphi 2.0, static binding is achieved using a declaration
such as:

function Foo(parm: Integer): Integer; stdcall; external 'my.dll' name 'Foo';

You can use either C++ or Structured Exception Handling in the DLL. For best
results, exceptions should be caught within the scope of the DLL throwing the
exception. If the calling application is built with Borland C++, Delphi or
Microsoft Visual C++, the exception can be caught in the application calling the
DLL; however, Visual Basic does not seem to have an exception handlng syntax.

To create an EH-compatible 32-bit DLL, just replace the default startup code,
c0d32.obj for 32-bit DLL's, with c0d32dyn.obj and re-link the DLL. Using
command-line tools, the startup code is the first object module specified to
Tlink32. Using the Integrated Development Environment, select Options |
Environment | Project View and check Show run-time nodes. In the project window,
there will now be displayed entries for the startup module and all the libraries
which are automatically linked in depending on your target. Remove the node for
the startup code, c0d32.obj, and add c0d32dyn.obj in its place.

List of files
=============
README.TXT     - This file
C0D32DYN.OBJ   - Startup for building compatible DLL's

BCDLL.CPP      - Source and built DLL to be called
BCDLL.H        - Header file for the DLL and C/C++ consumers
BCDLL.DEF      - Module definition file
BCDLL.DLL      - Built version of the DLL
MAKEDLL.MAKE   - Makefile for building the test DLL

CTOBC.CPP      - C++ source for a test application calling BCDLL
CTOBC.RC       - Dialog resource
CTOBC.RH       - Resource header file
HANDSHAK.BMP   - Main window bitmap
HANDSHAK.ICO   - Application icon

MAKEBC.MAK     - Makefile for building CToBC with Borland C++
BCTOBC.EXE     - CToBC built with Borland C++
MAKEVC.MAK     - Makefile for building CToBC with Microsoft Visual C++
VCTOBC.EXE     - CToBC buiilt with Microsoft Visual C++

DELPHI2C.DPR   - Delphi 2.0 project for a test application calling BCDLL
DELPHI2C.EXE   - Built version of Delphi2C test application
MAIN.DFM       - Form resource
MAIN.PAS       - Pascal source for Delphi2C application

VBTOC.EXE      - Visual Basic 4.0 project for a test application calling BCDLL
VBTOC.FRM      - Form resource
VBTOC.MAK      - Project file
VB40032.DLL    - Visual Basic run-time library
