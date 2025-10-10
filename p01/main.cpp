//main.cpp

#include <iostream>
#include <string>
#include "Rooms.h"
#include "Customers.h"

int main ()
{
  std::string userinput;

  Rooms rooms;
  Customers customers;

  rooms.loadFile();
  customers.loadFile();

  std::cout << "Welcome to Hell0 H0tel\n"; 
  std::cout << "What would you like to do (m: Manage rooms and customers, r: Print reports ) : "; 
  std::cin >> userinput;

  switch(userinput)
  {
    case "m":
    case "M":
    {
      std::cout << "Would you like to 1: add a room, 2: book a room or 3: checkout a room\n";
      std::cint >> userinput;
      switch(userinput)
      {

      }
      break;
    }
    case "r":
    case "R":
    {
      break;
    }
  }

  /*std::cout << customers << "\n\n" <<std::endl;*/
  /*std::cout << "Would you like to add a customer? (y/n)\n";*/
  /*std::cin >> userinput; */
  /**/
  /*if(userinput == "y" || userinput == "Y" || userinput == "1")*/
  /*{*/
  /*  std::string name;*/
  /*  int roomNumber;*/
  /*  std::string phone_number;*/
  /**/
  /*  while(true)*/
  /*  {*/
  /*    std::cout << "what is the customers first name: ";*/
  /*    std::cin >> userinput; */
  /*    name += userinput;*/
  /**/
  /*    std::cout << "what is the customers last name: ";*/
  /*    std::cin >> userinput; */
  /*    name += ' ' + userinput;*/
  /**/
  /*    std::cout << "what is the room number: ";*/
  /*    std::cin >> roomNumber;*/
  /**/
  /*    std::cout << "what is the customers phone number: ";*/
  /*    std::cin >> phone_number;*/
  /**/
  /*    std::cout << "Customer Name: "            << name*/
  /*      << " | Room Number: "           << roomNumber*/
  /*      << " | Customer Phone Number: " << phone_number*/
  /*      << std::endl;*/
  /**/
  /*    std::cout << "is this correct? (y/n)\n";*/
  /*    std::cin >> userinput;*/
  /**/
  /*    if(userinput == "y" || userinput == "Y")*/
  /*    {*/
  /*      customers.addCustomers(name, roomNumber, phone_number);*/
  /*      customers.sort();*/
  /*      std::cout << "Would you like to add another? (y/n)\n";*/
  /*      std::cin >> userinput;*/
  /**/
  /*      if(userinput == "n" || userinput == "N")*/
  /*        break;*/
  /*    }*/
  /*  }*/
  /*}*/
  /**/
  /*customers.saveFile();*/

  /**/
  /*std::cout << "Would you like to add a room? (y/n)\n";*/
  /*std::cin >> userinput; */
  /**/
  /*if(userinput == "y" || userinput == "Y" || userinput == "1")*/
  /*{*/
  /*  int roomNumber;*/
  /*  std::string type;*/
  /*  double price;*/
  /*  bool available;*/
  /**/
  /*  while(true)*/
  /*  {*/
  /*    std::cout << "what is the room number: ";*/
  /*    std::cin >> roomNumber;*/
  /*    roomNumber = roomNumber;*/
  /**/
  /*    std::cout << "what is the room type: ";*/
  /*    std::cin >> type;*/
  /*    type = type;*/
  /**/
  /*    std::cout << "what is the price: ";*/
  /*    std::cin >> price;*/
  /*    price = price;*/
  /**/
  /*    std::cout << "is the room available y/n: ";*/
  /*    std::cin >> userinput;*/
  /*    available = (userinput == "y" || userinput == "Y" || userinput == "1") ? true : false;*/
  /**/
  /*    std::cout << "Room Number: "   << roomNumber */
  /*              << " | Room type: "  << type*/
  /*              << " | price: "      << price*/
  /*              << " | available: "  << available*/
  /*              << std::endl;*/
  /**/
  /*    std::cout << "is this correct? (y/n)\n";*/
  /*    std::cin >> userinput;*/
  /**/
  /*    if(userinput == "y" || userinput == "Y")*/
  /*    {*/
  /*      rooms.addRoom(roomNumber, type, price, available);*/
  /*      rooms.sort();*/
  /*      std::cout << "Would you like to add another? (y/n)\n";*/
  /*      std::cin >> userinput;*/
  /**/
  /*      if(userinput == "n" || userinput == "N")*/
  /*        break;*/
  /*    }*/
  /**/
  /*  }*/
  /*}*/
  /**/
  /*std::cout << "Would you like to book a room? (y/n)\n";*/
  /**/
  /*while(true)*/
  /*{  */
  /*  std::cin >> userinput; */
  /**/
  /*  if(userinput == "y" || userinput == "Y" || userinput == "1")*/
  /*  {*/
  /*    int roomNumber;*/
  /**/
  /*    std::cout << "What room would you like to book? \n" << rooms;*/
  /*    std::cin >> roomNumber;*/
  /**/
  /*    rooms.bookRoom(roomNumber);*/
  /*  }*/
  /*  else*/
  /*    break;*/
  /**/
  /*  std::cout << "Would you like to book another room? (y/n)\n";*/
  /*}*/
  /**/
  /*std::cout << rooms << "\nWould you like to free a room? (y/n)\n";*/
  /**/
  /*while(true)*/
  /*{*/
  /*  std::cin >> userinput; */
  /**/
  /*  if(userinput == "y" || userinput == "Y" || userinput == "1")*/
  /*  {*/
  /*    int roomNumber;*/
  /**/
  /*    std::cout << "What room would you like to free? \n" << rooms;*/
  /*    std::cin >> roomNumber;*/
  /**/
  /*    rooms.freeRoom(roomNumber);*/
  /*  }*/
  /*  else*/
  /*    break;*/
  /**/
  /*  std::cout << rooms << "would you like to free another room? (y/n)\n";*/
  /*}*/
  /**/
  /*std::cout << "After bookRoom: \n\n" << rooms << std::endl;*/
  /*rooms.saveFile();*/

  return 0;
}
