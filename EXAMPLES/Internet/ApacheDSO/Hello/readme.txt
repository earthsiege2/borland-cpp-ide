Demo: HelloModule

Requirements
============
  Apache 1.3.X
  Write access to Apache conf file  .../conf/httpd.conf


Build Project (using the IDE)
=============
  Open HelloModule.bpr in CBuilder
  From the menu items select:
    Project | Options -->Directories Tab
  Set the OutPut Directory to the location you use for your Apache Modules. Make
  sure you have write access to the location you are using.
  Apache Modules are usually stored in the following location:
  
        <ApacheInstallDir>/modules


Build Project (From the commmand line)
=============
  Project Build HelloModule

Setup
=====
  Edit the Apache Conf file. Default locations include.......
   <ApacheInstallDir>/conf/httpd.conf

  Add the following lines to httpd.conf (After the AddModules Section)

        LoadModule hello_module Modules/HelloModule.dll

        <Location /HelloWorld>
                SetHandler hello-handler
        </Location>


Run the Demo
============
  Start Apache
  Open a WebBrowser
  goto http://localhost/HelloWorld/

