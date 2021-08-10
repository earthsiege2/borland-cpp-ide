//--------------------------------------------------------------------------
// Turbo Meteor -- Copyright (c) 1995, Borland International
//--------------------------------------------------------------------------
#ifndef SPRITE_H
#define SPRITE_H

#include <owl/listbox.h>
#include <math.h>

const MAX_SPEED = 20;

double sind( int angle );
double cosd( int angle );

class SpriteList;  // forward declaration for use in Sprite class

// class Sprite -- a base class for any object which will be displayed
// on the screen.
//
class Sprite {
  friend class SpriteList;   // so the SpriteList class can access
                             // data members
  public:
    Sprite( TSize& aScreenSize ) {
      screenSize = aScreenSize;
      ResetBoundingRect();
      mx=my=0;
      condemned = false;
      next = 0;
      owner = 0;
    }

    virtual ~Sprite();

    void SetMomentum( TSize& newMomentum ) {
      mx = newMomentum.cx;
      my = newMomentum.cy;
    }

    void Condemn() { condemned = true; }

    // Update -- by default, moves sprite based on it's momentum.  Should
    // return a value which will be added to the score
    //
    virtual int Update() {
      origin.x+=mx;
      origin.y+=my;
      Wrap();
      return 0;
    }

    void ResetBoundingRect() { boundingRect = TRect( origin, origin ); }

    // ExpandBoundingRect -- given a point, expand our bounding rectangle
    // to include this point.
    //
    void ExpandBoundingRect( TPoint& p ) {
      if (p.x<boundingRect.left)
        boundingRect.left = p.x;
      if (p.y<boundingRect.top)
        boundingRect.top = p.y;
      if (p.x>boundingRect.right)
        boundingRect.right = p.x;
      if (p.y>boundingRect.bottom)
        boundingRect.bottom = p.y;
      boundingRect.Normalize();
    }

    // Default draw function draws a pixel at the sprites origin
    //
    virtual void Draw( TMemoryDC& dc ) {
      dc.SetPixel( origin, TColor( 255, 255, 255 ) );
    }

    // DebugInfo -- returns string to display in the debugging log window
    //
    virtual const char *DebugInfo() { return "Sprite"; }

    // Wrap -- adjust the sprites origin, if it strays off the edge of
    // the window
    //
    void Wrap() {
      origin.x = (origin.x + screenSize.cx) % screenSize.cx;
      origin.y = (origin.y + screenSize.cy) % screenSize.cy;
    }

  protected:
    SpriteList *owner;         // pointer to the list which contains us
    Sprite     *next;          // pointer to next sprite in the list
    TPoint     origin;         // sprites position in the window
    TRect      boundingRect;   // a rectangle which completely encloses sprite
    double     mx,my;          // current direction of sprite
    TSize      screenSize;     // size of screen which contains the sprite
                               // used to wrap objects from one side of screen to other
    bool       condemned;      // used to mark dead objects

  private:
    Sprite() {}                // to generate compile-time error

};

// SpriteList -- contains a list of sprites.  Contains specific
// functions for collision detection
//
class SpriteList {
  public:
    SpriteList() {
      root = 0;
      count = 0;
    }
   ~SpriteList();

    void    Add( Sprite* sprite );
    void    DrawAll( TMemoryDC& dc );
    void    UpdateLog( TListBox *lb );
    int     UpdateAll();
    Sprite* CheckForHitMeteor( TPoint& p );

    int count;

  private:
    Sprite *root;
};

// the following are defined in sprite.cpp

extern int angle1[10];
extern int radius1[10];
extern int count1;

// Meteor -- a rock, floating in space.  The meteor is specified as
// a series of polor-coordinate points (an angle and a radius).  This
// allows for faster calculation when making the meteors rotate as
// they float about.
//
class Meteor : public Sprite {
  public:
    Meteor( TPoint& aOrigin, TSize& aMomentum, int aSize, int aSpawnCount );

    int GetSize() { return size; }
    void SetRotationAngle( int angle );
    int Update() {
      origin.x+=mx;
      origin.y+=my;
      Wrap();
      currentAngle = (currentAngle+angularMomentum+360)%360;
      return 0;
    };
    void Hit();
    virtual void Draw( TMemoryDC& dc );
    virtual const char *DebugInfo();

  private:
    int    angularMomentum,    // how fast the meteor is spinning
           currentAngle;       // current angle of rotation
    int    angle[10],          // angle and radius of the points
           radius[10];         //   which define the meteor
    int    count;              // # of points which define the meteor
    int    size;               // 1=tiny, 2=medium, 3=large rock
    int    spawnCount;         // how many smaller meteors to create when hit
};

// Shot -- a bullet (5 pixels in a cross pattern)
//
class Shot : public Sprite {
  public:
    Shot( TPoint& aOrigin, TSize& aMomentum, int aTimeToDie ):
      Sprite( TSize(600,400) ) {  //*BBK*
      origin = aOrigin;
      mx = aMomentum.cx;
      my = aMomentum.cy;
      timeToDie = aTimeToDie;
    }

    virtual void Draw( TMemoryDC& dc ) {
      if (timeToDie>0) {
        dc.SetPixel( origin, TColor(255,255,255) );
        dc.SetPixel( origin+TPoint(1,0), TColor(255,255,255) );
        dc.SetPixel( origin+TPoint(0,1), TColor(255,255,255) );
        dc.SetPixel( origin+TPoint(0,-1), TColor(255,255,255) );
        dc.SetPixel( origin+TPoint(-1,0), TColor(255,255,255) );
      }
    }

    virtual int Update();
    virtual const char *DebugInfo() { return "Shot"; }

  private:
    int timeToDie;            // shots dissapear after a set amount of time
};

// Debris -- a spinning line.  it floats about for a few seconds and
// disappears.  the player ship is turned into these when it is destroyed.
//
class Debris : public Sprite {
  public:
    Debris( TPoint& aP1, TPoint& aP2, TSize& screenSize )
    :
      Sprite(screenSize)
    {
      p1 = aP1;
      p2 = aP2;
      mx = random(10)-5;
      my = random(10)-5;
      angularMomentum = random(10)-5;
      timeToDie = 20 + random(5);
    }

    int Update() {
      if (timeToDie>0) {
        p1+=TPoint(mx,my);
        p2+=TPoint(mx,my);
        timeToDie--;
      } else
        Condemn();
      return 0;
    }

    void Draw( TMemoryDC& dc ) {
      dc.MoveTo(p1);
      dc.LineTo(p2);
    }

  private:
    TPoint p1,p2;
    int size;              // length of line
    int angle;             // current angle of spinning line
    int angularMomentum;   // rate of spin
    int timeToDie;
};

// Ship -- the player ship
//
class Ship : public Sprite {
  public:
    Ship( TPoint& pos )
    :
      Sprite( TSize(600,400) )
    {
      origin = pos;
      angle = 0;
      radius=10;
      thrust=0;
      mx=my=0;
    }

    virtual void Draw( TMemoryDC& dc ) {
      TPoint p1,p2,p3,p4;

      p1 = TPoint( radius*sind(angle), radius*cosd(angle) );
      p2 = TPoint( radius*sind(angle+130), radius*cosd(angle+130) );
      p3 = TPoint( (radius/4)*sind(angle+180), (radius/4)*cosd(angle+180) );
      p4 = TPoint( radius*sind(angle+230), radius*cosd(angle+230) );
      dc.MoveTo( p1+origin );
      dc.LineTo( p2+origin );
      dc.LineTo( p3+origin );
      dc.LineTo( p4+origin );
      dc.LineTo( p1+origin );
    }

    void Explode() {
      Condemn();
      TPoint p1,p2,p3,p4;
      p1 = origin + TPoint( radius*sind(angle), radius*cosd(angle) );
      p2 = origin + TPoint( radius*sind(angle+130), radius*cosd(angle+130) );
      p3 = origin + TPoint( (radius/4)*sind(angle+180), (radius/4)*cosd(angle+180) );
      p4 = origin + TPoint( radius*sind(angle+230), radius*cosd(angle+230) );

      owner->Add( new Debris( p1, p2, screenSize ) );
      owner->Add( new Debris( p2, p3, screenSize ) );
      owner->Add( new Debris( p3, p4, screenSize ) );
      owner->Add( new Debris( p4, p1, screenSize ) );
    }

    void Rotate( int adjust ) { angle = (angle+adjust+360)%360; }
    void AddThrust( int adjust ) {
      thrust+=adjust;
      if (thrust<0) thrust=0;
    }
    int Update() {
      int len;
      mx+= thrust*sind( angle );
      my+= thrust*cosd( angle );
      len = (sqrt(mx*mx+my*my));
      if (len>MAX_SPEED) {
        mx = mx/len*MAX_SPEED;
        my = my/len*MAX_SPEED;
        thrust=0;
      }
      origin.x+=mx;
      origin.y+=my;
      Wrap();

      // check to see if we hit a meteor

      Sprite* meteor = owner->CheckForHitMeteor( origin );

      if (meteor)
        return -9999;

      return 0;
    }

    Shot* CreateNewShot() {
      TSize shotDir( 10*sind(angle),10*cosd(angle) );
      TPoint shotOrigin = TPoint( radius*sind( angle ), radius*cosd( angle ) );
      return new Shot( origin+shotOrigin, shotDir+TPoint(mx,my), 20 );
    }

    virtual const char *DebugInfo() { return "Ship"; }

  private:
    int angle,radius,thrust;
};

// Message -- a sprite that can display numbers 0-9, used for score display
//
class Message: public Sprite {
  char *text;
  int  bufferLen;
public:
  Message( TPoint& aOrigin, int aBufferLen );
  ~Message();
  void SetText( const char *aText ) {
    if (strlen(aText) < bufferLen)
      strcpy(text, aText);
//    delete[] text;
//    bufferLen = strlen(aText)+1;
//    text = new char[bufferLen];
  }
  virtual void Draw( TMemoryDC& dc );
  virtual const char *DebugInfo();
};

#endif // SPRITE_H
