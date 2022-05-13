#include "Date.h"


Date::Date() {
    day = month = year = 0;
}

Date::Date(int day, int month, int year)
{
    this->day = day;
    this->month = month;
    this->year = year;
}

Date::Date(string str)
{
    this->day = stoi(str.substr(0, str.find(".")));
    this->month = stoi(str.substr(str.find(".") + 1, str.rfind(".")));
    this->year = stoi(str.substr(str.rfind(".") + 1, str.length()));
}

int Date::getYear()
{
    return this->year;
}

int Date::getMonth()
{
    return this->month;
}

int Date::getDay()
{
    return this->day;
}

bool Date::isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int Date::convertToDays()
{
    const int startingPoint = 2000;
    int daysCounter = 0;
    int monthCounter = this->month - 1;

    if (isLeapYear(year)) {
        while (monthCounter >= 0) {
            daysCounter += daysInMonthsLeap[monthCounter];
            
            monthCounter--;
        }
        daysCounter += (this->year - startingPoint) * 366;
    }
    else {
        while (monthCounter >= 0) {
            daysCounter += daysInMonthsNonLeap[monthCounter];
            monthCounter--;
        }
        daysCounter += (this->year - startingPoint) * 365;
    }
    daysCounter += day;
    return daysCounter;
}

Date& Date::operator=(const Date& other) {
    this->day = other.day;
    this->month = other.month;
    this->year = other.year;

    return *this;
}

ostream& operator<<(ostream& os, const Date& date) {
    /*os.write((char*)&date.day, sizeof(date.day));
    os.write((char*)&date.month, sizeof(date.month));
    os.write((char*)&date.year, sizeof(date.year));*/
    os << date.day << "." << date.month << "." << date.year;
    return os;
}

istream& operator>> (istream& is, Date& date) {
    /*is.read((char*)&date.day, sizeof(date.day));
    is.read((char*)&date.month, sizeof(date.month));
    is.read((char*)&date.year, sizeof(date.year));*/
    string str = "";
    is >> str;
    date = Date(str);
    return is;
}
