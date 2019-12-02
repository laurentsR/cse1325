#ifndef __CLIENT_H
#define __CLIENT_H

#include <ostream>
#include <string>
#include <vector>
#include "animal.h"


class Client {
  public:
    Client(std::string name, std::string phone, std::string email);
    ~Client();
    Client(std::istream& ist);
    void save(std::ostream& ost);
    std::string name() const;
    std::string phone() const;
    std::string email() const;
    std::string to_string() const;
    int num_adopted();
    friend std::ostream& operator<<(std::ostream& ost, const Client& client);
    void adopt_animal(Animal& animal);
    Animal& adopted(int index); 

  private:
    std::string _name;
    std::string _phone;
    std::string _email;
    std::vector<Animal*> _adopted;
};

#endif

