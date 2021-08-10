 #include <algorithm>
 #include <vector>
 #include <iterator>

 using namespace std;

 bool isOdd(int i)
 {
     return (i%2);
 }

 int main ()
 {
   //
   // Initialize a vector with an array of integers.
   //
   int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
   vector<int> v(arr+0, arr+10);
   //
   // Print out original vector.
   //
   cout << "The original list: " << endl << "     ";
   copy(v.begin(), v.end(), ostream_iterator<int>(cout," "));
   cout << endl << endl;
   //
   // Replace the number 7 with 11.
   //
   replace(v.begin(), v.end(), 7, 11);
   //
   // Print out vector with 7 replaced.
   //
   cout << "List after replace:" << endl << "     ";
   copy(v.begin(), v.end(), ostream_iterator<int>(cout," "));
   cout << endl << endl;
   //
   // Replace 1 & 3 with 13 13 13.
   //
   replace_if(v.begin(), v.begin()+3, isOdd, 13);
   //
   // Print out the remaining vector.
   //
   cout << "List after replace_if:" << endl << "     ";
   copy(v.begin(), v.end(), ostream_iterator<int>(cout," "));
   cout << endl << endl;
   //
   // Replace those 13s with 17s on output.
   //
   cout << "List using replace_copy to cout:" << endl << "     ";
   replace_copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "), 13, 17);

   cout << endl << endl;

   return 0;
 }
