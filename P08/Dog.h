#ifndef __DOG_H
#define __DOG_H

#include "Dog_breed.h"
#include "Animal.h"


class Dog : public Animal
{
	public:
		Dog(Dog_breed breed, std::string name, Gender gender, int age);
		virtual ~Dog();
		std::string family() override;
		std::string breed() override;
		
	private:
		Dog_breed _breed;
};

#endif
