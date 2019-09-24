#ifndef LOCOMOTIVE_H
#define LOCOMOTIVE_H
#include "stock.h"

class Locomotive : public Stock
{
	public:
		Locomotive(double weight, double power);
		double power();
		double weight() override;
	
	private:
		double _power;
};


#endif
