/**************************************************************************
 *
 * alg5.cpp - Example programs for STL generic algorithms those producing
 *    scalar values. Section 12.6
 *
 * $Id: alg5.cpp,v 1.3 1995/08/29 18:43:21 oberg Exp $
 *
 * $$RW_INSERT_HEADER "slyrs.cpp"
 *
 **************************************************************************/

# include <iostream.h>

# include <vector>
# include <list>
# include <algorithm>
# include <numeric>

# include <string.h>
# include <string>
using namespace std;

// prototypes used to halt warnings
bool isVowel (char);
void count_example();
void accumulate_example();
template<class T>
list<T> & listadd(list<T> & base, T & newValue);
void inner_product_example();
void equal_example();


bool isVowel (char c)
{
	switch (c) {
		case 'a': case 'A':
		case 'e': case 'E':
		case 'i': case 'I':
		case 'o': case 'O':
		case 'u': case 'U':
			return true;
		}
	return false;
}

void count_example()
	// illustrate the use of the count function
{
	int ecount = 0;
	int vowelCount = 0;
	
	char * text = "Now is the time to begin";
	
	count (text, text + strlen(text), 'e', ecount);
	count_if (text, text + strlen(text), isVowel, vowelCount);
	
	cout << "There are " << ecount << " letter e's " << endl << "and "
		<< vowelCount << " vowels in the text:" << text << endl;
}

list<int>& intReplicate (list<int>& nums, int n)
	// add n to 1 to list
{
	while (n) nums.push_back(n--);
	return nums;
}

void accumulate_example()
	// illustrate the use of the accumulate function
{
	int numbers[] = {1, 2, 3, 4, 5};
	
	int sum = accumulate(numbers, numbers+5, 0);
	int product = accumulate(numbers, numbers+5, 1, times<int>());
	
	cout << "The sum of the first five numbers is " << sum << endl;
	cout << "The product of the first five numbers is " << product << endl;
	
		// example with different types for init
	list<int> nums;
	nums = accumulate(numbers, numbers+5, nums, intReplicate);
	copy (nums.begin(), nums.end(),
		ostream_iterator<int>(cout, " ")), cout << endl;
}

void inner_product_example()
	// illustrate the use of the inner_product function
{
	int a[] = {4, 3, -2};
	int b[] = {7, 3, 2};
	
		// example 1, simple inner product
	int in1 = inner_product(a, a+3, b, 0);
	cout << "Inner product is " << in1 << endl;
	
		// example 2, using different operations
	bool anyequal = inner_product(a, a+3, b, true, logical_or<bool>(), equal_to<int>());
	cout << "any equal? " << anyequal << endl;	
}

void equal_example()
	// illustrate the use of the equal function
{
	int a[] = {4, 5, 3};
	int b[] = {4, 3, 3};
	int c[] = {4, 5, 3};
	
	cout << "a = b is:" << equal(a, a+3, b) << endl;
	cout << "a = c is:" << equal(a, a+3, c) << endl;
	cout << "a pair-wise-greater_equal b is" << equal(a, a+3, b, greater_equal<int>()) << endl;
}

void lexical_comparison_example ()
	// illustrate the use of the lexical_comparison function
{
	char * wordOne = "everything";
	char * wordTwo = "everybody";
	
	cout << "compare everybody to everything " <<
		lexicographical_compare(wordTwo, wordTwo + strlen(wordTwo), wordOne, wordOne + strlen(wordOne))
			<< endl;
			
	int a[] = {3, 4, 5, 2};
	int b[] = {3, 4, 5};
	int c[] = {3, 5};
	
	cout << "compare a to b: " << lexicographical_compare(a, a+4, b, b+3) << endl;
	cout << "compare a to c: " << lexicographical_compare(a, a+4, c, c+2) << endl;
}

int main() {
	cout << "STL generic algorithms -- algorithms that produce scalar results" << endl;
	count_example();
	accumulate_example();
	inner_product_example();
	equal_example();
	lexical_comparison_example();
	
	cout << "End of scalar algorithms test"  << endl;
	return 0;
}
