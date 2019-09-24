#ifndef STOCK_H
#define STOCK_H
#include <string>
#include <vector>

class Stock
{
	public:
		Stock();
		Stock(double weight);
		virtual double weight() = 0;
		std::string ascii_art(int row);
	
	private:
		double _weight;
	
	protected:
		std::vector<std::string> _art;
};

#endif
