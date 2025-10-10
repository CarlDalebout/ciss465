
#ifndef ROOMS_H
#define ROOMS_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

struct room
{
  int roomNumber;
  std::string type;
  double price; 
  bool available;
};

class Rooms
{
public:
  Rooms();
  
  void bookRoom(int roomNumber);
  void freeRoom(int roomNumber);

  void addRoom(int, std::string, double, bool);

  void sort();
  void saveFile() const;
  void loadFile();

  std::vector<room> _info;
};

std::ostream & operator<<(std::ostream & cout, const Rooms & c);

#endif
