//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.3  $
//
// Definition of class TToolBox.
//----------------------------------------------------------------------------
#if !defined(OWL_TOOLBOX_H)
#define OWL_TOOLBOX_H

#if !defined(OWL_GADGETWI_H)
# include <owl/gadgetwi.h>
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

//
// class TToolBox
// ~~~~~ ~~~~~~~~
// Arranges its gadgets in a matrix. All columns are the same width (as wide
// as the widest gadget) and all rows are the same height (as high as the
// heighest gadget)
//
// You specify the number of rows and columns you want. You can specify
// AS_MANY_AS_NEEDED in which case the toolbox figures out how many rows or
// columns are needed based on the opposite dimension (e.g. if there are
// 20 gadgets and you requested 4 columns then you would get 5 rows)
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

    // Override Insert member function and tell the button to not notch
    // its corners
    //
    void  Insert(TGadget& gadget, TPlacement = After, TGadget* sibling = 0);

    virtual void  SetDirection(TTileDirection direction);

  protected:
    TRect TileGadgets();

    int   GetNumRows() const;
    int   GetNumColumns() const;

  protected_data:
    int   NumRows;
    int   NumColumns;

  private:
    void  ComputeNumRowsColumns(int& numRows, int& numColumns);
    void  ComputeCellSize(TSize& size);

  DECLARE_CASTABLE;
};

// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>

//----------------------------------------------------------------------------
// Inline implementation
//

//
// Return the number of rows the toolbox is using.
//
inline int TToolBox::GetNumRows() const
{
  return NumRows;
}

//
// Return the number of columns the toolbox is using.
//
inline int TToolBox::GetNumColumns() const
{
  return NumColumns;
}
#endif  // OWL_TOOLBOX_H
