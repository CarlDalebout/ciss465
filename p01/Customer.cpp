#include "Customer.h"
#include <sstream>

Customer::Customer() {}


void Customer::addcustomer(const std::string & name)
{
    customer_info c;
    c.name = name;
    c.assignedRoomNumber = -1;
    customer_list.push_back(c);
}


void Customer::assignRoom(int index, int roomNumber)
{
    if (index >= 0 && index < (int)customer_list.size())
        customer_list[index].assignedRoomNumber == roomNumber;
}


void Customer::releaseRoom(int index)
{
    if (index >= 0 && index < (int)customer_list.size())
        customer_list[index].assignedRoomNumber = -1;
}


std::string Customer::serialize() const
{
    std::string result = "";
    for (int i = 0; i < customer_list.size(); ++i)
    {
        result += customer_list[i].name + ',' +
            std::to_string(customer_list[i].assignedRoomNumber);
        if (i != customer_list.size() - 1)
            result += '\n';
    }
    return result;
}


void Customer::deserialize(const std::string & data)
{
    customer_list.clear();
    int start = 0;
    int end;

    while ((end = data.find('\n', start)) != std::string::npos)
    {
        std::string token = data.substr(start, end - start);
        parseCustomer(token);
        start = end + 1;
    }
    if (start < data.size())
    {
        std::string token = data.substr(start);
        parseCustomer(token);
    }
}


void Customer::parseCustomer(const std::string & e)
{
    int comma = e.find(',');
    if (comma != std::string::npos)
    {
        customer_info c;
        c.name = e.substr(0, comma);
        c.assignedRoomNumber = std::stoi(e.subtr(comma + 1));
        customer_list.push_back(c)
    }
}
std::ostream & operator<<(std::ostream & cout, const Customer & c)
{
    for (int i = 0; i < c.customer_list.size(); ++i)
    {
        cout << "Customer: " << c.customer_list[i].name
             << " | Room Number: ";
        if (c.customer_list[i].assignedRoomNumber == -1)
            cout << "None";
        else
            cout << c.customer_list[i].assignedRoomNumber;

        if (i != c.customer_list.size() - 1)
            cout << '\n';
    }
    return cout;
}
