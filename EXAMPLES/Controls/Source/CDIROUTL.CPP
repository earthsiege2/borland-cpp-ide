//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 1999 Borland International Inc.  All Rights Reserved.
//---------------------------------------------------------------------------
#pragma hdrstop          //This header has some initialized data so we can't use
#include  "cdiroutl.h"
#include <ctype.h>
#include <dir.h>
#include "samp.h"

#pragma resource "*.res"    
#pragma package(smart_init);

//
// definitions of static data members
// ----------------------------------
//
const TCDirectoryOutline::InvalidIndex;
const TCDirectoryOutline::RootIndex;
void *TCDirectoryOutline::APointer = &TCDirectoryOutline::APointer;

//
// inline helpers
// --------------
//

inline bool SameLetter(char a, char b)
{
    return toupper(a) == toupper(b);
}

inline int GetPos(const AnsiString& s, const AnsiString& p)
{
    return s.AnsiPos(p);
}

//---------------------------------------------------------------------------
static inline TCDirectoryOutline *ValidCtrCheck()
{
    return new TCDirectoryOutline((TComponent *)NULL);
}
//---------------------------------------------------------------------------
__fastcall TCDirectoryOutline::TCDirectoryOutline(TComponent* Owner)
    : TCustomOutline(Owner),
      PictureLeaf(PictureClosed),
      FTextCase(tcLowerCase)
{
    OutlineStyle = osTreePictureText;
    Options = TOutlineOptions() << ooStretchBitmaps << ooDrawFocusRect;
    PictureLeaf = PictureClosed;
    AssignCaseProc();
}
//---------------------------------------------------------------------------
inline int __fastcall TCDirectoryOutline::DriveToInt(char d)
{
    // this assumes that A..Z are contiguous and packed
    return toupper(d) - 'A';
}
//---------------------------------------------------------------------------
inline char __fastcall TCDirectoryOutline::IntToDrive(int i)
{
    // this assumes that A..Z are contiguous and packed
    return static_cast<char>(i + 'A');
}
//---------------------------------------------------------------------------
void __fastcall TCDirectoryOutline::AssignCaseProc()
{
    switch (TextCase) {
        case tcLowerCase:
            FCaseFunction = AnsiLowerCaseFileName;
            break;
            
        case tcUpperCase:
            FCaseFunction = AnsiUpperCaseFileName;
            break;
        default:
            FCaseFunction = NULL;
            break;
    }
}
//---------------------------------------------------------------------------

// helper class for exception safety that wraps FindFirst/FindNext/FindClose
namespace {
    class FileFind {
        private:
            TSearchRec FSRec;
            int FError;
            bool IsOk()                      { return FError == 0; }

        public:
            FileFind(const AnsiString &Path, int Attr)
            {
                FError = FindFirst(Path, Attr, FSRec);
            }

            ~FileFind()                      { FindClose(FSRec); }

            __property bool Ok             = { read = IsOk };
            __property int Error           = { read = FError };
            __property TSearchRec SRec     = { read = GetSRec };

            TSearchRec &GetSRec()            { return FSRec; }
            operator bool()                  { return Ok; }

            bool Next()
            {
                FError = FindNext(FSRec);
                return Ok;
            }
    };
};
//---------------------------------------------------------------------------

void __fastcall TCDirectoryOutline::BuildOneLevel(long RootItem)
{
    TOutlineNode *RootNode = Items[RootItem];
    AnsiString RootName = RootNode->FullPath;

    if (!RootName.IsPathDelimiter(RootName.Length()))
        RootName += "\\";
    RootName += "*.*";

    for (FileFind Find(RootName, faDirectory); Find.Ok; Find.Next()) {
        TSearchRec &SRec = Find.GetSRec();

        // only store directories, ignoring "." and ".."
        if ((SRec.Attr & faDirectory) && SRec.Name[1] != '.') {
            AnsiString Name = ForceCase(SRec.Name);

            if (RootNode->HasItems) { // insert in sorted order
                long Child = RootNode->getFirstChild();
                while (Child != InvalidIndex &&
                        Items[Child]->Text.AnsiCompareIC(Name) < 0)
                    Child = RootNode->GetNextChild(Child);

                if (Child != InvalidIndex)
                    Insert(Child, Name);
                else
                    Add(RootNode->GetLastChild(), Name);
            }
            else
                AddChild(RootItem, Name);
        }
    }
    // mark this node with an arbitrary address so we can tell we've
    // already been here
    Items[RootItem]->Data = APointer;
}
//---------------------------------------------------------------------------
void __fastcall TCDirectoryOutline::BuildTree()
{
    Clear();
    AddChild(0, ForceCase(AnsiString(Drive) + ":")); // was ":\\"
    WalkTree(FDirectory);
    Change();
}
//---------------------------------------------------------------------------
void __fastcall TCDirectoryOutline::BuildSubTree(long RootItem)
{
    BuildOneLevel(RootItem);
    TOutlineNode *RootNode = Items[RootItem];

    for (long TempRoot = RootNode->getFirstChild();
            TempRoot != InvalidIndex; 
            TempRoot = RootNode->GetNextChild(TempRoot))
        BuildSubTree(TempRoot);
}
//---------------------------------------------------------------------------
void __fastcall TCDirectoryOutline::Change()
{
    if (FOnChange)
        FOnChange(this);
}
//---------------------------------------------------------------------------
void __fastcall TCDirectoryOutline::Click()
{
    TCustomOutline::Click();
    Directory = Items[SelectedItem]->FullPath;
}
//---------------------------------------------------------------------------
void __fastcall TCDirectoryOutline::CreateWnd()
{
    AnsiString CurrentPath;
    
    TCustomOutline::CreateWnd();
    
    if (FDrive == 0) {
        AnsiString CurrentPath = ForceCase(CurDir());
        if (CurrentPath.Length() != 0) {
            FDrive = CurrentPath[1];
            FDirectory = CurrentPath;
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TCDirectoryOutline::Expand(int Index)
{
    // check to see if we've already built this
    if (!Items[Index]->Data)
        BuildOneLevel(Index);
    
    // call the event handler
    TCustomOutline::Expand(Index);
}
//---------------------------------------------------------------------------
void __fastcall TCDirectoryOutline::Loaded()
{
    Loading = true;
    TCustomOutline::Loaded();
    AssignCaseProc();
    BuildTree();
    Loading = false;
}

//---------------------------------------------------------------------------
AnsiString __fastcall TCDirectoryOutline::ForceCase(const AnsiString &s)
{
    return FCaseFunction ? (*FCaseFunction)(s) : s;
}
//---------------------------------------------------------------------------

void __fastcall TCDirectoryOutline::SetDirectory(const TFileName NewDir)
{
    if (NewDir.Length() > 0) {
        TFileName Path = ForceCase(ExpandFileName(NewDir));
        int n = Path.Length();

        if (n > 3 && Path.IsPathDelimiter(n))
            Path.SetLength(n - 1);

        if (Path != FDirectory) {
            FDirectory = Path;
            chdir(FDirectory.c_str());

            if (!SameLetter(Path[1], Drive))
                Drive = Path[1];
            else {
                WalkTree(Path);
                Change();
            }
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TCDirectoryOutline::SetDrive(char NewDrive)
{
    // the original sample did not throw an exception here.
    // should we do so now?
    NewDrive = static_cast<char>(toupper(NewDrive));
    if ((NewDrive >= 'A' && NewDrive <= 'Z')) {
        if (!SameLetter(NewDrive, FDrive)) {
            FDrive = NewDrive;
            setdisk(DriveToInt(FDrive));
            FDirectory = ForceCase(CurDir());
            if (!ComponentState.Contains(csLoading)) 
                BuildTree();
        }
    }
}

//---------------------------------------------------------------------------
void __fastcall TCDirectoryOutline::SetTextCase(TTextCase NewCase)
{
    if (NewCase != FTextCase) {
        FTextCase = NewCase;
        AssignCaseProc();
        
        if (NewCase == tcAsIs) {
            AnsiString CurrentPath = CurDir();
            FDrive = CurrentPath[1];
            FDirectory = CurrentPath;
        }
        
        if (!ComponentState.Contains(csLoading))
            BuildTree();
    }
}
//---------------------------------------------------------------------------
AnsiString TCDirectoryOutline::CurDir()
{
    const initbuf = 256;
    size_t buflen = initbuf;
    char *buf = reinterpret_cast<char *>(malloc(buflen));
    
    if (buf) {
        buflen = GetCurrentDirectory(buflen, buf);
        if (buflen > initbuf) {
            char *p = reinterpret_cast<char *>(realloc(buf, buflen));
            if (p) {
                buf = p;
                buflen = GetCurrentDirectory(buflen, buf);
            }
        }
    }
    
    try {
        AnsiString Result((buflen && buf) ? buf : "");
        free(buf);
        return Result;
    } catch (...) {
        free(buf);
        throw;
    }
}
//---------------------------------------------------------------------------
long __fastcall TCDirectoryOutline::GetChildNamed(const AnsiString& Name,
        long Item)
{
    String AText, AName;

    TOutlineNode* Node = Items[Item];

    Node->Expanded = true;
    long rc = Node->getFirstChild();

    AName = AnsiUpperCase(Name);
    AText = AnsiUpperCase(Items[rc]->Text); 
    while (rc != InvalidIndex && AText != AName)
      {
        rc = Node->GetNextChild(rc);
        if (rc != InvalidIndex)
            AText = AnsiUpperCase(Items[rc]->Text);
      }
    return rc;
}

//---------------------------------------------------------------------------

void __fastcall TCDirectoryOutline::WalkTree(const AnsiString& Dest)
{
    AnsiString Path = ForceCase(Dest);
    long Item = RootIndex;  // start at root


    // remove drive component of Path

    int Colon = Path.Pos(":");
    if (Colon > 0) {
        int Offset = (Path[Colon + 1] == '\\') ? 2 : 1;
        if ((Colon + Offset) >= Path.Length())
           Path = "";
        else
           Path = Path.SubString(Colon + Offset, Path.Length() - (Colon + Offset) +1);
    }

    // do the walk
    for (int SlashPos = GetPos(Path, "\\"); Path.Length() > 0;
            SlashPos = GetPos(Path, "\\")) {
        AnsiString Dir = Path;

        if (SlashPos > 0) {
            // splice out the first directory
            Dir = Path.SubString(1, SlashPos - 1);
            Path = Path.SubString(SlashPos + 1, Path.Length() - (SlashPos + 1) + 1);
        }
        else {
            Dir = Path;
            Path = "";
        }

        Item = GetChildNamed(Dir, Item);
    }

    SelectedItem = Item;
}
            
//---------------------------------------------------------------------------
namespace Cdiroutl
{
    void __fastcall PACKAGE Register()
    {
        TComponentClass classes[1] = {__classid(TCDirectoryOutline)};
        RegisterComponents(LoadStr(Tab_101), classes, 0);
    }
}
//---------------------------------------------------------------------------
