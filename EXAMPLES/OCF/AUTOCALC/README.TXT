Overview 
======== 
The AUTOCALC project is an example illustrating OLE 2 automation
servers and controllers. The list below describes the targets
produced by the example:

  ACALIPS.DLL  :  DLL version of OLE 2 automation server.
  AUTOCALC.EXE :  EXE version of OLE 2 automation server.
  CALLCALC.EXE :  Automation controller which exercises the
                  DLL and EXE automation servers.

The following sections describe how to build, register and run
the samples created AUTOCALC using either the Integrated
Development Environment (IDE) or the command line tools of
Borland C++. The section 'Additional Information' provides some
interesting insights on the features illustrated by the samples.


Building the Samples from the IDE
================================= 
To build the targets described above, open the AUTOCALC.IDE
project and select the 'Build All' option from the Project menu.
NOTE: It is important to select 'Build All' as the DLL and EXE
servers are built from the same sources but require different
compiler configurations.


Registering the Servers from the IDE
====================================
The DLL and EXE servers must be registered with OLE before
running the controller. After building the targets, register the
automation servers using the steps described below:

i.  Right-mouse click on the ACALIPS.DLL node within the Project window.
    (This activates the local menu).

ii. Select the 'Special|Register OLE Server' menu option.
    (This registers the DLL Server with OLE).

Repeat the above steps with the AUTOCALC.EXE node to register the
EXE server with OLE.


Running the Controller from the IDE
===================================
To exercise the DLL and EXE servers, activate the CALLCALC.EXE
node and select the Run option from the Debug menu. CALLCALC
looks for a command line argument string consisting of numbers
between 1 and 6. The following table describes how each number
is interpreted by the controller:

    Number in CmdLine         Action performed by Controller
    ---------------------------------------------------------------
      1                       Binds to EXE Server via CLSID
      2                       Binds to EXE Server via progid
      3                       Binds to DLL Server via CLSID
      4                       Binds to DLL Server via progid
      5                       Binds to EXE Server via CLSID in debug mode
      6                       Binds to EXE Server via progid in debug mode


If no command line string is specified, CALLCALC.EXE defaults to
"1234" - the EXE and DLL Servers are activated via both CLSID
and progids in non-debug mode. You can specify an argument
string by selecting Environment|Debugger|Run_Arguments from the
Options menu. For example, the string "135" exercises the
servers by binding via CLSIDs only.


Using the command line tools 
============================ 
A MAKEFILE is provided for building the samples of this project.
Since OLE applications need to perform several tasks, (such as
registering with the system or generating TypeLibrary files)
which require Windows, you must run the MAKEFILE at a DOS prompt
from Windows and make sure that the Borland C++ WINRUN utility
is properly configured. (See UTILS.TXT for more information
about WINRUN).


Building the Samples from the command line
==========================================
To build the targets described above, simply execute the MAKE
command from the EXAMPLES\OCF\AUTOCALC directory. NOTE: The
MAKE utility will execute the AUTOCALC.EXE program to generate a
TypeLibrary file which is then used to build CALLCALC.EXE.


Registering the Servers from the command line
=============================================
The MAKE utility will automatically invoke the REGISTER.EXE
utility to register the DLL version of the automation server.
The MAKE utility also executes the AUTOCALC.EXE application (to
generate a TypeLibrary file) which allows the EXE server to be
registered.


Running the Controller from the command line
============================================
To exercise the DLL and EXE servers, run CALLCALC.EXE utility
using the following command:

        wr  callcalc.exe

CALLCALC looks for a command line argument string consisting of
numbers between 1 and 6. The following table describes how each
number is interpreted by the controller:

    Number in CmdLine         Action performed by Controller
    ---------------------------------------------------------------
      1                       Binds to EXE Server via CLSID
      2                       Binds to EXE Server via progid
      3                       Binds to DLL Server via CLSID
      4                       Binds to DLL Server via progid
      5                       Binds to EXE Server via CLSID in debug mode
      6                       Binds to EXE Server via progid in debug mode


If no command line string is specified, CALLCALC.EXE defaults to
"1234":  the EXE and DLL Servers are activated via both CLSID
and progids in non-debug mode. The following command exercices
the servers by binding via CLSIDs only.

        wr  callcalc.exe 135

Note that the Accumulator field of the CALLCALC dialog box is updated by an
automation callback from the calculator using a report object passed to the
callculator by the controller. Try manually entering numbers in the calculator.


Additional Build Information
======================
This sample illustrates building both a DLL and EXE server from
one set of sources. The file WINMAIN.CPP takes advantage of
compiler macros to provide separate OLE registration values and
program entry point (LibMain vs. WinMain) for the DLL and EXE
versions. NOTE: Since the DLL and EXE server use the same set of
.CPP files, make sure that you use the Build_All option when
rebuilding either servers after modifying the sources.

This sample also illustrates the performance advantage of DLL
servers: the passes which bind to the DLL server are noticeably
faster than the ones which bind to the EXE version.


Automated Classes - examples of various types of automated classes
=================

class TCalc        application object, contains TCalcWindow as a member object
class TCalcWindow  calculator dialog box with window property accessors
class TCalcButton  simple encapsulation of a dialog button
class TButtonList  collection of calculator buttons, exposed for automation
class TCalcArray   collection of simple integers, not related to calc function


Automation Features Demonstrated
================================

Returning C++ objects - TCalcWindow as a property of TCalc
C++ objects as arguments - LookAtWindow method with TCalcWindow argument
External object as property - TUpdate object binding to external IDispatch*
Callback via external object - Calling method on TUpdate proxy object
Exposing collection of intrisic types - interger array exposed as collection
Exposing collection of objects - TButtonList collection of TCalcButton objects
Enumeration of C++ enumeration - translation of C++ operators to text strings
Help strings, help context IDs, and help files for automation
Localization of names and help - resourced translations for German language
Registration of error code translator - function to convert codes to strings


Running AUTOCALC from a VBA application
=======================================

BASIC scripts are supplied which bring up and control the calculator.
Note that the script first trys to connect to a running instance of AUTOCALC,
then, if that fails, will create a new instance of AUTOCALC.
The progid, "OCCalc.Application", may be changed to "OCCalc.DLLServer".
The steps to run the AUTOCALC.BAS script from Microsoft Excel are as follows:
  Invoke EXCEL.EXE
  Menu: Insert..Macro..Module
  Menu: Insert..File..(select All Files(*.*), select directory) AUTOCALC.BAS
  At this point script will run with F5 or the VB run icon (green triangle).
  To enable browsing the registered type library for AUTOCALC do as below:
  Menu: Tools..References..check: Automated Calculator 1.0 Application
  The F2 key brings up the Object Browser, select Library: OCCalc.Application
To enable Excel to use German scripts, German type libraries must be setup:
  VBADE.OLB must be present, normally in the WINDOWS\SYSTEM directory
  XLDE50.OLB must be present, normally in the same directory with Excel
  In order to use the object browser, the German typelib must be registered:
  Run AUTOCALC with the command line: -Language=9 -Typelib=ACALCGER
  Create a new workbook with File New or by invoking Excel
  Menu: Insert..Macro..Module (or use the icon with a bunch of linked boxes)
  Menu: Tools..References..Browse..navigate to and select XLDE50.OLB
  Ignore the following following error message and exit the dialogs with OK:
    "Object library's language setting incompatible with current project"
  Menu: Tools..References..Browse..navigate to and select VBADE.OLB
  The German type libraries are now registered in the system registry.
To run the German language script, ACALCGER.BAS, perform the steps below:
  Menu: Tools..Options..Module General..Language/Country..German/Germany
  Menu: Insert..File..(select All Files(*.*), select directory) ACALCGER.BAS
  Menu: Tools..References..check: Automatisierte Taschenrechner-Anwendung 1.0
  Bring up the Object Browser, select Library: OCCalc.Application
  
