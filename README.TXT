                   Welcome to Borland C++ 4.0
                   --------------------------

  This README file contains important information about Borland C++.
  For the latest information about Borland C++ and its accompanying
  programs and manuals, read this entire file.

-----------------
TABLE OF CONTENTS
-----------------
1.  How to Get Help
2.  Installation
3.  Features
     -Compiler
     -Linker
     -IDE
     -Turbo Debugger
     -Resource Workshop
     -ObjectWindows Library (OWL)
     -VBX Support
     -Documentation
4.  Important Information
     -General
     -New Tools
     -Running from a Windows 3.1 DOS Prompt
     -C/C++ Language Changes
     -Developing for NT
     -Libraries and Startup Code
     -New Compiler and Linker Switches
     -Converting Your Borland C++ 3.1 Windows Code to Borland C++ 4.0
     -Class Libraries
     -Casting Macros
     -IDE/Integrated Debugging
     -Floating Point Formats
     -Turbo Debugger for Windows
     -Using Tools with NTFS

------------------
1. HOW TO GET HELP
------------------

  If you have any problems, please read this file, the
  HELPME!.DOC and other files in your DOC subdirectory, and
  check the on-line help and the Borland C++ manuals first.
  If you still have a question and need assistance, help is
  available from the following sources:

  1. For instant on-line access to the Borland forums with
     their libraries of technical information and answers
     to common questions, type

        GO BCPPDOS     - for questions pertaining to DOS

         or

        GO BCPPWIN     - for questions pertaining to Windows

     If you are not a member of CompuServe, see the enclosed
     special offer, and write for full details on how to receive
     a free IntroPak containing a $15 credit toward your first
     month's on-line charges.

  2. Borland offers a wide variety of Technical Support plans
     providing a range of assistance from installation and general
     usage of Borland C++ to language syntax, programming, and
     debugging help. For information about these support programs,
     call 1-800-523-7070.

  3. Borland's TECHFAX service. Call (800) 822-4269 for a FAX
      catalog of technical document entries.

  4. Borland DLBBS. Dial (408) 431-5096 (up to 9600 baud, 8-N-1)
      for a host of free technical documents and example programs.

  5. For immediate assistance with everything from configuring Borland C++
      to programming or debugging, call our C++ Programmer's
      Advisor Lines ($2/minute, first minute free):
            * Windows / Win32:	1-900-555-1002  or 1-800-782-5558 (MC/Visa)
            * DOS :		1-900-555-1004  or 1-800-368-3366 (MC/Visa)

---------------
2. INSTALLATION
---------------
Important!
----------
Do not install Borland C++ 4.0 files over previously installed Borland
C++ directories. The files in this distribution will not work
with previously shipped tools and libraries.  This is particularly
true for configuration files from previous shipping
releases, like TDCONFIG.TDW and BCCONFIG.BCW.

Also, be especially careful when using object files and libraries
from Borland C++ 3.1 with binaries created with this release. There are 
several potential problems when linking with old objects or libraries. 
Exceptions won't work correctly (destructors won't get called) when a 
pre-BC4 stack frame is unwound due to an exception. Also, if a constructor 
or destructor compiled with a pre-BC4 compiler is involved in exception 
unwinding, trouble may occur. Another potential problem is when an RTTI class 
is shared with pre-BC4 code; some cases of that will be caught by the linker,
but others may fail mysteriously. Try using the -K2 switch to get pre-BC4 code
to link. Note: these problems are C++ specific. C objects between versions
should be more readily compatible.

Installing Borland C++ 4.0 on your hard disk:
--------------------------------------
Installing from floppy disks:
	1. Select File|Run from Windows 3.1, Windows for Workgroups 3.1x,
	   or Windows NT.
	2. Enter A:INSTALL (or B:INSTALL) on the input line.
	3. Under "Installation Options", you have the option of not
	   installing Win32s, which should be turned off if you are 
	   installing under Windows NT.
          (NOTE that BCW does not run under NT, so if you are only using
          NT, you may wish to not install it.)
	4. Fill in directories as appropriate, and INSTALL will create
          appropriate Windows groups, install Win32s, and install the
	   new Borland C++ 4.0 software according to the directories you select.

Installing from the CDROM:
	1. Go to the CDROM, and change directories to INSTALL.
	2. Select File|Run from Windows 3.1, Windows for Workgroups 3.1x,
	   or Windows NT.
	3. Enter X:INSTALL on the input line (where X: is your CDROM drive).
	4. Under "Installation Options", you have the option of not
	   installing Win32s, which should be turned off if you are
	   installing under Windows NT.
	5. Fill in directories as appropriate, and INSTALL will create
	   appropriate Windows groups, install Win32s, and install the
	   new Borland C++ 4.0 software according to the directories you select.

To use the built-in transfer tools and Help, make sure their location is
in your path (the \BIN directory for Borland C++ 4.0).

After installing, make sure your path is set correctly, and restart 
Windows before using Borland C++ 4.0.

NOTE: If you want to install the Win32s debug kernel, use the
SWITCH.BAT file provided with the Microsoft Win32s tools, found on the
NT SDK CD-ROM distribution.  This will ensure that the proper files
are copied to the appropriate places.  Not copying the files correctly 
will result in obscure load errors. 

Configuring Borland Pascal and Borland C++
------------------------------------------
The install program for Borland C++ 4.0 will configure your system to
allow the use of Borland C++ 4.0 and Borland Pascal 7.0 on the same
machine.  As long as you have installed Borland Pascal prior to
(rather than after) installing Borland C++ there are very few
guidelines you must follow:

- The two Windows hosted IDEs may not be run simultaneously.

- Each must use their respective copies of tools and utilities that
  depend on debug information, most notably Turbo Debugger for Windows
  (TDW).  You may find it useful to rename the Borland Pascal version
  of TDW.EXE to something like BPTDW.EXE to avoid confusing filenames
  in your path.

- Both versions of TDW may not be run simultaneously.

- Make sure that old copies of TDW.INI are removed from your system. 
  (Running the utility TDWINI.EXE will make sure that this takes
  place.)

That's all there is to it!  To reduce disk space requirements, you
may wish to remove duplicate versions of utilities that do not
require debug information, such as WinSight and Resource Workshop. 
In these cases, you will want to use the versions that came with
Borland C++ 4.0 so that you will have the latest features.

If you wish to use TDWGUI.DLL with TDW version 3.1 you need to
manually add UseTimer=Yes to the VideoOptions section of TDW.INI. 
Note that this option should not be set when using TDW version 4.0. 
This means that you would need to hand change your TDW.INI file each
time you switched between versions of TDW.  For this reason, we
recommend the non-windowed video DLLs (such as SVGA.DLL) for
customers who debug both BP and BC applications.

If you are installing Borland Pascal 7.0 AFTER Borland C++ 4.0 has
been installed, you will have to manually change the system settings
that allow these products to coexist:

In your system.ini file, check your [386Enh] section for multiple
entries for the device TDDEBUG.386.  Remove duplicate entries of
TDDEBUG.386 so that only the version from Borland C++ is loaded.  On
disk, you may also want to rename or remove the BP7 versions of
TDDEBUG.386 and TDWIN.DLL to avoid their accidental loading.  You
must restart Windows after making changes to system.ini.

Win32s and minimum swap file size
---------------------------------
Borland recommends that you have a minimum of 12 MB of memory available to
run Win32s applications.  For example, if your machine has 8 MB of memory
available to Windows, you should configure your "Virtual Memory" (swapfile)
to at least 4 MB.  This will reduce the risk of out-of-memory errors 
occuring in Win32s.

NT console applications and Win32s
----------------------------------
There is no Win32s console, so attempting to run a Win32 console
application without NT loaded will result in an error.

Changes to SYSTEM.INI file
--------------------------
The install program makes these changes to the SYSTEM.INI file:

  1) Adds "device=c:\bc4\bin\windpmi.386" to support our 32-bit tools.
  2) Adds "device=c:\bc4\bin\tddebug.386" to support our debugger.


Configuring the Windows NT command prompt
-----------------------------------------
To run 16-bit protected-mode programs (bcc, tlink) under an NT command prompt
you need to add the following line to CONFIG.NT:

  ntcmdprompt

Under the default NT command-line prompt, DOS COMMAND.COM is run after
returning from a TSR (such as RTM.EXE which bcc and tlink load). Adding the 
above line will cause the original NT CMD.EXE to be run.


Outdated versions of Win32s
---------------------------
If you are running an outdated version of Win32s, the INSTALL program will
instruct you to remove it before installation.  To remove an old
version of Win32s perform the following steps:

  1. Change directory to the WINDOWS directory on your hard drive.  This
     is most likely C:\WINDOWS.

  2. Edit the SYSTEM.INI file and remove the line in the [386Enh]
     section that reads:

       device=C:\WINDOWS\SYSTEM\WIN32S\W32S.386

     (The actual path in the above line may be different to reflect your
      configuration.)

  3. Change directory to the SYSTEM subdirectory.

  4. Remove the following files:

       W32SYS.DLL
       WIN32S.INI
       WIN32S16.DLL

  5. Change directory to the WIN32S subdirectory.

  6. Remove all files here.

  7. Change directory back to SYSTEM and remove the WIN32S subdirectory.

You will now be ready to run the INSTALL program.  Be sure to select
<Install Win32s> in the INSTALL program so that the newer version of Win32s
will be installed on your system.


-----------
3. FEATURES
-----------

Compiler:
---------
  - Support for writing 16 and 32-bit Windows applications that target
    Windows 3.1, Win32s and Windows NT, and 16-bit DOS applications.
  - Pentium support.
  - Support for ANSI C++ exception handling, structured exception handling
    under C, and mixed C/C++ exception handling. All exception handling
    constructs are available for both 16- and 32-bit.
  - Additional optimizations and faster compile time.
  - Support for ANSI C++ operator new[] and operator delete[].
  - Runtime Library support for the ANSI C++ string class.
  - Support for ANSI C++ runtime type identification (RTTI).
  - Support for ANSI C++ new style casts dynamic_cast, static_cast, const_cast,
    and  reinterpret_cast.
  - Support for three character types as provided in ANSI C++.

Linker (16-bit and 32-bit):
---------------------------
  - Now handles binding of resources; no need for a separate RC or
    RLINK step.
  - Linker debug capacity expanded.

IDE
---
  - 16-bit DOS and Windows plus 32-bit Windows targeting from a single IDE.
  - Integrated GUI debugging for 16-bit Windows applications.
  - Includes both 16- and 32-bit tools (compiler, linker, resource 
    compiler, resource binder, and library manager)  
  - A new project manager that supports multiple targets, drag-and-drop,
    and Style Sheets for associating options. 
  - AppExpert, which simplifies the process of creating
    ObjectWindows applications through code generation.
  - ClassExpert, which simplifies adding and managing classes in
    your AppExpert application.
  - Transfers, Settings Notebook, SpeedMenus, and a configurable SpeedBar.
  - Expanded editor support, including column blocking and window 
    splitting.  TEMC now called KEYMAPR.
  
Turbo Debugger:
---------------
  - Turbo Debugger (TD32) for Win32s and Windows NT.
  - Support for OS exception handling.
  - Support C/C++ exception handling.
  - Windows NT thread support.
  - Video DLL to run TDW in a window.
  - Remote debugging with TDW.
  - Session state saving.
  - Process attach for Windows NT.
  - Turbo Debugger Video Configuration Utility (TDWINI.EXE). 
  - Built in large model for greater capacity.

Resource Workshop:
------------------
  - Support for Win32s, Win32.
  - Resource preview
  - DialogExpert
  - Auto ID numbering
  - Auto mapping of accelerators and help hints to menu items
  - Support for VBX controls
  - SpeedMenus
  - Dialog editor property inspector
  - Integrated with ClassExpert and IDE project manager

ObjectWindows Library (OWL)
---------------------------
  - Complete coverage of Windows API, including GDI
  - Single source for Win 3.1, Win 32s, and NT
  - Built in exception handling using standard C++ exceptions for robust error
    handling
  - Built-in type safety using standard C++ templates
  - Toolbars, status lines, and print preview
  - Flexible Document/View architecture
  - Supports VBX 1.0 controls in a dialog or window
  - Layout Windows
  - Mix-in architecture
  - Support for 3d controls
  - Support for BWCC controls
  - Gadgets and Widgets
  - Multi threading support
  - Printing and print previewing support

VBX Support
-----------
Borland's visual tools, such as Resource Workshop, provide support of VBX 1.0
controls via a DLL called BIVBX10.DLL. You can freely distrubute this DLL
with programs you create that use VBX controls.

BIVBX10.DLL has been tested with a large number of VBX controls written to the
Microsoft Visual Basic 1.0 CDK specification. If you have a problem with a
specific control, make sure that it does not require VB 2.0 or VB 3.0 CDK
functionality. VBX 2.0 and 3.0 controls will usually display a message saying
that they require VB 2.0 or 3.0 support. In some cases, though, the control may
appear to work but exhibit instability. Please contact the control vendor and
explain the problem. They may have an updated control or may be able to contact
Borland to find a solution.

Documentation:
--------------
This distribution includes printed and online documentation
to help you understand and use the new features of Borland C++ 4.0, as well
as online Help.  

For C++ Language and Programming information:
	See the Library Reference, the
	Programmer's Guide, and the DOS Reference.
	See also the online Help.

For information on using MAKE, TLINK, and resource tools:
	See the User's Guide.
	See also the online Help.

For information on keyboard mapping and KEYMAPR (used to be called TEMC):
	See the online Help.

For information on using the IDE, AppExpert & ClassExpert, the Integrated
Debugger, and compiling options:
	See the User's Guide.
	See also the online Help.

For information on using the new Project Manager:
	See the online Help.

For information on converting your ObjectWindows 1.0 code to 
ObjectWindows 2.0:
	See the ObjectWindows Programmer's Guide.
	See also the online text file owldoc.wri.
	
For information on programming in ObjectWindows 2.0: 
	See the ObjectWindows Reference Guide, and the
 	ObjectWindows Programmer's Guide.
	See also the online text file, owldoc.wri.

For help using Turbo Debugger:
	See the online text files helpme!.tdw and hints.tdw.
       See also the online Help.

To use the online Help, make sure the Borland C++ 4.0 \BIN directory is
on your path.


------------------------
4. IMPORTANT INFORMATION
------------------------
GENERAL
-------
Note that if you have only 8 MB of RAM, you might experience some out-of-memory
problems building and using 32-bit applications. Please see the section below
titled, "Out of memory and MAKESWAP".


Object File Format
------------------
This product is designed to use and generate only object files which adhere
to the Intel OMF (Object Module Format) specification. This means that TLINK32
and TLIB only accept files of this format, and all provided libraries use 
this format. There is no support in the linker or librarian for COFF object
modules produced by Microsoft C tools.

MAKE 
----
MAKE will not put a space between two sets of file list macros as in BC++ 3.1
and before.  The example makefile below illustrates this; simply execute MAKE
in the directory containing the makefile. The output is:

   ALLOBJS1 = one onetwo two
   ALLOBJS2 = one one two two

makefile:

OBJS1 = \
   one \
   one

OBJS2 = \
   two \
   two

ALLOBJS1 = $(OBJS1)$(OBJS2)
ALLOBJS2 = $(OBJS1) $(OBJS2)

..:

   @@echo ALLOBJS1 = $(ALLOBJS1)
   @@echo ALLOBJS2 = $(ALLOBJS2)


Out of Memory and MAKESWAP
--------------------------
If you get "Out of Memory" errors from DOS when running the
command-line tools, create a swap file with the MAKESWAP utility.
(Note that this applies to DOS only, not to DOS boxes opened under
Windows.) MAKESWAP takes the size of the file to create in KBytes,
for example:

  MAKESWAP 12000

will create a 12MB swap file in the current directory called EDPMI.SWP
for use by Borland command line tools.  To enable the swap file, use
the DPMI32 environment variable by issuing the following command at
the DOS prompt:

  set DPMI32=SWAPFILE <location of swap file>\EDPMI.SWP

Note that you must clear this environment variable by issuing the
command

  set DPMI32=

before running Paradox or other 16-bit DPMI-hosted executables,
such as Borland C++ 3.1 command-line tools.

Threads
-------
When creating secondary threads, the _beginthread or _beginthreadNT and
_endthread() RTL functions must be used to ensure the proper RTL
initialization and cleanup. Using NT's CreateThread and ExitThread functions
will result in undefined behavior if an implicit or explicit call is made to
the RTL. Note that using exception handling and/or RTTI can lead to implicit
RTL calls.


DDVT functions and RTTI
-----------------------
When compiling code that contains DDVT functions, do not use run-time type
information. If you attempt this, you will receive an error message. In order
to compile without using run-time type information, compile all code that
uses DDVTs (for instance OWL 1.0x libraries and applications) with the
-RT- switch (Options|Project|C++ Options|Exception handling\RTTI in the IDE).

Inline assembly and interrupts
------------------------------
If your inline assembly code includes an interrupt call, the compiler does not
preserve any registers altered by the call. You must write code to save and
restore registers when using interrupt calls within inline assembly code.

Obsolete Win32 functions
------------------------
To discover when a function (such as DOS3Call) is obsolete under Win32, click
on the hypertext link for "Win32 version" in Online Help. This leads to a new
screen explaining that you can't use this function in Win32. When a
function works differently in the two versions, a link appears on the
first screen enabling the user to jump directly to help for the Win32
version of the function.

BC4 path name
------------------
Any occurrence of BORLANDC in the BC++ 4.0 path should be replaced with BC4.

Creating 16-bit import libraries from .DEF files
------------------------------------------------
Use the /o implib switch when creating 16-bit import libraries from .DEF files
to prevent implib from generating extensions for import entry module names.

Debugging DDE applications
--------------------------
DDE applications must be debugged in hard mode.


----------
New Tools
----------
The 16-bit linker has been modified in this version to allow for more than 64K
symbols in the executable's symbol table. The following tools have changed to
conform to the resulting new debug information format:

  TDW
  TDUMP
  Turbo Debugger (standalone)
  IDE Debugger
  IDE Browser

These tools have versioning information, so that if you attempt to use any of
them with executables created in prior versions, an error message will result.
You will then need to relink your executables.

If you don't see correct dump information when using TDUMP version 4.1 on your
executables, check the header at the top of the output. If it does not indicate
version 4.0 debug information, the associated .EXE file must be recompiled with
version 4.0 tools.

-------------------------------------
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

-------------------
Developing under NT
-------------------
To do development on NT, use the command-line tools, Resource
Workshop, and TD32. Using the IDE under NT is not currently
supported.

----------------------
C/C++ Language Changes
----------------------
Many changes were made to the compiler in compliance with the 
latest changes proposed by the ANSI C++ committee.  These include
three distinct char types, enhancements to templates, support for
virtual functions differing in return types, and other improvements
listed here.  See the Library Reference and the Programmer's Guide
for complete details on these changes and how they affect your 
code.

wchar_t is a fundamental data type in C++ programs. In C programs it continues
to be a typedef defined in stddef.h. See online Help.

Enum operator overloading is also supported in this compiler.

The runtime library now supports the ANSI C++ string class.
If you already have a string class, it must be renamed for Borland C++ 4.0.

In addition, operator new and operator new[] now throw an
exception (xalloc), as specified by the ANSI C++ committee.
To get the old behavior, you can issue set_new_handler(0). (Note,
however, that set_new_handler(0) does not work with ObjectWindows
or string classes.) See Chapter 3 of the Programmer's Guide.

Note that arrays are now being allocated through operator new[]()
and deleted by operator delete[](). An example is provided in 
Chapter 3 of the Programmer's Guide.

Borland C++ 4.0 implements ANSI C++ runtime type identification (RTTI). See
the Library Reference, "C++ runtime support",  for a description of
class Type_info. RTTI and operator typeid() are fully described in
Chapter 3 of the Programmer's Guide.

Borland C++ 4.0 provides a full implementation of exception handling
under C++ and C.  C exceptions can be handled in C or C++ code;
C++ exceptions can be handled only in C++ code. The C++ exceptions are
described in the Library Reference, "C++ run-time support." See Chapter 4
of the Programmer's Guide for a full description of how to use exception
handling.

Borland C++ 4.0 also implements the accepted ANSI C++ new style casts. See the
Chapter 3 of the Programmer's Guide for information and examples.

--------------------------
Libraries and Startup Code
--------------------------
The contents of the LIB directory are described in the online Help.
See the DOS Reference for a description of DOS-only libraries and
start-up code.

There are two new functions that provide access to 32-bit operating system
file handles. See online Help for a description of _open_osfhandle and
_get_osfhandle.

Member function Type_info::fname() is not available.

Several global variables and library functions have been renamed. See the
Library Reference, Chapter 1.


----------------------------------
Compiler and Linker Switch Changes
----------------------------------
See the User's Guide for information on new compiler and linker switches.

You may get this 32-bit Linker warning:
	Warning: External symbol <XX> was not qualified with __import in 
       module <YY>
If the symbol <XX> is a function, you can ignore this warning.  If
the symbol <XX> is data, then you must qualify the symbol with __import.

BCC32 provides support for the Pentium processor. This support is enabled
by the -5 compiler switch.

-----------------------------------------------------------------------
Converting Your Borland C++ Version 3.1 Windows Code to Borland C++ 4.0
-----------------------------------------------------------------------
To get your BC++ 3.1 code to compile and run successfully under Borland C++ 4.0,
you can modify your code to reflect three character types where compiler
errors occur when using the Borland C++ 4.0 RTL includes. Otherwise, you can
use the -K2 compiler option with the RTL includes from BC++ 3.1. This option
provides for only two character types. (Note that -K2, a backward 
compatibility switch, is supported only in the 16-bit compiler.) 
Also, use operator new[]() and delete[]() syntax for class arrays.

Note that certain 32-bit to 8-bit conversions allowed by ANSI are flagged 
by BCC32 with "Conversion may lose significant digits in function XXXXX".
You can safely ignore this message if you are doing certain types of 32-bit
to 8-bit casts (for instance, int to char) and you're not worried about
losing significant digits in those cases.


------------------------------
Changes to the Class Libraries
------------------------------
Only the version of the class library implemented with C++ templates 
is distributed and directly supported in Borland C++ 4.0.

The class library "object-based" include files are provided in the
\BC4\INCLUDE\CLASSLIB\OBSOLETE subdirectory.  The object-based
libraries themselves are not supplied, but can be built using the
instructions found in the \BC4\SOURCE\CLASSLIB makefile (see the
comments located there).

TSArray and TSArrayIterator classes have been added to the class libraries.
They are aliases for TSArrayAsVector and TSArrayAsVectorIterator.

The Flush and Delete member functions for direct containers (except
dictionaries) no longer take a delete parameter (this parameter had been
ignored since direct containers have their own copy of the contained element).
For example:

  TMArrayAsVector<double> arr(10);
  arr.Flush();	// legal
  arr.Flush(1);	// illegal - causes syntax error
  arr.Detach(index);	// legal
  arr.Detach(index,1);	// illegal - causes syntax error

  TMIArrayAsVector<double> arr1(10);
  arr1.Flush();	// legal
  arr1.Flush(1);	// legal.
  arr1.Detach(index); // legal
  arr1.Detach(index,1); // legal

Bag and set container member function FindMember is now called Find.
It takes the same parameters.

Association containers now have a member function called DeleteElements:

  void DeleteElements()

The dictionary containing the associations determines whether pointed-to
objects should be deleted, and, if so, calls DeleteElements for each of
the associations it holds. The Detach and Flush member functions for the
TMDictionaryAsHashTable template (and all templates derived from it)
have been changed to the following:

  int Detach( const T &t, DeleteType dt = DefDelete )

  void Flush( DeleteType dt = DefDelete )

These changes to the direct versions of the dictionary templates makes them
similar to an indirect container in how they handle object ownership. Here is
an example:

  TDIAssociation<int,int> assoc( 3, new int(4) ); //create an association
  TDictionaryAsHashTable<int,int> dict; //creates a dictionary
  dict.Add( assoc ); //copies assoc into the dictionary
  dict.OwnsElements(); //tell dict that it should delete pointed-to objects
  dict.Flush(); //deletes the int created by new in the first line.

All list and double-list containers now have the DetachAtHead member function.
This function removes items from the head of a list without searching for a
match. The syntax is

  int DetachAtHead() // for direct lists

  int DetachAtHead( int del = 0 ) //for indirect lists

Example:

  TMListImp<MyObject>list; //create list to hold MyObjects
  list.Add(MyObject()); //construct a MyObject, add to list
  list.Add(MyObject()); //add second MyObject
  list.DetachAtHead(); //remove MyObject at head of list

Changes to class diagnostics
----------------------------
Previously, in order to create a diagnostic group you had to declare it
and define it in the same file:

  DIAG_DECLARE_GROUP( Sample );
  DIAG_DEFINE_GROUP( Sample, 1, 0 );

We also provided a macro that did both of these together:

  DIAG_CREATE_GROUP( Sample, 1, 0 );

A change in the diagnostic software makes it illegal to have both
DECLARE and DEFINE in the same file. So code that creates a diagnostic
group now does it in one step:

  DIAG_DEFINE_GROUP( Sample, 1, 0 );

DIAG_CREATE_GROUP has been removed. DIAG_DECLARE_GROUP still creates an
extern declaration for a diagnostic group (see file CHECKS.H and CHECKS.CPP).

Code that uses both DIAG_DECLARE_GROUP and DIAG_DEFINE_GROUP in the same
file must be changed to remove DIAG_DECLARE_GROUP.

Old code:

  DIAG_DECLARE_GROUP( Sample );
  DIAG_DEFINE_GROUP( Sample, 1, 0 );

New code:

  DIAG_DEFINE_GROUP( Sample, 1, 0 );

Any use of DIAG_CREATE_GROUP must be changed to DIAG_DEFINE_GROUP.

Old code:
  DIAG_CREATE_GROUP( Sample, 1, 0);

New code:

  DIAG_DEFINE_GROUP( Sample, 1, 0 );

Also if a header file uses DIAG_DECLARE_GROUP (so that the group declaration is
automatically available to files that #include the header), the source file
that contains the DIAG_DEFINE_GROUP invocation for that group will generate
a redefinition error (this isn't done anywhere in OWL or class lib). The
solution here to conditionalize the header file so that the declaration goes
away when the source file with the DIAG_DEFINE_GROUP invocation is built:

	foo.h
	-------
	#if !defined( BUILD_FOO_GROUP )
	DIAG_DECLARE_GROUP( Foo );
	#endif

	foo.cpp
	-----------
	#define BUILD_FOO_GROUP
	#include "foo.h"


Changes to Object Streaming
---------------------------
The implementation of Object Streaming formerly used in ObjectWindows and
Turbo Vision has been moved into the class library. There have been several
changes made to the streaming mechanism, but they should be transparent to
existing class library code.  See the Programmer's Guide for details on 
streaming.

The header file OBJSTRM.H defines several macros that will make creating
streamable objects easier. See that header file for further documentation.

There are two types of streamable objects:
 - Resident objects which may be streamed out but which are not reconstructed
   when streamed back in
 - Dynamic objects which are reconstructed when streamed in.

Resident objects include static objects and objects present when an
application starts, such as its main window. These objects must be streamed
out via a reference rather than via a pointer.

Dynamic objects, on the other hand, must be streamed out via pointers,
causing them to be reconstructed when streamed back in.

Resident objects must be streamed out before any objects which stream out
pointers to the resident objects, else duplicate objects will be constructed
when streaming in.

When streaming objects in, Streamer::Read must insure that all data fields
are initialized, because the streaming constructor doesn't initialize any of
the data fields. Any data members not streamed in must be set to meaningful
values. Care must be taken to initialize the members before streaming in base
class data or pointers to objects which have pointers back to the current
object. Virtual functions are enabled in Streamer::Read.

Changes to the string class
---------------------------
The following sections correct string class member function definitions.

  size_t find_first_of( const string _FAR &s ) const
Locates the first occurrence in the target string of any character contained
in string s. If the search is successful find_first_of returns the character
location. If the search fails it returns NPOS.

  size_t find_first_of( const string _FAR &s, size_t pos ) const
Locates the first occurrence in the target string of any character contained
in string s after position pos. If the search is successful, it returns the
character position within the target string. If the search fails or if
pos > length(), it returns NPOS.

  size_t find_first_not_of( const string _FAR &s) const
Locates the first occurrence in the target string of any character not
contained in string s. If the search is successful, find_first_not_of returns
the character position within the target string. If the search fails it
returns NPOS.

  size_t find_first_not_of( const string _FAR &s, size_t pos ) const
Locates the first occurrence in the target string of any character not
contained in string s after position pos. If the search is successful
find_first_not_of returns the character position within the target string.
If the search fails or if pos > length(), find_first_not_of returns NPOS.

  size_t find_last_of( const string _FAR &s ) const
Locates the last occurrence in the target string of any character contained in
string s. If the search is successful find_last_of returns the character
position within the target string. If the search fails it returns 0.

  size_t find_last_of( const string _FAR &s, size_t pos ) const
Locates the last occurrence in the target string of any character contained in
string s after position pos. If the search is successful find_last_of returns
the character position within the target string. If the search fails or if
pos > length(), find_last_of returns NPOS.

  size_t find_last_not_of( const string _FAR &s ) const
Locates the last occurrence in the target string of any character not
contained in string s. If the search is successful find_last_not_of returns
the character position within the target string. If the search fails it
returns NPOS.

  size_t find_last_not_of( const string _FAR &s, size_t pos ) const
Locates the last occurrence in the target string of any character not
contained in string s after position pos. If the search is successful
find_last_not_of returns the character position within the target string. If
the search fails or if pos > length(), find_last_not_of returns NPOS.

The assign member funtion

	assign( const string&, size_t = NPOS );

was changed to

	assign( const string&, size_t = 0, size_t = NPOS );

The size_t parameter in the old version was the number of characters
to copy. In the new version that is the second size_t parameter; the
first one is the position in the passed string to start copying.
For example:

	string s1 = "abcdef";
	string s2;
	s2.assign( s1, 2, 3 );

After executing this code, s2 should contain "cde".

The same change was made in several other functions. The following lists the
new form:

	string( const string _FAR &, size_t, size_t );
	string( const char _FAR *, size_t, size_t );
	string( const char __far *, size_t, size_t );
	assign( const string _FAR &, size_t, size_t );
	append( const string _FAR &, size_t, size_t );
	append( const char _FAR *, size_t, size_t );
	prepend( const string _FAR&, size_t, size_t );
	prepend( const char _FAR*, size_t, size_t );
	compare( const string _FAR&, size_t, size_t );
	insert( size_t, const string _FAR&, size_t, size_t );
	replace( size_t, size_t, const string _FAR&, size_t, size_t );


--------------
Casting Macros
--------------
The following casting macros have been provided, and are defined in
\BC4\INCLUDE\CLASSLIB\DEFS.H:

  TYPESAFE_DOWNCAST(object,toClass)
Converts the pointer referred to by 'object' into a pointer to an object of
type 'toClass'. Note that the macro parameters to TYPESAFE_DOWNCAST are in the
opposite order from the rest of the macros here. When using a compiler that
supports new style casts and runtime type information this is done with
dynamic_cast<> and will return 0 if the cast cannot be done. When using a
compiler that does not support new-style casts and runtime type information
this is done with fake runtime type information generated by the
IMPLEMENT_CASTABLE macro.

  STATIC_CAST(targetType,object)
Converts the data object referred to by 'object' into the type referred to
by 'targetType'. When using a compiler that supports new style casts, this is
done with static_cast<> and will fail if the cast cannot be done without
runtime type information. When using a compiler that does not support new-style
casts, this is done with an old-style dangerous cast.

  CONST_CAST(targetType,object)
Converts the data object referred to by 'object' into the type referred to
by 'targetType'. When using a compiler that supports new style casts, this
is done with const_cast<> and will fail if the cast changes the type of the 
object in any way other than adding or removing const and volatile qualifiers.
When using a compiler that does not support new-style casts, this is done with
an old-style dangerous cast.

  REINTERPRET_CAST(targetType,object)
Converts the data object referred to by 'object' into the type referred to
by 'targetType'. When using a compiler that supports new style casts, this
is done with reinterpret_cast<>. When using a compiler that does not support
new-style casts, this is done with an old-style dangerous cast.

------------------------
IDE/Integrated Debugging
------------------------
Using the IDE under NT is not currently supported.

The default extension for Borland C++ 4.0 project files is IDE. 

Using the Microsoft DBWIN utility interferes with the Event log's
ability to display those same messages. If you wish to see those messages in
the Event log, either quit DBWIN or select Options|No Output in DBWIN.

Project style sheets are inherited from the default project when you select
Project|New. You can set inheritance using the following option in the BCW.INI
file:
   [projects]
   inherit=0
where 0 inherits from the default project, 1 from the previous project,
and 2 from the shipping defaults (which are unchangeable).

The following listing explains some of the more useful BCW.INI settings:

[ToolDir]                ; BCW's default paths
BcInclude=\bc4\include   ;Default Include path, MPD Directories
BcLib=\bc4\lib           ;Default Lib path, MPD Directories

[Project]
saveastext=1	;PDL file with Style Sheets and Modified tools
readastext=1	;Read Style Sheets and Tools

[IDE]
HelpDir=C:\BC4\BIN              ;where to find the help files
DefaultDesktopDir=C:\BC4\BIN\   ;where to find bcconfig.bcw,
                                ;bcwdef.bcw/dsw,*.tok,*.ckb


If you step over or into a throw() call, the application will run until it
reaches a breakpoint or program termination, instead of stopping at the
appropriate catch() function. If you wish to debug catch() functions, you
must set breakpoints within them.

Run to Cursor (F4) will do nothing if the source line you wish to run to is
the same source line that the execution point is on. Thus, using F4 to iterate
through any loop structure will not work. Instead, set a breakpoint on a line
in the loop and use Ctrl-F9 (Debug|Run) to iterate through the loop. Once
finished with the loop, the breakpoint can be removed.

The following combination of events will cause unusual behavior:

  - Placing breakpoints in Windows procedures or OWL event handler which will
    receive WM_KILLFOCUS or WM_WINDOWPOSCHANGED messages.
  - Shifting focus from this application while debugging, directly to the IDE.

When focus is changed from the application being debugged to the IDE, Windows
initiates an intertask SendMessage from the IDE to the application. But the
breakpoint prevents SendMessage from completing, putting Windows into an
unstable state. Many GUI debuggers silently ignore a breakpoint in this
situation. The Borland Integrated Debugger displays a message box warning of
this situation giving you the choice of ignoring the breakpoint and continuing
the application, or aborting the application so you can make further changes to
the code or placement of breakpoints before running again. The best way to
avoid this situation is to not click on the IDE when you have a breakpoint in
the Window procecure or OWL event handler that could stop due to an intertask
SendMessage from the IDE. Instead click on some other application like the
Program Manager. This will still result in the WM_KILLFOCUS and related
messages and the intertask SendMessage, but the initiating task will not be the
IDE and thus completely avoids the Windows instability.

One further note: the first click of the mouse on the IDE immediately initiates
the MessageBox and the click in the OK box is the next mouse event captured, so
interesting visual effects may occur depending on where that first mouse click
occurred. For example, if the first click was in the title bar of the IDE, the
second click (in the MessageBox OK) will result in a move of the IDE Window
from its original location to the location of the OK mouse click. If this
happens, move the IDE back to where you want it.


----------------------
Floating Point Formats
----------------------
Floating point formats are a collection of formatting information used to
manipulate floating point numbers in certain runtime library functions such as
scanf() and atof().

This section discusses why you might get the error 
FLOATING POINT FORMATS NOT LINKED : ABNORMAL PROGRAM TERMINATION and tells
you how to resolve it.

There are no current plans to fix this because it is not a bug. The intent
is to avoid linking the floating point formats (about 1K of overhead) when
they are not required.  The tradeoff of this feature is that the programmer
must explicitly request that the floating point formats be linked in for some
programs that manipulate floats in a limited and specific fashion.

Because you can get the error in a number of different ways, check the
following list of potential causes to find out how to resolve the error.
These are listed in order of most common to least common causes.

  1.  CAUSE:  Floating point set to <None>.  You have your
      floating point option set to None when it should be set to
      either Fast or Normal.

      FIX:  Set Floating Point to Fast or Normal.  

  2.  CAUSE:  Either the compiler is overoptimizing, or the
      floating point formats really do need to be linked in because
      your program manipulates floats in a limited and specific
      fashion.  Under certain obscure conditions, the compiler will
      ignore floating point usage in scanf().  (e.g., trying to
      read into a float variable that is part of an array contained
      in a structure.)

      FIX: Add the following to one source module:

              extern _floatconvert;
              #pragma extref _floatconvert

  3.  CAUSE:  Forgetting to put the address operator & on the scanf
      variable expression.  For example,
          float foo;
          scanf("%f", foo);

      FIX:  Change the code so that the & operator is used where it
      is needed.  For example, the above code should be
          float foo;
          scanf("%f", &foo);


--------------------------
Turbo Debugger for Windows
--------------------------
You can use TD32 to debug under Win32s. However, to do so, you must
ensure you use SVGA.DLL or equivalent support in the VideoDLL entry
in the [TurboDebugger] section of TDW.INI.

TD32 can support dual monitor debugging under Win32s. Ensure that
a monochrome adapter is installed in your machine and set the
Mono=yes flag in the [VideoOptions] section of TDW.INI:

	[VideoOptions]
	MONO=yes

See the online text file called td_help!.txt for more information on
using TD32 and TDW.

---------------------
Using Tools with NTFS
---------------------
When using Borland C++ 4.0 tools under NTFS, there are issues to be aware
of related to extension assumptions. If Borland C++ 4.0 tools see an
extension, they assume no default.  Therefore, with "bcc32 test.1.cpp",
BCC32 spawns TLINK32 with "-ap c0x32.obj test.1, test.1, import32 cw32".
As TLINK32 sees an extension on test.1, it makes NO assumptions about
a .obj or .exe extension.  It attempts to look for test.1 (instead of
test.1.obj) and to create test. (instead of test.1.exe).

Embedded blanks in filenames are not currently supported. For instance, under
the Windows NT NTFS file system it is legal to have a file named
"This is an interesting file name.cpp". The response file processing in our
32-bit tools cannot handle this type of file.

16-bit tools running on NT cannot use NTFS filenames.
