/**************************************************************************
 *
 * alg1.cpp - Example program for STL generic algorithms that initialize
 *    sequences.  Section 12.2
 *
 * $Id: alg1.cpp,v 1.3 1995/08/29 18:37:31 oberg Exp $
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

class iotaGen {
public:
	iotaGen (int iv) : current(iv) { }
	operator () () { return current++; }
private:
	int current;
};

void fill_example ()
	// illustrate the use of the fill and fill_n functions
{
	cout << "Illustrate fill function" << endl;
		// example 1, fill an array with initial values
	char buffer[100], *bufferp = buffer;
	fill(bufferp, bufferp + 100, '\0');
	fill_n(bufferp, 10, 'x');
	cout << buffer << endl;
	
		// example 2, use fill to initialize a list
	list<string> aList;
	fill_n (inserter(aList, aList.begin()), 10, "empty");
	copy(aList.begin(), aList.end(), ostream_iterator<string>(cout, " ")), cout << endl;
	
		// example 3, use fill to overwrite values in a list
	fill (aList.begin(), aList.end(), "full");
	copy(aList.begin(), aList.end(), ostream_iterator<string>(cout, " ")), cout << endl;
	
		// example 4, fill in a portion of a list
	vector<int> iVec(10);
	generate (iVec.begin(), iVec.end(), iotaGen(1));
	vector<int>::iterator seven = find(iVec.begin(), iVec.end(), 7);
	fill(iVec.begin(), seven, 0);
	copy(iVec.begin(), iVec.end(), ostream_iterator<int>(cout)), cout << endl;
}

void copy_example()
	// illustrate the use of the copy function
{
	cout << "Illustrate copy function " << endl;
	char * source = "reprise";
	char * surpass = "surpass";
	char buffer[120], *bufferp = buffer;
	
		// example 1, a simple copy
	copy(source, source + strlen(source) + 1, bufferp);
	
		// example 2, self copies
	* copy(bufferp + 2, bufferp+ strlen(buffer), bufferp) = '\0';	
	int buflen = strlen(buffer) + 1;
	copy_backward(bufferp, bufferp + buflen, bufferp + buflen + 3);
	copy(surpass, surpass + 3, bufferp);
	
		// example 3, copy to output
	copy(bufferp, bufferp + strlen(buffer), ostream_iterator<char>(cout));
	cout << endl;
	
		// example 4, use copy to convert type
	list<char> char_list;
	copy(bufferp, bufferp + strlen(buffer),inserter(char_list,char_list.end()));
	char * big = "big ";
	copy(big, big + 4, inserter(char_list, char_list.begin()));
	
	char buffer2[200], *buffer2p = buffer;
	* copy(char_list.begin(), char_list.end(), buffer2p) = '\0';
	cout << buffer2 << endl;
}

#ifndef RWSTD_NO_LONG_HEADER_NAME
# include <strstream.h>
#else
# include <strstrea.h>
#endif

string generateLabel() {
	// generate a label string of the form L_ddd
	static int lastLabel = 0;
	char labelBuffer[80];
	ostrstream ost(labelBuffer, 80);
	ost << "L_" << lastLabel++ << '\0';
	return string(labelBuffer);
}

void generate_example ()
	// illustrate the use of the generate and genrate_n functions
{
	cout << "Illusustrate generate algorithm" << endl;
	
		// example 1, generate a list of label numbers
	list<string> labelList;
	generate_n (inserter(labelList, labelList.begin()), 4, generateLabel);	
	copy (labelList.begin(), labelList.end(),
			ostream_iterator<string>(cout, " ")), cout << endl;
			
		// example 2, generate an arithmetic progression
	vector<int> iVec(10);
	generate (iVec.begin(), iVec.end(), iotaGen(2));
	generate_n (iVec.begin(), 5, iotaGen(7));
	copy (iVec.begin(), iVec.end(), ostream_iterator<int>(cout, " ")), cout << endl;
}

void swap_example ()
	// illustrate the use of the algorithm swap_ranges
{
	cout << "Illustrate swap_ranges algorithm" << endl;
	
		// first make two parallel sequences
	int data[] = {12, 27, 14, 64}, *datap = data;
	vector<int> aVec(4);
	generate (aVec.begin(), aVec.end(), iotaGen(1));
	
		// illustrate swap and swap_itr
	swap(data[0], data[2]);
	copy (data, data+4, ostream_iterator<int>(cout, " ")), cout << endl;
	vector<int>::iterator last = aVec.end(); last--;
	iter_swap(aVec.begin(), last);
	copy (aVec.begin(), aVec.end(), ostream_iterator<int>(cout, " ")), cout << endl;
	
		// now swap the entire sequence
	swap_ranges (aVec.begin(), aVec.end(), datap);
	copy (data, data+4, ostream_iterator<int>(cout, " ")), cout << endl;
	copy (aVec.begin(), aVec.end(), ostream_iterator<int>(cout, " ")), cout << endl;
}

int main()
{
	cout << "STL generic algorithms -- initialization algorithms"
		<< endl;
	fill_example();
	copy_example();
	generate_example();
	swap_example();
	
	cout << "End of initialization tests" << endl;
	return 0;
}
