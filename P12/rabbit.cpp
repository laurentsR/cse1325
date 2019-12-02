#include "rabbit.h"
#include <map>
#include <string>

// Constructor / Destructor - note how delegation to base class works!
Rabbit::Rabbit(Rabbit_breed breed, std::string name, Gender gender, int age)
    : Animal(name, gender, age), _breed{breed} { }
Rabbit::~Rabbit() { }

// File I/O
Rabbit::Rabbit(std::istream& ist) : Animal(ist) {
    std::string s;
    getline(ist, s);
    for(Rabbit_breed breed : rabbit_breeds) 
        if(s == ::to_string(breed)) {_breed = breed; break;}
}
void Rabbit::save(std::ostream& ost) {
    ost << "Rabbit\n";
    Animal::save(ost);
    ost << breed() << '\n';
}

// Overrides for pure virtual methods
std::string Rabbit::family() const {return "rabbit";}
std::string Rabbit::breed() const {return ::to_string(_breed);}

//Create a MAP for Rabbit breeds
std::map< Rabbit_breed, std::string > mapOfRabbits = 
{
	{ Rabbit_breed::BELGIAN_HARE, "Belgian Hare" },
	{ Rabbit_breed::BLANC_DE_HOTOT, "Blanc De Hotot" },
	{ Rabbit_breed::CALIFORNIAN, "Californian" },
	{ Rabbit_breed::CHECKERED_GIANT, "Checkered Giant" },
	{ Rabbit_breed::DUTCH, "Dutch" },
	{ Rabbit_breed::ENGLISH_LOP, "English Lop" },
	{ Rabbit_breed::FLEMISH_GIANT, "Flemish Giant" },
	{ Rabbit_breed::NETHERLAND_DWARF, "Netherland Dwarf" },
	{ Rabbit_breed::SATIN_ANGORA, "Satin Angora" },
	{ Rabbit_breed::SILVER, "Silver" },
	{ Rabbit_breed::TAN, "Tan" },
	{ Rabbit_breed::MIX, "Mix" },
};


// Convert breed to string and stream - use a std::map for other derived classes!
std::string to_string(const Rabbit_breed& breed) {
    auto it = mapOfRabbits.find(breed);
    return it->second;
}
std::ostream& operator<<(std::ostream& ost, const Rabbit_breed& breed) {
    ost << ::to_string(breed);
    return ost;
}

