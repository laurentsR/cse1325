#include <iostream>
#include <cstring>
#include <cmath>
//#include "line.h"

class Line
{
public:
 Line(double x1, double y1, double x2, double y2);
 std::string to_string();
 double length();
 
private:
 double _x1;
 double _x2;
 double _y1;
 double _y2;
};

Line::Line(double x1, double y1, double x2, double y2) : _x1(x1), _y1(y1), _x2(x2), _y2(y2) {};

std::string Line::to_string()
{
std::string s = "";
s = "(" + std::to_string(_x1) + "," + std::to_string(_y1) + ")-(" + std::to_string(_x2) + "," + std::to_string(_y2) + ")\n";
return s;
}

double Line::length()
{
	double x;
	x = ((_x1 - _x2)*(_x1 - _x2)) + ((_y1 - _y2)*(_y1 - _y2));
	x = sqrt(x);
	return x;
}

int main() 
{    
Line line{1, 2, 3, 4};    
std::cout << line.to_string() << " is " << line.length() << " long" << std::endl;
}
