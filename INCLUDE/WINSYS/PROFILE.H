//----------------------------------------------------------------------------
// Borland WinSys Library
// Copyright (c) 1994, 1996 by Borland International, All Rights Reserved
//
//$Revision:   5.5  $
//
// Definition of TProfile class
//----------------------------------------------------------------------------
#if !defined(WINSYS_PROFILE_H)
#define WINSYS_PROFILE_H

#if !defined(WINSYS_DEFS_H)
# include <winsys/defs.h>
#endif

//
// class TProfile
// ~~~~~ ~~~~~~~~
class _WSYSCLASS TProfile  {
  public:
    // Use system global profile for filename==0
    //
    TProfile(const char far* section, const char far* filename = 0);
   ~TProfile();

    int GetInt(const char far* key, int defaultInt = 0);

    // Returns all section values if key==0
    //
    bool GetString(const char far* key, char far* buff,
                   unsigned buffSize, const char far* defaultString = "");

    bool WriteInt(const char far* key, int value);
    bool WriteString(const char far* key, const char far* str);
    void Flush();

  private:
    char far* Section;     // Name of the section to use
    char far* FileName;    // File name of the .INI file
};

#endif  // WINSYS_PROFILE_H
