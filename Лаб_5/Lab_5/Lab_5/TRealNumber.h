#pragma once
#include "TNumber.h"
class TRealNumber : public TNumber
{
private:
	int integral;
	int fraction;
public:
	TRealNumber(int integral, int fraction);

	int getLastDgt() override;

	int getFirstDgt() override;

	int getSumOfDgts() override;
};

