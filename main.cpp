#include"Menu.h"
int main(){
    Data d;
    d.readFileCustomer();
    d.readFileBook();
    d.readFileOrder();
    d.readFileDetailOrder();
    d.readFileDiscount();
    d.readFileCategory();
    Menu m;
    m.mainMenu(d);
    return 0;
}