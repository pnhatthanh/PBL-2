#include"Order.h"
Order::Order(){};
Order::Order(string id, string idCustomer,Date d,string dis,double totalPrice){
    this->idOrder=id;
    this->idCustomer=idCustomer;
    this->date=d;
    this->idDiscount=dis;
    this->totalPrice=totalPrice;
}
double Order::getTotalPrice(){
    return this->totalPrice;
}
string Order::getIDDiscount(){
    return this->idDiscount;
}
string Order::getIDOrder(){
    return this->idOrder;
}
string Order::getIDCustomer(){
    return this->idCustomer;
}
Date Order::getDate(){
    return this->date;
}
