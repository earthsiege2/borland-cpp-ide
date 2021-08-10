//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//-------------------------------------------------------------------------
//    counter.h. - example of a small, non-visual counter component
//-------------------------------------------------------------------------
class TCounter;         // forward

typedef void (__closure *TCounterEvent)(TCounter *Sender);
//-------------------------------------------------------------------------
class TCounter 
{
private:
  TCounterEvent FOnMultiple;
  int FVal;
  int FMultiple;
public:
  __property int Val = {read=FVal, write=FVal};
  __property int Multiple = {read=FMultiple};
  __property TCounterEvent OnMultiple = {read=FOnMultiple, write=FOnMultiple};
  void Clear();
  void Increment();
  TCounter(int Multiple);
};
//-------------------------------------------------------------------------
