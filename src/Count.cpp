#include "Count.h"

void count(bool& isL, bool& isR, bool& wasL, bool& wasR,
	unsigned char& peopleIn,
	unsigned char& peopleOut)

{
	if (isR && wasL && !isL)
	{
		++peopleOut;
		isL = false;
		isR = false;
		wasL = false;
		wasR = false;
	}
	if (isL && wasR && !isR)
	{
		++peopleIn;
		isL = false;
		isR = false;
		wasL = false;
		wasR = false;
	}
}