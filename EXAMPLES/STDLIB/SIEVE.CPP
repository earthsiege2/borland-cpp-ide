/**************************************************************************
 *
 * sieve.cpp - 	sieve program.  Section 5.3
 *
 * $Id: sieve.cpp,v 1.3 1995/08/29 19:03:22 oberg Exp $
 *
 * $$RW_INSERT_HEADER "slyrs.cpp"
 *
 **************************************************************************/

# include <vector>
# include <iostream.h>
using namespace std;

int main() {
	cout << "Prime Sieve program, a test of vectors" << endl;
	
	// create a sieve of bits, initially on
	const int sievesize = 100;
	vector<int> sieve(sievesize, 1);
		
		// now search for 1 bt positions
	for (int i = 2; i * i < sievesize; i++)
		if (sieve[i])
			for (int j = i + i; j < sievesize; j += i)
				sieve[j] = 0;
					
		// now output all the values that are set
	for (int j = 2; j < sievesize; j++)
		if (sieve[j])
			cout << j << " ";
	cout << endl;
	
	cout << "End of Prime Sieve program" << endl;
	return 0;
}
