#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <iostream>
#include <fstream>

class Customer
{
public:
    Customer();
    Customer(const std::string & name, int room_number = -1,
             std::string phone_number = "");
    
    std::string get_name() const;
    int get_room() const;
    std::string get_phone() const;

    void set_name(const std::string & name);
    void set_room(int room_number);
    void set_phone(std::string phone);

    bool has_room(int room) const;

    void saveFile(std::ofstream & outFile) const;
    bool loadFile(std::ifstream & inFile);
    
private:
    std::string name_;
    int room_number_;
    std::string phone_number_;
};

std::ostream & operator<<(std::ostream & cout, const Customer & c);

#endif
