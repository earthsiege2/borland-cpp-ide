//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1992, 1994 by Borland International, All Rights Reserved
//
//   Definition of class TToolBox.
//----------------------------------------------------------------------------
#if !defined(OWL_TOOLBOX_H)
#define OWL_TOOLBOX_H

#if !defined(OWL_GADGETWI_H)
# include <owl/gadgetwi.h>
#endif

//
//  class TToolBox
//  ----- --------
//
//  arranges its gadgets in a matrix. all columns are the same width (as wide
//  as the widest gadget) and all rows are the same height (as high as the
//  heighest gadget)
//
//  you specify the number of rows and columns you want. you can specify
//  AS_MANY_AS_NEEDED in which case the toolbox figures out how many rows or
//  columns are needed based on the opposite dimension (e.g. if there are
//  20 gadgets and you requested 4 columns then you would get 5 rows)
//
const int AS_MANY_AS_NEEDED = -1;

class _OWLCLASS TToolBox : public TGadgetWindow {
  public:
    TToolBox(TWindow*        parent,
             int             numColumns = 2,
             int             numRows = AS_MANY_AS_NEEDED,
             TTileDirection  direction = Horizontal,  // Row Major
             TModule*        module = 0);

    void  GetDesiredSize(TSize& size);
    void  LayoutSession();

    //
    // override Insert member function and tell the button to not notch
    // its corners
    //
    void  Insert(TGadget& gadget, TPlacement = After, TGadget* sibling = 0);

    virtual void  SetDirection(TTileDirection direction);
  
  protected:
    int             NumRows;
    int             NumColumns;

    TRect TileGadgets();

  private:
    void  ComputeNumRowsColumns(int& numRows, int& numColumns);
    void  ComputeCellSize(TSize& size);

  DECLARE_CASTABLE;
};

#endif  // OWL_TOOLBOX_H
