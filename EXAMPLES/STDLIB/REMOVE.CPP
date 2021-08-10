 #include <algorithm>
 #include <vector>
 #include <iterator>

 using namespace std;

 bool isEven(int i)
 {
     return !(i%2);
 }

 int main ()
 {
   int arr[10] = {1,2,3,4,5,6,7,8,9,10};
   vector<int> v(arr+0, arr+10);

   copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
   cout << endl << endl;
   //
   // Remove the 7.
   //
   vector<int>::iterator result = remove(v.begin(), v.end(), 7);
   //
   // Delete dangling elements from the vector.
   //
   v.erase(result, v.end());

   copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
   cout << endl << endl;
   //
   // Remove all even elements.
   //
   result = remove_if(v.begin(), v.end(), ptr_fun(isEven));
   //
   // Delete dangling elements.
   //
   v.erase(result, v.end());

   copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
   cout << endl << endl;
   //
   // Now remove all 3s on output.
   //
   remove_copy(v.begin(), v.end(), ostream_iterator<int>(cout," "), 3);
   cout << endl << endl;

   return 0;
 }
