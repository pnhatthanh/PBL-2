
#include<iostream>
#include"Date.h"
using namespace std;
class Discount{
    private:
        string idDiscount;
        double discount;
        double level;
        int quantity;
        Date firstDate;
        Date lastDate;
        string status;
    public:
        Discount();
        Discount(string,double,double,int,Date,Date,string);
        string getIDDiscount();
        double getDiscount();
        double getLevel();
        int getQuantity();
        Date getFirstDate();
        Date getLastDate();
        string getStatus();
};