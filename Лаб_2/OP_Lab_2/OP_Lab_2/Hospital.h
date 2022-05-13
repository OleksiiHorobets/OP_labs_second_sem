#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "Patient.h"

using namespace std;

class Hospital
{
private:
	vector<Patient*> patientList;
	vector<Patient*> secondaryPatientsList;
	vector<Patient*> newPatientsList;

	void fillSecondaryPatientList();
	void fillNewPatientsList();

public:
	Hospital() {}

	Hospital(vector<Patient*> patientList);

	void deleteTimeUpPatients();

	void getDataFromFile(string fileName);

	vector<Patient*> getPatientList();

	void writeToFile();

	void createPatientsList();

	void createSecondaryPatientsFile();

	void createNewPatientsFile();

	void displayData();

	
	
};

