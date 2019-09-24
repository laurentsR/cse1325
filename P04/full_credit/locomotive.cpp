#include "locomotive.h"

Locomotive::Locomotive(double weight, double power) : _power(80000) , Stock(13500) 
{
	_art = { // Locomotive
 	"       * # @ ",
 	"     . ______",
 	"   _()_||__||",
 	"  ( cse1325 |",
 	" /-OO----OO''",
 	"#############",
	};
};

double Locomotive::power()
{
	return Locomotive::_power;
}


