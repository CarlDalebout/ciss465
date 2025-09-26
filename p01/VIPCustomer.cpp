#include "VIPCustomer.h"

VIPCustomer::VIPCustomer()
    : Customer(), membershipLevel("") {}

VIPCustomer:VIPCustomer(const std::string & name, const std::string & level)
    : Customer(), membershipLevel(level)
{
    addCustomer(name);
}


void VIPCustomer::setMembershipLevel(const std::string & level)
{
    membershipLevel = level;
}


std::string VIPCustomer::getMembershipLevel() const
{
    return membershipLevel;
}


double VIPCustomer::getDiscount() const
{
    if (membershipLevel == "Bronze")  // 5% discount
        return 0.05;
    else if (membershipLevel == "Silver") // 10% discount
        return 0.10;
    else if (membershipLevel == "Gold")  // 20% discount
        return 0.20;
    else
        return 0.0; // no discount 
}
