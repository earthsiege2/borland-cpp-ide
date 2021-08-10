//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//-------------------------------------------------------------------------
//    minicomp.cpp - uses the TCounter example component
//-------------------------------------------------------------------------
#include "minicomp.h"
#include <stdio.h>
#include <stdlib.h>
#include <condefs.h>
//-------------------------------------------------------------------------
USEUNIT("counter.cpp");
//---------------------------------------------------------------------------
main()
{
  TExample example;

  return 0;
}
//-------------------------------------------------------------------------
TExample::TExample()
{
  TCounter Counter(7);
  int i;

  Counter.OnMultiple = MultipleReached;

  for (i=0; i < 100; i++)
    Counter.Increment();
}
//-------------------------------------------------------------------------
void TExample::MultipleReached(TCounter *Sender)
{
  printf("Multiple=%d reached with val=%d\n", Sender->Multiple, Sender->Val);
}
//-------------------------------------------------------------------------
