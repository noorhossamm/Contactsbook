#include <iostream>
#include <iomanip>
#include "ContactBook.h"
#include "Person.h"
#include "Address.h"
#include "DynamicArray.h"

using namespace std;

int main()
{
    Person p1;
    ContactBook book;
      string filename;
    int choice;

    do
    {
        cout << "**** CONTACT BOOK MENU ****" << endl;
        cout << "1. Add a new Contact" << endl;
        cout << "2. Search by Last Name" << endl;
        cout << "3. Search by Classification (friend, family, other)" << endl;
        cout << "4. Print All Contacts" << endl;
        cout << "5. Print Favorite Contacts" << endl;
        cout << "6. Save to File" << endl;
        cout << "7. Load from File" << endl;
        cout << "8. Delete Contact" << endl;
        cout << "9. Update Contact Information" << endl;
        cout << "10. Reverse Contact Book" << endl;
        cout << "11. Exit" << endl;
        cout << "Enter Your Choice: ";
        cin >> choice;
        if(choice<1 || choice>11)
            {
                cout<<"Enter a valid choice please: ";
                cin>>choice;

        }

        switch (choice)
        {
            case 1:
            {
                Person newPerson;
                newPerson.input();
                book.AddContacts(newPerson);
                break;
            }
            case 2:
                book.SearchbyLastname();
                break;

            case 3:
                book.Searchbyclassification();
                break;

            case 4:
                book.printAllContacts();
                break;

            case 5:
                book.PrintAllFav();
                break;

            case 6:

                cout<<"Enter filename: ";
                cin>>filename;

                book.saveToFile(filename);
                break;

            case 7:

                cout<<"Enter filename: ";
                cin>>filename;
                book.loadFromFile(filename);
                break;

            case 8:
            {
                int index;
                cout << "Enter index to delete: ";
                cin >> index;
                book.DeleteContact(index);
                break;
            }
            case 9:
            {
                int index;
                cout << "Enter index to update: ";
                cin >> index;
                Person updatedPerson;
                updatedPerson.input();
                book.updateContact(index, updatedPerson);
                break;
            }
            case 10:
                book.ReverseContact();
                book.printAllContacts();
                break;

            case 11:
                cout << "Exiting program." << endl;
                break;

            default:
                cout << "Invalid choice. Please enter a number from 1 to 11." << endl;
        }

        cout << endl;

    } while (choice != 11);

    return 0;
}
