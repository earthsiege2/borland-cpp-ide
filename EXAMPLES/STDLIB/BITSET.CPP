#include <bitset>
#include <iostream.h>

using namespace std;

int main ()
{
    bitset<8> b;
    b |= 5;
#ifndef RWSTD_NO_NONTYPE_ARGS
    cout << b << endl; // results in 00000101
#endif
    return 0;
}
