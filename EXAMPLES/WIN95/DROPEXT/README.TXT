THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
PARTICULAR PURPOSE.

Copyright (C) 1993-1995  Microsoft Corporation.  All Rights Reserved.

TITLE:
    DROPEXT

PURPOSE:
    Demonstrates how to create a context menu extension handler.

COMMENTS:
    To see how it works after building DROPEXT.DLL, please update the registry
    in following steps.

    1. Build DROPEXT.DLL
    2-a. Copy DROPEXT.DLL to the system directory (e.g., c:\windows\system)
         or
    2-b. Modify DROPEXT.REG file to points to a fully qualified path to the DLL
         (e.g., @="c:\\bc5\\examples\\win95\\dropext\\dropext.dll"
    3. Run "regedit dropext.reg"

    Then, using the right-mouse button, drag a file (or multiple files)
    from one folder to another, you'll see additional menu items on drop.

