Copyright Borland International
ObjectWindows (C) 1995

Title: METAFILE Example

Keywords: TMetaFilePict;TMetaFileDC;TEnhMetaFilePict;TEnhMetaFileDC;
Placeable metafile;METAFILEHEADER

Three sample metafiles accompany this example.

  ENHANCED.EMF   A metafile using the new "enhanced metafile" format
  PLACBLE.WMF    A placeable metafile that uses the header commonly 
                 prefixed to metafile files by programs like MS Office.
                 (See METAFILE.H for a definition of the header structure.)
  REGULAR.WMF    A plan, simple, unadulterated, original-format metafile.

The example can open and display all three metafiles.  (ENHANCED.EMF and 
REGULAR.WMF happen to contain the same image stored in different formats.)


