#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <iostream>
#include <iomanip>
#include "Address.h"
using namespace std;
class Person {
private:
    string firstName;
    string lastName;
    string phoneNumber;
    string email;
    int id;
    string classification;
    Address address;
    bool fav;

public:
    Person();
    Person(string fName, string lName, string phone, string mail, int identifier, string c, Address addr, bool f);
    Person(const Person& p);
    ~Person();
    string getfirstname() const;
    string getlastname() const;
    string getphone() const;
    void setfirstname(string fname);
    void setlastname(string lname);
    void setphone(int phoneNum);
    string getclassification();
    void setclassification(string c);
    int getid();
    void setid(int i);
    string getemail();
    void setemail(int e);
    bool getfav();
    void setfav(bool f);
    Address getaddress();
    void input();
    void display() ;

};

#endif // PERSON_H
