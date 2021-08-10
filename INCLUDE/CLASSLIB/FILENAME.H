//----------------------------------------------------------------------------
// Borland Class Library
// Copyright (c) 1995, 1997 by Borland International, All Rights Reserved
//
//$Revision:   5.10  $
//
//----------------------------------------------------------------------------
#if !defined(CLASSLIB_FILENAME_H)
#define CLASSLIB_FILENAME_H

#if !defined(CLASSLIB_DEFS_H)
# include <classlib/defs.h>
#endif
#if !defined(SERVICES_CSTRING_H)
# include <services/cstring.h>
#endif
#include <dir.h>  // struct ffblk

#if defined(BI_NAMESPACE)
namespace ClassLib {
#endif

struct TFileStatus;

//
// class TFileName
// ~~~~~ ~~~~~~~~~
class _BIDSCLASS TFileName {
  public:
    // Construct an empty filename
    //
    TFileName();

    // Construct a filename from its parts. OK to pass 0 to skip part
    //
    TFileName(const _TCHAR far* serverName, const _TCHAR far* shareOrDeviceName,
              const _TCHAR far* path, const _TCHAR far* file,
              const _TCHAR far* ext);

    // Construct a filename from a freeform string
    //
    TFileName(const _TCHAR far* freeform);
    TFileName(const string& freeform);

    // Construct a filename from another filename
    //
    TFileName(const TFileName& src);

    // Assign new filename or freeform to this name
    //
    TFileName& operator =(const TFileName& src);
    TFileName& operator =(const string& src);
    TFileName& operator =(const _TCHAR far* src);

    // Construct a filename representing a special file or directory
    //
    enum TSpecialType {
      TempFile,     // A temporary filename
      TempDir,      // Location of temporary files
      CurrentDir,   // Current working directory if any
      BootDir,      // Root dir of boot device (LDID_BOOT)
      MachineDir,   // (LDID_MACHINE)
      HomeDir,      // Home directory for OS (LDID_WIN)
      SharedDir,    // Shared home directory for OS (LDID_SHARED)
      SysDir,       // Location of system files (LDID_SYS)
      ComputerName,
    };
    TFileName(TSpecialType type);

    // Normal fully qualified path string, & short filename version of it
    // Convert a possibly logical drive based name to a UNC name if indicated
    //
    string Canonical(bool forceUNC = false) const;
    string ShortName(bool forceUNC = false) const;

    // Nice, human readable rendering of the filename using system conventions
    // (Returns null string for directory names or malformed names.  For
    // directories, try Canonical() instead.)
    //
    string Title() const;

    // Human readable form of the filename squeezed to fit in 'maxLen' _TCHARs
    //
    string Squeezed(int maxLen) const;

    // Obtain any combination of various filename parts. Seperators inserted
    // only as appropriate
    //
    enum TPart {
      Server = 1,  // Server name
      Device = 2,  // Logical device or sharename
      Path   = 4,  // Directory path to the file
      File   = 8,  // Filename part without the extension
      Ext    =16,  // Extension
    };
    string GetParts(uint p) const;      // Return assembled string of parts
    bool   HasParts(uint p) const;      // Does name have an given part
    void   SetPart(uint p, const string& partStr);    // Modify sub part
    void   MergeParts(uint p, const TFileName& source); // Modify sub parts
    void   StripParts(uint p);         // Remove indicated parts

    // Information about the filename
    //
    bool IsValid() const;       // Is a valid name of any kind
    bool IsUNC() const;         // Is UNC vs logical drive based name
    bool Exists() const;        // Does device/dir/file exist?

    // Is another filename equivalent to this filename?
    //
    bool operator ==(const TFileName& other) const;

    // Remove the file or dir associated with this filename.
    //
    void Remove() const;

    // Move (rename) the file associated with this filename, and change this
    // name to the new name
    //
    enum { ReplaceExisting=1, CopyAllowed=2, DelayUntilReboot=4 };
    void Move(const TFileName& newName, uint32 how = CopyAllowed);

    // Copy the file associated with this filename to a new file
    //
    void Copy(const TFileName& newName, bool failIfExists) const;

    int ChangeDir() const;
    int CreateDir() const;

    // Get and Set the file status struct for the item associated with this
    // filename
    //
    int GetStatus(TFileStatus& status) const;
    int SetStatus(const TFileStatus& status);

    // Other ideas...
    //
    static const _TCHAR* WildName() {return "*";}       // General wildstring
    static const _TCHAR* WildPart(uint p) {return "*";} // Part specific?

  private:
    void   Parse(const _TCHAR far* freeform);

    bool   Unc;
    string ServerStr;
    string DeviceStr;
    string PathStr;
    string FileStr;
    string ExtStr;
};

//
// class TFileNameIterator
// ~~~~~ ~~~~~~~~~~~~~~~~~
class _BIDSCLASS TFileNameIterator {
  public:
    TFileNameIterator(const string& wildName);
   ~TFileNameIterator();

//    operator bool() const;

#if defined(BI_PLAT_WIN32)
    operator const TCHAR*() const;

    const WIN32_FIND_DATA& operator ++();
    const WIN32_FIND_DATA& Current() const;

#elif defined(BI_PLAT_WIN16)
    operator const _TCHAR*() const;

    const ffblk& operator ++();
    const ffblk& Current() const;
#endif

  private:
#if defined(BI_PLAT_WIN32)
    WIN32_FIND_DATA Data;
    HANDLE          Handle;
#elif defined(BI_PLAT_WIN16)
    ffblk           Data;
#endif
    bool            Done;
};

#if defined(BI_NAMESPACE)
}   // namespace ClassLib
#endif

//----------------------------------------------------------------------------
// Inlines
//
#if !defined(CLASSLIB_FILE_H)
# include <classlib/file.h>
#endif

inline TFileName& TFileName::operator =(const string& src)
{
  Parse(src.c_str());
  return *this;
}

inline TFileName& TFileName::operator =(const _TCHAR far* src)
{
  Parse(src);
  return *this;
}

inline bool TFileName::operator ==(const TFileName& other) const
{
  string::set_case_sensitive(0);         // maybe true for some OSs
  return Canonical() == other.Canonical();
}

inline bool TFileName::IsUNC() const
{
  return Unc;
}

inline int TFileName::GetStatus(TFileStatus& status) const
{
  return TFile::GetStatus(Canonical().c_str(), status);
}

inline int TFileName::SetStatus(const TFileStatus& status)
{
  return TFile::SetStatus(Canonical().c_str(), status);
}

#if defined(BI_PLAT_WIN32)
inline const WIN32_FIND_DATA& TFileNameIterator::Current() const
#elif defined(BI_PLAT_WIN16)
inline const ffblk& TFileNameIterator::Current() const
#endif
{
  return Data;
}

//inline TFileNameIterator::operator bool() const
//{
//  return !Done;
//}

#if defined(BI_PLAT_WIN32)
inline TFileNameIterator::operator const TCHAR*() const
{
  return Done ? 0 : Data.cFileName;
}
#elif defined(BI_PLAT_WIN16)
inline TFileNameIterator::operator const _TCHAR*() const
{
  return Done ? 0 : Data.ff_name;
}
#endif

#endif  // CLASSLIB_FILENAME_H
