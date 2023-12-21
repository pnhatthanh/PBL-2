
#include<iostream>
#include"Book.h"
#include"Date.h"
#include<string>
using namespace std;
class Order{
    private:
        string idOrder;
        string idCustomer;
        Date date;
        string idDiscount;
        double discount;
        double totalPrice;
    public:
        Order();
        Order(string,string,Date,string,double,double);
        void setOrder();
        string getIDOrder();
        void setIDOrder(string);
        string getIDCustomer();
        void setIDCustomer(string);
        void setDate(Date);
        Date getDate();
        double getDiscount();
        double getTotalPrice();
        string getIDDiscount();
};