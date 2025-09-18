#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

struct customer_info
{
    std::string name;
    int assignedRoomNumber;
};


class Customer
{
public:
    Customer();

    void addCustomer(const std::string & name);
    void assignRoom(int index, int roomNumber);
    void releaseRoom(int index);
    std::string serialize() const;
    void deserialize(const std::string & data);
    void parseCustomer(const std::string & e);
    
private:
    std::vector<customer_info> customer_list;
};

std::ostream & operator<<(std::ostream & cout, const Customer & c);

#endif
