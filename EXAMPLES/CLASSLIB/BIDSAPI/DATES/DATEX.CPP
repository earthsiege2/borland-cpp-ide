// ---------------------------------------------------------------------------
// Copyright (C) 1994 Borland International
// date.cpp
// ---------------------------------------------------------------------------

#include <classlib/date.h>
#include <iostream.h>

void PrintDate(TDate& date)
{
    cout << date.NameOfDay() << " ";
    cout << date.NameOfMonth() << " ";
    cout << date.DayOfMonth() << ", " << date.Year();
}

int main()
{
    TDate date;
  
    cout << "Welcome to TDate!" << endl << endl;
    cout << "Please enter the date you were born (MM/DD/YY): ";
    cin >> date;
  
    cout << "You were born on "; 
    PrintDate(date);
    cout << "." << endl;
  
    cout << "With 'operator <<', the date is " << date << endl << endl;
  
    cout << "The year " << date.Year() << " was";
    cout << (date.Leap() ? "" : " not") << " a leap year." << endl;
  
    cout << "The week before that date was ";
    PrintDate(date-7);
    cout << "." << endl;
  
    cout << "The week after that date was " << (date+7) << endl;
  
    return 0;
}
