#include "stlexam.h"
#pragma hdrstop
/**************************************************************************
 *
 * deque.cpp - Example program for deque class. See Class Reference Section
 *
 ***************************************************************************
 *
 * (c) Copyright 1994, 1998 Rogue Wave Software, Inc.
 * ALL RIGHTS RESERVED
 *
 * The software and information contained herein are proprietary to, and
 * comprise valuable trade secrets of, Rogue Wave Software, Inc., which
 * intends to preserve as trade secrets such software and information.
 * This software is furnished pursuant to a written license agreement and
 * may be used, copied, transmitted, and stored only in accordance with
 * the terms of such license and with the inclusion of the above copyright
 * notice.  This software and information or any other copies thereof may
 * not be provided or otherwise made available to any other person.
 *
 * Notwithstanding any other lease or license that may pertain to, or
 * accompany the delivery of, this computer software and information, the
 * rights of the Government regarding its use, reproduction and disclosure
 * are as set forth in Section 52.227-19 of the FARS Computer
 * Software-Restricted Rights clause.
 * 
 * Use, duplication, or disclosure by the Government is subject to
 * restrictions as set forth in subparagraph (c)(1)(ii) of the Rights in
 * Technical Data and Computer Software clause at DFARS 252.227-7013.
 * Contractor/Manufacturer is Rogue Wave Software, Inc.,
 * P.O. Box 2328, Corvallis, Oregon 97339.
 *
 * This computer software and information is distributed with "restricted
 * rights."  Use, duplication or disclosure is subject to restrictions as
 * set forth in NASA FAR SUP 18-52.227-79 (April 1985) "Commercial
 * Computer Software-Restricted Rights (April 1985)."  If the Clause at
 * 18-52.227-74 "Rights in Data General" is specified in the contract,
 * then the "Alternate III" clause applies.
 *
 **************************************************************************/

#include <deque>
#include <string>

#ifdef _RW_STD_IOSTREAM
#include <iostream>
#else
#include <iostream.h>
#endif     

#ifndef _RWSTD_NO_NAMESPACE
  using namespace std;
#endif


deque<string,allocator<string> > deck_of_cards; 
deque<string,allocator<string> > current_hand;

void initialize_cards(deque<string,allocator<string> >& cards)
{
   cards.push_front("aceofspades");
   cards.push_front("kingofspades");
   cards.push_front("queenofspades");
   cards.push_front("jackofspades");
   cards.push_front("tenofspades");
   //
   // etc.
   //
}

template <class It, class It2> 
void print_current_hand(It start, It2 end) 
{
   while (start < end) 
     cout << *start++ << endl;
}


template <class It, class It2>
void deal_cards(It, It2 end)
{
   for (int i=0;i<5;i++)
   {
     current_hand.insert(current_hand.begin(),*end);
     deck_of_cards.erase(end++);
   }
}

void play_poker()
{
   initialize_cards(deck_of_cards);
   deal_cards(current_hand.begin(),deck_of_cards.begin()); 
}

int main () 
{
   play_poker();
   print_current_hand(current_hand.begin(),current_hand.end());
   return 0;
}



