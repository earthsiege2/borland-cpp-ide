Copyright Borland International
ObjectWindows (C) 1995, 1996

Title: BLAZER Example

Keywords: TSplashWindow;TMci;TMciWaveAudio;Directory listing;THarbor;
          Dockable toolbars;TControlBar;TModeGadget;TTextGadget;TStatusBar;
          TButtonGadget;TControlGadget;Common Controls;TPaneSplitter;
          TListWindow;TTreeWindow;Context-sensitive Help;MAPI;TRecentFiles;
          Context menu;TPropertySheet;TSlider


The BLAZER sample application illustrates many of the common control
encapsulations. It is designed to be run only in 32-bit flat model.


When run, the application displays a TSplashWindow. If you have a sound
system, you can also hear an engine roar in the background. That's the
TMciWaveAudio encapsulation working. In the meantime, a directory listing
is being retrieved from the C: drive.


Once the application comes up, you'll notice the application has a menu.
If you press the F1 key any time a menu choice is highlighted, the help
page for that particular option is displayed. If any of the controls have
focus and the F1 key is pressed, the help page for that control is
displayed. This is the THelpFileManager class in action. Take a look at
the header file to see how DECLARE_HELPCONTEXT() is used. Also, take a look
at client.cpp to see how DEFINE_HELPCONTEXT is used. Notice in particular
the macros HCENTRY_MENU and HCENTRY_CONTROL. With the help manager, it is
required to use SETUP_HELPCONTEXT() and CLEANUP_HELPCONTEXT() to make sure
the correct context table is used.


The menu has two top-level choices: File and Help. The File menu has three
choices: Select to MRU, Send, and Exit. The Select to MRU option selects a
file to the Most Recently Used (MRU) list (TRecentFiles). The Send menu
option is only active when a file is selected from the TListWindow (more
on TListWindow later). The Send demonstrates the MAPI encapsulation.


The Help top-level menu has only one choice: About. The About box here is
not a dialog, but rather a layout window. The window contains a bouncing
ball (TDiBitmap), and three buttons. If you click the right mouse button
on the bouncing ball area, the context menu is displayed. The context menu
displays the same menu choices as the three buttons: Ok, Help, and
Options. The Ok button closes the about box. The Help button displays the
help page for the about box. The Options displays a property sheet
(TPropertySheet) for the various options of the bouncing ball.


So much for the menu options. The main window is divided by a
TPaneSplitter. On the left pane is the TTreeWindow and the right is a
TListWindow. The TTreeWindow displays the directory hierarchy for the
current drive. When a directory is selected with the mouse, the
TListWindow is filled with the files in that directory. For more uses of
the TListWindow, see the CLASSES/LISTWIND example.


Above and below the two panes are dockable gadget windows. These dockable
windows come up docked in the harbors. You can drag them out of the
harbors to make them float. When the windows are floating, you can resize
them to fit any rectangular area and the gadgets know how to resize
themselves.




