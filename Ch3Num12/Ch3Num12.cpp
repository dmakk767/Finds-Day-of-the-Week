// Ch3Num12.cpp : Defines the entry point for the console application.
//used this link to check http://www.searchforancestors.com/utility/dayofweek.html


//Finds the day of the week given a year 1-9999, a month, and a date

#include "stdafx.h"
#include <iostream>

using namespace std;

//predefine
bool isLeapYear(int year);
int getCenturyValue(int year);
int getYearValue(int year);
int getMonthValue(int year, int month);
int year, month, date, day;



int main()
{
	cout << "Please enter a year 1-9999." << endl;
	cin >> year;
	cout << "Please enter a month 1-12." << endl;
	cin >> month;
	cout << "Please enter the date." << endl;
	cin >> date;
	 
	//calc
	day = (date + getMonthValue(year, month) + getYearValue(year) + getCenturyValue(year)) % 7;
		switch (day)
		{
		case 0:
			cout << "The day of the week was Sunday" << endl;
			break;
		case 1:
			cout << "The day of the week was Monday" << endl;
			break;
		case 2:
			cout << "The day of the week was Tuesday" << endl;
			break;
		case 3:
			cout << "The day of the week was Wed" << endl;
			break;
		case 4:
			cout << "The day of the week was Thur" << endl;
			break;
		case 5:
			cout << "The day of the week was Fri" << endl;
			break;
		case 6:
			cout << "The day of the week was Sat" << endl;
			break;
		default:
			cout << "I broke" << endl;
			break;
		}
    return 0;
}

//declare functions
bool isLeapYear(int year)
{

	if ((year % 400) == 0)
	{
		return true;
	}

	if (((year % 4) == 0) && ((year % 100) != 0))
	{
		return true;
	}
	else
	{
		return false;
	}
}

int getCenturyValue(int year)
{
	int centuryVal = (year / 100) % 4;
	centuryVal = (3 - centuryVal) * 2;
	return centuryVal;
}

int getYearValue(int year)
{
	int yearVal = (((year % 100) / 4) + (year % 100)); 
	return yearVal;
}

int getMonthValue(int year, int month)
{
	int monthVal;
	if (month == 1) 
	{
		if (isLeapYear(year) == true) {
			monthVal = 6;
			return monthVal;
		}
		else {
			monthVal = 0;
			return monthVal;
		}
	}

	else if (month == 2)
	{
		if (isLeapYear(year) == true) {
			monthVal = 2;
			return monthVal;
		}
		else {
			monthVal = 3;
			return monthVal;
		}
	}

	switch (month)
	{
	case 3 :
		monthVal = 3; 
		return monthVal;
	case 4:
		monthVal = 6;
		return monthVal;
	case 5:
		monthVal = 1;
		return monthVal;
	case 6:
		monthVal = 4;
		return monthVal;
	case 7:
		monthVal = 6;
		return monthVal;
	case 8:
		monthVal = 2;
		return monthVal;
	case 9:
		monthVal = 5;
		return monthVal;
	case 10:
		monthVal = 0;
		return monthVal;
	case 11:
		monthVal = 3;
		return monthVal;
	case 12:
		monthVal = 5;
		return monthVal;
	default:
		cout << "im broke" << endl;
		break;
	}

}