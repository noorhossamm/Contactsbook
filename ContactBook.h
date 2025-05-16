#ifndef CONTACTBOOK_H
#define CONTACTBOOK_H
#include <iostream>
#include <iomanip>
#include <string>
#include "DynamicArray.h"
#include "DynamicArray.cpp"
#include "Person.h"
#include <fstream>
class ContactBook
{
private:
    DynamicArray<Person> contacts;

public:
    ContactBook();
    Person AccessContacts(int x);
    void ReverseContact();
    void AddContacts(const Person& person);
    void DeleteContact(int i);
    void SearchbyLastname();
    void Searchbyclassification();
    void printAllContacts();
    void saveToFile(string filename);
    void loadFromFile(string filename);
    void updateContact(int index, const Person& newPerson);
    void PrintAllFav();
};

#endif // CONTACTBOOK_H
