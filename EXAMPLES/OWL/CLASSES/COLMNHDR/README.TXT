Copyright Borland International
ObjectWindows (C) 1995

Title: COLMNHDR Example

Keywords: Common Control;Header Controls;TColumnHeader;THeaderItem


TColumnHeader, an Introduction
===============================
The ObjectsWindows classes TColumnHeader and THeaderItem can be
used to create, alias and manipulate Header Controls. Header
Controls are windows typically used to 'label' columns of data.
The control contains one or more items, each label a column.
Each Header Item can consists of a string, a bitmapped image and
an associated application-defined 32-bit value.


Creating a Header Control
=========================
To create a Header Control, simply create a 'TColumnHeader'
object within the constructor of the parent object specifying the
'parent' and the 'id' of the control.  For example,

   TMyWindow::TMyWindow() {
     // ...
     TColumnHeader* hdrCtl = new TColumnHeader(this, ID_XX);
   }

When constructed within the constructor of the parent object, it
is not necessary to invoke the 'Create' method of the
'TColumnHeader' object. The 'AutoCreate' feature of
ObjectWindows will ensure that the control is created once the
parent object is created. However, if you are constructing the
TColumnHeader object after its parent has been created, you will
also need to invoke it's 'Create' method.

NOTE: Although you can specify the screen coordinates of the
control, these parameters are typically left out in favour of
the 'Layout' capabilities of the 'TColumnHeader' object; more on
this later.


Adding items to a Header Control
================================ 
Once the control has been created (NOTE: It's important to
distinguish between the construction of the C++ object and the
creation of the actual underlying window, you can add items
using the 'Add' or 'Insert' methods of the TColumnHeader class.

The 'THeaderItem' class holds information about an item of a
Header Control. To add/insert an item you must first construct a
'THeaderItem' instance. After initializing the 'THeaderItem' instance,
you can invoke the 'Add' or 'Insert' method of the 'TColumnHeader' object.
For example:

  THeaderItem item("&Name of Employee");
  hdrCtl->Add(item);


Responding to Header Control Notification Messages
====================================================
The Header Control sends notification messages to its parent
window whenever user manipulates the Header Control. For
example, if the user clicks an item, the control sends a
HDN_ITEMCLICK notification message.

ObjectWindows provides several macros which can be used in the
definition of a Message Response Table allowing a member
function to be invoked when particular notification messages are
received by the parent. The following list the macros pertinent
to the Header Control:

  EV_HDN_BEGINTRACK(id, method)       // User starts dragging divider
  EV_HDN_DIVIDERDBLCLICK(id, method)  // User double clicked divider
  EV_HDN_ENDTRACK(id, method)         // User ends drag operation
  EV_HDN_ITEMCHANGED(id,method)       // Attribute of an item changed
  EV_HDN_ITEMCHANGING(id,method)      // Attribute about to change
  EV_HDN_ITEMCLICK(id, method)        // User clicked on item
  EV_HDN_TRACK(id, method)            // User dragged a divider


Sizing and Positioning a Header Control
========================================
A Header Control is typically docked to the upper side of its
parent's client area. The control provides an API which allows
the control to specify a desired size and position within the
boundary of a specified rectangle. The 'bool Layout(TRect&
boundingRect, WINDOWPOS& winPos)' method can be used to retrieve
the appropriate size and position values in a WINDOWPOS
structure.

The overloaded 'bool Layout(uint swpFlags = 0)' method provides
an higher abstraction of this API: the desired size of the
control is retrieved specifying the client area of its parent as
the bounding rectangle and the control is then repositioned
accordingly. The 'swpFlags' are used when call 'SetWindowPos' to
reposition the control.









