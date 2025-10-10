#include <cstring>
#include <algorithm>
#include "Rooms.h"

Rooms::Rooms()
:_info(std::vector<room>())
{}

void Rooms::bookRoom(int roomNumber)
{
  bool found_room = false;
  for(int i = 0; i < _info.size(); i++)
  {
    if(_info[i].roomNumber == roomNumber)
    {
      std::cout << "booking room: " << roomNumber << std::endl;
      _info[i].available = false;
      found_room = true;
    }
  }

  if(found_room)
    std::cout << "The room has been booked\n";
  else
    std::cout << "\n\n\nThere is no room with that number\n\n\n";
}

void Rooms::freeRoom(int roomNumber)
{
  bool found_room = false;
  for(int i = 0; i < _info.size(); i++)
  {
    if(_info[i].roomNumber == roomNumber)
    {
      std::cout << "booking room: " << roomNumber << std::endl;
      _info[i].available = true;
      found_room = true;
    }
  }

  if(found_room)
    std::cout << "The room has been freed\n";
  else
    std::cout << "\n\n\nThere is no room with that number\n\n\n";
}

void Rooms::addRoom(int roomNumber, std::string type, double price, bool available)
{
  _info.push_back(room{roomNumber, type, price, available});
}

bool compareRoomNumbers(const room& room1, const room& room2)
{
  return room1.roomNumber < room2.roomNumber;
}

void Rooms::sort()
{
  std::sort(_info.begin(), _info.end(), compareRoomNumbers);
}

void Rooms::saveFile() const
{
  std::ofstream file("rooms.txt", std::ios::binary);
  if (!file.is_open()) {
    std::cerr
      << "Error: Failed to open file for writing."
      << std::endl;
    return;
  }

  for (const room& i : _info) 
  {
    // Write room number
    file.write(reinterpret_cast<const char*>(&i.roomNumber), sizeof(i.roomNumber));

    // Write string length + characters
    size_t len = i.type.size();
    file.write(reinterpret_cast<const char*>(&len), sizeof(len));
    file.write(i.type.data(), len);

    // Write price + availability
    file.write(reinterpret_cast<const char*>(&i.price), sizeof(i.price));
    file.write(reinterpret_cast<const char*>(&i.available), sizeof(i.available));
  }  
  file.close();
}

void Rooms::loadFile()
{
  std::ifstream file("rooms.txt", std::ios::binary);
  if (!file) {
    std::cerr << "Error: Failed to open file for reading.\n";
    return;
  }

  _info.clear();
  while (true) 
  {
    room temp;

    // Room number
    if (!file.read(reinterpret_cast<char*>(&temp.roomNumber), sizeof(temp.roomNumber)))
      break;

    // String length + characters
    size_t len;
    file.read(reinterpret_cast<char*>(&len), sizeof(len));
    std::string buffer(len, '\0');
    file.read(buffer.data(), len);
    temp.type = buffer;

    // Price + availability
    file.read(reinterpret_cast<char*>(&temp.price), sizeof(temp.price));
    file.read(reinterpret_cast<char*>(&temp.available), sizeof(temp.available));

    _info.push_back(temp);
  }
}

std::ostream & operator<<(std::ostream & cout, const Rooms & c)
{
  for(const room& i : c._info)
  {
    cout << "Room Number: "   << i.roomNumber 
         << " | Room type: "  << i.type
         << " | price: "      << i.price
         << " | available: "  << i.available
         << std::endl;
  }
  return cout;
}
