#include <iostream>
#include "FileManagment.h"

void FileManagment::parse_line(std::string line, char delim = ',')
{
  std::string token = "";
  std::vector<std::string> tokens;

  for(int i = 0; i < line.size(); ++i)
  {
    if(line[i] == delim || line[i] == '\n')
    {
      if(token == "")
        continue;
      tokens.push_back(token);
      token = "";
      continue;
    }
    token += line[i];
  }

  if(token != "")
  {
    tokens.push_back(token);
    token = "";
  }

  _info.push_back(tokens);
}

void FileManagment::load_file(std::string file_name)
{
  std::ifstream file(file_name);
  std::string line;

  while(std::getline(file, line)) // line formate room_number|room_type|room_price|available
  {
    parse_line(line);
  }
}

void FileManagment::save_file(std::string file_name)
{

}

std::vector<std::string>& FileManagment::operator[](int index)
{
  if (index < 0 || index >= _info .size()) {
    std::cerr << "Error: Index out of bounds!" << std::endl;
    exit(EXIT_FAILURE); 
  }
  return _info[index];
}

const std::vector<std::string>& FileManagment::operator[](int index) const
{
  if (index < 0 || index >= _info.size()) {
    std::cerr << "Error: Index out of bounds!" << std::endl;
    exit(EXIT_FAILURE);
  }
  return _info[index];
}

std::ostream & operator<<(std::ostream& cout, const FileManagment& c)
{
  for(int i = 0; i < c._info.size(); ++i)
  {  
    for(int j = 0; j < c[i].size(); ++j)
    {
      cout << "room: " << i << " item: " << j << " text: " << c[i][j] << '\n';
    }
  }
  return cout;
}
