//Ryan Laurents - 09/16/2019 - HW 02: Averages
#include <iostream>
#include "average.h"

Average::Average(double _sum, int _values) : _sum(0) , _values(0){}

std::ostream& operator<<(std::ostream& ost, const Average& average)
{
	if(average._values != 0)
	{
		int avg = average._sum/average._values;
		ost << avg << "\n";
		return ost;
	}
	else
	{
		ost << "Undefined.\n";
		return ost;
	}
}

std::istream& operator>>(std::istream& ist, Average& average)
{
	double temp;
	ist >> temp;
	average._sum = average._sum + temp;
	average._values = average._values +1;
}

/*
Average operator+=(Average& sum, Average& average)
{
	
}
*/

