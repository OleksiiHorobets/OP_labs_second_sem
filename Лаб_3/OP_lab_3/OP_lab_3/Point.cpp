#include "Point.h"

Point::Point()
{
	this->coordX = 0;
	this->coordY = 0;
}

Point::Point(double coordX, double coordY)
{
	this->coordX = coordX;
	this->coordY = coordY;
}

double Point::getCoordX()
{
	return this->coordX;
}

double Point::getCoordY()
{
	return this->coordY;
}

void Point::setCoordX(double coordX)
{
	this->coordX = coordX;
}

void Point::setCoordY(double coordY)
{
	this->coordY = coordY;
}


ostream& operator<<(ostream& os,const Point& point) {
	os << point.coordX <<' '<< point.coordY;
	return os;
}

istream& operator>>(istream& is, Point& point) {
	is >> point.coordX >> point.coordY;
	return is;
}