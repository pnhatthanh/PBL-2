#include<iostream>
using namespace std;
class Customer
{
    private:
        string idCustomer;
        string fulName;
        string address;
        string phoneNumber;
        string email;
    public:
        Customer();
        Customer(string, string, string, string, string);
        string getIDCustomer();
        void setIDCustomer(string);
        string getFullName();
        void setFullName(string);
        string getAddress();
        void setAddress(string);
        string getPhoneNumber();
        void setPhoneNumber(string);
        string getEmail();
        void setEmail(string);

};