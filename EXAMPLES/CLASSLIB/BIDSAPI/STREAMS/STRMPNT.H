// ---------------------------------------------------------------------------
// Copyright (C) 1994 Borland International
//  strmpnt.h
// ---------------------------------------------------------------------------
#ifndef STRMPNT_H
#define STRMPNT_H

#include <classlib/objstrm.h>
#include <iostream.h>

//
// T2DPoint
//
// Simple object used for streaming.
// 
const int T2DPointVersion = 1;

class T2DPoint : public virtual TStreamableBase {
  public:
    T2DPoint(int i=0, int j=0);
    virtual void Draw();

  protected:
    int X;
    int Y;

  DECLARE_STREAMABLE(, T2DPoint, T2DPointVersion);
};


// 
// T3DPoint
// 
// Multiple-derived object used for streaming.
// 
const int T3DPointVersion = 2;

class T3DPoint : public T2DPoint {
  public:
    T3DPoint(int i=0, int j=0, int k=0);
    virtual void Draw();

  protected:
    int Z;

  DECLARE_STREAMABLE(, T3DPoint, T3DPointVersion);
};

// 
// TColor
// 
// A non-streamable base class to show streaming of a multiply inherited
// class.
// 
const int TColorVersion=3;

class TColor {
  public:
    TColor(int i=0, int j=0, int k=0);
    virtual void DisplayColor();

  protected:
    int R;
    int G;
    int B;
};

// T2DPointColor                                                   
//    Streaming of a multiply inherited class where one branch     
//    of inheritence is streamable (T2DPoint) and one branch       
//    is not (TColor).                                             
//                                                                 
//    Notice in the definition of                                  
//      Streamer::Read and Streamer::Write                         
//    there's code to stream the data members of the TColor.       
//    If the code is not provided, then the members of TColor      
//    will be lost.                                                
//    If all branches of the inheritence are already streamable,   
//    then the Read and Write functions are easily defined.        
//    For example,                                                 
//        void Derived::Streamer::Write(opstream &os) const        
//        {                                                        
//          WriteBaseObject((Base1 *)GetObject(), os);             
//          WriteBaseObject((Base2 *)GetObject(), os);             
//          ...                                                    
//          os << NewDataMember1;                                  
//          os << NewDataMember2;                                  
//          ...                                                    
//        }                                                        
//    Similarly for the Read function.                             
const int T2DPointColorVersion=3;

class T2DPointColor : public T2DPoint, public TColor {
  public:
    T2DPointColor(int x, int y, int r, int g, int b);
    virtual void Draw();

  DECLARE_STREAMABLE(, T2DPointColor, T2DPointColorVersion);
};

#endif