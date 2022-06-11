#pragma once
#include "TNumber.h"

class TIntNumber : public TNumber
{
private:
	int number;

public:
	TIntNumber();

	TIntNumber(int number);

	int getLastDgt() override;
	
	int getFirstDgt() override;

	int getSumOfDgts() override;
};

