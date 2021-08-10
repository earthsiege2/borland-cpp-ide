//----------------------------------------------------------------------------
// Borland Class Library
// Copyright (c) 1995, 1997 by Borland International, All Rights Reserved
//
//$Revision:   5.21  $
//
// TFileName class implementation.
//----------------------------------------------------------------------------
#include <classlib/pch.h>
#include <classlib/filename.h>
#include <services/memory.h>
#include <winsys/system.h>
#include <tchar.h>
#if !defined(BI_PLAT_WIN32)
# include <dir.h>
#endif
#if defined(BI_PLAT_WIN16)
# include <commdlg.h>
# include <stdio.h>
#endif

#define WIN95_LONGFILENAME_MAX 260

#if defined(BI_PLAT_MSW)
  static _TCHAR serverNamePrefix[] = "\\\\";
  static int  serverNamePrefixLen = _tcslen(serverNamePrefix);
//  static _TCHAR devTerminator[] = "\\/:";
  static _TCHAR ldevTerminator = ':';
  static _TCHAR dirSeparator[] = "\\/";
  static _TCHAR dirSeparatorCh = '\\';
  static _TCHAR extSeparator = '.';
#endif

//
// Some Win32 APIs that are available under Win16 via DOS calls
//
#if defined(BI_PLAT_WIN16)
DWORD
GetFullPathName(LPCSTR lpFileName, DWORD nBufferLength, LPSTR lpBuffer,
                LPSTR* lpFilePart)
{
  // use new MS-DOS long filename function x7160,0 - GetFullPathName
  _TCHAR destPath[WIN95_LONGFILENAME_MAX]; // defined at top of file
  _TCHAR const far* farFileName = lpFileName;
  _TCHAR far* farDestPath = destPath;
  _asm {
    mov ax, 0x7160
    mov cl, 0                    // GetFullPathName
    mov ch, 0                    // return string contains path not SUBST drive
    lds si, farFileName
    les di, farDestPath
    int 21h
    jc  error
  }

  _tcsncpy(lpBuffer, destPath, (int)(nBufferLength - 1));
  goto exit;
error:
    _tcsncpy(lpBuffer, lpFileName, (int)(nBufferLength - 1)); // just copy in to out
exit:
  int bufferLen = _tcslen(lpBuffer);
  // find the beginning of the filename part, lpFilePart must point to it
  if (lpFilePart) {
    *lpFilePart = lpBuffer;
    int i;
    for (i = bufferLen -1; i >= 0; i--)
      if (lpBuffer[i] == '\\' || lpBuffer[i] == '/' || lpBuffer[i] == ':') {
        *lpFilePart = lpBuffer + i + 1;
        break;
      }
  }
  return bufferLen;
}

DWORD
GetShortPathName(LPCSTR lpszLongPath, LPSTR lpszShortPath, DWORD cchBuffer)
{
  // use new MS-DOS long filename function x7160,1 - GetShortPathName
  _TCHAR destPath[WIN95_LONGFILENAME_MAX]; // defined at top of file
  _TCHAR const far* farLongPath = lpszLongPath;
  _TCHAR far* farDestPath = destPath;
  _asm {
    mov ax, 0x7160
    mov cl, 1                    // GetShortPathName
    mov ch, 0                    // return string contains path not SUBST drive
    lds si, farLongPath
    les di, farDestPath
    int 21h
    jc  error
  }
  _tcsncpy(lpszShortPath, destPath, (int)(cchBuffer - 1));
  goto exit;
error:
    _tcsncpy(lpszShortPath, lpszLongPath, (int)(cchBuffer - 1)); // just copy in to out
exit:
  return _tcslen(lpszShortPath);
}
#endif

//
// overloaded functions to perform string scanning
//
static const _TCHAR far* strend(const _TCHAR far* str)
{
  while (*str)
    str++;
  return str;
}

static const _TCHAR far* find(const _TCHAR far* start, const _TCHAR far* end, int match)
{
  while (*start != match && start != end)
    start++;
  return start;
}

static const _TCHAR far* find(const _TCHAR far* start, const _TCHAR far* end, const _TCHAR far* set)
{
  const _TCHAR far* setend = set + _tcslen(set);
  while (find(set, setend, *start) == setend && start != end)
    start++;
  return start;
}

static const _TCHAR far* findl(const _TCHAR far* start, const _TCHAR far* end, int match)
{
  while (*start != match && start != end)
    start--;
  return start;
}

static const _TCHAR far* findl(const _TCHAR far* start, const _TCHAR far* end, const _TCHAR far* set)
{
  const _TCHAR far* setend = set + _tcslen(set);
  while (find(set, setend, *start) == setend && start != end)
    start--;
  return start;
}

static const _TCHAR far* skipstr(const _TCHAR far* start, const _TCHAR far* end,
                               const _TCHAR far* skip)
{
  while (*skip && *start == *skip && start != end)
    start++, skip++;

  return start;
}

//-----
// Low level helper functions for parsing filename parts
//

//
//
//
static string formServer(const _TCHAR far* serverName)
{
  if (!serverName)
    return serverName;

  const _TCHAR far* serverNameEnd = strend(serverName);

  if (_tcsncmp(serverName, serverNamePrefix, serverNamePrefixLen) == 0)
    serverName += serverNamePrefixLen;               // skip "\\"

  const _TCHAR far* ds = find(serverName, serverNameEnd, dirSeparator);
  return string(serverName, 0, (int)(ds - serverName));
}

//
//
//
static string formDevice(const _TCHAR far* deviceName, bool isUNC)
{
  if (!deviceName)
    return deviceName;

  const _TCHAR far* deviceNameEnd = strend(deviceName);


  if (isUNC)
    deviceNameEnd = find(deviceName, deviceNameEnd, dirSeparator);
  else
    deviceNameEnd = find(deviceName, deviceNameEnd, ldevTerminator);

  return string(deviceName, 0, (int)(deviceNameEnd - deviceName));
}

//
// Return a well formed path from any kind of filename part. A lone name
// is assumed to be just the path
//
static string formPath(const _TCHAR far* path)
{
  if (!path)
    return path;

  const _TCHAR far* pathEnd = strend(path);

  // Find the start of the path, skipping logical device or server+share
  //
  const _TCHAR far* dvs = find(path, pathEnd, ldevTerminator);
  if (dvs < pathEnd) {
    path = dvs + 1;  // skip logical device
  }

  return string(path, 0, (int)(pathEnd - path));
}

//
// Return a well formed file from any kind of filename part. A lone name
// is assumed to be just the file
//
//   "dir.x\file.ext"  -> "file"
//   "dir.x\"          -> ""
//   "file"            -> "file"
//
static string formFile(const _TCHAR far* file)
{
  if (!file)
    return file;

  const _TCHAR far* fileEnd = strend(file);

  const _TCHAR far* ds = findl(fileEnd-1, file-1, dirSeparator);
  if (ds >= file)
    file = ds + 1;

  const _TCHAR far* es = findl(fileEnd-1, file-1, extSeparator);
  if (es >= file)
    fileEnd = es;

  return string(file, 0, (int)(fileEnd - file));
}

//
// Return a well formed extension from any kind of filename part. A lone name
// is assumed to be just the extension and a '.' is prepended
//
//   "dir.x\file.ext"  -> ".ext"
//   "dir.x\"          -> "."
//   "ext"             -> ".ext"
//
static string formExt(const _TCHAR far* ext)
{
  if (!ext)
    return ext;  // or extSeparator?

  const _TCHAR far* extEnd = strend(ext);

  const _TCHAR far* ds = findl(extEnd-1, ext-1, dirSeparator);
  if (ds >= ext)
    ext = ds + 1;

  const _TCHAR far* es = findl(extEnd-1, ext-1, extSeparator);
  if (es >= ext)
    return es;

  return string(extSeparator) + ext;
}

//----------------------------------------------------------------------------

//
//
//
TFileName::TFileName()
{
}

//
//
//
TFileName::TFileName(const TFileName& src)
:
  ServerStr(src.ServerStr),
  DeviceStr(src.DeviceStr),
  PathStr(src.PathStr),
  FileStr(src.FileStr),
  ExtStr(src.ExtStr),
  Unc(src.Unc)
{
}

//
// Construct a filename in the form:
//
//   filename := [[servername]devicename][path][file[ext]]
//
//  where:
//
//   servername := \\multiname\         //
//   devicename := name(: | \ | :\)
//   sharename := name
//   logicaldevice := name
//
//   path := multiname\[...]
//   file := multiname
//   ext := [.[name]]
//
//   name := (filecharset)[...]
//   multiname := (filecharset | .)[...]
//
TFileName::TFileName(const _TCHAR far* serverName, const _TCHAR far* deviceName,
                     const _TCHAR far* path, const _TCHAR far* file,
                     const _TCHAR far* ext)
{
  ServerStr = formServer(serverName);

  Unc = serverName != 0;

  DeviceStr = formDevice(deviceName, Unc);
  PathStr += formPath(path);
  FileStr += formFile(file);
  ExtStr += formExt(ext);
}

//
//
//
void
TFileName::Parse(const _TCHAR far* freeform)
{
  const _TCHAR far* nextp;
  const _TCHAR far* freeformEnd = strend(freeform);

  // Parse from the left, the server name and device if UNC "\\", or the
  // logical device name if one.
  //
  nextp = skipstr(freeform, freeformEnd, serverNamePrefix);
  if (nextp > freeform) {
    Unc = true;
    freeform = nextp;               // skip "\\"
    nextp = find(freeform, freeformEnd, dirSeparator);
    ServerStr = string(freeform, 0, (int)(nextp-freeform));
    freeform = nextp + 1;               // skip past "\"

    nextp = find(freeform, freeformEnd, dirSeparator);
    DeviceStr = string(freeform, 0, (int)(nextp-freeform));
    freeform = nextp + 1;               // skip past "\"
  }
  else {
    Unc = false;
    ServerStr = "";

    nextp = find(freeform, freeformEnd, ldevTerminator);
    if (nextp != freeformEnd) {
      DeviceStr = string(freeform, 0, (int)(nextp-freeform));
      freeform = nextp + 1;               // skip past "\/:"
    }
    else
      DeviceStr = "";
  }

  // Parse the extension and filename from the right.
  //
  nextp = findl(freeformEnd-1, freeform-1, extSeparator);
  const _TCHAR far* dirp = findl(freeformEnd-1, freeform-1, dirSeparator);

  if (nextp > dirp) {
    ExtStr = string(nextp, 0, (int)(freeformEnd-nextp));
    freeformEnd = nextp;
  }
  else
    ExtStr = "";

  FileStr = string(dirp+1, 0, (int)(freeformEnd - (dirp+1)));
  freeformEnd = dirp;

  // What is left is the path
  //
  if (freeformEnd > freeform)
    PathStr = string(freeform, 0, (int)(freeformEnd-freeform));
  else
    PathStr = "";
}

//
// Construct a filename given the full path in any form
//
TFileName::TFileName(const _TCHAR far* freeform)
{
  Parse(freeform);
}

//
// Construct a filename given the full path in any form
//
TFileName::TFileName(const string& freeform)
{
  Parse(freeform.c_str());
}

//
// Construct a special filename
//
TFileName::TFileName(TFileName::TSpecialType type)
{
  switch (type) {
#if defined(BI_PLAT_WIN32)
    case TempFile:
    case TempDir: {
      int tmpLen = ::GetTempPath(0,0);
      _TCHAR* tmpPath = new _TCHAR[tmpLen];
      ::GetTempPath(tmpLen, tmpPath);
      if (type == TempDir) {
        Parse(tmpPath);
      }
      else {
        _TCHAR tmpFile[WIN95_LONGFILENAME_MAX];
        ::GetTempFileName(tmpPath, "TFN", 0, tmpFile);

        Parse(tmpFile);
      }
      delete[] tmpPath;
    }
    break;
    case CurrentDir: {
      _TCHAR tmp[WIN95_LONGFILENAME_MAX];
      ::GetCurrentDirectory(sizeof tmp, tmp);

      Parse(tmp);
    }
    break;
#elif defined(BI_PLAT_WIN16)
    case TempFile:
    case TempDir: {
      _TCHAR tmpFile[WIN95_LONGFILENAME_MAX];
      ::GetTempFileName(0, "TFN", 0, tmpFile);

      Parse(tmpFile);
      if (type == TempDir) {
        // Strip off filename part...
        //
        FileStr = "";
        ExtStr = "";
      }
    }
    break;
    case CurrentDir: {
      _TCHAR tmp[WIN95_LONGFILENAME_MAX];
      _tgetcwd(tmp, sizeof tmp);

      Parse(tmp);
    }
    break;
#endif
    case HomeDir: {
      _TCHAR tmp[WIN95_LONGFILENAME_MAX];
      ::GetWindowsDirectory(tmp, sizeof tmp);

      Parse(tmp);
    }
    break;
    case BootDir:
    case MachineDir:
    case SharedDir:
    break;
    case SysDir: {
      _TCHAR tmp[WIN95_LONGFILENAME_MAX];
      ::GetSystemDirectory(tmp, sizeof tmp);
      Parse(tmp);
    }
    break;
#if defined(BI_PLAT_WIN32)
    case ComputerName: {
      _TCHAR tmp[WIN95_LONGFILENAME_MAX];
      uint32 size = sizeof tmp;
      ::GetComputerName(tmp, &size);
      Parse(tmp);
    }
    break;
#endif
  }
}

//
//
//
TFileName&
TFileName::operator =(const TFileName& src)
{
  Unc = src.Unc;
  ServerStr = src.ServerStr;
  DeviceStr = src.DeviceStr;
  PathStr = src.PathStr;
  FileStr = src.FileStr;
  ExtStr = src.ExtStr;
  return *this;
}

//
//
//
static void
ForceFullPath(string canonical)
{
  _TCHAR buffer[WIN95_LONGFILENAME_MAX];
  ::GetFullPathName(canonical.c_str(), sizeof buffer, buffer, 0);
  canonical = buffer;
}

//
// Reassemble the filename parts into a canonical form & expand any relative
// dirs
//
string
TFileName::Canonical(bool forceUNC) const
{
  string canonical;

  if (forceUNC)
    canonical = string(serverNamePrefix) + DeviceStr
        + dirSeparatorCh + PathStr + dirSeparatorCh + FileStr + ExtStr;
  else
    canonical = GetParts(Server|Device|Path|File|Ext);

  ForceFullPath(canonical);

  return canonical;
}

//
//
//
string
TFileName::ShortName(bool forceUNC) const
{
  _TCHAR tmp[WIN95_LONGFILENAME_MAX];
  ::GetShortPathName(Canonical(forceUNC).c_str(), tmp, sizeof tmp);

  return string(tmp);
}

//
// Human readable form of the filename appropriate for use in titles
//
string TFileName::Title() const
{
  string canonical = Canonical();
  _TCHAR tmp[WIN95_LONGFILENAME_MAX];
  ::GetFileTitle(canonical.c_str(), tmp, sizeof tmp);

  return string(tmp);
}

//
// Human readable form of the filename squeezed to fit in 'maxLen' chars
//
string TFileName::Squeezed(int maxLen) const
{
  // Try subsequently smaller sets of parts until it fits into maxLen chars
  //
  static uint parts[] = {
    Server | Device | Path | File | Ext,  // Whole thing
    Server | Device | File | Ext,         
    File | Ext,
    File,
  };
  for (int i = 0; i < sizeof parts / sizeof parts[0]; i++) {
    string attempt = GetParts(parts[i]);
    if (attempt.length() <= (uint)maxLen) {
      return attempt;
    }
  }
  return "";
}

//
//
//
bool
TFileName::IsValid() const
{
  OFSTRUCT ofs;
  ofs.cBytes = sizeof ofs;
  return ::OpenFile(Canonical().c_str(), &ofs, OF_PARSE) != -1;
}

//
//
//
bool
TFileName::Exists() const
{
  OFSTRUCT ofs;
  ofs.cBytes = sizeof ofs;
  return ::OpenFile(Canonical().c_str(), &ofs, OF_EXIST) != -1;
}


//
// Reassemble any logical subset of filename parts
//
string
TFileName::GetParts(uint p) const
{
  string part;

  if (Unc) {
    if (p & Server) {
      part += serverNamePrefix;
      part += ServerStr;
      if (p & Device)
        part += dirSeparatorCh;
    }
    if ((p & Device) && DeviceStr.length() > 0) {
      part += DeviceStr;
      if ((p & Path) || (p & File))
        part += dirSeparatorCh;
    }
  }
  else {
    if ((p & Device) && DeviceStr.length() > 0) {
      part += DeviceStr;
      part += ldevTerminator;
    }
  }

  if ((p & Path) && PathStr.length() > 0)
    part += PathStr + dirSeparatorCh;

  if ((p & File) && FileStr.length() > 0)
    part += FileStr;

  if ((p & Ext) && ExtStr.length() > 0)
    part += ExtStr;

  return part;
}

//
//
//
bool
TFileName::HasParts(uint p) const
{
  bool has = false;
  if (p & Server)
    has |= ServerStr.length() > 0;
  if (p & Device)
    has |= DeviceStr.length() > 0;
  if (p & Path)
    has |= PathStr.length() > 0;
  if (p & File)
    has |= FileStr.length() > 0;
  if (p & Ext)
    has |= ExtStr.length() > 0;
  return has;
}

//
//
//
void
TFileName::SetPart(uint p, const string& partStr)
{
  if (p & Server)
    ServerStr = partStr;
  if (p & Device)
    DeviceStr = partStr;
  if (p & Path)
    PathStr = partStr;
  if (p & File)
    FileStr = partStr;
  if (p & Ext)
    ExtStr = partStr;
}

//
//
//
void
TFileName::MergeParts(uint p, const TFileName& source)
{
  // Walk thru bits & SetPart(p) from source.GetParts(p)
  //
  if (p & Server)
    ServerStr = source.GetParts(Server);
  if (p & Device)
    DeviceStr = source.GetParts(Device);
  if (p & Path)
    PathStr = source.GetParts(Path);
  if (p & File)
    FileStr = source.GetParts(File);
  if (p & Ext)
    ExtStr = source.GetParts(Ext);
}

//
//
//
void
TFileName::StripParts(uint p)
{
  if (p & Server)
    ServerStr = "";
  if (p & Device)
    DeviceStr = "";
  if (p & Path)
    PathStr = "";
  if (p & File)
    FileStr = "";
  if (p & Ext)
    ExtStr = "";
}

//----------------------------------------------------------------------------

//
//
//
void
TFileName::Remove() const
{
#if defined(BI_PLAT_WIN32)
  if (!::DeleteFile(Canonical().c_str()))
    ::RemoveDirectory(Canonical().c_str());
#else
  if (_tremove(Canonical().c_str()) != 0)
    _trmdir(Canonical().c_str());
#endif
}

//
//
//
void
#if defined(BI_PLAT_WIN32)
TFileName::Move(const TFileName& newName, uint32 how)
#else
TFileName::Move(const TFileName& newName, uint32 /*how*/)
#endif
{
#if defined(BI_PLAT_WIN32)
  //
  // Contrary to the help\MSDN MoveFileEx fails under Win95. (as of 2/97)
  //
  bool retval = false;
  if( !TSystem::IsWin95() )
    retval = ::MoveFileEx(Canonical().c_str(), newName.Canonical().c_str(), how);
  else
    retval = ::MoveFile(Canonical().c_str(), newName.Canonical().c_str());

  if(retval)
   *this = newName;
#else
  _trename(Canonical().c_str(), newName.Canonical().c_str());
#endif
}

//
//
//
void
TFileName::Copy(const TFileName& newName, bool failIfExists) const
{
#if defined(BI_PLAT_WIN32)
  ::CopyFile(Canonical().c_str(), newName.Canonical().c_str(), failIfExists);
#else
  FILE *in;
  FILE *out;
  _TCHAR c;

  if (failIfExists) {
    out = _tfopen(newName.Canonical().c_str(), "r");
    if (!out)
      return;
    fclose(out);
  }

  out = _tfopen(newName.Canonical().c_str(), "w");
  if (!out)
    return;
  in = _tfopen(Canonical().c_str(), "r");
  if (!in) {
    fclose(out);
    return;
  }

  while ((c = _gettc(in)) != 0) // != 0 part to get by compiler warning
    _puttc(c, out);

  fclose(in);
  fclose(out);
#endif
}

//
//
//
int
TFileName::CreateDir() const
{
#if defined(BI_PLAT_WIN32)
  return ::CreateDirectory(Canonical().c_str(), 0);  //LPSECURITY_ATTRIBUTES
/*
BOOL CreateDirectoryEx(
    LPCTSTR  lpTemplateDirectory, // pointer to path string of template directory
    LPCTSTR  lpNewDirectory,  // pointer to path string of directory to create
    LPSECURITY_ATTRIBUTES  lpSecurityAttributes // pointer to security descriptor
   );
*/
#else
  return _tmkdir(Canonical().c_str()) == 0;
#endif
}

//
//
//
int
TFileName::ChangeDir() const
{
#if defined(BI_PLAT_WIN32)
  return ::SetCurrentDirectory(Canonical().c_str());
#else
  return _tchdir(Canonical().c_str()) == 0;
#endif
}

//----------------------------------------------------------------------------

TFileNameIterator::TFileNameIterator(const string& wildName)
:
#if defined(BI_PLAT_WIN32)
  Handle(::FindFirstFile(wildName.c_str(), &Data)),
#endif
  Done(false)
{
#if !defined(BI_PLAT_WIN32)
  Done = _tfindfirst(wildName.c_str(), &Data, 0x3F) < 0;  // All attributes
#endif
}

TFileNameIterator::~TFileNameIterator()
{
#if defined(BI_PLAT_WIN32)
  if (Handle != INVALID_HANDLE_VALUE)
    ::FindClose(Handle);
#endif
}

#if defined(BI_PLAT_WIN32)
const WIN32_FIND_DATA&
TFileNameIterator::operator ++()
{
  if (!::FindNextFile(Handle, &Data))
    Done = true;
  return Data;
}
#else

const ffblk&
TFileNameIterator::operator ++()
{
  if (::_tfindnext(&Data) < 0)
    Done = true;
  return Data;
}
#endif
