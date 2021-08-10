Copyright Borland International
ObjectWindows (C) 1995

Title: GADGETS Example

Keywords: TGadget;TModeGadget;TTextGadget;TMenuGadget;TControlBar;
  TStatusBar;TTimeGadget;TControlGadget;TButtonGadget;TSeparatorGadget;
  Command target

The GADGETS example illustrates how to use all of the available gadgets
in OWL. A gadget is a user-interface element that acts like a window,
but due to resource issues, it is not.


[Sample Overview]

The GADGETS example creates a decorated SDI main window. The example
creates a control bar and inserts a button gadget, a separator gadget,
a menu gadget, two mode gadgets, a text gadget and a control gadget
wrapped around an edit control. The example creates a status bar with
several mode gadgets, separator gadgets and a time gadget. Various
styles of the gadgets are demonstrated.


The client window is the command target of the edit control gadget.
Whenever the edit control sends a notification, the control gadget
routes the notification to its command target, which is the client
window.





