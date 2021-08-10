/**************************************************************************
 *
 * alg3.cpp - Sample programs for STL generic algorihtms that modify
 *   their arguments in place.  Section 12.4
 *
 * $Id: alg3.cpp,v 1.4 1995/08/29 18:43:04 oberg Exp $
 *
 * $$RW_INSERT_HEADER "slyrs.cpp"
 *
 **************************************************************************/

# include <iostream.h>
# include <vector>
# include <list>
# include <algorithm>

# include <ctype.h>
# include <string>
# include <string.h>
using namespace std;

class iotaGenerator {
public:
	iotaGenerator (int iv) : current(iv) { }
	operator () () { return current++; }
private:
	int current;
};

bool isEven(int n) { return 0 == (n % 2); }

void reverse_example ()
	// illustrate the use of the reverse function
{
	cout << "Illustrate reverse algorithm" << endl;
	
		// example 1, reversing a string
	char * text = "Rats live on no evil star";
	reverse (text, text + strlen(text));
	cout << text << endl;
	
		// example 2, reversing a list
	list<int> iList;
	generate_n(inserter(iList, iList.begin()), 10, iotaGenerator(2));
	reverse (iList.begin(), iList.end());
	copy (iList.begin(), iList.end(),
			ostream_iterator<int>(cout, " ")), cout << endl;	
}

void replace_example ()
	// illustrate the use of the replace function
{
	cout << "Illustrate replace algorithm" << endl;
	
		// make vector 0 1 2 3 4
	vector<int> numbers(11);	
	for (int i = 0; i < 11; i++)
		numbers[i] = i < 5 ? i : 10 - i;
	copy (numbers.begin(), numbers.end(),
		ostream_iterator<int> (cout, " ")), cout << endl;

		
		// replace 0 by 2
	replace (numbers.begin(), numbers.end(), 3, 7);
	copy (numbers.begin(), numbers.end(),
		ostream_iterator<int> (cout, " ")), cout << endl;
		
		// replace even numbers by 9
	replace_if (numbers.begin(), numbers.end(), isEven, 9);
	copy (numbers.begin(), numbers.end(),
		ostream_iterator<int> (cout, " ")), cout << endl;
		
		// copy into a list, replacing 9 by 3
	int aList[] = {2, 1, 4, 3, 2, 5};
	int bList[6];
	int cList[6];
	replace_copy (aList, aList+6, &bList[0], 2, 7);
	replace_copy_if (bList, bList+6, &cList[0], bind2nd(greater<int>(), 3), 8);
	copy (bList, bList + 6, ostream_iterator<int> (cout, " ")), cout << endl;
	copy (cList, cList + 6, ostream_iterator<int> (cout, " ")), cout << endl;
}

void rotate_example ()
	// illustrate the use of the rotate function
{
	cout << "Illustrate rotate algorithm" << endl;
	
		// create the list 1 2 3 ... 10
	list<int> iList;
	generate_n(inserter(iList, iList.begin()), 10, iotaGenerator(1));
		
		// find the location of the seven
	list<int>::iterator  middle = find(iList.begin(), iList.end(), 7);
	
		// now rotate around that location
	rotate(iList.begin(), middle, iList.end());
	copy (iList.begin(), iList.end(),
		ostream_iterator<int>(cout, " ")), cout << endl;
		
		// rotate again around the same location
	list<int> cList;
	rotate_copy(iList.begin(), middle, iList.end(),
		inserter(cList, cList.begin()));
	copy (cList.begin(), cList.end(),
		ostream_iterator<int>(cout, " ")), cout << endl;
}


void partition_example ()
	// illustrate the use of the paration function
{
	cout << "Illustrate partition algorithm" << endl;
	
		// first make the vector 1 2 3 ... 10
	vector<int> numbers(10);
	generate(numbers.begin(), numbers.end(), iotaGenerator(1));
	
		// now put the odd values low, even values high
	vector<int>::iterator result = partition (numbers.begin(), numbers.end(), isEven);
	copy (numbers.begin(), numbers.end(),
		ostream_iterator<int>(cout, " ")), cout << endl;
	cout << "middle location " << result - numbers.begin() << endl;	
	
		// now do a stable partition
	generate(numbers.begin(), numbers.end(), iotaGenerator(1));
	//stable_partition(numbers.begin(), numbers.end(), isEven);
	copy (numbers.begin(), numbers.end(),
		ostream_iterator<int>(cout, " ")), cout << endl;
}


bool nameCompare(char * a, char * b) { return strcmp(a, b) <= 0; }

void permutation_example ()
	// illustrate the use of the next_permutation function
{
		// start with the values 1 2 3 in sequence
	int start [] = {1, 2, 3 };
	
	do
		copy (start, start + 3, ostream_iterator<int> (cout, " ")), cout << endl;
	while (next_permutation(start, start + 3));
		
	char * names[] = {"Alpha", "Beta", "Gamma"};
	do
		copy (names, names + 3, ostream_iterator<char *> (cout, " ")), cout << endl;
	while (next_permutation(names, names + 3, nameCompare));
	
	char * word = "bela";
	do
		cout << word << ' ';
	while (prev_permutation(word, &word[4]));
	cout << endl;	
}

void inplace_merge_example ()
	// illustrate the use of the inplace_merge function
{
	cout << "Illustrate inplace merge algorithm" << endl;
	
		// first generate the numbers 0 2 4 6 8 1 3 5 7 9
	vector<int> numbers(10);
	for (int i = 0; i < 10; i++)
		numbers[i] = i < 5 ? 2 * i : 2 * (i - 5) + 1;
	copy (numbers.begin(), numbers.end(),
		ostream_iterator<int> (cout, " ")), cout << endl;
	vector<int>::iterator midvec = find(numbers.begin(), numbers.end(), 1);
	
		// copy them into a list
	list<int> numList;
	copy(numbers.begin(), numbers.end(),
			inserter(numList, numList.begin()));
	list<int>::iterator midList = find(numList.begin(), numList.end(), 1);
	copy (numList.begin(), numList.end(),
		ostream_iterator<int> (cout, " ")), cout << endl;

		// now put them back together
	inplace_merge(numbers.begin(), midvec, numbers.end());
	inplace_merge(numList.begin(), midList, numList.end());
	copy (numList.begin(), numList.end(),
		ostream_iterator<int> (cout, " ")), cout << endl;
}

struct RandomInteger
{
	operator() (int m) { return rand() % m; }
};

void random_shuffle_example()
	// illustrate the use of the random_shuffle function
{
		// first make the vector 1 2 3 ... 10
	vector<int> numbers(10);
	generate(numbers.begin(), numbers.end(), iotaGenerator(1));

	RandomInteger random;
	
		// randomly shuffle the elements
	random_shuffle(numbers.begin(), numbers.end(), random);
	copy (numbers.begin(), numbers.end(),
		ostream_iterator<int>(cout, " ")), cout << endl;
			
		// do it again
	random_shuffle(numbers.begin(), numbers.end(), random);
	copy (numbers.begin(), numbers.end(),
		ostream_iterator<int>(cout, " ")), cout << endl;
}

int main()
{
	cout << "STL generic algorithms -- in-place algorithms" << endl;

	reverse_example();
	replace_example();
	rotate_example();
	partition_example();
	permutation_example();
	inplace_merge_example();
	random_shuffle_example();
	
	cout << "End of in-place algorithm sample program"  << endl;

	return 0;
}
