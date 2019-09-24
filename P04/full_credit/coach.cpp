#include "coach.h"
#include <iostream>

Coach::Coach(double weight) : Stock(28000) 
{
	_art = { // Coach
        "               ",
        " ______________",
        " | [] [] [] []|",
        " |            |",
        "='OO--------OO'",
        "###############",
    };
};


int Coach::add_passengers(int passengers)
{
	Coach::_passengers += passengers;
	try
	{
		if(_passengers > 120)
		{
			throw _passengers;
		}
	}
	catch (int _passengers)
	{
		std::cout << "Too many passengers! The limit is 120, you have loaded " << _passengers << "\n" << std::endl;
	}
}

double Coach::weight()
{
	return (weight() + (_passengers * 60));
}
