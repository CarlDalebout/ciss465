#ifndef FILEMANAGMENT_H
#define FILEMANAGMENT_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class FileManagment
{
  public: 
    FileManagment() 
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

  std::vector<std::string>& operator[](int index) {
        if (index < 0 || index >= _info .size()) {
            std::cerr << "Error: Index out of bounds!" << std::endl;
            // In a real application, you might throw an exception
            // For simplicity, we'll return a reference to a dummy value or exit
            exit(EXIT_FAILURE); 
        }
        return _info[index];
    }

    const std::vector<std::string>& operator[](int index) const {
        if (index < 0 || index >= _info.size()) {
            std::cerr << "Error: Index out of bounds!" << std::endl;
            // In a real application, you might throw an exception
            // For simplicity, we'll return a reference to a dummy value or exit
            exit(EXIT_FAILURE);
        }
        return _info[index];
    }

    friend std::ostream& operator<<(std::ostream&, const FileManagment&);

  private:
    std::vector<std::vector<std::string>> _info;
};

#endif
