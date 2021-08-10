//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.7  $
//
// Implementation of class TMailer which provides Mail enabling.
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_WINDOW_H)
# include <owl/window.h>
#endif
#if !defined(OWL_MAILER_H)
# include <owl/mailer.h>
#endif
#if !defined(WINSYS_PROFILE_H)
# include <winsys/profile.h>
#endif
#include <stdio.h>
#include <commdlg.h>  // GetFileTitle()

OWL_DIAGINFO;

#if defined(BI_PLAT_WIN32)
  static char MapiLibName[] = "mapi32.dll";
#else
  static char MapiLibName[] = "mapi.dll";
#endif

//
// Loads the MAPI DLL.
//
TMailer::TMailer()
:
  TModule(MapiLibName, true, true),  // Should load library & must exist
  MAPISendDocuments(*this, "MAPISendDocuments")
{
}

//
// owner
//   The owning window that is using the mailer. Is used to parent mail UI
//   windows
//
// paths
//   Pointer to string containg the files to send. The files must have a
//   fully qualified path and filename. The string could have multiple
//   files separated by a semicolon ';'.  The filenames may be long filenames.
//
// names
//
// asynchWork
//   If true, the message submission will be made from a separate thread
//   other than the thread where the SendMail was called.  With this flag,
//   the function returns immediately after the working thread has been
//   created. If false, the call is synchronous and it wll return when the
//   message is submitted to the messaging subsystem.
//
// Purpose:
//  This function is called by apps to send files to a mail recipient. The
//  attachments can be of any size. The underlying messaging system will ask
//  for credentials of the recipients.  When the send note is displayed, other
//  options could be added or modified.  Also at that time other type of
//  attachments can be added (i.e. OLE objects).
//
void
TMailer::SendDocuments(TWindow* owner, const char far* docPaths,
                       const char far* docNames, bool asynchWork)
{
  // Get the document names--either directly if passed, or by parsing the paths
  //
  char far* tmpDocNames = 0;
  if (!docNames) {
    // The file name must be separated by semi-colon, so parse the string for
    // the sub-strings
    //
    char far* tmpPaths = strnewdup(docPaths);
    tmpDocNames = new char[1024];
    *tmpDocNames = 0;
    char far* nameToken = strtok(tmpPaths, ";\n");
    while (nameToken) {
      // Strip leading blanks from name
      //
      while (*nameToken == ' ')
        nameToken++;

      // Get the file name (long file names are supported) from the path
      //
      char tmpName[_MAX_PATH];
      ::GetFileTitle(nameToken, tmpName, sizeof tmpName);

      // Append to string of file names (no paths)
      //
      strcat(tmpDocNames, tmpName);
      strcat(tmpDocNames, ";");

      // Get the next sub-string in the files string
      //
      nameToken = strtok(0, ";\n");
    }
    delete[] tmpPaths;
    docNames = tmpDocNames;
  }

  // Call MAPI to send the document. This function always prompts with a
  // dialog box so that the user can provide recipients and other sending
  // options.  The function tries to etablish a session from the messaging
  // system's shared session.  If no shared session exists, it prompts for
  // logon information to establish a session.  Before the function return,
  // it closes the session.
  //
  uint32 err = MAPISendDocuments(uint32(owner->GetHandle()), ";",
                                 (char far*)docPaths,
                                 (char far*)docNames,
                                 asynchWork);
  if (err) {
    // A problem was encountered.  Report it to the user?
    //
//    sprintf(docNames, "Failed to send the documents. Error: %d", err);
//    owner->MessageBox(docNames, 0, MB_OK);
  }

  // Delete the temp names string if we new'd one here
  //
  delete[] tmpDocNames;
}


//
// Verify whether SMAPI is properly installed and configured on this machine
// by checking WIN.INI MAIL/MAPI setting
//
bool  
TMailer::IsMAPIAvailable() const 
{
#if 1
  TProfile mailSection("Mail");
  return mailSection.GetInt("MAPI") != 0;

#else //   Do we need to perform additional checking

  static bool doneCheck = false;
  static bool mailState = false;

  // Have we checked yet?
  //
  if (doneCheck)
    return mailState;

  TProfile mailSection("Mail");

  bool mapiFlag = mailSection.GetInt("MAPI");

  if (mapiFlag && TSystem::IsWin95()) {
    // If we're running on Windows 95, we have to also make sure
    // Exchange is installed.
    //
    TAPointer<char> buffer = new char[80];
    mailSection.GetString("Exchange", buffer, 80);

    if (buffer) {
      strlwr(buffer);

      if (strstr(buffer, "exchng32"))
        mailState = true;
    }

  }
  else if (mapiFlag && TSystem::IsNT()) {
    mailState = true;
  }

  doneCheck = true;
  return mailState;
#endif
}
