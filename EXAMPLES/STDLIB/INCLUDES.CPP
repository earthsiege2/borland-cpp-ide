 #include <algorithm>
 #include <set>

 using namespace std;

 int main ()
 {
  //
  // Initialize some sets.
  //
  int a1[10] = {1,2,3,4,5,6,7,8,9,10};
  int a2[6]  = {2,4,6,8,10,12};
  int a3[4]  = {3,5,7,8};
  set<int, less<int> > all(a1+0, a1+10), even(a2+0, a2+6), smalll(a3+0, a3+4);
  //
  // Demonstrate includes.
  //
  cout << "The set: ";
  copy(all.begin(),all.end(), ostream_iterator<int>(cout," "));
  bool answer = includes(all.begin(), all.end(), smalll.begin(), smalll.end());
  cout << endl << (answer ? "INCLUDES " : "DOES NOT INCLUDE ");
  copy(smalll.begin(),smalll.end(), ostream_iterator<int>(cout," "));
  answer = includes(all.begin(), all.end(), even.begin(), even.end());
  cout << ", and" << endl << (answer ? "INCLUDES" : "DOES NOT INCLUDE ");
  copy(even.begin(),even.end(), ostream_iterator<int>(cout," "));
  cout << endl << endl;

  return 0;
 }

