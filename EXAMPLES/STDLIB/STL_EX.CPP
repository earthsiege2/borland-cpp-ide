//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 2000 Borland International Inc.  All Rights Reserved.
//---------------------------------------------------------------------------
/* Standard C++ library examples */

#include "std1.h"
#include <algorithm>
#include <bitset>
#include <complex>
#include <ctype.h>
#include <deque>
#include <fstream.h>
#include <functional>
#include <iomanip.h>
#include <iostream.h>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <stdexcept>
#include <string.h>
#include <string>
#include <strstrea.h>
#include <utility>
#include <vector>

using namespace std;

extern int ct;  // counter for current memo line

 int accum_ex () /* accum */
 {
   //
   // Typedef for vector iterators.
   //
   Form1->Memo1->Lines->Strings[ct++] = " ========== Accumulator Example =========";
   typedef vector<int>::iterator iterator;
   //
   // Initialize a vector using an array of integers.
   //
   int d1[10] = {1,2,3,4,5,6,7,8,9,10};
   vector<int> v1(d1+0, d1+10);
   //
   // Accumulate sums and products.
   //
   int sum  = accumulate(v1.begin(), v1.end(), 0);
   //
   // Output the results.
   //
   Form1->Memo1->Lines->Strings[ct++] = "For the series: ";
   for(iterator i = v1.begin(); i != v1.end(); i++)
	  Form1->Memo1->Lines->Strings[ct] =
      	Form1->Memo1->Lines->Strings[ct] + IntToStr(*i) + " ";
   ct++;
   Form1->Memo1->Lines->Strings[ct++] = " where N = 10.";
   Form1->Memo1->Lines->Strings[ct++] = "The sum = (N*N + N)/2 = " +IntToStr(sum);

   return 0;
 }
