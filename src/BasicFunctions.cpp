#include "BasicFunctions.h"




unsigned char myAbs(char ch_in)
{
	if (ch_in >= 0)
		return static_cast<unsigned char>(ch_in);
	else
	{
		return static_cast<unsigned char>(-ch_in);
	}
}