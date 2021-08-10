APPLICATION AND DIALOG EXPERTS EXAMPLE

The Dialogbox and Application Experts represent additional functionality
for the C++ Builder IDE and the source code for them (supplied in this
directory) offers the C++ Builder user the following additional sources
of information:

1) examples which serve to illustrate the development of experts
2) miscellaneous examples of CBuilder component operations

Compiling and Linking the Dialogbox and Application Experts
-----------------------------------------------------------

The Experts DLL may be compiled and linked using either the IDE or the
EXPERTS.BPR file. Use of the IDE should be fairly obvious so we will
leave this as a exercise for the user. To create EXPERTS.DLL with the
EXPERTS.BPR file, change to the experts subdirectory
(BCB\EXAMPLES\EXPERTS) and execute the following command:

            MAKE -fexperts.bpr

At times it may be desirable to force the rebuild of all the expert
sources (ala Project|Build All in the IDE). This is accomplished with
this command:

            MAKE -B -fexperts.bpr


Installation of the Experts
---------------------------

The Application and Dialog Experts are normally installed at C++Builder
setup time but may be installed and removed manually using the following
procedure:

Transfer (or delete) the experts DLL (EXPERTS.DLL) from the C++Builder
BIN directory (BCB\BIN). Execute the registry editor (REGEDIT)
and locate HKEY_CURRENT_USER\Software\Borland\C++Builder\4.0\Experts.

Under the "Experts" key, insert (or delete) the string value
(Edit|New|StringValue) "ExptDemo". If you are installing the expert DLL,
click on the string value "ExptDemo" in the right hand list box to select
it. Via the modify option (Edit|Modify), enter the path to the experts
DLL as the "Value Data:". Finally, exit REGEDIT, and restart C++Builder to
+test the installation/removal.

Source Organization
-------------------

The Experts DLL is composed of three main translation units:

1) The C++Builder project file for the DLL is represented by the file
   EXPERTS.CPP. Since EXPERTS.CPP requires no form it has no associated
   DFM file and since we chose to include the definition of the expert
   interface classes (TDialogExpert and TApplicationExpert) directly in
   the CPP module, there is no associated header file.

   The project file provides both the definition and implementation of
   the Application and Dialog Experts IDE interface classes. These
   classes provide the linkage required between the IDE and an expert
   used to supplement the IDE's services. Such classes are always derived
   from TIExpert.

   TIExpert is an abstract class defined in EXPTINF.H. Abstract classes
   provide at least one method which is not implemented within that class.
   In TIExpert's case, none of the methods defined are implemented.
   Consequently, C++ Builder classes derived from TIExpert MUST implement
   ALL methods defined by TIExpert. (Note that this differs from Object
   Pascal, which allows the creation of classes derived from abstract
   classes but does not require implementation of all methods.)

   In addition to the expert interface class implementations, EXPERT.CPP
   provides the DLL entry point (DLLEntryPoint) required to pass the IDE's
   tool services object into the experts DLL and to initialize the various
   local and global variables used by the experts.

   It is the Execute() method of the TDialogExpert and TApplicationExpert
   interface classes that actually invoke the Application and Dialog
   experts.

2) The C++ Builder Application Expert source consists of the files: APP.CPP,
   APP.H, APP.DFM, FILTERS.CPP, FILTERS.DFM, FILTERS.H, STRINGS.RC,
   EXPTBMPS.RC and CODEGEN.TXT.

   The Application Expert builds the target application source files using
   "Snipets" of code recorded as text in the file CODEGEN.TXT. This file,
   #included by the resource file STRINGS.RC, contains two types of text
   record: basic source code text which is selectively read and subsequently
   written out to the CPP (source) and H (header) files of a C++ translation
   unit and Object Pascal Object records, which are written out to a file
   (MAIN.TXT) used by the ObjectTextToResource() IDE service (in the
   GenerateMainFormFile() function in APP.CPP) to create the application's
   form file.

   The STRINGS resource file, besides providing the snipets strings resource,
   also provides strings used as hints, file names, buttons captions, etc.

   The EXPTBMPS resource file provides the bitmaps used by the Application
   Expert to maintain the thumbnail picture of user selctions for the
   style of application to be generated.

   The FILTERS files provide the sources required to generate the dialog
   box displayed when the user elects to enter a file filter type (i.e.,
   the file description and file type(s) associated with that description).

3) Unlike the Application Expert, the Dialog Expert builds the target
   dialog box "on-the-fly". All components and code for the target
   dialog are composed in memory. One notable reflection of this lies in
   the Proxies::CreateSubClass() call within the DoFormCreation() method
   of the TDlgExpert class (in DLG.CPP). Because this approach was chosen
   for the Dialog Expert, the files DLG.CPP and DLG.H represent the
   major part of the expert's code.

   Both the Dialog Expert and the Application Expert use bitmap resources
   from EXPTBMPS.RC.

   If you are interested in more information regarding the Proxie system
   and other fairly deep internal elements of the VCL, "Secrets of
   Delphi" (ISBN 1-57169-026-3, Ray Lischner, Waite Group) is an excellent
   resource.


File Descriptions
-----------------

The C++Builder expert sources have been supplemented with the source
of the Delphi Object Pascal sources from which they were translated.
These sources should, therefore, serve to provide plentiful examples
of conversion from Object Pascal to C++ and vica versa.

app.cpp      -  Application Expert class implementation
app.dfm      -  Application Expert form
app.h        -  Application Expert class defintion
codegen.txt  -  Code snipets for Application generator
dlg.cpp      -  Dialog Expert class implementation
dlg.dfm      -  Dilaog Expert form
dlg.h        -  Dialog Expert class definition
exconst.h    -  Global constants and defines
experts.cpp  -  Application & Dialog Experts interface definitions
                and implementation. This is the Experts DLL
                "Project" file.
experts.bpr  -  MAKE file for Application & Dialog Expert DLL
exptbmps.rc  -  Bitmap resources used by Dialog & Application Expert
filters.cpp  -  File type filter class implementation
filters.dfm  -  File type filter form
filters.h    -  File type filter class definition
strings.rc   -  String resources used by Application Expert

