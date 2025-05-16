#include "ContactBook.h"
#include <iostream>
#include <iomanip>
//#include <stdexcept>
#include <fstream>
using namespace std;
ContactBook::ContactBook() {}

Person ContactBook::AccessContacts(int x)
{
    if (x < 0 || x >= contacts.getSize())
        throw out_of_range("Index out of range");
    else
        return contacts.access(x);
}

void ContactBook::ReverseContact()
{
    contacts.reverse_elements();
}

void ContactBook::AddContacts(const Person& person)
{
    contacts.add(person);
}

void ContactBook::DeleteContact(int i)
{
    contacts.Delete(i);
}

void ContactBook::SearchbyLastname()
{
    string lastName;
    cout << "Enter last name to search: ";
    cin >> lastName;
       cout << "FirstName" <<
         setw(20) << "LastName" <<
          setw(30) << "PhoneNumber" <<
          setw(25) << "Email" <<
          setw(20) << "ID" <<
          setw(20) << "Classification" <<
          setw(15) << "Fav" <<
          setw(15) << "Street"  << setw(15) << "City" << setw(15) << "Country" << endl;
    cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

    bool found = false;
    for (int i = 0; i < contacts.getSize(); ++i)
    {
        if (contacts[i].getlastname() == lastName)
        {
            contacts[i].display();
            found = true;
        }
    }
    if (!found)
    {
        cout << "No contact found with last name " << lastName << endl;
    }
}

void ContactBook::Searchbyclassification()
{
    string classification;
    cout << "Enter classification to search: ";
    cin >> classification;
       cout <<"FirstName" <<
         setw(20) << "LastName" <<
          setw(30) << "PhoneNumber" <<
          setw(25) << "Email" <<
          setw(20) << "ID" <<
          setw(20) << "Classification" <<
          setw(5) << "Fav" <<
          setw(15) << "Street"  << setw(15) << "City" << setw(15) << "Country" << endl;
    cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

    bool found = false;
    for (int i = 0; i < contacts.getSize(); ++i)
    {
        if (contacts[i].getclassification() == classification)
        {
            contacts[i].display();
            found = true;
        }
    }
    if (!found)
    {
        cout << "No contact found with classification " << classification << endl;
    }
}

void ContactBook::printAllContacts()
{
  cout << "FirstName" <<
     setw(20) << "LastName" <<
     setw(30) << "PhoneNumber" <<
     setw(25) << "Email" <<
     setw(20) << "ID" <<
     setw(20) << "Classification" <<
     setw(15) << "Fav" <<
     setw(15) << "Street" << setw(15) << "City" << setw(15) << "Country" << endl;

   cout<<"-----------------------------------------------------------------------------------------------------------------------------------------------"<<endl;

    for (int i = 0; i < contacts.getSize(); ++i)
    {

       contacts[i].display();
    }
}

void ContactBook::saveToFile(string filename)
{
    ofstream myFile;
    myFile.open(filename);

        for (int i = 0; i < contacts.getSize(); i++)
        {

            myFile<<contacts[i].getfirstname()<<"   ";
            myFile<<contacts[i].getlastname()<<"   ";
            myFile<<contacts[i].getid()<<"   ";
            myFile<<contacts[i].getclassification()<<"   ";
            myFile<<contacts[i].getemail()<<"   ";
            myFile<<contacts[i].getfav()<<"   ";
             Address a;
           myFile<<a.getcity()<<"   "<<a.getcountry()<<"  "<<a.getstreet();
           cout<<endl;
        }
        cout<<"Saved contacts to File ,Open to check"<<endl;
        myFile.close();

}

void ContactBook::loadFromFile(string filename)
{
    ifstream MyFile;
    MyFile.open(filename);
    if(MyFile.is_open()==false)
    {
        cout<<"The file is not opened "<<endl;

    }
    else
        cout<<"File is opened "<<endl;
    string firstname,lastname,phone,classification,email,city,country,street;
    int id;
    bool fav;
    while(MyFile>>firstname>>lastname>>phone>>email>>id>>classification>>country>>city>>street>>fav)
    {
        Address a(street,city,country);
        Person p(firstname,lastname,phone,email,id,classification,a,fav);
        AddContacts(p);

    }


        MyFile.close();
        cout<<"File is closed. "<<endl;


}

void ContactBook::updateContact(int index, const Person& newPerson)
{
    if (index >= 0 && index < contacts.getSize())
        contacts[index] = newPerson;
    else
        cout << "Index out of range." << endl;
}

void ContactBook::PrintAllFav()
{
   cout << "FirstName" <<
         setw(20) << "LastName" <<
          setw(30) << "PhoneNumber" <<
          setw(25) << "Email" <<
          setw(20) << "ID" <<
          setw(20) << "Classification" <<
          setw(15) << "Fav" <<
          setw(15) << "Street"  << setw(15) << "City" << setw(15) << "Country" << endl;

    cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < contacts.getSize(); ++i)
    {
        if (contacts[i].getfav())
            contacts[i].display();
    }
}
