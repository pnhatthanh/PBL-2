#include "Book.h"
Book::Book(string a, string b, string c, string d, int e, int f, double g, int flag)
    : idBook(a), nameBook(b), idCategory(c), nameAuthor(d), publishYear(e), quanity(f), price(g),flag(flag)
{ }
Book::~Book()
{ }
string Book::getIDBook()
{
    return this->idBook;
}
void Book::setIDBook(string new_value)
{
    this->idBook = new_value;
}
string Book::getNameBook()
{
    return this->nameBook;
}
void Book::setNameBook(string new_value)
{
    this->nameBook = new_value;
}
string Book::getIDCategory()
{
    return this->idCategory;
}
void Book::setIDCategory(string new_value)
{
    this->idCategory= new_value;
}
string Book::getNameAuthor()
{
    return this->nameAuthor;
}
void Book::setNameAuthor(string new_value)
{
    this->nameAuthor= new_value;
}
int Book::getPublishYear()
{
    return this->publishYear;    
}
void Book::setPublishYear(int new_value)
{
    if(new_value >= 0) this->publishYear = new_value;
}
int Book::getQuantity()
{
    return this->quanity;
}
void Book::setQuantity(int new_value)
{
    if(new_value >= 0) this->quanity = new_value;
}
double Book::getPrice()
{
    return this->price;
}
void Book::setPrice(double new_value)
{
    if(new_value >= 0) this->price = new_value;
}
int Book::getFlag(){
    return this->flag;
}
void Book::setFlag(int f){
    this->flag=f;
}
void Book::decreaseQuantity(int q){
    this->quanity=this->quanity-q;
}
bool Book::operator==(const Book &b){
    if(this->idBook==b.idBook){
        return true;
    }else{
        return false;
    }
}