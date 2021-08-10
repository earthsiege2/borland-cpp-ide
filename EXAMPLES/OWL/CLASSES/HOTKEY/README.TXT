Copyright Borland International
ObjectWindows (C) 1995

Title: HOTKEY Example

Keywords: THotKey;Common Control

THotKey, an Introduction
========================
The ObjectWindows THotKey class encapsulates the hot-key control
from the Common Control Library. The control allows the user to
enter a combination keystrokes to be used as a hot key. (A hot
key is a key combination that the user can press to perform an
action quickly. The key combination can consist of a modifier
key, such as CTRL, ALT or SHIFT, and an accomapanying key, such
as a character key, an arrow key or a function key).


Creating a THotKey Object
=========================
THotKey offers two constructors: one for creating a hot-key
control from scratch and one for aliasing a hot-key control
which was defined in a dialog resource. 

The following code snippet illustrates how to create a brand new
hot-key control within a window represented by the class
TMyWindow.

   TMyWindow::TMyWindow(TWindow* parent) : TWindow(parent)
   {
      HotKey = new THotKey(this, ID_HOTKEY, 10, 10, 40, 40);
   }

NOTE: Since the control is newed within the constructor of it's
parent object, you need not explictly invoke its 'Create'
method. ObjectWindows' autocreate feature will ensure that the
control is created after the creation of the parent window.

To alias a hot-key control from a dialog resource, you must use
the other constructor of the THotKey class. The following code
fragment illustrates:

   TMyDialog::TMyDialog(TWindow* parent, TResId resId)
             :TDialog(parent, resId)
   {
      HotKey = new THotKey(this, IDC_HOTKEY);
   }
             

Setting and Retrieving the Key Combination
==========================================
The 'SetHotKey' and 'GetHotKey' methods of THotKey allow you to
set and retrieve the virtual key code and modifier flags of a
hot-key from a hot-key control.


Using a hot-key
===============
The value returned from the 'GetHotKey' method can be used with
the WM_SETHOTKEY message to associate a window with a hot-key.
When user presses the hot-key, the system activates the window.


Additional Information
======================
1. The value retrieved from the hot-key control is not usable
with the 'RegisterHotKey' API.
2. You can customize a hot-key control by specifying invalid key
combinations and providing the default modifier. See the 'SetRules'
method for more information.

