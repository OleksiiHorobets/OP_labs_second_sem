#include "surfaceVector.h"

surfaceVector::surfaceVector()
{
    this->coordX = 0;
    this->coordY = 0;
}

surfaceVector::surfaceVector(double coords[])
{
    this->coordX = coords[0];
    this->coordY = coords[1];
}

surfaceVector::surfaceVector(double coordX, double coordY)
{
    this->coordX = coordX;
    this->coordY = coordY;
}

surfaceVector surfaceVector::operator-(const surfaceVector& other)
{
    return surfaceVector(this->coordX - other.coordX, this->coordY - other.coordY);
}

surfaceVector surfaceVector::operator*(int factor)
{
    return surfaceVector(this->coordX * factor, this->coordY * factor);
}

double surfaceVector::getLen()
{
    
    return sqrt(this->coordX * this->coordX + this->coordY * this->coordY);
}

double surfaceVector::getCoordX()
{
    return this->coordX;
}

double surfaceVector::getCoordY()
{
    return this->coordY;
}

void surfaceVector::setCoordX(double coordX)
{
    this->coordX = coordX;
}

void surfaceVector::setCoordY(double coordY)
{
    this->coordY = coordY;
}

ostream& operator<<(ostream& os, const surfaceVector& vec) {
    os << vec.coordX << ' ' << vec.coordY;
    return os;
}

istream& operator>>(istream& is, surfaceVector& vec) {
    is >> vec.coordX >> vec.coordY;
    return is;
}
