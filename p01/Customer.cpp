#include "Customer.h"

Customer::Customer()
    : name_(""), room_number_(-1), phone_number_("") {}


Customer::Customer(const std::string & name, int room_number,
                   std::string phone_number)
    : name_(name), room_number_(room_number), phone_number_(phone_number) {}


std::string Customer::get_name() const { return name_; }


int Customer::get_room() const { return room_number_; }


std::string Customer::get_phone() const { return phone_number_; }


void Customer::set_name(const std::string & name) { name_ = name; }


void Customer::set_room(int room_number) { room_number_ = room_number; }


void Customer::set_phone(std::string phone) { phone_number_ = phone; }


bool Customer::has_room(int room) const
{
    return room_number_ == room;
}


void Customer::saveFile(std::ofstream & outFile) const
{
    if (outFile.is_open())
    {
        outFile << name_ << "," << room_number_ << "," << phone_number_
                << '\n';
    }
}


bool Customer::loadFile(std::ifstream & inFile)
{
    if (inFile.is_open())
    {
        std::string line;
        if (std::getline(inFile, line))
        {
            int pos1 = line.find(',');
            int pos2 = line.find(',', pos1 + 1);

            if (pos1 != std::string::npos && pos2 != std::string::npos)
            {
                name_ = line.substr(0, pos1);
                room_number_ = std::stoi(line.substr(pos1 + 1,
                                                     pos2 - pos1 - 1));
                
                phone_number_ = line.substr(pos2 + 1, pos2 - 1);
                return true;
            }
        }
    }
    return false;
}


std::ostream & operator<<(std::ostream & cout, const Customer & c)
{
    cout << "Customer: " << c.get_name() << " | Room: "
         << (c.get_room() == -1 ? "None" : std::to_string(c.get_room()))
         << " | Phone: " << c.get_phone();
    return cout;
}
