JavaScript Include Files Troubleshooter

When a JavaScript error occurs while using an InternetExpress 
application, the error is often the result of unavailable JavaScript
include files. Use scripttest.html to verify that the JavaScript 
files are available. 

1. If necessary, modify scripttest.html to correspond to the
configuration of your Web Server virtual directories.

scripttest.html looks for JavaScript files in the current 
directory. To modify scripttest.html to reference a different 
virtual directory (e.g., SCRIPTS), modify the SRC attribute 
in the <SCRIPT> tag (e.g., SRC="/SCRIPTS/xmldom.js").

2. Copy scripttest.html to the virtual directory where your 
InternetExpress .exe or .dll is located.  This virtual directory must
have read access permission.

3. View scripttest.html using your browser.
You must access scripttest.html through your Web Server. Accessing 
as a local file (e.g.; c:\inetpub\wwwroot\scripttest.html) may 
provide incorrect results.


Note that Navigator often does a better job of reporting errors 
than IE. If you have Navigator, use it to access your InternetExpress 
page.  You may get an error message that explains the problem. 




