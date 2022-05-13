#pragma once
#include <iostream>
#include <fstream>
#include "Point.h"

using namespace std;


class Line
{
private:
	double coeffA;
	double coeffB;
	double coeffC;

	friend ostream& operator<<(ostream& os, const Line& line);
	friend istream& operator>>(istream& is, Line& line);
public:
	Line() { coeffA = coeffB = coeffC = 0; }
	Line(double coeffA, double coeffB, double coeffC);

	double getCoeffA();
	double getCoeffB();
	double getCoeffC();

	void setCoeffA(double coeffA);
	void setCoeffB(double coeffB);
	void setCoeffC(double coeffC);

	bool lineContainsPoint(Point& point);
};

