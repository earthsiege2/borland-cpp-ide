//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.8  $
//
// Definition of TRecentFiles class
//----------------------------------------------------------------------------
#if !defined(OWL_RECENTFILE_H)
#define OWL_RECENTFILE_H

#if !defined(OWL_EVENTHAN_H)
# include <owl/eventhan.h>
#endif

#if !defined(WINSYS_PROFILE_H)
# include <winsys/profile.h>
#endif

#if defined(BI_NAMESPACE)
namespace OWL {
#endif

//
// Derived classes should catch the following registered message to know
// when an item in the recent list has been selected.
//
#define MruFileMessage "MRUFILEMESSAGE"

// Generic definitions/compiler options (eg. alignment) preceeding the
// definition of classes
#include <services/preclass.h>

//
// class TRecentFiles
// ~~~~~ ~~~~~~~~~~~~
// This class implements a most-recent files list, designed to be mixed-in with
// TApplication.
// The list is appended to the menu with CM_EXIT options.
//
class _OWLCLASS TRecentFiles : virtual public TEventHandler
#if defined (BI_NO_RTTI)
  , virtual public TStreamableBase
#endif
{
  public:
    enum { MaxMenuItems = 10 };

    TRecentFiles(const char far* iniName, int numSavedFiles = MaxMenuItems);
   ~TRecentFiles();

    void          SaveMenuChoice(const char far* text);
    bool          GetMenuText(int id, char far* text, int maxTextLen);
    void          SetMaxMruItems(int max);

  protected:
    void          CeExit(TCommandEnabler& ce);
    void          CmFile(uint id);

    // Do the MRU items already exists in the menu?
    //
    bool          MruItemsInsertedIntoMenu(HMENU hMenu);
    void          RemoveMruItemsFromMenu(HMENU hMenu);
    void          InsertMruItemsToMenu(HMENU hMenu);
    int           GetMenuPos(HMENU hMenu, uint id);
    int           GetExitMenuPos(HMENU hMenu);

    // Profile methods
    //
    int           GetMruCount();
    void          RemoveMruIndex(int index);
    void          AddMruItem(const char far* text);
    bool          ExistMruItem(const char far* text);
    int           GetMruItemIndex(const char far* text);

  private:
    // Read information from the .INI file
    //
    void          Read();

    static uint   MruMessage;
    int           MaxFilesToSave;
    TProfile*     Profile;
    bool          AddedSeparator;
    HMENU         LastHMenu;

  DECLARE_RESPONSE_TABLE(TRecentFiles);
  DECLARE_CASTABLE;
};

// Generic definitions/compiler options (eg. alignment) following the
// definition of classes
#include <services/posclass.h>

#if defined(BI_NAMESPACE)
} // namespace OWL
#endif

#endif  // OWL_RECENTFILE_H
