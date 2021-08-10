//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1994 by Borland International, All Rights Reserved
//
//   Definition of TProfile class
//----------------------------------------------------------------------------
#if !defined(OWL_PROFILE_H)
#define OWL_PROFILE_H

#if !defined(OWL_OWLDEFS_H)
# include <owl/owldefs.h>
#endif

//
//  class TProfile
//  ----- --------
//
class _OWLCLASS TProfile  {
  public:
    // Use system profile for filename==0
    //
    TProfile(const char* section, const char* filename = 0);
   ~TProfile();

    int GetInt(const char* key, int defaultInt = 0);

    // Returns all section values if key==0
    //
    bool GetString(const char* key, char buff[], 
                   unsigned buffSize, const char* defaultString = "");

    bool WriteInt(const char* key, int value);
    bool WriteString(const char* key, const char* str);

  private:
    char* Section;
    char* FileName;
};

#endif  // OWL_PROFILE_H
