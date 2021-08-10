WebSnap Demos
DumpModules directory

This example contains JavaScript to traverse the modules, adapters, 
fields, and actions in a web application.

The pertinent JavaScript is in DumpModulesInc.html.

Notes
=====

Modify the style sheet in DumpModulesInc.html to change colors or fonts.

Only modules that have been instantiated will be dumped.  In this sample app, 
the CountryTable page is registered with the crAlways create flag.

The buttons on the CountryTable page do not work.  See the CountryEditor example 
for a working version of this table.

The dumpmodules page does not display properly at design time because it uses
script objects that are only populated at runtime.

To run the WebAppDebugger version of the project, first compile the
project ending in Debugger, and then start the Web App Debugger. Browse to
http://localhost:1024/DumpModulesDebugger.DumpModules
