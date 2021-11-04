#ifndef CUSTOMERDB_H
#define CUSTOMERDB_H

#include <map>
#include "Customer.h"

namespace MovieDB {

class CustomerDb final {
public:
    //There can be only one
    static CustomerDb& getInstance() {
      static CustomerDb cDb = CustomerDb();
        return cDb;
    }

    void addCustomerRentals(const Customer &c);

    virtual ~CustomerDb();
private:
    CustomerDb();

private:
    std::map<std::string, Customer> customers;
};

}

#endif //CUSTOMERDB_H
