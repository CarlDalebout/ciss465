//main.cpp

#include <iostream>
#include "FileManagment.h"

int main ()
{
  FileManagment rooms;
  rooms.load_file("rooms.txt");
  std::cout << "finished parse_line \n";
  std::cout << rooms;
  return 0;
}
