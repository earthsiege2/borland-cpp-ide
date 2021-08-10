//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1997 by Borland International, All Rights Reserved
// written by Michael Sawczyn
//----------------------------------------------------------------------------
#ifndef TIsapiStream_H
#define TIsapiStream_H

class TIsapiExtension;

#include <iostream.h>

//
// Proxy for server output. Data can be streamed to this object, and
// will be written to the server.
//

class TIsapiStreambuf : public streambuf
    {
    static uint bufsize;
 public:
    TIsapiStreambuf( TIsapiExtension * aParent )
        {
        Parent = aParent;

        isapibuf = new char[bufsize];
                memset( isapibuf, 0, bufsize );
                setbuf( isapibuf, bufsize-1, 1 );
                setp( isapibuf, isapibuf + (bufsize-1) );
        }

    ~TIsapiStreambuf(  )
        {
        // delete[] isapibuf;
        }

    void    SetParent( TIsapiExtension * aParent )
        {
        Parent = aParent;
        }

    virtual int overflow( int );
    virtual int sync(  );

protected:
private:
    // Informs the stream of the parent TIsapiExtension.
    //
    TIsapiStreambuf( const TIsapiStreambuf & )
        {

        }

    TIsapiStreambuf & operator = ( const TIsapiStreambuf & )
        {
        return *this;
        }

    /**# :[Label = "Parent"] [Cardinalities = "0..1/"] */
    TIsapiExtension *Parent;
    char   *isapibuf;
    };

class TIsapiStream : public ostream
    {
    friend class TIsapiExtension;
 public:
            TIsapiStream( TIsapiExtension * parent )
        {
        bp = new TIsapiStreambuf( parent );
        ios::init( bp );
        }

    virtual ~TIsapiStream(  )
        {
        sync(  );
        delete  bp;
                bp = NULL;
        }

    int     sync(  )
        {
        return bp->sync(  );
        }

 protected:
 private:
    // Informs the stream of the parent TIsapiExtension.
    //
    void    SetParent( TIsapiExtension * parent )
        {
        dynamic_cast < TIsapiStreambuf * >( bp )->SetParent( parent );
        }

    // Private default constructor to prevent accidental creation.
    //
    TIsapiStream(  );

    // Private to prevent accidental copying.
    //
    TIsapiStream( const TIsapiStream & );

    // Private to prevent accidental copying.
    //
    TIsapiStream & operator = ( const TIsapiStream & );
    };

#endif
