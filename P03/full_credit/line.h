#include <iostream>
#include <cstring>
#include <cmath>

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