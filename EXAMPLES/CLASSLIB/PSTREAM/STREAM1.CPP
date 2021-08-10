/*------------------------------------------------------------------------*/
/*                                                                        */
/*  STREAM1.CPP                                                           */
/*                                                                        */
/*  Copyright Borland International, 1993                                 */
/*                                                                        */
/*  Streaming example, version 1                                          */
/*                                                                        */
/*  Streams objects.                                                      */
/*                                                                        */
/*------------------------------------------------------------------------*/
#include <owl\owlpch.h>

#include <new.h>
#include <cstring.h>

#include <classlib\sets.h>
#include <classlib\objstrm.h>   // Changed

#include <owl\point.h>
#include <owl\window.h>
#include <owl\dc.h>
#include <owl\applicat.h>
#include <owl\framewin.h>
#include <owl\dialog.h>
#include <owl\opensave.h>       // Changed

#include "streams.h"

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  class GraphicalObject                                                 */
/*                                                                        */
/*      class GraphicalObject provides the abstract interface             */
/*      to all of the graphical objects that can be displayed             */
/*      by this graphical system.  It should be a virtual base            */
/*      of any class derived from it.                                     */
/*                                                                        */
/*  Member functions:                                                     */
/*                                                                        */
/*      GraphicalObject();                                                */
/*                                                                        */
/*          Creates a GraphicalObject with undefined initial              */
/*          coordinates. Needed only in multiple inheritance when         */
/*          we know that GraphicalObject(const TRect&) will be used       */
/*          by derived classes.                                           */
/*                                                                        */
/*      GraphicalObject( TPoint p1, TPoint p2 );                          */
/*                                                                        */
/*          Creates a GraphicalObject with the location and size          */
/*          specified by p1 and p2.                                       */
/*                                                                        */
/*      virtual ~GraphicalObject();                                       */
/*                                                                        */
/*          Destructor.                                                   */
/*                                                                        */
/*      void Draw( TDC& );                                                */
/*                                                                        */
/*          Does some preliminary setup of the device context, then       */
/*          calls DoDraw() to draw the object.                            */
/*                                                                        */
/*      virtual void DoDraw( TDC& ) = 0;                                  */
/*                                                                        */
/*          Draws the object.  In GraphicalObject this does               */
/*          nothing.  It should be overridden in any class                */
/*          that will be displayed on the screen.                         */
/*                                                                        */
/*      int operator == ( const GraphicalObject& ) const;                 */
/*                                                                        */
/*          This operator must exist so that we can put GraphicalObjects  */
/*          into the Set that is used in TGraphWindow.                    */
/*                                                                        */
/*------------------------------------------------------------------------*/

class GraphicalObject : public TStreamableBase  // Changed
{

public:

    GraphicalObject();
    GraphicalObject( TPoint p1, TPoint p2 );
    virtual ~GraphicalObject();

    void Draw( TDC& );
    int operator == ( const GraphicalObject& obj ) const;

protected:

    TRect bbox;

private:

    virtual void DoDraw( TDC& ) = 0;

    class GraphicalObjectDC
    {
    public:
        GraphicalObjectDC( TDC& dc );
        ~GraphicalObjectDC();
        operator TDC&() const;
    private:
        TDC& DC;
    };

    DECLARE_ABSTRACT_STREAMABLE( , GraphicalObject, 1 );// Changed

};

inline GraphicalObject::GraphicalObject()
{
}

inline GraphicalObject::GraphicalObject( TPoint p1, TPoint p2 ) :
    bbox( p1, p2 )
{
}

inline GraphicalObject::~GraphicalObject()
{
}

void GraphicalObject::Draw( TDC& dc )
{
    GraphicalObjectDC gdc( dc );
    DoDraw( gdc );
}

inline int GraphicalObject::operator == ( const GraphicalObject& obj ) const
{
    return this == &obj;
}


GraphicalObject::GraphicalObjectDC::GraphicalObjectDC( TDC& dc ) : DC(dc)
{
    DC.SelectStockObject( NULL_BRUSH );
}

GraphicalObject::GraphicalObjectDC::~GraphicalObjectDC()
{
}

GraphicalObject::GraphicalObjectDC::operator TDC&() const
{
    return DC;
}

// Changed
IMPLEMENT_CASTABLE( GraphicalObject );
IMPLEMENT_ABSTRACT_STREAMABLE( GraphicalObject );

// Changed
void *GraphicalObject::Streamer::Read( ipstream& in, uint32 ) const
{
    in >> GetObject()->bbox;
    return GetObject();
}

// Changed
void GraphicalObject::Streamer::Write( opstream& out ) const
{
    out << GetObject()->bbox;
}

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  class Line                                                            */
/*                                                                        */
/*      class Line draws a line between two specified points.             */
/*                                                                        */
/*  Member functions:                                                     */
/*                                                                        */
/*      Line( TPoint p1, TPoint p2 );                                     */
/*                                                                        */
/*          Creates a line between the points p1 and p2.                  */
/*                                                                        */
/*      void ImplementDraw( TDC& );                                       */
/*                                                                        */
/*          Draws the line.                                               */
/*                                                                        */
/*      virtual void DoDraw( TDC& );                                      */
/*                                                                        */
/*          Overrides GraphicalObject::DoDraw and draws the line by       */
/*          calling ImplementDraw().                                      */
/*                                                                        */
/*------------------------------------------------------------------------*/

class Line : public virtual GraphicalObject
{

public:

    Line( TPoint p1, TPoint p2 );

protected:

    void ImplementDraw( TDC& );

private:

    virtual void DoDraw( TDC& );

    DECLARE_STREAMABLE_FROM_BASE( , Line, GraphicalObject );    // Changed

};

inline Line::Line( TPoint p1, TPoint p2 ) : GraphicalObject( p1, p2 )
{
}

void Line::ImplementDraw( TDC& dc )
{
    dc.MoveTo( bbox.left, bbox.top );
    dc.LineTo( bbox.right, bbox.bottom );
}

void Line::DoDraw( TDC& dc )
{
    ImplementDraw( dc );
}

// Changed
IMPLEMENT_CASTABLE1( Line, GraphicalObject );
IMPLEMENT_STREAMABLE_FROM_BASE( Line, GraphicalObject );

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  class TRectangle                                                      */
/*                                                                        */
/*      class TRectangle draws a rectangle.                               */
/*                                                                        */
/*  Member functions:                                                     */
/*                                                                        */
/*      TRectangle( TPoint p1, TPoint p2 );                               */
/*                                                                        */
/*          Creates a TRectangle whose upper left corner is at p1         */
/*          and whose lower right corner is at p2.                        */
/*                                                                        */
/*      void ImplementDraw( TDC& );                                       */
/*                                                                        */
/*          Draws the rectangle.                                          */
/*                                                                        */
/*      virtual void DoDraw( TDC& );                                      */
/*                                                                        */
/*          Overrides GraphicalObject::DoDraw and draws the rectangle by  */
/*          calling ImplementDraw().                                      */
/*                                                                        */
/*------------------------------------------------------------------------*/

class TRectangle : public virtual GraphicalObject
{

public:

    TRectangle( TPoint p1, TPoint p2 );

protected:

    void ImplementDraw( TDC& );

private:

    virtual void DoDraw( TDC& );

    DECLARE_STREAMABLE_FROM_BASE( , TRectangle, GraphicalObject );  // Changed

};

inline TRectangle::TRectangle( TPoint p1, TPoint p2 ) :
    GraphicalObject( p1, p2 )
{
}

void TRectangle::ImplementDraw( TDC& dc )
{
    dc.Rectangle( bbox );
}

void TRectangle::DoDraw( TDC& dc )
{
    ImplementDraw( dc );
}

// Changed
IMPLEMENT_CASTABLE1( TRectangle, GraphicalObject );
IMPLEMENT_STREAMABLE_FROM_BASE( TRectangle, GraphicalObject );

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  class TEllipse                                                        */
/*                                                                        */
/*      class TEllipse draws an ellipse.                                  */
/*                                                                        */
/*  Member functions:                                                     */
/*                                                                        */
/*      TEllipse( TPoint p1, TPoint p2 );                                 */
/*                                                                        */
/*          Creates a TEllipse whose bounding box is defined by p1 and p2 */
/*                                                                        */
/*      void ImplementDraw( TDC& );                                       */
/*                                                                        */
/*          Draws the ellipse.                                            */
/*                                                                        */
/*      virtual void DoDraw( TDC& );                                      */
/*                                                                        */
/*          Overrides GraphicalObject::DoDraw and draws the ellipse by    */
/*          calling ImplementDraw().                                      */
/*                                                                        */
/*------------------------------------------------------------------------*/

class TEllipse : public virtual GraphicalObject
{

public:

    TEllipse( TPoint p1, TPoint p2 );

protected:

    void ImplementDraw( TDC& );

private:

    virtual void DoDraw( TDC& );

    DECLARE_STREAMABLE_FROM_BASE( , TEllipse, GraphicalObject );    // Changed

};

TEllipse::TEllipse( TPoint p1, TPoint p2 ) :
    GraphicalObject( p1, p2 )
{
}

void TEllipse::ImplementDraw( TDC& dc )
{
    dc.Ellipse( bbox );
}

void TEllipse::DoDraw( TDC& dc )
{
    ImplementDraw( dc );
}

// Changed
IMPLEMENT_CASTABLE1( TEllipse, GraphicalObject );
IMPLEMENT_STREAMABLE_FROM_BASE( TEllipse, GraphicalObject );

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  class Caption                                                         */
/*                                                                        */
/*      class Caption draws its text on the screen.                       */
/*      Note that Caption is an abstract class.  It                       */
/*      must have a bounding box, but it does not                         */
/*      have a constructor that takes any coordinates.                    */
/*      Each class derived from Caption will provide                      */
/*      a bounding box in the virtual base GraphicalObject.               */
/*                                                                        */
/*  Type definitions:                                                     */
/*                                                                        */
/*      TextLoc                                                           */
/*                                                                        */
/*          An enum used to specify how y-coordinate values               */
/*          should be interpreted when displaying text.                   */
/*                                                                        */
/*  Member functions:                                                     */
/*                                                                        */
/*      Caption( const string& txt, TextLoc where );                      */
/*                                                                        */
/*          Creates a Caption with the specified text,                    */
/*          which will be drawn in its bounding box                       */
/*          at the top, center, or bottom, depending                      */
/*          on the value of its argument 'where'.                         */
/*                                                                        */
/*      virtual void ImplementDraw( TDC& );                               */
/*                                                                        */
/*          Draws the caption.                                            */
/*                                                                        */
/*------------------------------------------------------------------------*/

class Caption : public virtual GraphicalObject
{

public:

    enum TextLoc{ T_TOP, T_CENTER, T_BOTTOM };

    Caption( const string& txt, TextLoc where );

protected:

    void ImplementDraw( TDC& );

private:

    string Text;
    TextLoc Where;

    DECLARE_ABSTRACT_STREAMABLE( , Caption, 1 );// Changed

};

Caption::Caption( const string& text, TextLoc where ) :
    Text( text ), Where(where)
{
}

void Caption::ImplementDraw( TDC& dc )
{
    TEXTMETRIC tm;
    dc.GetTextMetrics(tm);
    WORD textHeight = tm.tmHeight+tm.tmExternalLeading;

    int yDelta;
    switch( Where )
    {
    case T_TOP:
        yDelta = textHeight/2;
        break;
    case T_CENTER:
        yDelta = (bbox.Height()-textHeight)/2;
        break;
    case T_BOTTOM:
        yDelta = bbox.Height()-3*textHeight/2;
        break;
    }
    dc.TextOut( bbox.left+bbox.Width()/2,
                bbox.top+yDelta,
                Text.c_str(), Text.length() );
}

// Changed
IMPLEMENT_CASTABLE1( Caption, GraphicalObject );
IMPLEMENT_ABSTRACT_STREAMABLE1( Caption, GraphicalObject );

// Changed
void *Caption::Streamer::Read( ipstream& in, uint32 ) const
{
    ReadVirtualBase( STATIC_CAST(GraphicalObject *,GetObject()), in );
    int temp;
    in >> GetObject()->Text >> temp;
    GetObject()->Where = TextLoc(temp);
    return GetObject();
}

// Changed
void Caption::Streamer::Write( opstream& out ) const
{
    WriteVirtualBase( STATIC_CAST(GraphicalObject *,GetObject()), out );
    out << GetObject()->Text << int(GetObject()->Where);
}

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  class CaptionedRectangle                                              */
/*                                                                        */
/*      class CaptionedRectangle draws a rectangle on the                 */
/*      screen, with a caption horizontally centered at the               */
/*      top, in the center, or at the bottom.                             */
/*                                                                        */
/*  Member functions:                                                     */
/*                                                                        */
/*      CaptionedRectangle( TPoint p1, TPoint p2,                         */
/*                          const string& txt,                            */
/*                          TextLoc loc = T_TOP )                         */
/*                                                                        */
/*          Creates a CaptionedRectangle with the specified               */
/*          location, size, and text.                                     */
/*                                                                        */
/*      void ImplementDraw( TDC& );                                       */
/*                                                                        */
/*          Draws the rectangle and its text.                             */
/*                                                                        */
/*      virtual void DoDraw( TDC& );                                      */
/*                                                                        */
/*          Overrides GraphicalObject::DoDraw and draws the rectangle by  */
/*          calling ImplementDraw().                                      */
/*                                                                        */
/*------------------------------------------------------------------------*/

class CaptionedRectangle : public TRectangle, public Caption
{

public:

    CaptionedRectangle( TPoint p1, TPoint p2,
                        const string& txt,
                        TextLoc loc = T_TOP );

protected:

    void ImplementDraw( TDC& );

private:

    virtual void DoDraw( TDC& );

    DECLARE_STREAMABLE( , CaptionedRectangle, 1 );  // Changed

};

CaptionedRectangle::CaptionedRectangle( TPoint p1, TPoint p2,
                                        const string& txt,
                                        TextLoc loc ) :
    GraphicalObject( p1, p2 ),
    TRectangle( p1, p2 ),
    Caption( txt, loc )
{
}

void CaptionedRectangle::ImplementDraw( TDC& dc )
{
    TRectangle::ImplementDraw( dc );
    Caption::ImplementDraw( dc );
}

void CaptionedRectangle::DoDraw( TDC& dc )
{
    ImplementDraw( dc );
}

// Changed
IMPLEMENT_CASTABLE2( CaptionedRectangle, TRectangle, Caption );
IMPLEMENT_STREAMABLE3( CaptionedRectangle, TRectangle, Caption, GraphicalObject );

// Changed
void *CaptionedRectangle::Streamer::Read( ipstream& in, uint32 ) const
{
    ReadBaseObject( STATIC_CAST(TRectangle *,GetObject()), in );
    ReadBaseObject( STATIC_CAST(Caption *,GetObject()), in );
    return GetObject();
}

// Changed
void CaptionedRectangle::Streamer::Write( opstream& out ) const
{
    WriteBaseObject( STATIC_CAST(TRectangle *,GetObject()), out );
    WriteBaseObject( STATIC_CAST(Caption *,GetObject()), out );
}

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  class CaptionedEllipse                                                */
/*                                                                        */
/*      class CaptionedEllipse draws an ellipse on the                    */
/*      screen, with a caption centered in the ellipse.                   */
/*                                                                        */
/*  Member functions:                                                     */
/*                                                                        */
/*      CaptionedEllipse( TPoint p1, TPoint p2,                           */
/*                        const string& txt )                             */
/*                                                                        */
/*          Creates a CaptionedEllipse with the specified                 */
/*          bounding box and text.                                        */
/*                                                                        */
/*      void ImplementDraw( TDC& );                                       */
/*                                                                        */
/*          Draws the ellipse and its text.                               */
/*                                                                        */
/*      virtual void DoDraw( TDC& );                                      */
/*                                                                        */
/*          Overrides GraphicalObject::DoDraw and draws the ellipse by    */
/*          calling ImplementDraw().                                      */
/*                                                                        */
/*------------------------------------------------------------------------*/

class CaptionedEllipse : public TEllipse, public Caption
{

public:

    CaptionedEllipse( TPoint p1, TPoint p2, const string& txt );

protected:

    void ImplementDraw( TDC& );

private:

    virtual void DoDraw( TDC& );

    DECLARE_STREAMABLE( , CaptionedEllipse, 1 );    // Changed

};

CaptionedEllipse::CaptionedEllipse( TPoint p1, TPoint p2, const string& txt ) :
    GraphicalObject( p1, p2 ),
    TEllipse( p1, p2 ),
    Caption( txt, T_CENTER )
{
}

void CaptionedEllipse::ImplementDraw( TDC& dc )
{
    TEllipse::ImplementDraw( dc );
    Caption::ImplementDraw( dc );
}

void CaptionedEllipse::DoDraw( TDC& dc )
{
    ImplementDraw( dc );
}

// Changed
IMPLEMENT_CASTABLE2( CaptionedEllipse, TEllipse, Caption );
IMPLEMENT_STREAMABLE3( CaptionedEllipse, TEllipse, Caption, GraphicalObject );

// Changed
void *CaptionedEllipse::Streamer::Read( ipstream& in, uint32 ) const
{
    ReadBaseObject( STATIC_CAST(TEllipse *,GetObject()), in );
    ReadBaseObject( STATIC_CAST(Caption *,GetObject()), in );
    return GetObject();
}

// Changed
void CaptionedEllipse::Streamer::Write( opstream& out ) const
{
    WriteBaseObject( STATIC_CAST(TEllipse *,GetObject()), out );
    WriteBaseObject( STATIC_CAST(Caption *,GetObject()), out );
}

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  class TObjectBuilder                                                  */
/*                                                                        */
/*      class TObjectBuilder provides the core functionality for          */
/*      building objects derived from GraphicalObject in a Windows        */
/*      environment. It handles changing the cursor to one that           */
/*      indicates the type of object being built, clipping the cursor     */
/*      so that it stays within the application's client area,            */
/*      handles anchoring the object's bounding box and dragging the      */
/*      unanchored corner of the bounding box.                            */
/*                                                                        */
/*  Public member functions:                                              */
/*                                                                        */
/*      TObjectBuilder( TWindow& owner, int cursorId );                   */
/*                                                                        */
/*          Clips the cursor so that it stays within the owner's          */
/*          client area and replaces the default cursor with the          */
/*          cursor contained in the resource identified by cursorId.      */
/*                                                                        */
/*      ~TObjectBuilder();                                                */
/*                                                                        */
/*          Restores the default cursor and ends the clipping.            */
/*                                                                        */
/*                                                                        */
/*      void SetAnchor( TPoint pos );                                     */
/*                                                                        */
/*          Sets the anchor point of the bounding box to the point pos.   */
/*                                                                        */
/*      void Drag( TPoint pos );                                          */
/*                                                                        */
/*          Moves the unanchored corner of the bounding box to the        */
/*          point pos, drawing the object's skeleton as appropriate.      */
/*          See DrawSkeleton().                                           */
/*                                                                        */
/*      GraphicalObject *CreateObject();                                  */
/*                                                                        */
/*          Returns a pointer to the newly created object derived         */
/*          from GraphicalObject and contained within the bounding box    */
/*          delimited by the anchor point and the unanchored corner as    */
/*          set up by SetAnchor() and Drag() and cleans up whatever       */
/*          needs to be cleaned up. See BuildObject().                    */
/*                                                                        */
/*      void Cancel()                                                     */
/*                                                                        */
/*          Cleans up whatever needs to be cleaned up when the object is  */
/*          not wanted.                                                   */
/*                                                                        */
/*  Protected member functions:                                           */
/*                                                                        */
/*      const TWindow& GetOwner() const;                                  */
/*                                                                        */
/*          Returns a reference to the TWindow that owns the client       */
/*          area that we're drawing to.                                   */
/*                                                                        */
/*  Virtual functions:                                                    */
/*                                                                        */
/*      void DrawSkeleton( TDC& dc, TPoint p1, TPoint p2 ) const = 0;     */
/*                                                                        */
/*          This must be overridden by the derived class. It is called    */
/*          from Drag() to erase the previously drawn skeleton which      */
/*          was drawn at p1 and p2, and it is called again to draw the    */
/*          new skeleton at positions p1 and p2. The skeleton should be   */
/*          some sort of simple line representation of the object being   */
/*          built.                                                        */
/*                                                                        */
/*      GraphicalObject *BuildObject( TPoint p1, TPoint p2 ) = 0;         */
/*                                                                        */
/*          Called from CreateObject() to actually build the desired      */
/*          object, with its bounding box defined by p1 and p2. Typically */
/*          this just calls a constructor for the desired object.         */
/*                                                                        */
/*------------------------------------------------------------------------*/

class TObjectBuilder
{

public:

    TObjectBuilder( TWindow& owner, int cursorId );
    virtual ~TObjectBuilder();

    void SetAnchor( TPoint pos );
    void Drag( TPoint pos );
    GraphicalObject *CreateObject();
    void Cancel() const;

protected:

    const TWindow& GetOwner() const { return Owner; }


private:

    class BuilderDC : public TClientDC
    {
    public:
        BuilderDC( HWND wnd );
        ~BuilderDC();
    };

    virtual void DrawSkeleton( TDC& dc, TPoint p1, TPoint p2 ) const = 0;
    virtual GraphicalObject *BuildObject( TPoint p1, TPoint p2 ) = 0;

    TPoint Anchor;
    TPoint Current;
    int Anchored;

    HCURSOR OldCursor;
    TWindow& Owner;

    TObjectBuilder( const TObjectBuilder& );
    const TObjectBuilder& operator = ( const TObjectBuilder& );

};

TObjectBuilder::TObjectBuilder( TWindow& owner, int cursorId ) :
    Owner(owner),
    Anchored(0)
{
    TRect Rect;
    Owner.GetWindowRect( Rect );
    ClipCursor( &Rect );
    Owner.SetCursor( Owner.GetApplication(), cursorId );
}

TObjectBuilder::~TObjectBuilder()
{
    Owner.SetCursor( 0, IDC_ARROW );
    ClipCursor(0);
}

void TObjectBuilder::SetAnchor( TPoint point )
{
    Anchor = Current = point;
    BuilderDC dc( Owner );
    DrawSkeleton( dc, Anchor, Current );
    Anchored = 1;
}

void TObjectBuilder::Drag( TPoint point )
{
    if( Anchored )
        {
        BuilderDC dc( Owner );
        DrawSkeleton( dc, Anchor, Current );
        Current = point;
        DrawSkeleton( dc, Anchor, Current );
        }
}

GraphicalObject *TObjectBuilder::CreateObject()
{
    return BuildObject( Anchor, Current );
}

void TObjectBuilder::Cancel() const
{
    if( Anchored )
        {
        BuilderDC dc( Owner );
        DrawSkeleton( dc, Anchor, Current );
        }
}

TObjectBuilder::BuilderDC::BuilderDC( HWND wnd ) : TClientDC( wnd )
{
    SelectStockObject(WHITE_PEN);
    SetROP2( R2_XORPEN );
    SelectStockObject(NULL_BRUSH);
}

TObjectBuilder::BuilderDC::~BuilderDC()
{
}

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  class LineBuilder                                                     */
/*                                                                        */
/*      class LineBuilder builds a Line object using the mechanisms       */
/*      provided by TObjectBuilder.                                       */
/*                                                                        */
/*  Member functions:                                                     */
/*                                                                        */
/*      LineBuilder( TWindow& owner );                                    */
/*                                                                        */
/*          Initializes a LineBuilder that will draw its skeleton inside  */
/*          the client area of owner.                                     */
/*                                                                        */
/*      void DrawSkeleton( TDC& dc, TPoint p1, TPoint p2 ) const;         */
/*                                                                        */
/*          Overrides TObjectBuilder::DrawSkeleton to draw the skeleton   */
/*          for a line, which is just a line from p1 to p2.               */
/*                                                                        */
/*      GraphicalObject *BuildObject( TPoint p1, TPoint p2 );             */
/*                                                                        */
/*          Overrides TObjectBuilder::BuildObject to build a Line         */
/*          object with its endpoints at p1 and p2.                       */
/*                                                                        */
/*------------------------------------------------------------------------*/

class LineBuilder : public TObjectBuilder
{

public:

    LineBuilder( TWindow& owner );

private:

    virtual void DrawSkeleton( TDC& dc, TPoint p1, TPoint p2 ) const;
    virtual GraphicalObject *BuildObject( TPoint p1, TPoint p2 );

};

LineBuilder::LineBuilder( TWindow& owner ) :
    TObjectBuilder( owner, LINE_CURSOR )
{
}

void LineBuilder::DrawSkeleton( TDC& dc, TPoint p1, TPoint p2 ) const
{
    dc.MoveTo( p1.x, p1.y );
    dc.LineTo( p2.x, p2.y );
}

GraphicalObject *LineBuilder::BuildObject( TPoint p1, TPoint p2 )
{
    return new Line( p1, p2 );
}

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  class RectangleBuilder                                                */
/*                                                                        */
/*      class RectangleBuilder builds a TRectangle object using the       */
/*      mechanisms provided by TObjectBuilder.                            */
/*                                                                        */
/*  Member functions:                                                     */
/*                                                                        */
/*      RectangleBuilder( TWindow& owner );                               */
/*                                                                        */
/*          Initializes a RectangleBuilder that will draw its skeleton    */
/*          inside the client area of owner.                              */
/*                                                                        */
/*      void DrawSkeleton( TDC& dc, TPoint p1, TPoint p2 ) const;         */
/*                                                                        */
/*          Overrides TObjectBuilder::DrawSkeleton to draw the skeleton   */
/*          for a TRectangle, which is a rectangle whose upper left       */
/*          corner is at p1 and whose lower right corner is at p2.        */
/*                                                                        */
/*      GraphicalObject *BuildObject( TPoint p1, TPoint p2 );             */
/*                                                                        */
/*          Overrides TObjectBuilder::BuildObject to build a TRectangle   */
/*          object with its upper left corner at p1 and its lower right   */
/*          corner at p2.                                                 */
/*                                                                        */
/*------------------------------------------------------------------------*/

class RectangleBuilder : public TObjectBuilder
{

public:

    RectangleBuilder( TWindow& owner );

private:

    virtual void DrawSkeleton( TDC& dc, TPoint p1, TPoint p2 ) const;
    virtual GraphicalObject *BuildObject( TPoint p1, TPoint p2 );

};

RectangleBuilder::RectangleBuilder( TWindow& owner ) :
    TObjectBuilder( owner, RECT_CURSOR )
{
}

void RectangleBuilder::DrawSkeleton( TDC& dc, TPoint p1, TPoint p2 ) const
{
    dc.Rectangle( p1, p2 );
}

GraphicalObject *RectangleBuilder::BuildObject( TPoint p1, TPoint p2 )
{
    return new TRectangle( p1, p2 );
}

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  class EllipseBuilder                                                  */
/*                                                                        */
/*      class EllipseBuilder builds a TEllipse object using the           */
/*      mechanisms provided by TObjectBuilder.                            */
/*                                                                        */
/*  Member functions:                                                     */
/*                                                                        */
/*      EllipseBuilder( TWindow& owner );                                 */
/*                                                                        */
/*          Initializes an EllipseBuilder that will draw its skeleton     */
/*          inside the client area of owner.                              */
/*                                                                        */
/*      void DrawSkeleton( TDC& dc, TPoint p1, TPoint p2 ) const;         */
/*                                                                        */
/*          Overrides TObjectBuilder::DrawSkeleton to draw the skeleton   */
/*          for a TEllipse, which is an ellipse with a bounding box whose */
/*          upper left corner is at p1 and whose lower right corner is    */
/*          at p2.                                                        */
/*                                                                        */
/*      GraphicalObject *BuildObject( TPoint p1, TPoint p2 );             */
/*                                                                        */
/*          Overrides TObjectBuilder::BuildObject to build a TEllipse     */
/*          object with a bounding box whose upper left corner is at p1   */
/*          and whose lower right corner is at p2.                        */
/*                                                                        */
/*------------------------------------------------------------------------*/

class EllipseBuilder : public TObjectBuilder
{

public:

    EllipseBuilder( TWindow& owner );

private:

    virtual void DrawSkeleton( TDC& dc, TPoint p1, TPoint p2 ) const;
    virtual GraphicalObject *BuildObject( TPoint p1, TPoint p2 );

};

EllipseBuilder::EllipseBuilder( TWindow& owner ) :
    TObjectBuilder( owner, ELLIPSE_CURSOR )
{
}

void EllipseBuilder::DrawSkeleton( TDC& dc, TPoint p1, TPoint p2 ) const

{
    dc.Ellipse( p1, p2 );
}

GraphicalObject *EllipseBuilder::BuildObject( TPoint p1, TPoint p2 )
{
    return new TEllipse( p1, p2 );
}

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  class CaptionBuilder                                                  */
/*                                                                        */
/*      class CaptionBuilder provides a base class for use by builders    */
/*      of captioned objects. It does not inherit from TObjectBuilder.    */
/*      It is expected that this class will be mixed in with a class      */
/*      that does inherit from TObjectBuilder. See, for example,          */
/*      CaptionedRectangleBuilder.                                        */
/*                                                                        */
/*  Member functions:                                                     */
/*                                                                        */
/*      CaptionBuilder( TWindow& owner, int allowPosition );              */
/*                                                                        */
/*          Initializes a CaptionBuilder that will belong to the TWindow  */
/*          owner. allowPosition is a flag that indicates whether the     */
/*          user should be allowed to specify the placement of the        */
/*          caption. If allowPosition is non-zero, the dialog box that    */
/*          prompts for the caption also allows the user to specify       */
/*          whether the caption should be at the top, in the center, or   */
/*          at the bottom of the object. If allowPosition is 0 this       */
/*          part of the dialog box is grayed out.                         */
/*                                                                        */
/*      string GetCaption();                                              */
/*                                                                        */
/*          Retrieves the text of the caption specified by the user. If   */
/*          the user hasn't been asked for the caption yet GetCaption()   */
/*          puts up a dialog box requesting input from the user.          */
/*                                                                        */
/*      Caption::TextLoc GetLocation();                                   */
/*                                                                        */
/*          Retrieves the location for the caption specified by the user. */
/*          If the user hasn't been asked for the caption yet             */
/*          GetLocation() puts up a dialog box requesting input from the  */
/*          user. If allowPosition was 0 GetLocation() returns T_TOP.     */
/*                                                                        */
/*------------------------------------------------------------------------*/

class CaptionBuilder
{

public:

    CaptionBuilder( TWindow& owner, int allowPosition = 1 );
    string GetCaption();
    Caption::TextLoc GetLocation();

private:

    void GetData();
    int HaveData;
    string Caption;
    Caption::TextLoc Location;
    TWindow& Owner;
    int AllowPosition;

    class CaptionDialog : public TDialog
    {
    public:
        CaptionDialog( TWindow& parent, CaptionBuilder& builder );
        BOOL CanClose();
        void SetupWindow();
    private:
        void TopClicked();
        void CenterClicked();
        void BottomClicked();
        CaptionBuilder& Builder;
    DECLARE_RESPONSE_TABLE( CaptionDialog );
    };

    friend CaptionDialog;

};

CaptionBuilder::CaptionBuilder( TWindow& owner, int allowPosition ) :
    HaveData(0),
    Location(Caption::T_TOP),
    Owner(owner),
    AllowPosition(allowPosition)
{
}

void CaptionBuilder::GetData()
{
    if( !HaveData )
        {
        CaptionDialog dialog( Owner, *this );
        dialog.Execute();
        HaveData = 1;
        }
}

string CaptionBuilder::GetCaption()
{
    GetData();
    return Caption;
}

Caption::TextLoc CaptionBuilder::GetLocation()
{
    GetData();
    return Location;
}

DEFINE_RESPONSE_TABLE1( CaptionBuilder::CaptionDialog, TDialog )
    EV_CHILD_NOTIFY( IDD_TOP, BN_CLICKED, TopClicked ),
    EV_CHILD_NOTIFY( IDD_CENTER, BN_CLICKED, CenterClicked ),
    EV_CHILD_NOTIFY( IDD_BOTTOM, BN_CLICKED, BottomClicked ),
END_RESPONSE_TABLE;

CaptionBuilder::CaptionDialog::CaptionDialog( TWindow& parent, CaptionBuilder& builder ) :
    TDialog( &parent, "CaptionDlg" ),
    Builder(builder)
{
}

void CaptionBuilder::CaptionDialog::SetupWindow()
{
    if( Builder.AllowPosition )
        SendDlgItemMessage( IDD_TOP, BM_SETCHECK, 1, 0L );
    else
        {
        ::EnableWindow( GetDlgItem( IDD_TOP ), 0 );
        ::EnableWindow( GetDlgItem( IDD_CENTER ), 0 );
        ::EnableWindow( GetDlgItem( IDD_BOTTOM ), 0 );
        ::EnableWindow( GetDlgItem( IDD_POSITIONBOX ), 0 );
        }
}

BOOL CaptionBuilder::CaptionDialog::CanClose()
{
    char buf[256];
    GetDlgItemText( IDD_INPUTEDITBOX, buf, sizeof(buf) );
    Builder.Caption = buf;
    return TRUE;
}

void CaptionBuilder::CaptionDialog::TopClicked()
{
    Builder.Location = Caption::T_TOP;
}

void CaptionBuilder::CaptionDialog::CenterClicked()
{
    Builder.Location = Caption::T_CENTER;
}

void CaptionBuilder::CaptionDialog::BottomClicked()
{
    Builder.Location = Caption::T_BOTTOM;
}

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  class CaptionedRectangleBuilder                                       */
/*                                                                        */
/*      class CaptionedRectangleBuilder builds a CaptionedRectangle       */
/*      object using the mechanisms provided by TObjectBuilder.           */
/*                                                                        */
/*  Member functions:                                                     */
/*                                                                        */
/*      CaptionedRectangleBuilder( TWindow& owner );                      */
/*                                                                        */
/*          Initializes a CaptionedRectangleBuilder that will draw its    */
/*          skeleton inside the client area of owner and prompt for the   */
/*          caption after the bounding box has been defined.              */
/*                                                                        */
/*      void DrawSkeleton( TDC& dc, TPoint p1, TPoint p2 ) const;         */
/*                                                                        */
/*          Overrides TObjectBuilder::DrawSkeleton to draw the skeleton   */
/*          for a CaptionedRectangle, which is a rectangle whose upper    */
/*          left corner is at p1 and whose lower right corner is at p2.   */
/*                                                                        */
/*      GraphicalObject *BuildObject( TPoint p1, TPoint p2 );             */
/*                                                                        */
/*          Overrides TObjectBuilder::BuildObject to build a              */
/*          CaptionedRectangle object with its upper left corner at p1    */
/*          and its lower right corner at p2.                             */
/*                                                                        */
/*------------------------------------------------------------------------*/

class CaptionedRectangleBuilder : public RectangleBuilder, private CaptionBuilder
{

public:

    CaptionedRectangleBuilder( TWindow& owner );

private:

    virtual GraphicalObject *BuildObject( TPoint p1, TPoint p2 );

};

CaptionedRectangleBuilder::CaptionedRectangleBuilder( TWindow& owner ) :
    RectangleBuilder( owner ),
    CaptionBuilder( owner )
{
}

GraphicalObject *CaptionedRectangleBuilder::BuildObject( TPoint p1, TPoint p2 )
{
    return new CaptionedRectangle( p1, p2, GetCaption(), GetLocation() );
}

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  class CaptionedEllipseBuilder                                         */
/*                                                                        */
/*      class CaptionedEllipseBuilder builds a CaptionedEllipse           */
/*      object using the mechanisms provided by TObjectBuilder.           */
/*                                                                        */
/*  Member functions:                                                     */
/*                                                                        */
/*      CaptionedEllipseBuilder( TWindow& owner );                        */
/*                                                                        */
/*          Initializes a CaptionedRectangleBuilder that will draw its    */
/*          skeleton inside the client area of owner and prompt for the   */
/*          caption after the bounding box has been defined.              */
/*                                                                        */
/*      void DrawSkeleton( TDC& dc, TPoint p1, TPoint p2 ) const;         */
/*                                                                        */
/*          Overrides TObjectBuilder::DrawSkeleton to draw the skeleton   */
/*          for a CaptionedEllipse, which is an ellipse with a bounding   */
/*          box whose upper left corner is at p1 and whose lower right    */
/*          corner is at p2.                                              */
/*                                                                        */
/*      GraphicalObject *BuildObject( TPoint p1, TPoint p2 );             */
/*                                                                        */
/*          Overrides TObjectBuilder::BuildObject to build a              */
/*          CaptionedEllipse object with a bounding box whose upper left  */
/*          corner is at p1 and whose lower right corner is at p2.        */
/*                                                                        */
/*------------------------------------------------------------------------*/

class CaptionedEllipseBuilder : public EllipseBuilder, public CaptionBuilder
{

public:

    CaptionedEllipseBuilder( TWindow& owner );

private:

    virtual GraphicalObject *BuildObject( TPoint p1, TPoint p2 );

};

CaptionedEllipseBuilder::CaptionedEllipseBuilder( TWindow& owner ) :
    EllipseBuilder( owner ),
    CaptionBuilder( owner, 0 )
{
}

GraphicalObject *CaptionedEllipseBuilder::BuildObject( TPoint p1, TPoint p2 )
{
    return new CaptionedEllipse( p1, p2, GetCaption() );
}

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  class TGraphWindow                                                    */
/*                                                                        */
/*      class TGraphWindow pulls all of the forgoing together into a      */
/*      rather limited shape editor. It uses a TISetAsVector to hold      */
/*      the various objects that are in the current drawing.              */
/*                                                                        */
/*  Member functions:                                                     */
/*                                                                        */
/*      TGraphWindow();                                                   */
/*                                                                        */
/*          Initializes the window.                                       */
/*                                                                        */
/*      void Paint( TDC&, BOOL, TRect& );                                 */
/*                                                                        */
/*          Called whenever the window receives a WM_PAINT message. Draws */
/*          the objects by calling each of their Draw() functions.        */
/*                                                                        */
/*      void CmNew();                                                     */
/*                                                                        */
/*          Called when the user selects File/New from the menu. Removes  */
/*          all objects from the current drawing.                         */
/*                                                                        */
/*      void CmLine();                                                    */
/*                                                                        */
/*          Called when the user selects Edit/Line from the menu. Adds    */
/*          a line to the drawing.                                        */
/*                                                                        */
/*      void CmRectangle();                                               */
/*                                                                        */
/*          Called when the user selects Edit/Rectangle from the menu.    */
/*          Adds a rectangle to the drawing.                              */
/*                                                                        */
/*      void CmCaptionedRectangle();                                      */
/*                                                                        */
/*          Called when the user selects Edit/CaptionedRectangle from the */
/*          menu. Adds a captioned rectangle to the drawing.              */
/*                                                                        */
/*      void CmEllipse();                                                 */
/*                                                                        */
/*          Called when the user selects Edit/Ellipse from the menu.      */
/*          Adds an ellipse to the drawing.                               */
/*                                                                        */
/*      void CmCaptionedEllipse();                                        */
/*                                                                        */
/*          Called when the user selects Edit/CaptionedEllipse from the   */
/*          menu. Adds a captioned ellipse to the drawing.                */
/*                                                                        */
/*      void CmAbout();                                                   */
/*                                                                        */
/*          Called when the user selects Help/About from the menu.        */
/*          Displays the About box.                                       */
/*                                                                        */
/*      void EvLButtonDown();                                             */
/*                                                                        */
/*          Called when the user presses the left mouse button. During    */
/*          building of an object, this anchors the object's bounding     */
/*          box at the current position of the mouse.                     */
/*                                                                        */
/*      void EvLButtonUp();                                               */
/*                                                                        */
/*          Called when the user releases the left mouse button. During   */
/*          building of an object, this creates the actual object with    */
/*          its bounding box defined by the previous anchor position and  */
/*          the current position of the mouse.                            */
/*                                                                        */
/*      void EvRButtonDown();                                             */
/*                                                                        */
/*          Called when the user presses the right mouse button. During   */
/*          building of an object, this terminates building.              */
/*                                                                        */
/*      void EvMouseMove();                                               */
/*                                                                        */
/*          Called when the user moves the mouse. During building of an   */
/*          object, if the object's bounding box has been anchored, this  */
/*          drags the free corner of the bounding box.                    */
/*                                                                        */
/*------------------------------------------------------------------------*/

class TGraphWindow : public TWindow
{

public:

    TGraphWindow();

    void Paint(TDC&, BOOL, TRect&);

    void CmNew();
    void CmLine();
    void CmRectangle();
    void CmCaptionedRectangle();
    void CmEllipse();
    void CmCaptionedEllipse();
    void CmAbout();

    void CmFileOpen();      // Changed
    void CmFileSave();      // Changed
    void CmFileSaveAs();    // Changed

    void EvLButtonDown( UINT modKeys, TPoint& point );
    void EvLButtonUp( UINT modKeys, TPoint& point );
    void EvRButtonDown( UINT modKeys, TPoint& point );
    void EvMouseMove( UINT modKeys, TPoint& point );

    BOOL CanClose();    // Changed

    TOpenSaveDialog::TData FileData;    // Changed

private:

    int SaveFile();         // Changed
    int SaveFileAs();       // Changed
    void ReadObjects();     // Changed
    void WriteObjects();    // Changed
    int CheckAndClear();    // Changed
    int OkToClear();        // Changed
    static void WriteObject( GraphicalObject &obj, void * );    // Changed

    TObjectBuilder *Builder;

    void FlushObjects();
    void AddObject( GraphicalObject *obj );
    static void DrawObject( GraphicalObject &obj, void * );
    TISetAsVector<GraphicalObject> Objects;

    int WindowIsDirty;          // Changed

    class GraphWindowDC
    {
    public:
        GraphWindowDC( TDC& );
        ~GraphWindowDC();
        operator TDC&() const;
    private:
        TDC& DC;
        WORD OldFlags;
        TPen Pen;
    };

    DECLARE_RESPONSE_TABLE(TGraphWindow);

};

DEFINE_RESPONSE_TABLE1( TGraphWindow, TWindow )
    EV_COMMAND( CM_FILENEW, CmNew ),
    EV_COMMAND( CM_FILEOPEN, CmFileOpen ),      // Changed
    EV_COMMAND( CM_FILESAVE, CmFileSave ),      // Changed
    EV_COMMAND( CM_FILESAVEAS, CmFileSaveAs ),  // Changed
    EV_COMMAND( CM_EDITLINE, CmLine ),
    EV_COMMAND( CM_EDITRECTANGLE, CmRectangle ),
    EV_COMMAND( CM_EDITCAPTIONEDRECTANGLE, CmCaptionedRectangle ),
    EV_COMMAND( CM_EDITELLIPSE, CmEllipse ),
    EV_COMMAND( CM_EDITCAPTIONEDELLIPSE, CmCaptionedEllipse ),
    EV_COMMAND( CM_HELPABOUT, CmAbout ),
    EV_WM_LBUTTONDOWN,
    EV_WM_LBUTTONUP,
    EV_WM_RBUTTONDOWN,
    EV_WM_MOUSEMOVE,
END_RESPONSE_TABLE;

TGraphWindow::GraphWindowDC::GraphWindowDC( TDC& dc ) :
    DC(dc),
    Pen(::GetSysColor(COLOR_WINDOWTEXT))
{
    OldFlags = DC.SetTextAlign( TA_CENTER );
    DC.SelectObject( Pen );
    DC.SetBkColor( ::GetSysColor( COLOR_WINDOW ) );
}

TGraphWindow::GraphWindowDC::~GraphWindowDC()
{
    DC.RestorePen();
    DC.SetTextAlign( OldFlags );
}

TGraphWindow::GraphWindowDC::operator TDC&() const
{
    return DC;
}

// Changed
TGraphWindow::TGraphWindow() :
    TWindow( 0, 0, 0 ),
    Builder(0),
    FileData(OFN_FILEMUSTEXIST|OFN_HIDEREADONLY|OFN_PATHMUSTEXIST,
             "Stream Files (*.stm)|*.stm|All Files (*.*)|*.*|",
             0, "", "*"),
    WindowIsDirty(0)
{
}

void TGraphWindow::DrawObject( GraphicalObject &obj, void *ptr )
{
    obj.Draw( *(GraphWindowDC *)ptr );
}

void TGraphWindow::Paint( TDC& dc, BOOL, TRect& )
{
    GraphWindowDC gdc(dc);
    Objects.ForEach( DrawObject, &gdc );
}

void TGraphWindow::CmNew()
{
    if( CheckAndClear() )
        Invalidate();
}

// Changed
void TGraphWindow::CmFileOpen()
{
    if( CheckAndClear() )
        {
        *FileData.FileName = 0;
        TFileOpenDialog dlg( this, FileData );
        if( dlg.Execute() == IDOK )
            {
            ReadObjects();
            Invalidate();
            }
        }
}

// Changed
void TGraphWindow::CmFileSave()
{
    SaveFile();
}

// Changed
int TGraphWindow::SaveFile()
{
    if( *FileData.FileName == '\0' )
        return SaveFileAs();
    else
        {
        WriteObjects();
        return 1;
        }
}

// Changed
void TGraphWindow::CmFileSaveAs()
{
    SaveFileAs();
}

// Changed
int TGraphWindow::SaveFileAs()
{
    *FileData.FileName = '\0';
    TFileSaveDialog dlg( this, FileData );
    if( dlg.Execute() == IDOK )
        {
        WriteObjects();
        return 1;
        }
    else
        return 0;
}

// Changed
void TGraphWindow::ReadObjects()
{
    ifpstream in( FileData.FileName );
    int count;
    in >> count;
    while( count-- != 0 )
        {
        GraphicalObject *object;
        in >> object;
        AddObject( object );
        }
    WindowIsDirty = 0;
}

// Changed
void TGraphWindow::WriteObject( GraphicalObject& obj, void *data )
{
    *(ofpstream *)data << &obj;
}

// Changed
void TGraphWindow::WriteObjects()
{
    ofpstream out( FileData.FileName );
    out << Objects.GetItemsInContainer();
    Objects.ForEach( WriteObject, &out );
    WindowIsDirty = 0;
}

// Changed
int TGraphWindow::CheckAndClear()
{
    if( OkToClear() )
        {
        FlushObjects();
        return 1;
        }
    else
        return 0;
}

// Changed
int TGraphWindow::OkToClear()
{
    if( !WindowIsDirty )
        return 1;
    else
        {
        string msg;
        if( *FileData.FileName == 0 )
            msg = "<untitled>";
        else
            msg = FileData.FileName;
        msg += " has not been saved. Save before closing?";
        int res = MessageBox( msg.c_str(), GetApplication()->GetName(),
                              MB_ICONEXCLAMATION | MB_YESNOCANCEL );
        switch( res )
            {
            case IDYES:
                return SaveFile();
            case IDNO:
                return 1;
            case IDCANCEL:
                return 0;
            }
        return 0;
        }
}

void TGraphWindow::CmLine()
{
    Builder = new LineBuilder( *this );
}

void TGraphWindow::CmRectangle()
{
    Builder = new RectangleBuilder( *this );
}

void TGraphWindow::CmCaptionedRectangle()
{
    Builder = new CaptionedRectangleBuilder( *this );
}

void TGraphWindow::CmEllipse()
{
    Builder = new EllipseBuilder( *this );
}

void TGraphWindow::CmCaptionedEllipse()
{
    Builder = new CaptionedEllipseBuilder( *this );
}

void TGraphWindow::CmAbout()
{
    TDialog dlg( this, "About" );
    dlg.Execute();
}

// Changed
BOOL TGraphWindow::CanClose()
{
    return CheckAndClear();
}

void TGraphWindow::AddObject( GraphicalObject *object )
{
    Objects.Add( object );
    WindowIsDirty = 1;      // Changed
}

void TGraphWindow::FlushObjects()
{
    Objects.Flush();
    WindowIsDirty = 0;      // Changed
}

void TGraphWindow::EvLButtonDown( UINT modKeys, TPoint& point )
{
    if( Builder == 0 )
        TWindow::EvLButtonDown( modKeys, point );
    else
        Builder->SetAnchor(point);
}

void TGraphWindow::EvLButtonUp( UINT modKeys, TPoint& point )
{
    if( Builder == 0 )
        TWindow::EvLButtonUp( modKeys, point );
    else
        {
        AddObject( Builder->CreateObject() );
        delete Builder;
        Builder = 0;
        Invalidate();
        }
}

void TGraphWindow::EvRButtonDown( UINT modKeys, TPoint& point )
{
    if( Builder == 0 )
        TWindow::EvRButtonDown( modKeys, point );
    else
        {
        Builder->Cancel();
        delete Builder;
        Builder = 0;
        }
}

void TGraphWindow::EvMouseMove( UINT modKeys, TPoint& point )
{
    if( Builder == 0 )
        TWindow::EvMouseMove( modKeys, point );
    else
        Builder->Drag( point );
}

class TStreamApp : public TApplication 
{

public:

    TStreamApp() : TApplication() {}

    void InitMainWindow();

};

void TStreamApp::InitMainWindow()
{
    MainWindow = new TFrameWindow( 0, "Streaming Example, version 1",
                                   new TGraphWindow );
    MainWindow->AssignMenu("COMMANDS");
}

int OwlMain( int, char ** )
{
    TStreamApp app;
    return app.Run();
}


