#ifndef __ANIMAL_H
#define __ANIMAL_H

#include "Gender.h"
#include <vector>
#include <string>

class Animal
{
	public:
		Animal(std::string name, Gender gender, int age);
		virtual ~Animal();
		virtual std::string family();
		virtual std::string breed();
		std::string name();
		Gender gender();
		int age();
		std::string to_string();
		
	protected:
		std::string _name;
		Gender _gender;
		int _age;
};

#endif
