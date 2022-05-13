#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Date
{
private:
	int year;
	int month;
	int day;

	const int daysInMonthsNonLeap[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	const int daysInMonthsLeap[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };


	friend ostream& operator<<(ostream& os, const Date& date);
	friend istream& operator>>(istream& is, Date& date);

public:
	Date();

	Date(int day, int month, int year);

	Date(string str);

	Date& operator=(const Date& other);

	int getYear();
	int getMonth();
	int getDay();

	int convertToDays();

	static bool isLeapYear(int year);
};
