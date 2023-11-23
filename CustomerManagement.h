#include"Data.h"
#include<string>
#include<iostream>
using namespace std;
class CustomerManagement
{
private:
    Graphics g;
public:
    CustomerManagement();
    ~CustomerManagement();
    void searchCustomer(Data&);
    void deleteCustomer(Data&);
    void showCustomer(Data&);
};

