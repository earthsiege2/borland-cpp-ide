                 ************************************************
                  WELCOME TO CODEGUARD 16/32 FOR BORLAND C++ 5.0
                 ************************************************

********
CONTENTS
********

1.  How to Get Assistance
2.  Installation
3.  Important Information

------------------------
1. HOW TO GET ASSISTANCE
------------------------

If you have any problems, please read this file and other files in your
DOC subdirectory, and check the online help.  If you still need assistance, 
help is available from the following sources:

  1. Borland offers a wide variety of Technical Support plans
     providing a range of assistance from installation and general
     usage of Borland C++ to language syntax, programming, and
     debugging help. For information about these support programs,
     call 1-800-523-7070.

  2. For immediate assistance with everything from configuring Borland 
     C++ to C++ programming or debugging, call our C++ Programmer's 
     Advisor Lines ($2.95/minute, first minute free):

     1-800-782-5558 (MC/Visa)

  3. Borland's TECHFAX service. Call 1-800-822-4269 for a FAX
     catalog of technical document entries. For assistance outside of
     North America, contact your local Borland representative.

  4. Technical information on Borland C++ is available on the Internet
     via anonymous ftp at our ftp site ftp.borland.com and via the
     World Wide Web at the URL http://www.borland.com.


---------------
2. INSTALLATION
---------------

To install CodeGuard 16/32 for Borland C++ 5.0, run SETUP.EXE located in
\SETUP\CG5.


------------------------
3. IMPORTANT INFORMATION
------------------------

This section contains important information not found in the manuals, 
online Help, or online text files.


General
-------

If you are developing applications with CodeGuard across multiple
directories, take care when using relative paths (i.e. ..\foo.cpp).  If
your CodeGuard errors do not include source information, you may need to
specify in CGCONFIG.EXE the directory where your .OBJs reside rather 
than your source directory to compensate for relative paths.

Programs which use the obsolete IOStream 1.2 constructors will report
resource Leaks when built with CodeGuard.  Borland does not plan to 
update this code.

The log view in Turbo Debugger for Windows and Turbo Debugger for Win32
(TDW and TD32) scrolls when full.  If you are capturing CodeGuard 
messages in the log view and it appears that you are missing errors, 
see the application's .CGL file for a complete log.

CodeGuard cannot give accurate source positions for errors that
occur within inline functions.  The command line compiler defaults
to generating inline functions out of line when debugging information 
is turned on, but the IDE does not.  For debugging purposes, it is 
best to compile your CodeGuard enabled applications with "Out of line
inline functions" (-vi-) enabled.  In the IDE, look under 
Options|Project|Compiler|Debugging.

Conditions which produce the message "CodeGuard Error: That entrypoint
is not available (undefined dynalink)" will leave CodeGuard in an 
unstable state.  Until you restart Windows, or, under Windows NT, 
shutdown VDMs, all subsequent CodeGuard enabled applications run will 
produce a similar error.

The message "Resource from different RTL" will sometimes indicate a 
mixing of far and near memory allocation routines.  For example, 
allocating memory with faralloc() and releasing it with free() can 
produce this message even when used from the same RTL.

Versions of the OWL, BIDS and ObjectComponents libraries built with
CodeGuard enabled are provided.  These can be found in the LIB\CG 
directory.

If building an application using CodeGuard, any DLLs used by that
application must also have CodeGuard enabled if they share the same
version of the RTL DLL with the EXE.  If the DLLs use a different 
version of the RTL DLL or use the RTL linked statically, the DLLs need 
not be built with CodeGuard.  In either of these cases, however, it is 
important to link CG16.LIB or CG32.LIB *before* any of the import 
libraries for the other DLLs or you will see spurious resource leak 
errors.  See online help for TLINK for information on library 
ordering on the command line. In the IDE, you must enable 
Options|Environment|Project View | Show runtime nodes to see and 
change the library ordering in your project.

You should not run an application built without CodeGuard which uses the
RTL DLL at the same time as an application built with CodeGuard that 
uses the RTL DLL.

CodeGuard expects source files to be saved to disk and unmodified when
providing line number information.  If you have made modifications to
your source which are not committed to disk, or if you have committed
modifications to disk without rebuilding, CodeGuard may provide you
with code excerpts which are unrelated to the error detected.
In the IDE, turn on Options|Environment|Preferences|AutoSave|
Editor files to automatically save all dirty buffers before you build, run,
debug run, exit, or transfer.


Linker Errors with Undefined Symbols
------------------------------------
If your application includes any modules that are CodeGuard-enabled, you
must link CG16.LIB. The linker emits the following error message if you
don't use CG16.LIB and you attempt to link a CodeGuard-enabled module:

        Undefined symbol _CG_DESC in module FILENAME.CPP.
        Undefined symbol _CG_THIS in module FILENAME.CPP.

These are symbols which the compiler inserts into your modules to allow
CodeGuard to detect errors.  If you disable CodeGuard for an 
application, it is important to perform an entire rebuild of that 
application (rather than a make) to remove these symbols from your OBJs.


Using Map Files
---------------
A general debugging technique with CodeGuard is to use the .CGL file in
conjunction with map files for the modules in your program.  In the .CGL
file, the segments and offset of a problem within the module is given. 
These correspond directly to entries in the map file generated for the 
module. Be sure to generate a detailed map file with line numbers for 
every module in your application.

Once you have the map files, look at the first line of the error in
your .CGL file:

 >> Resource type mismatch: a(n) object was expected. delete(0x4AA7:0012)
 >> Call Tree: 0x5B27:01AA(=FOO.DLL:0x33:01AA)
 >> 0x610F:083D(=FOO.DLL:0x13:083D) 0x610F:321B(=FOO.DLL:0x13:321B)
 >> 0x610F:08FE(=FOO.DLL:0x13:08FE) 0x5B27:27EE(=FOO.DLL:0x33:27EE)
 >> 0x5B27:1AA0(=FOO.DLL:0x33:1AA0)

In this case, it is FOO.DLL:0x33:01AA. You know the problem is coming
from FOO, and it is in segment 0x33 offset 0x1AA. If you look at
the map file, you'll see which OBJ this is in. From the offset, you can
find out which function is causing the problem.  The line numbers 
section will give you file name and line number of the segment and
offset for a more detailed location of the problem.


CodeGuard 16 and Exceptions under Windows 95
--------------------------------------------
If running a 16-bit CodeGuard-enabled application under Windows 95 and
that application generates a GP fault, Windows 95 will trap the fault
and prevent CodeGuard from ever seeing it. When the OS traps the
fault, it will display a error dialog. If you select Close, the
application will be terminated without executing the shutdown code and
CodeGuard will report resource leaks. If you select Ignore, CodeGuard
will report everything except the fault.

Running your application under Windows 3.1 or Windows NT will allow
CodeGuard to provide you with the fault information. Under Windows 95,
you can use WinSpector and DFA to get the source file and line number
where the fault occurred, the type of fault, the call stack, and the
values of global and local variables at the time of the fault.


CodeGuard 32 and Exceptions under Windows 95
--------------------------------------------
There is an anomaly unique to Windows 95 which appears to be a result of
attempting to open and close a file while the operating system is
processing an exception.  As a result, previous reports in the CodeGuard
log file are overwritten by subsequent reporting.  However, the first
messages in a series of exceptions represent the real failure in the
application being debugged.  To view these reports, you need to take 
these steps:

1) Run your application.  When the exception occurs, Win95 displays
   an error dialog.

2) Do not close the system dialog.  Instead, bring up a DOS box or
   Explorer, navigate to the home directory of the executable you are
   debugging, and copy or rename the *.CGL file.

If, for any reason, you determine these subsequent reports to be of 
value, you can trap them in the same manner by capturing the CodeGuard 
log file at each system error dialog.
