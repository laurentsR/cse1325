#ifndef __SHELTER_H
#define __SHELTER_H

#include "Dog.h"


class Shelter
{
	public:
		Shelter(std::string name);
		std::string name();
		void add_animal(Animal&);
		int num_animals();
		Animal& animal(int index);
	
	private:
		std::string _name;
		std::vector<Animal> _available;
		
};

#endif
