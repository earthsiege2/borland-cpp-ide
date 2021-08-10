//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 2000-2002 Borland Corporation. All Rights Reserved.
//---------------------------------------------------------------------------
//      Example:        VirtualListView
//      File:           VListView.h  Declaration Header File
//---------------------------------------------------------------------------

#ifndef VListViewH
#define VListViewH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include <ImgList.hpp>
#include <Menus.hpp>
#include <FileCtrl.hpp>
#include <ShellAPI.h>
#include <comObj.hpp>
//---------------------------------------------------------------------------

//ShellItem Struct
struct PShellItem
{
        public:
                //Variables
                PItemIDList FullID, ID;
                bool Empty;
                AnsiString DisplayName, TypeName, ModDate;
                int ImageIndex, Size;
                DWORD Attributes;
                //Constructor
                PShellItem();
};

// Function Declarations
int __fastcall ListSortFunc(void * Item1, void * Item2);
int __fastcall GetShellImage(PItemIDList PIDL, bool Large, bool Open);
int __fastcall GetPIDLSize(PItemIDList IDList);
bool IsFolder(LPSHELLFOLDER ShellFolder, PItemIDList ID);
bool __fastcall ValidFileTime(TFileTime FileTime);
bool IsFolder(PShellItem * ShellItem);
PItemIDList __fastcall CopyITEMID(LPMALLOC Malloc, PItemIDList ID);
PItemIDList __fastcall NextPIDL(PItemIDList IDList);
PItemIDList __fastcall CreatePIDL(int Size);
PItemIDList __fastcall CopyPIDL(PItemIDList IDList);
PItemIDList __fastcall StripLastID(PItemIDList IDList);
PItemIDList __fastcall ConcatPIDLs(PItemIDList IDList1, PItemIDList IDList2);
AnsiString __fastcall GetDisplayName(LPSHELLFOLDER ShellFolder, PItemIDList PIDL,
                        bool ForParsing);

// Main Form Class Declaration
class TfrmVirtualLView : public TForm
{
__published:	// IDE-managed Components
        TCoolBar *clbrMyCoolbar;
        TToolBar *tlbrMyButtons;
        TToolButton *tlbtnBrowse;
        TToolButton *tlbtnUpOneLevel;
        TToolButton *tlbtnSeperater;
        TToolButton *tlbtnLargeIcons;
        TToolButton *tlbtnSmallIcons;
        TToolButton *tlbtnList;
        TToolButton *tlbtnReport;
        TComboBox *cmbxPath;
        TImageList *imglstToolBarImages;
        TListView *lstvwVirtualList;
        TPopupMenu *pmnViews;
        TMenuItem *LargeIcons1;
        TMenuItem *SmallIcons1;
        TMenuItem *ListView1;
        TMenuItem *ReportView1;
        void __fastcall lstvwVirtualListCustomDrawItem(
          TCustomListView *Sender, TListItem *Item, TCustomDrawState State,
          bool &DefaultDraw);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall tlbtnBrowseClick(TObject *Sender);
        void __fastcall cmbxPathKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall cmbxPathClick(TObject *Sender);
        void __fastcall tlbtnLargeIconsClick(TObject *Sender);
        void __fastcall lstvwVirtualListDblClick(TObject *Sender);
        void __fastcall lstvwVirtualListKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall tlbtnUpOneLevelClick(TObject *Sender);
        void __fastcall lstvwVirtualListDataHint(TObject *Sender,
          int StartIndex, int EndIndex);
        void __fastcall lstvwVirtualListData(TObject *Sender,
          TListItem *Item);
        void __fastcall lstvwVirtualListDataFind(TObject *Sender,
          TItemFind Find, const AnsiString FindString,
          const TPoint &FindPosition, Pointer FindData, int StartIndex,
          TSearchDirection Direction, bool Wrap, int &Index);
        void __fastcall lstvwVirtualListCustomDrawSubItem(
          TCustomListView *Sender, TListItem *Item, int SubItem,
          TCustomDrawState State, bool &DefaultDraw);
        void __fastcall tlbtnReportClick(TObject *Sender);
        void __fastcall tlbtnSmallIconsClick(TObject *Sender);
        void __fastcall tlbtnListClick(TObject *Sender);
        void __fastcall LargeIcons1Click(TObject *Sender);
        void __fastcall SmallIcons1Click(TObject *Sender);
        void __fastcall ListView1Click(TObject *Sender);
        void __fastcall ReportView1Click(TObject *Sender);
private:	// User declarations
        TList * FIDList;
        PItemIDList FPIDL;
        LPSHELLFOLDER FIDesktopFolder;
        AnsiString FPath;

        PShellItem * __fastcall GetShellItem(int Index);
        void __fastcall SetPath(const AnsiString Value);
        void __fastcall SetPath(LPITEMIDLIST ID);
        void __fastcall PopulateIDList(LPSHELLFOLDER ShellFolder);
        void __fastcall ClearIDList();
        void __fastcall CheckShellItems();
        void __fastcall DisposePIDL(PItemIDList ID);
        void __fastcall CheckShellItems(int StartIndex, int EndIndex);


public:		// User declarations
        __fastcall TfrmVirtualLView(TComponent* Owner);
        LPSHELLFOLDER FIShellFolder;


};
//---------------------------------------------------------------------------
extern PACKAGE TfrmVirtualLView *frmVirtualLView;
//---------------------------------------------------------------------------
#endif
