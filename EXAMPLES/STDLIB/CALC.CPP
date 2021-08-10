#include "stlexam.h"
#pragma hdrstop
/**************************************************************************
 *
 * calc.cpp - RPN Calculator -- Illustration of the use of stacks.
 *      Section 10.2.1
 *
 ***************************************************************************
 *
 * (c) Copyright 1994, 1998 Rogue Wave Software, Inc.
 * ALL RIGHTS RESERVED
 *
 * The software and information contained herein are proprietary to, and
 * comprise valuable trade secrets of, Rogue Wave Software, Inc., which
 * intends to preserve as trade secrets such software and information.
 * This software is furnished pursuant to a written license agreement and
 * may be used, copied, transmitted, and stored only in accordance with
 * the terms of such license and with the inclusion of the above copyright
 * notice.  This software and information or any other copies thereof may
 * not be provided or otherwise made available to any other person.
 *
 * Notwithstanding any other lease or license that may pertain to, or
 * accompany the delivery of, this computer software and information, the
 * rights of the Government regarding its use, reproduction and disclosure
 * are as set forth in Section 52.227-19 of the FARS Computer
 * Software-Restricted Rights clause.
 * 
 * Use, duplication, or disclosure by the Government is subject to
 * restrictions as set forth in subparagraph (c)(1)(ii) of the Rights in
 * Technical Data and Computer Software clause at DFARS 252.227-7013.
 * Contractor/Manufacturer is Rogue Wave Software, Inc.,
 * P.O. Box 2328, Corvallis, Oregon 97339.
 *
 * This computer software and information is distributed with "restricted
 * rights."  Use, duplication or disclosure is subject to restrictions as
 * set forth in NASA FAR SUP 18-52.227-79 (April 1985) "Commercial
 * Computer Software-Restricted Rights (April 1985)."  If the Clause at
 * 18-52.227-74 "Rights in Data General" is specified in the contract,
 * then the "Alternate III" clause applies.
 *
 **************************************************************************/


#include <vector>
#include <stack>

#ifdef _RW_STD_IOSTREAM
#include <iostream>
#else
#include <iostream.h>
#endif
    
#ifndef _RWSTD_NO_NAMESPACE
using namespace std;
#endif

//
// Simulate the behavior of a simple integer calculator.
//

class CalculatorEngine
{
  public:
    enum binaryOperator { PLUS, MINUS, TIMES, DIVIDE };
    int  currentMemory ()                { return data.top(); }
    void pushOperand   (int value)       { data.push (value); }
    void doOperator    (binaryOperator);
  protected:
    stack< int, vector<int,allocator<int> > > data;
};

void CalculatorEngine::doOperator (binaryOperator theOp)
{
    int right = data.top();
    data.pop();
    int left = data.top();
    data.pop();
    switch (theOp)
    {
        case PLUS:   data.push(left + right); break;
        case MINUS:  data.push(left - right); break;
        case TIMES:  data.push(left * right); break;
        case DIVIDE: data.push(left / right); break;
    }
}

int main()
{
    cout << "Calculator example program, from Chapter 8" << endl;

    cout << "Enter a legal RPN expression, end with p q (print and quit)" << endl;
    int intval;
    CalculatorEngine calc;
    char c;
    
    while (cin >> c)
        switch (c)
        {
            case '0': case '1': case '2': case '3': case '4':
            case '5': case '6': case '7': case '8': case '9':
                cin.putback(c);
                cin >> intval;
                calc.pushOperand(intval);
                break;
            case '+': 
                calc.doOperator(CalculatorEngine::PLUS); break;
            case '-': calc.doOperator(CalculatorEngine::MINUS); break;
            case '*': calc.doOperator(CalculatorEngine::TIMES); break;
            case '/': calc.doOperator(CalculatorEngine::DIVIDE); break;
            case 'p': cout << calc.currentMemory() << endl;
            case 'q': cout << "End calculator program" << endl;
                return 0; // quit program
        }
    return 0;
}
