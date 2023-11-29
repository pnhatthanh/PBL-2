#pragma once
#include <iostream>
#include<ctime>
#include<iomanip>
#include"Graphics.h"
using namespace std;
class Date{
    private:
        int day;
        int month;
        int year;
    public:
        Date();
        Date(int, int, int);
        int getDay();
        void setDay(int);
        int getMonth();
        void setMonth(int);
        int getYear();
        void setYear(int);
        void setDate();
        void localDate();
        friend ostream& operator <<( ostream&, const Date&);
        bool checkDate();
        bool operator<=(const Date&);
        bool operator>=(const Date&);
};