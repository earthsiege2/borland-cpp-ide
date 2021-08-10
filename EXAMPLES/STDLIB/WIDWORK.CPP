#include "stlexam.h"
#pragma hdrstop
/**************************************************************************
 *
 * widwork.cpp - widget works, from Chapter 6.3
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

# include <list>
# include <algorithm>
# include <functional>

#ifdef _RW_STD_IOSTREAM
#include <iostream>
#else
#include <iostream.h>
#endif
    
#ifndef _RWSTD_NO_NAMESPACE
using namespace std;
using namespace std::rel_ops;
#endif

class  Widget
{
  public:
    Widget(int a = 0) : id(a) { }
    void operator= (const Widget& rhs) { id = rhs.id; }
    int id;
    friend ostream & operator << (ostream & out, const Widget & w)
        { return out << "Widget " << w.id; }
};

bool operator== (const Widget& lhs, const Widget& rhs)
{ return lhs.id == rhs.id; }

bool operator< (const Widget& lhs, const Widget& rhs)
{ return lhs.id < rhs.id; }

struct WidgetTester : binary_function<Widget, int, bool>
{
  public:
    bool operator () (const Widget & wid, int testid) const
      { return wid.id == testid; }
};

class inventory
{
  public:
    void order (int wid);   // Process order for widget type wid.
    void receive (int wid); // Receive widget of type wid in shipment.
  private:
    list<Widget,allocator<void> > on_hand;
    list<int,allocator<int> > on_order;
};

void inventory::order (int wid)
{
    cout << "Received order for widget type " << wid << endl;
    list<Widget,allocator<void> >::iterator wehave = find_if(on_hand.begin(), on_hand.end(), 
                                            bind2nd(WidgetTester(), wid));
    if (wehave != on_hand.end())
    {
        cout << "Ship " << *wehave << endl;
        on_hand.erase(wehave);
    }
    else
    {
        cout << "Back order widget of type "  << wid  << endl;
        on_order.push_front(wid);
    }
}

void inventory::receive (int wid)
{
    cout << "Received shipment of widget type " << wid << endl;
    list<int,allocator<int> >::iterator weneed = find(on_order.begin(), on_order.end(), wid);
    if (weneed != on_order.end())
    {
        cout << "Ship " << Widget(wid) << " to fill back order" << endl;
        on_order.erase(weneed);
    }
    else
        on_hand.push_front(Widget(wid));
}

int main ()
{
    cout << "Widget Works test program" << endl;

    inventory stock;
    stock.receive(1);
    stock.receive(2);
    stock.receive(3);
    stock.order(2);
    stock.order(2);
    stock.order(3);
    stock.receive(2);
    
    cout << "End of widget words test program" << endl;

    return 0;
}
