#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class FileHandler
{
  public: 
    FileHandler() 
    {
    }

    void parse_line(std::string line, char delim = ',')
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

    void load_file(std::string file_name)
    {
      std::ifstream file(file_name);
      std::string line;

      while(std::getline(file, line)) // line formate room_number|room_type|room_price|available
      {
        parse_line(line);
      }
    }
  /*private:*/
    std::vector<std::vector<std::string>> _info;
};

std::ostream & operator<<(std::ostream & cout, const FileHandler & c)
{
  /*cout << "Customer: " << c.get_name() << " | Room: "*/
  /*     << (c.get_room() == -1 ? "None" : std::to_string(c.get_room()))*/
  /*     << " | Phone: " << c.get_phone();*/
  for(int i = 0; i < c._info.size(); ++i)
  {  
    for(int j = 0; j < c._info[i].size(); ++j)
    {
      std::cout << "room: " << i << " item: " << j << " text: " << c._info[i][j] << '\n';
    }
  }
}

#endif
