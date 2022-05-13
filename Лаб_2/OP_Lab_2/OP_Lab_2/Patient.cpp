#include "Patient.h"

Patient::Patient() {
	this->name = "";
	this->surname = "";
	this->lastVisitDate;
	this->curVisitDate;
}

void Patient::displayData()
{
	cout << this->name << endl;
	cout << this->surname << endl;
	cout << this->lastVisitDate << endl;
	cout << this->curVisitDate << endl << endl;
}

Patient::Patient(string name, string surname, Date lastVisitDate, Date curVisitDate) {
	this->name = name;
	this->surname = surname;
	this->lastVisitDate = lastVisitDate;
	this->curVisitDate = curVisitDate;
}


bool Patient::isNewPatient()
{
	const int days_from_last_visit = 10;
	return (this->curVisitDate.convertToDays() - this->lastVisitDate.convertToDays() > days_from_last_visit);
}

bool Patient::timeIsUp()
{
	time_t t = time(0);
	tm* now = localtime(&t);
	Date currDate(now->tm_mday, now->tm_mon + 1, now->tm_year + 1900);
		
	return currDate.convertToDays() > this->curVisitDate.convertToDays();
}

//bool Patient::timeIsUp()
//{
//	/*time(NULL);
//	return ;*/
//}

string Patient::getName() { return (this->name); }
string Patient::getSurname() { return (this->surname); }
Date Patient::getLastVisitDate() { return (this->lastVisitDate); }
Date Patient::getCurVisitDate() { return (this->curVisitDate); }


void Patient::setName(string name) { this->name = name; }
void Patient::setSurname(string surname) { this->surname = surname; }
void Patient::setLastVisitDate(Date lastVisitDate) { this->lastVisitDate = lastVisitDate; }
void Patient::setCurVisitDate(Date curVisitDate) { this->curVisitDate = curVisitDate; }

ostream& operator<<(ostream& os, const Patient& patient)
{
	/*os.write((char*)&(patient.name), sizeof(patient.name));
	os.write((char*)&(patient.surname), sizeof(patient.surname));

	os.write((char*)&(patient.lastVisitDate), sizeof(patient.lastVisitDate));
	os.write((char*)&(patient.curVisitDate), sizeof(patient.curVisitDate));*/

	os << patient.name << endl << patient.surname << endl << patient.lastVisitDate << endl << patient.curVisitDate << endl << endl;
	return os;
}

istream& operator>>(istream& is, Patient& patient) {
	/*is.read((char*)&patient.name, sizeof(patient.name));
	is.read((char*)&patient.surname, sizeof(patient.surname));
	is.read((char*)& patient.lastVisitDate, sizeof(patient.lastVisitDate));
	is.read((char*)&patient.curVisitDate, sizeof(patient.curVisitDate));*/
	
	is >> patient.name >> patient.surname >> patient.lastVisitDate >> patient.curVisitDate;
	return is;
}
