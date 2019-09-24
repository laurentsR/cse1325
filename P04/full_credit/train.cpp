#include "train.h"
#include "locomotive.h"
#include <cmath>

void Train::add_locomotive(Locomotive& locomotive)
{
	_locomotives.push_back(&locomotive);
}

void Train::add_coach(Coach& coach)
{
	_coaches.push_back(&coach);
}  

double Train::speed(double minutes)
{
	//Locomotive power;
	//double _power = power.power()
	//double weight = Stock::weight(weight);
	//double seconds = minutes*60;
	
	//double speed = (std::sqrt(2*power*seconds/weight));
	//return speed;
	
}

std::string Train::to_art()
{
	std::string result;
	for(int i = 0; i < 6; ++i)
	{
		for(int j = 0; j < Train::_locomotives.size(); ++j)
		{
			//result.append()
		}
	}
		
}
