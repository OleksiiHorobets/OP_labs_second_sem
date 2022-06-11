#include "TRealNumber.h"

TRealNumber::TRealNumber(int integral, int fraction)
{
    this->integral = integral;
    this->fraction = fraction;
}

int TRealNumber::getLastDgt()
{
    return abs(this->fraction)%10;
}

int TRealNumber::getFirstDgt()
{
    int temp_num = abs(this->integral);
    while (temp_num >= 10) {
        temp_num /= 10;
    }
    return temp_num;
}

int TRealNumber::getSumOfDgts()
{
    int sum = 0;
    int temp_num = abs(this->integral);

    while (temp_num) {
        sum += temp_num % 10;
        temp_num /= 10;
    }
    temp_num = this->fraction;
    while (temp_num) {
        sum += temp_num % 10;
        temp_num /= 10;
    }
    return sum;
}
