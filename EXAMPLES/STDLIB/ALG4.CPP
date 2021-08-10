/**************************************************************************
 *
 * alg4.cpp - Example programs for STL generic algorithms removal
 *    algorithms. Section 12.5
 *
 * $Id: alg4.cpp,v 1.3 1995/08/29 18:43:12 oberg Exp $
 *
 * $$RW_INSERT_HEADER "slyrs.cpp"
 *
 **************************************************************************/

# include <list>
# include <set>
# include <algorithm>

# include <iostream.h>
using namespace std;

bool isEven(int n) { return 0 == (n % 2); }

void remove_example ()
	// illustrate the use of the remove algorithm
{
	cout << "Remove Algorithm examples" << endl;
	
	// create a list of numbers
	int data[] = {1, 2, 4, 3, 1, 4, 2};
	list<int> aList;
	copy (data, data+7, inserter(aList, aList.begin()));
	cout << "Original list: ";
	copy (aList.begin(), aList.end(), ostream_iterator<int>(cout, " ")), cout << endl;
	
		// remove 2's, copy into a new list
	list<int> newList;
	remove_copy (aList.begin(), aList.end(), back_inserter(newList), 2);
	cout << "After removing 2's: ";
	copy (newList.begin(), newList.end(), ostream_iterator<int>(cout, " ")), cout << endl;
	
		// remove 2's in place
	list<int>::iterator where;
	where = remove(aList.begin(), aList.end(), 2);
	cout << "List after removal, before erase: ";
	copy (aList.begin(), aList.end(), ostream_iterator<int>(cout, " ")), cout << endl;
	aList.erase(where, aList.end());
	cout << "List after erase: ";
	copy (aList.begin(), aList.end(), ostream_iterator<int>(cout, " ")), cout << endl;
	
		// remove all even values
	where = remove_if (aList.begin(), aList.end(), isEven);
	aList.erase(where, aList.end());
	cout << "List after removing even values: ";
	copy (aList.begin(), aList.end(), ostream_iterator<int>(cout, " ")), cout << endl;
	
}

void unique_example ()
	// illustrate use of the unqiue algorithm
{
		// first make a list of values
	int data[] = {1, 3, 3, 2, 2, 4};
	list<int> aList;
	copy(data, data+6, inserter(aList, aList.begin()));
	cout << "Origianal List: ";
	copy(aList.begin(), aList.end(), ostream_iterator<int>(cout, " ")), cout << endl;
	
		// copy unique elements into a set
	set<int, less<int> > aSet;
	unique_copy(aList.begin(), aList.end(), inserter(aSet, aSet.begin()));
	cout << "Set after unique_copy: ";
	copy(aSet.begin(), aSet.end(), ostream_iterator<int>(cout, " ")), cout << endl;
	
		// copy unique elements in place
	list<int>::iterator where;
	where = unique(aList.begin(), aList.end());
	cout << "List after calling unique: ";
	copy(aList.begin(), aList.end(), ostream_iterator<int>(cout, " ")), cout << endl;
	
		// remove trailing values
	aList.erase(where, aList.end());
	cout << "List after erase: ";
	copy(aList.begin(), aList.end(), ostream_iterator<int>(cout, " ")), cout << endl;
}

int main() {
	cout << "STL generic algorithms -- Removal Algorithms" << endl;
	remove_example();
	unique_example();
	
	cout << "End of removal algorithms sample program" << endl;
	return 0;
}
