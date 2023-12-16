#include"MapBook.h"
MapBook::MapBook(){}
MapBook::MapBook(string id, int c){
    this->idBook=id;
    this->count=c;
}
// void MapBook::increase(int a){
//     this->count=this->count
// }
void MapBook::setCount(int count){
    this->count=count;
}
int MapBook::getCount(){
    return this->count; 
}
string MapBook::getIDBook(){
    return this->idBook;
}
bool MapBook::operator<(const MapBook& tmp){
    if(this->count<tmp.count){
        return true;
    }
    return false;
}
ostream& operator<<(ostream &o, const MapBook& m){
    o<<m.idBook<<" "<<m.count<<endl;
    return o;
}