#include "stlexam.h"
#pragma hdrstop
/**************************************************************************
 *
 * icecream.cpp - priority queue example program. Section 11.3.1
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

#include <vector>
#include <queue>

#ifdef _RW_STD_IOSTREAM
#include <iostream>
#else
#include <iostream.h>
#endif
    
#ifndef _RWSTD_NO_NAMESPACE
using namespace std;
#endif

//
// Execution event in a descrete event driven simulation.
//

class event
{
  public:
    //
    // Construct sets time of event.
    //
    event (unsigned int t) : time(t) { };
    //
    // Time is a public data field.
    //
    const unsigned int time;
    //
    // Execute event my invoking this method.
    //
    virtual void processEvent() = 0;
};

//
// Needed by some compilers.
//
inline void __destroy (event **) {}

struct eventComparison
{
    bool operator () (const event * left, const event * right)
        { return left->time > right->time; }
};

//
// Framework for discrete event-driven simulations.
//

class simulation
{
  public:
    simulation () : eventQueue(), time(0) {}
    void run ();
    unsigned int time;
    void  scheduleEvent (event * newEvent) { eventQueue.push(newEvent); }
  protected:
    priority_queue<event*, vector<event *,allocator<event*> >, eventComparison > eventQueue;
};

void simulation::run ()
{
    while (! eventQueue.empty())
    {
        event * nextEvent = eventQueue.top();
        eventQueue.pop();
        time = nextEvent->time;
        nextEvent->processEvent();
        delete nextEvent;
    }
}

//
//  Ice cream store simulation.
//

class storeSimulation : public simulation
{
  public:
    storeSimulation() : freeChairs(35), profit(0.0), simulation() { }
        
    bool canSeat (unsigned int numberOfPeople);
    void order   (unsigned int numberOfScoops);
    void leave   (unsigned int numberOfPeople);
    //
    // Data fields.
    //
    unsigned int freeChairs;
    double       profit;  
} theSimulation;

class arriveEvent : public event
{
  public:
    arriveEvent (unsigned int time, unsigned int groupSize)
        : event(time), size(groupSize) { }
    virtual void processEvent();
  private:
    unsigned int size;
};

class orderEvent : public event
{
  public:
    orderEvent (unsigned int time, unsigned int groupSize)
        : event(time), size(groupSize) { }
    virtual void processEvent();
  private:
    unsigned int size;
};

class leaveEvent : public event
{
public:
    leaveEvent (unsigned int time, unsigned int groupSize)
        : event(time), size(groupSize) { }
    virtual void processEvent();
private:
    unsigned int size;
};

//
// Return random integer between 0 and n.
//

int irand (int n) { return (rand()/10) % n; }

void arriveEvent::processEvent ()
{
    if (theSimulation.canSeat(size))
        theSimulation.scheduleEvent(new orderEvent(time + 1 + irand(4), size));
}

void orderEvent::processEvent ()
{
    //
    // Each person orders some number of scoops.
    //
    for (int i = 0; i < size; i++)
        theSimulation.order(1 + irand(4));
    //
    // Then we schedule the leave event.
    //
    theSimulation.scheduleEvent(new leaveEvent(time + 1 + irand(10), size));
}

void leaveEvent::processEvent () { theSimulation.leave(size); }

//
// If sufficient room then seat customers.
//

bool storeSimulation::canSeat (unsigned int numberOfPeople)
{
    cout << "Time: " << time;
    cout << " group of " << numberOfPeople << " customers arrives";
    if (numberOfPeople < freeChairs)
    {
        cout << " is seated" << endl;
        freeChairs -= numberOfPeople;
        return true;
    }
    else
    {
        cout << " no room, they leave" << endl;
        return false;
    }
}

//
// Service icecream, compute profits.
//

void storeSimulation::order (unsigned int numberOfScoops)
{
    cout << "Time: " << time;
    cout << " serviced order for " << numberOfScoops << endl;
    profit += 0.35 * numberOfScoops;
}

//
// People leave, free up chairs.
//

void storeSimulation::leave (unsigned int numberOfPeople)
{
    cout << "Time: " << time;
    cout << " group of size " << numberOfPeople << " leaves" << endl;
    freeChairs += numberOfPeople;
}

int main ()
{
    cout << "Ice Cream Store simulation from Chapter 9"  << endl;
    //
    // Load queue with some number of initial events.
    //
    unsigned int t = 0;
    while (t < 20)
    {
        t += irand(6);
        cout << "pumping queue with event " << t << endl;
        theSimulation.scheduleEvent(new arriveEvent(t, 1 + irand(4)));
    }
    //
    // Run the simulation.
    //
    theSimulation.run();
    cout << "Total profits " << theSimulation.profit << endl;
    
    cout << "End of ice cream store simulation" << endl;

    return 0;
}
    
