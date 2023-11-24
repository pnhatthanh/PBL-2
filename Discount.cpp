#include"Discount.h"
Discount::Discount(){}
Discount::Discount(string id, double dis,double level, int q, Date fd, Date ld, string st,int fl){
    this->idDiscount=id;
    this->discount=dis;
    this->level=level;
    this->quantity=q;
    this->firstDate=fd;
    this->lastDate=ld;
    this->status=st;
    this->flag=fl;
}
string Discount::getIDDiscount(){
    return this->idDiscount;
}
double Discount::getDiscount(){
    return this->discount;
}
double Discount::getLevel(){
    return this->level;
}
int Discount::getQuantity(){
    return this->quantity;
}
Date Discount::getFirstDate(){
    return this->firstDate;
}
Date Discount::getLastDate(){
    return this->lastDate;
}
string Discount::getStatus(){
    return this->status;
}
int Discount::getFlag(){
    return this->flag;
}
void Discount::setFlag(int fl){
    this->flag=fl;
}