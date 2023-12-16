#include<iostream>
using namespace std;
class MapBook{
    private:
        string idBook;
        int count;
    public:
        MapBook();
        MapBook(string, int);
        void setCount(int);
        int getCount();
        string getIDBook();
        bool operator<(const MapBook&);
        friend ostream& operator<<(ostream&,const MapBook&);
};