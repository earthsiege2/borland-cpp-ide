/**************************************************************************
 *
 * alg2.cpp - test program for STL generic algorithm that search for
 *    elements that satisfy a condition.  Section 12.3
 *
 * $Id: alg2.cpp,v 1.2 1995/08/29 18:42:51 oberg Exp $
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

int randomInteger(int m)
{	return rand() % m; }

bool isLeapYear (unsigned int year)
{
	if (year % 1000 == 0)
		return true;
	if (year % 100 == 0)
		return false;
	if (year % 4 == 0)
		return true;
	return false;
}

bool operator < (const string & left, const string & right)
{	return left.compare(right) < 0; }

void split
	(const string & text, const string & separators, list<string> & words)
{
	int n = text.length();
	int start, stop;
	
	start = text.find_first_not_of(separators);
	while ((start >= 0) && (start < n)) {
		stop = text.find_first_of(separators, start);
		if ((stop < 0) || (stop > n)) stop = n;
		words.push_back (text.substr(start, stop-start));
		start = text.find_first_not_of(separators, stop+1);
		}
		
}


void find_test()
	// illustrate use of the find function
{
	cout << "Test of algorithm find" << endl;
	int vintageYears[] = {1967, 1972, 1974, 1980, 1995};

	vector<int>::iterator start = vintageYears;
	vector<int>::iterator stop = vintageYears + 5;
	
	vector<int>::iterator where = find_if(start, stop, isLeapYear);
	
	if (where != stop)
		cout << "first vintage leap year is " << *where << endl;
	else
		cout << "no vintage leap years" << endl;
		
	where = find(start, stop, 1995);
	
	if (where != stop)
		cout << "1995 is position " << where - start << " in sequence" << endl;
	else
		cout << "1995 does not occur in sequence" << endl;
	
}

void find_adjacent_test()
{
	cout << "Test of algorithm find adjacent" << endl;
	char * text = "The bookkeeper carefully opened the door";
	
	vector<char>::iterator start = text;
	vector<char>::iterator stop = text + strlen(text);
	
	vector<char>::iterator where = start;
	
	cout << "In the text " << text << endl;
	while ((where = adjacent_find(where, stop)) != stop) {
		cout << "double " << *where << " in position " << where - start << endl;
		++where;
		}
}

void search_test()
	// illustrate the use of the search function
{
	cout << "Test of algorithm search" << endl;
	char * base = "aspirations";
	char * text = "ration";
	
	char * where = search(base, base + strlen(base), text, text + strlen(text));
	
	if (*where != '\0')
		cout << "substring begins in position " << where - base << endl;
	else
		cout << "substring does not occur in text" << endl;
}

void max_min_example ()
	// illustrate use of max_element and min_element algorithms
{
	cout << "Test of max and min algorithms " << endl;
	// make a vector of random numbers between 0 and 99
	vector<int> numbers(25);
	for (int i = 0; i < 25; i++)
		numbers[i] = randomInteger(100);
		
	// print the maximum
	vector<int>::iterator max =
		max_element(numbers.begin(), numbers.end());
	cout << "largest value was " << *max << endl;
	
		// example using strings
	string text =
		"it was the best of times, it was the worst of times.";
	list<string>words;
	split(text, " .,!:;", words);
	cout << "The smallest word is "
		<< * min_element(words.begin(), words.end())
		<< " and the largest word is "
		<< * max_element(words.begin(), words.end())
		<< endl;
}

void mismatch_test(char * a, char * b)
	// illustrate the use of the mismatch function
{
	pair<char *, char *> differPositions(0, 0);
	char * aDiffPos;
	char * bDiffPos;

	if (strlen(a) < strlen(b)) {
		differPositions = mismatch(a, a + strlen(a), b);
		aDiffPos = differPositions.first;
		bDiffPos = differPositions.second;
		}
	else {
		differPositions = mismatch(b, b + strlen(b), a);
		aDiffPos = differPositions.second;
		bDiffPos = differPositions.first;
		}
		
	cout << "string " << a;
	if (*aDiffPos == *bDiffPos)
		cout << " is equal to ";
	else if (*aDiffPos < *bDiffPos)
		cout << " is less than ";
	else
		cout << " is greater than ";
	cout << b << endl;
}

int main()
{
	cout << "STL generic algorithms -- Searching Algorithms" << endl;
	find_test();
	find_adjacent_test();
	search_test;
	max_min_example();
	mismatch_test("goody", "goody");
	mismatch_test("good", "goody");
	mismatch_test("goody", "good");
	mismatch_test("good", "fred");
	mismatch_test("fred", "good");
	
	cout << "End of search algorithms test program" << endl;
	return 0;
}
