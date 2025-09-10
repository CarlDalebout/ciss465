#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct room_info
{
  std::string room_number;
  std::string room_type;
  std::string room_price;
  std::string available;
};

class Room {
  public: 
    room_info parse_line(std::string line, char delim = ' ')
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

      room_info room{tokens[0], tokens[1], tokens[2], tokens[3]};
      return room;
    }

    /*Room(std::string room_file_name = "rooms.txt")*/
    /*{*/
    /*  std::ifstream room_file(room_file_name)*/
    /**/
    /*  while(std::getline(room_file, line)) // line formate room_number|room_type|room_price|available*/
    /*  {*/
    /*    room_list.push_back(parse_line(line));*/
    /*  }*/
    /*}*/
  private:
  std::vector<room_info> room_list;
};

#endif
