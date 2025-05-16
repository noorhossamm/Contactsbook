#include "Person.h"
Person::Person(){}
Person::Person(string fName, string lName, string phone, string mail, int identifier, string c, Address addr, bool f)
    : firstName(fName), lastName(lName), phoneNumber(phone), email(mail), id(identifier), classification(c), address(addr), fav(f) {}

Person::Person(const Person& p)
    : firstName(p.firstName), lastName(p.lastName), phoneNumber(p.phoneNumber),
      email(p.email), id(p.id), classification(p.classification), address(p.address), fav(p.fav) {}

// Destructor
Person::~Person() {}

string Person::getfirstname() const
 {
      return firstName;
      }
string Person::getlastname() const
{
    return lastName;
    }
string Person::getphone() const
{
     return phoneNumber;
      }

void Person::setfirstname(string fname)
{
     firstName = fname;
     }
void Person::setlastname(string lname)
{
    lastName = lname;
    }
void Person::setphone(int phoneNum)
{
     phoneNumber = phoneNum;
     }

string Person::getclassification()
{
     return classification;
     }
void Person::setclassification(string c)
{
    classification = c;
 }

int Person::getid()
{
     return id;
      }
void Person::setid(int i)
{
     id = i;
     }

string Person::getemail()
{
     return email;
     }
void Person::setemail(int e)
{
     email = e;
     }

bool Person::getfav()
{
     return fav;
     }
void Person::setfav(bool f)
{
     fav = f;
     }

Address Person::getaddress()
{
     return address;
}

void Person::input()
{
    cout << "Enter First Name: ";
    cin >> firstName;
    cout << "Enter Last Name: ";
    cin >> lastName;

    int x;
    cout << "How many phone numbers: ";
    cin >> x;
    if(x>3){
        cout<<"Maximum number of phonenumber is 3 please enter again:"<<" ";
        cin>>x;
    }
    for (int i = 0; i < x; i++)
    {
        cout << "Enter Phone Number ( 11 digits): ";
        cin >> phoneNumber;

    }

    int n;
    cout << "How many mails: ";
    cin >> n;
    if(n>3){
        cout<<"Maximum number of emails is 3 please enter correct number of emails :"<<" ";
        cin>>n;
    }
    for (int i = 0; i < n; i++)
    {
        cout << "Enter Email: ";
        cin >> email;
    }

    cout << "Enter ID: ";
    cin >> id;
    cout << "Enter classification (friend, family, other): ";
    cin >> classification;
    cout << "Enter Address details:\n";
    address.input();
    cout << "Is fav or not: ";
    cin >> fav;


}

  void Person::display()
{
    cout << left << setw(15) << getfirstname()
         << setw(20) << getlastname()
         << setw(30) << getphone()
         << setw(25) << getemail()
         << setw(15) << getid()
         << setw(20) << getclassification()
         << setw(5) << getfav()
         << setw(15) << address.getstreet()
         << setw(15) << address.getcity()
         << setw(15) << address.getcountry();
    cout << endl;

}
