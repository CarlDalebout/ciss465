#ifndef FILEMANAGMENT_H
#define FILEMANAGMENT_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct customer
{
  std::string name;
  int assignedRoomNumber;
  std::string phone_number;
};

class FileManagment
{
  public: 
    FileManagment()
    {}

    void parse_line(std::string, char);

    void load_file(std::string);
    void save_file(std::string);

    void add_row(std::vector<std::string>);
    
    std::vector<std::string>& operator[](int);
    const std::vector<std::string>& operator[](int) const;

   friend std::ostream& operator<<(std::ostream&, const FileManagment&);

  private:
    std::vector<std::vector<std::string>> _info;
};

#endif
