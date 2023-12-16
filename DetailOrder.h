#include<iostream>
using namespace std;
class DetailOrder{
    private:
        string idOrder;
        string  idBook;
        double salePrice;
        int quantityBook;
    public:
        DetailOrder();
        DetailOrder(string,string,double,int);
        string getIDOrder();
        int& getQuantityBook();
        double getSalePrice();
        string getIDBook();
};