/**************************************************************************
 *
 * radix.cpp - radix sort program.  Section 7.3
 *
 * $Id: radix.cpp,v 1.3 1995/08/29 19:02:16 oberg Exp $
 *
 * $$RW_INSERT_HEADER "slyrs.cpp"
 *
 **************************************************************************/

# include <deque>
# include <list>
# include <vector>
# include <algorithm>
# include <numeric>

# include <iostream.h>
using namespace std;

class copyIntoBuckets {
public:
	copyIntoBuckets(int d, vector< deque<unsigned int> > & b, bool & f)
		: divisor(d), buckets(b), flag(f) {}
	int divisor;
	vector< deque<unsigned int> > & buckets;
	bool & flag;
	void operator () (unsigned int v)
			{	int index = (v / divisor) % 10;
				// flag is set to true if any bucket
				// other than zeroth is used
				if (index) flag = true;
				buckets[index].push_back(v);
			}
};

list<unsigned int>::iterator listCopy(list<unsigned int>::iterator c, deque<unsigned int> & lst)
{
	return copy(lst.begin(), lst.end(), c);
}

void radixSort(list<unsigned int> & values)
{
	bool flag = true;
	int divisor = 1;
	
	while (flag) {
		vector< deque<unsigned int> > buckets(10);
		flag = false;
		for_each(values.begin(), values.end(),
			copyIntoBuckets(divisor, buckets, flag));
		accumulate(buckets.begin(), buckets.end(), values.begin(), listCopy);
		divisor *= 10;
		copy(values.begin(), values.end(), ostream_iterator<int>(cout, " ")), cout << endl;
		}
}

int main() {
	cout << "Radix sort program"  << endl;
	int data[] = {624, 852, 426, 987, 269, 146, 415, 301, 730, 78, 593};
	list<unsigned int> values(11);
	copy(data, data + 11, values.begin());
	radixSort(values);
	copy(values.begin(), values.end(), ostream_iterator<int>(cout, " ")), cout << endl;

	cout << "End radix sort program" << endl;
	return 0;	
}
