#include <except.h>
#include <cstring.h>

xmsg::xmsg(const string& msg)
{
    str = new string(msg);
};

xmsg::xmsg(const xmsg& msg)
{
    str = new string(msg.why());
}

xmsg::~xmsg()
{
    delete str;
}

void xmsg::raise() throw( xmsg )
{
    throw *this;
}

xmsg& xmsg::operator=(const xmsg _FAR & src)
{
   if(this!=&src)
   {
      delete str;
      str = new string(src.why());
   }
   return(*this);
}

