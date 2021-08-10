/**************************************************************************
 *
 * complx.cpp - Complex Number example program.	Section 14.3
 *
 * $Id: complx.cpp,v 1.3 1995/08/29 19:00:58 oberg Exp $
 *
 * $$RW_INSERT_HEADER "slyrs.cpp"
 *
 **************************************************************************/

# include <complex>
# include <utility>

# include <iostream.h>
using namespace std;

typedef complex<double> dcomplex;

pair<dcomplex, dcomplex> quadratic
	(dcomplex a, dcomplex b, dcomplex c)
		// return roots of a quadratic equation
{
	dcomplex root = sqrt(b * b - 4.0 * a * c);
	a = a * 2.0;
	
	return make_pair (
		(-b + root) / a,
		(-b - root) / a);
}

int main() {
	dcomplex a(2, 3);
	dcomplex b(4, 5);
	dcomplex c(6, 7);
	
	pair<dcomplex, dcomplex> ans = quadratic(a, b, c);
	cout << "Roots are " << ans.first << " and " << ans.second  << endl;
	return 0;
}
