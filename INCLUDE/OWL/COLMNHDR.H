//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.10  $
//
// Definition of class TColumnHeader and helper classes
//----------------------------------------------------------------------------
#if !defined(OWL_COLMNHDR_H)
#define OWL_COLMNHDR_H

#if !defined(OWL_COMMCTRL_H)
# include <owl/commctrl.h>
#endif

#if defined(BI_NAMESPACE)
namespace OWL {
#endif

class _OWLCLASS THdrItem;
class _OWLCLASS THdrNotify;
class _OWLCLASS TColumnHeader;

#if !defined(HDI_ALL)   // Mentioned in docs. but missing from headers
# define HDI_ALL (HDI_BITMAP|HDI_FORMAT|HDI_HEIGHT|HDI_LPARAM|HDI_TEXT|HDI_WIDTH)
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

//
// class THdrItem
// ~~~~~ ~~~~~~~~
// THdrItem contains information about an item in a header control.
//
class _OWLCLASS THdrItem : public HD_ITEM {
  public:
    // Constructors which create 'THdrItem' structures to be used
    // for adding, inserting or updating a header control's item
    // 'str' specifies the text/title of the item; 'hbm' specifies a handle
    // to a bitmap to be used in the item.
    //
    THdrItem(const char far* str);
    THdrItem(const char far* str, HBITMAP hbm);
    THdrItem(HBITMAP hbm);

    // Constructors used primarily to construct a 'THdrItem' structure
    // which will be used to retrieve information about an item within
    // a header control. 'buffer' specifies the location to receive the
    // item's title and 'len' indicates the size of that buffer. The 'msk'
    // flags indicates which members of the structure should be updated.
    //
    THdrItem(char far* buffer, int len, uint msk = HDI_TEXT);
    THdrItem(uint msk = 0);

    // Methods to set the data members of the HD_ITEM structure.
    //
    void          SetText(const char far* str);
    void          SetBitmap(HBITMAP hbm);
    void          SetWidth(int cx);
    void          SetHeight(int cy);
    void          SetItemData(TParam2 data);
    void          SetMask(int msk);

    static  void  SetDefStringSize(int size);
    static  void  SetDefBitmapSize(int size);
    
  protected:
    static  int  DefStringItemSize;
    static  int  DefBitmapItemSize;
};


//
// class THeaderHitTestInfo
// ~~~~~ ~~~~~~~~~~~~~~~~~~
// THeaderHitTestInfo contains hittest information for the header control.
// It is used with the TColumnHeader::HitTest method.
//
class THeaderHitTestInfo : public HD_HITTESTINFO {
  public:
    THeaderHitTestInfo(const TPoint& pt);
    THeaderHitTestInfo(int x, int y);
};

//
// class TColumnHeader
// ~~~~~ ~~~~~~~~~~~~~
//  TColumnHeader encapsulates the 'header control', a window
//  usually positioned above columns of text or numbers.
//

#if defined(BI_NAMESPACE)
} // namespace OWL
#endif
#include <classlib/arrays.h>
#if defined(BI_NAMESPACE)
namespace OWL {
#endif

class _OWLCLASS TColumnHeader : public TControl {
  public:
    TColumnHeader(TWindow* parent,
                  int             id,
                  int x, int y, int w, int h,
                  TModule*        module = 0);

    TColumnHeader(TWindow* parent, int resourceId, TModule* module = 0);
    ~TColumnHeader();

    // Position Column Header
    //
    bool          Layout(TRect& boundingRect, WINDOWPOS& winPos);
    bool          Layout(uint swpFlags = 0);

    // Column Header attributes
    //
    int           GetCount() const;

    // Operations on individual column header items
    //
    int           Add(const THdrItem& item);
    int           Insert(const THdrItem& item, int index);
    bool          Delete(int index);
    bool          GetItem(THdrItem&, int index, uint mask = 0);
    bool          SetItem(const THdrItem& itemInfo, int index);

    // Hit-testing
    //
    int           HitTest(THeaderHitTestInfo& ht);

    // Override virtual method to save/restore contents of columnHeader
    //
    uint          Transfer(void* buffer, TTransferDirection direction);

  protected:
    // Override TWindow virtual member functions
    //
    char far*     GetClassName();

#if !defined(OWL_NATIVECTRL_ALWAYS)
  public:
    static void SetNativeUse(TNativeUse nu);

  protected_data:
    static TNativeUse ClassNativeUse;

  protected:
    void Paint(TDC &dc,bool erase,TRect &rect);
    void EvLButtonUp(uint modKeys,TPoint &point);
    void EvMouseMove(uint modKeys,TPoint &point);
    void EvLButtonDblClk(uint modKeys,TPoint &point);
    void EvLButtonDown(uint modKeys,TPoint &point);
    bool EvSetCursor(HWND hWndCursor,uint hitTest,uint mouseMsg);
    void EvSetFont(HFONT hFont,bool redraw);
    HFONT EvGetFont();

  private:
    void InitCtl();
    void CleanupCtl();
    LRESULT SendNotify(uint code,int item);

    // Internal tracking functions
    //
    void TrackLine(int pos);
    void BeginTrack(const TPoint &point,int iItem);
    void Track(const TPoint &point);
    void EndTrack();

    TFont *Font;

    class _OWLCLASS TItem: public HD_ITEM {
    public:
      TItem();
        TItem(const HD_ITEM &other);
        ~TItem();
        TItem &operator=(const TItem &other);
      bool operator==(const TItem &other) const;

    private:
      void Cleanup();
        void Init(const HD_ITEM &other);
    };

#if defined(BI_NAMESPACE)
    ClassLib::TArrayAsVector<TItem> Item;
#else
    TArrayAsVector<TItem> Item;  
#endif
  
    int HotItem;    // item currently clicked or tracked
    enum TOperation { // current operation on hot item
      CLICKING,
      TRACKING,
      NONE
    } Operation;

    // for clicking
    int Pressed;
    // for tracking
    int TrackStart;
    int TrackSize;
    TPoint TrackPoint;

  DECLARE_RESPONSE_TABLE(TColumnHeader);
#endif

  private:
    // Hidden to prevent accidental copying or assignment
    //
    TColumnHeader(const TColumnHeader&);
    TColumnHeader& operator =(const TColumnHeader&);

  DECLARE_STREAMABLE(_OWLCLASS, TColumnHeader, 1);
};


// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>

#if defined(BI_NAMESPACE)
} // namespace OWL
#endif

//----------------------------------------------------------------------------
// Inline implementations
//

//
// Updates the mask member of the structure. The latter indicates
// which other members of the structure contain valid data.
//
inline void THdrItem::SetMask(int msk)
{
  mask = msk;
}

//
// Initializes the client ooordinates being hit-tested with the 
// specified TPoint parameter.
//
inline THeaderHitTestInfo::THeaderHitTestInfo(const TPoint& point)
{
  pt.x = point.x;
  pt.y = point.y;
}

//
// Initializes the client ooordinates being hit-tested with the 
// specified 'x' and 'y' locations.
//
inline THeaderHitTestInfo::THeaderHitTestInfo(int x, int y)
{
  pt.x = x;
  pt.y = y;
}


#endif  // OWL_COLMNHDR_H
