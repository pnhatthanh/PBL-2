#include"DetailOrder.h"
DetailOrder::DetailOrder(){}
DetailOrder::DetailOrder(string b, string c, int d){
    this->idOrder=b;
    this->nameBook=c;
    this->quantityBook=d;
}
string DetailOrder::getIDOrder(){
    return this->idOrder;
}
int& DetailOrder::getQuantityBook(){
    return this->quantityBook;
}
string DetailOrder::getNameBook(){
    return this->nameBook;
}