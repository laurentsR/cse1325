#ifndef __RABBIT_H
#define __RABBIT_H

#include "animal.h"

// List of rabbit breeds, conversion to/from string and stream, and iteration
enum class Rabbit_breed {
    AMERICAN,
    BELGIAN_HARE,
    BLANC_DE_HOTOT,
    CALIFORNIAN,
    CHECKERED_GIANT,
    DUTCH,
    ENGLISH_LOP,
    MIX,
    FLEMISH_GIANT,
    NETHERLAND_DWARF,
    SATIN_ANGORA,
    SILVER,
    TAN,
};
constexpr Rabbit_breed rabbit_breeds[] = {
    Rabbit_breed::AMERICAN,
    Rabbit_breed::BELGIAN_HARE,
    Rabbit_breed::BLANC_DE_HOTOT,
    Rabbit_breed::CALIFORNIAN,
    Rabbit_breed::CHECKERED_GIANT,
    Rabbit_breed::DUTCH,
    Rabbit_breed::ENGLISH_LOP, 
    Rabbit_breed::MIX,
    Rabbit_breed::FLEMISH_GIANT,
    Rabbit_breed::NETHERLAND_DWARF,
    Rabbit_breed::SATIN_ANGORA,
    Rabbit_breed::SILVER,
    Rabbit_breed::TAN,
};
std::string to_string(const Rabbit_breed& breed);
std::ostream& operator<<(std::ostream& ost, const Rabbit_breed& breed);

// Class Rabbit with overrides for family and breed
class Rabbit : public Animal {
  public:
    Rabbit(Rabbit_breed breed, std::string name, Gender gender, int age);
    virtual ~Rabbit();
    Rabbit(std::istream& ist);
    void save(std::ostream& ost) override;
    virtual std::string family() const override;
    virtual std::string breed() const override;
  private:
    Rabbit_breed _breed;
};

#endif
