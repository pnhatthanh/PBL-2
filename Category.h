#include<iostream>
using namespace std;
class Category{
    private:
        string idCategory;
        string nameCategory;
    public:
        Category();
        Category(string, string);
        void setIDCategory(string);
        string getIDCategory();
        void setNameCategory(string);
        string getNameCategory();
};