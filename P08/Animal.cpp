#include "Animal.h"

Animal::Animal(std::string name, Gender gender, int age)
    : _name{name}, _gender{gender}, _age{age} { }


Animal::~Animal() { }

std::string Animal::family() {}
std::string Animal::breed() {}

std::string Animal::name() {return _name;}

Gender Animal::gender() {return _gender;}

int Animal::age() {return _age;}

std::string Animal::to_string() { }
