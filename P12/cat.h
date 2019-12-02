#ifndef __CAT_H
#define __CAT_H

#include "animal.h"
#include <map>

// List of cat breeds, conversion to/from string and stream, and iteration
enum class Cat_breed {
    BENGAL,
    BOMBAY,
    BURMESE,
    EGYPTIAN,
    HIMALAYAN,
    MAINE_COON,
    MANX,
    MIX,
    PERSIAN,
    SCOTTISH_FOLD,
    SIAMESE,
    SPHYNX,
    TOYGER,
};
constexpr Cat_breed cat_breeds[] = {
    Cat_breed::BENGAL,
    Cat_breed::BOMBAY,
    Cat_breed::BURMESE,
    Cat_breed::EGYPTIAN,
    Cat_breed::HIMALAYAN,
    Cat_breed::MAINE_COON,
    Cat_breed::MANX, 
    Cat_breed::MIX,
    Cat_breed::PERSIAN,
    Cat_breed::SCOTTISH_FOLD,
    Cat_breed::SIAMESE,
    Cat_breed::SPHYNX,
    Cat_breed::TOYGER,
};
extern const std::map<Cat_breed, std::string> mapOfCats;
std::string to_string(const Cat_breed& breed);
std::ostream& operator<<(std::ostream& ost, const Cat_breed& breed);

// Class Cat with overrides for family and breed
class Cat : public Animal {
  public:
    Cat(Cat_breed breed, std::string name, Gender gender, int age);
    virtual ~Cat();
    Cat(std::istream& ist);
    void save(std::ostream& ost) override;
    virtual std::string family() const override;
    virtual std::string breed() const override;
  private:
    Cat_breed _breed;
};

#endif
