#include<iostream>
#include"Statistics.h"
#include"OrderManagement.h"
#include"CustomerManagement.h"
#include"DiscountManagement.h"
#include"BookManagement.h"
using namespace std;
class Menu{
    private:
        Graphics g;
    public:
        void mainMenu(Data&);
        void bookMenu(Data&);
        void customerMenu(Data&);
        void orderMenu(Data&);
        void discountMenu(Data&);
        void statisticsMenu(Data&);
        void loadingBar();
};