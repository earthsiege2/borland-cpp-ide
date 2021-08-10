 #include <iterator>
 #include <deque>

 using namespace std;

 int main ()
 {
   //
   // Initialize a deque using an array.
   //
   int arr[4] = { 3,4,7,8 };
   deque<int> d(arr+0, arr+4);
   //
   // Output the original deque.
   //
   cout << "Start with a deque: " << endl << "     ";
   copy(d.begin(), d.end(), ostream_iterator<int>(cout," "));
   //
   // Insert into the middle.
   //
   insert_iterator<deque<int> > ins(d, d.begin()+2);
   *ins = 5; *ins = 6;
   //
   // Output the new deque.
   //
   cout << endl << endl;
   cout << "Use an insert_iterator: " << endl << "     ";
   copy(d.begin(), d.end(), ostream_iterator<int>(cout," "));
   //
   // A deque of four 1s.
   //
   deque<int> d2(4, 1);
   //
   // Insert d2 at front of d.
   //
   copy(d2.begin(), d2.end(), front_inserter(d));
   //
   // Output the new deque.
   //
   cout << endl << endl;
   cout << "Use a front_inserter: " << endl << "     ";
   copy(d.begin(), d.end(), ostream_iterator<int>(cout," "));
   //
   // Insert d2 at back of d.
   //
   copy(d2.begin(), d2.end(), back_inserter(d));
   //
   // Output the new deque.
   //
   cout << endl << endl;
   cout << "Use a back_inserter: " << endl << "     ";
   copy(d.begin(), d.end(), ostream_iterator<int>(cout," "));
   cout << endl;

   return 0;
 }
