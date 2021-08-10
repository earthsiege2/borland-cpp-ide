/*****************************************************************/
                  Welcome to Borland C++ Release 5.0
                  ----------------------------------

This README file contains important information about BORLAND C++.
For the latest information about Borland C++ and its accompanying 
programs, read this entire file.

STOP!  For IMPORTANT product updates and technical information... 
 
Borland highly recommends that you investigate one of the following 
resources as soon as you have installed Borland C++ 5.0: 
 
World Wide Web:  http://loki.borland.com/cpp/patchs.htm 
CompuServe:      GO BCPP, section 3, "From Borland" 
FTP:             ftp.borland.com 
BBS:             (408)431-5096. 8-N-1 (I bits, No parity, 1 stop bit) 
Listserv:        listserv@borland.com  Send an email message 
                 containing this text: 
                                    
     SUBSCRIBE<space>BCPP<space>FIRSTNAME<space>LASTNAME 
 
This is crucial to our efforts to provide you with the most 
comprehensive product information, updates, and service possible with 
this new release of Borland C++. 

------------------------
Visual Database Tools users should also read DOC\VDBT.WRI.
CodeGuard users should also read CGREADME.TXT.
Turbo Debugger users should also read TD_RDME.TXT.

--------
CONTENTS
--------
1. How to Get Updates and Assistance
2. Installation
3. New Features
4. Important Information
   a) BOOL and bool Types in ObjectWindows 5.0
   b) Integrated Debugger
   c) Include Files with No Extension
   d) Out of Memory and MAKESWAP
   e) NOEHxx Libraries
   f) Floating-point Formats
   g) Declarations in Conditions
   h) Name Mangling
   i) Pragma to Support Anonymous Structs
   j) Compiler Error Messages
   k) Changes in the Semantics of C++
   l) BCC32i.EXE, 32-bit Optimizing Compiler
   m) Borland Database Engine (BDE)
   n) International Codepages
   o) Building 16-Bit Applications in Windows 95
   p) Running OLE Applications under Windows NT
   q) Editing in Integrated Resource Workshop
   r) Master Index for Help Files
   s) Building the STL Examples

5. Important Information for the Development Suite
   a) PVCS Version Manager

------------------------------------
1. How to Get Updates and Assistance
------------------------------------
If you have problems, read the HELPME.WRI and other files 
in your DOC subdirectory and check online Help. If you still 
need assistance, help is available from the following sources:

1. Borland offers a wide variety of Technical Support plans
   providing a range of assistance from installation and general
   usage of Borland C++ to language syntax, programming, and
   debugging help. For information about these support programs,
   call 1-800-523-7070.

2. For immediate assistance with everything from configuring Borland 
   C++ to C++ programming or debugging, call our C++ Programmer's 
   Advisor Lines ($2/minute, first minute free):

   * Windows / Win32: 1-900-555-1002 or 1-800-782-5558 (MC/VISA)
   * DOS: 1-900-555-1004 or 1-800-368-3366 (MC/VISA)

   For assistance outside North America, see #9 below or contact 
   your local Borland representative.

3. For the latest updates to Borland C++, see Borland Online at
   the URL http://www.borland.com.  Also

       Patch page:      http://loki.borland.com/cpp/patchs.htm
   Tech Info page:      http://www.borland.com/TechInfo/
         C++ page:      http://www.borland.com/TechInfo/cpp     
   Bug submission page: http://loki.borland.com/bugs

4. For online access to the Borland CompuServe forums, with their 
   libraries of technical information and answers to common 
   questions, type:

   GO BCPP      - for questions related to C/C++ programming
                  languages and Borland's programming tools
   GO BDEVTOOLS - for questions about the Borland Database Engine
   GO BCPPLIB   - for questions about ObjectWindows Library, STL,
                  and other Borland class libraries, and the 
                  Windows API.

   If you are not a member of CompuServe, see the enclosed
   special offer, and write for full details on how to receive
   a free IntroPak containing a $15 credit toward your first
   month's online charges.

5. Borland's TECHFAX service: Call 1-800-822-4269 for a FAX
   catalog of technical document entries. For assistance outside 
   North America, contact your local Borland representative.

6. Borland DLBBS: dial (408) 431-5096 (up to 9600 baud, 8-N-1)
   for a host of free technical documents and example programs.

7. Technical information on Borland C++ is available on the 
   Internet via anonymous ftp at our ftp site ftp.borland.com.

8. Subscribe to Borland's free electronic newsletter and get 
   regular updates on up-to-date technical tips, patch 
   notifications, bug fixes, and product releases. Send your full
   name and address via electronic mail to tech-info@borland.com.

9. For help outside North America:
   Australia       1 800 641 144
   Austria         +49 (0) 8995914705
   Belgium (NL)    +32 (0) 27298022
   Belgium (FR)    +32 (0) 27298035
   Czech Republic  +42 (2) 6272135
   Denmark         +45 (0) 45762313
   Finland         +358 (09) 04209792
   France          +33 (1) 41377019
   Germany         +49 (0) 8995914705
   Iceland         +47 (0) 22250017
   Ireland         +44 (0) 1256373479
   Italy           +39 (2) 57303203
   Netherlands     +31 (0) 30 833730
   Norway          +47 (0) 22250017
   Portugal        +34 (1) 6618091
   South Africa    +27 11  7894316
   Spain           +34 (1) 6618091
   Sweden          +46 (0) 86297520
   Switzerland     +49 (0) 8995914705
   UK              +44 (0) 1256373479

---------------
2. Installation
---------------
IMPORTANT!
Do not install Borland C++ 5.0 over previously installed Borland
C++ directories. The files in this distribution will not work with
previously shipped tools and libraries. This is particularly true
for configuration files from previous shipping releases, like 
TDCONFIG.TDW and BCCONFIG.BCW.

To install Borland C++ 5.0, run \SETUP\BC5\SETUP.EXE.
To install the Borland Development Suite, run \SETUP.EXE (in the
root of the CD).

If you need to use the Borland Power Pack for DOS, use it with
Borland C++ 4.5 (also provided with this release). It is not 
compatible with Borland C++ 5.0.

Also, be particularly careful when using object files and libraries
from earlier Borland C++ versions with binaries created with this
release. Several potential problems may occur when linking with old
objects or libraries. Exceptions won't work correctly (destructors 
won't get called) when a pre-BC4 stack frame is unwound due to an 
exception.

We recommend that you do not install Borland C++ to a path that
contains spaces or long file names.

For more information about installing Borland C++ 5.0, refer 
to INSTALL.TXT, which can be found in the following locations:

* Borland C++ CD-ROM (\BC5\INSTALL.TXT)
* Borland C++ floppy disk 1 (INSTALL.TXT)


---------------
3. New Features
---------------
This section briefly lists new features of Borland C++ 5.0. You 
can find details on the new features in online Help. Look for "What's 
New" in openhelp.hlp or look in the Help index.

The following features are new in Borland C++ 5.0:

* ObjectScripting for customizing the IDE (See BC5\SCRIPTS\EXAMPLES)
* Borland C++ Add-On Environment for Java
* Visual Database Tools (See VDBT.WRI)
* Microsoft Foundation Classes (MFC) Support 
  (See \SETUP\MFC32\README.TXT or \SETUP\MFC40\README.TXT)
* Standard C++ Library included
* New 32-bit Optimizing Compiler (BCC32i.EXE)
* New ObjectWindows classes (common controls, WinSocks, docking, shell)
* Asynchronous (Background) builds (Options|Environment|Process Control)
* New Compiler Options (-fp, -OI, -OM, -OS, -VC, -Vd, -Ve, -VF)
* Pentium Scheduler Optimization
* New TLINK and TLINK32 Command-line Options
* 32-bit hosted IDE
* IDE Add-on Interfaces (See BC5\DOC\ADDON.TXT)
* Turbo Debugger for Windows works under Windows NT
* New .DEF Statements
* OCX Container Support in OCF (See \EXAMPLES\OWL\TUTORIAL\STEP18)
* New Win32 SDK tools in SDKTOOLS directory
* New C++ keywords (__declspec, bool, mutable, explicit, typename)
* New macros for portability and compatibility
* Integrated Resource Workshop
* Integrated 32-bit debugger with CPU view support
* New MAKE Preprocessing Directive: !CMDSWITCHES
* Updated Help files
* New examples
* Borland C++ Development Suite available
  - CodeGuard 16/32
  - InstallShield Express
  - PVCS Version Manager
  - AppAccelerator for Borland C++ Add-On Environment for Java

------------------------
4. Important Information
------------------------
This section contains important information that may not be found in
the manuals, online Help, or online text files. Reading this material
is helpful for preventing potential errors.

   a) BOOL and bool Types in ObjectWindows 5.0
   -------------------------------------------
   ObjectWindows now uses the C++ bool type that Borland C++ supports.
   In version 2.5, bool was simulated via an enumeration. Because
   enums and integers have the same size by default, ObjectWindows
   made 'bool' and 'BOOL' interchangeable.

   With the new support for 'bool,' the two types are now
   unique and distinct. This change may require that you update your
   ObjectWindows code. For example, virtual methods returning 'bool'
   (such as TWindow's CanClose) must match the exact signature
   defined by the library.

   Another instance of this problem is with BC4.02-generated AppExpert 
   applications that support printing. In version 5.0, you may see 
   the error:

      Virtual function 'function' conflicts with base class 'class'

   You can fix this by changing BOOL to bool.

   b) Integrated Debugger
   ----------------------
   The integrated debugger in Borland C++ is for 32-bit programs
   only. Use Turbo Debugger for Windows (TDW) for 16-bit 
   debugging.  You can launch TDW from the IDE by choosing 
   Tools|Turbo Debugger.

   Due to Windows 95 limitations, hitting a breakpoint in a 
   WM_SIZE handler may result in unexpected mouse behavior.
   Also, while you can run more than one process in the debugger
   you can only have one process stopped at a time.  If a given 
   process is stopped (such as at a breakpoint) and a breakpoint
   (or other stop condition) is encountered in another process, 
   you can't debug the second process until you set the first 
   process running. Likewise, you can't step more than one process 
   at a time.

   QEMM Version 8 is not compatible with the integrated debugger.

   c) Include Files with No Extension
   ----------------------------------
   To support header names for the C++ Standard Library, 
   the following changes are made to names of #include files
   with no extension:

      * #include file names of 8 characters or less are automatically
        given a .h extension; for example, string is changed to
        string.h
  
      * #include file names greater than 8 characters are truncated
        to 8 characters and automatically given a .h extension;
        for example, algorithm is changed to algorith.h
   
   File names with extensions and file names with only a dot (.)
   extension are not affected. The result is that you can include the 
   standard headers such as <string> and <algorithm> and the compiler 
   correctly maps them to the appropriate .H files.

   d) Out of Memory and MAKESWAP
   -----------------------------
   If you get "Out of Memory" errors from DOS when running the
   command-line tools, or if you have only 8MB of RAM and have
   out-of-memory problems building and using 32-bit applications,
   create a swap file with the MAKESWAP utility. Note that this
   applies to DOS only, not to DOS boxes opened under Windows.
   MAKESWAP takes the size of the file to create in KBytes. For
   example:

      MAKESWAP 12000

   creates a 12MB swap file in the current directory called EDPMI.SWP
   for use by Borland command-line tools. To enable the swap file,
   use the DPMI32 environment variable by issuing the following
   command at the DOS prompt:

      set DPMI32=SWAPFILE <location of swap file>\EDPMI.SWP

   You must clear this environment variable by issuing the command

      set DPMI32=

   before running other 16-bit DPMI-hosted executables, such as
   Borland C++ 3.1 command-line tools.

   e) NOEHxx Libraries
   -------------------
   Purpose: The NOEHxx libraries eliminate the overhead of
   exception-handling code in the run-time library for users who
   don't need it and for those who rely on any libraries that do
   require it.

   How to use: You must link a NOEHxx library before linking any
   standard runtime library. For command-line tools, you can do this
   by specifying the required NOEHxx library on the BCC command-line
   or by making it the first library given to TLINK.

   For the IDE, choose the No Exception library option from 
   TargetExpert.

   What they do: The NOEHxx libraries resolve calls to
   exception-related compiler helper functions to dummy functions
   that return appropriate return values. They also restore the
   pre-exception behavior of operator new to return NULL on
   out-of-memory conditions. Non-exception-enabled versions of
   setjmp() and longjmp() are also provided.

   Limitations: Some features introduced in BC4.0 require exception
   handling. These include the string class, BIDS container classes,
   the standard OWL libraries, and RTTI.

   f) Floating-Point Formats
   -------------------------
   This section discusses why you might get the error: "Floating
   point formats not linked: abnormal program termination" and tells
   how to resolve it. Floating-point formats provide formatting
   information for floating-point numbers used in certain
   run-time library functions such as scanf() and atof().

   This section tells you how to avoid linking the floating-point
   formats (about 1K of overhead) when they are not required. The
   trade-off is that you must explicitly link the floating-point
   formats for some programs that manipulate floats in a specific
   fashion.

   The following list includes potential causes of the "floating-point
   formats not linked" error. (Most common listed first.)

   1. CAUSE: Floating-point set to <None>. Your floating-point option
      is set to None when it should be set to either Fast or Normal.

      FIX: Set Floating Point to Fast or Normal.

   2. CAUSE: Either the compiler is over-optimizing or the
      floating-point formats need to be linked because your
      program requires them. Under certain obscure conditions, 
      the compiler ignores floating-point usage in scanf() 
      (for example, trying to read into a float variable that
      is part of an array contained in a structure).

      FIX: Add the following code to one source module:

         extern _floatconvert;
         #pragma extref _floatconvert

   3. CAUSE: Forgetting to put the address operator & on the
      scanf variable expression. For example,

         float foo;
         scanf("%f", foo);

      FIX: Change the code to use the & operator as needed.
      For example:

         float foo;
         scanf("%f", &foo);

   g) Declarations in Conditions
   -----------------------------
   Declarations in conditions are now supported. This means that
   variables may be declared within the condition expression of 'if'
   and 'switch' statements. The scope of the variable is that of the
   statement. In the case of an 'if' statement, the variable is
   available in both the 'if' and the 'else' clauses. Refer to the
   description of the if keyword in online Help for more information.

   h) Name Mangling
   ----------------
   Name mangling has changed to include the calling convention and
   other code modifiers. The following modifiers now affect mangling:

       __saveregs
       __stdcall
       __fastcall
   
   This may have an impact in linking existing libraries, since the
   default calling convention is cdecl, and the Win32 API macro
   CALLBACK implies __stdcall calling convention. Therefore, functions
   that are declared as CALLBACK functions and compiled with older
   compilers will have different external naming than the same
   function compiled with this release. The linker will report these
   as unresolved externals.

   You need to recompile the old code with the new compiler, or
   use the -VC backward compatibility switch to inhibit the new
   mangling.

   i) Pragma to Support Anonymous Structs
   --------------------------------------
   A new pragma has been introduced to support anonymous structs
   in classes. This is to allow compilation of certain constructs
   used by MFC, although these constructs are not compatible with
   ANSI C++. You can use the pragma as follows:

      #pragma anon_struct on
      #pragma anon_struct off

   Between the two pragma directives above, anonymous structs
   embedded in classes are considered legal syntax by the compiler.

   j) Compiler Error Messages
   --------------------------
   Using typedef struct foo { ...}; without giving the typedef
   name used to be accepted by the version 4.x compiler, but now
   causes the error message: "Need an identifier to declare."

   Declaring a template class without a terminating semicolon used
   to be accepted by the version 4.x compiler, but now causes the
   error message:  "Declaration missing ;"

   k) Changes in the Semantics of C++
   ----------------------------------
   The compiler includes the latest changes in the ANSI C++
   Working Paper (Sept 95). Along with major new language features
   (like namespaces), there are some minor changes in the semantics
   of C++. Because they could cause potential pitfalls for existing
   code, we want to bring them to your attention.

       (1) Scope of declarations in a for-init statement

       Until this release, you could define a variable in a for-init
       statement and use this variable after the end of the
       for loop. For example,

           ...
           for (int i = 0; i < 10; i++)
                if (f(i))
                     break;
              -  if (i == 5) // Error: Undefined symbol 'i'
                             // unless -Vd is enabled
           ...

       By default, you cannot use the variable i outside the for
       loop. In the code example above, the compiler issues an
       error message when you attempt to access i, unless you 
       enable the new -Vd compiler switch.

       You can use the -Vd switch to compile applications using 
       the old for-init scoping rules. When -Vd is enabled, the 
       scope of a variable declared in the for statement extends 
       until processing encounters the end of the block containing 
       the for loop.

       (2) Checking template body syntax before instantiation

       Older versions of the compiler didn't check the syntax of
       a template body unless the template was instantiated. Now,
       a template body is parsed like every other declaration
       immediately when seen.

           template <class T>
           class X : T
           {
             Int j; // Error: Type name expected in template X<T>
           };

       Let's assume that Int hasn't been defined so far. This
       means that Int must be a member of the template argument T.
       But it also might be a typo that should be int instead of Int.
       Because the compiler can't guess the correct meaning, it will
       issue an error message.

       If you want to access types defined by a template argument,
       you can use a typedef to make your intention clear to the
       compiler:

           template <class T>
           class X : T
           {
             typedef T::Int Int;
             Int j;
           };

       NOTE: You cannot write just

           typedef T::Int;

       as in older versions of the compiler. Not giving the typedef
       name used to be acceptable, but now causes an error message.

       All other templates mentioned inside the template body are
       declared or defined at that point. Therefore, the following
       example is ill-formed and will not compile:

           template <class T>
           class X
           {
             void f(NotYetDefinedTemplate<T> x);
           };

       All template definitions must end with a semicolon. Older
       versions of the compiler did not complain if the semicolon
       was missing.

       (3) Linkage of locally declared names
 
       The default linkage of locally declared names is the
       linkage of the enclosing block. In other words, the default
       linkage depends on the current scope. In a C++ source file,
       the global default linkage is C++. If there is a definition
       of a name with C linkage, all locally declared names in that
       definition also get C linkage.

       If the linkage specifications for a name conflict within a
       single source file, the compiler will give an error message.
       If there is more than one source file involved (as in the
       example below), the linker displays messages about undefined
       external symbols.

           // SOURCE 1:    X.CPP
           extern "C" int cf(void)
           {
             int cppf(int);
             return cppf(42);
           }

           // SOURCE 2:    MAIN.CPP
           extern "C" int cf(void);
           int cppf(int i)
           {
             return i;
           }

           int main()
           {
             return cf() - 42;
           }

       To fix the example above, you have to make the local
       prototype for cppf() global. Then the rule for the local
       default linkage doesn't apply, and cppf() gets the global
       default linkage, which is C++.

       (4) Stricter rules for enum types

       The rules for statements involving enum types are now
       stricter. The compiler enforces these rules with error
       messages if the compiler switch -A is turned on (which means
       strict ANSI C++).

       Assigning an integer to a variable of enum type will give
       an error:

           enum color
           {
             red, green, blue
           };

           int f()
           {
             color c;
             c = 0;
             return c;
           }

       The same applies for passing an integer as a parameter to
       a function. Notice that the resulting type of the expression
       flag1|flag2 is int:

           enum e
           {
             flag1 = 0x01,
             flag2 = 0x02
           };

           void p(e);

           void f()
           {
             p(flag1|flag2);
           }

       To make the example compile, the expression flag1|flag2
       must be cast to the enum type: e(flag1|flag2).

   l) BCC32i.EXE, 32-bit Optimizing Compiler
   -----------------------------------------
   Borland C++ includes an additional 32-bit compiler, BCC32i.EXE.
   BCC32i is one of the alternatives on the Options|Project|32-bit
   Compiler page. This highly optimizing compiler is somewhat 
   slower than Borland's other 32-bit compiler (BCC32.EXE)
   but produces faster executable code. So you may find 
   it useful to use BCC32.EXE while developing an application,
   then optimize the code by doing a final compile using BCC32i.EXE.
   For best results, use the -O2 switch.

      * You can gain extra optimizations by using the -OI
        and -OM switches.

      * To debug code built with BCC32i.EXE, turn optimization
        off (using the -Od switch).

      * Debug information is not supported when the compiler
        compiles via assembly. To use the -B switch, turn
        off the -v switch. Also, if you have inline assembly code
        or use pseudoregisters, this implies compilation via
        assembly, and debug information must be disabled.

      * BCC32i inlines common math routines with the -O2 switch,
        including many routines from math.h. The inline versions do
        not handle floating-point exceptions, so fperr is not 
        called for exceptions in these routines. To disable the
        inlining of the math routines, use the -O-i switch.

   NOTE: You cannot use CodeGuard with the BCC32i compiler.

   m) 32-Bit Borland Database Engine (BDE)
   ---------------------------------------
   ODBC Driver
   -----------
   Version 2.0 of the MS-SQL ODBC driver from Microsoft does
   not support DECIMAL or NUMERIC field types (TTable.CreateTable
   fails). Version 2.11 MS-SQL driver from Intersolv does.

   32-bit/16-bit Connectivity
   --------------------------
   To support the Sybase and MS-SQL drivers, optional
   parameters were added to BDE's 32-bit configuration. 
   The installed CFG file will not contain the required 
   parameters. 

   To use the Sybase or MS-SQL drivers for 32-bit only:

   1. Run BDE Configuration Utility (32-bit)

   2. File | Merge parameters from SYB32.CFG or MSS32.CFG
      (for Sybase or MS-SQL)

   3. File | Save either option (Win31 or 32)

      a) Win 31 updates Registry's Configfile01
         directory, but will NOT save drivers in Registry

      b) Win 32 option updates Registry's Configfile01
         directory and saves Drivers in Registry

   4. After configuring, add aliases you want to use
      with the updated driver

      Note: The new configuration file is for 32-bit use only.

   Redistributing BDE Applications
   -------------------------------
   When using InstallShield Express to redistribute applications,
   be aware that it ALWAYS adds the extra parameters mentioned
   above.  This means that you must provide a separate CFG file 
   (without the extra parameters) for 16-bit applications.  To 
   keep the 16- and 32-bit CFG files separate, put the new 
   configuration file in a different location than the one in 
   the WIN.INI file under the IDAPI section.

   All BDE Applications
   --------------------
   Windows NT only: When running a BDE application from a directory
   that does not have "write" access: If there is no TEMP directory
   on the system, the error DBIERR_OSACCESS (OS Permission Denied) 
   occurs during a call to DbiInit.  To continue, create a TEMP 
   directory.

   All SQL Drivers
   ---------------
   Adding an Index to an SQL table may change the record buffer
   size.  If the cursor is live, close then reopen the table.

   Schema Cache for SQL Drivers
   ----------------------------
   The schema cache option (i.e., "Enable Schema Cache" set to true
   with BDECFG32) is for use with static databases. Changing the 
   database while this option is enabled can cause errors.

   Do not enable schema cache if you frequently:

      * add columns to a table
      * add/drop indexes from a table
      * change validity checks on fields (that is, "not null" added 
        or removed)

   One sign that a database is not static enough to use schema
   cache is if "Unknown SQL Errors" are returned whose error
   context refers to:

      * "Unknown Column"
      * "Invalid Bind Type"
      * "Invalid Type"
      * "Invalid Type Conversion"
      * "Column Not a Blob"

   If you receive these errors, try disabling schema cache.

   Oracle Driver
   -------------
   Live queries for Oracle tables require a table qualifier or
   an alias if the field names are quoted.  The following code
   produces an error:
     select * from someTable where "fieldname" = someValue

   Instead use either:

     select * from someTable T1 where T1."fieldname" = someValue
   or:
     select * from someTable where "someTable"."fieldname" = someValue

   n) International Codepages
   --------------------------
   Under Windows NT, the 16-bit compiler does not support filenames 
   that use extended characters from codepage 850.  Codepage 437 
   works fine.

   o) Building 16-Bit Applications in Windows 95
   ---------------------------------------------
   When you build 16-bit applications in the IDE, a process called
   CapDos32 remains in memory.  If you view PVIEW.EXE, it shows 
   these processes as WINOLDAP.  

   To make these processes unload themselves after 16-bit builds,  
   select \WINDOWS\SYSTEM\CONAGENT.EXE, select File | Properties, and 
   check Close on exit on the Program page. To avoid running out of 
   memory while linking 16-bit applications, set all memory choices 
   to Auto on the Memory page of the CONAGENT.EXE properties.

   p) Running OLE Applications under Windows NT
   --------------------------------------------
   You must set the system path to the BIN directory if running OLE
   applications using the dynamic version of the libraries.

   q) Editing in Integrated Resource Workshop
   ------------------------------------------
   Integrated Resource Workshop doesn't support editing 24-bit images 
   or images using greater than 256 colors.

   If your TMP environment variable is set to a nonexistent directory,
   the Dialog editor may behave unpredictably.

   After editing your AppExpert menus in Resource Workshop, close the
   resource project and run Rescan in order to see your new menu items
   in ClassExpert's list of command notifications.

   r) Master Index for Help Files
   ------------------------------
   The Win32 API Help file is very large, and creating a master index
   that includes it strains the capacity of some machines.  If Help's index
   page comes up blank, open the BC5\HELP\OPENHELP.CNT file and locate
   this line:

      :INDEX Microsoft Windows SDK Reference = WIN32.HLP

   Comment it out by inserting a semicolon (;) in front of it.

   s) Building the STL Examples
   ----------------------------
   Don't build the examples in \EXAMPLES\STDLIB using the
   BINDING=DLL make option.  The makefile does not link the
   examples correctly when that switch is set.

--------------------------------------------------
5. Important Information for the Development Suite
--------------------------------------------------

This section is for users who purchased the Borland C++
Development Suite.

   a) PVCS Version Manager
   -----------------------
   Use the Browse PVCS Project menu only with a project open.

   Do not use PVCS from the IDE while a background compile
   is in progress.

      (1) Managing an Existing PVCS Project

      If you have a project already under PVCS version control
      and you want to manage the existing project  through the
      IDE PVCS Add-On, follow these steps to set it up:

        1. Save a copy of your original archive file.
        2. Set up the project anew in PVCS through the IDE.
        3. Copy your old archive file over the new one PVCS 
           just created.

      (2) Which Project Files are Placed Under Version Control

      When you first place a project under version control, 
      PVCS enumerates the nodes in your .IDE project.  It adds 
      to version control only those files associated with nodes in
      the project.  As a result, it omits autodependency files.

      For example, if you have a node for MYSOURCE.CPP, and
      MYSOURCE.CPP includes MYSOURCE.H, only the CPP file is added to
      version control. To include the header file, you must add it to 
      the project explicitly. Right-click the source node, choose Add
      Node, and browse to the header file.  Now when PVCS enumerates
      nodes, it will add the header, too.  

      The PVCS Add-On does not support archiving files from nodes  
      that are not translated.  This includes binary resource files 
      (.BMP, .ICO...), text files, and source pools.

/****************************END OF FILE***************************/

