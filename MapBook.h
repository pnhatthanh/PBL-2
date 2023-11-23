#include<iostream>
using namespace std;
class MapBook{
    private:
        string nameBook;
        int count;
    public:
        MapBook();
        MapBook(string, int);
        int& getCount();
        string& getBook();
        bool operator<(const MapBook&);
        friend ostream& operator<<(ostream&,const MapBook&);
};