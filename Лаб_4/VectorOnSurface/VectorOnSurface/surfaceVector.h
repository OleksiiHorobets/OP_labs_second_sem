#pragma once
#include <iostream>
#include <fstream>


using namespace std;
class surfaceVector
{
private:
	double coordX;
	double coordY;

	
	friend ostream& operator<<(ostream& os, const surfaceVector& vec);
	friend istream& operator>>(istream& is, surfaceVector& vec);


public:

	surfaceVector();
	surfaceVector(double coords[]);
	surfaceVector(double coordX, double coordY);

	surfaceVector operator - (const surfaceVector& other);

	surfaceVector operator * (int factor);

	double getLen();

	double getCoordX();
	double getCoordY();


	void setCoordX(double coordX);
	void setCoordY(double coordY);

};

