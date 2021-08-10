//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.5  $
//
// Definition of class TEditSearch, an edit control that responds to Find,
// Replace and FindNext menu commands.
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

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

//
// class TEditSearch
// ~~~~~ ~~~~~~~~~~~
class _OWLCLASS TEditSearch : public TEdit {
  public:
    TEditSearch(TWindow*        parent = 0,
                int             id = 0,
                const char far* text = 0,
                int x = 0, int y = 0, int w = 0, int h = 0,
                TModule*        module = 0);

    // NOTE: The following constructor, which aliases an Edit control created
    //       from a dialog resource is 'unconventional' in that it expects
    //       a TModule reference instead of the traditional 'TModule* = 0'.
    //       This is, however, to avoid ambiguities between the two forms
    //       of constructor. Since it is traditionally created as a child
    //       of a TDialog-derived class, you can simply use the module of the
    //       parent object. 
    //       For example,
    //             TMyDialog::TMyDialog(....) {
    //                edit = new TEditSearch(this, ID_EDIT1, *GetModule());
    //             }
    //
    TEditSearch(TWindow*   parent,
                int        resourceId,
                TModule&   module);

   ~TEditSearch();

    void          SetupWindow();
    void          DoSearch();

    TFindReplaceDialog::TData& GetSearchData();
    void          SetSearchData(const TFindReplaceDialog::TData& searchdata);

    TFindReplaceDialog* GetSearchDialog();
    void          SetSearchDialog(TFindReplaceDialog* searchdialog);

    uint          GetSearchCmd();
    void          SetSearchCmd(uint searchcmd);

  protected: 

    // Menu command handlers
    //
    void          CmEditFind();               // CM_EDITFIND
    void          CmEditReplace();            // CM_EDITREPLACE
    void          CeEditFindReplace(TCommandEnabler& ce);
    void          CmEditFindNext();           // CM_EDITFINDNEXT
    void          CeEditFindNext(TCommandEnabler& ce);

    TResult       EvFindMsg(TParam1, TParam2);  // Registered commdlg message

  public_data:
    TFindReplaceDialog::TData SearchData;
    TFindReplaceDialog*       SearchDialog;  // Find or replace dialog
    uint                      SearchCmd;     // command set that opened dialog

  private:
    // Hidden to prevent accidental copying or assignment
    //
    TEditSearch(const TEditSearch&);
    TEditSearch& operator=(const TEditSearch&);

  DECLARE_RESPONSE_TABLE(TEditSearch);
  DECLARE_STREAMABLE(_OWLCLASS, TEditSearch, 1);
};

// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>

//----------------------------------------------------------------------------
// Inline implementations
//
inline
TEditSearch::TEditSearch(TWindow* parent, int resourceId, TModule& module)
            :TEdit(parent, resourceId, 0, &module)
{
}

//
// Return the search data used for the common dialog.
//
inline TFindReplaceDialog::TData& TEditSearch::GetSearchData() {
  return SearchData;
}

//
// Use new search data.
//
inline void TEditSearch::SetSearchData(const TFindReplaceDialog::TData& searchdata) {
  SearchData = searchdata;
}

//
// Return the common dialog pointer.
//
inline TFindReplaceDialog* TEditSearch::GetSearchDialog() {
  return SearchDialog;
}

//
// Use new common dialog pointer.
//
inline void TEditSearch::SetSearchDialog(TFindReplaceDialog* searchdialog) {
  SearchDialog = searchdialog;
}

//
// Return the user selected command that brought up the search dialog.
//
inline uint TEditSearch::GetSearchCmd() {
  return SearchCmd;
}

//
// Remember the command the user selected to bring up the search dialog.
//
inline void TEditSearch::SetSearchCmd(uint searchcmd) {
  SearchCmd = searchcmd;
}


#endif  // OWL_EDITSEAR_H
