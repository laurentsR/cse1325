//Ryan Laurents - 09/16/2019 - HW 02: Averages
#ifndef AVERAGE_H
#define AVERAGE_H
#include <iostream>
class Average
{
private:
	//double _sum;
	//int _values;
	
public:
    double _sum;
	int _values;
	Average(double sum, int values);
	friend std::ostream& operator<<(std::ostream& ost, const Average& average);
	friend std::istream& operator>>(std::istream& ist, Average& average);
	Average operator += (Average& value);
};

#endif
