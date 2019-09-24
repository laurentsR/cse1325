#ifndef COACH_H
#define COACH_H
#include "stock.h"

class Coach : public Stock
{
	public:
		Coach(double weight);
		int add_passengers(int passengers);
		double weight() override;

	private:
		int _passengers;
};


#endif
