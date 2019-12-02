#include "cat.h"
#include <map>
#include <string>

// Constructor / Destructor - note how delegation to base class works!
Cat::Cat(Cat_breed breed, std::string name, Gender gender, int age)
    : Animal(name, gender, age), _breed{breed} { }
Cat::~Cat() { }

// File I/O
Cat::Cat(std::istream& ist) : Animal(ist) {
    std::string s;
    getline(ist, s);
    for(auto& [_breed, breed_name] : mapOfCats)
        if(s == breed_name) break;
}
void Cat::save(std::ostream& ost) {
    ost << "Cat\n";
    Animal::save(ost);
    ost << breed() << '\n';
}


// Overrides for pure virtual methods
std::string Cat::family() const {return "cat";}
std::string Cat::breed() const {return ::to_string(_breed);}

//Create a MAP for cat breeds
const std::map<Cat_breed, std::string> mapOfCats = 
{
	{ Cat_breed::BOMBAY, "Bombay" },
	{ Cat_breed::BURMESE, "Burmese" },
	{ Cat_breed::EGYPTIAN, "Egyptian" },
	{ Cat_breed::HIMALAYAN, "Himalayan" },
	{ Cat_breed::MAINE_COON, "Maine Coon" },
	{ Cat_breed::MANX, "Manx" },
	{ Cat_breed::PERSIAN, "Persian" },
	{ Cat_breed::SCOTTISH_FOLD, "Scottish Fold" },
	{ Cat_breed::SIAMESE, "Siamese" },
	{ Cat_breed::SPHYNX, "Sphynx" },
	{ Cat_breed::TOYGER, "Toyger" },
	{ Cat_breed::MIX, "Mix" },
};


// Convert breed to string and stream - use a std::map for other derived classes!
std::string to_string(const Cat_breed& breed) {
    auto it = mapOfCats.find(breed);
    return it->second;
}
std::ostream& operator<<(std::ostream& ost, const Cat_breed& breed) {
    ost << ::to_string(breed);
    return ost;
}

