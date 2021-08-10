#include <except.h>
#include <cstring.h>

xalloc::xalloc( const string& msg, size_t size ) : xmsg(msg), siz(size)
{
}

void xalloc::raise() throw( xalloc )
{
    throw *this;
}


