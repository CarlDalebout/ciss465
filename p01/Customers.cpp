#include <cstring>
#include <algorithm>
#include "Customers.h"

Customers::Customers()
:_info(std::vector<customer>())
{}

void Customers::addCustomers(int customerID, std::string name, int roomNumber, std::string phone_number)
{
  _info.push_back(customer{customerID, name, roomNumber, phone_number});
}

void Customers::addCustomers(const customer& c)
{
  _info.push_back(c);
}

void Customers::bookRoom(int customerID, int roomNumber)
{
  bool found_room = false;
  for(int i = 0; i < _info.size(); i++)
  {
    if(_info[i].customerID == customerID)
    {
      std::cout << "booking room: " << roomNumber << std::endl;
      _info[i].roomNumber= roomNumber;
      found_room = true;
    }
  }

  if(found_room)
    std::cout << "The room has been booked\n";
  else
    std::cout << "\n\n\nThere is no room with that number\n\n\n";
}

void Customers::freeRoom(int customerID)
{
  bool found_room = false;
  for(int i = 0; i < _info.size(); i++)
  {
    if(_info[i].customerID == customerID)
    {
      std::cout << "freeing room" << _info[i].roomNumber << std::endl;
      _info[i].roomNumber = -1;
      found_room = true;
    }
  }

  if(found_room)
    std::cout << "The room has been freed\n";
  else
    std::cout << "\n\n\nThere is no room with that number\n\n\n";
}

bool compareRoomNumbers(const customer& customer1, const customer& customer2)
{
  return customer1.customerID < customer2.customerID;
}

void Customers::sort()
{
  std::sort(_info.begin(), _info.end(), compareRoomNumbers);
}

void Customers::saveFile() const
{
  std::ofstream file("customers.txt", std::ios::binary);
  if (!file.is_open()) {
    std::cerr
      << "Error: Failed to open file for writing."
      << std::endl;
    return;
  }

  for (const customer& i : _info) 
  {
    // Write customerID
    file.write(reinterpret_cast<const char*>(&i.customerID), sizeof(i.customerID));

    // Write string length + characters
    size_t len = i.name.size();
    file.write(reinterpret_cast<const char*>(&len), sizeof(len));
    file.write(i.name.data(), len);

    // Write room number
    file.write(reinterpret_cast<const char*>(&i.roomNumber), sizeof(i.roomNumber));

    // Write string length + characters
    len = i.phone_number.size();
    file.write(reinterpret_cast<const char*>(&len), sizeof(len));
    file.write(i.phone_number.data(), len);
  }

  file.close();
}

void Customers::loadFile()
{
  std::ifstream file("customers.txt", std::ios::binary);
  if (!file) {
    std::cerr << "Error: Failed to open file for reading.\n";
    return;
  }

  _info.clear();
  while (true) 
  {
    customer temp;

    // Room number
    file.read(reinterpret_cast<char*>(&temp.customerID), sizeof(temp.customerID));

    // String length + name
    size_t len;
    if(!file.read(reinterpret_cast<char*>(&len), sizeof(len)))
      break;
    std::string buffer1(len, '\0');
    file.read(buffer1.data(), len);
    temp.name = buffer1;

    // Room number
    file.read(reinterpret_cast<char*>(&temp.roomNumber), sizeof(temp.roomNumber));

    // String length + phone_number
    file.read(reinterpret_cast<char*>(&len), sizeof(len));
    std::string buffer2(len, '\0');
    file.read(buffer2.data(), len);
    temp.phone_number = buffer2;

    _info.push_back(temp);
  }
}

std::ostream & operator<<(std::ostream & cout, const Customers & c)
{
  for(const customer& i : c._info)
  {
    cout << "CustomerID: "      << i.customerID
         << " | Name: "            << i.name
         << " | Room Number: "  << i.roomNumber
         << " | Phone Number: " << i.phone_number
         << std::endl;
  }
  return cout;
}
