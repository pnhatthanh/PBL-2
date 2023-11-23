#include<iostream>
using namespace std;
class DetailOrder{
    private:
        string idOrder;
        string nameBook;
        int quantityBook;
    public:
        DetailOrder();
        DetailOrder(string,string, int);
        string getIDOrder();
        int& getQuantityBook();
        string getNameBook();
};