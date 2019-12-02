#ifndef __SHELTER_H
#define __SHELTER_H

#include "client.h"
#include <vector>

class Shelter {
  public:
    Shelter(std::string name);
    std::string name();
    ~Shelter();
    Shelter(std::istream& ist);
    void save(std::ostream& ost);
    
    std::string get_filename();
    void set_filename(std::string filename);

    void add_animal(Animal& animal);
    int num_animals();
    Animal& animal(int index); 
    void add_client(Client& client);
    int num_clients();
    Client& client(int index);
    void remove_animal(int index);
   	
   	std::vector<int> _undo;
   
  protected:
   	std::string filename;
    
  private:
    std::string _name;
    std::vector<Animal*> _available;
    std::vector<Client> _clients;
    
};

#endif

