//main.cpp

#include <iostream>
#include <string>
#include "Rooms.h"
#include "Customers.h"

int main ()
{
  int switchChoice = 1;

  Rooms rooms;
  Customers customers;

  rooms.loadFile();
  customers.loadFile();

  std::cout << "Welcome to Hell0 H0tel\n";

  while(switchChoice != 0)
  {
    std::cout << "What would you like to do (0: Exit, 1: Manage rooms and customers, 2: Print reports ): "; 
    std::cin >> switchChoice;

    switch(switchChoice)
    {
      case 0:
        break;

      case 1:
        {
          std::cout << "Would you like to do (1: add a room, 2: add a customer 3: book a room 4: checkout a room 5: free a room): ";
          std::cin >> switchChoice;
          switch(switchChoice)
          {
            case 1:
              {
                std::string userinput;

                std::cout << '\n' << rooms << std::endl;

                int roomNumber;
                std::string type;
                double price;
                bool available;

                while(true)
                {
                  std::cout << "what is the room number: ";
                  std::cin >> roomNumber;

                  std::cout << "what is the room type: ";
                  std::cin >> type;

                  std::cout << "what is the price: ";
                  std::cin >> price;

                  std::cout << "is the room available y/n: ";
                  std::cin >> userinput;
                  available = (userinput == "y" || userinput == "Y" || userinput == "1") ? true : false;

                  std::cout << "Room Number: "   << roomNumber 
                            << " | Room type: "  << type
                            << " | price: "      << price
                            << " | available: "  << available
                            << std::endl;

                  std::cout << "is this correct? (y/n)\n";
                  std::cin >> userinput;

                  if(userinput == "y" || userinput == "Y")
                  {
                    rooms.addRoom(roomNumber, type, price, available);
                    rooms.sort();
                    std::cout << "Would you like to add another? (y/n)\n";
                    std::cin >> userinput;

                    if(userinput == "n" || userinput == "N")
                      break;
                  }
                }
                break;
              }

            case 2:
              {
                std::string userinput;

                int customerID;
                std::string name;
                int roomNumber;
                std::string phone_number;

                while(true)
                {
                  std::cout << "what is the customerID: ";
                  std::cin >> customerID;

                  std::cout << "what is the customers first name: ";
                  std::cin >> userinput;
                  name += userinput;

                  std::cout << "what is the customers last name: ";
                  std::cin >> userinput;
                  name += ' ' + userinput;

                  std::cout << "what is the room number: ";
                  std::cin >> roomNumber;

                  std::cout << "what is the customers phone number: ";
                  std::cin >> phone_number;

                  std::cout << "CustomerID: " << customerID
                    << " | Customer Name: "    << name
                    << " | Room Number: "           << roomNumber
                    << " | Customer Phone Number: " << phone_number
                    << std::endl;

                  std::cout << "is this correct? (y/n)\n";
                  std::cin >> userinput;

                  if(userinput == "y" || userinput == "Y")
                  {
                    customers.addCustomers(customerID, name, roomNumber, phone_number);
                    customers.sort();
                    std::cout << "Would you like to add another? (y/n)\n";
                    std::cin >> userinput;

                    if(userinput == "n" || userinput == "N")
                      break;
                  }
                }
                break;
              }

            case 3:
              {
                int userinput;

                std::cout << customers;
                std::cout << rooms;

                int customerID;
                std::cout << "What is the customer's id number: ";
                std::cin >> customerID;
                std::cout << "What room will the customer reside in: ";
                std::cin >> userinput;

                customers.bookRoom(customerID, userinput);
                rooms.bookRoom(userinput);
                break;
              }

            case 4:
              {
                int userinput;

                int customerID;

                std::cout << customers;

                std::cout << "What room is the customer in: ";
                std::cin >> userinput;

                customers.freeRoom(userinput);
                rooms.freeRoom(userinput);
                break;
              }

            case 5:
              {
                int userinput;

                std::cout << rooms;

                std::cout << "What room would you like to free: ";
                std::cin >> userinput;

                rooms.freeRoom(userinput);
                break;
              }
          }
          break;
        }

      case 2:
        {
          std::cout << "What report would you like to print (1: Rooms and Room Statis, 2: customers): ";
          std::cin  >> switchChoice;
          switch(switchChoice)
          {

            case 1:
              {
                std::cout << '\n' <<  rooms << std::endl;   
                break;
              }

            case 2:
              {
                std::cout << '\n' << customers << std::endl;   
                break;
              }

          }
          break;
        }
    }
  }

  rooms.saveFile();
  customers.saveFile();

  return 0;
}
