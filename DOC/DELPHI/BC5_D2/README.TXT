Samples and tutorial paper for "Using Borland Delphi and C++ Together"
  (C) 1996 Copyright Borland International Inc., All Rights Reserved.

Last updated: August 8, 1996 [ckh]


This distribution package includes classes and two examples for using Borland 
C++ and OWL with Delphi Forms.  The original presentation was made at the 
Borland Developer's Conference in July 1996.  The slides and example code 
have been updated since the BDC conference CD to use the new factory 
function that returns an IUnknown.
         
Roadmap
-------
The paper describing the techniques for using BC++ and Delphi together is an
HTML file named BC360.HTM as well as a WinWord document named BC5_D2.DOC.  The
presentation slides are in BC360.PPT, which is a Microsoft PowerPoint32 file.

View the WinWord documents by downloading the MS Word Viewer from
 http://www.microsoft.com/msword/Internet/Viewer/default.htm

There are four directories: two examples: SAMPLE and MDISAMP, one Delphi Form
DLL project TESTDLL, and a DATA directory.

Building the examples
---------------------
All of the examples are already built.  However, they also include an .IDE 
file if you wish to rebuild the examples yourself.
The C++ examples can be built with BC++ 5.01 and OWL 5.01; the Delphi form DLL
can be built with Delphi 2.01.

Files
-----
The files included on this distribution are listed below.


readme.txt                      - this file
723_O.HTM                       - a brief outline of the Borland Developer
                                  Conference presentation
BC360.HTM                       - the presentation paper
BC360.PPT                       - the PowerPoint slides

CODE\TESTDLL.H                  - header file for the DLL, in C++

CODE\DATA\SITES.DB              - A Paradox database containing some data that 
CODE\DATA\SITES.DOF               TESTDLL will display
CODE\DATA\SITES.DPR
CODE\DATA\SITES.FAM
CODE\DATA\SITES.MB
CODE\DATA\SITES.PX
CODE\DATA\SITES.RES
CODE\DATA\SITES.TV

CODE\SAMPLE\DLCTL.IDE           - SDI sample project
CODE\SAMPLE\DLCTL.CPP           - SDI sample source code
CODE\SAMPLE\DLCTL.EXE           - SDI sample application
CODE\SAMPLE\TESTDLL.DLL         - Form runtime DLL
CODE\SAMPLE\DLCTL.INI           - Together C++ display file
CODE\SAMPLE\DLWRAP.H            - Wrapper header files for C++
CODE\SAMPLE\TESTDLL.H           - Form DLL header file
CODE\SAMPLE\TESTDLL.LIB         - Import library for the Form DLL

CODE\MDISAMP\MDIFILE.IDE        - MDI sample project
CODE\MDISAMP\MDIFILE.CPP        - MDI sample source code
CODE\MDISAMP\MDIFILE.EXE
CODE\MDISAMP\MDIFILE.H
CODE\MDISAMP\MDIFILE.INI
CODE\MDISAMP\MDIFILE.RC
CODE\MDISAMP\MDIFILE.RES
CODE\MDISAMP\DLWRAP.H           - Wrapper header files for C++
CODE\MDISAMP\TESTDLL.H          - Form DLL header file
CODE\MDISAMP\TESTDLL.LIB        - Import library for the Form DLL

CODE\TESTDLL\TESTDLL.DPR        - Form DLL Delphi project
CODE\TESTDLL\EMBFORM.PAS        - TEmbeddedForm source code
CODE\TESTDLL\TESTDLL.DLL        - Form runtime DLL
CODE\TESTDLL\TESTDLL.dof
CODE\TESTDLL\TESTDLL.LIB        - Import library for the Form DLL
CODE\TESTDLL\TESTDLL.RES        - Sample Form resource file
CODE\TESTDLL\unit2.dfm          - Sample Form file
CODE\TESTDLL\unit2.pas          - Sample Form source code
