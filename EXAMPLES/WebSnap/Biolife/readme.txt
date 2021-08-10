WebSnap Demos
-------------
To run the BiolifeDebugger application, start the Web App Debugger, and browse to:
http://localhost:1024/BiolifeDebugger.Biolife

Feature Overview
================

User List
  The application keeps a list of users.  The list contains user name, password,
  and access rights.
Login/Logout
  The user is prevented from accessing pages if not logged in.  A login page is
  automatically displayed.
DB Image Support
  When an image is requested, a DB bitmap is converted to JPG and returned in the
  HTTP response.
File Upload
  Bitmap files can be uploaded using a <input type=file> element.
End User Access Control
  The HTML elements for a page depend on  the user's access rights.  For
  example, in <input type=edit> is generated for one user but static text is
  generated for another.
Sessions
  Sessions are used to keep track of the current end-user.
AdapterPageProducer element types
  <multiline> and <img> are generated in addition to <input>.

Trouble Shooting
================

This web application must remain in memory between requests.  Sessions will not work otherwise.  If you 
aren't able to leave the login screen then sessions aren't working.  The ISAPI version will work 
properly because ISAPI dll's stay in memory.  However, the Web App Debugger executable will not 
remain in memory unless it is started before browsing to the login page.

The BDE error "Image modified by another user" sometimes occurs when viewing
the grid and when editing a record.  This problem seems to occur more often after
uploading an image.

Setting up a BDE share dir seems to help with this problem.  Create a directory for BDE
(e.g.; c:\paradox_share) and use the BDE Adminstrator to indicate the directory name.  In the BDE Administrator, modify
Configuration/Drivers/Native/Paradox/Net Dir.

Using this Application
======================

The two login names are "Ellen" and "Will" (case sensitive).  No password required.  After logging
in as Ellen, the form view will allow editing.  After logging in as Will, the form
view will not allow editing.

You can replace the image while in the form view by entering the name of a local bitmap file
before clicking the Apply button.


