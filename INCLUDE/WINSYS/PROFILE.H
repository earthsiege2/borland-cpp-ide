//----------------------------------------------------------------------------
// Borland WinSys Library
// Copyright (c) 1994, 1996 by Borland International, All Rights Reserved
//
//$Revision:   5.9  $
//
// Definition of TProfile class
//----------------------------------------------------------------------------
#if !defined(WINSYS_PROFILE_H)
#define WINSYS_PROFILE_H

#if !defined(WINSYS_DEFS_H)
# include <winsys/defs.h>
#endif

#if defined(BI_NAMESPACE)
namespace ClassLib {
#endif

//
// class TProfile
// ~~~~~ ~~~~~~~~
class _WSYSCLASS TProfile  {
  public:
    // Use system global profile for filename==0
    //
    TProfile(const _TCHAR far* section, const _TCHAR far* filename = 0);
   ~TProfile();

    int GetInt(const _TCHAR far* key, int defaultInt = 0);

    // Returns all section values if key==0
    //
    bool GetString(const _TCHAR far* key, _TCHAR far* buff,
                   unsigned buffSize, const _TCHAR far* defaultString = "");

    bool WriteInt(const _TCHAR far* key, int value);
    bool WriteString(const _TCHAR far* key, const _TCHAR far* str);
    void Flush();

  protected:
    _TCHAR far* Section;     // Name of the section to use
    _TCHAR far* FileName;    // File name of the .INI file
};

#if defined(BI_NAMESPACE)
}     // namespace ClassLib 
#endif

#endif  // WINSYS_PROFILE_H
