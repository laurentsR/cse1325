#include "Dog.h"

Dog::Dog(Dog_breed breed, std::string name, Gender gender, int age)
    : _breed{breed}, Animal{_name, _gender, _age} { }
    
Dog::~Dog() { }

std::string Dog::family() { }

std::string Dog::breed() { }
