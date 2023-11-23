#include"Category.h"
Category::Category(){
    this->idCategory="";
    this->nameCategory="";
}
Category::Category(string id, string name){
    this->idCategory=id;
    this->nameCategory=name;
}
void Category::setIDCategory(string id){
    this->idCategory=id;
}
string Category::getIDCategory(){
    return this->idCategory;
}
void Category::setNameCategory(string name){
    this->nameCategory=name;
}
string Category::getNameCategory(){
    return this->nameCategory;
}