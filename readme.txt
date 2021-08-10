C++Builder 6
Release Notes


============================================================

This file contains important supplementary and late-breaking
information that may not appear in the main product
documentation. We recommend that you read this file in its
entirety.

For information on new features in this release, choose
"What's New" in the online Help contents.


============================================================
CONTENTS

* OTHER RELEASE NOTES INCLUDED WITH THIS PRODUCT
* ABOUT EDITING THE REGISTRY
* NOTES AND ISSUES: GENERAL
* NOTES AND ISSUES:
  WEB/DISTRIBUTED APPLICATION DEVELOPMENT
* NOTES AND ISSUES: DATABASE DEVELOPMENT
* NOTES AND ISSUES: ACTIVEX/COM
* NOTES AND ISSUES: INTERNATIONAL/LOCALES
* NOTES AND ISSUES: ONLINE HELP
* PRODUCT INFORMATION ON THE WEB


============================================================
OTHER RELEASE NOTES INCLUDED WITH THIS PRODUCT

* INSTALL contains system requirements and product
  installation information.

* DEPLOY contains information about redistributing your
  applications.

* LICENSE contains information on licensing allowances and
  limitations for this product and other Borland software
  that is bundled with it.

 The three files listed above, along with this file, are
 installed to your main product directory (default:
 C:\Program Files\Borland\CBuilder6).

 You can also find detailed information about new features
 and compatibility issues in BCB6NEW.HLP, which is part of
 the main online Help system (look for "What's New" in the
 Help contents or index).

* BDEREADME, BDEINST, and BDEDEPLOY contain release notes,
  installation, and deployment information about the
  Borland Database Engine (BDE) and Borland SQL Links
  products. These files are located in your main BDE
  directory (installation default: c:\Program Files\Common
  Files\Borland Shared\Bde).

 IMPORTANT: Any BDE-related information in this README
 overrides any corresponding information provided in the
 BDE release notes.

 Additional notes about existing issues with BDE and
 utility applications supplied with BDE are covered in the
 KNOWN ISSUES section later in this document.


============================================================
ABOUT EDITING THE WINDOWS REGISTRY

Warning:
 Registry edits are performed at your own risk.

Several items in this document and in other parts of the
documentation that accompany this product describe how to
edit your Windows registry. In most cases, we recommend that
you use the Microsoft Regedit tool to perform your editing.
Whatever tool you use, however, you should, before making
any edits, make backups of your registry and thoroughly
familiarize yourself with the editing tool and the registry
editing process. The registry is a critical component of
your operating system, and any mistakes made while editing
it can cause your machine to stop functioning.


============================================================
NOTES AND ISSUES:
GENERAL

Compatibility issues
------------------------------

* Some C++Builder 5 projects (including complex projects
  involving database connectivity) will not run as is. If
  you have trouble running a project from an earlier
  version, create a new C++Builder 6 project, remove the
  default unit, add the units from your old project, and
  recompile.

* Design-time packages that used ToolsAPI now also require
  the designide package. To add it, choose
  File|New|Other|Package; in the Package dialog, select the
  Requires node, then click Add; in the Add dialog, Browse
  to your CBuilder6\Lib directory, and choose
  designide.bpi.

* Comma-delimited string handling

 When assigning comma-delimited values to a TStringList
 using the CommaText property, a trailing comma in the
 source string will result in a blank item in the
 StringList. For example, if CommaText is set to:

 "String1, String2, String3,"

 The StringList will contain:

 String1
 String2
 String3
 <Blank>

 This is a change in behavior from previous releases.

* C++Builder 5 or earlier projects (command-line
  applications) that link to vcl.lib should change the
  reference to vcllink.lib. The vcl.lib included with
  C++Builder 6 does not contain the same functionality as
  the old vcl.lib.

Other compatibility issues between C++Builder 6 and earlier
versions of C++Builder, as well as between C++Builder 6 and
other products, are described in the install.txt/.rtf
document (located in your C++Builder6 root directory) What's
New section of your online Help system (search for
"Compatibility" in the Help Index).

Updating your CORBA applications

------------------------------
To update your existing CORBA applications to work with
C++Builder 6, you must change the Conditional Define option
in Project|Options to _USE_OLD_RW_STL.

Common controls library version note
------------------------------

Outdated versions of the Windows common controls library
(COMCTL32.DLL) can result in various graphical and
behavioral problems when using C++Builder and any programs
you develop with C++Builder. To help you avoid such
problems, C++Builder provides a separate (and
redistributable) common controls library updater. Running
the updater will refresh an outdated common controls
library, but will not replace later versions of the library
that may have been installed on your system by other
products released after C++Builder 6. Before running the
updater, be sure to read the readme.txt and license.txt
files that accompany it. And if you redistribute the updater
to your customers, be sure to include the readme and license
files in the deployment.

The common controls updater can be run directly from your CD
at:
\info\extras\comctl\50comupd.exe

Environment options/environment variable usage
------------------------------

You can now use operating-system environment variables to
specify directory paths in certain IDE dialogs. Use of
environment variables is available on the
Directories/Conditionals page of the Project Options dialog
and on the Library page of the Environment Options dialog.
The syntax is $(VariableName). For example, under Search
Path, you can now enter

$(TEMP);$(BCB)\source

The $(BCB) macro, used to specify directory paths, still
points by default to the directory immediately above
C++Builder's bin directory.

The Environment Options dialog now has an Environment
Variables page that you can use to set OS environment
variables.

ActiveX Wizard/licensing issue
------------------------------

[Enterprise, Professional editions only]
C++Builder does not directly support the licensing of
ActiveX controls for Web deployment. License package (.LPK)
files, which are required for runtime licensing of ActiveX
controls, can only be generated by LPK_TOOL.EXE, a utility
available in Microsoft's Internet SDK. For more information
on the license-creation tool and how it is used, visit
http://support.microsoft.com and search for "LPK".

Class Explorer and Windows 98
------------------------------

Since some users may experience issues when using Class
Explorer on Windows 98, Class Explorer is neither registered
nor enabled by default on that platform.

If you are using Windows 98 and you want to enable Class
Explorer, a file is provided on your C++Builder installation
CD that will allow you to register the feature. The file,
CE98.reg, is located on your CD in the folder \info\extras\.
To activate it, simply double-click the file name in Windows
Explorer or right-click the file name and choose Merge.

If you experience issues after installing the feature, you
can remove the enabling registry entry by running the
Windows registry editor (Regedit) and removing the value
that was merged by CE98.reg. To disable Class Explorer:

1. On the Start menu, click Run.
2. Type regedit, then click OK.
3. Follow this path:
   HKEY_CURRENT_USER\Software\Borland\
        C++Builder\6.0\Known IDE Packages
4. Right-click the value $(BCB)\Bin\bcbcxp60.bpl and choose
   Delete.

Before editing the Windows registry, please read the warning
above in the item "About Editing the Windows Registry." If
you are not familiar with the Regedit tool, consult your
operating system Help file.

Other general usage issues
------------------------------

* When checking variants, use the IsEmpty method instead of
  NULL.

* If, after installing TeamSource, you don't see TeamSource
  listed on your Tools menu, you'll need to manually
  configure the application to run with C++Builder. To do
  that, open C++Builder, choose Tools|Configure Tools to
  open the Tools Options dialog, then click Add to open the
  Tool Properties dialog, and Browse for your TeamSource
  application and working directory.

* You may encounter linker errors (including "[Linker Fatal
  Error] Fatal: Expected a file name:") if your project
  includes any paths that contain a "-" (hyphen) or "+"
  (plus sign). Best practice: Avoid those symbols in any
  paths used in your project.

* An Office XP controls demo is located on your installation
  CD at:
     \info\extras\officexpcontrols
  All other demos are installed to your \CBuilder6\Examples
  directory.


============================================================
NOTES AND ISSUES:
WEB AND DISTRIBUTED APPLICATION DEVELOPMENT

Using Apache modules in C++Builder 6
------------------------------

The following two steps are required when using Apache DSOs
in C++Builder 6 [note: this requirement does not apply to
Apache DSOs in Delphi 6].

1. Choose Project|Options, then the Packages tab. Uncheck
   the "Build with runtime packages" checkbox.

2. To load Apache modules, you must insert an underscore
   ("_") as the first character of any module symbols in
   the LoadModule entry of your http.conf file.

Example:

If, for example, you export a module named hello_module and
set the content type to hello-handler in your project source
file, as shown here:

//------------------------------------------------------
extern "C"
{
  Httpd::module __declspec(dllexport) hello_module;
}

int WINAPI DllEntryPoint(HINSTANCE hinst,
 unsigned long reason, void*)
{
  try
  {
    if (reason == DLL_PROCESS_ATTACH) {
     Apacheapp::set_module(&hello_module);
     strcpy(Apacheapp::ContentType, "hello-handler");
     Application->Initialize();
     Application->CreateForm(__classid(TWebModule1),
          &WebModule1);
     Application->Run();
    }
  }
  catch (Exception &exception)
  {
  }
  return 1;
}
//------------------------------------------------------

You would need to modify your http.conf file as follows:

#############################################
LoadModule _hello_module modules/Hello.dll
<Location /hello>
        SetHandler hello-handler
</Location>
##############################################

Using ClearModuleList in Apache httpd.conf
------------------------------

ClearModuleList, enabled by default in Apache 1.3.22 and
later (it was previously commented out), offers you two
options when developing modules in C++Builder. The command
appears between the LoadModule and AddModule lines in
httpd.conf:

 LoadModule foo_module modules/mod_foo.dll
 ...
 ClearModuleList
 ...
 AddModule mod_foo.c

To use the command, either:

* Add your "LoadModule" command after the ClearModuleList
  line in httpd.conf.
or
* In your C++Builder project file, change your module name
  using the strcopy function:

 strcpy(ModuleName, "MyModuleName");

 Then use the existing LoadModule/AddModule sections in
 httpd.conf, specifying your new module name:

 AddModule MyModuleName

Web Services notes
------------------------------

* A new Echo Service demo is available in your
  \Examples\WebServices directory.

* The Web Services Import Wizard and Add Web Service Wizard
  are not fully functional. Workaround: Use the command-
  line import tool (wsdlimp.exe).

* Enum support is available to servers. However, the
  typeinfo of an enum cannot be explicitly accessed for
  registration, which means clients are not able to send
  the proper namespace to a server expecting enum values.
  Workaround: Give the .CPP module of the client defining
  the enum the same name as the server.

* You must add

       #define DYNARRAY_RTTI

  to your code in order to use dynamic arrays with Web
  Services.

* The default server URL for the Web App Debugger
  (Tools|Web App Debugger, Start, select a listed Web App
  server, click Go to open http://localhost:1024/null)
  generates a "URL not found" error on versions of Netscape
  earlier than 6.2. The error does not occur in Internet
  Explorer.

* The THTTPRIO component used for client SOAP connections
  can be lifetime-managed as either a component or as an
  interfaced object. It is managed as a component when its
  owner is non-nil, such as when it is placed on a form or
  on a data module. In such cases, be sure to nil out any
  interface references that are not local variables before
  the owner is destroyed.

  Example:

  //------------------------------------------------------
  #include <vcl.h>
  #pragma hdrstop

  #include "Unit1.h"
  #include "IMyInterface.h"

  //------------------------------------------------------

  #pragma package(smart_init)
  #pragma resource "*.dfm"
  TForm1 *Form1;

  //------------------------------------------------------

  __fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
  {
  }

  //------------------------------------------------------
  __fastcall TForm1::FormCreate(TObject *Sender)
  {
  IMyINterfaceIntf service;
  HTTPRIO1->QueryInterface(service);
  }

//------------------------------------------------------
  __fastcall TForm1::Button1Click(TObject *Sender)
  {
    if (service) {
       service->Method(args);
    }
  }

//------------------------------------------------------
  __fastcall TForm1::FormDestroy(TObject *Sender)
  {
    service = 0;
  }

WebConnection issue on Windows XP
------------------------------

If using WebConnection on Windows XP, you may encounter the
error "Method not allowed (405)" when attempting to get the
servername dropdown list. Solution: Set up a virtual path.
Steps:

1. Open your Computer Management Console. You can open the
   console in a number of ways, including running
   "compmgmt.msc" from a command prompt, opening Control
   Panel's Administrative Tools, or by right-clicking on
   "My Computer" and choosing Manage.
2. In the Computer Management Console, expand Services and
   Applications,  Internet Information Services, and Web
   Sites. Right-click Default Web Site, then choose
   New|Virtual Directory.
3. Follow the steps in the Virtual Directory Creation
   Wizard.

DataSnap notes
------------------------------

* The TSoapConnection component now defaults to a different
  interface: IAppServerSOAP. Reasons for the change:

  a) IAppServer requires the safe calling convention and
  the latter is not available on C++, and

  b) Avoidance of the remote use of OLE Variants.

  If you want to use a C++ client with current Delphi and
  Kylix SOAP Data Module servers, be sure to set the
  'UseSOAPAdapter' property to false. This will cause the
  component to revert to IAppServer.

Using the Web App Debugger with C++Builder 5 projects
------------------------------

To run C++Builder 5 Web Server Applications using the
C++Builder 6 Web App Debugger, it is necessary to create a
new Web Server Application, selecting "Web App Debugger
executable" as the server type. Then remove the default
WebModule and add your existing WebModules to the new
application. For each WebModule you add, add the following
code to the unit's initialization section:

static void initFunc()
{
  WebRequestHandler()->WebModuleClass =
__classid(TWebModule2);
}
#pragma startup initFunc 31
//-------------------------

Note that "TWebModule2" should be replaced with the name of
the actual WebModule.

WebSnap notes
------------------------------

* Environment options:

 The Internet tab is used to set some WebSnap configuration
 options.

 An external HTML editor must be specified in order to
 enable the HTML editor command in the Internet toolbar.

* InterBase 6.5 implementation note

 If you are using a WebSnap application with InterBase 6.5,
 a local database connection is not recommended. Instead,
 use a client/server connection specified by a protocol-
 specific prefix to the path to the database.

 Examples:

 Local connection (not recommended):
 C:\PathTo\Database\DBName.gdb

 TCP/IP connection on Windows:
 saturn:C:\PathTo\Database\DBName.gdb

 TCP/IP connection on UNIX:
 jupiter:/usr/PathTo/Database/DBName.gdb

 NetBEUI connection:
 \\venus\C:\PathTo\Database\DBName.gdb

 IPX/SPX connection:
 mars@vol2:\PathTo\Database\DBName.gdb

 If the WebSnap application is on the same machine as the
 server, you can use localhost:
 localhost:C:\PathTo\Database\DBName.gdb

MSXML.DLL required for SOAP, WSDL, and XMLMapper
------------------------------

The MSXML.DLL library must be present and registered in
order to use the new SOAP, WSDL, and XMLMapper features
included with this product. If the library is not present on
your machine, you can obtain it as part of an XML Parser
package from the Microsoft Download Center at:

http://www.microsoft.com/downloads/search.asp?

Choose the "Keyword Search" option, then search for "MSXML".

To register the library from a command prompt, cd to the
location where the MSXML.DLL file is installed (e.g.
\winnt\system32), then type

REGSVR32 MSXML.DLL


============================================================
NOTES AND ISSUES:
DATABASE DEVELOPMENT

How to statically link dbExpress drivers
------------------------------

Static linking of dbExpress drivers (dbxdsnint.lib for
InterBase, dbxdsnora.lib for Oracle, dbxdsndb2.lib for DB2,
or dbxdsnmys.lib for MySQL 3.23.x) in C++Builder is a two-
step process: Link the driver, then register both the driver
and the DataSnap library. You can enter this code in your
TForm constructor.
The .lib files are located in your \cbuilder6\lib directory.

Important:
 Do not link more than one dbExpress driver into a project.
 Linking more than one driver will cause linking errors and
 may require a corrective shutdown of C++Builder.

The following example uses the InterBase driver.

Step 1.  Include the dbExpress/DataSnap header file:

#include <dbxdsnint.h>

Step 2. Register the static library:

RegisterDbXpressLib(::getSQLDriverINTERBASE);
RegisterMidasLib(::DllGetClassObject);

Note:
 DataSnap (a part of what was formerly known as MIDAS) is
 linked in to each dbExpress driver for C++Builder 6. Thus,
 if you need to statically link DataSnap only for access to
 midaslib, simply link in any of the drivers listed above.

Updating existing dbExpress configuration files
------------------------------

If the shared dbExpress configuration files
dbxconnections.ini and dbxdrivers.ini already exist (default
location \Program Files\Common Files\Borland
Shared\DBExpress), C++Builder will not overwrite them.
Instead, it will install updated configuration files named
dbxconnections.win and dbxdrivers.win into the same location
as the existing configuration files. To use the new
configuration information, first back up the existing .ini
files, then manually merge the new data (using any text
editor) from the .win files into the .ini files.

Important note for Informix users: If you have Delphi 6
installed, you will need to merge the Informix information
from the dbx*.win files into your dbx*.ini files, as
described above.

DB2 notes for dbExpress
------------------------------

* The provided DB2 driver is certified for DB2 version 7
  only. The client version and server version must match.
  BDE also supports DB2 version 7 only.

Oracle notes for dbExpress
------------------------------

* The Oracle driver provided for dbExpress components is
  certified for Oracle 8.1.7. BDE and ADO also support
  Oracle 8.1.6. In all cases, the client version and server
  version must be the same.

* When qualifying a table name with a user name, you must
  use quotes around the table name when CommandType is set
  to ctTable.

InterBase 6 Dialect 3
------------------------------

To use the new InterBase 6 or 6.5 Dialect 3 features, add an
entry to your Windows registry under
 HKEY_LOCAL_MACHINE\SOFTWARE\
     Borland\Database Engine\Settings
     \Drivers\Intrbase\Db Open\SQLDIALECT
and set the value to "3".

When an InterBase alias is created, the new entry will be
available in the .CFG file.

To use InterBase 5.6, SQLDIALECT can be set to "1" (existing
IB aliases which do not have the SQLDIALECT entry default to
SQLDIALECT=1 or to the registry setting when the SQLDIALECT
entry is added to the registry).

Informix BLOB/CLOB fields
------------------------------

A new global variable, InformixLob, is available to allow
you to work with Informix BLOB and CLOB fields.

The variable is required because Informix BLOB (fldBLOB,
fldstHBINARY) and CLOB (fldBLOB, fldstHMEMO) fields are
mapped as ftOraBlob and ftOraClob, respectively, and the
DataSnap resolver performs special query generation when
resolving Oracle BLOB/CLOB fields, but not when resolving
Informix BLOB/CLOBs. To address this issue, set InformixLob
to True when using Informix BLOB/CLOBs, and switch it back
to False (the default) when using Oracle BLOB/CLOBs.

Oracle LONG and LONG RAW fields
------------------------------

When using Oracle, the size of LONG and LONG RAW fields
cannot be determined without fetching the whole field. So if
BLOB SIZE is set to -1, LONG and LONG RAW fields are
truncated to 64K. Recommendation: Set BLOB SIZE to your best
estimate of the blob size.

Other database development notes
------------------------------

* C++Builder 6 supports InterBase 6.0 and 6.5. The client
  version and server version must be the same.

* C++Builder 6 installs sample database files that are
  compatible with the provided InterBase 6.5. Sample
  databases which are compatible with older versions of
  InterBase are on your CD in the Info\Extras directory.

* Enterprise edition only: Microsoft Data Access Components
  (MDAC) components are available for separate installation
  by running MDAC_TYP.EXE from the \MDAC directory on your
  product CD.

* A VCL hierarchy change involving TClientDataSet and
  TCustomClientDataSet causes incompatible parameter lists
  and affects the behavior of a number of types and events.
  For details, see What's New Help and search the index for
  the phrase "compatibility".

* The MySQL driver (dbexpmysql.dll) has been tested with
  MySQL version 3.23.45.

* The new Informix driver (dbexpinf.dll) has been tested
  with Informix version 9.2.1.

* The Borland Database Engine CAB file (BDEINST.CAB) is no
  longer digitally signed. This CAB file is provided for
  backward compatibility. For new applications, we
  recommend deploying the BDE with the BDE merge modules.


============================================================
NOTES AND ISSUES:
ACTIVEX/COM

Variant code failing to compile
------------------------------

Code which uses the TVariant class may fail to compile with
an error involving a missing template specialization
parameter specification. This is due to a problem with the
way template expansion is handled by the compiler. If you
encounter this error, open the Compiler page of the Project
Options dialog and ensure that 'disable inline expansions'
is NOT checked.

Delphi-style custom variants
------------------------------

Delphi-style custom variants are not supported in
C++Builder. Thus, you should not create descendants of
TCustomVariant.

TVariantInParam
------------------------------

Interface and Variant parameters are no longer passed as
smart pointers. As a result, TVariantInParam has been
deprecated and code which uses it should be updated.


============================================================
NOTES AND ISSUES:
INTERNATIONAL/LOCALES

Menu Shortcut Conflicts
------------------------------

Menu shortcuts in the IDE may conflict with system shortcuts
and international character key combinations. If you want to
disable the Ctrl+Alt hot keys in the IDE, set this DWORD
registry key:

 HKEY_CURRENT_USER\Software\Borland\CBuilder\6.0\
     Editor\Options\NoCtrlAltKeys

to "1".

Resource DLL Wizard and Windows 2000 locales
------------------------------

The Resource DLL wizard requires a distinct two- or three-
letter file extension for each translated version of a
project it maintains. For some languages that are written in
both Latin and Cyrillic characters, however, Windows 2000
uses the same default extension regardless of the character
set (as shown in the table below). If you want to maintain
both Latin and Cyrillic versions for such languages, change
the extension for one of the translations when you run the
Resource DLL wizard.

Language          Locale ID   Extension
                              
Azeri (Cyrillic)  82C         AZE
Azeri (Latin)     42C         AZE
                              
Uzbek (Cyrillic)  843         UZB
Uzbek (Latin)     443         UZB


============================================================
NOTES AND ISSUES:
ONLINE HELP

How to disengage CLX Help Reference linking
------------------------------
[Applies to Enterprise and Professional editions only]

The default Help installation for C++Builder 6 includes
documentation for two component libraries: the familiar
Visual Component Library (VCL) for Windows development, and
the new CLX library documentation for cross-platform
development. As a result, you'll often be presented with a
choice of two titles when seeking information on a specific
object or property--one title from the VCL reference, and
the other from the CLX reference. If, however, you are doing
Windows platform development only and you'd like to forego
the library choice when summoning Help, you can easily
disengage the CLX reference from the main Help system's
linking mechanisms. Here's how:

1. If C++Builder Help is running, close it (no need to
   close the C++Builder IDE, though).

2. Using any text editor, open the files BCB6.OHL,
   BCB6.OHI, and BCB6.OHC (all are located in your
   CBuilder6\Help directory).

3. In each file, comment out each line containing the
   string "BLX2CLX" by entering a semicolon as the first
   character on the line.

4. Save each file.

5. In your CBuilder6\Help folder, delete any hidden files
   with the extension "GID". Also delete any files with an
   extension beginning with "F".

Note:
 All of these files are automatically generated by Help,
 and will be restored the next time C++Builder Help is run.
 The GID is a General Index file, and the "F" files are
 generated when you run a full-text search from the Help
 Topics dialog. Deleting these files--always recommended
 when you alter the Help system configuration or install
 updated Help files--will assure proper indexing and
 database searching when you restart Help.

6. Restart Help, either by running BCB6.HLP directly from
   your CBuilder6\Help folder, or by starting it from the
   IDE using the Help menu or F1. The BLX2CLX.HLP topics
   should now be excluded from your searches and indexes.

If you also delete the BLX2CLX files from your
CBuilder6\Help folder and later decide to restore them (from
CD), remember to uncomment the BLX2CLX lines in your *.OH?
files to allow the files to be linked back into your larger
Help system.

You can also use the BCB6.OH* file set to disengage any
other part of the Help system (apart from the core BCB6.*
set), or add your own Help files to the system.

STL Help
------------------------------

C++Builder now uses STLport as the default STL
implementation, and the full set of SGI's online
documentation is provided with the product. However, the SGI
documentation is in HTML format, and context sensitive
search capability is not provided for this release of
C++Builder. Instead, context-sensitive searches on STL
classes will continue to use the Rogue Wave STL online help.
SGI's online documentation is available from C++Builder's
Help menu. You can also open the documentation directly, by
opening the file called bcb6_stlport.html in the main Help
directory. For more information about the STLport project,
you can also refer to www.stlport.com.

Windows Help index limitation on Windows 98/Me
------------------------------

The Windows Help engine on Windows 98 and Me uses a 16-bit
list box in the Help Topics dialog's Index tab, and can
display no more than 32,767 keywords. If this limitation is
exceeded, the Index is blank. If you are using one of these
operating systems, you may note that the Help Index control
file (bcb6.ohi) has been modified to exclude a number of
Help files from the Index. This modification does not affect
other Help system functionality--such as crossfile linking
or F1 accessibility--and you can expand the index or modify
it further to include or exclude any Help file reference by
adding or removing semi-colon comment marks before ":Index"
entries. When modifying the .OHI file, however, you must
keep the WinHelp viewer limitation in mind to avoid the
"blank index" problem.

Keeping your Help Index pointers current
------------------------------

Whenever your C++Builder Help system is modified or
reconfigured, be sure to delete any hidden *.GID files in
your CBuilder6/Help directory before restarting Help.

SHED and MRBC utilities not included
------------------------------

The Help file for the Help Compiler Workshop (HCW) product
states that two utilities--SHED.EXE and MRBC.EXE--are
included with HCW. We do not, however, ship these utilities
with our distribution of HCW. They are included in the full
HCW distribution, available free from the Microsoft Web
site.

Help may include references
to features not available in your edition
------------------------------

Your Help system may include references to features or
functionality that is not available in your edition of
C++Builder. For example, the Help system included with the
Personal Edition includes topics that describe cross-
platform development and WebSnap features. These sections of
the Help system may be ignored. If you'd like more
information about such features and the advantages of
upgrading to a version of C++Builder that includes them,
however, check the C++Builder home site at
http://www.borland.com/bcppbuilder/.

"Unable to display Find tab" message
------------------------------

If you receive an "Unable to display Find tab" message when
attempting to generate a full-text search in Help, close
Help, remove all *.fts files in your \WINNT\Help (or
\Windows\Help) directory, remove all *.gid (hidden index
files) and *.f?? files in your \CBuilder6\Help directory,
then restart Help and run full-text search again.
Background: WinHelp automatically generates *.gid and *.f??
files when you run Help or when you run a full-text search.
If Help components are updated or added, existing copies of
these files can cause indexing problems. Removing the auto-
generated files allows regeneration of indexes and
positional information when Help is rerun.

VCL hierarchy chart errata
------------------------------

On the VCL hierarchy chart, TWebContainedComponent looks
like it descends from TIBTimer. It actually descends from
TComponent.


============================================================
PRODUCT INFORMATION ON THE WEB

In addition to numerous private sites that offer
information, instruction, and samples, the following Borland
Web-based resources provide a continuous stream of news,
product information, updates, code, and other materials. You
can connect to many of these resources directly from the
Help menu.

C++Builder Direct [Help|C++Builder Direct]
------------------------------

This IDE add-in resource provides an automatically updated
list of links to the latest news, downloads, and other
information about C++Builder and Borland.

Code Central
------------------------------

The CodeCentral Repository is a free, searchable database of
code, tips, and other materials of interest to developers.
For details and registration information, visit
http://community.borland.com/codecentral/

The Borland Web site
------------------------------

Borland Software Corporation home page:
  http://www.borland.com/
  [IDE: Help|Borland Home Page]

C++Builder home page:
  http://www.borland.com/bcppbuilder/
  [IDE: Help|C++Builder Home Page]

C++Builder developer support:
  http://www.borland.com/devsupport/bcppbuilder/
  [IDE: Help|C++Builder Developer Support]

C++Builder updates and other downloads:
  http://www.borland.com/downloads/

C++Builder documentation site:
  http://www.borland.com/techpubs/bcppbuilder/

Newsgroups:
  http://www.borland.com/newsgroups/

Worldwide offices and distributors:
  http://www.borland.com/bww/

FTP site (anonymous access):
  ftp.borland.com


============================================================
Copyright (c) 2002 Borland Software Corporation.
All rights reserved.

