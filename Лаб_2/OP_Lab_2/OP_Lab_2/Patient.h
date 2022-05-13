#pragma once
#include <iostream>
#include "Date.h"
#include <ctime>
#include <chrono>

using namespace std;

class Patient
{
private:
	string name;
	string surname;
	Date lastVisitDate;
	Date curVisitDate;

	friend ostream& operator<<(ostream& os, const Patient& patient);
	friend istream& operator>>(istream& is, Patient& patient);

public:
	void displayData();

	Patient();

	Patient(string name, string surname, Date lastVisitDate, Date curVisitDate);

	bool isNewPatient();
	bool timeIsUp();

	string getName();
	string getSurname();
	Date getLastVisitDate();
	Date getCurVisitDate();

	void setName(string name);
	void setSurname(string surname);
	void setLastVisitDate(Date lastVisitDate);
	void setCurVisitDate(Date curVisitDate);


};