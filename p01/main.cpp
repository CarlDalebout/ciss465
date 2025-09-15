//main.cpp

#include <iostream>
#include "FileHandler.h"

int main ()
{
  FileHandler rooms;
  rooms.load_file("rooms.txt");
  std::cout << "finished parse_line \n";
  for(int i = 0; i < c._info.size(); ++i)
  {  
    for(int j = 0; j < c._info[i].size(); ++j)
    {
      std::cout << "room: " << i << " item: " << j << " text: " << c._info[i][j] << '\n';
    }
  }
  return 0;
}
