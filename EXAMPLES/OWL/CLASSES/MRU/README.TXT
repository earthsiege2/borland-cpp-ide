Copyright Borland International
ObjectWindows (C) 1995

Title: MRU Example

Keywords: TRecentFiles;TProfile;Most recently used file list;
  TFileOpenDialog;TApplication mix-in


The MRU example illustrates how to use TRecentFiles which encapsulates
a most recently used file list.


TRecentFiles is designed to mix in with an TApplication. A mix-in class
is an OWL term to mean one of the base class that is not commonly used
for derivation. In the MRU example, TSampleApp is the derived class
that has two base classes, TApplication and TRecentFiles. TApplication
is the base class commonly derived from and TRecentFiles is the mix-in
class. A mix-in is different from simple derivation because it allows
you to decide whether you want to have a recently-used file list or not
in your application. Mix-ins are derived from TEventHandler so that
they can catch messages.


The class TRecentFiles works off of command enabling of the exit menu
choice (which must have the id of either CM_FILEEXIT or CM_EXIT). If
your application does not have a menu choice of those IDs, TRecentFiles
will not work.


To add a choice to the menu, call TRecentFiles::SaveMenuChoice(). To
know when the user clicked on one of the choices on the menu,
TRecentFiles will send a registered message (MruFileMessage) to the main
window. The WPARAM sent along with this message is the id you should
pass to TRecentFiles::GetMenuText(), which gets the text of the menu
choice. TSampleApp displays the selection in a message box.






