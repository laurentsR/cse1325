#ifndef __CLIENT_H
#define __CLIENT_H

#include <ostream>
#include <string>


class Client {
  public:
    Client(std::string name, std::string phone, std::string email);
    ~Client();
    std::string name();
    std::string phone();
    std::string email();
    std::string to_string();

  private:
    std::string _name;
    std::string _phone;
    std::string _email;
};

#endif

