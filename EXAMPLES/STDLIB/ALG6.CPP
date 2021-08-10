/**************************************************************************
 *
 * alg6.cpp - STL generic algorithms that produce new sequences
 *    section 12.7
 *
 * $Id: alg6.cpp,v 1.3 1995/08/29 18:43:29 oberg Exp $
 *
 * $$RW_INSERT_HEADER "slyrs.cpp"
 *
 **************************************************************************/

# include <vector>
# include <list>
# include <algorithm>
# include <numeric>

# include <iostream.h>
using namespace std;

int square(int n) { return n * n; }

class iotaGen {
public:
	iotaGen (int iv) : current(iv) { }
	operator () () { return current++; }
private:
	int current;
};


void transform_example ()
	// illustrate the use of the transform algorithm
{
	// generate a list of values from 1 to 6
	list<int> aList;
	generate_n (inserter(aList, aList.begin()), 6, iotaGen(1));
	cout << "Original list: ";
	copy(aList.begin(), aList.end(), ostream_iterator<int>(cout, " ")), cout << endl;
	
		// transform elements by squaring, copy into vector
	vector<int> aVec(6);
	transform (aList.begin(), aList.end(), aVec.begin(), square);
	cout << "After squaring: ";
	copy(aVec.begin(), aVec.end(), ostream_iterator<int>(cout, " ")), cout << endl;
	
		// transform vector again, in place, yielding 4th powers
	transform (aVec.begin(), aVec.end(), aVec.begin(), square);
	cout << "After squaring again: ";
	copy(aVec.begin(), aVec.end(), ostream_iterator<int>(cout, " ")), cout << endl;
	
		// transform in parallel, yielding cubes
	vector<int> cubes(6);
	transform (aVec.begin(), aVec.end(), aList.begin(),
		cubes.begin(), divides<int>());
	cout << "After division: ";
	copy(cubes.begin(), cubes.end(), ostream_iterator<int>(cout, " ")), cout << endl;
	
}

void partial_sum_example ()
	// illustrate the use of the partial sum algorithm
{
		// generate values 1 to 5
	 vector<int> aVec(5);
	 generate (aVec.begin(), aVec.end(), iotaGen(1));
	
	 	// output partial sums
	 cout << "Partial sums examples" << endl;
	 cout << "Partial sums : ";
	 partial_sum (aVec.begin(), aVec.end(),
	 	ostream_iterator<int>(cout, " ")), cout << endl;
	 	
	 	// output partial products
	 cout << "Partial products: ";
	 partial_sum (aVec.begin(), aVec.end(),
	 	ostream_iterator<int>(cout, " "), times<int>() ), cout << endl;
}

void adjacent_difference_example ()
	// illustrate the use of the adjacent difference algorithm
{
		// generate values 1 to 5
	 vector<int> aVec(5);
	 generate (aVec.begin(), aVec.end(), iotaGen(1));
	
	 	// output partial sums
	 cout << "Adjacent Differences examples" << endl;
	 cout << "Adjacent Differences : ";
	adjacent_difference (aVec.begin(), aVec.end(),
	 	ostream_iterator<int>(cout, " ")), cout << endl;
	 	
	 	// output partial products
	 cout << "Adjacent sums: ";
	 adjacent_difference (aVec.begin(), aVec.end(),
	 	ostream_iterator<int>(cout, " "), plus<int>() ), cout << endl;
}


int main() {
	cout << "STL generic algorithms -- that transform sequences"  << endl;
	
	transform_example();
	partial_sum_example();
	adjacent_difference_example ();
	
	cout << "End generic transform algorithms example" << endl;
	return 0;
}
