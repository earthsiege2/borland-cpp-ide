/*------------------------------------------------------------------------*/
/*                                                                        */
/*  QUEUETST.CPP                                                          */
/*                                                                        */
/*  Copyright (c) 1991, 1993 Borland International                        */
/*  All Rights Reserved.                                                  */
/*                                                                        */
/*  TQueue example file                                                   */
/*                                                                        */
/*------------------------------------------------------------------------*/

#ifndef __CLASSLIB__TIME_H__
#include "classlib\time.h"
#endif  // __LTIME_H

#ifndef __QUEUES_H
#include "classlib\queues.h"
#endif  // __QUEUE_H

#ifndef __IOSTREAM_H
#include <iostream.h>
#endif

#ifndef __DOS_H
#include <dos.h>
#endif

#ifndef __STDLIB_H
#include <stdlib.h>
#endif


int main()
{

    randomize();
    TQueue<TTime> TimeLine;
    cout << "\nSampling";
    for( int i = 0; i < 7; i++ )
        {
        TTime SnapShot;
        TimeLine.Put( SnapShot );
        cout << ".";
        int k = rand();
        for(int j = 0; j < k; ++j )  // Delay loop
            {
            cout << "";
            cout << "";
            cout << "";
            }
        }
    cout << "\nThe timing samples are:\n\n";
    while( !TimeLine.IsEmpty() )
        {
        TTime SampleTime = TimeLine.Get();
        cout << SampleTime << "\n";
        }

    return 0;
}
