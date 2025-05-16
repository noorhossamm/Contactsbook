#include "Address.h"
Address::Address()
{}
Address::Address(string street, string city, string country)
     {
         this->street=street;
         this->country=country;
         this->city=city;
     }
Address::Address(const Address& a)
    : street(a.street), city(a.city), country(a.country) {}


Address::~Address() {}
void Address::input()
{
    cout << "Enter Street: ";
    cin >> street;
    cout << "Enter City: ";
    cin >> city;
    cout << "Enter Country: ";
    cin >> country;
}

string Address::getcountry() const
 {
     return country;
      }
string Address::getcity() const
 {
     return city;
     }
string Address::getstreet() const
{
    return street;
    }

void Address::setcountry(string cntr)
{
    country = cntr;
 }
void Address::setcity(string cty)
{
    city = cty;
     }
void Address::setstreet(string str)
 {
    street = str;
     }

void Address::display() const
{

cout<<street<<" "<<city<<" "<<country<<endl;

}
