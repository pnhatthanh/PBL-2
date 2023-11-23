#include"MapBook.h"
MapBook::MapBook(){}
MapBook::MapBook(string name, int c){
    this->nameBook=name;
    this->count=c;
}
// void MapBook::increase(int a){
//     this->count=this->count
// }
int& MapBook::getCount(){
    return this->count; 
}
string& MapBook::getBook(){
    return this->nameBook;
}
bool MapBook::operator<(const MapBook& tmp){
    if(this->count<tmp.count){
        return true;
    }
    return false;
}
ostream& operator<<(ostream &o, const MapBook& m){
    o<<m.nameBook<<" "<<m.count<<endl;
    return o;
}