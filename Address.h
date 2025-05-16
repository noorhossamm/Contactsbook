#ifndef ADDRESS_H
#define ADDRESS_H
#include <string>
#include <iostream>
using namespace std;
class Address {
private:
    string street;
    string city;
    string country;

public:
    Address();
    Address(string street , string city , string country );
    Address(const Address& a);
    ~Address();
    void input();
    string getcountry() const;
    string getcity() const;
    string getstreet() const;
    void setcountry(string cntr);
    void setcity(string cty);
    void setstreet(string str);
    void display() const;
};

#endif // ADDRESS_H
