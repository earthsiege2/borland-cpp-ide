//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.8  $
//
// Definition of classes supporting Printing/PrintPreview for TRichEdit
//----------------------------------------------------------------------------
#if !defined(OWL_RICHEDPR_H)
#define OWL_RICHEDPR_H

#if !defined(BI_PLAT_WIN32)
# error OWL: Rich Edit preview support is only available for WIN32 targets
#endif

#if !defined(OWL_PRINTER_H)
# include <owl/printer.h>
#endif
#if !defined(OWL_PREVIEW_H)
# include <owl/preview.h>
#endif
#if !defined(OWL_PREVWIN_H)
# include <owl/prevwin.h>
#endif
#if !defined(OWL_LAYOUTWI_H)
# include <owl/layoutwi.h>
#endif
#if !defined(OWL_RICHEDIT_H)
# include <owl/richedit.h>
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

//
//
template <class T>
class TDynArray {
  public:
    TDynArray(uint limit, uint delta);
   ~TDynArray();
    T&          operator[](uint index);

  protected:
    void        SetLimit(uint aLimit);

  private:
    T*          items;              // Pointer to array of T
    uint        limit;              // Size array is allocated for
    uint        delta;              // Inc. delta for resizing
};

//
//
//
template<class T>
TDynArray<T>::TDynArray(uint aLimit, uint aDelta)
: items(0), limit(0), delta(aDelta)
{
  SetLimit(aLimit);
}

//
//
//
template<class T> TDynArray<T>::~TDynArray()
{
  SetLimit(0);
}

//
//
//
template<class T> T& TDynArray<T>::operator[](uint index)
{
  // Grow if necessary
  //
  while(index >= limit)
   SetLimit(limit + delta);

  return items[index];
}

//
//
//
template<class T> void TDynArray<T>::SetLimit(uint aLimit)
{
  if (aLimit != limit) {
    T* aItems;

    if (aLimit == 0) {
      aItems = 0;
    }
    else {
      // NOTE: T must have default constructor and proper copy
      //       semantics (copy ctr and assignment operator)..
      //
      aItems = new T[aLimit];

      // Copy over the items already in array
      //
      for (int i=0; i<limit && i<aLimit; i++)
        aItems[i] = items[i];
    }

    delete [] items;
    items = aItems;
    limit = aLimit;
  }
}


#if defined(BI_COMP_BORLANDC)
# if defined(_OWLDLL) || defined(BI_APP_DLL)
//
// Export template of TDynArray<int> when building ObjectWindows DLL 
// and provide import declaration of DLL instance for users of the class.
//
template class _OWLCLASS TDynArray<int>;
# endif //  _OWLDLL || BI_APP_DLL
#endif  //  BI_COMP_BORLANDC

//
// class TRichEditPreviewFrame
// ~~~~~ ~~~~~~~~~~~~~~~~~~~~~
// TRichEditPreviewFrame is a window object which contains preview pages
// displaying data from a rich edit control. It contains a simple preview
// toolbar and one or two preview pages.
//
class _OWLCLASS TRichEditPreviewFrame : public TPreviewWin {
  public:
    TRichEditPreviewFrame(TWindow* parentWindow,  /* Parent object  */
                          TPrinter& printer,      /* Printer object */
                          TPrintout& printout,    /* Printout object*/
                          TRichEdit& richEdit,    /* RichEdit ctrl. */
                          const char far* title,  /* Title of window*/
                          TLayoutWindow* client); /* Client window  */  

  protected:
    TPreviewPage* GetNewPreviewPage(TWindow* parent,
                                    TPrintout& printout,
                                    TPrintDC&  prndc,
                                    TSize&     printExtent,
                                    int        pagenum = 1);
};

//
// class TRichEditPagePreview
// ~~~~~ ~~~~~~~~~~~~~~~~~~~~
// TRichEditPagePreview is a window which displays rich edit data formatted
// for a particular printer DC.
//
class _OWLCLASS TRichEditPagePreview : public TPreviewPage {
  public:
    TRichEditPagePreview(TWindow* parent, TPrintout& printout,
                         TPrintDC&  prndc, TSize& printExtent,
                         int pagenum = 1);
  protected:
    void  Paint(TDC& dc, bool, TRect& clip);
};

//
// class TRichEditPrintout
// ~~~~~ ~~~~~~~~~~~~~~~~~
// TRichEditPrintout encapsulates the information to print/preview data from
// a rich edit control. For example, it holds the offset of pages, the range
// of data to be printer/previewed etc. etc.
//
class _OWLCLASS TRichEditPrintout : public TPrintout {
  public:
    TRichEditPrintout(TPrinter& printer,
                      TRichEdit& richEdit,
                      const char far* title);
   ~TRichEditPrintout();

    // Overriden virtual methods of TPrintout
    //
    void          GetDialogInfo (int& minPage, int& maxPage,
                                 int& selFromPage, int& selToPage);
    void          SetPrintParams(TPrintDC* dc, TSize pageSize);
    bool          HasPage(int pageNumber);
    void          BeginPrinting();
    void          PrintPage(int page, TRect& rect, uint flags);
    void          EndPrinting();
    void          CleanupPrintParams();

    // Helper methods
    //
    int           PageOfOffset(int offset);

  protected:


    TRichEdit&     RichEdit;              // Ref. to associated control  
    TPrinter&      Printer;               // Ref. to associated printer
    TSize          SizePhysPage;          // Physical size of printer (pels)
    TSize          SizePhysInch;          // Size of printer in inches
    TSize          Margins;               // Size of margins
    TFormatRange   FmtRange;              // Range of text to format
    bool           FlushCache;            // Have cached formatted data
    int            TextLen;               // Length of text formatted
    int            PageCount;             // Number of pages formatted
    TDynArray<int> PageIndices;           // Index of page offsets
};

// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>

#endif  // OWL_REDITPRI_H
