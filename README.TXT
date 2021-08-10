                         ****************************
                          WELCOME TO BORLAND C++ 4.5
                         ****************************

This README file contains important information about BORLAND C++.
For the latest information about Borland C++ and its accompanying programs,
read this entire file.

*****************
TABLE OF CONTENTS
*****************
1.  How to Get Assistance
          -- Sources of information
2.  Installation
          -- Installing Borland C++ on your hard disk
3.  New Features
4.  Important Information
          -- ObjectComponents Framework (OCF), OLE 2.0, and ObjectWindows 2.5
                   -- New file in WINDOWS\SYSTEM directory
                   -- New tools for registering OLE servers and
                      automation controllers
                   -- Registering a debugger to run an OLE server
                   -- Debugging OLE applications under Windows NT
                   -- WinSight
                   -- OLE error codes
                   -- OLE2 applications
                   -- OLE implementation under Windows NT
                   -- OLE2 compiler options
          -- VBX Support (including 32-bit)
          -- OpenHelp
                   -- OpenHelp with TASM and PowerPack
          -- Out of Memory and MAKESWAP
          -- Threads
          -- DDVT functions and RTTI
          -- Inline assembly and interrupts
          -- Creating 16-bit import libraries from .DEF files
          -- New Compiler Back-end and Pentium scheduler support
          -- New Compiler Switches and Linker Optimizations
          -- NOEHxx Libraries
          -- IDE/Integrated Debugging
          -- InProc servers and the IDE
          -- Turbo Debugger for Windows
          -- Using Tools with NTFS
          -- CTLDATA statements in Win32
          -- Running from a Windows 3.1 DOS Prompt
          -- Converting Borland C++ 3.1 to Borland C++ 4.5 code
          -- Floating-Point Formats
          -- WinRun
          -- AppExpert and OWL

*********************************************
1. HOW TO GET ASSISTANCE
*********************************************
If you have any problems, please read this file, the
HELPME.WRI and other files in your DOC subdirectory, and
check the on-line help. If you still have a question and
need assistance, help is available from the following sources:

  1. Borland offers a wide variety of Technical Support plans
     providing a range of assistance from installation and general
     usage of Borland C++ to language syntax, programming, and
     debugging help. For information about these support programs,
     call 1-800-523-7070.

  2. For immediate assistance with everything from configuring Borland C++
     to C++ programming or debugging, call our C++ Programmer's Advisor 
     Lines ($2/minute, first minute free):
     * Windows / Win32:  1-900-555-1002  or 1-800-782-5558 (MC/Visa)
     * DOS :   1-900-555-1004  or 1-800-368-3366 (MC/Visa)

     For assistance outside of North America, contact your local Borland 
     representative.

  3. To receive Technical Support for Borland Database Tools, please call:
     1-800-839-9777

  4. To receive Technical Support for Dashboard, call:
     1-800-953-9995 (MC/Visa) or 1-900-555-1010.

  5. For on-line access to the Borland CompuServe forums, with their 
     libraries of technical information and answers to common questions,
     type

     GO BCPPDOS   - for questions pertaining to DOS
     GO BDEVTOOLS - for questions pertaining to Borland Database Tools
     GO BCPPWIN   - for questions pertaining to Windows

     If you are not a member of CompuServe, see the enclosed
     special offer, and write for full details on how to receive
     a free IntroPak containing a $15 credit toward your first
     month's on-line charges.

  6. Borland's TECHFAX service. Call (800) 822-4269 for a FAX
     catalog of technical document entries. For assistance outside of 
     North America, contact your local Borland representative.

  7. Borland DLBBS. Dial (408) 431-5096 (up to 9600 baud, 8-N-1)
     for a host of free technical documents and example programs.

  8. Technical information on Borland C++ is available on the Internet
     via anonymous ftp at our ftp site ftp.borland.com.

  9. Subscribe to Borland's free electronic newsletter and get a regular
     update on the hottest programming tips and tricks.  Send your full
     name and address via electronic mail to tech-info@borland.com.

===============
2. INSTALLATION
===============
IMPORTANT!
Do not install Borland C++ 4.5 over previously installed Borland
C++ directories. The files in this distribution will not work with
previously shipped tools and libraries.  This is particularly true for
configuration files from previous shipping releases, like TDCONFIG.TDW
and BCCONFIG.BCW.

If you used Turbo Assembler 4.0 or the Borland Power Pack for DOS with
a previous installation of Borland C++, you must reinstall those
products after installing Borland C++ 4.5.

Also, be especially careful when using object files and libraries
from earlier Borland C++ versions with binaries created with this
release. There are several potential problems when linking with old
objects or libraries. Exceptions won't work correctly (destructors won't
get called) when a pre-BC4 stack frame is unwound due to an exception.

Do not use long file names when installing under Windows NT.

-----------------------------------------------
Installing Borland C++ 4.5 on your hard disk
-----------------------------------------------

For information about installing Borland C++ 4.5 from CD-ROM, see the CD
booklet.

To install Borland C++ 4.5 from floppy disks,
1.  Put the put disk 1 in your floppy drive.
2.  In Program Manager, choose File|Run.
3.  Type A:\INSTALL. (If your disk drive is not drive A, type the
    appropriate letter instead.)
4.  Choose OK.
5.  Follow the instructions on the screen.

Diagnostic and debug version of OWL are not installed to the hard
disk, but they can be copied from the CD or built from OWL source
using the makefile provided.

Users of ObjectWindows 1.0, Turbo Vision 1.0, or the Paradox Engine
should read the COMPAT.TXT file for information on using these
products with Borland C++ 4.5.

To get the Turbo Profiler, you must install the debuggers.

**** Note to Windows NT, OS/2, and Windows 95 users ****
If you intend to use Borland C++ under any of these platforms you must follow
some additional installation steps, which are listed in the INSTALL.TXT file.
If you fail to read and follow these configuration guidelines, you may
encounter several significant problems when using Borland C++.

For more information about installing and configuring Borland C++, see the
file INSTALL.TXT which can be found in the following locations:
* Borland C++ floppy disk 1 (INSTALL.TXT)
* Borland C++ CD-ROM (\BC45\INSTALL.TXT)


***************
3. NEW FEATURES
***************
Borland C++ 4.5 includes the following new features:
  * A complete encapsulation of OLE2 via new ObjectWindows classes
    and the ObjectComponents Framework, a new set of C++ classes. This
    allows you to develop applications that support the following
    16-bit OLE capabilities:
          - Linking and embedding containers
          - Linking and embedding servers
          - Automation servers (automatable servers)
          - Automation controllers
          - OLE clipboard operations
          - OLE drag and drop operations
          - In-place editing
          - OLE user interface, including menu merging, pop-up menu
            for activated object, verbs on container's Edit menu
          - Compound file storage
          - Registration
          - Localized strings for international support
          - Type libraries
  * IDE enhancements to TargetExpert, AppExpert, and ClassExpert to
    support the new OLE2 capabilities.
  * A new, faster, default compiler  back-end.
  * The 16-bit Profilers (TPROF and TPROFW) have returned to the product.
  * VBX support for 32-bit programs.
  * OpenHelp, a utility that enhances the functionality of Windows Help
    by allowing you to quickly search for topics across Help files, as
    well as the ability to add your own Help files (or remove them) from
    the search.
  * Simplify Dashboard, a convenient push-button utility panel for
    working more efficiently in Windows. With Dashboard, you can quickly
    launch your applications and easily switch between them. For 
    information about installing Dashboard, see the README.WRI file in the
    DASH directory.
  * Visio OLE Testbed, a subset of Shapeware's drag-and-drop drawing
    program. You can use Visio OLE Testbed to test OLE compound documents,
    objects, and automation with applications you create using Borland C++.
  * WinRun allows you to launch Window application from the MS-DOS prompt
    in Windows 3.1.
  * 32-bit OLE Preview allows you to compile OLE applications created with
    AppExpert, ObjectWindows, and the ObjectComponents Framework as 32-bit
    applications.  The final version of these libraries will be available
    as an update in March 1995.
  * For CD-ROM users, the complete Borland C++ manual set is now available
    online in the DynaText document viewing browser. Using DynaText, you 
    can search through the entire collection of books to find selected
    topics. You can view the contents of a single book page by page or 
    even print the complete documentation set. See the booklet in your
    Borland C++ 4.5 CD-ROM case for information about how to launch and 
    use the DynaText Browser.  Complete information on how to use DynaText
    is available in the online Help for the Browser.

************************
4. IMPORTANT INFORMATION
************************
This section contains important information not found in the manuals, 
online Help, or online text files.  Please read through this material
in its entirety.

----------------------------------------------------------------
ObjectComponents Framework (OCF), OLE 2.0, and ObjectWindows 2.5
----------------------------------------------------------------

New file In WINDOWS\SYSTEM directory
-------------------------------------
Borland C++ 4.5 installs a new file called BOCOLE.DLL in your
WINDOWS\SYSTEM directory. This library must be present in order for any
ObjectComponents program to execute.

New tools for registering OLE servers and automation controllers
------------------------------------------------------------------
The program tool AUTOGEN simplifies the task of writing proxy classes for an
automation controller. AUTOGEN reads type libraries (*.OLB; *.TLB) and emits
C++ source files containing the proxy objects. The REGISTER and GUIDGEN
utilities provide a means of registering and unregistering servers and
generating unique identifiers.

Registering a debugger to run an OLE server
-------------------------------------------
To make OLE invoke your server through the debugger, add the following
entry to the appropriate registration table.

     REGDATA(debugger,   "TDW")

You can specify a complete path to the debugger as well as command-line
options for the debugger.  Do not place the name of the server program on
the debugger command line. That will happen automatically.

If you want to choose at runtime whether to invoke the server with or
without the debugger, then each application or document must essentially
be registered twice, using different CLSIDs, progids, and descriptions. The
debug and non-debug entries will appear simultaneously in object browsers.
The debug invocation will have the /Debug flag on the command line; this
will in turn register the application class factory for the debug
registration instead of the normal registration. To test for the presence
of /Debug on the command line, call this function:

      TOcModule::IsOptionSet(amDebug);

If you register debugprogid, you should also register both debugdesc and
debugger. The debug description string distinguishes the debugging and
non-debugging registry entries for the user. If you register debugprogid,
the debugger entry will be used only for the debug registration.

These are typical debug entries:
     REGDATA(debugprogid,"MyDocument.Debug")
     REGDATA(debugdesc,  "MyDocument Debug Object")
     REGDATA(debugger,   "TDW")

There is also a debugclsid entry, but you don't have to register it yourself
because ObjectComponents generates it for you automatically by offsetting
the application's clsid.

The application registration is used for automation invocations, and
document registrations are used for linking and embedding invocations.
Any or all can be set up for dual registration.

For DLL servers, the registration debug entries are completely ignored.
To debug DLL servers, use the REGISTER  tool with the -Debug command-line
option. This will launch the DLL and break inside, allowing breakpoints to
be set. Do not close the message box until the debugging session is
complete.

Debugging OLE applications under Windows NT
-------------------------------------------

When debugging OLE applications under Windows NT 3.5, you may experience
a lock up if a program is forced to terminate.  This will happen when any
OLE application is running under the IDE and you explicitly request
Debug | Program Terminate, or implicitly request program termination by
closing a project.  This problem will not occur under Windows 3.1 or Windows
95, and will not happen with non-OLE applications.  Borland recommends that
all developers running under NT accept any updates to the NT OLE DLLs if and
when they are made available by Microsoft.

WinSight
--------
When WinSight spies on an ObjectWindows OLE container, it sometimes causes
corruption of the container's menus.  This behavior is expected.  If it
occurs, quit the application and start again.

OLE error codes
---------------
The file DOC\OLE_ERRS.TXT contains a list of the error codes OLE defines.
The list is sorted in numerical order.  Refer to it for help in interpreting
OLE-related error returns.

OLE2 applications
-----------------
Many commercial products are now offering their first generation of OLE2
enabled applications. Some of these applications are more complete
OLE implementations than others. Borland has observed several major
commercial applications that exhibit errant behavior when asked to
perform certain OLE operations. This is especially true when asked to
embed DLL servers, which many OLE applications appear to be
unprepared to handle. If you experience problems when using OLE
applications you create with Borland C++ in conjunction with third party
products, do not jump to the conclusion that the problem is yours.  Until 
OLE applications in the market place mature, it is not yet a safe assumption
that just because a product comes from a leading company that it is
robust. Changes introduced between OLE 2.0 and OLE 2.02 are
responsible for exposing some of these problems. When reporting bugs
in OLE applications to third parties, be sure to specify that they should
be developing and testing under the latest version of OLE.

OLE implementation under Windows NT
-----------------------------------
The 16 bit OLE implementation originally shipped in Windows NT 3.5 may
exhibit problems with DLL servers and may behave differently than the
version of OLE that MS recommends for Windows 3.1. Borland
recommends that all NT developers update to later versions of the NT OLE
DLLs if and when they are made available by Microsoft.

OLE2 compiler options
---------------------
1) 32 bit OLE2 projects must increase the identifier length to 55.
   You can do this with the command line compiler -i switch or in the IDE
   with the Options|Project|Compiler|Source edit field.
2) When using 32-bit OLE2, INC_OLE2 must be defined. You can do this on the
   command line with -DINC_OLE2 or in the IDE in the
   Options|Project|Compiler|Defines edit field.
3) When linking 16 or 32 bit OLE2 modules, the OLE2 import library
   (ole2w16.lib or ole2w32.lib) must come before the RTL import library 
   (import.lib or import32.lib respectively).


-----------------------------
VBX Support (including 32-bit)
------------------------------
The BIVBX102.DLL has been renamed to BIVBX11.DLL.

BIVBX11.DLL has been tested with a large number of VBX controls written
to the Microsoft Visual Basic 1.0 CDK specification. If you have a problem
with a specific control, make sure that it does not require VB 2.0 or
VB 3.0 CDK functionality. VBX 2.0 and 3.0 controls will usually display a
message saying that they require VB 2.0 or 3.0 support. In some cases,
though, the control might appear to work but exhibit instability. Please
contact the control vendor and explain the problem. They might have an
updated control or might be able to contact Borland to find a solution.

The following functions in BIVBX.H are limited to 16-bit only and should be
replaced as follows:

 Old (16-bit only)         New (16-bit and 32-bit)
 -----------------         -----------------------
 VBXGetBasicStringPtr      VBXGetBasicStringBuf
 VBXGetCStringPtr          VBXGetCStringBuf
 VBXGetEventName           VBXGetEventNameBuf
 VBXGetPropName            VBXGetPropNameBuf
 VBXLockCString            VBXLockCStringBuf
 VBXMethod                 N/A

To build any 32-bit application that uses VBX controls, link with
BIVBX32.LIB instead of BIVBX.LIB. VBX support for 32-bit applications
requires that the following files are present in the Windows
\SYSTEM directory at run-time:

All:           BIVBX11.DLL
Win32s:        BIVBX11S.DLL and BIVBX11.32S
Windows95:     BIVBX11C.DLL and BIVBX11.32C
NT:            BIVBX11N.EXE and BIVBX11.32N (installed in \SYSTEM32)

For more information, see the BIVBX.WRI file.

TargetExpert now manages libraries for VBX controls.   If you have an IDE
project which uses VBX controls, make the following change  to your project
to take advantage of TargetExpert support:
- In the project window, delete the bivbx.lib node.
- In the project window, right click on your EXE node.
- From the resulting SpeedMenu, select TargetExpert.
- In TargetExpert, enable the VBX checkbox and press OK.

----------------------------------
NT console applications and Win32s
----------------------------------
There is no Win32s console, so attempting to run a Win32 console
application without NT loaded will result in an error.

----------
OpenHelp
----------
See the online Help provided with OpenHelp (OPENHELP.HLP) for details on how
to use and configure this new search engine.

OpenHelp with TASM and PowerPack
------------------------------------
If you install TASM with BC4.5, you need to run the OpenHelp configuration
to configure your Help files. If you install PowerPack, the BCDOS.HLP file
will be overwritten. However, the .HLX index file will not include index
entries for the new BCDOS.HLP file. To fix this, remove BCDOS.HLP from
OpenHelp and re-add it so that a new .HLX file is generated. You can delete
the BHBC4.HDX file from the \BIN directory because it is no longer needed.

--------------------------
Out of Memory and MAKESWAP
--------------------------
If you get "Out of Memory" errors from DOS when running the command-line
tools, or if you have only 8 MB of RAM and have out-of-memory problems
building and using 32-bit applications, then create a swap file with the
MAKESWAP utility. Note that this applies to DOS only, not to DOS boxes
opened under Windows. MAKESWAP takes the size of the file to create in
KBytes, for example

  MAKESWAP 12000

will create a 12MB swap file in the current directory called EDPMI.SWP 
for use by Borland command-line tools.  To enable the swap file, use the
DPMI32 environment variable by issuing the following command at the DOS
prompt:

  set DPMI32=SWAPFILE <location of swap file>\EDPMI.SWP

You must clear this environment variable by issuing the command

  set DPMI32=

before running Paradox or other 16-bit DPMI-hosted executables, such as
Borland C++ 3.1 command-line tools.

-------
Threads
-------
When creating secondary threads, the _beginthread or _beginthreadNT
and _endthread() RTL functions must be used to ensure the proper RTL
initialization and cleanup. Using NT's CreateThread and ExitThread functions
will result in undefined behavior if an implicit or explicit call is made to
the RTL. Both exception handling and RTTI can lead to implicit RTL calls.

-----------------------
DDVT functions and RTTI
-----------------------
When compiling code that contains DDVT functions, do not use run-time type
information or you will receive an error message. In order to compile
without using run-time type information, compile all code that uses DDVTs
(for instance OWL 1.0x libraries and applications)with the -RT- switch
(Options|Project|C++ Options|Exception handling\RTTI in the IDE).

------------------------------
Inline assembly and interrupts
------------------------------
If your inline assembly code includes an interrupt call, the compiler does
not preserve any registers altered by the call. You must write code to save
and restore registers when using interrupt calls within inline assembly
code.

------------------------------------------------
Creating 16-bit import libraries from .DEF files
------------------------------------------------
Use the /o implib switch when creating 16-bit import libraries from .DEF
files to prevent implib from generating extensions for import entry module
names.

--------------------------------------------------
New Compiler Back-end and Pentium scheduler support
--------------------------------------------------
Borland C++ 4.5 includes two different compiler back-ends. By
default, the IDE uses BCWS32.EXE and the command line uses BCC32.EXE. 
(Both 32-bit compilers use the same front-end.) However, if your application 
requires special Pentium scheduler support, then you must use BCWS32A.EXE 
from the IDE or BCC32A.EXE from the command line. 

To configure the IDE so that it uses BCWS32A.EXE:
1) Use a text editor to open the file \WINDOWS\BCW.INI.
2) Add the following lines to the file and then save the file:
   
   [SERVER]
   Server32=BCWS32A.EXE

The BCWS32A and BCC32A compilers reorder certain assembly instructions
so that they take advantage of the Pentium scheduler. However,
BCWS32A.EXE and BCC32A.EXE have the disadvantage of longer compile
times. Because the executable files produced by BCWS32.EXE and
BCC32.EXE run on all 80386 systems and greater, it's recommended
that you always use these default compilers, except when you need the
special support of the Pentium scheduler.

If you use the BCC32A.EXE command-line compiler, you can specify Pentium
scheduler support using the -5 command-line option. To specify Pentium
scheduler support for the BCWS32A.EXE IDE compiler, open the Project
Options dialog box and check 32-bit Compiler|Processor|Pentium setting.
Note that the default compilers do not support these option settings.

BCC32.EXE and BCW32S.EXE evaluate function parameters in the order they are
pushed on the stack as opposed to BCC32A.EXE and BCW32A.EXE, which evaluate
parameters from left to right. This difference in the order of evaluation is
important if, for example, functions called in parameter evaluations cause
global side effects. According to the ANSI C/C++ language specifications,
the evaluation of function parameters is implementation dependent.

---------------------------------------------
New Compiler Switches and Linker Optimizations
----------------------------------------------
See your documentation for a description of the new compiler switches
for exception handling and a list of the new optimization capabilities
as well as the new command-line linker options.

----------------
NOEHxx Libraries
----------------
Purpose:

The NOEHxx libraries eliminates the overhead of exception-handling code in
the run-time library for users who don't need it and who do rely on any
libraries that require it.

How to use:

A NOEHxx library must be linked in before the standard runtime library.
For command-line tools this can be accomplished by specifing the appropriate
NOEHxx library on the BCC command-line, or making it the first library given
to TLINK.

For the IDE, add the approriate library to the project using AddNode.
To ensure the NOEHxx library is processed before the standard libraries,
turn on "Show Runtime Nodes" in the Options|Environment|ProjectView dialog.
From the project window you can move the library up and down using the
ALt-<arrow> keys. Be sure the NOEHxx library appears before other standard
libraries. Note: use NOEHWL.LIB when building DPMI16 programs.

What they do:

The NOEHxx libraries resolve calls to exception-related compiler helper
functions to dummy functions that return appropriate return values. They
also restore the pre-exception behavior of operator new to return NULL on
out of memory conditions. Non-exception enabled versions of setjmp() and
longjmp() are also provided.

Limitations:

Note: some features introduced in BC4.0 require exception handling.
These include the string class, BIDS container classes, the standard
OWL libraries, and RTTI.


Running from a Windows 3.1 DOS Prompt
-------------------------------------
If you run BCC or TLINK from a Windows DOS box and you get
out of memory errors, increase the XMS memory (in the 'Maximum'
setting) allocated for the DOS box by editing the appropriate .PIF
file (usually DOSPRMPT.PIF). BCC.EXE needs about 4MB to compile
medium-sized .CPP files, and might need more memory for large .CPP
files with debugging information.

NOTE: You must set the 'Maximum:' setting to the amount needed, not
      the 'Required:' setting.  Using the 'Required:' setting only
      sets aside memory for XMS, NOT for DPMI services and hence
      any amount set in the 'Required:' setting box is unavailable.

------------------------
IDE/Integrated Debugging
------------------------
Using the Microsoft DBWIN utility interferes with the Event log's ability to
display those same messages. To see those messages in the Event log, either
quit DBWIN or select Options|No Output in DBWIN.

DDE applications must be debugged in hard mode.

Hard-mode debugging does not work reliably under Windows NT version 3.1,
and might crash the WOW session. The IDE disallows users from selecting
hard mode on all stops, but setting a breakpoint on certain Windows
messages might cause the debugger to go into hard mode.

--------------------------
InProc servers and the IDE
---------------------------
You must delete bcwdef.* files from BC++ 4.0 or 4.02 in order to use the
OleRegisterServer and OleUnregisterServer tools from the IDE SpeedMenu.

--------------------------
Turbo Debugger for Windows
--------------------------
You can use TD32 to debug under Win32s. However, to do so, you must ensure
you use SVGA.DLL or equivalent support in the VideoDLL entry in the
[TurboDebugger] section of TDW.INI.

TD32 can support dual monitor debugging under Win32s. Ensure that a
monochrome adapter is installed in your machine and set the Mono=yes flag
in the [VideoOptions] section of TDW.INI:

       [VideoOptions]
       MONO=yes

---------------------
Using Tools with NTFS
---------------------
When you are using Borland C++ 4.5 tools under NTFS, be aware of assumptions
about file extensions. If Borland C++ 4.5 tools see an extension,
they assume no default. Therefore, with "bcc32 test.1.cpp", BCC32
spawns TLINK32 with "-ap c0x32.obj test.1, test.1, import32 cw32".
As TLINK32 sees an extension on test.1, it makes NO assumptions about
a .obj or .exe extension.  It attempts to look for test.1 (instead of
test.1.obj) and to create test. (instead of test.1.exe).

Embedded blanks in filenames are not currently supported. For instance, under
the Windows NT NTFS file system it is legal to have a file named
"This is an interesting file name.cpp". The response file processing in our
32-bit tools cannot handle this type of file.

16-bit tools running on NT cannot use NTFS filenames.

---------------------------
CTLDATA statements in Win32 
---------------------------
Different implementations of the Win32 API require different alignment rules 
applied to DLGITEMTEMPLATE data structures. For most dialog templates,
this difference has no effect because most programmers do not use this
statement. If, however, a dialog template uses the CTLDATA statement to
pass initialization data to a custom control, the data may not be passed
properly, or the dialog may fail to display properly or even at all, or the
program may receive a general protection fault. Borland's resource compilers
produce DLGITEMTEMPLATE data structures according to the alignment rules
applied by Win32s and Windows 95. Therefore, dialog templates using 
CTLDATA statements compiled using Resource Workshop, BRCC32, or BRCC may
not work in Windows NT. Note that this warning applies only if a template
uses the CTLDATA statement. All other templates work correctly in all
known implementations of the Win32 API.

-------------------------------------
Running from a Windows 3.1 DOS Prompt
-------------------------------------
If you run BCC or TLINK from a Windows DOS box and you get out of memory
errors, increase the XMS memory (in the 'Maximum' setting) allocated for
the DOS box by editing the appropriate .PIF file (usually DOSPRMPT.PIF).
BCC.EXE needs about 4MB to compile medium-sized .CPP files, and might
need more memory for large .CPP files with debugging information.

NOTE: You must set the 'Maximum:' setting to the amount needed, not
      the 'Required:' setting.  Using the 'Required:' setting only
      sets aside memory for XMS, not for DPMI services.  Thus, any
      amount set in the 'Required:' setting box is unavailable.

-----------------------------------------------------------
Converting Borland C++ 3.1 Windows Code to Borland C++ 4.5
------------------------------------------------------------
To get your BC++ 3.1 code to compile and run under Borland C++ 4.5,
modify your code to reflect three character types where compiler
errors occur when using the Borland C++ 4.5 RTL includes.
Alternatively, you can use the -K2 compiler option with the RTL
includes from BC++ 3.1. This option provides for only two character
types. (Note that -K2, a backward compatibility switch, is supported
only in the 16-bit compiler.) Also, use operator new[]() and
delete[]() syntax for class arrays.

Some 32-bit to 8-bit conversions allowed by ANSI are flagged by BCC32 with
"Conversion may lose significant digits in function XXXXX".  You can safely
ignore this message if you are doing certain types of 32-bit to 8-bit casts
(for instance, int to char) and you're not worried about losing significant
 digits in those cases.

----------------------
Floating-Point Formats
----------------------
Floating-point formats are a collection of formatting information used to
manipulate floating point numbers in certain runtime library functions such
as scanf() and atof().

This section discusses why you might get the error
FLOATING POINT FORMATS NOT LINKED : ABNORMAL PROGRAM TERMINATION and tells
you how to resolve it.

There are no current plans to fix this because it is not a bug. The
intent is to avoid linking the floating-point formats (about 1K of
overhead) when they are not required. The tradeoff is that the
programmer must explicitly request that the floating-point formats be
linked in for some programs that manipulate floats in a limited and
specific fashion.

Because you can get this error in a number of different ways, check the
following list of potential causes to find out how to resolve the error.
The causes are listed in order of most common to least common.

  1.  CAUSE:  Floating point set to <None>.  You have your
      floating point option set to None when it should be set to
      either Fast or Normal.

      FIX:  Set Floating Point to Fast or Normal.

  2.  CAUSE:  Either the compiler is over-optimizing, or the
      floating-point formats really do need to be linked in because
      your program manipulates floats in a limited and specific
      fashion. Under certain obscure conditions, the compiler will
      ignore floating point usage in scanf() (e.g., trying to
      read into a float variable that is part of an array contained
      in a structure.)

      FIX: Add the following to one source module:

           extern _floatconvert;
           #pragma extref _floatconvert

  3.  CAUSE:  Forgetting to put the address operator & on the scanf
      variable expression. For example,
       float foo;
       scanf("%f", foo);

      FIX: Change the code so that the & operator is used where it
      is needed.  For example, the above code should be
       float foo;
       scanf("%f", &foo);

--------
WinRun
--------
WinRun is a utility that lets you run a Windows program in a DOS box. This
utility is especially useful if you need to run Windows programs from a
DOS box in order to build certain ObjectWindows OLE-enabled applications.
It requires Windows 3.1 Enhanced mode. 

On the command line, you can optionally add /a or /w or /aw  switches.
(Autodetect and Wait mode)

The install program automatically adds WinRun to your startup group.

Switches for WinRun:

If you have selected the AutoDetect mode,(either by WinRun's command line
switch /a, or setting it in WinRun's system menu), you can simply type BCW
in a DOS box, and BCW will launch. You can still use WR to launch an
application, (for example to override the current Asynch mode setting
with wr.exe's /w or /a switches) However, this switch slightly
affects the loadtime of all DOS programs though it is minimal in cases
where you are using a disk caching.

The Asynchronous mode (selectable through WinRun's menu or
/w command line switch) causes the DOS box NOT to wait for the Windows
application to finish. Instead, it will always return with an exit code of 0.
In synchronous (wait) mode, the DOS box will be suspended until the Windows
application terminates, and the exit code will be propagated to the DOS box.

-----------------
AppExpert and OWL
-----------------
The value of the IDS_LISTNUM define in OWL has changed since BC++ 4.02.  If 
you have created an application in BC++ 4.0 or 4.02 using AppExpert, you will
receive redefinition warnings when rebuilding in BC++ 4.5.  To correct this
problem, update the .RH file for your project to match the new value for this
define.  Specifically, the following line

#define IDS_LISTNUM 32582

should be changed to

#define IDS_LISTNUM 32584
