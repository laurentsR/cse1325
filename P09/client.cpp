#include "client.h"

Client::Client(std::string name, std::string phone, std::string email) : _name{name}, _phone{phone}, _email{email} { }
Client::~Client() { }
std::string Client::name() {return _name;}
std::string Client::phone() {return _phone;}
std::string Client::email() {return _email;}

std::string Client::to_string() {
    return _name + " (" + this->phone() + ") <" + this->email() + ">";
}
