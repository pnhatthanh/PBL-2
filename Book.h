#include<iostream>
using namespace std;
class Book
{
        string idBook;
        string nameBook;
        string idCategory;
        string nameAuthor;
        int publishYear;
        int quanity;
        double price;
        int flag;
    public:
        Book(string = "", string = "", string="", string = "", int=0, int = 0, double = 0,int=0);
        ~Book();
        string getIDBook();
        void setIDBook(string);
        string getNameBook();
        void setNameBook(string);
        string getIDCategory();
        void setIDCategory(string);
        string getNameAuthor();
        void setNameAuthor(string);
        int getPublishYear();
        void setPublishYear(int);
        int getQuantity();
        void setQuantity(int);
        double getPrice();
        void setPrice(double);
        int getFlag();
        void setFlag(int);
        void decreaseQuantity(int);
        bool operator ==(const Book&);
};
