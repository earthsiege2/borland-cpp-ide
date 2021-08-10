//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1992, 1993 by Borland International
//   include\owl\editsear.h
//   Definition of class TEditSearch, an edit control that responds to
//   Find, Replace and FindNext menu commands.
//----------------------------------------------------------------------------
#if !defined(__OWL_EDITSEAR_H)
#define __OWL_EDITSEAR_H

#if !defined(__OWL_EDIT_H)
  #include <owl\edit.h>
#endif
#if !defined(__OWL_FINDREPL_H)
  #include <owl\findrepl.h>
#endif
#include <owl\editsear.rh>


//
//  class TEditSearch
//  ----- -----------
//
class _OWLCLASS TEditSearch : public TEdit {
  public:
    TFindReplaceDialog::TData SearchData;
    TFindReplaceDialog*       SearchDialog;  // Find or replace dialog
    UINT                      SearchCmd;     // command set that opened dialog

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
    void          CmEditFindNext();           // CM_EDITFINDNEXT

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

#endif  // __OWL_EDITSEAR_H
