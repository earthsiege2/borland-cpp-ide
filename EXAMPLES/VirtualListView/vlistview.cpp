//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 2000 Inprise Corporation. All Rights Reserved.
//---------------------------------------------------------------------------
//      Example:        VirtualListView
//      File:           VListView.cpp  Implementation File
//---------------------------------------------------------------------------
#define NO_WIN32_LEAN_AND_MEAN

#include <vcl.h>
#pragma hdrstop

#include "VListView.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TfrmVirtualLView *frmVirtualLView;

//---------------------------------------------------------------------------

__fastcall TfrmVirtualLView::TfrmVirtualLView(TComponent* Owner)
        : TForm(Owner)
{

}
//---------------------------------------------------------------------------

void __fastcall TfrmVirtualLView::lstvwVirtualListCustomDrawItem(
      TCustomListView *Sender, TListItem *Item, TCustomDrawState State,
      bool &DefaultDraw)
{
        int Attrs = 0;
        if (Item != NULL)
        {
                Attrs = GetShellItem(Item->Index)->Attributes;
        }
        if (BOOL(Attrs & FILE_ATTRIBUTE_READONLY))
                lstvwVirtualList->Canvas->Font->Color = clGrayText;
        if (BOOL(Attrs & FILE_ATTRIBUTE_HIDDEN))
                lstvwVirtualList->Canvas->Font->Style = lstvwVirtualList->Canvas->Font->Style << fsStrikeOut;
        if (BOOL(Attrs & FILE_ATTRIBUTE_SYSTEM))
                lstvwVirtualList->Canvas->Font->Color = clHighlight;
}
//---------------------------------------------------------------------------

void __fastcall TfrmVirtualLView::lstvwVirtualListCustomDrawSubItem(
      TCustomListView *Sender, TListItem *Item, int SubItem,
      TCustomDrawState State, bool &DefaultDraw)
{
       if (SubItem != 0)
                lstvwVirtualList->Canvas->Font->Color = GetSysColor(COLOR_WINDOWTEXT);
        //workaround for Win98 bug.
}
//---------------------------------------------------------------------------

void __fastcall TfrmVirtualLView::tlbtnReportClick(TObject *Sender)
{
        lstvwVirtualList->ViewStyle = vsReport;
}
//---------------------------------------------------------------------------

void __fastcall TfrmVirtualLView::tlbtnSmallIconsClick(TObject *Sender)
{
        lstvwVirtualList->ViewStyle = vsSmallIcon;
}
//---------------------------------------------------------------------------

void __fastcall TfrmVirtualLView::tlbtnListClick(TObject *Sender)
{
        lstvwVirtualList->ViewStyle = vsList;
}
//---------------------------------------------------------------------------

PShellItem * __fastcall TfrmVirtualLView::GetShellItem(int Index)
{
       return (PShellItem * )FIDList->Items[Index];
}
//---------------------------------------------------------------------------

void __fastcall TfrmVirtualLView::FormCreate(TObject *Sender)
{
        SHFILEINFO FileInfo;
        THandle ImageListHandle;
        PItemIDList NewPIDL;

        FPIDL = NULL;
        FIDList = new TList();

        OleCheck(SHGetDesktopFolder(&FIDesktopFolder));
        FIShellFolder = FIDesktopFolder;

        ImageListHandle = SHGetFileInfo("C:\\", 0, &FileInfo, sizeof(FileInfo),
                        SHGFI_SYSICONINDEX | SHGFI_SMALLICON);

        SendMessage(lstvwVirtualList->Handle, LVM_SETIMAGELIST, LVSIL_SMALL,
                 ImageListHandle);

        ImageListHandle = SHGetFileInfo("C:\\", 0, &FileInfo, sizeof(FileInfo),
                        SHGFI_SYSICONINDEX | SHGFI_LARGEICON);

        SendMessage(lstvwVirtualList->Handle, LVM_SETIMAGELIST, LVSIL_NORMAL,
                         ImageListHandle);

        OleCheck(SHGetSpecialFolderLocation(Application->Handle, CSIDL_DRIVES,
                         &NewPIDL));

        SetPath(NewPIDL);
        ActiveControl = cmbxPath;
        cmbxPath->SelStart = 0;
        cmbxPath->SelLength = cmbxPath->Text.Length();
        tlbtnReport->Down = true;
}
//---------------------------------------------------------------------------

void __fastcall TfrmVirtualLView::SetPath(AnsiString Value)
{
        wchar_t * P;
        PItemIDList NewPIDL;
        unsigned long int Flags;
        unsigned long int NumChars;

        NumChars = Value.Length();
        Flags = 0;
        P = StringToOleStr(Value);

        OleCheck( FIDesktopFolder->ParseDisplayName( Application->Handle, NULL,
                P, &NumChars, &NewPIDL, &Flags));

        SetPath(NewPIDL);
}
//---------------------------------------------------------------------------

void __fastcall TfrmVirtualLView::SetPath(LPITEMIDLIST ID)
{
        int Index;
        LPSHELLFOLDER  NewShellFolder;
        OleCheck(FIDesktopFolder->BindToObject(ID, NULL, IID_IShellFolder,
                        (void **)&NewShellFolder));

        lstvwVirtualList->Items->BeginUpdate();
        try
        {
                PopulateIDList(NewShellFolder);
                FPIDL = ID;
                FPath = GetDisplayName(FIDesktopFolder, FPIDL, true);
                Index = cmbxPath->Items->IndexOf(FPath);
                if (Index < 0)
                {
                        cmbxPath->Items->InsertObject(0, FPath, (TObject*)FPIDL);
                        cmbxPath->Text = FPath;
                }
                else
                {
                        cmbxPath->ItemIndex = Index;
                        cmbxPath->Text = FPath;
                }

                if (lstvwVirtualList->Items->Count > 0)
                {
                        lstvwVirtualList->Selected = lstvwVirtualList->Items->Item[0];
                        lstvwVirtualList->Selected->Focused = true;
                        lstvwVirtualList->Selected->MakeVisible(false);
                }
        }
        __finally
        {
                lstvwVirtualList->Items->EndUpdate();
        }

}
//---------------------------------------------------------------------------

void __fastcall TfrmVirtualLView::PopulateIDList(LPSHELLFOLDER ShellFolder)
{
        UINT Flags = SHCONTF_FOLDERS | SHCONTF_NONFOLDERS | SHCONTF_INCLUDEHIDDEN;

        PItemIDList ID;
        LPENUMIDLIST EnumList;
        unsigned long NumIDs;
        TCursor SaveCursor;
        PShellItem * ShellItem;

        SaveCursor = Screen->Cursor;
        try
        {
                Screen->Cursor = crHourGlass;
                OleCheck( ShellFolder->EnumObjects( Application->Handle,
                                Flags, &EnumList));

                FIShellFolder = ShellFolder;
                ClearIDList();
                while (EnumList->Next(1, &ID, &NumIDs) == S_OK)
                {
                        ShellItem = new PShellItem;
                        ShellItem->ID = ID;
                        ShellItem->DisplayName = GetDisplayName(FIShellFolder, ID, False);
                        ShellItem->Empty = true;
                        FIDList->Add(ShellItem);
                }

                FIDList->Sort(ListSortFunc);

                //We need to tell the ListView how many items it has.
                lstvwVirtualList->Items->Count = FIDList->Count;

                lstvwVirtualList->Repaint();
        }
        __finally
        {
                Screen->Cursor = SaveCursor;
        }
}
//---------------------------------------------------------------------------

void __fastcall TfrmVirtualLView::ClearIDList()
{
        int I;

        for (I = 0; I <= FIDList->Count-1; I++)
        {
                DisposePIDL(GetShellItem(I)->ID);
                FIDList->Delete(I);
        }
        FIDList->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TfrmVirtualLView::DisposePIDL(PItemIDList ID)
{
        LPMALLOC Malloc;

        if (ID != NULL)
        {
                OleCheck(SHGetMalloc(&Malloc));
                Malloc->Free(ID);
        }
}

//----------------------------------------------------------------------------

void __fastcall TfrmVirtualLView::tlbtnBrowseClick(TObject *Sender)
{
        AnsiString S;
        S = "";
        if (SelectDirectory("Select Directory", "", S))
                SetPath(S);
}
//---------------------------------------------------------------------------

void __fastcall TfrmVirtualLView::cmbxPathKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
        if (Key == VK_RETURN)
        {
                if (cmbxPath->Text[cmbxPath->Text.Length()] == ':')
                {
                        cmbxPath->Text = cmbxPath->Text + "\\";
                        SetPath(cmbxPath->Text);
                        Key = 0;
                }
        }
}
//---------------------------------------------------------------------------

void __fastcall TfrmVirtualLView::cmbxPathClick(TObject *Sender)
{
        int I;

        I = cmbxPath->Items->IndexOf(cmbxPath->Text);

        if (I >= 0)
                SetPath(PItemIDList(cmbxPath->Items->Objects[I]));
        else
                SetPath(cmbxPath->Text);
}
//---------------------------------------------------------------------------

void __fastcall TfrmVirtualLView::tlbtnLargeIconsClick(TObject *Sender)
{
        lstvwVirtualList->ViewStyle = vsIcon;
}
//---------------------------------------------------------------------------

void __fastcall TfrmVirtualLView::lstvwVirtualListDblClick(TObject *Sender)
{
        PItemIDList RootPIDL;
        PItemIDList ID;

        if (lstvwVirtualList->Selected != NULL)
        {
                int I = lstvwVirtualList->Selected->Index;
                ID = GetShellItem(I)->ID;
                if (IsFolder(FIShellFolder, ID))
                {
                        RootPIDL = ConcatPIDLs(FPIDL, ID);
                        SetPath(RootPIDL);
                }
        }
}
//---------------------------------------------------------------------------

void __fastcall TfrmVirtualLView::lstvwVirtualListKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
        switch(Key)
        {
                case VK_RETURN:         lstvwVirtualListDblClick(Sender);
                                        break;
                case VK_BACK:           tlbtnUpOneLevelClick(Sender);
                                        break;
        }
}

//---------------------------------------------------------------------------

void __fastcall TfrmVirtualLView::CheckShellItems(int StartIndex, int EndIndex)
{
        TWin32FindData FileData;
        TSHFileInfo FileInfo;
        TSystemTime SysTime;
        int I;
        TFileTime LocalFileTime;

        //Here all the data that wasn't initialized in PopulateIDList is
        //filled in.
        for(I = StartIndex; I <= EndIndex; I++)
        {
                if (GetShellItem(I)->Empty)
                {
                        GetShellItem(I)->FullID = ConcatPIDLs(FPIDL, GetShellItem(I)->ID);
                        GetShellItem(I)->ImageIndex = GetShellImage(GetShellItem(I)->FullID, (lstvwVirtualList->ViewStyle == vsIcon), false);

                        //File Type
                        SHGetFileInfo(PChar(GetShellItem(I)->FullID), 0, &FileInfo, sizeof(FileInfo), SHGFI_TYPENAME | SHGFI_PIDL);
                        GetShellItem(I)->TypeName = FileInfo.szTypeName;

                        //Get File info from Windows
                        memset(&FileData, 0, sizeof(FileData));
                        SHGetDataFromIDList(FIShellFolder, GetShellItem(I)->ID, SHGDFIL_FINDDATA, &FileData, sizeof(FileData));

                        //File Size, in KB
                        GetShellItem(I)->Size = FileData.nFileSizeLow/1000;
                        if (GetShellItem(I)->Size == 0)
                                GetShellItem(I)->Size = 1;

                        //Modified Date
                        memset(&LocalFileTime, 0, sizeof(LocalFileTime));
                        //with FileData do
                        if (ValidFileTime(FileData.ftLastWriteTime)&&
                                FileTimeToLocalFileTime(&(FileData.ftLastWriteTime),
                                &LocalFileTime)&&
                                FileTimeToSystemTime(&LocalFileTime, &SysTime))
                        {
                                try
                                {
                                        GetShellItem(I)->ModDate = DateTimeToStr(SystemTimeToDateTime(SysTime));
                                }
                                catch(EConvertError &E)
                                {
                                        GetShellItem(I)->ModDate = "";
                                }
                        }
                        else
                                GetShellItem(I)->ModDate = "";

                        //Attributes
                        GetShellItem(I)->Attributes = FileData.dwFileAttributes;

                        //Flag this record as complete.
                        GetShellItem(I)->Empty = False;
                }
        }
}
//-------------------------------------------------------------------------

void __fastcall TfrmVirtualLView::tlbtnUpOneLevelClick(TObject *Sender)
{
        PItemIDList Temp;

        Temp = CopyPIDL(FPIDL);

        if (Temp != NULL)
                StripLastID(Temp);
        if (Temp->mkid.cb != 0)
                SetPath(Temp);
        else
                Sysutils::Beep;
}
//---------------------------------------------------------------------------

void __fastcall TfrmVirtualLView::lstvwVirtualListDataHint(TObject *Sender,
      int StartIndex, int EndIndex)
{
        if ((StartIndex < FIDList->Count) && (EndIndex < FIDList->Count))
                CheckShellItems(StartIndex, EndIndex);
}
//---------------------------------------------------------------------------

void __fastcall TfrmVirtualLView::lstvwVirtualListData(TObject *Sender,
      TListItem *Item)
{
        AnsiString Attrs;
        PShellItem * ShellItem;
        //OnData gets called once for each item for which the ListView needs
        //data. If the ListView is in Report View, be sure to add the subitems.
        //Item is a "dummy" item whose only valid data is it's index which
        //is used to index into the underlying data.
        if ((Item->Index < FIDList->Count))
        {

                ShellItem = GetShellItem(Item->Index);
                Item->Caption = ShellItem->DisplayName;
                Item->ImageIndex = ShellItem->ImageIndex;

                if (lstvwVirtualList->ViewStyle == vsReport)
                {
                        if (!(IsFolder(FIShellFolder, ShellItem->ID)))
                                Item->SubItems->Add(Format("%dKB", ARRAYOFCONST((ShellItem->Size))));
                        else
                                Item->SubItems->Add("");

                        Item->SubItems->Add(ShellItem->TypeName);

                        Item->SubItems->Add(ShellItem->ModDate);

                        if (BOOL(ShellItem->Attributes & FILE_ATTRIBUTE_READONLY))
                                Attrs = Attrs + 'R';
                        if (BOOL(ShellItem->Attributes & FILE_ATTRIBUTE_HIDDEN))
                                Attrs = Attrs + 'H';
                        if (BOOL(ShellItem->Attributes & FILE_ATTRIBUTE_SYSTEM))
                                Attrs = Attrs + 'S';
                        if (BOOL(ShellItem->Attributes & FILE_ATTRIBUTE_ARCHIVE))
                                Attrs = Attrs + 'A';

                        Item->SubItems->Add(Attrs);
                }
        }
}
//---------------------------------------------------------------------------

void __fastcall TfrmVirtualLView::lstvwVirtualListDataFind(TObject *Sender,
      TItemFind Find, const AnsiString FindString,
      const TPoint &FindPosition, Pointer FindData, int StartIndex,
      TSearchDirection Direction, bool Wrap, int &Index)
{
        //OnDataFind gets called in response to calls to FindCaption, FindData,
        //GetNearestItem, etc. It also gets called for each keystroke sent to the
        //ListView (for incremental searching)
        int I;
        bool Found;
        PShellItem * ShellItem;

        I = StartIndex;

        if ((Find == ifExactString) || (Find == ifPartialString))
        {
                do
                {
                        ShellItem = GetShellItem(I);
                        if (I == FIDList->Count-1)
                        {
                                if (Wrap)
                                        I = 0;
                                else
                                        break;
                        }
                        Found = (UpperCase(ShellItem->DisplayName)).Pos(UpperCase(FindString)) == 1;
                        I++;
                }while (!Found && (I != StartIndex));
                if (Found)
                        Index = I-1;

        }
}
//---------------------------------------------------------------------------

void __fastcall TfrmVirtualLView::LargeIcons1Click(TObject *Sender)
{
        tlbtnLargeIcons->Down = true;
        tlbtnLargeIconsClick(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TfrmVirtualLView::SmallIcons1Click(TObject *Sender)
{
        tlbtnSmallIcons->Down = true;
        tlbtnSmallIconsClick(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TfrmVirtualLView::ListView1Click(TObject *Sender)
{
        tlbtnList->Down = true;
        tlbtnListClick(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TfrmVirtualLView::ReportView1Click(TObject *Sender)
{
        tlbtnReport->Down = true;
        tlbtnReportClick(Sender);
}
//---------------------------------------------------------------------------
// PIDL Manipulation
//---------------------------------------------------------------------------

PItemIDList __fastcall CopyITEMID(LPMALLOC Malloc, PItemIDList ID)
{
        void * Result = Malloc->Alloc(ID->mkid.cb + sizeof(ID->mkid.cb));
        CopyMemory(Result, ID, ID->mkid.cb + sizeof(ID->mkid.cb));
        return (PItemIDList)Result;
}
//---------------------------------------------------------------------------

PItemIDList __fastcall NextPIDL(PItemIDList IDList)
{
        PItemIDList Result = IDList;
        Result = PItemIDList(PChar(Result) + IDList->mkid.cb);
        return Result;
}
//---------------------------------------------------------------------------

int __fastcall GetPIDLSize(PItemIDList IDList)
{
        int Result = 0;
        if (IDList != NULL)
        {
                Result = sizeof(IDList->mkid.cb);
                while (IDList->mkid.cb != 0)
                {
                        Result = Result + IDList->mkid.cb;
                        IDList = NextPIDL(IDList);
                }
        }
        return Result;
}
//---------------------------------------------------------------------------

PItemIDList __fastcall StripLastID(PItemIDList IDList)
{
        PItemIDList MarkerID;

        MarkerID = IDList;
        if (IDList != NULL)
        {
                while (IDList->mkid.cb != 0)
                {
                        MarkerID = IDList;
                        IDList = NextPIDL(IDList);
                }
                MarkerID->mkid.cb = 0;
        }
        return MarkerID;
}
//---------------------------------------------------------------------------

PItemIDList __fastcall CreatePIDL(int Size)
{
        LPMALLOC Malloc;
        HRESULT HR;
        void * Result;

        Result = NULL;


        if (!FAILED(SHGetMalloc(&Malloc)))
        {
                Result = Malloc->Alloc(Size);
                if ((PItemIDList)Result != NULL)
                {
                        memset(Result,0, sizeof(Result));
                }

        }
        return (PItemIDList) Result;
}
//---------------------------------------------------------------------------

PItemIDList __fastcall CopyPIDL(PItemIDList IDList)
{
        int Size;
        PItemIDList Result;

        Size = GetPIDLSize(IDList);
        Result = CreatePIDL(Size);
        if (Result != NULL)
        {
                CopyMemory(Result, IDList, Size);
        }
        return Result;
}
//---------------------------------------------------------------------------

PItemIDList __fastcall ConcatPIDLs(PItemIDList IDList1, PItemIDList IDList2)
{
        int cb1;
        int cb2;
        PItemIDList Result;

        if (IDList1 != NULL)
                cb1 = GetPIDLSize(IDList1) - sizeof(IDList1->mkid.cb);
        else
                cb1 = 0;

        cb2 = GetPIDLSize(IDList2);

        Result = CreatePIDL(cb1 + cb2);
        if (Result != NULL)
        {
                if (IDList1 != NULL)
                        CopyMemory(Result, IDList1, cb1);
                CopyMemory(PChar(Result) + cb1, IDList2, cb2);
        }
        return Result;
}
//---------------------------------------------------------------------------
// Shell Folder Item Info
//---------------------------------------------------------------------------

int __fastcall GetShellImage(PItemIDList PIDL, bool Large, bool Open)
{
        TSHFileInfo FileInfo;
        int Flags;
        int Result;

        memset(&FileInfo, 0, sizeof(FileInfo));
        Flags = SHGFI_PIDL | SHGFI_SYSICONINDEX | SHGFI_ICON;

        if (Open)
                Flags = Flags | SHGFI_OPENICON;
        if (Large)
                Flags = Flags | SHGFI_LARGEICON;
        else
                Flags = Flags | SHGFI_SMALLICON;

        SHGetFileInfo(PChar(PIDL), 0, &FileInfo, sizeof(FileInfo), Flags);
        Result = FileInfo.iIcon;
        return Result;
}
//---------------------------------------------------------------------------

bool IsFolder(PShellItem * ShellItem)
{
        if (ShellItem->TypeName == "File Folder")
                return true;
        else
                return false;
}
//---------------------------------------------------------------------------
bool IsFolder(LPSHELLFOLDER ShellFolder, PItemIDList ID)
{
        unsigned long Flags;
        bool Result;

        Flags = SFGAO_FOLDER;

        ShellFolder->GetAttributesOf(1, (const _ITEMIDLIST **) &ID, &Flags);
        Result = ((SFGAO_FOLDER & Flags) !=0);
        
        return Result;
}
//---------------------------------------------------------------------------

bool __fastcall ValidFileTime(TFileTime FileTime)
{
        bool Result = ((FileTime.dwLowDateTime != 0) || (FileTime.dwHighDateTime != 0));
        return Result;
}
//---------------------------------------------------------------------------

int __fastcall ListSortFunc(void * Item1, void * Item2)
{
        return Smallint(frmVirtualLView->FIShellFolder->CompareIDs(0,
                 ((PShellItem *)Item1)->ID, ((PShellItem *)Item2)->ID));
}
//---------------------------------------------------------------------------

AnsiString __fastcall GetDisplayName(LPSHELLFOLDER ShellFolder, PItemIDList PIDL,
                       bool ForParsing)
{

        TStrRet StrRet;
        PChar  P;
        int Flags;
        AnsiString * Result;

        if (ForParsing)
        {
                Flags = SHGDN_FORPARSING;
        }
        else
                Flags = SHGDN_NORMAL;

        ShellFolder->GetDisplayNameOf(PIDL, Flags, &StrRet);

        switch (StrRet.uType)
        {
                case STRRET_CSTR:       Result = new AnsiString(StrRet.cStr, strlen(StrRet.cStr));
                                        break;
                case STRRET_OFFSET:     P = &PIDL->mkid.abID[StrRet.uOffset - sizeof(PIDL->mkid.cb)];
                                        Result = new AnsiString(P);
                                        break;
                case STRRET_WSTR:       Result = new AnsiString(StrRet.pOleStr);
                                        break;
        }
        return (*Result);
}
//--------------------------------------------------------------------------
//      ShellItem Constructor.
//--------------------------------------------------------------------------
PShellItem::PShellItem()
{
        FullID = NULL;
        ID = NULL;
        Empty = true;
        DisplayName = "";
        TypeName = "";
        ModDate = "";
        ImageIndex = 0;
        Size = 0;
        Attributes = 0;
}


//End of File



