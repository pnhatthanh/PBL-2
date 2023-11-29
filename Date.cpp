#include "Date.h"
Date::Date()
{
}
Date::Date(int d, int m, int y)
{
    this->day = d;
    this->month = m;
    this->year = y;
}
void Date::setDay(int d)
{
    this->day = d;
}
int Date::getDay()
{
    return this->day;
}
void Date::setMonth(int m)
{
    this->month = m;
}
int Date::getMonth()
{
    return this->month;
}
void Date::setYear(int y)
{
    this->year = y;
}
int Date::getYear()
{
    return this->year;
}
void Date::setDate()
{
    Graphics g;
    while (true)
    {
        g.tab(60);
        cout<<"Nhap thoi gian(dd/mm/yyyy): ";
        string date;
        getline(cin, date);
        if (date.length() != 10 || date[2] != '/' || date[5] != '/')
        {
            g.tab(65);cout<<"Dinh dang ngay thang nam khong chinh xac!"<<endl;
        }
        else
        {
            int day = (date[0] - '0') * 10 + (date[1] - '0');
            int month = (date[3] - '0') * 10 + (date[4] - '0');
            int year = (date[6] - '0') * 1000 + (date[7] - '0') * 100 + (date[8] - '0') * 10 + (date[9] - '0');
            this->day = day;
            this->month = month;
            this->year = year;
            if (!this->checkDate())
            {
                g.tab(65);cout << "Ngay thang nam khong hop le. Vui long nhap lai!" << endl;
            }
            else
            {
                break;
            }
        }
    }
}
void Date::localDate(){
    time_t local = time(0);
    tm *ltm = localtime(&local);
    this->day=ltm->tm_mday;
    this->month=1+ltm->tm_mon;
    this->year=1900+ltm->tm_year;
}
ostream &operator<<(ostream &o, const Date &d)
{
    o << setw(2)  << d.day << "/" << setw(2) << 
    d.month << "/" << setw(4) << d.year;
    return o;
}
bool Date::checkDate()
{
    switch (this->month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if (this->day <= 0 || this->day > 31)
        {
            return false;
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        if (this->day <= 0 || this->day > 30)
        {
            return false;
        }
        break;
    case 2:
        if (this->year % 400 == 0 || (this->year % 4 == 0 && this->year % 100 != 0))
        {
            if (this->day <= 0 || this->day > 29)
                return false;
        }
        else if (this->day <= 0 || this->day > 28)
            return false;
        break;
    default:
        return false;
    }
    return true;
}
bool Date::operator<=(const Date &d)
{
    if (this->year < d.year)
    {
        return true;
    }
    else if (this->year == d.year)
    {
        if (this->month < d.month)
        {
            return true;
        }
        else if (this->month == d.month)
        {
            if (this->day <= d.day)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
bool Date::operator>=(const Date &d)
{
    if (this->year > d.year)
    {
        return true;
    }
    else if (this->year == d.year)
    {
        if (this->month > d.month)
        {
            return true;
        }
        else if (this->month == d.month)
        {
            if (this->day >= d.day)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}