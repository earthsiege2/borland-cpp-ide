//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987-2002 Borland International Inc.  All Rights Reserved.
//---------------------------------------------------------------------------

TITLE:
    RICHEDIT

DESCRIPTION:
    A Rich Text word processor

DEMONSTRATES:
    + TRichEdit, TPanel, TSpeedButton, TComboBox, TUpDown, TLabel, TBevel,
      TFontDialog, TOpenDialog, TSaveDialog, TPrintDialog, TMainMenu
    + Use of resource only Dll's for the languages English, German and French.
    + Design-time switching of resource only DLLs
    + Runtime switching of resource only DLLs

COMMENTS:
    * Open RichEditGroup.bpg from the Examples\Apps\RichEdit directory.
    * Important: Select Project | Make All Projects
    * Important: For each of the following items, make sure that richedit.exe
                 is the active project in the Project Manager.

    o Adding a language:
      - Select Project | Languages | Add... and follow the wizard steps.

    o Design-time switching of resource only DLLs:
      - Select Project | Languages | Set Active... and choose the language you
        want your to see your application in.
      - Select Run | Run.

    o Runtime switching of resource only DLLs:
      While the RichEdit demo is running:
      - Open the Language menu item and choose the language. The application
        will show using the selected language.

    o Modifying the source code:
      - Modify the source code.
      - Project | Languages | Update Resouce DLLs.
      - Translate any new resources in the Translation Manager.
      - Select Project | Make all projects.
      - In the Project Manager, activate richedit.exe.
      - See Design-Time or Runtime switching above to test it.
