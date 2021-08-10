/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     fsbskoff.cpp                                             |*/
/*|                                                              |*/
/*|     Class filebuf                                            |*/
/*|        streampos filebuf::seekoff( streamoff, ios::seek_dir, |*/
/*|                                    int)                      |*/
/*[]------------------------------------------------------------[]*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1990, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */

#include <ioconfig.h>
#include "filesys.h"
#include <fstream.h>

// Seek file to position.
// We take a simple approach, and don't check for small position changes
// within the current buffer.

streampos filebuf::seekoff(streamoff off, ios::seek_dir dir, int /* mode ignored */)
{
#if 1
/*
	Note: sync() doesn't handle text mode so we have to do it here currently
	Removed because filebuf doesn't know how to talk to CRTL.  The mode
	flag serves double duty in that it also specifies whether filebuf
	opened the handle.  Possibly revert if filebuf gains CRTL knowledge.
*/      
    long loff = off;
    int count = out_waiting();
    if( count )
        {       // flush the output
        if( ::write(xfd, pbase(), count) != count )
            return EOF;
        }
    else if( dir == ios::cur )
        if( (count = in_avail()) != 0)
            {
            loff -= count;

            //  if we're in text mode, need to allow for newlines
            //  in the buffer
            if( (mode & ios::binary) == 0 )
                {
                char *tptr = gptr();
                while( tptr != egptr() )
                    if( *tptr++ == '\n' )
                        loff--;
                }
            }
    int w = (dir == ios::beg) ? L_set : ((dir == ios::cur) ? L_cur : L_end);
    last_seek = ::lseek(xfd, loff, w);
    if( ! unbuffered()  &&  base() )
        {      // set up get and put areas
        int pb = (blen() > 8) ? 4 : 1;  // putback area size
        char *b = base();
        setp(b+pb, b+pb);
        setg(b, b+pb, b+pb);
        }
    return (last_seek == long(OS_err)) ? EOF : last_seek;
#else
    if (sync() == EOF)
        return EOF;
    int w = (dir == ios::beg) ? L_set : ((dir == ios::cur) ? L_cur : L_end);
    last_seek = ::lseek(xfd, off, w);
    return (last_seek == long(OS_err)) ? EOF : last_seek;
#endif    
}
