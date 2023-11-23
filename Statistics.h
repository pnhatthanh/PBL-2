#pragma once
#include<iostream>
#include"Data.h"
#include"MapBook.h"
using namespace std;
class Statistics{
    private:
        Graphics g;
    public:
        void inventoryNumber(Data&);
        void listBestSeller(Data&);
        void sales(Data&);
};