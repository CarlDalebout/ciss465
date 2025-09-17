#include <iostream>
#include "FileManagment.h"

std::ostream & operator<<(std::ostream& cout, const FileManagment& c)
{
  for(int i = 0; i < c._info.size(); ++i)
  {  
    for(int j = 0; j < c._info[i].size(); ++j)
    {
      cout << "room: " << i << " item: " << j << " text: " << c[i][j] << '\n';
    }
  }
  return cout;
}
