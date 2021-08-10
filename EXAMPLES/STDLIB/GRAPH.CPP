#include "stlexam.h"
#pragma hdrstop
/**************************************************************************
 *
 * graph.cpp - Graph program.  Section 9.3.2
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

#include <map>
#include <vector>
#include <queue>

#ifdef _RW_STD_IOSTREAM
#include <iostream>
#else
#include <iostream.h>
#endif

#include <string>
#ifndef _RWSTD_NO_NAMESPACE
using namespace std;
#ifndef __BORLANDC__
using namespace std::rel_ops;  // RW_BUG
#endif
#endif

typedef map<string, int, less<string>,allocator<string>  >          stringVector;
typedef map<string, stringVector, less<string>,allocator<string>  > graph;

struct DistancePair
{
    unsigned first;
    string   second;
    DistancePair() : first(0) {}
    DistancePair(unsigned f, const string& s) : first(f), second(s) {}
};

bool operator< (const DistancePair& lhs, const DistancePair& rhs)
{
    return lhs.first < rhs.first;
}

bool operator> (const DistancePair& lhs, const DistancePair& rhs)
{
    return lhs.first > rhs.first;
}

string pendleton("Pendleton");
string pensacola("Pensacola");
string peoria("Peoria");
string phoenix("Phoenix");
string pierre("Pierre");
string pittsburgh("Pittsburgh");
string princeton("Princeton");
string pueblo("Pueblo");

graph cityMap;

void shortestDistance (graph& cityMap, string& start, stringVector& distances)
{
    //
    // Process a priority queue of distances to nodes.
    //
    priority_queue<DistancePair, vector<DistancePair,allocator<DistancePair> >,
        greater<DistancePair> > que;
    que.push(DistancePair(0, start));
    
    while (! que.empty())
    {
        //
        // Pull nearest city from queue.
        //
        int distance = que.top().first;
        string city = que.top().second;
        que.pop();
        //
        // If we haven't seen it already, process it.
        //
        if (0 == distances.count(city))
        {
            //
            // Then add it to shortest distance map.
            //
            distances[city] = distance;
            //
            // And put values into queue.
            //
            const stringVector& cities = cityMap[city];
            stringVector::const_iterator start = cities.begin();
            stringVector::const_iterator stop  = cities.end();
            for (; start != stop; ++start)
                que.push(DistancePair(distance + (*start).second,
                                      (*start).first));
        }
    }
}

int main ()
{
    cout << "Graph example program, from Chapter 7" << endl;

    cityMap[pendleton][phoenix]    = 4;
    cityMap[pendleton][pueblo]     = 8;
    cityMap[pensacola][phoenix]    = 5;
    cityMap[peoria][pittsburgh]    = 5;
    cityMap[peoria][pueblo]        = 3;
    cityMap[phoenix][peoria]       = 4;
    cityMap[phoenix][pittsburgh]   = 10;
    cityMap[phoenix][pueblo]       = 3;
    cityMap[pierre][pendleton]     = 2;
    cityMap[pittsburgh][pensacola] = 4;
    cityMap[princeton][pittsburgh] = 2;
    cityMap[pueblo][pierre]        = 3;
    
    stringVector distances;
    
    shortestDistance(cityMap, pierre, distances);
    stringVector::iterator where;
    for (where = distances.begin(); where != distances.end(); ++where)
        cout << "Distance to: " << (*where).first << ":"
             <<  (*where).second << endl;
        
    cout << "End of graph example program" << endl;

    return 0;
}
