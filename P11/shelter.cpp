#include "shelter.h"

Shelter::Shelter(std::string name) : _name{name} { }
std::string Shelter::name() {return _name;}

void Shelter::add_animal(Animal& animal) {
    _available.push_back(&animal);
}
int Shelter::num_animals() {return _available.size();}
Animal& Shelter::animal(int index) {return *(_available[index]);}

void Shelter::add_client(Client& client) {
	_clients.push_back(&client);
}
int Shelter::num_clients() {return _clients.size();}
Client& Shelter::client(int index) {return *(_clients[index]);}

void Shelter::remove_animal(int index)
{
	_available.erase(_available.begin() + index);
}
/*
void Shelter::save(std::ostream& ost) {
  for(int i = 0; i < shelter::num_animals(); ++i)
  {
      ost << shelter->animal(i) << ' ';
      ost << std::endl;
  }

}
*/

