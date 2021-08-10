 #include <vector>

 using namespace std;

 ostream& operator<< (ostream& out, const vector<int>& v)
 {
   copy(v.begin(), v.end(), ostream_iterator<int>(out," "));
   return out;
 }

 int main ()
 {
   //
   // Create a vector of doubles, and one of integers.
   //
   vector<int>         vi;
   int                 i;

   for (i = 0; i < 10; ++i)
     //
     // Insert values before the beginning.
     //
     vi.insert(vi.begin(), i);
   //
   // Print out the vector.
   //
   cout << vi << endl;
   //
   // Now let's erase half of the elements.
   //
   int half = vi.size() / 2;

   for (i = 0; i < half; ++i)
     vi.erase(vi.begin());
   //
   // Print it out again.
   //
   cout << vi << endl;

   return 0;
 }
