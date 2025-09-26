#ifndef VIPCUSTOMER_H
#define VIPCUSTOMER_H

#include "Customer.h"
#include <string>

class VIPCustomer : public Customer
{
  public:
    VIPCustomer();
    VIPCustomer(const std::string & name, const std::string & level);
    
    void setMembershipLevel(const std::string & level);
    std::string getMembershipLevel() const;
    
    double getDiscount() const;
    
  private:
    std::string membershipLevel;
};

#endif
