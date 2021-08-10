//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1992, 1993 by Borland International
//   include\owl\decmdifr.h
//   Definition of TDecoratedMDIFrame class
//----------------------------------------------------------------------------
#if !defined(__OWL_DECMDIFR_H)
#define __OWL_DECMDIFR_H

#if !defined(__OWL_MDI_H)
  #include <owl\mdi.h>
#endif
#if !defined(__OWL_DECFRAME_H)
  #include <owl\decframe.h>
#endif

//
//  class TDecoratedMDIFrame
//  ----- ------------------
//
//  MDI frame that supports decoration child windows
//
class _OWLCLASS TDecoratedMDIFrame : public TMDIFrame, public TDecoratedFrame {
  public:
    TDecoratedMDIFrame(const char far* title,
                       TResId          menuResId,
                       TMDIClient&     clientWnd = *new TMDIClient,
                       BOOL            trackMenuSelection = FALSE,
                       TModule*        module = 0);

    LRESULT  DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam);

  private:
    //
    // hidden to prevent accidental copying or assignment
    //
    TDecoratedMDIFrame(const TDecoratedMDIFrame&);
    TDecoratedMDIFrame& operator =(const TDecoratedMDIFrame&);

  DECLARE_RESPONSE_TABLE(TDecoratedMDIFrame);
  DECLARE_STREAMABLE(_OWLCLASS, TDecoratedMDIFrame, 1);
};

#endif  // __OWL_DECMDIFR_H
