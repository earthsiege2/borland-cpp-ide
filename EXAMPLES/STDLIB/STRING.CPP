 #include <string>

 using namespace std;

 int main ()
 {
   string test, result;
   //
   // Type in a string over five characters long.
   //
   while (test.empty() ||  test.size() <= 5)
   {
     cout << "Type a string between 5 and 100 characters long. " << endl;
     cin >> test;
   }
   //
   // Test operator[] access.
   //
   cout << endl << "You typed in: " << test << endl << endl;
   cout << "Changing the third character from " << test[2] << " to * " << endl;
   test[2] = '*';
   cout << "now its: " << test << endl << endl;
   //
   // Try the insertion member function.
   //
   test.insert(test.size() / 2, "(the middle is here!)");
   cout << "Identifying the middle: " << test << endl << endl;
   //
   // Try replacement.
   //
   test.replace(test.find("middle",0), 6, "center");
   cout << "I didn't like the word 'middle', so instead, I'll say: "
        << endl << test << endl;

   return 0;
 }
