//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1993, 1994 by Borland International, All Rights Reserved
//
//   Implements classes TFileDocument, TFileInStream, TFileOutStream, TFileBuf
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl/owlpch.h>
#include <owl/filedoc.h>

#if !defined(SECTION) || SECTION == 1

//
//  class TFileBuf
//  ----- --------
//
class _OWLCLASS_RTL TFileBuf : public streambuf {
  public:
    enum { shDefault = shReadWrite };  // default file sharing

    TFileBuf(int fhdl, int omode, streampos seekpos);
   ~TFileBuf() {}

    virtual int overflow(int = EOF);
    virtual int underflow();
    virtual int sync();
    virtual streampos  seekoff(streamoff, ios::seek_dir, int);

    int       xfd;       // the file descriptor, EOF if closed
    int       mode;      // the opened mode
    streampos last_seek;
    char      lahead[2]; // current input char if unbuffered
};

//
//  class TFileStreamBase
//  ----- ---------------
//
class _OWLCLASS_RTL TFileStreamBase : virtual public ios {
  public:
    TFileStreamBase(int fhdl, int omode, streampos seekpos);
   ~TFileStreamBase() {}
    TFileBuf buf;
};

//
//  class TFileInStream
//  ----- -------------
//
class _OWLCLASS_RTL TFileInStream : public TFileStreamBase, public TInStream {
  public:
    TFileInStream(TFileDocument& doc, HFILE fhdl, int omode, streampos seekpos)
               : TInStream (doc,0,omode), TFileStreamBase(fhdl,omode,seekpos){}
   ~TFileInStream();
};

//
//  class TFileOutStream
//  ----- --------------
//
class _OWLCLASS_RTL TFileOutStream : public TFileStreamBase, public TOutStream {
  public:
    TFileOutStream(TFileDocument& doc, HFILE fhdl, int omode, streampos seekpos)
              : TOutStream (doc,0,omode), TFileStreamBase(fhdl,omode,seekpos){}
   ~TFileOutStream();
};

//
//  class TFileDocument
//  ----- -------------
//

HFILE
TFileDocument::OpenThisFile(int omode, const char far* name, streampos* pseekpos){
  int how;
  HFILE fhdl;
  bool exists = false;
  int share = omode & shMask;

  if (share < shCompat)
    share = (omode & ofWrite) ? shRead : shReadWrite;

  how = ((unsigned)(share-shCompat)) >> 5;

  if (omode & ofWrite) {
    if (!(omode & (ofAtEnd | ofAppend | ofRead)))
      omode |= ofTruncate; // output implies truncate unless in, app, or ate

    if (omode & ofRead)
      how |= OF_READWRITE;
    else
      how |= OF_WRITE;
    if (!((omode & ofNoCreate) && !(omode & ofTruncate))) {
      if (!((omode & ofTruncate) && !(omode & (ofNoCreate | ofNoReplace)))) {
        if ((fhdl=::_lopen(name,OF_READ|OF_SHARE_COMPAT))   !=HFILE_ERROR
        ||  (fhdl=::_lopen(name,OF_READ|OF_SHARE_DENY_NONE))!=HFILE_ERROR) {
          ::_lclose(fhdl);
          exists = true;
          }
        }
      if (!(exists && !(omode & (ofNoCreate | ofNoReplace)))) {
        if ((exists && (omode & ofNoReplace))
        || (!exists && (omode & ofNoCreate)) )
            return 0;
        if ((fhdl = _lcreat(name, 0)) == HFILE_ERROR)
            return HFILE_ERROR;
        ::_lclose(fhdl);   // close in order to open with share mode
        }
      }
    }
  else if (omode & ofRead)
    how |= OF_READ;
  else
    return HFILE_ERROR;   // must specfify in, out, or in/out

  if ((fhdl = ::_lopen(name, how)) != HFILE_ERROR) {
    if ((*pseekpos = ::_llseek(fhdl, 0L, (omode & (ofAtEnd|ofAppend))
                             ? SEEK_END : SEEK_SET)) == long(HFILE_ERROR)) {
      ::_lclose(fhdl);
      return HFILE_ERROR;
    }
  }
#if defined(BI_PLAT_WIN32)
  FileLength = GetFileSize((HANDLE)fhdl, 0);
  InfoPresent = GetFileTime((HANDLE)fhdl, &FileCreateTime, &FileAccessTime,
                            &FileUpdateTime);
#else
  FileLength = filelength(fhdl);
  getftime(fhdl, (struct ftime*)&FileTime);
  InfoPresent = true;
#endif
  NotifyViews(vnDocOpened,omode);
  return fhdl;
}

void
TFileDocument::CloseThisFile(HFILE fhdl, int omode)
{
  if (!IS_PREV_OPEN(omode)) {
    ::_lclose(fhdl);
    NotifyViews(vnDocClosed, omode);
  }
}

bool
TFileDocument::Open(int omode, const char far* path)
{
  long seekpos;
  if (FHdl != HFILE_ERROR)
    return false;    // if already open at document level
  if (path)
    SetDocPath(path);
  if (omode != 0)
    SetOpenMode(omode);
  if ((FHdl = OpenThisFile(GetOpenMode(),GetDocPath(),&seekpos)) == HFILE_ERROR)
    return false;
  return true;
}

bool
TFileDocument::Open(HFILE fhdl)
{
  SetOpenMode(PREV_OPEN | ofReadWrite);  // can we determine open mode?
  SetDocPath(0); // can we get path name?
  FHdl = fhdl;
  return true;
}

bool
TFileDocument::Close()
{
  if (!TDocument::Close())     // close all children first
    return false;
  if (FHdl != HFILE_ERROR) {   // if open at document level
    if (TDocument::IsOpen())   // cannot close document if streams open
      return false;       // ?should we close streams here?
    CloseThisFile(FHdl, GetOpenMode());
    FHdl = HFILE_ERROR;
  }
  return true;
}

bool
TFileDocument::Commit(bool force)
{
  if (!TDocument::Commit(force))      // flush views and child docs
    return false;
  SetDirty(false);
  return true;
}

bool
TFileDocument::Revert(bool clear)
{
  if (!TDocument::Revert(clear))
    return false;
  SetDirty(false);
  return true;
}

static char* PropNames[] = {
  "Create Time",   // CreateTime 
  "Modify Time",   // ModifyTime
  "Access Time",   // AccessTime
  "Storage Size",  // StorageSize
  "File Handle",   // FileHandle
};

static int PropFlags[] = {
  pfGetBinary|pfGetText,   // CreateTime 
  pfGetBinary|pfGetText,   // ModifyTime
  pfGetBinary|pfGetText,   // AccessTime
  pfGetBinary|pfGetText,   // StorageSize
  pfGetBinary,             // FileHandle
};

const char*
TFileDocument::PropertyName(int index)
{
  if (index <= PrevProperty)
    return TDocument::PropertyName(index);
  else if (index < NextProperty)
    return PropNames[index-PrevProperty-1];
  else
    return 0;
}

int
TFileDocument::PropertyFlags(int index)
{
  if (index <= PrevProperty)
    return TDocument::PropertyFlags(index);
  else if (index < NextProperty)
    return PropFlags[index-PrevProperty-1];
  else
    return 0;
}

int
TFileDocument::FindProperty(const char far* name)
{
  int i;
  for (i=0; i < NextProperty-PrevProperty-1; i++)
    if (strcmp(PropNames[i], name) == 0)
      return i+PrevProperty+1;
  return TDocument::FindProperty(name);
}

int
TFileDocument::GetProperty(int prop, void far* dest, int textlen)
{
  switch(prop) {
    case FileHandle:
      if (textlen)
        return 0;
      *(HFILE FAR*)dest = FHdl;
      return sizeof(FHdl);
    default:
      if (InfoPresent) {
        switch(prop) {
          case StorageSize:
            if (!textlen) {
              *(unsigned long FAR*)dest = FileLength;
              return sizeof(FileLength);
            }
            else {
              char buf[10];
              int len = wsprintf(buf, "%ld", FileLength);
              if (textlen > len)
                textlen = len;
              memcpy(dest, buf, textlen);
              *((char far*)dest + textlen) = 0;
              return len;
            }
#if defined(BI_PLAT_WIN32)
          case CreateTime:
            return FormatFileTime(&FileCreateTime, dest, textlen);
          case ModifyTime:
            return FormatFileTime(&FileUpdateTime, dest, textlen);
          case AccessTime:
            return FormatFileTime(&FileAccessTime, dest, textlen);

#else  // DOS file system
          case CreateTime:
          case ModifyTime:
          case AccessTime: {
            struct date  propdate;
            struct time  proptime;
            propdate.da_year = ((struct ftime*)&FileTime)->ft_year+1980;
            propdate.da_mon  = ((struct ftime*)&FileTime)->ft_month;
            propdate.da_day  = ((struct ftime*)&FileTime)->ft_day;
            proptime.ti_hour = ((struct ftime*)&FileTime)->ft_hour;
            proptime.ti_min  = ((struct ftime*)&FileTime)->ft_min;
            proptime.ti_sec  = ((struct ftime*)&FileTime)->ft_tsec*2;
            proptime.ti_hund = 0;
            return FormatDateTime(propdate, proptime, dest, textlen);
          }
#endif
        }
      }
      return TDocument::GetProperty(prop, dest, textlen);
  }
}

bool
TFileDocument::SetProperty(int prop, const void far* src)
{
  // File properties currently not settable
  //
  return TDocument::SetProperty(prop, src);
}

TInStream*
TFileDocument::InStream(int omode, const char far* /*strmId*/) 
{
  HFILE fhdl;
  streampos seekpos;
  if (omode == ofParent)
    omode = GetOpenMode();
  if (!(omode & ofRead))
    return 0;
  if ((fhdl = FHdl) == HFILE_ERROR) {   // if file not open at document level
    if ((fhdl=OpenThisFile (omode, GetDocPath(), &seekpos)) == HFILE_ERROR)
      return 0;
  }
  else {
    omode = GetOpenMode() ? (GetOpenMode() & ~ofBinary) | (omode & ofBinary)
                          : omode;
    omode |= PREV_OPEN;
  }
  return new TFileInStream(*this, fhdl, omode, seekpos);
}

TOutStream*
TFileDocument::OutStream(int omode, const char far* /*strmId*/)
{
  HFILE fhdl;
  streampos seekpos;
  if (omode == ofParent)
    omode = GetOpenMode();
  if (!(omode & ofWrite))
    return 0;
  if ((fhdl = FHdl) == HFILE_ERROR) {   // if file not open at document level
    if ((fhdl=OpenThisFile (omode, GetDocPath(), &seekpos)) == HFILE_ERROR)
      return 0;
  }
  else {
    omode = GetOpenMode() ? (GetOpenMode() & ~ofBinary) | (omode & ofBinary)
                          : omode;
    omode |= PREV_OPEN;
  }
  return new TFileOutStream(*this, fhdl, omode, seekpos);
}

TFileInStream::~TFileInStream()
{
  ((TFileDocument&)Doc).CloseThisFile(buf.xfd, GetOpenMode());
}

TFileOutStream::~TFileOutStream()
{
  if (buf.out_waiting())
    buf.overflow(EOF);
  ((TFileDocument&)Doc).CloseThisFile(buf.xfd, GetOpenMode());
}

//
//  class TFileBuf
//  ----- --------
//
const int B_size = 516; // natural size for a file buffer, plus 4 for putback

// make a TFileBuf attached to an open fd

TFileBuf::TFileBuf(int fhdl, int omode, long seekpos)
{
  xfd = fhdl;     // assumed to be valid
  mode = omode;   // this may not represent the actual mode opened previously
  last_seek = seekpos;
  char* p = new char[B_size];
  if (p) {
    setb(p, p+B_size, 1);   // ~streambuf() will delete buffer
    setp(p+4, p+4);
    setg(p, p+4, p+4);
  }
}

// Seek file to position.
// We take a simple approach, and don't check for small position changes
// within the current buffer.

streampos TFileBuf::seekoff(streamoff off, ios::seek_dir dir, int /*mode*/)
{
  long loff = off;
  if (out_waiting()) {       // flush the output
    if (sync() == EOF)
        return EOF;
  }
  else if (dir == ios::cur) {
    int count = in_avail();
    if (count != 0) {
      loff -= count;

      //  if we're in text mode, need to allow for newlines
      //  in the buffer
      if ((mode & ofBinary) == 0) {
        char *tptr = gptr();
        while (tptr != egptr())
          if (*tptr++ == '\n')
            loff--;
      }
    }
  }
  int w = (dir==ios::beg) ? SEEK_SET : ((dir==ios::cur) ? SEEK_CUR:SEEK_END);
  last_seek = ::_llseek(xfd, loff, w);
  if (!unbuffered() && base()) {      // set up get and put areas
    int pb = (blen() > 8) ? 4 : 1;  // putback area size
    char *b = base();
    setp(b+pb, b+pb);
    setg(b, b+pb, b+pb);
  }
  return (last_seek == long(HFILE_ERROR)) ? EOF : last_seek;
}

int TFileBuf::sync()
{
  int count = out_waiting();
  if (count) {
    char* curp;
    char* srcp = pbase();
    char* endp = srcp + count;

    // Convert LF's to CR/LF if text mode
    //
    if ((mode & ofBinary) == 0) {
      for (curp = srcp; curp < endp; curp++) {
        if (*curp == '\n') {
          *curp = '\r';
          count = (int)(curp - srcp) + 1;
          if (::_lwrite(xfd, srcp, count) != count)
            return EOF;
          *(srcp = curp) = '\n';
        }
      }
      count = (int)(curp - srcp);  // write what remains in the buffer below
    }
    if (::_lwrite(xfd, srcp, count) != count)
      return EOF;

    // reset get and put areas
    int pb = (blen() > 8) ? 4 : 1;  // putback area size
    char *b = base();
    setp(b+pb, b+blen());
    setg(b, b+pb, b+pb);
  }
  else if (in_avail()) {
    last_seek = ::_llseek(xfd, long(-in_avail()), SEEK_CUR);
    setg(eback(), gptr(), gptr());
    setp(gptr(), gptr());
    if (last_seek == long(HFILE_ERROR))
      return EOF;
  }
  return 0;
}

int TFileBuf::underflow()
{
  if ((mode & (ofRead | ofWrite)) == ofWrite)
    return EOF;

  if (in_avail())    // no action needed
    return (unsigned char) *gptr();

  int c = 0;  // the return value
  int count;  // input character count

  if (!unbuffered() && base()) {     // this is buffered
    if (sync() != 0)
      return EOF;

    // find buffer data
    int pb = (blen() > 8) ? 4 : 1;  // putback area size
    char* begp = base() + pb;

    // read in a new buffer
    count = ::_lread(xfd, begp, blen()-pb);
    if (count == HFILE_ERROR)
      return EOF;

    // remove CR's if text mode
    if ((mode & ofBinary) == 0) {
      char* endp = begp + count;
      char* dstp = 0;
      char* srcp = 0; // initialized only to prevent compiler warning
      char* curp;

      for (curp = begp;  curp < endp; curp++) {
        if (*curp == '\r') {
          if (dstp) {
            memcpy(dstp, srcp, (int)(curp - srcp));
            dstp += (int)(curp - srcp);
          }
          else
            dstp = curp;
          srcp = curp + 1;
        }
      }
      if (dstp) {
        endp = dstp + (int)(curp - srcp);
        if (curp != srcp)
          memcpy(dstp, srcp, (int)(curp - srcp));
      }
      count = (int)(endp - begp);
    }
    // set up get and put areas
    setg(base(), begp, begp + count);
    setp(begp, begp);

    if (count)
      c = (unsigned char) *gptr();
  }
  else {     // this is not buffered
    for (;;) {
      count = ::_lread(xfd, lahead, 1);
      if (count == HFILE_ERROR) {
        c = EOF;
        setg(0, 0, 0);
      }
      else {
        c = (unsigned char)lahead[0];
        if ((mode & ofBinary) == 0  && c == '\r')
          continue;
        setg(lahead, lahead, lahead+1);
      }
      break;
    }
  }
  if (!count)
    c = EOF;    // end of file
  return c;
}

// always flush

int TFileBuf::overflow(int c)
{
  if ((mode & (ofRead | ofWrite)) == ofRead)
    return EOF;

  if (unbuffered() || !base()) {
    if (c != EOF) {
      int count;
      char b[2];
      if (c == '\n' && (mode & ofBinary) == 0) {
        b[0] = '\r';
        b[1] = (char)c;
        count = 2;
      }
      else {
        b[0] = (char)c;
        count = 1;
      }
      if (::_lwrite(xfd, b, count) != count)
        return EOF;
    }
  }
  else {   // now we know this is buffered and state is not bad

    // resets get and put areas
    if (sync() != 0)
      return EOF;

    // reset get and put areas
    int pb = (blen() > 8) ? 4 : 1;  // putback area size
    char *b = base();
    setp(b+pb, b+blen());
    setg(b, b+pb, b+pb);

    if (c != EOF) {
      sputc(c);
      gbump(1);       // pptr and gptr must be the same
    }
  }
  return 1;
}

//
//  class TFileStreamBase
//  ----- ---------------
//

TFileStreamBase::TFileStreamBase(int fhdl, int omode, streampos seekpos)
                : buf(fhdl, omode, seekpos)
{
  ios::init(&buf);
}

#endif

#if !defined(SECTION) || SECTION == 2

IMPLEMENT_STREAMABLE1(TFileDocument, TDocument);

void*
TFileDocument::Streamer::Read(ipstream& is, uint32 /*version*/) const
{
  TFileDocument* o = GetObject();
  o->FHdl = HFILE_ERROR;    // initialize to closed file
  o->InfoPresent = false;
  ReadBaseObject((TDocument*)o, is);
  return o;
}

void
TFileDocument::Streamer::Write(opstream& os) const
{
  //  assumed that document is committed at this point
  WriteBaseObject((TDocument*)GetObject(), os);
}

#endif
