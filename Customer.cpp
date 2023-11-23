#include"Customer.h"
Customer::Customer(){}
Customer::Customer(string id, string name, string address, string phone, string email){
    this->idCustomer=id;
    this->fulName=name;
    this->address=address;
    this->phoneNumber=phone;
    this->email=email;
}
string Customer::getIDCustomer(){
    return this->idCustomer;
}
void Customer::setIDCustomer(string id){
    this->idCustomer=id;
}
string Customer::getFullName(){
    return this->fulName;
}
void Customer::setFullName(string name){
    this->fulName=name;
}
string Customer::getAddress(){
    return this->address;
}
void Customer::setAddress(string add){
    this->address=add;
}
string Customer::getPhoneNumber(){
    return this->phoneNumber;
}
void Customer::setPhoneNumber(string phone){
    this->phoneNumber=phone;
}
void Customer::setEmail(string email){
    this->email=email;
}
string Customer::getEmail(){
    return this->email;
}