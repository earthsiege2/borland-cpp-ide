//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1992, 1994 by Borland International, All Rights Reserved
//
//   Definition of class TEditSearch, an edit control that responds to
//   Find, Replace and FindNext menu commands.
//----------------------------------------------------------------------------
#if !defined(OWL_EDITSEAR_H)
#define OWL_EDITSEAR_H

#if !defined(OWL_EDIT_H)
# include <owl/edit.h>
#endif
#if !defined(OWL_FINDREPL_H)
# include <owl/findrepl.h>
#endif
#include <owl/editsear.rh>


//
//  class TEditSearch
//  ----- -----------
//
class _OWLCLASS TEditSearch : public TEdit {
  public:
    TFindReplaceDialog::TData SearchData;
    TFindReplaceDialog*       SearchDialog;  // Find or replace dialog
    uint                      SearchCmd;     // command set that opened dialog

    TEditSearch(TWindow*        parent = 0,
                int             id = 0,
                const char far* text = 0,
                int x = 0, int y = 0, int w = 0, int h = 0,
                TModule*        module = 0);

   ~TEditSearch();

    void          SetupWindow();
    void          DoSearch();

    //
    // menu command handlers
    //
    void          CmEditFind();               // CM_EDITFIND
    void          CmEditReplace();            // CM_EDITREPLACE
    void          CeEditFindReplace(TCommandEnabler& ce);
    void          CmEditFindNext();           // CM_EDITFINDNEXT
    void          CeEditFindNext(TCommandEnabler& ce);

    LRESULT       EvFindMsg(WPARAM, LPARAM);  // Registered commdlg message

  private:
    //
    // hidden to prevent accidental copying or assignment
    //
    TEditSearch(const TEditSearch&);
    TEditSearch& operator=(const TEditSearch&);

  DECLARE_RESPONSE_TABLE(TEditSearch);
  DECLARE_STREAMABLE(_OWLCLASS, TEditSearch, 1);
};

#endif  // OWL_EDITSEAR_H
