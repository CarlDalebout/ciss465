#ifndef CUSTOMERS_H
#define CUSTOMERS_H

#include <string>
#include <iostream>
#include <vector>
#include <fstream>

struct customer
{
  std::string name;
  int roomNumber;
  std::string phone_number;
};

class Customers
{
public:
  Customers();
  
  void addCustomers(std::string, int, std::string);
  void addCustomers(const customer&);

  void sort();
  void saveFile() const;
  void loadFile();

/*private:*/
  std::vector<customer> _info;
};

std::ostream & operator<<(std::ostream & cout, const Customers & c);

#endif
