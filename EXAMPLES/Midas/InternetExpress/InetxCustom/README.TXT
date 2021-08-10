InetXCustom Demo for C++Builder
===============================

This package consists of several additional InternetExpress 
components.  See the list of components below.  The TReconcilePageProducer
component is particularly usefull.

Component Installation:
======================
     - Project/Open, Change "Files of Type" to be "C++Builder Package (*.bpk)",
       then open ..\examples\Midas\InternetExpress\InetxCustom\InetXCustom_bcb.bpk
     - Click Compile button
     - Project/Open, Change "Files of Type" to be "C++Builder Package (*.bpk)",
       then open ..\examples\Midas\InternetExpress\InetxCustom\DclInetXCustom_bcb.bpk
     - Click on 'Compile' button, then click on 'Install' button.
       Clear the 'components installed' message.
     - go to InternetExpress Palette.  You'll find the ReconcilePageProducer
       available.  All of the other components are available within the
       TMidasPageProducer property editor.
       
Image components
================

The TImg* components use the <IMG> element to display a .gif file.  You will
need to copy the .gif files to your web server's virtual directory so that
they can be downloaded.  If you would like the .gif files to display properly at
design time, add the following registry string:

HKEY_CURRENT_USER\Software\Borland\
C++Builder\5.0\Property Editors\WebPage Editor\BlankPage = 'c:\inetpub\wwwroot\blank.htm'

Substitute c:\inetpub\wwwroot with the directory where the .gif files are located.
You will also need to create a file called blank.htm in this directory.  This
file should be empty.
  
The file specified by this registry key will be used to initialize the
WebBrowser control embedded within the TMidasPageProducer property editor. 

You may also specify a URL instead of a file path.  For example,
BlankPage = http://localhost/blank.htm.   A URL must be used if you set the
TImgDataNavigator.ImagePathURL to the name of a virtual directory.  For example,
TImgDataNavigator.ImagePathURL = '/images/'; 

Components list:
================
 
TImgApplyUpdatesButton  
  TImgApplyUpdatesButton behaves like TApplyUpdatesButton. An IMG element is 
  used rather than an INPUT element.
 
TImgDataNavigator  
  TImgDataNavigator is the parent of TImg*Button components.
 
TImgDeleteButton  
  TImgDeleteButton behaves like TDeleteButton. An IMG element is used rather 
  than an INPUT element.
 
TImgFirstButton  
  TImgFirstButton behaves like TFirstButton. An IMG element is used rather 
  than an INPUT element.
 
TImgInsertButton  
  TImgInsertButton behaves like TInsertButton. An IMG element is used 
  rather than an INPUT element.
 
TImgLastButton  
  TImgLastButton behaves like TLastButton. An IMG element is used 
  rather than an INPUT element. 
 
TImgNextButton  
  TImgNextButton behaves like TNextButton. An IMG element is used 
  rather than an INPUT element. 
 
TImgNextPageButton  
  TImgNextPageButton behaves like TNextPageButton. An IMG element 
  is used rather than an INPUT element.
 
TImgPostButton  
  TImgPostButton behaves like TPostButton. An IMG element is used 
  rather than an INPUT element.
 
TImgPriorButton  
  TImgPriorButton behaves like TPriorButton. An IMG element is 
  used rather than an INPUT element. 
 
TImgPriorPageButton  
  TImgPriorPageButton behaves like TPriorPageButton. An IMG element 
  is used rather than an INPUT element. 
 
TImgUndoButton  
  TImgUndoButton behaves like TUndoButton. An IMG element is used 
  rather than an INPUT element.
 
TReconcilePageProducer  
  This component generates a page that displays reconcile errors that occured while 
  applying updates. The user has the opportunity to correct the errors. This page 
  is associated with a TXMLBroker by setting the TXMLBroker.ReconcileProducer property.
 
TShowDeltaButton  
  When clicked, this component opens a window displaying the XML data packet. 
 
TShowXMLButton  
  When clicked, this component opens a window displaying the XML data packet. 

Include Path
=============

In order for CBuilder to find the include files (showxml.h, reconcileprod.h
and imgbuttons.h) the file path must be added to each project's include path
(Project/Options/Directories Conditionals).
For convenience, you can add the path to the library path (Tools/Environment
Options/Library).  CBuilder will automatically update the project include path
when the a header is found using the library path.  Use the following path:

$(BCB)\examples\midas\iternetexpress\inetxcustom

Web Application Example
=======================

The CustomerList_Custom project in the customerlist examples
directory demonstrates the use of these components.  See
customerlist\readme.txt and
customerlist\CustomerListWebModule_Custom.cpp for details.

