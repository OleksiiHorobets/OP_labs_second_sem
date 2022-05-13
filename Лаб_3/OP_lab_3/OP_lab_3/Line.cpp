#include "Line.h"

Line::Line(double coeffA, double coeffB, double coeffC)
{
	this->coeffA = coeffA;
	this->coeffB = coeffB;
	this->coeffC = coeffC;
}

double Line::getCoeffA()
{
	return this->coeffA;
}

double Line::getCoeffB()
{
	return this->coeffB;
}

double Line::getCoeffC()
{
	return this->coeffC;
}

void Line::setCoeffA(double coeffA)
{
	this->coeffA = coeffA;
}

void Line::setCoeffB(double coeffB)
{
	this->coeffB = coeffB;
}

void Line::setCoeffC(double coeffC)
{
	this->coeffC = coeffC;
}

bool Line::lineContainsPoint(Point& point)
{
	return  this->coeffA * point.getCoordX() + this->coeffB * point.getCoordY() + this->coeffC == 0;
}

ostream& operator<<(ostream& os, const Line& line) {
	os << line.coeffA << "*x";
	if (line.coeffB < 0) {
		os << line.coeffB << "*y";
	}
	else {
		os << " + " << line.coeffB << "*y";
	}
	if (line.coeffC < 0) {
		os << line.coeffC;
	}
	else {
		os << " + " << line.coeffC;
	}
	os << " = 0" << endl;
	return os;
}

istream& operator>>(istream& is, Line& line) {
	is >> line.coeffA >> line.coeffB >> line.coeffC;
	return is;
}