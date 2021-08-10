//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1992, 1994 by Borland International, All Rights Reserved
//
//   Definition of TDecoratedMDIFrame class
//----------------------------------------------------------------------------
#if !defined(OWL_DECMDIFR_H)
#define OWL_DECMDIFR_H

#if !defined(OWL_MDI_H)
# include <owl/mdi.h>
#endif
#if !defined(OWL_DECFRAME_H)
# include <owl/decframe.h>
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
                       bool            trackMenuSelection = false,
                       TModule*        module = 0);

    LRESULT  DefWindowProc(uint message, WPARAM wParam, LPARAM lParam);

  private:
    //
    // hidden to prevent accidental copying or assignment
    //
    TDecoratedMDIFrame(const TDecoratedMDIFrame&);
    TDecoratedMDIFrame& operator =(const TDecoratedMDIFrame&);

  DECLARE_RESPONSE_TABLE(TDecoratedMDIFrame);
  DECLARE_STREAMABLE(_OWLCLASS, TDecoratedMDIFrame, 1);
};

#endif  // OWL_DECMDIFR_H
