//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "ShellCtrls.h"
#include "ShellConsts.h"
#include <ComObj.hpp>

#include "Consts.hpp"
#include <Controls.hpp>

//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------

// If you get compiler errors in this unit, you must define NO_WIN32_LEAN_AND_MEAN

const int nFolder[] = {CSIDL_DESKTOP, CSIDL_DRIVES, CSIDL_NETWORK, CSIDL_BITBUCKET, CSIDL_APPDATA,
    CSIDL_COMMON_DESKTOPDIRECTORY, CSIDL_COMMON_PROGRAMS, CSIDL_COMMON_STARTMENU,
    CSIDL_COMMON_STARTUP, CSIDL_CONTROLS, CSIDL_DESKTOPDIRECTORY, CSIDL_FAVORITES,
    CSIDL_FONTS, CSIDL_INTERNET, CSIDL_PERSONAL, CSIDL_PRINTERS, CSIDL_PRINTHOOD,
    CSIDL_PROGRAMS, CSIDL_RECENT, CSIDL_SENDTO, CSIDL_STARTMENU, CSIDL_STARTUP,
    CSIDL_TEMPLATES};

PChar cmvProperties = "properties";  // Do not localize
_di_IContextMenu ICM = NULL;
_di_IContextMenu2 ICM2 = NULL;
TShellFolder *DesktopFolder = NULL;
TRTLCriticalSection CS;
_di_IMalloc ShellMalloc = NULL;
TShellFolder *CompareFolder = NULL;


TShellFolderCapabilities GetCaps(_di_IShellFolder ParentFolder, PItemIDList PIDL);
TShellFolderProperties GetProperties(_di_IShellFolder ParentFolder, PItemIDList PIDL);
int GetShellImage(PItemIDList PIDL, bool Large, bool Open);
bool GetIsFolder(_di_IShellFolder ParentFolder, PItemIDList PIDL);
bool GetHasSubFolders(_di_IShellFolder ParentFolder, PItemIDList PIDL);
bool GetHasSubItems(_di_IShellFolder ShellFolder, int Flags);

void NoFolderDetails(TShellFolder *AFolder, HResult HR);
PItemIDList CreatePIDL(int Size);
PItemIDList NextPIDL(PItemIDList IDList);
void StripLastID(PItemIDList IDList);
int GetPIDLSize(PItemIDList IDList);
PItemIDList CopyPIDL(PItemIDList IDList);
PItemIDList ConcatPIDLs(PItemIDList IDList1, PItemIDList IDList2);
void DisposePIDL(PItemIDList PIDL);
PItemIDList RelativeFromAbsolute(PItemIDList AbsoluteID);
TList *CreatePIDLList(PItemIDList ID);
void DestroyPIDLList(TList *List);
String StrRetToString(PItemIDList PIDL, TStrRet StrRet);
bool SamePIDL(PItemIDList ID1, PItemIDList ID2);
PItemIDList DesktopPIDL(void);

String GetDisplayName(_di_IShellFolder ParentFolder, PItemIDList PIDL, DWORD Flags);
int GetShellImage(PItemIDList PIDL, bool Large, bool Open);
_di_IShellFolder DesktopShellFolder(void);

Shlobj::_di_IShellDetails GetIShellDetails(_di_IShellFolder IFolder, PItemIDList PIDL,
    HWND Handle = 0);

_di_IShellFolder2 GetIShellFolder2(_di_IShellFolder IFolder, PItemIDList PIDL,
    HWND Handle = 0);

TShellFolder *CreateRootFromPIDL(PItemIDList Value);
TShellFolder *CreateRootFolder(TShellFolder *RootFolder, TRoot OldRoot, TRoot NewRoot);
void DoContextMenuVerb(TShellFolder *AFolder, PChar Verb);

_di_IShellFolder GetIShellFolder(_di_IShellFolder IFolder, PItemIDList PIDL, HWND Handle = 0);

bool GetHasSubItems(_di_IShellFolder ShellFolder, int Flags);
int ObjectFlags(TShellObjectTypes ObjectTypes);
int __fastcall ComboSortFunc(void *Item1, void *Item2);
int __fastcall ListSortFunc(void *Item1, void *Item2);
int CALLBACK TreeSortFunc(LPARAM, LPARAM, LPARAM);

//---------------------------------------------------------------------------
// EInvalidPath -------------------------------------------------------------

__fastcall EInvalidPath::EInvalidPath(const AnsiString Msg): Sysutils::Exception(Msg)
{
}
//---------------------------------------------------------------------------

__fastcall EInvalidPath::EInvalidPath(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size)
                                    : Sysutils::Exception(Msg, Args, Args_Size)
{
}
//---------------------------------------------------------------------------

__fastcall EInvalidPath::EInvalidPath(int Ident): Sysutils::Exception(Ident)
{
}
//---------------------------------------------------------------------------

__fastcall EInvalidPath::EInvalidPath(int Ident, const System::TVarRec * Args, const int Args_Size)
                                : Sysutils::Exception(Ident, Args, Args_Size)
{
}
//---------------------------------------------------------------------------

__fastcall EInvalidPath::EInvalidPath(const AnsiString Msg, int AHelpContext)
                                    : Sysutils::Exception(Msg, AHelpContext)
{
}
//---------------------------------------------------------------------------

__fastcall EInvalidPath::EInvalidPath(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext)
                        : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext)
{
}
//---------------------------------------------------------------------------

__fastcall EInvalidPath::EInvalidPath(int Ident, int AHelpContext)
                                    : Sysutils::Exception(Ident, AHelpContext)
{
}
//---------------------------------------------------------------------------

__fastcall EInvalidPath::EInvalidPath(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)
            : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext)
{
}
//---------------------------------------------------------------------------

__fastcall EInvalidPath::~EInvalidPath(void)
{
}
//---------------------------------------------------------------------------
// TShellFolder -------------------------------------------------------------

__fastcall TShellFolder::TShellFolder(TShellFolder* AParent,
    Shlobj::PItemIDList ID, _di_IShellFolder SF)
{
    FLevel = 0;
    FDetails = new TStringList();

    FIShellFolder = SF;
    FIShellFolder2 = NULL;
    FIShellDetails = NULL;
    FParent = AParent;
    FPIDL = CopyPIDL(ID);
    if (FParent)
    {
        FFullPIDL = ConcatPIDLs(AParent->FFullPIDL, ID);
    }
    else
    {
        PItemIDList DesktopID = DesktopPIDL();
        try
        {
            FFullPIDL = ConcatPIDLs(DesktopID, ID);
        }
        __finally  {
            DisposePIDL(DesktopID);
        }
    }

    if (FParent == NULL)
        FParent = DesktopFolder;

    while (AParent)
    {
        AParent = AParent->Parent;
        if (AParent)
            FLevel++;
    }
}
//---------------------------------------------------------------------------

__fastcall TShellFolder::~TShellFolder(void)
{
    if (FDetails)
        delete FDetails;

    if(FPIDL != NULL)
        DisposePIDL(FPIDL);

    if(FFullPIDL != NULL)
        DisposePIDL(FFullPIDL);
}
//---------------------------------------------------------------------------

System::_di_IInterface __fastcall TShellFolder::GetDetailInterface()
{
    System::_di_IInterface Result = FDetailInterface;

    if(FDetailInterface == NULL && FIShellFolder != NULL)
    {
        FIShellDetails = GetIShellDetails(FIShellFolder, FFullPIDL, FViewHandle);
        
        if(FIShellDetails == NULL && Win32MajorVersion >= 5)
        {
            FIShellFolder2 = GetIShellFolder2(FIShellFolder, FFullPIDL, FViewHandle);
            if(FIShellFolder2 == NULL) // Hack!
            {
                /*Note: Although QueryInterface will not work in this instance,
                    IShellFolder2 is indeed supported for this Folder if IShellDetails
                    is not. In all tested cases, hard-casting the interface to
                    IShellFolder2 has worked. Hopefully, Microsoft will fix this bug in
                    a future release of ShellControls */
                //FIShellFolder2 = static_cast<_di_IShellFolder2>(FIShellFolder);
                FIShellFolder2 = (_di_IShellFolder2)FIShellFolder;
            }
        }

        if(FIShellFolder2 != NULL)
            Result = FIShellFolder2;
        else
            Result = FIShellDetails;

        FDetailInterface = Result;
    }

    return Result;
}
//---------------------------------------------------------------------------

Shlobj::_di_IShellDetails __fastcall TShellFolder::GetShellDetails()
{
    if(FDetailInterface == NULL)
        GetDetailInterface();

    return FIShellDetails;
}
//---------------------------------------------------------------------------

_di_IShellFolder2 __fastcall TShellFolder::GetShellFolder2()
{
    if(FDetailInterface == NULL)
        GetDetailInterface();

    return FIShellFolder2;
}
//---------------------------------------------------------------------------

AnsiString __fastcall TShellFolder::GetDetails(int Index)
{
    String Result = "";

    if(FDetails->Count > 0)
        Result = FDetails->Strings[Index-1]; // Index is 1-based
    else
    {
        TVarRec Records[] = { this->DisplayName() };
        throw Exception(SCallLoadDetails,  Records, 1);
    }

    return Result;
}
//---------------------------------------------------------------------------

void __fastcall TShellFolder::SetDetails(int Index, const AnsiString Value)
{
    if(Index < FDetails->Count)
        FDetails->Strings[Index] = Value;
    else
        FDetails->Insert(Index, Value);
}
//---------------------------------------------------------------------------

TWin32FindData GetDetailsOf(TShellFolder *AFolder)
{
    char szPath[MAX_PATH];
    String Path;
    HWND Handle;

    TWin32FindData Details;

    memset(&Details, 0, sizeof(TWin32FindData));
    memset(szPath, 0, MAX_PATH);
    
    Path = AFolder->PathName();
    Handle = FindFirstFile(Path.c_str(), &Details);
    try
    {
        if(Handle == INVALID_HANDLE_VALUE)
            NoFolderDetails(AFolder, GetLastError());
    }
    __finally
    {
        FindClose(Handle);
    }
    return Details;
}

long long CalcFileSize(TWin32FindData FindData)
{
    if((FindData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) == 0)
        return FindData.nFileSizeHigh * MAXDWORD + FindData.nFileSizeLow;

    return -1;
}

TDateTime CalcModifiedDate(TWin32FindData FindData)
{
    TFileTime LocalFileTime;
    int Age;

    if((FindData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) == 0)
    {
        FileTimeToLocalFileTime(&FindData.ftLastWriteTime, &LocalFileTime);

        WORD *AgeHi = (WORD*)(&Age + sizeof(WORD));
        WORD *AgeLo = (WORD*)&Age;

        if(FileTimeToDosDateTime(&LocalFileTime, AgeHi, AgeLo))
            return FileDateToDateTime(Age);
    }

    return -1;
}

String DefaultDetailColumn(TWin32FindData FindData, int Col)
{
    String Result = "";

    switch(Col)
    {
        case 1:
            Result = IntToStr(CalcFileSize(FindData)); // Size
            break;

        case 2:
            Result = ExtractFileExt(FindData.cFileName); // Type
            break;

        case 3:
            Result = DateTimeToStr(CalcModifiedDate(FindData)); // Modified
            break;

        case 4:
            Result = IntToStr(FindData.dwFileAttributes);
            break;
    }

    return Result;
}

void AddDetail(HResult HR, PItemIDList PIDL, TShellDetails *SD, Classes::TStrings *FDetails)
{
    if(HR == S_OK)
        FDetails->Add(StrRetToString(PIDL, SD->str));
    else
        FDetails->Add("");
}

void __fastcall TShellFolder::LoadColumnDetails(TShellFolder* RootFolder, HWND Handle, int ColumnCount)
{
    if(FDetails == NULL || FDetails->Count >= ColumnCount) // Details are loaded
        return;

    HResult HR;
    TWin32FindData FindData;

    FDetails->Clear();
    FViewHandle = Handle;

    TShellDetails SD;
    memset(&SD, 0, sizeof(SD));
    _di_IShellFolder2 SF2 = RootFolder->ShellFolder2;
    if(SF2 != NULL)
    {
        // Already have name and icon, so see if we can provide details
        for (int j = 1; j <= ColumnCount; j++) // start at index 1, to up to and including ColumnCount
        {
            HR = SF2->GetDetailsOf(FPIDL, j, &SD);
            AddDetail(HR, FPIDL, &SD, FDetails);
        }
    }
    else
    {
        Shlobj::_di_IShellDetails ISD = RootFolder->ShellDetails;
        if(ISD != NULL)
        {
            for(int j = 1; j <= ColumnCount; j++)
            {
                HR = ISD->GetDetailsOf(FPIDL, j, SD);
                AddDetail(HR, FPIDL, &SD, FDetails);
            }
        }
        else if(RootFolder->Properties().Contains(fpFileSystem))
        {
            FindData = GetDetailsOf(this);
            for(int j = 1; j <= ColumnCount; j++)
                FDetails->Add(DefaultDetailColumn(FindData, j));
        }
    }
}
//---------------------------------------------------------------------------

TShellFolderCapabilities __fastcall TShellFolder::Capabilities(void)
{
    return GetCaps(ParentShellFolder(), FPIDL);
}
//---------------------------------------------------------------------------

AnsiString __fastcall TShellFolder::DisplayName()
{
    _di_IShellFolder ParentFolder;

    if(Parent != NULL)
        ParentFolder = ParentShellFolder();
    else
        ParentFolder = DesktopShellFolder();

    return GetDisplayName(ParentFolder, FPIDL, SHGDN_INFOLDER);
}
//---------------------------------------------------------------------------

int __fastcall TShellFolder::ExecuteDefault(void)
{
    SHELLEXECUTEINFO sei;
    memset(&sei, 0, sizeof(SHELLEXECUTEINFO));
    sei.cbSize = sizeof(SHELLEXECUTEINFO);
    sei.hwnd = Application->Handle;
    sei.fMask = SEE_MASK_INVOKEIDLIST;
    sei.lpIDList = AbsoluteID;
    sei.nShow = SW_SHOW;
    return ShellExecuteEx(&sei);
}

//---------------------------------------------------------------------------

int __fastcall TShellFolder::ImageIndex(bool LargeIcon)
{
    return GetShellImage(AbsoluteID, LargeIcon, false);
}
//---------------------------------------------------------------------------

bool __fastcall TShellFolder::IsFolder(void)
{
    return GetIsFolder(ParentShellFolder(), FPIDL);
}
//---------------------------------------------------------------------------

_di_IShellFolder __fastcall TShellFolder::ParentShellFolder()
{
    _di_IShellFolder Result = NULL;

    if(FParent != NULL)
        Result = FParent->ShellFolder;
    else
        OleCheck(SHGetDesktopFolder(&Result));

    return Result;
}
//---------------------------------------------------------------------------

AnsiString __fastcall TShellFolder::PathName()
{
    return GetDisplayName(DesktopShellFolder(), FFullPIDL, SHGDN_FORPARSING);
}
//---------------------------------------------------------------------------

TShellFolderProperties __fastcall TShellFolder::Properties(void)
{
    return GetProperties(ParentShellFolder(), FPIDL);
}
//---------------------------------------------------------------------------

bool __fastcall TShellFolder::Rename(const WideString NewName)
{
      PItemIDList NewPIDL;

    bool Result = false;
    if(!Capabilities().Contains(fcCanRename))
        return Result;

      Result = ParentShellFolder()->SetNameOf(0, FPIDL, NewName, SHGDN_NORMAL, &NewPIDL) == S_OK;
      if(Result)
    {
        DisposePIDL(FPIDL);
        DisposePIDL(FFullPIDL);
        FPIDL = NewPIDL;
        if (FParent != NULL)
            FFullPIDL = ConcatPIDLs(FParent->FPIDL, NewPIDL);
        else
            FFullPIDL = CopyPIDL(NewPIDL);
    }
    else
    {
        String strName = NewName;
        TVarRec Records[] = { strName };
        throw(Exception(SRenamedFailedError, Records, 1));
    }

    return Result;
}
//---------------------------------------------------------------------------

bool __fastcall TShellFolder::SubFolders(void)
{
    return GetHasSubFolders(ParentShellFolder(), FPIDL);
}
//---------------------------------------------------------------------------
// TShellChangeThread -------------------------------------------------------

__fastcall TShellChangeThread::TShellChangeThread(Classes::TThreadMethod ChangeEvent)
                                                        : TThread(true)
{
    FreeOnTerminate = false; 
    FChangeEvent = ChangeEvent;
    FWaitHandle = INVALID_HANDLE_VALUE;
    FWaitChanged = false;
    FMutex = CreateMutex(NULL,
        true /* initial owner - must be Release'd by this thread*/,
        NULL);
    if (FMutex)
        WaitForSingleObject(FMutex, INFINITE);
}
//---------------------------------------------------------------------------

__fastcall TShellChangeThread::~TShellChangeThread(void)
{
    FChangeEvent = NULL;
    FWaitChanged = false;
    
    if (FWaitHandle != INVALID_HANDLE_VALUE)
    {
        HANDLE hOld = FWaitHandle;
        FWaitHandle = 0;
        FindCloseChangeNotification(hOld);
    }
}
//---------------------------------------------------------------------------

void __fastcall TShellChangeThread::Execute(void)
{

    EnterCriticalSection(&CS);
    FWaitHandle = FindFirstChangeNotification(FDirectory.c_str(),
        FWatchSubTree, FNotifyOptionFlags);
    LeaveCriticalSection(&CS);
    if (FWaitHandle == INVALID_HANDLE_VALUE)
        return;

    while(!Terminated)
    {
        HANDLE hHandles[2];
        hHandles[0] = FWaitHandle;
        hHandles[1] = FMutex;

        int Obj = WaitForMultipleObjects(2, hHandles, false, INFINITE);
        switch(Obj)
        {
            case WAIT_OBJECT_0: // FWaitHandle
            {
                  if (FChangeEvent)
                      Synchronize(FChangeEvent);
                  if (FWaitHandle)
                      FindNextChangeNotification(FWaitHandle);
                  break;
            }
            case WAIT_OBJECT_0+1: // FMutex
            {
                ReleaseMutex(FMutex);
                break;
            }
            default: 
                return;
        }

        if(FWaitChanged)
        {
            EnterCriticalSection(&CS);
            FWaitHandle = FindFirstChangeNotification(FDirectory.c_str(),
                FWatchSubTree, FNotifyOptionFlags);
            FWaitChanged = false;
            LeaveCriticalSection(&CS);
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TShellChangeThread::SetDirectoryOptions(AnsiString Directory, bool WatchSubTree, unsigned NotifyOptionFlags)
{
    EnterCriticalSection(&CS);
    FDirectory = Directory;
    FWatchSubTree = WatchSubTree;
    FNotifyOptionFlags = NotifyOptionFlags;

    // Release the current notification handle
    FindCloseChangeNotification(FWaitHandle);
    FWaitChanged = true;
    LeaveCriticalSection(&CS);
}
//---------------------------------------------------------------------------
// TCustomShellChangeNotifier -----------------------------------------------
void __fastcall TCustomShellChangeNotifier::SetRoot(const AnsiString Value)
{
    if(FRoot == Value)
        return;

       FRoot = Value;
    Change();
}
//---------------------------------------------------------------------------

void __fastcall TCustomShellChangeNotifier::SetWatchSubTree(const bool Value)
{
    FWatchSubTree = Value;
    Change();
}
//---------------------------------------------------------------------------

void __fastcall TCustomShellChangeNotifier::SetFilters(const TNotifyFilters Value)
{
    FFilters = Value;
    Change();
}
//---------------------------------------------------------------------------

void __fastcall TCustomShellChangeNotifier::SetOnChange(const Classes::TThreadMethod Value)
{
    FOnChange = Value;
    if(FThread != NULL)
        FThread->ChangeEvent = FOnChange;
    else
        Start();
}
//---------------------------------------------------------------------------

DWORD NotifyOptionFlags(TNotifyFilters FFilters)
{
    DWORD Result = 0;
    if(FFilters.Contains(nfFileNameChange))
        Result |= FILE_NOTIFY_CHANGE_FILE_NAME;
    if(FFilters.Contains(nfDirNameChange))
        Result |= FILE_NOTIFY_CHANGE_DIR_NAME;
    if(FFilters.Contains(nfSizeChange))
        Result |= FILE_NOTIFY_CHANGE_SIZE;
    if(FFilters.Contains(nfAttributeChange))
        Result |= FILE_NOTIFY_CHANGE_ATTRIBUTES;
    if(FFilters.Contains(nfWriteChange))
        Result |= FILE_NOTIFY_CHANGE_LAST_WRITE;
    if(FFilters.Contains(nfSecurityChange))
        Result |= FILE_NOTIFY_CHANGE_SECURITY;

    return Result;
}

void __fastcall TCustomShellChangeNotifier::Change(void)
{
    if(FThread != NULL)
        FThread->SetDirectoryOptions(Root, FWatchSubTree, NotifyOptionFlags(FFilters));
}
//---------------------------------------------------------------------------

void __fastcall TCustomShellChangeNotifier::Start(void)
{
    if(FOnChange == NULL)
        return;
    FThread = new TShellChangeThread(FOnChange);
    FThread->SetDirectoryOptions(FRoot, FWatchSubTree, NotifyOptionFlags(FFilters));
    FThread->Resume();
}
//---------------------------------------------------------------------------

__fastcall TCustomShellChangeNotifier::TCustomShellChangeNotifier(Classes::TComponent* AOwner)
                                            : TComponent(AOwner)
{
    FRoot = "C:\\";      // Do not localize
    FWatchSubTree = true;
    FFilters << nfFileNameChange << nfDirNameChange;
    Start();
}
//---------------------------------------------------------------------------

__fastcall TCustomShellChangeNotifier::~TCustomShellChangeNotifier(void)
{
    if (FThread)
    {
        FThread->Terminate();
        ReleaseMutex(FThread->FMutex); // this current thread must release the mutex
        delete FThread;
    }
}
//---------------------------------------------------------------------------
// TShellChangeNotifier -----------------------------------------------------
__fastcall TShellChangeNotifier::TShellChangeNotifier(Classes::TComponent* AOwner)
                                            : TCustomShellChangeNotifier(AOwner)
{
}
//---------------------------------------------------------------------------

__fastcall TShellChangeNotifier::~TShellChangeNotifier(void)
{
}
//---------------------------------------------------------------------------

__fastcall TCustomShellListView::TCustomShellListView(Classes::TComponent* AOwner)
                                                    : TCustomListView(AOwner)
{
    TSHFileInfo FileInfo;

    FRootFolder = NULL;
    OwnerData = true;
    FSorted = true;
    FObjectTypes << otFolders;
    FObjectTypes << otNonFolders;
    FAutoContext = true;
    FAutoNavigate = true;
    FAutoRefresh = false;
    FFolders = new TList();
    FTreeView = NULL;
    FUpdating = false;
    FSettingRoot = false;
    FSmallImages = SHGetFileInfo("C:\\" /* Do not localize */, 0, &FileInfo, sizeof(FileInfo), SHGFI_SYSICONINDEX | SHGFI_SMALLICON);
    FLargeImages = SHGetFileInfo("C:\\" /* Do not localize */, 0, &FileInfo, sizeof(FileInfo), SHGFI_SYSICONINDEX | SHGFI_LARGEICON);
    FRoot = SRFDesktop;
    HideSelection = False;
}
//---------------------------------------------------------------------------

__fastcall TCustomShellListView::TCustomShellListView(HWND ParentWindow)
                                    : Comctrls::TCustomListView(ParentWindow)
{
    TSHFileInfo FileInfo;

    FRootFolder = NULL;
    OwnerData = true;
    FSorted = true;
    FObjectTypes << otFolders;
    FObjectTypes << otNonFolders;
    FAutoContext = true;
    FAutoNavigate = true;
    FAutoRefresh = false;
    FFolders = new TList();
    FTreeView = NULL;
    FUpdating = false;
    FSettingRoot = false;
    FSmallImages = SHGetFileInfo("C:\\" /* Do not localize */, 0,
        &FileInfo, sizeof(FileInfo), SHGFI_SYSICONINDEX | SHGFI_SMALLICON);
    FLargeImages = SHGetFileInfo("C:\\" /* Do not localize */, 0,
        &FileInfo, sizeof(FileInfo), SHGFI_SYSICONINDEX | SHGFI_LARGEICON);
    FRoot = SRFDesktop;
    HideSelection = False;
}
//---------------------------------------------------------------------------

__fastcall TCustomShellListView::~TCustomShellListView(void)
{
    if (FNotifier)
        delete FNotifier;
    if (FRootFolder)
        delete FRootFolder;
    delete FFolders;
}
//---------------------------------------------------------------------------
// TCustomShellListView -----------------------------------------------------

/*
The method I outlined previously works for me (just tested for Printers):

 - Start with the required IShellFolder interface
 - See if it supports IShellDetails
 - If not, use FShellFolder.CreateViewObject to get IShellDetails
 - If it is a normal file folder (SFGAO_FILESYSTEM) you know what to do
 - If not, call IShellDetails.GetDetailsOf on the virtual folder until
   it returns the same column name twice (gives you the column types,
   names, and count).  Use nil for the first parameter.
 - For each virtual file, call IShellDetails.GetDetailsOf the number of
   columns times passing in the PItemIDList this time to get details.

> Furthermore, I have not yet found a way to determine that a PIDL I
> happen to have is a virtual folder, or a specific virtual folder. Still
> looking for suggestions there as well.

  You can tell a normal folder using IShellFolder.GetAttributesOf and
checking for SFGAO_FILESYSTEM.  This returns false for printers, scheduled
tasks, etc.

*/
// --------------------------------------------------------------------------
// AddColumn helper
bool ColumnIsUnique(TStringList *ColNames, String Name)
{
    for(int i = 0; i < ColNames->Count; i++)
        if(ColNames->Strings[i] == Name)
          return false;

    return true;
}

// --------------------------------------------------------------------------

bool __fastcall TCustomShellListView::AddColumn(TStringList *ColNames, TShellDetails *SD)
{
    PItemIDList PIDL = NULL;
    String ColName = StrRetToString(PIDL, SD->str);
    bool Result = true;

    if(ColName != "")
    {
        Result = ColumnIsUnique(ColNames, ColName);
        if(Result)
        {
            TListColumn *Column = Columns->Add();
            Column->Caption = ColName;

            switch(SD->fmt)
            {
                case LVCFMT_CENTER:
                    Column->Alignment = taCenter;
                    break;
                case LVCFMT_LEFT:
                    Column->Alignment = taLeftJustify;
                    break;
                case LVCFMT_RIGHT:
                    Column->Alignment = taRightJustify;
                    break;
            }

            Column->Width = SD->cxChar * Canvas->TextWidth('X');
            ColNames->Add(ColName);
        }
    }

    return Result;
}

// --------------------------------------------------------------------------
void __fastcall TCustomShellListView::AddDefaultColumn(String ACaption, TAlignment AAlignment, int AWidth)
{
    TListColumn *Column = Columns->Add();
    Column->Caption = ACaption;
    Column->Alignment = AAlignment;
    Column->Width = AWidth * Canvas->TextWidth('X');
}

void __fastcall TCustomShellListView::AddDefaultColumns(int ColCount)
{
    ColCount--;

    if(ColCount < 1)
        return;

    switch(ColCount)
    {
        case 1:
            AddDefaultColumn(SShellDefaultNameStr, taLeftJustify, 25);
            break;

        case 2:
            AddDefaultColumn(SShellDefaultSizeStr, taRightJustify, 10);
            break;

        case 3:
              AddDefaultColumn(SShellDefaultTypeStr, taLeftJustify, 10);
            break;

        default:
            AddDefaultColumn(SShellDefaultModifiedStr, taLeftJustify, 14);
    }
}

// --------------------------------------------------------------------------

void __fastcall TCustomShellListView::EnumColumns(void)
{
    TStringList *ColNames;
    int Col;
    TShellDetails SD;
    PItemIDList PIDL;
    _di_IShellFolder2 SF2;
    Shlobj::_di_IShellDetails ISD;
    DWORD ColFlags;
    bool Default;

    if (FRootFolder == NULL || FRootFolder->ShellFolder == NULL)
        return;

    ColNames = new TStringList();
    try
    {
        Columns->BeginUpdate();

        try
        {
            Columns->Clear();
            Col = 0;
            PIDL = NULL;
            Default = false;
            memset(&SD, 0, sizeof(SD));

            FRootFolder->ViewHandle = this->Handle;
            SF2 = FRootFolder->ShellFolder2;
            if(SF2 != NULL)    // Have _di_IShellFolder2 interface
            {
                while(SF2->GetDetailsOf(PIDL, Col, &SD) == S_OK)
                {
                    SF2->GetDefaultColumnState(Col, &ColFlags);
                    Default = Default || bool(ColFlags & Shlobj::SHCOLSTATE_ONBYDEFAULT);
                    if(Default && !bool(ColFlags & Shlobj::SHCOLSTATE_ONBYDEFAULT))
                        return;

                    AddColumn(ColNames, &SD);
                    Col++;
                }
            }
            else
            {
                ISD = FRootFolder->ShellDetails;
                if(ISD != NULL)
                {
                  while (ISD->GetDetailsOf(NULL, Col, SD) == S_OK)
                  {
                    if(AddColumn(ColNames, &SD))
                      Col++;
                    else
                      break;
                  }
                }
                else
                {
                    if(FRootFolder->Properties().Contains(fpFileSystem))
                        AddDefaultColumns(4);
                    else
                        AddDefaultColumns(1);
                }
            }
        }
        __finally
        {
            Columns->EndUpdate();
        }
    }
    __finally
    {
        delete ColNames;
    }
}
//---------------------------------------------------------------------------

TShellFolder* __fastcall TCustomShellListView::GetFolder(int Index)
{
    return (TShellFolder *)(FFolders->Items[Index]);
}
//---------------------------------------------------------------------------

void __fastcall TCustomShellListView::SetAutoRefresh(bool Value)
{
    FAutoRefresh = Value;
    if(!ComponentState.Contains(csLoading))
    {
        if (FAutoRefresh)
        {
            if (FNotifier)
                delete FNotifier;

            FNotifier = new TShellChangeNotifier(this);
            FNotifier->ComponentStyle << csSubComponent;
            FNotifier->WatchSubTree = false;
            FNotifier->Root = FRootFolder->PathName();
            FNotifier->OnChange = this->Refresh;
        }
        else if(FNotifier != NULL)
        {
          delete FNotifier;
          FNotifier = NULL;
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TCustomShellListView::SetSorted(bool Value)
{
    if(FSorted != Value)
    {
        FSorted = Value;
        Populate();
    }
}
//---------------------------------------------------------------------------

void __fastcall TCustomShellListView::SetTreeView(TCustomShellTreeView* Value)
{
    if(Value == FTreeView)
        return;

    if(Value != NULL)
      {
        Value->Root = Root;
        Value->FListView = this;
      }
      else if(FTreeView != NULL)
          FTreeView->FListView = NULL;

    if(FTreeView != NULL)
        FTreeView->FreeNotification(this);

    FTreeView = Value;
}
//---------------------------------------------------------------------------

void __fastcall TCustomShellListView::SetComboBox(TCustomShellComboBox* Value)
{
    if(Value == FComboBox)
        return;

    if(Value != NULL)
    {
        Value->Root = Root;
        Value->FListView = this;
    }
    else if(FComboBox != NULL)
        FComboBox->FListView = NULL;

    if(FComboBox != NULL)
        FComboBox->FreeNotification(this);

    FComboBox = Value;
}
//---------------------------------------------------------------------------

void __fastcall TCustomShellListView::TreeUpdate(Shlobj::PItemIDList NewRoot)
{
    if(FUpdating || (FRootFolder != NULL && SamePIDL(FRootFolder->AbsoluteID, NewRoot)))
        return;

    SetPathFromID(NewRoot);
}
//---------------------------------------------------------------------------

void __fastcall TCustomShellListView::SetPathFromID(Shlobj::PItemIDList ID)
{
    if(FUpdating)
        return;

    if(FRootFolder != NULL)
    {
        if(SamePIDL(FRootFolder->AbsoluteID, ID))
            return;
        else
        {
            delete FRootFolder;
            FRootFolder = NULL;
        }
    }

    FSettingRoot = false;
    FRootFolder = CreateRootFromPIDL(ID); 
    RootChanged();
    TControl::Refresh();
}
//---------------------------------------------------------------------------

void __fastcall TCustomShellListView::SynchPaths(void)
{
    try
    {
        if(FSettingRoot)
        {
            if(FTreeView != NULL)
                FTreeView->SetRoot(FRoot);

            if(FComboBox != NULL)
                FComboBox->SetRoot(FRoot);
        }
        else
        {
            if(FTreeView != NULL)
                FTreeView->SetPathFromID(FRootFolder->AbsoluteID);

            if(FComboBox != NULL)
                FComboBox->TreeUpdate(FRootFolder->AbsoluteID);
        }
    }
    __finally
    {
        FSettingRoot = false;
    }
}
//---------------------------------------------------------------------------

void __fastcall TCustomShellListView::ClearItems(void)
{
    if(!ComponentState.Contains(csDestroying))
        Items->Clear();

      for(int i = 0; i < FFolders->Count; i++)
        if(Folders[i] != NULL)
              delete Folders[i];

    FFolders->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TCustomShellListView::CreateRoot(void)
{
    FRootFolder = CreateRootFolder(FRootFolder, FOldRoot, FRoot);
}
//---------------------------------------------------------------------------

void __fastcall TCustomShellListView::CreateWnd(void)
{
    Comctrls::TCustomListView::CreateWnd();
    if(HandleAllocated())
    {
        if(FSmallImages != 0)
            SendMessage(Handle, LVM_SETIMAGELIST, LVSIL_SMALL, FSmallImages);

        if(FLargeImages != 0)
            SendMessage(Handle, LVM_SETIMAGELIST, LVSIL_NORMAL, FLargeImages);
    }

    CreateRoot();
    RootChanged();
}
//---------------------------------------------------------------------------

void __fastcall TCustomShellListView::DblClick(void)
{

    if(FAutoNavigate && Selected != NULL)
    {
        TShellFolder *sflFolder = Folders[Selected->Index];
        if(sflFolder->IsFolder())
            SetPathFromID(sflFolder->AbsoluteID);
        else
        {
            // The delphi code does not have SW_SHOW as the last param (bug fix)
            ShellExecute(Handle, NULL, sflFolder->PathName().c_str(),
                NULL, ExtractFilePath(sflFolder->PathName()).c_str(), SW_SHOW);
        }
                
    }
    Comctrls::TCustomListView::DblClick();
}
//---------------------------------------------------------------------------

void __fastcall TCustomShellListView::DoContextPopup(const Types::TPoint &MousePos, bool &Handled)
{
    if(FAutoContext && (SelectedFolder() != NULL))
    {
        InvokeContextMenu(this, SelectedFolder(), MousePos.x, MousePos.y);
        Handled = True;
    }
    else
        Comctrls::TCustomListView::DoContextPopup(MousePos, Handled);
}
//---------------------------------------------------------------------------

void __fastcall TCustomShellListView::EditText(void)
{
    if(Selected != NULL)
        ListView_EditLabel(Handle, Selected->Index);
}
//---------------------------------------------------------------------------

void __fastcall TCustomShellListView::Edit(const tagLVITEMA &Item)
{
    String S;

    if(Item.iItem >= FFolders->Count)
        return;

    if(Item.pszText != NULL)
    {
        S = Item.pszText;
        TShellFolder *Folder = (TShellFolder *)FFolders->Items[Item.iItem];
        Folder->Rename(S);
    }
}
//---------------------------------------------------------------------------

void __fastcall TCustomShellListView::KeyDown(Word &Key, Classes::TShiftState Shift)
{
    Comctrls::TCustomListView::KeyDown(Key, Shift);
    if(FAutoNavigate)
        switch(Key)
        {
            case VK_RETURN:
                if(Shift.Contains(ssAlt))
                {
                      DoContextMenuVerb(SelectedFolder(), cmvProperties);
                      Key = 0;
                }
                else if (SelectedFolder() != NULL)
                    if(SelectedFolder()->IsFolder())
                      {
                        SetPathFromID(SelectedFolder()->AbsoluteID);
                      }
                    else
                        SelectedFolder()->ExecuteDefault();
                break;
            case VK_BACK:
                if(!IsEditing())
                    Back();

            case VK_F5:
                Refresh();
        }
}
//---------------------------------------------------------------------------

void __fastcall TCustomShellListView::Loaded(void)
{
    Comctrls::TCustomListView::Loaded();
    Populate();

    if(ComponentState.Contains(csLoading))
        Comctrls::TCustomListView::Loaded();

    SetAutoRefresh(FAutoRefresh);
}
//---------------------------------------------------------------------------

void __fastcall TCustomShellListView::Notification(Classes::TComponent* AComponent, Classes::TOperation Operation)
{
    Comctrls::TCustomListView::Notification(AComponent, Operation);

    if(Operation == opRemove)
    {
        if(AComponent == FTreeView)
            FTreeView = NULL;
        else if(AComponent == FComboBox)
            FComboBox = NULL;
    }
}
//---------------------------------------------------------------------------

bool __fastcall TCustomShellListView::OwnerDataFetch(Comctrls::TListItem* Item, Comctrls::TItemRequest Request)
{
    if (FUpdating) return true;


    TShellFolder *AFolder = Folders[Item->Index];

    if(AFolder == NULL)
        return true;

    if((Item->Index > FFolders->Count-1) || (Item->Index < 0))
        return true;

    if(Request.Contains(irText) || Item->Caption == "")
        Item->Caption = AFolder->DisplayName();

    if(Request.Contains(irImage))
        Item->ImageIndex = AFolder->ImageIndex(ViewStyle == vsIcon);

    if(ViewStyle != vsReport)
        return true;

    AFolder->LoadColumnDetails(FRootFolder, this->Handle, Columns->Count);
    
    for(int j = 1; j <  Columns->Count; j++) // start at 1, not 0
        Item->SubItems->Add(AFolder->Details[j]);

    return true;
}
//---------------------------------------------------------------------------

int __fastcall TCustomShellListView::OwnerDataFind(Comctrls::TItemFind Find, const AnsiString FindString, const Types::TPoint &FindPosition, void * FindData, int StartIndex, Comctrls::TSearchDirection Direction, bool Wrap)
{
    bool Found = false;
    int Result = -1;
    int i = StartIndex;

    //OnDataFind gets called in response to calls to FindCaption, FindData,
    //GetNearestItem, etc. It also gets called for each keystroke sent to the
    //ListView (for incremental searching)

    if((Find == ifExactString) || (Find == ifPartialString))
    {
        do
        {
            if(i == FFolders->Count-1)
                if(Wrap)
                    i = 0;
                else
                    return Result;
            String Upper = Folders[i]->DisplayName().UpperCase();
            Found = Upper.Pos(FindString.UpperCase());
            i++;
        } while (Found || i == StartIndex);

        if(Found)
            Result = i-1;
    }

    return Result;
}
//---------------------------------------------------------------------------

void __fastcall TCustomShellListView::Populate(void)
{
    PItemIDList ID;
    IEnumIDList *EnumList;
    DWORD NumIDs;
    TCursor SaveCursor;
    bool CanAdd;
    TShellFolder *AFolder;

    if(ComponentState.Contains(csLoading) && !HandleAllocated())
        return;

    Items->BeginUpdate();

    try
    {
        ClearItems();
        SaveCursor = Screen->Cursor;
        Screen->Cursor = crHourGlass;
        try
        {
            HRESULT HR = FRootFolder->ShellFolder->EnumObjects(Application->Handle,
                ObjectFlags(FObjectTypes), &EnumList);

            if(HR != 0)
                return;

            int nCount = 0;
            while(EnumList->Next(1, &ID, &NumIDs) == S_OK)
            {
                _di_IShellFolder ishlFolder = GetIShellFolder(FRootFolder->ShellFolder, ID);
                AFolder = new TShellFolder(FRootFolder, ID, ishlFolder);

                CanAdd = true;
                if (FOnAddFolder)
                    FOnAddFolder(this, AFolder, CanAdd);

                if (CanAdd)
                {
                    FFolders->Add(AFolder);
                    nCount++;
                }
                else
                  delete AFolder;
            }
            Items->Count = nCount;
            if (FSorted)
            {
                CompareFolder = FRootFolder;
                try
                {
                    FFolders->Sort(ListSortFunc);
                }
                __finally
                {
                    CompareFolder = NULL;
                }
            }
        }
        __finally
        {
            Screen->Cursor = SaveCursor;
        }
    }
    __finally
    {
        Items->EndUpdate();
    }
}
//---------------------------------------------------------------------------

void __fastcall TCustomShellListView::RootChanged(void)
{
    bool StayFresh;

    if(FUpdating)
        return;

    FUpdating = true;
    try
    {
        StayFresh = FAutoRefresh;
        AutoRefresh = false;
        SynchPaths();
        Populate();
        if(ViewStyle == vsReport)
            EnumColumns();
        AutoRefresh = StayFresh;
    }
    __finally
    {
        FUpdating = false;
    }
}
//---------------------------------------------------------------------------

void __fastcall TCustomShellListView::SetObjectTypes(TShellObjectTypes Value)
{
    FObjectTypes = Value;
    if(!ComponentState.Contains(csLoading))
        RootChanged();
}
//---------------------------------------------------------------------------

void __fastcall TCustomShellListView::SetRoot(const AnsiString Value)
{
    if(Value != FRoot)
    {
        FOldRoot = FRoot;
        FRoot = Value;
        CreateRoot();
        FSettingRoot = true;
        RootChanged();
    }
}
//---------------------------------------------------------------------------

void __fastcall TCustomShellListView::SetViewStyle(Comctrls::TViewStyle Value)
{
    Comctrls::TCustomListView::SetViewStyle(Value);

    if(Value == vsReport && !ComponentState.Contains(csLoading))
        EnumColumns();
}
//---------------------------------------------------------------------------


void __fastcall TCustomShellListView::WndProc(Messages::TMessage &Message)
{
    if(((Message.Msg == WM_INITMENUPOPUP) || (Message.Msg == WM_DRAWITEM) || (Message.Msg == WM_MENUCHAR)
        || (Message.Msg == WM_MEASUREITEM)) && ICM2 != NULL)
    {
        ICM2->HandleMenuMsg(Message.Msg, Message.WParam, Message.LParam);
          Message.Result = 0;
    }
    else if (Message.Msg == WM_DESTROY)
        ClearItems(); // make sure the items are freed (insures no memory leaks

    Comctrls::TCustomListView::WndProc(Message);
}
//---------------------------------------------------------------------------

void __fastcall TCustomShellListView::Back(void)
{
    PItemIDList RootPIDL = CopyPIDL(FRootFolder->AbsoluteID);

    try
    {
        StripLastID(RootPIDL);
        SetPathFromID(RootPIDL);
    }
    __finally
    {
        DisposePIDL(RootPIDL);
    }
}
//---------------------------------------------------------------------------

void __fastcall TCustomShellListView::Refresh(void)
{
    int SelectedIndex = -1;
    PItemIDList RootPIDL;

    if(Selected != NULL)
        SelectedIndex = Selected->Index;

    Selected = NULL;
    RootPIDL = CopyPIDL(FRootFolder->AbsoluteID);
    try
    {
        delete FRootFolder;
        FRootFolder = NULL;
        SetPathFromID(RootPIDL);
      }
      __finally
    {
        DisposePIDL(RootPIDL);
    }
    if((SelectedIndex > -1) && (SelectedIndex < Items->Count - 1))
        Selected = Items->Item[SelectedIndex];
}
//---------------------------------------------------------------------------

TShellFolder* __fastcall TCustomShellListView::SelectedFolder(void)
{
    if(Selected != NULL)
        return Folders[Selected->Index];

    return NULL;
}
// TCustomShellComboBox -----------------------------------------------------

void __fastcall TCustomShellComboBox::WndProc(Messages::TMessage &Message)
{
    if (Message.Msg == WM_DESTROY)
        ClearItems();
    Comctrls::TCustomComboBoxEx::WndProc(Message);
}

__fastcall TCustomShellComboBox::TCustomShellComboBox(Classes::TComponent* AOwner)
                                    : Comctrls::TCustomComboBoxEx(AOwner)
{
    TSHFileInfo FileInfo;

    FRootFolder = NULL;
    FImages = SHGetFileInfo("C:\\", 0, &FileInfo, sizeof(FileInfo), SHGFI_SYSICONINDEX | SHGFI_SMALLICON);   // Do not localize
    ImageList_GetIconSize((HIMAGELIST)&FImages, &FImageWidth, &FImageHeight);
    FUpdating = false;
    Style << csExDropDown;
    FObjectTypes << otFolders;
    FRoot = SRFDesktop;
    FUseShellImages = true;
}
//---------------------------------------------------------------------------

__fastcall TCustomShellComboBox::TCustomShellComboBox(HWND ParentWindow)
                                    : Comctrls::TCustomComboBoxEx(ParentWindow)
{
    TSHFileInfo FileInfo;

    FRootFolder = NULL;
    FImages = SHGetFileInfo("C:\\", 0, &FileInfo, sizeof(FileInfo), SHGFI_SYSICONINDEX | SHGFI_SMALLICON);   // Do not localize
    ImageList_GetIconSize((HIMAGELIST)&FImages, &FImageWidth, &FImageHeight);
    FUpdating = false;
    Style << csExDropDown;
    FObjectTypes << otFolders;
    FRoot = SRFDesktop;
    FUseShellImages = true;
}
//---------------------------------------------------------------------------

__fastcall TCustomShellComboBox::~TCustomShellComboBox(void)
{
    if(FImageList != NULL)
        delete FImageList;
    if (FRootFolder)
        delete FRootFolder;
}
//---------------------------------------------------------------------------

void __fastcall TCustomShellComboBox::ClearItems(void)
{
    ItemsEx->BeginUpdate();
    try
    {
        for(int i = 0; i < ItemsEx->Count; i++)
        {
              if(Folders[i] != NULL)
                delete Folders[i];
                
              ItemsEx->Items[i]->Data = NULL;
        }
        ItemsEx->Clear();
    }
    __finally
    {
        ItemsEx->EndUpdate();
    }
}
//---------------------------------------------------------------------------

TShellFolder* __fastcall TCustomShellComboBox::GetFolder(int Index)
{
    if(Index > ItemsEx->Count - 1)
        Index = ItemsEx->Count - 1;

      return (TShellFolder *)ItemsEx->Items[Index]->Data;
}
//---------------------------------------------------------------------------

AnsiString __fastcall TCustomShellComboBox::GetPath()
{
    String Result = "";
    TShellFolder *Folder = NULL;

    if(ItemIndex > -1)
    {
        Folder = Folders[ItemIndex];
        if(Folder != NULL)
            Result = Folder->PathName();
    }

    return Result;
}
//---------------------------------------------------------------------------

void __fastcall TCustomShellComboBox::SetPath(const AnsiString Value)
{
    PWCHAR P;
    PItemIDList NewPIDL;
    DWORD Flags;
    DWORD NumChars;

    NumChars = Value.Length();
    Flags = 0;
    P = StringToOleStr(Value);
    try
    {
        OleCheck(DesktopShellFolder()->ParseDisplayName(0, NULL, P, &NumChars, &NewPIDL, &Flags));
        SetPathFromID(NewPIDL);
    }
    catch(EOleSysError &Error)
    {
        TVarRec Records[] = { Value };

        throw( EInvalidPath(Consts_SErrorSettingPath, Records, 1) );
    }
}
//---------------------------------------------------------------------------

// TCustomShellComboBox::SetPathFromID -* helper *-
void __fastcall TCustomShellComboBox::InsertItemObject(int Position, String Text, TShellFolder *AFolder)
{
    TComboExItem *Item = ItemsEx->Insert(Position);
    Item->Caption = Text;
    Item->Indent = AFolder->Level;
    Item->Data = AFolder;
    if(AFolder == NULL)
        Item->Data = AFolder;
    Item->ImageIndex = GetShellImageIndex(AFolder);
}

void __fastcall TCustomShellComboBox::SetPathFromID(Shlobj::PItemIDList ID)
{
    TList *Pidls;
    int i, Item, Temp;
    TShellFolder *AFolder;
    PItemIDList RelID;

    Item = -1;
    ItemsEx->BeginUpdate();

    try
    {
        CreateRoot();
        Pidls = CreatePIDLList(ID);
        try
        {
            i = Pidls->Count-1;
            while(i >= 0)
            {
                Item = IndexFromID((PItemIDList)Pidls->Items[i]);
                if(Item != -1)
                    break;
                i--;
            }

            if(i < 0)
                return;

            while(i < Pidls->Count-1)
            {
              i++;
              RelID = RelativeFromAbsolute((PItemIDList)Pidls->Items[i]);
              AFolder = InitItem(Folders[Item], RelID);
              InsertItemObject(Item+1, AFolder->DisplayName(), AFolder);
              Item++;
            }

            Temp = IndexFromID(ID);
            if(Temp < 0)
            {
              RelID = RelativeFromAbsolute(ID);
              AFolder = InitItem(Folders[Item], RelID);
              Temp = Item + 1;
              InsertItemObject(Item+1, AFolder->DisplayName(), AFolder);
            }
            ItemIndex = Temp;
        }
        __finally
        {
            DestroyPIDLList(Pidls);
        }
    }
    __finally
    {
        ItemsEx->EndUpdate();
    }
}
//---------------------------------------------------------------------------

void __fastcall TCustomShellComboBox::SetRoot(const AnsiString Value)
{
    if(FRoot != Value)
    {
        FOldRoot = FRoot;
        FRoot = Value;
        RootChanged();
    }
}
//---------------------------------------------------------------------------

void __fastcall TCustomShellComboBox::SetTreeView(TCustomShellTreeView* Value)
{
    if(Value == FTreeView)
        return;

    if(Value != NULL)
    {
        Value->Root = Root;
        Value->FComboBox = this;
    }
    else if(FTreeView != NULL)
        FTreeView->FComboBox = NULL;

    if(FTreeView != NULL)
        FTreeView->FreeNotification(this);

    FTreeView = Value;
}
//---------------------------------------------------------------------------

void __fastcall TCustomShellComboBox::SetListView(TCustomShellListView* Value)
{
    if(Value == FListView)
        return;

    if(Value != NULL)
    {
        Value->Root = Root;
        Value->FComboBox = this;
    }
    else if(FListView != NULL)
        FListView->FComboBox = NULL;

    if(FListView != NULL)
        FListView->FreeNotification(this);

    FListView = Value;
}
//---------------------------------------------------------------------------

void __fastcall TCustomShellComboBox::SetUseShellImages(bool Value)
{
    THandle ImageListHandle;

    FUseShellImages = Value;
    if(Images == NULL)
    {
        if(FUseShellImages)
            ImageListHandle = FImages;
        else
            ImageListHandle = NULL;
    }
    else
        ImageListHandle = Images->Handle;

    SendMessage(Handle, CBEM_SETIMAGELIST, 0, ImageListHandle);

    if(FUseShellImages && FImageList == NULL)
        ImageList_GetIconSize((HIMAGELIST)&FImages, &FImageWidth, &FImageHeight);
    else
        if(FImageList == NULL)
        {
            FImageWidth = 16;
            FImageHeight = 16;
        }
        else
        {
            FImageWidth = FImageList->Width;
            FImageHeight = FImageList->Height;
        }
}
//---------------------------------------------------------------------------

int __fastcall TCustomShellComboBox::GetShellImageIndex(TShellFolder* AFolder)
{
    int Result = -1;

    if(FUseShellImages)
        Result = GetShellImage(AFolder->AbsoluteID, false, false);

    return Result;
}
//---------------------------------------------------------------------------

void __fastcall TCustomShellComboBox::AddItems(int Index, TShellFolder* ParentFolder)
{
    IEnumIDList *EnumList;
    PItemIDList ID;
	int ImageIndex;
    TComboExItem *Item;
    int NumIDs;
    TList *List;
    String ItemText;

    OleCheck(ParentFolder->ShellFolder->EnumObjects(0, ObjectFlags(FObjectTypes), &EnumList));
    CompareFolder = ParentFolder;
    List = NULL;
    ItemsEx->BeginUpdate();
    try
    {
        List = new TList();
        while(EnumList->Next(1, &ID, (PDWORD)&NumIDs) == S_OK)
            List->Add(ID);

        List->Sort(ComboSortFunc);

        for(NumIDs = 0; NumIDs < List->Count; NumIDs++)
        {
            TShellFolder *AFolder = InitItem(ParentFolder, (PItemIDList)List->Items[NumIDs]);
            ItemText = AFolder->DisplayName();
            Item = ItemsEx->Insert(NumIDs+1);
            Item->Caption = ItemText;
            Item->Data = AFolder;
            // AFolder is never freed = mem leak
            

            Item->Indent = AFolder->Level;
            Item->ImageIndex = GetShellImageIndex(AFolder);
            Item->SelectedImageIndex = Item->ImageIndex;

            if(FOnGetImageIndex != NULL && ((FImageList != NULL) || FUseShellImages))
            {
                ImageIndex = ItemsEx->ComboItems[NumIDs]->ImageIndex;
                FOnGetImageIndex(this, NumIDs, ImageIndex);
                ItemsEx->ComboItems[NumIDs]->ImageIndex = ImageIndex;
            }
        }
    }
    __finally
    {
        CompareFolder = NULL;
        delete List;
        ItemsEx->EndUpdate();
    }
}
//---------------------------------------------------------------------------
class TAccessItemUpdateCount: public TComboExItems
{
    public:
        inline int UpdateCount(void) { return TComboExItems::UpdateCount; }
};

void __fastcall TCustomShellComboBox::Change(void)
{
    TShellFolder *Node;

    if( ((TAccessItemUpdateCount *)ItemsEx)->UpdateCount() > 0 )
        return;


    Comctrls::TCustomComboBoxEx::Change();
    if(ItemIndex > -1 && !FUpdating && !DroppedDown)
    {
        FUpdating = true;
        try
        {
            Node = Folders[ItemIndex];

            if(Node != NULL)
            {
                if(FTreeView != NULL)
                      FTreeView->SetPathFromID(Node->AbsoluteID);
                if(FListView != NULL)
                      FListView->TreeUpdate(Node->AbsoluteID);
            }
        }
        __finally
        {
            FUpdating = false;
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TCustomShellComboBox::Click(void)
{
    PItemIDList Temp;

    FUpdating = true;
    try
    {
        Temp = CopyPIDL(Folders[ItemIndex]->AbsoluteID);
        //Folder will be destroyed when removing the lower level ShellFolders.
        try
        {
            SetPathFromID(Temp);
            Comctrls::TCustomComboBoxEx::Click();
        }
        __finally
        {
            DisposePIDL(Temp);
        }
    }
    __finally
    {
        FUpdating = false;
    }
}
//---------------------------------------------------------------------------

void __fastcall TCustomShellComboBox::CreateRoot(void)
{
    TShellFolder *AFolder;
    String Text;
    int ImageIndex;

    if(ComponentState.Contains(csLoading))
        return;

    ItemsEx->BeginUpdate();

    try
    {
        ClearItems();
        FRootFolder = CreateRootFolder(FRootFolder, FOldRoot, FRoot);
        AFolder = new TShellFolder(NULL, FRootFolder->AbsoluteID, FRootFolder->ShellFolder);
        Text = AFolder->DisplayName(); //! PathName;

        ImageIndex = GetShellImageIndex(AFolder);
        ItemsEx->AddItem(Text, ImageIndex, ImageIndex, -1, 0, AFolder);
        Init();
        ItemIndex = 0;
        if(FUseShellImages)        // Force image update
        {
            SetUseShellImages(False);
            SetUseShellImages(True);
        }
    }
    __finally
    {
        ItemsEx->EndUpdate();
    }
}
//---------------------------------------------------------------------------

void __fastcall TCustomShellComboBox::CreateWnd(void)
{
    Comctrls::TCustomComboBoxEx::CreateWnd();

    if(FImages != NULL)
        SendMessage(Handle, CBEM_SETIMAGELIST, 0, FImages);

    SetUseShellImages(FUseShellImages);
    if(ItemsEx->Count == 0)
        CreateRoot();
}
//---------------------------------------------------------------------------

int __fastcall TCustomShellComboBox::IndexFromID(Shlobj::PItemIDList AbsoluteID)
{
    int Result = ItemsEx->Count-1;
    while(Result >= 0)
    {
        if(DesktopShellFolder()->CompareIDs(0, AbsoluteID, Folders[Result]->AbsoluteID) == 0)
            return Result;
        Result--;
    }

    return Result;
}
//---------------------------------------------------------------------------

void __fastcall TCustomShellComboBox::Init(void)
{
    PItemIDList MyComputer;
    int Index;

    //show desktop contents, expand My Computer if at desktop.
    //!!!otherwise expand the root.
    ItemsEx->BeginUpdate();
    try
    {
        AddItems(0, FRootFolder);

        if(Root == SRFDesktop)
        {
            SHGetSpecialFolderLocation(0, CSIDL_DRIVES, &MyComputer);
            Index = IndexFromID(MyComputer);
            if(Index != -1)
                AddItems(Index, Folders[Index]);
        }
    }
    __finally
    {
        ItemsEx->EndUpdate();
    }
}
//---------------------------------------------------------------------------

TShellFolder* __fastcall TCustomShellComboBox::InitItem(TShellFolder* ParentFolder, Shlobj::PItemIDList ID)
{
    _di_IShellFolder SF = GetIShellFolder(ParentFolder->ShellFolder, ID);
    return new TShellFolder(ParentFolder, ID, SF);
}
//---------------------------------------------------------------------------

void __fastcall TCustomShellComboBox::Loaded(void)
{
    Comctrls::TCustomComboBoxEx::Loaded();
    CreateRoot();
}
//---------------------------------------------------------------------------

void __fastcall TCustomShellComboBox::Notification(Classes::TComponent* AComponent, Classes::TOperation Operation)
{
    Comctrls::TCustomComboBoxEx::Notification(AComponent, Operation);

    if(Operation == opRemove)
    {
        if(AComponent == FTreeView)
            FTreeView = NULL;
        else if(AComponent == FListView)
            FListView = NULL;
        else if(AComponent == FImageList)
            FImageList = NULL;
    }
}
//---------------------------------------------------------------------------

void __fastcall TCustomShellComboBox::RootChanged(void)
{
    FUpdating = true;
    try
    {
        ClearItems();
        CreateRoot();
        if(FTreeView != NULL)
            FTreeView->SetRoot(FRoot);
        if(FListView != NULL)
            FListView->SetRoot(FRoot);
    }
    __finally
    {
        FUpdating = false;
    }
}
//---------------------------------------------------------------------------

void __fastcall TCustomShellComboBox::TreeUpdate(Shlobj::PItemIDList NewPath)
{
    if(FUpdating || (ItemIndex > -1 && SamePIDL(Folders[ItemIndex]->AbsoluteID, NewPath)))
        return;

    FUpdating = true;
    try
    {
        SetPathFromID(NewPath);
    }
    __finally
    {
        FUpdating = false;
    }
}
//---------------------------------------------------------------------------

void __fastcall TCustomShellComboBox::SetObjectTypes(TShellObjectTypes Value)
{
    FObjectTypes = Value;
    RootChanged();
}
//---------------------------------------------------------------------------
// TCustomShellTreeView -----------------------------------------------------

__fastcall TCustomShellTreeView::TCustomShellTreeView(Classes::TComponent* AOwner)
                                    : Comctrls::TCustomTreeView(AOwner)
{
    TSHFileInfo FileInfo;

    FRootFolder = NULL;
    ShowRoot = false;
    FObjectTypes << otFolders;
    RightClickSelect = true;
    FAutoContext = true;
    OnDeletion = NodeDeleted;
    FUpdating = false;
    FComboBox = NULL;
    FListView = NULL;
    FImageListChanging = false;
    FUseShellImages = true;
    FImages = SHGetFileInfo("C:\\", 0, &FileInfo, sizeof(FileInfo), SHGFI_SYSICONINDEX | SHGFI_SMALLICON);   // Do not localize
    FNotifier = new TShellChangeNotifier(this);
    FNotifier->ComponentStyle << csSubComponent;
    FRoot = SRFDesktop;
    FLoadingRoot = false;
}
//---------------------------------------------------------------------------

__fastcall TCustomShellTreeView::TCustomShellTreeView(HWND ParentWindow)
                                    : Comctrls::TCustomTreeView(ParentWindow)
{
    TSHFileInfo FileInfo;

    FRootFolder = NULL;
    ShowRoot = false;
    FObjectTypes << otFolders;
    RightClickSelect = true;
    FAutoContext = true;
    OnDeletion = NodeDeleted;
    FUpdating = false;
    FComboBox = NULL;
    FListView = NULL;
    FImageListChanging = false;
    FUseShellImages = true;
    FImages = SHGetFileInfo("C:\\", 0, &FileInfo, sizeof(FileInfo), SHGFI_SYSICONINDEX | SHGFI_SMALLICON);   // Do not localize
    FNotifier = new TShellChangeNotifier(this);
    FNotifier->ComponentStyle << csSubComponent;
    FRoot = SRFDesktop;
    FLoadingRoot = false;
}
//---------------------------------------------------------------------------

__fastcall TCustomShellTreeView::~TCustomShellTreeView(void)
{
    if (FNotifier)
        delete FNotifier;
    if (FRootFolder)
        delete FRootFolder;
}
//---------------------------------------------------------------------------

Comctrls::TTreeNode* __fastcall TCustomShellTreeView::FolderExists(Shlobj::PItemIDList FindID, Comctrls::TTreeNode* InNode)
{
    int ALevel;

    ALevel = InNode->Level;
    do
    {
          if(DesktopShellFolder()->CompareIDs(0, FindID, ((TShellFolder *)InNode->Data)->AbsoluteID) == 0)
            return InNode;

        InNode = InNode->GetNext();
    }
    while(InNode != NULL && InNode->Level > ALevel);

    return NULL;
}
//---------------------------------------------------------------------------

TShellFolder * __fastcall TCustomShellTreeView::GetFolder(int Index)
{
    return (TShellFolder *)Items->Item[Index]->Data;
}
//---------------------------------------------------------------------------

AnsiString __fastcall TCustomShellTreeView::GetPath()
{
    if(SelectedFolder() != NULL)
        return SelectedFolder()->PathName();

    return "";
}
//---------------------------------------------------------------------------

void __fastcall TCustomShellTreeView::SetComboBox(TCustomShellComboBox* Value)
{
    if(Value == FComboBox)
        return;

    if(Value != NULL)
    {
        Value->Root = Root;
        Value->FTreeView = this;
    }
    else
        if(FComboBox != NULL)
            FComboBox->FTreeView = NULL;

    if(FComboBox != NULL)
        FComboBox->FreeNotification(this);
    FComboBox = Value;
}
//---------------------------------------------------------------------------

void __fastcall TCustomShellTreeView::SetListView(TCustomShellListView* Value)
{
    if(Value == FListView)
        return;

    if(Value != NULL)
    {
        Value->Root = Root;
        Value->FTreeView = this;
    }
    else
        if(FListView != NULL)
            FListView->FTreeView = NULL;

    if(FListView != NULL)
        FListView->FreeNotification(this);
    FListView = Value;
}
//---------------------------------------------------------------------------

void __fastcall TCustomShellTreeView::SetPath(AnsiString Value)
{
    PWCHAR P;
    PItemIDList NewPIDL;
    DWORD Flags, NumChars;

    NumChars = Value.Length();
    Flags = 0;
    P = StringToOleStr(Value);
    try
    {
        OleCheck(DesktopShellFolder()->ParseDisplayName(0, NULL, P, &NumChars, &NewPIDL, &Flags));
        SetPathFromID(NewPIDL);
    }
    catch(EOleSysError &Error)
    {
        TVarRec Records[] = { Value };

        throw( EInvalidPath(Consts_SErrorSettingPath, Records, 1) );
    }

    FUpdating = false;
}
//---------------------------------------------------------------------------

void __fastcall TCustomShellTreeView::SetPathFromID(Shlobj::PItemIDList ID)
{
    TList *Pidls = NULL;
      TTreeNode *Temp, *Node;

    if(FUpdating || ComponentState.Contains(csLoading)  || ((SelectedFolder() != NULL) && SamePIDL(SelectedFolder()->AbsoluteID, ID)))
        return;

    FUpdating = true;
    Items->BeginUpdate();
    try
    {
        Pidls = CreatePIDLList(ID);
        try
        {
            Node = Items->Item[0];
            for(int i = 0; i < Pidls->Count; i++)
            {
                Temp = FolderExists((PItemIDList)Pidls->Items[i], Node);
                if(Temp != NULL)
                {
                    Node = Temp;
                    Node->Expand(false);
                }
            }
            Node = FolderExists(ID, Node);
            Selected = Node;
            if(Node != NULL)
            {
                if(FListView != NULL)
                    FListView->TreeUpdate(((TShellFolder *)Node->Data)->AbsoluteID);
                if(FComboBox != NULL)
                    FComboBox->TreeUpdate(((TShellFolder *)Node->Data)->AbsoluteID);
            }
        }
        __finally
        {
            DestroyPIDLList(Pidls);
        }
    }
    __finally
    {
        Items->EndUpdate();
        FUpdating = false;
    }
}
//---------------------------------------------------------------------------

void __fastcall TCustomShellTreeView::SetRoot(const AnsiString Value)
{
    if(FRoot != Value)
    {
        FOldRoot = FRoot;
        FRoot = Value;
        RootChanged();
    }
}
//---------------------------------------------------------------------------

void __fastcall TCustomShellTreeView::SetUseShellImages(const bool Value)
{
    THandle ImageListHandle;


    FUseShellImages = Value;
    if(Images == NULL)
        if(FUseShellImages)
            ImageListHandle = FImages;
        else
              ImageListHandle = 0;
    else
        ImageListHandle = Images->Handle;

    SendMessage(Handle, TVM_SETIMAGELIST, TVSIL_NORMAL, ImageListHandle);
}
//---------------------------------------------------------------------------

void __fastcall TCustomShellTreeView::SetAutoRefresh(const bool Value)
{
    FAutoRefresh = Value;
    if (!ComponentState.Contains(csLoading))
    {
        if (FAutoRefresh)
        {
            if (FNotifier)
            {
                delete FNotifier;
                FNotifier = NULL;
            }

            FNotifier = new TShellChangeNotifier(this);
            FNotifier->ComponentStyle << csSubComponent;
            FNotifier->WatchSubTree = false;
            if(FNodeToMonitor != NULL)
                FNotifier->Root = ((TShellFolder *)FNodeToMonitor->Data)->PathName();
            else
                FNotifier->Root = FRootFolder->PathName();

            FNotifier->OnChange = this->RefreshEvent;
        }
        else if (FNotifier)
        {
            delete FNotifier;
            FNotifier = NULL;
        }
    }
}
//---------------------------------------------------------------------------

bool __fastcall TCustomShellTreeView::CanChange(Comctrls::TTreeNode* Node)
{
    TShellFolder *Fldr;
    bool StayFresh;

    bool Result = Comctrls::TCustomTreeView::CanChange(Node);
    if(Result && !FUpdating && Node != NULL)
    {
        Fldr = (TShellFolder *)(Node->Data);
        StayFresh = FAutoRefresh;
        AutoRefresh = False;
        if(!Fldr->IsFolder())
            Fldr = Fldr->Parent;

        FUpdating = true;
        try
        {
            if(FComboBox != NULL)
                FComboBox->TreeUpdate(Fldr->AbsoluteID);
            if(FListView != NULL)
                FListView->TreeUpdate(Fldr->AbsoluteID);
        }
        __finally
        {
            FUpdating = false;
        }

        FNodeToMonitor = Node;

        try
        {
            AutoRefresh = StayFresh;
        }
        __finally
        {
            FNodeToMonitor = NULL;
        }
    }

    return Result;
}
//---------------------------------------------------------------------------

bool __fastcall TCustomShellTreeView::CanExpand(Comctrls::TTreeNode* Node)
{
    TShellFolder *Fldr;

    bool Result = true;
    Fldr = (TShellFolder *)Node->Data;

    if(ComponentState.Contains(csDesigning) && (Node->Level > 0))
        return Result;

    if(OnExpanding != NULL)
        OnExpanding(this, Node, Result);

    if(Result)
        if(Fldr->IsFolder() && Node->HasChildren && Node->Count == 0)
            PopulateNode(Node);
        else if(Fldr->IsFolder())
        {
            ShellExecute(Handle, NULL, Fldr->PathName().c_str(), NULL, ExtractFilePath(Fldr->PathName()).c_str(), 0);
        }

    Node->HasChildren == Node->Count > 0;

    return Result;
}
//---------------------------------------------------------------------------

void __fastcall TCustomShellTreeView::CreateRoot(void)
{
    TTreeNode *RootNode;
    String ErrorMsg;

    if(ComponentState.Contains(csLoading))
        return;

    try
    {
        FRootFolder = CreateRootFolder(FRootFolder, FOldRoot, FRoot);
        ErrorMsg = "";
    }
    catch(Exception &E)
    {
        ErrorMsg = E.Message;
    }

    if(FRootFolder != NULL)
    {
        FLoadingRoot = true;
        try
        {
            if(Items->Count > 0)
              ClearItems();

            RootNode = Items->Add(NULL, "");
            RootNode->Data = new TShellFolder(NULL, FRootFolder->AbsoluteID, FRootFolder->ShellFolder);
            RootNode->Text = GetDisplayName(DesktopShellFolder(), ((TShellFolder *)RootNode->Data)->AbsoluteID, SHGDN_NORMAL);

            if(FUseShellImages && Images == NULL)
            {
                RootNode->ImageIndex = GetShellImage(((TShellFolder *)RootNode->Data)->AbsoluteID, false, false);
                RootNode->SelectedIndex = GetShellImage(((TShellFolder *)RootNode->Data)->AbsoluteID, false, true);
            }

            RootNode->HasChildren = ((TShellFolder *)RootNode->Data)->SubFolders();

            RootNode->Expand(False);
            Selected = RootNode;
        }
        __finally
        {
            FLoadingRoot = false;
        }
    }

    if(ErrorMsg.Length())
        throw Exception( ErrorMsg );
}
//---------------------------------------------------------------------------

void __fastcall TCustomShellTreeView::CreateWnd(void)
{
    Comctrls::TCustomTreeView::CreateWnd();

    if(Items->Count > 0)
        ClearItems();

    if(Images == NULL)
        SetUseShellImages(FUseShellImages);

    if(!FLoadingRoot)
        CreateRoot();
}
//---------------------------------------------------------------------------


void __fastcall TCustomShellTreeView::DoContextPopup(const Types::TPoint &MousePos, bool &Handled)
{
    if(AutoContextMenus && !(PopupMenu != NULL && PopupMenu->AutoPopup))
        InvokeContextMenu(this, SelectedFolder(), MousePos.x, MousePos.y);
    else
        Comctrls::TCustomTreeView::DoContextPopup(MousePos, Handled);
}
//---------------------------------------------------------------------------

void __fastcall TCustomShellTreeView::Edit(const tagTVITEMA &Item)
{
    String S;
    TTreeNode *Node;

    if(Item.pszText != NULL)
    {
        S = Item.pszText;
        Node = Items->GetNode(Item.hItem);
        if(OnEdited != NULL)
            OnEdited(this, Node, S);

        if(Node != NULL && ((TShellFolder *)Node->Data)->Rename(S))
            Node->Text = S;
    }
}
//---------------------------------------------------------------------------

void __fastcall TCustomShellTreeView::GetImageIndex(Comctrls::TTreeNode* Node)
{
    if(Images != NULL)
        Comctrls::TCustomTreeView::GetImageIndex(Node);
}
//---------------------------------------------------------------------------

void __fastcall TCustomShellTreeView::GetSelectedIndex(Comctrls::TTreeNode* Node)
{
    if(Images != NULL)
        Comctrls::TCustomTreeView::GetSelectedIndex(Node);
}
//---------------------------------------------------------------------------

void __fastcall TCustomShellTreeView::InitNode(Comctrls::TTreeNode* NewNode, Shlobj::PItemIDList ID, Comctrls::TTreeNode* ParentNode)
{
    bool CanAdd;
    _di_IShellFolder NewFolder;
    TShellFolder *AFolder;
    TShellFolder *Temp;

    AFolder = (TShellFolder *)ParentNode->Data;
    NewFolder = GetIShellFolder(AFolder->ShellFolder, ID);
    NewNode->Data = new TShellFolder(AFolder, ID, NewFolder);
    Temp = (TShellFolder *)NewNode->Data;
    {
        NewNode->Text = Temp->DisplayName();
        if(FUseShellImages && Images == NULL)
        {
            NewNode->ImageIndex = GetShellImage(Temp->AbsoluteID, false, false);
            NewNode->SelectedIndex = GetShellImage(Temp->AbsoluteID, false, true);
        }

        if(NewNode->SelectedIndex == 0)
            NewNode->SelectedIndex = NewNode->ImageIndex;

        NewNode->HasChildren = Temp->SubFolders();
        if(Temp->Properties().Contains(fpShared))
            NewNode->OverlayIndex = 0;

        if(ObjectTypes.Contains(otNonFolders) && Temp->ShellFolder != NULL)
            NewNode->HasChildren = GetHasSubItems(Temp->ShellFolder, ObjectFlags(FObjectTypes));
    }

    CanAdd = true;
    if(FOnAddFolder != NULL)
        FOnAddFolder(this, (TShellFolder *)NewNode->Data, CanAdd);

    if(!CanAdd)
        NewNode->Delete();
}
//---------------------------------------------------------------------------

void __fastcall TCustomShellTreeView::Loaded(void)
{
    Comctrls::TCustomTreeView::Loaded();
    CreateRoot();
}
//---------------------------------------------------------------------------

void __fastcall TCustomShellTreeView::Delete(Comctrls::TTreeNode* Node)
{
    // not used
    Comctrls::TCustomTreeView::Delete(Node);
}
//---------------------------------------------------------------------------

Comctrls::TTreeNode *__fastcall TCustomShellTreeView::NodeFromAbsoluteID(Comctrls::TTreeNode* StartNode, Shlobj::PItemIDList ID)
{
    HResult HR;

    Comctrls::TTreeNode *Result = StartNode;
    while(Result != NULL)
    {
        HR = DesktopShellFolder()->CompareIDs(0, ID, ((TShellFolder *)Result->Data)->AbsoluteID);

        if(HR == 0)
            return Result;

        Result = Result->GetNext();
    }

    return Result;
}
//---------------------------------------------------------------------------

/*
//! Commenting this out fixes #107480, #109250
procedure TCustomShellTreeView.MouseUp(Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
begin
  if (Button = mbRight) and FAutoContext and (Selected <> nil) and (Selected.Data <> nil) then
    InvokeContextMenu(Self, SelectedFolder, X, Y)
  else
    inherited MouseUp(Button, Shift, X, Y);
end;
*/

Comctrls::TTreeNode* __fastcall TCustomShellTreeView::NodeFromRelativeID(Comctrls::TTreeNode* ParentNode, Shlobj::PItemIDList ID)
{
    HResult HR;

    Comctrls::TTreeNode *Result = ParentNode->getFirstChild();
    while(Result != NULL)
    {
        HR = ((TShellFolder *)ParentNode->Data)->ShellFolder->CompareIDs(0, ID, ((TShellFolder *)Result->Data)->RelativeID);

        if(HR == 0)
            return Result;

        Result = ParentNode->GetNextChild(Result);
    }

    return Result;
}
//---------------------------------------------------------------------------

void __fastcall TCustomShellTreeView::Notification(Classes::TComponent* AComponent, Classes::TOperation Operation)
{
    Comctrls::TCustomTreeView::Notification(AComponent, Operation);
    if(Operation == opRemove)
    {
        if (AComponent == FComboBox)
            FComboBox = NULL;
        else if(AComponent == FListView)
            FListView = NULL;
    }
}
//---------------------------------------------------------------------------

int CALLBACK TreeSortFunc(LPARAM Node1, LPARAM Node2, LPARAM lParam)
{
    if (Node1 && Node2)
    {
        TShellFolder* sfFirst = (TShellFolder*)((TTreeNode*)Node1)->Data;
        TShellFolder* sfSecond = (TShellFolder*)((TTreeNode*)Node2)->Data;
        return sfFirst->ParentShellFolder()->CompareIDs(0,
            sfFirst->RelativeID, sfSecond->RelativeID);
    }
    else  return 0;
}

void __fastcall TCustomShellTreeView::PopulateNode(Comctrls::TTreeNode* Node)
{
    PItemIDList ID;
    IEnumIDList *EnumList;
    TTreeNode *NewNode;
    DWORD NumIDs;
    TCursor SaveCursor;
    HResult HR;

    SaveCursor = Screen->Cursor;
    Screen->Cursor = crHourGlass;
    Items->BeginUpdate();
    try
    {
        try
        {
            HR = ((TShellFolder *)Node->Data)->ShellFolder->EnumObjects(Application->Handle, ObjectFlags(FObjectTypes), &EnumList);
            if(HR != NULL)
                return;
        }
        catch(Exception &E)
        {
        }

        while(EnumList->Next(1, &ID, &NumIDs) == S_OK)
        {
            NewNode = Items->AddChild(Node, "");
            InitNode(NewNode, ID, Node);
        }

        // Hack for header file problem
        Node->CustomSort(TreeSortFunc, 0, true);
    }
    __finally
    {
        Items->EndUpdate();
        Screen->Cursor = SaveCursor;
    }
}
//---------------------------------------------------------------------------

void __fastcall TCustomShellTreeView::NodeDeleted(TObject *Sender, TTreeNode *Node)
{
    if(Node->Data != NULL)
    {
        delete (TShellFolder *)(Node->Data);
        Node->Data = NULL;
    }
}
//---------------------------------------------------------------------------

void __fastcall TCustomShellTreeView::RootChanged(void)
{
    if(FUpdating)
        return;

    FUpdating = true;
    try
    {
        CreateRoot();
        if(FComboBox != NULL)
            FComboBox->SetRoot(FRoot);
        if(FListView != NULL)
            FListView->SetRoot(FRoot);
    }
    __finally
    {
        FUpdating = false;
    }
}
//---------------------------------------------------------------------------

void __fastcall TCustomShellTreeView::SetObjectTypes(TShellObjectTypes Value)
{
    FObjectTypes = Value;
    RootChanged();
}
//---------------------------------------------------------------------------

void __fastcall TCustomShellTreeView::WndProc(Messages::TMessage &Message)
{
    THandle ImageListHandle;

    switch(Message.Msg)
    {
        case WM_INITMENUPOPUP:
        case WM_DRAWITEM:
        case WM_MENUCHAR:
        case WM_MEASUREITEM:
            if(ICM2 != NULL)
            {
                ICM2->HandleMenuMsg(Message.Msg, Message.WParam, Message.LParam);
                Message.Result = 0;
            }
            break;

        case TVM_SETIMAGELIST:
            if(!FImageListChanging)
            {
                FImageListChanging = true;
                try
                {
                    if(Images == NULL)
                    {
                        if(FUseShellImages)
                             ImageListHandle = FImages;
                        else
                             ImageListHandle = 0;
                    }
                    else
                        ImageListHandle = Images->Handle;

                    SendMessage(this->Handle, TVM_SETIMAGELIST, TVSIL_NORMAL, ImageListHandle);
                }
                __finally
                {
                    FImageListChanging = false;
                }
            }
            else
                Comctrls::TCustomTreeView::WndProc(Message);

            break;

        case WM_DESTROY:
            ClearItems(); 
            // Fall through and do the standard wndproc
        default:
            Comctrls::TCustomTreeView::WndProc(Message);
    }
}
//---------------------------------------------------------------------------

void __fastcall TCustomShellTreeView::ClearItems(void)
{
    Items->BeginUpdate();
    try
    {
        for(int i = 0; i < Items->Count; i++)
        {
            if(Folders[i] != NULL)
                delete Folders[i];

            Items->Item[i]->Data = NULL;
        }
        Items->Clear();
    }
    __finally
    {
        Items->EndUpdate();
    }
}
//---------------------------------------------------------------------------

void __fastcall TCustomShellTreeView::RefreshEvent(void)
{
    if(Selected != NULL)
        Refresh(Selected);
}
//---------------------------------------------------------------------------

void __fastcall TCustomShellTreeView::Refresh(Comctrls::TTreeNode* Node)
{
    TTreeNode *NewNode;
    TTreeNode *OldNode;
    TTreeNode *Temp;
    TShellFolder *OldFolder;
    TShellFolder *NewFolder;
    int ThisLevel;
    TCursor SaveCursor;
    PItemIDList TopID;
    PItemIDList SelID;
    TShellFolder *ParentFolder;

    if(((TShellFolder *)Node->Data)->ShellFolder != NULL)
        return;

    SaveCursor = Screen->Cursor;
    ParentFolder = NULL;

    // Need absolute PIDL to search for top item once tree is rebuilt.
    TopID = CopyPIDL(((TShellFolder *)TopItem->Data)->RelativeID);
    if(((TShellFolder *)TopItem->Data)->Parent != NULL)
        TopID = ConcatPIDLs(((TShellFolder *)TopItem->Data)->Parent->AbsoluteID, TopID);

    //Same thing for SelID
    SelID = NULL;
    if(Selected != NULL && Selected->Data != NULL)
    {
        SelID = CopyPIDL(((TShellFolder *)Selected->Data)->RelativeID);
        if(((TShellFolder *)Selected->Data)->Parent != NULL)
            SelID = ConcatPIDLs(((TShellFolder *)Selected->Data)->Parent->AbsoluteID, SelID);
    }

    Items->BeginUpdate();
    try
    {
        Screen->Cursor = crHourGlass;
        OldFolder = (TShellFolder *)Node->Data;
        NewNode = Items->Insert(Node, "");
        if(Node->Parent != NULL)
            ParentFolder = (TShellFolder *)(Node->Parent->Data);

        NewNode->Data = new TShellFolder(ParentFolder, OldFolder->RelativeID, OldFolder->ShellFolder);
        PopulateNode(NewNode);

        NewFolder = (TShellFolder *)NewNode->Data;
        NewNode->ImageIndex = GetShellImage(NewFolder->AbsoluteID, false, false);
        NewNode->SelectedIndex = GetShellImage(NewFolder->AbsoluteID, false, true);
        NewNode->HasChildren = NewFolder->SubFolders();
        NewNode->Text = NewFolder->DisplayName();

        ThisLevel = Node->Level;
        OldNode = Node;

        do
        {
            Temp = FolderExists(((TShellFolder *)OldNode->Data)->AbsoluteID, NewNode);
            if(Temp != NULL && OldNode->Expanded)
                Temp->Expand(false);

            OldNode = OldNode->GetNext();
        }
        while(OldNode != NULL && OldNode->Level != ThisLevel);

        if(Node->Data != NULL)
        {
            delete (TShellFolder *)Node->Data;
              Node->Data = NULL;
        }

        delete Node;

        if(SelID != NULL)
        {
            Temp = FolderExists(SelID, Items->Item[0]);
            Selected = Temp;
        }

        Temp = FolderExists(TopID, Items->Item[0]);
        TopItem = Temp;
    }
    __finally
    {
        Items->EndUpdate();
        DisposePIDL(TopID);
        if(SelID != NULL)
            DisposePIDL(SelID);

        Screen->Cursor = SaveCursor;
    }
}
//---------------------------------------------------------------------------

TShellFolder* __fastcall TCustomShellTreeView::SelectedFolder(void)
{
    if(Selected != NULL)
        return (TShellFolder *)Selected->Data;

    return NULL;
}

//---------------------------------------------------------------------------
// TShellTreeView -----------------------------------------------------------
__fastcall TShellTreeView::TShellTreeView(Classes::TComponent* AOwner) : TCustomShellTreeView(AOwner)
{
}
//---------------------------------------------------------------------------

__fastcall TShellTreeView::TShellTreeView(HWND ParentWindow) : TCustomShellTreeView(ParentWindow)
{
}
//---------------------------------------------------------------------------

__fastcall TShellTreeView::~TShellTreeView(void)
{
}
//---------------------------------------------------------------------------
// TShellComboBox -----------------------------------------------------------
__fastcall TShellComboBox::TShellComboBox(Classes::TComponent* AOwner)
                                                : TCustomShellComboBox(AOwner)
{
}
//---------------------------------------------------------------------------

__fastcall TShellComboBox::TShellComboBox(HWND ParentWindow)
                                            : TCustomShellComboBox(ParentWindow)
{
}
//---------------------------------------------------------------------------

__fastcall TShellComboBox::~TShellComboBox(void)
{
}
//---------------------------------------------------------------------------
// TShellListView -----------------------------------------------------------
__fastcall TShellListView::TShellListView(Classes::TComponent* AOwner)
                                                : TCustomShellListView(AOwner)
{
}
//---------------------------------------------------------------------------

__fastcall TShellListView::TShellListView(HWND ParentWindow)
                                            : TCustomShellListView(ParentWindow)
{
}
//---------------------------------------------------------------------------

__fastcall TShellListView::~TShellListView(void)
{
}
//---------------------------------------------------------------------------
// Global ShellCtrl namespace -----------------------------------------------
PACKAGE String Shellctrls::GetEnumName(TRootFolder Value)
{
    String Result = "";

    switch(Value)
    {
        case rfDesktop:
            Result = "rfDesktop";
            break;

        case rfMyComputer:
            Result = "rfMyComputer";
            break;

        case rfNetwork:
            Result = "rfNetwork";
            break;

        case 3:
            Result = "rfRecycleBin";
            break;

        case 4:
            Result = "rfAppData";
            break;

        case 5:
            Result = "rfCommonDesktopDirectory";
            break;

        case 6:
            Result = "rfCommonPrograms";
            break;

        case 7:
            Result = "rfCommonStartMenu";
            break;

        case 8:
            Result = "rfCommonStartup";
            break;

        case 9:
            Result = "rfControlPanel";
            break;

        case 10:
            Result = "rfDesktopDirectory";
            break;

        case 11:
            Result = "rfFavorites";
            break;

        case 12:
            Result = "rfFonts";
            break;

        case 13:
            Result = "rfInternet";
            break;

        case 14:
            Result = "rfPersonal";
            break;

        case 15:
            Result = "rfPrinters";
            break;

        case 16:
            Result = "rfPrograms";
            break;

        case 17:
            Result = "rfPrintHood";
            break;

        case 18:
            Result = "rfRecent";
            break;

        case 19:
            Result = "rfSendTo";
            break;

        case 20:
            Result = "rfStartMenu";
            break;

        case 21:
            Result = "rfStartup";
            break;

        case 22:
            Result = "rfTemplates";
            break;
    }
    return Result;
}

PACKAGE TRootFolder Shellctrls::GetEnumValue(String Value)
{
    if(Value == "rfDesktop")
        return rfDesktop;

    if(Value == "rfMyComputer")
        return rfMyComputer;

    if(Value == "rfNetwork")
        return rfNetwork;

    if(Value == "rfRecycleBin")
        return rfRecycleBin;

    if(Value == "rfAppData")
        return rfAppData;

    if(Value == "rfCommonDesktopDirectory")
        return rfCommonDesktopDirectory;

    if(Value == "rfCommonPrograms")
        return rfCommonPrograms;

    if(Value == "rfCommonStartMenu")
        return rfCommonStartMenu;

    if(Value == "rfCommonStartup")
        return rfCommonStartup;

    if(Value == "rfControlPanel")
        return rfControlPanel;

    if(Value == "rfDesktopDirectory")
        return rfDesktopDirectory;

    if(Value == "rfFavorites")
        return rfFavorites;

    if(Value == "rfFonts")
        return rfFonts;

    if(Value == "rfInternet")
        return rfInternet;

    if(Value == "rfPersonal")
        return rfPersonal;

    if(Value == "rfPrinters")
        return rfPrinters;

    if(Value == "rfPrintHood")
        return rfPrintHood;

    if(Value == "rfPrograms")
        return rfPrograms;

    if(Value == "rfRecent")
        return rfRecent;

    if(Value == "rfSendTo")
        return rfSendTo;

    if(Value == "rfStartMenu")
        return rfStartMenu;

    if(Value == "rfStartup")
        return rfStartup;

    if(Value == "rfTemplates")
        return rfTemplates;

    return (TRootFolder)-1;
}

PItemIDList CreatePIDL(int Size)
{
    if(ShellMalloc == NULL)
        OleCheck(SHGetMalloc(&ShellMalloc));
    PItemIDList PIDL = (PItemIDList)ShellMalloc->Alloc(Size);

    if(PIDL != NULL) // if Assigned(Result) then
        memset(PIDL, 0, Size); // FillChar(Result^, Size, 0);

    return PIDL;
}

PItemIDList NextPIDL(PItemIDList IDList)
{
    return (PItemIDList)((int)IDList+IDList->mkid.cb); // Inc(PChar(Result), IDList^.mkid.cb);
}

void StripLastID(PItemIDList IDList)
{
    PItemIDList MarkerID = IDList;
    if(MarkerID != NULL) // if Assigned(IDList) then
    {
        while(IDList->mkid.cb)
        {
            MarkerID = IDList;
            IDList = NextPIDL(IDList);
        }

        MarkerID->mkid.cb = 0;
    }
}

int GetItemCount(PItemIDList IDList)
{
    int ItemCount = 0;

    while(IDList->mkid.cb)
    {
        ItemCount++;
        IDList = NextPIDL(IDList);
    }

    return ItemCount;
}

int GetPIDLSize(PItemIDList IDList)
{
    int PIDLSize = 0;
    if(IDList) // if Assigned(IDList) then
    {
        PIDLSize = sizeof(IDList->mkid.cb);
        while(IDList->mkid.cb)
        {
            PIDLSize += IDList->mkid.cb;
            IDList = NextPIDL(IDList);
        }
    }
    return PIDLSize;
}

PItemIDList CopyPIDL(PItemIDList IDList)
{
    int Size = GetPIDLSize(IDList);

    PItemIDList PIDL = CreatePIDL(Size);
    if(PIDL != NULL)
        memcpy(PIDL, IDList, Size);

    return PIDL;
}

PItemIDList ConcatPIDLs(PItemIDList IDList1, PItemIDList IDList2)
{
    int cb1, cb2;

    if(IDList1 != NULL)
        cb1 = GetPIDLSize(IDList1) - sizeof(IDList1->mkid.cb);
      else
        cb1 = 0;

    cb2 = GetPIDLSize(IDList2);

    PItemIDList PIDL = CreatePIDL(cb1 + cb2);
    if(PIDL != NULL)
    {
        if(IDList1 != NULL)
            memcpy(PIDL, IDList1, cb1);

        memcpy((PChar)PIDL + cb1, IDList2, cb2);
    }

    return PIDL;
}

void DisposePIDL(PItemIDList PIDL)
{
    if(ShellMalloc == NULL)
        OleCheck(SHGetMalloc(&ShellMalloc));

    ShellMalloc->Free(PIDL);
}

PItemIDList RelativeFromAbsolute(PItemIDList AbsoluteID)
{
    PItemIDList PIDL = AbsoluteID;
    while(GetItemCount(PIDL) > 1)
        PIDL = NextPIDL(PIDL);

    return CopyPIDL(PIDL);
}

TList *CreatePIDLList(PItemIDList ID)
{
    TList *TempList = new TList();
    PItemIDList TempID = ID;

    while(TempID->mkid.cb)
    {
        TempID = CopyPIDL(TempID);
        TempList->Insert(0, TempID);        //0 = lowest level PIDL.
        StripLastID(TempID);
    }

    return TempList;
}

void DestroyPIDLList(TList *List)
{
    if(List == NULL)
        return;

    for(int i = 0; i < List->Count; i++)
        DisposePIDL((PItemIDList)List->Items[i]);

    List->Free();
}

// Miscellaneous

void NoFolderDetails(TShellFolder *AFolder, HResult HR)
{
  throw EInvalidPath(SShellNoDetails);
};

_di_IShellFolder DesktopShellFolder(void)
{
    _di_IShellFolder NewSF;
    OleCheck(SHGetDesktopFolder(&NewSF));
    return NewSF;
}

void CreateDesktopFolder(void)
{
    PItemIDList DesktopPIDL;
    SHGetSpecialFolderLocation(0, nFolder[rfDesktop], &DesktopPIDL);

    if(DesktopPIDL != NULL)
      DesktopFolder = new TShellFolder(NULL, DesktopPIDL, DesktopShellFolder());
}

bool SamePIDL(PItemIDList ID1, PItemIDList ID2)
{
    return DesktopShellFolder()->CompareIDs(0, ID1, ID2) == 0;
}

PItemIDList DesktopPIDL(void)
{
    PItemIDList PIDL;

    OleCheck(SHGetSpecialFolderLocation(0, nFolder[rfDesktop], &PIDL));

    return PIDL;
}

TRootFolder GetCSIDLType(String Value)
{
    return Shellctrls::GetEnumValue(Value);
}

bool IsElement(int Element, int Flag)
{
    return (Element & Flag) != 0;
}

int GetShellImage(PItemIDList PIDL, bool Large, bool Open)
{
    TSHFileInfo FileInfo;
    int Flags = SHGFI_PIDL | SHGFI_SYSICONINDEX;

    if(Open)
        Flags |= SHGFI_OPENICON;

    if(Large)
        Flags |= SHGFI_LARGEICON;
      else
        Flags |= SHGFI_SMALLICON;

    SHGetFileInfo(
        PChar(PIDL),
        0,
        &FileInfo,
        sizeof(FileInfo),
        Flags);

    return FileInfo.iIcon;
}

TShellFolderCapabilities GetCaps(_di_IShellFolder ParentFolder, PItemIDList PIDL)
{
    TShellFolderCapabilities FolderCaps;
    DWORD Flags = SFGAO_CAPABILITYMASK;

    ParentFolder->GetAttributesOf(1, (LPCITEMIDLIST *)&PIDL, &Flags);
    if(IsElement(SFGAO_CANCOPY, Flags))
        FolderCaps << fcCanCopy;

    if(IsElement(SFGAO_CANDELETE, Flags))
        FolderCaps << fcCanDelete;

    if(IsElement(SFGAO_CANLINK, Flags))
        FolderCaps << fcCanLink;

    if(IsElement(SFGAO_CANMOVE, Flags))
        FolderCaps << fcCanMove;

    if(IsElement(SFGAO_CANRENAME, Flags))
        FolderCaps << fcCanRename;

    if(IsElement(SFGAO_DROPTARGET, Flags))
        FolderCaps << fcDropTarget;

    if(IsElement(SFGAO_HASPROPSHEET, Flags))
        FolderCaps << fcHasPropSheet;

    return FolderCaps;
}

TShellFolderProperties GetProperties(_di_IShellFolder ParentFolder, PItemIDList PIDL)
{
     if(ParentFolder == NULL)
        return TShellFolderProperties();

    TShellFolderProperties FolderProps;
    DWORD Flags = SFGAO_DISPLAYATTRMASK;
    ParentFolder->GetAttributesOf(1,  (LPCITEMIDLIST*)&PIDL, &Flags);

    if(IsElement(SFGAO_GHOSTED, Flags))
        FolderProps >> fpCut;

    if(IsElement(SFGAO_LINK, Flags))
        FolderProps >> fpIsLink;

    if(IsElement(SFGAO_READONLY, Flags))
        FolderProps >> fpReadOnly;

    if(IsElement(SFGAO_SHARE, Flags))
        FolderProps >> fpShared;

    Flags = 0;
    ParentFolder->GetAttributesOf(1, (LPCITEMIDLIST *)&PIDL, &Flags);
    if(IsElement(SFGAO_FILESYSTEM, Flags))
        FolderProps >> fpFileSystem;

    if(IsElement(SFGAO_FILESYSANCESTOR, Flags))
        FolderProps >> fpFileSystemAncestor;

    if(IsElement(SFGAO_REMOVABLE, Flags))
        FolderProps >> fpRemovable;

    if(IsElement(SFGAO_VALIDATE, Flags))
        FolderProps >> fpValidate;

    return FolderProps;
}

bool GetIsFolder(_di_IShellFolder ParentFolder, PItemIDList PIDL)
{
    DWORD Flags;
    Flags = SFGAO_FOLDER;
    ParentFolder->GetAttributesOf(1, (LPCITEMIDLIST*)&PIDL, &Flags);
    return (SFGAO_FOLDER & Flags); 
}

bool GetHasSubFolders(_di_IShellFolder ParentFolder, PItemIDList PIDL)
{
    DWORD Flags = SFGAO_CONTENTSMASK;
    ParentFolder->GetAttributesOf(1, (LPCITEMIDLIST *)&PIDL, &Flags);
    return (SFGAO_HASSUBFOLDER & Flags);
}

bool GetHasSubItems(_di_IShellFolder ShellFolder, int Flags)
{
    PItemIDList ID;
    IEnumIDList *EnumList;
    DWORD NumIDs;
    HResult HR;
    int ErrMode;
    bool Result = False;

    if(ShellFolder == NULL)
        return Result;

    ErrMode = SetErrorMode(SEM_FAILCRITICALERRORS);

    try
    {
        HR = ShellFolder->EnumObjects(0, Flags, &EnumList);
        if(HR != S_OK)
            return Result;

        Result = EnumList->Next(1, &ID, &NumIDs) == S_OK;
    }
    __finally
    {
        SetErrorMode(ErrMode);
    }

    return Result;
}

String StrRetToString(PItemIDList PIDL, TStrRet StrRet)
{
    switch(StrRet.uType)
    {
        case STRRET_CSTR:
            return AnsiString(StrRet.cStr);
        case STRRET_OFFSET:
        {
            char *P = PIDL->mkid.abID + (StrRet.uOffset - sizeof(PIDL->mkid.cb));
            return AnsiString(P);
        }
        case STRRET_WSTR:
            if (StrRet.pOleStr)
            {
                AnsiString Result = AnsiString(StrRet.pOleStr);
                ShellMalloc->Free(StrRet.pOleStr);
                return Result;
            }

    }
    return AnsiString("");
}

String GetDisplayName(_di_IShellFolder ParentFolder, PItemIDList PIDL, DWORD Flags)
{
    if(ParentFolder == NULL)
        return AnsiString("parentfolder = nil"); // Do not localize

    TStrRet StrRet;
    memset(&StrRet, 0, sizeof(StrRet));
    ParentFolder->GetDisplayNameOf(PIDL, Flags, &StrRet);
    String Result = StrRetToString(PIDL, StrRet);
    //TODO 2 -oMGD -cShell Controls : Remove this hack (on Win2k, GUIDs are returned for the PathName of standard folders)
    if (Result.Pos("::{") == 1) 
        Result = GetDisplayName(ParentFolder, PIDL, SHGDN_NORMAL);
    return Result;
}

int ObjectFlags(TShellObjectTypes ObjectTypes)
{
    int Result = 0;
    if(ObjectTypes.Contains(otFolders))
        Result += SHCONTF_FOLDERS;

    if(ObjectTypes.Contains(otNonFolders))
        Result += SHCONTF_NONFOLDERS;

    if(ObjectTypes.Contains(otHidden))
        Result += SHCONTF_INCLUDEHIDDEN;

    return Result;
}


void __fastcall Shellctrls::InvokeContextMenu(Controls::TWinControl* Owner, TShellFolder* AFolder, int X, int Y)
{
    PItemIDList PIDL;
    _di_IContextMenu CM;
    HMENU Menu;
    POINT P;
    int Command; // was a bool, which caused some stuff to not work
    char ZVerb[255];
    String Verb;
    bool Handled;

    if(AFolder == NULL)
        return;

    PIDL = AFolder->RelativeID;
    (AFolder->ParentShellFolder())->GetUIObjectOf(Owner->Handle, 1, (LPCITEMIDLIST *)&PIDL, IID_IContextMenu, NULL, (void **)&CM);
    if(CM == NULL)
        return;

    P.x = X;
    P.y = Y;

    ClientToScreen(Owner->Handle, &P);
    Menu = CreatePopupMenu();
    try
    {
        CM->QueryContextMenu(Menu, 0, 1, 0xFFF, CMF_EXPLORE | CMF_CANRENAME);
        CM->QueryInterface(IID_IContextMenu2, (void **)&ICM2); //To handle submenus.
        try
        {
            Command = TrackPopupMenu(Menu, TPM_LEFTALIGN | TPM_LEFTBUTTON | TPM_RIGHTBUTTON |
                          TPM_RETURNCMD, P.x, P.y, 0, Owner->Handle, NULL);
        }
        __finally
        {
            ICM2 = NULL;
        }

        if(Command)
        {
            int ICmd = Command - 1;
            CM->GetCommandString(ICmd, GCS_VERBA, NULL, ZVerb, sizeof(ZVerb));
            Verb = StrPas(ZVerb);

            CMINVOKECOMMANDINFO ICI;
            memset(&ICI, 0, sizeof(CMINVOKECOMMANDINFO));
            ICI.cbSize = sizeof(CMINVOKECOMMANDINFO);
            if (Owner)
                ICI.hwnd = Owner->Handle;
            else
                ICI.hwnd = Application->Handle;
            ICI.lpVerb = MakeIntResource(ICmd);
            ICI.nShow = SW_SHOWNORMAL;
            CM->InvokeCommand(&ICI);
        }
    }
    __finally
    {
      DestroyMenu(Menu);
    }
}

void DoContextMenuVerb(TShellFolder *AFolder, PChar Verb)
{
    TCMInvokeCommandInfo ICI;
    _di_IContextMenu CM;
    PItemIDList PIDL;

    if(AFolder == NULL)
        return;

    memset(&ICI, 0, sizeof(ICI));

    ICI.cbSize = sizeof(ICI);
    ICI.fMask = CMIC_MASK_ASYNCOK;
    ICI.hwnd = 0;
    ICI.lpVerb = Verb;
    ICI.nShow = SW_SHOWNORMAL;

    PIDL = AFolder->RelativeID;
    (AFolder->ParentShellFolder())->GetUIObjectOf(0, 1, (LPCITEMIDLIST *)&PIDL, IID_IContextMenu, NULL, (void **)&CM);
    CM->InvokeCommand(&ICI);
}

_di_IShellFolder GetIShellFolder(_di_IShellFolder IFolder, PItemIDList PIDL, HWND Handle)
{
    _di_IShellFolder RetFolder;
    HResult HR;

    if(IFolder)
    {
        HR = IFolder->BindToObject(PIDL, NULL, IID_IShellFolder, (void **)&RetFolder);

        if(HR != S_OK) // bug fix from ShellCtrls.pas, added HR =
          HR = IFolder->GetUIObjectOf((void*)Handle, 1, (LPCITEMIDLIST *)&PIDL,
            IID_IShellFolder, NULL, (void **)&RetFolder);

        if(HR != S_OK)
          IFolder->CreateViewObject((void*)Handle, IID_IShellFolder, (void **)&RetFolder);
    }

    if(RetFolder == NULL)
        DesktopShellFolder()->BindToObject(PIDL, NULL, IID_IShellFolder, (void **)&RetFolder);

    return RetFolder;
}

Shlobj::_di_IShellDetails GetIShellDetails(_di_IShellFolder IFolder, PItemIDList PIDL, HWND Handle)
{
    Shlobj::_di_IShellDetails RetDetails;
    HResult HR;
    if(IFolder != NULL)
    {
        HR = IFolder->BindToObject(PIDL, NULL, IID_IShellDetails, (void **)&RetDetails);

        if(HR != S_OK)
            IFolder->GetUIObjectOf(&Handle, 1, (LPCITEMIDLIST *)&PIDL, IID_IShellDetails, NULL, (void **)&RetDetails);

        if(HR != S_OK)
            IFolder->CreateViewObject(&Handle, IID_IShellDetails, (void **)&RetDetails);
    }
    if(RetDetails == NULL)
        DesktopShellFolder()->BindToObject(PIDL, NULL, IID_IShellDetails, (void **)&RetDetails);

    return RetDetails;
}

_di_IShellFolder2 GetIShellFolder2(_di_IShellFolder IFolder, PItemIDList PIDL, HWND Handle)
{
    HResult HR;
    _di_IShellFolder2 RetFolder;

    if(Win32MajorVersion >= 5)
    {
        HR = DesktopShellFolder()->BindToObject(PIDL, NULL, IID_IShellFolder2, (void **)&RetFolder);

        if(HR != S_OK)
            IFolder->GetUIObjectOf(&Handle, 1, (LPCITEMIDLIST *)&PIDL, IID_IShellFolder2, NULL, (void **)&RetFolder);

        if (HR != S_OK && IFolder != NULL)
            IFolder->BindToObject(PIDL, NULL, IID_IShellFolder2,(void **) &RetFolder);
    }
    else
        RetFolder = NULL;

    return RetFolder;
}

TShellFolder *CreateRootFromPIDL(PItemIDList Value)
{
    _di_IShellFolder SF = GetIShellFolder(DesktopShellFolder(), Value);

    if (SF == NULL) //special case - Desktop folder can't bind to itself.
        SF = DesktopShellFolder();
    return new TShellFolder(DesktopFolder, Value, SF);
}

TShellFolder *CreateRootFolder(TShellFolder *RootFolder, TRoot OldRoot, TRoot NewRoot)
{
    PWideChar P;
    PItemIDList NewPIDL;
    DWORD NumChars,    Flags, HR;
    String ErrorMsg;

    HR = S_FALSE;
    if(Shellctrls::GetEnumValue(NewRoot) >= 0)
    {
        HR = SHGetSpecialFolderLocation(0, nFolder[GetCSIDLType(NewRoot)], &NewPIDL);
    }
    else if(NewRoot.Length() > 0)
    {
        if(NewRoot[NewRoot.Length()] == ':')
            NewRoot += '\\';
        NumChars = NewRoot.Length();
        Flags = 0;
        P = StringToOleStr(NewRoot);
        HR = DesktopShellFolder()->ParseDisplayName(0, NULL, P, &NumChars, &NewPIDL, &Flags);
    }

    if(HR != S_OK)
    {
        TVarRec Records[] = { NewRoot };
        ErrorMsg = Format(Consts_SErrorSettingPath, Records, 1); //ErrorMsg := Format( SErrorSettingPath, [ NewRoot ] );

        NewRoot = OldRoot;
        throw Exception( ErrorMsg );
    }

    TShellFolder *PIDL = CreateRootFromPIDL(NewPIDL);

    if(RootFolder != NULL)
        delete RootFolder;

    return PIDL;
}

int __fastcall ListSortFunc(void *Item1, void *Item2)
{
    TShellFolder* sfFirst = (TShellFolder*)Item1;
    TShellFolder* sfSecond = (TShellFolder*)Item2;

    int res = 0;
    if (sfFirst && sfFirst)
    {
        res = (int)sfFirst->IsFolder() - (int)sfSecond->IsFolder();

        if (res == 0 && sfFirst->ParentShellFolder())
            res = sfFirst->ParentShellFolder()->CompareIDs(0, sfFirst->RelativeID,
                                                              sfSecond->RelativeID);
    }
    return res;
}

int __fastcall ComboSortFunc(void *Item1, void *Item2)
{
    if (CompareFolder)
        return CompareFolder->ShellFolder->CompareIDs(0, (ITEMIDLIST*)Item1,
            (ITEMIDLIST*)Item2);
    else
        return 0;
}


class TShellStartup {
public:
  TShellStartup();
  ~TShellStartup();
};
static TShellStartup ShellStartup; // Initializes all the global variables


TShellStartup::TShellStartup()
{
  CreateDesktopFolder();
  InitializeCriticalSection(&CS);
  OleInitialize(NULL);
  OleCheck(SHGetMalloc(&ShellMalloc));
}

TShellStartup::~TShellStartup()
{
  if (DesktopFolder) 
    delete DesktopFolder;
  DeleteCriticalSection(&CS);
  OleUninitialize();
  ShellMalloc = NULL; // does a release
  ICM = NULL;
  ICM2 = NULL;
}

//---------------------------------------------------------------------------
