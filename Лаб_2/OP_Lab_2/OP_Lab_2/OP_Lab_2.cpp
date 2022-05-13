#include <iostream>
#include "Patient.h"
#include "Hospital.h"
#include "Date.h"


using namespace std;

void run(Hospital& hos);

int main()
{
	/*Patient *p1 = new Patient("Amantha", "Kriss", Date(13, 3, 2021), Date(21, 3, 2021));
	Patient *p2 = new Patient("Jackson", "Sutton", Date(22, 1, 2019), Date(20, 6, 2021));
	Patient *p3 = new Patient("Halbert", "Barlow", Date(14, 1, 2018), Date(20, 7, 2022));
	Patient *p4 = new Patient("Gregory", "Badman", Date(3, 2, 2016), Date(20, 3, 2019));
	Patient *p5 = new Patient("Toby", "Hammond", Date(14, 1, 2021), Date(20, 5, 2022));
	Patient* p6 = new Patient("Albert", "Morgh", Date(10, 5, 2022), Date(12, 5, 2022));
	
	vector<Patient*> patientLst = {p1, p2, p3, p4, p5 };
		
	Hospital hos1(patientLst);

	hos.writeToFile();*/
	
	Hospital hos;

	run(hos);

	hos.displayData();


	hos.deleteTimeUpPatients();
	hos.createNewPatientsFile();
	hos.createSecondaryPatientsFile();
}

void run(Hospital& hos) {

	int i;
	char s[10];

	cout << "--------------MENU--------------" << endl;
	cout << "<1>. Create patients list using console input" << endl;
	cout << "<2>. Get patients list data from file" << endl;

	cin.getline(s, 10);
	i = atoi(s);

	switch (i) {
	case 1: {
		system("cls");
		hos.createPatientsList();
		system("pause");
		break;
	}
	case 2: {
		system("cls");

		string fileName;
		cout << "Enter file name: " << endl;
		getline(cin, fileName);

		hos.getDataFromFile(fileName);

		system("pause");
		break;
	}
	default: {
		if (s[0] != '\0' && (i > 2 || i < 1)) {
			cout << "Wrong input!" << endl;
			system("pause");
		}
		break;
	}
	}
}
