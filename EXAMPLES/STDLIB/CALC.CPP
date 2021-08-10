/**************************************************************************
 *
 * calc.cpp - RPN Calculator -- Illustration of the use of stacks.
 *      Section 10.2.1
 *
 * $Id: calc.cpp,v 1.3 1995/08/29 19:00:41 oberg Exp $
 *
 * $$RW_INSERT_HEADER "slyrs.cpp"
 *
 **************************************************************************/

# include <vector>
# include <stack>
# include <iostream.h>
using namespace std;

//
//	class calculatorEngine
//		simulate the behavior of a simple integer calculator
//

class calculatorEngine {
public:
	enum binaryOperator {plus, minus, times, divide};
	
	int currentMemory ()
		{ return data.top(); }
		
	void pushOperand (int value)
		{ data.push (value); }
		
	void doOperator (binaryOperator);
	
protected:
	stack< int, vector<int> > data;
};

void calculatorEngine::doOperator (binaryOperator theOp)
{
	int right = data.top();
	data.pop();
	int left = data.top();
	data.pop();
	switch (theOp) {
		case plus: data.push(left + right); break;
		case minus: data.push(left - right); break;
		case times: data.push(left * right); break;
		case divide: data.push(left / right); break;
		}
}

int main() {
	cout << "Calculator example program, from Chapter 8" << endl;
	cout << "Enter a legal RPN expression, end with p q (print and quit)" << endl;
	int intval;
	calculatorEngine calc;
	char c;
	
	while (cin >> c)
		switch (c) {
			case '0': case '1': case '2': case '3': case '4':
			case '5': case '6': case '7': case '8': case '9':
				cin.putback(c);
				cin >> intval;
				calc.pushOperand(intval);
				break;
			
			case '+':
				calc.doOperator(calculatorEngine::plus);
				break;
						
			case '-':
				calc.doOperator(calculatorEngine::minus);
				break;
				
			case '*':
				calc.doOperator(calculatorEngine::times);
				break;
				
			case '/':
				calc.doOperator(calculatorEngine::divide);
				break;

			case 'p':
				cout << calc.currentMemory() << endl;
				
			case 'q':
				cout << "End calculator program" << endl;
				return 0; // quit program

		}
	return 0;
}
