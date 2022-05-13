#include "Hospital.h"

void Hospital::fillSecondaryPatientList()
{
	for (int i = 0; i < this->patientList.size(); i++)
	{
		if (!this->patientList[i]->timeIsUp() && !(this->patientList[i]->isNewPatient())) this->secondaryPatientsList.push_back(this->patientList[i]);
	}
}

void Hospital::fillNewPatientsList()
{
	for (int i = 0; i < this->patientList.size(); i++)
	{
		if (!this->patientList[i]->timeIsUp() && (this->patientList[i]->isNewPatient())) this->newPatientsList.push_back(this->patientList[i]);
	}
}

Hospital::Hospital(vector<Patient*> patientList) {
	this->patientList = patientList;
}

void Hospital::deleteTimeUpPatients()
{
	fstream fout;
	string fileName = "patientsData.bin";

	fout.open(fileName, ios::binary | fstream::out);
	if (!fout.is_open()) {
		cout << "File open error!";
		exit(0);
	}

	for (int i = 0; i < this->getPatientList().size(); i++)
	{
		if (!this->getPatientList()[i]->timeIsUp()) {
			fout.write((char*)&(*(this->getPatientList()[i])), sizeof(*(this->getPatientList()[i])));
		}
	}
	fout.close();
}

void Hospital::getDataFromFile(string fileName)
{
 	fstream inputFile;
	inputFile.open(fileName, ios::binary | fstream::in);

	if (!inputFile.is_open()) {
		cout << "Read file open error!" << endl;
		exit(0);
	}

	while (!inputFile.eof()) {
		Patient* temp = new Patient{};
		inputFile.read((char*)temp, sizeof(*temp));

		if (inputFile.eof()) break;
		this->patientList.push_back(temp);

	}
	if (patientList.size() == 0) {
		cout << "Empty file!" << endl;
		exit(0);
	}
	inputFile.close();
}

vector<Patient*> Hospital::getPatientList()
{
	return vector<Patient*>(patientList);
}

void Hospital::writeToFile()
{
	string fileName = "patientsData.bin";
	fstream fout;
	
	fout.open(fileName, ios::binary | fstream::out);

	if (!fout.is_open()) {
		cout << "Write file open error!" << endl;
		exit(0);
	}
	for (int i = 0; i < this->patientList.size(); i++)
	{
		fout.write((char*)&(*(this->patientList[i])), sizeof(*(this->patientList[i])));
	}
	fout.close();
}

void Hospital::createPatientsList()
{
	string fileName = "patientList.bin";
	fstream fin;
	fin.open(fileName, ios::binary | fstream::out);
	if (!fin.is_open()) {
		cout << fileName<<" open error!" << endl;
		exit(0);
	}

	while (true) {
		char ans;
		cout << "Want add patient? Enter Y/N" << endl;
		cin >> ans;
		if (ans != 'Y') break;

		Patient* temp = new Patient();
		cin >> *temp;
		this->patientList.push_back(temp);
		fin.write((char*)&(*temp), sizeof(*temp));
	}
	fin.close();
}

void Hospital::createSecondaryPatientsFile()
{
	this->fillSecondaryPatientList();

	string fileName = "secondaryPatientsData.bin";

	fstream fout;
	fout.open(fileName, fstream::out | ios::binary);

	for (int i = 0; i < this->secondaryPatientsList.size(); i++)
	{
		fout << (*secondaryPatientsList[i]);
	}
	fout.close();
}

void Hospital::createNewPatientsFile()
{
	this->fillNewPatientsList();

	string fileName = "newPatientData.bin";

	fstream fout;
	fout.open(fileName, fstream::out | ios::binary);

	if (!fout.is_open()) {
		cout << "File open error!";
		exit(0);
	}

	for (int i = 0; i < this->newPatientsList.size(); i++)
	{

		fout.write((char*)&(*this->newPatientsList[i]), sizeof(*this->newPatientsList[i]));
		fout << (*(this->newPatientsList[i]));
	}
	fout.close();
}

void Hospital::displayData()
{
	for (int i = 0; i < this->getPatientList().size(); i++)
	{
		cout << *(this->getPatientList()[i]);
	}
}