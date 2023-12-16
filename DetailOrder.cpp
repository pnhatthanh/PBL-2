#include"DetailOrder.h"
DetailOrder::DetailOrder(){}
DetailOrder::DetailOrder(string b, string c,double salePrice,int d){
    this->idOrder=b;
    this->idBook=c;
    this->salePrice=salePrice;
    this->quantityBook=d;
}
string DetailOrder::getIDOrder(){
    return this->idOrder;
}
int& DetailOrder::getQuantityBook(){
    return this->quantityBook;
}
double DetailOrder::getSalePrice(){
    return this->salePrice;
}
string DetailOrder::getIDBook(){
    return this->idBook;
}