
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
        int flag;
    public:
        Discount();
        Discount(string,double,double,int,Date,Date,string,int);
        string getIDDiscount();
        double getDiscount();
        double getLevel();
        int& getQuantity();
        Date getFirstDate();
        Date getLastDate();
        string getStatus();
        int getFlag();
        void setFlag(int);
};