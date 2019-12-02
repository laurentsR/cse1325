#include "client.h"

Client::Client(std::string name, std::string phone, std::string email) : _name{name}, _phone{phone}, _email{email} { }
Client::~Client() { }
std::string Client::name() const{return _name;}
std::string Client::phone() const{return _phone;}
std::string Client::email() const{return _email;}

// File I/O
Client::Client(std::istream& ist) {
    std::getline(ist, _name);
    std::getline(ist, _phone);
    std::getline(ist, _email);
    int animals;
    ist >> animals; ist.ignore(65535, '\n');
    while(animals--) _adopted.push_back(Animal::make_animal(ist)); 
}
void Client::save(std::ostream& ost) {
    ost << _name << '\n' << _phone << '\n' << _email << '\n';
    ost << _adopted.size() << '\n';
    for (Animal* a : _adopted) a->save(ost);
}


std::string Client::to_string() const {
    return _name + " (" + this->phone() + ") <" + this->email() + ">";
}

std::ostream& operator<<(std::ostream& ost, const Client& client) {
    ost << client.to_string();
    return ost;
}

void Client::adopt_animal(Animal& animal) {
    _adopted.push_back(&animal);
}

int Client::num_adopted() 
{
	return _adopted.size();
}

Animal& Client::adopted(int index) {return *(_adopted[index]);}
