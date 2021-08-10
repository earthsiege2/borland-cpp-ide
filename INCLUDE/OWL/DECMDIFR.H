//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.3  $
//
// Definition of TDecoratedMDIFrame class
//----------------------------------------------------------------------------
#if !defined(OWL_DECMDIFR_H)
#define OWL_DECMDIFR_H

#if !defined(OWL_MDI_H)
# include <owl/mdi.h>
#endif
#if !defined(OWL_DECFRAME_H)
# include <owl/decframe.h>
#endif

#if defined(BI_NAMESPACE)
namespace OWL {
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

//
// class TDecoratedMDIFrame
// ~~~~~ ~~~~~~~~~~~~~~~~~~
// MDI frame that supports decoration child windows
//
class _OWLCLASS TDecoratedMDIFrame : public TMDIFrame,
                                     public TDecoratedFrame {
  public:
    TDecoratedMDIFrame(const char far* title,
                       TResId          menuResId,
                       TMDIClient&     clientWnd = *new TMDIClient,
                       bool            trackMenuSelection = false,
                       TModule*        module = 0);

    TResult  DefWindowProc(uint message, TParam1 wParam, TParam2 lParam);

  private:
    // Hidden to prevent accidental copying or assignment
    //
    TDecoratedMDIFrame(const TDecoratedMDIFrame&);
    TDecoratedMDIFrame& operator =(const TDecoratedMDIFrame&);

  DECLARE_RESPONSE_TABLE(TDecoratedMDIFrame);
  DECLARE_STREAMABLE(_OWLCLASS, TDecoratedMDIFrame, 1);
};

// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>

typedef TDecoratedMDIFrame TDecoratedMdiFrame;

#if defined(BI_NAMESPACE)
} // namespace OWL
#endif

#endif  // OWL_DECMDIFR_H
