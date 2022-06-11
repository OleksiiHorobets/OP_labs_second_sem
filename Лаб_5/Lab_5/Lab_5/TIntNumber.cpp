#include "TIntNumber.h"

TIntNumber::TIntNumber()
{
	this->number = 0;
}

TIntNumber::TIntNumber(int number)
{
	this->number = number;
}

int TIntNumber::getLastDgt()
{
	return abs(this->number) % 10;
}

int TIntNumber::getFirstDgt()
{
	int temp_num = abs(this->number);
	while (temp_num >= 10) {
		temp_num /= 10;
	}
	return temp_num;
}

int TIntNumber::getSumOfDgts()
{
	int temp_num = abs(this->number);
	int sum = 0;
	while (temp_num) {
		sum += temp_num % 10;
		temp_num /= 10;
	}
	return sum;
}
