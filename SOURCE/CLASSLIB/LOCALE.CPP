//----------------------------------------------------------------------------
// Borland WinSys Library
// Copyright (c) 1994, 1996 by Borland International, All Rights Reserved
//
//$Revision:   5.7  $
//
// TLocaleString implementation - localized name support
// TRegList implementation - runtime component and object registration list
// TRegItem implementation - runtime component and object registration item
//
// NOTE: This code must reside in the same module that the strings are defined
//       The cache, NativeLangId, HINSTANCE are managed on a per-module basis
//       TLocaleString::NativeLangId may be user-implemented to symbol langid
//       TLocaleString::Module may be reset from this to another resource DLL
//----------------------------------------------------------------------------
#include <winsys/pch.h>
#include <winsys/lclstrng.h>
#include <winsys/wsysinc.h>  // just for _hInstance
#include <stdio.h>

//----------------------------------------------------------------------------
// Module global default values - except for TLocaleString::NativeLangId
//
TLangId TLocaleString::SystemDefaultLangId = TLocaleString::GetSystemLangId();
TLangId TLocaleString::UserDefaultLangId   = TLocaleString::GetUserLangId();
HINSTANCE TLocaleString::Module = _hInstance;
TLocaleString TLocaleString::Null = {""};

//----------------------------------------------------------------------------
// TLocaleCache definitions, private for implementation
//

#define AUTOLANG_CACHEDNEUT 0x02 // prefix indicates cache entry with neutral
#define AUTOLANG_CACHEDLOAD 0x01 // prefix indicates Neutral is not a string
const TLangId InvalidLangId = 0xFFFF;

struct TLocaleCache;
struct TLocaleCacheBase;

//
// Static object to hold destructable pointer
//
struct TLocaleCacheList {
  TLocaleCacheList() : Next(0) {}
 ~TLocaleCacheList();                     // releases cache entries
  TLocaleCache* Lookup(const char* name); // returns cache entry, 0 if failed
  TLocaleCacheBase* Next;                 // linked list of cached translations
};

//
// This base struct is used to cache failure to find language resource
//
struct TLocaleCacheBase {
  long  Hash;            // hashed original string, for duplicate elimination
  const char* Neutral;   // original string, +1 if resource found and loaded
  TLocaleCacheBase* Next;// linked list of cached strings, for search, cleanup

  TLocaleCacheBase(const char* name, long hash);
  static TLocaleCacheList CacheList;
};

//
// Buffer follows this header, sized for maximum string + null term.
//
struct TLocaleCache : public TLocaleCacheBase {
  void* operator new(unsigned size, unsigned buflen);
  TLocaleCache(const char* name, long hash, HRSRC rscHdl, HGLOBAL resData);
 ~TLocaleCache() {}
  const char* Translate(TLangId lang);   // (re)translate string

  TLangId ActLangId;   // actual language ID of cached string
  TLangId ReqLangId;   // requested language ID of cached string
  HRSRC   ResHdl;      // handle returned from ::FindResource()
  char    Buf[1];      // first character is string type
};

//----------------------------------------------------------------------------
// TLocaleCache implementation
//

TLocaleCacheBase::TLocaleCacheBase(const char* name, long hash)
:
  Neutral(name),
  Hash(hash)
{
  Next = CacheList.Next;
  CacheList.Next = this;
}

void* TLocaleCache::operator new(unsigned size, unsigned buflen)
{
  return ::operator new(size+buflen);
}

TLocaleCache::TLocaleCache(const char* name, long hash,
                           HRSRC resHdl, HGLOBAL resData)
:
  TLocaleCacheBase(name, hash),
  ResHdl(resHdl)
{
  ReqLangId = ActLangId = InvalidLangId;     // indicate initializing state
  *(HGLOBAL*)(Buf+1) = resData;   // store resource pointer temp in buffer
}

TLocaleCache* TLocaleCacheList::Lookup(const char* name)
{
  const char* neut = name + 1;      // skip over prefix flag char
  long hash = 0;
  const char* pc = name;
  while (*pc)
    hash = hash*2 ^ *pc++;
  for (TLocaleCacheBase* entry = Next; entry; entry = entry->Next) {
    if (hash == entry->Hash) {
      const char* pc = entry->Neutral;
      if (*pc != *neut)       // Neutral points to prefix if lookup failed
        pc++;
      if (TLocaleString::CompareLang(pc,neut,TLocaleString::NativeLangId) != 0)
        return  pc == entry->Neutral ? (TLocaleCache*)entry : 0;
    }
  }
  pc = name;
  if (*name != AUTOLANG_RCID)
    pc++;                    // '#' part of Id
  HRSRC resHdl = ::FindResource(TLocaleString::Module, pc, RT_LOCALIZATION);
  if (!resHdl) {
    new TLocaleCacheBase(name, hash);    // add cache entry for failed lookup
    return 0;
  }
  HGLOBAL resData = ::LoadResource(TLocaleString::Module, resHdl);
  if (!resData) {
    return 0;     // should throw exception on failure?!!
  }
  unsigned char far* pr = (unsigned char far*)::LockResource(resData);
  int maxLen = sizeof(HGLOBAL);  // scan for longest string, including null
  unsigned char c = *pr;         // check first byte of langid or neutral text
  if (c == 0) {                  // check for empty resource string
    ::FreeResource(resData);
    new TLocaleCacheBase(name, hash); // add failed cache entry if null or err
    return 0;
  }
  if (c >= ' ')                  // check for unprefixed neutral string first
    pr--;                        // cancel ++ in for loop initialization
  else
    pr++;                        // start to skip over 2-byte language id
  do {                           // loop to check for maximum string length
    unsigned char far* p = ++pr; // skip over id to start of translation
    while ((c=*pr++) >= ' ') ;   // skip over translation string
    if ((int)(pr-p) > maxLen)    // update maximum, including terminator
      maxLen = (int)(pr-p);
  } while(c);
  TLocaleCache* cache = new(maxLen) TLocaleCache(neut, hash, resHdl, resData);
  cache->Buf[0] = char(*name == AUTOLANG_XLAT ? AUTOLANG_CACHEDNEUT
                                              : AUTOLANG_CACHEDLOAD);
  return cache;
}

const char* TLocaleCache::Translate(TLangId reqLang)
{
  HGLOBAL resData;
  if (ReqLangId == InvalidLangId) { // if first time called after construction
    resData = *(HGLOBAL*)(Buf+1);
    ReqLangId = reqLang;
  }
  else {
    if (Buf[0]==AUTOLANG_CACHEDNEUT && TLocaleString::IsNativeLangId(reqLang))
      return Neutral;
    if (reqLang == ActLangId)
      return Buf+1;
    if (reqLang == ReqLangId) {
      if (ActLangId != InvalidLangId)
        return Buf+1;
      else if (Buf[0] == AUTOLANG_CACHEDNEUT)
        return Neutral;
      else
        return 0;
    }
    if ((resData = ::LoadResource(TLocaleString::Module, ResHdl)) == 0)
      return Neutral;   // should throw exception on failure?!!
  }

  unsigned char far* resBuf = (unsigned char far*)::LockResource(resData);
  unsigned char far* translation = 0;
  unsigned char far* pr = resBuf;
  TLangId            actLang = InvalidLangId;
  TLangId            resLang;
  unsigned char c;

  while ((c = *pr) != 0) {
    if (c > ' ') { // check for initial neutral string, used with CACHEDLOAD
      actLang = resLang = TLocaleString::NativeLangId;
      translation = pr;    // lowest preference match
    }
    else {
      resLang = TLangId(((c - 1)<<10) | *++pr);
      pr++;
    }
    if (resLang == reqLang) {     // exact match
      translation = pr;
      actLang = resLang;
      break;
    }
    if ((char)resLang == (char)reqLang) {   // base language match
      if ((char)actLang != (char)reqLang || resLang == (reqLang & 0x00FF)) {
        translation = pr;
        actLang = resLang;
      }
    }
    for ( ; *pr >= ' '; ++pr)   // skip over translation string till next Id
      ;
  }
  const char* retVal;
  if (translation) {
    while (*translation < ' ')    // skip over multiple language IDs
      translation += 2;
    if (actLang != ActLangId) {   // if same as in buffer, leave alone
      char* pc;
      for (pr = translation, pc = Buf + 1; *pr >= ' '; )
        *pc++ = *pr++;
      *pc = 0;
      ActLangId = actLang;
      if (reqLang != ActLangId)
        ReqLangId = reqLang;
    }
    retVal = Buf+1;
  }
  else if (Buf[0] == AUTOLANG_CACHEDNEUT) {
    retVal = Neutral;
  }
  else {
    retVal = 0;
  }
  ::FreeResource(resData);
  return retVal;
}

TLocaleCacheList TLocaleCacheBase::CacheList;  // declare module-global cache

TLocaleCacheList::~TLocaleCacheList()
{
  while (Next) {
    TLocaleCacheBase* p = Next;
    Next = Next->Next;
    delete p;
  }
}

//----------------------------------------------------------------------------
// TLocaleString implementation, except for static int CompareLang(s1,s2,lang)
//

const char* TLocaleString::Translate(TLangId reqLang)
{
  if (!Private)                   // check for null string pointer
    return Private;

  if (reqLang == LangNeutral)
    reqLang = NativeLangId;
  else if (reqLang == LangSysDefault)
    reqLang = SystemDefaultLangId;
  else if (reqLang == LangUserDefault)
    reqLang = UserDefaultLangId;

  TLocaleCache* cache;
  switch (Private[0])
  {
    default:                      // untranslatable string, no prefix
      return Private;

    case AUTOLANG_XLAT:           // not yet translated
      if (IsNativeLangId(reqLang))
        return Private+1;         // resource name IS neutral or default name
      if ((cache = TLocaleCacheBase::CacheList.Lookup(Private)) == 0)
        return ++Private;         // permanently bump pointer to make constant
      Private = cache->Buf;       // point to buffer in cache
      return cache->Translate(reqLang);

    case AUTOLANG_LOAD:           // named resource not accessed yet
    case AUTOLANG_RCID:           // numeric resource not accessed yet
      if ((cache = TLocaleCacheBase::CacheList.Lookup(Private)) == 0)
        return (Private = 0);     // permanently set pointer to null
      Private = cache->Buf;       // point to buffer in cache
      return cache->Translate(reqLang);

    case AUTOLANG_CACHEDNEUT:     // string in cache with neutral pointer
    case AUTOLANG_CACHEDLOAD:     // string in cache with no neutral pointer
      cache = (TLocaleCache*)(Private+1) - 1;   // backup to point to header
      return cache->Translate(reqLang);
  }
}

TLocaleString::operator const char*()
{
  if (Private == 0)
    return 0;

  switch (Private[0]) {
  case AUTOLANG_XLAT:       // not yet translated
  case AUTOLANG_CACHEDNEUT: // translated string in cache
  case AUTOLANG_CACHEDLOAD: // translated or neutral name in cache
    return Private+1;

  case AUTOLANG_RCID:       // resource not accessed yet
  case AUTOLANG_LOAD:       // resource not accessed yet
    return 0;

  default:                  // untranslatable string, no prefix
    return Private;
  }
}

int TLocaleString::Compare(const char far* str, TLangId lang)
{
  return CompareLang(this->Translate(lang), str, lang);
}

int TLocaleString::IsNativeLangId(TLangId lang)
{
  return lang == NativeLangId || lang == (NativeLangId & 0x00FF);
}

