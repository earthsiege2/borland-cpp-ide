ObjectWindows
Copyright (c) 1997 Borland International

Title: VCLDLG EXAMPLE

Keywords: VCL form OWL dialog

C++BUILDER AND BCBROOT ENVIRONMENT VARIABLE REQUIRED TO BUILD PROJECT
---------------------------------------------------------------------
In order to build this project, you must have Borland C++Builder
installed and you must manually define the environment variable
BCBROOT, making it point to the base of your installed C++Builder
tree.  For example:

    set BCBROOT=c:\cbuilder

WHAT IS OWLDLG?
---------------
This example demonstrates using OWL and VCL together in a single
application.  The Color menu command invokes a dialog box that
was designed with C++Builder.  The .DFM and VCLDLG.* files
were generated within C++Builder (and then tweaked by hand, but
that isn't always necessary.)

VCL-COMPATIBLE LIBRARIES
------------------------
This project links to several libraries that are not installed
as part of BC5.  VCLD.LIB and CP32MT.LIB come with Borland C++Builder.
OWLWV.LIB is on the BC5 CD in \BC5\LIB.  (VCL-compatible OWL
DLLs are also on the CD.)

SEEING THE LIBRARIES IN TARGET EXPERT
-------------------------------------
To link with the VCL-compatible OWL and RTL libraries, this project
overrides the usual TargetExpert settings.  If the runtime nodes
are not already visible, choose Options|Environment|Project View
and check the Show Run-time Nodes box.  You'll see in the Project
View that the runtime library is called CP32MT.LIB, not CW32MT.LIB.
CP32MT.LIB ships with C++Builder (as does VCL.LIB.)

If you open TargetExpert in this project, do not click OK to close
it or TargetExpert will reset the libraries and you'll have to restore
them by hand.

WHERE TO FIND MORE INFORMATION
------------------------------
For more details, see OWLVCL.DOC (a WordPad file) in the \BC5\DOC
directory.


