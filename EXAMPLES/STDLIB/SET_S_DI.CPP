 #include <algorithm>
 #include <set>

 using namespace std;

 int main ()
 {
   //
   // Initialize some sets.
   //
   int a1[] = {1,3,5,7,9,11};
   int a3[] = {3,5,7,8};
   set<int, less<int> > odd(a1+0, a1+6), result, smalll(a3+0, a3+4);
   //
   // Create an insert_iterator for result.
   //
   insert_iterator<set<int, less<int> > > res_ins(result, result.begin());
   //
   // Demonstrate set_symmetric_difference.
   //
   cout << "The symmetric difference of:" << endl << "{";
   copy(smalll.begin(),smalll.end(), ostream_iterator<int>(cout," "));
   cout << "} with {";
   copy(odd.begin(),odd.end(), ostream_iterator<int>(cout," "));
   cout << "} =" << endl << "{";
   set_symmetric_difference(smalll.begin(), smalll.end(),
                            odd.begin(), odd.end(), res_ins);
   copy(result.begin(),result.end(), ostream_iterator<int>(cout," "));
   cout << "}" << endl << endl;

   return 0;
 }

