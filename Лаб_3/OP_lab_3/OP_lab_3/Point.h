#pragma once
#include <fstream>
using namespace std;

class Point
{
private:
	double coordX;
	double coordY;

	friend istream& operator>>(istream& is, Point& point);
	friend ostream& operator<<(ostream& os, const Point& point);
public:
	Point();
	Point(double coordX, double coordY);

	double getCoordX();
	double getCoordY();

	void setCoordX(double coordX);
	void setCoordY(double coordY);

};

