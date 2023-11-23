#include"Data.h"
void Data::readFileCustomer(){
    ifstream f;
    f.open("Customer.txt",ios::in);
    while(!f.eof()){
        string idCustomer;
        string fullName;
        string address;
        string phoneNumber;
        string email;
        getline(f,idCustomer,',');
        getline(f,fullName,',');
        getline(f,address,',');
        getline(f,phoneNumber,',');
        getline(f,email);
        Customer c(idCustomer,fullName,address,phoneNumber,email);
        this->dataCustomer.addLast(c);
    }
    f.close();
}
List<Customer>& Data::getDataCustomer(){
    return this->dataCustomer;
}

void Data::readFileBook(){
    ifstream f;
    f.open("Book.txt",ios::in);
    while(!f.eof()){
        string idBook;
        string nameBook;
        string idCategory;
        string idAuthor;
        int publishYear;
        int quanity;
        double price;
        getline(f,idBook,',');
        getline(f,nameBook,',');
        getline(f,idCategory,',');
        getline(f,idAuthor,',');
        f>>publishYear;
        f.ignore(1);
        f>>quanity;
        f.ignore(1);
        f>>price;
        f.ignore(1);
        Book b(idBook,nameBook,idCategory,idAuthor,publishYear,quanity,price);
        this->dataBook.addLast(b);
    }
    f.close();
}
List<Book>& Data::getDataBook(){
    return this->dataBook;
}

void Data::readFileCategory(){
    ifstream f;
    f.open("Category.txt",ios::in);
    while(!f.eof()){
        string idCategory;
        string nameCategory;
        getline(f,idCategory,',');
        getline(f,nameCategory);
        Category c(idCategory,nameCategory);
        this->dataCategory.addLast(c);
    }
}
List<Category>& Data::getDataCategory(){
    return this->dataCategory;
}

void Data::readFileOrder(){
    ifstream f;
    f.open("Order.txt",ios::in);
    while(!f.eof()){
        string idOrder;
        string idCustomer;
        string date;
        string idDiscount;
        double totalPrice;
        getline(f,idOrder,',');
        getline(f,idCustomer,',');
        getline(f,date,',');
        getline(f,idDiscount,',');
        f>>totalPrice;
        f.ignore(1);
        int day=(date[0]-'0')*10+(date[1]-'0');
        int month=(date[3]-'0')*10+(date[4]-'0');
        int year=(date[6]-'0')*1000+(date[7]-'0')*100+(date[8]-'0')*10+(date[9]-'0');
        Date dd(day,month,year);
        Order od(idOrder,idCustomer,dd,idDiscount,totalPrice);
        this->dataOrder.addLast(od);
    }
    f.close();
}
List<Order>& Data::getDataOrder(){
    return this->dataOrder;
}

void Data::readFileDiscount(){
    ifstream f;
    f.open("Discount.txt",ios::in);
    while(!f.eof()){
        string idDiscount;
        double discount;
        double level;
        int quantity;
        string firstDate;
        string lastDate;
        string status;
        getline(f,idDiscount,',');
        f>>discount;
        f.ignore(1);
        f>>level;
        f.ignore(1);
        f>>quantity;
        f.ignore(1);
        getline(f,firstDate,',');
        getline(f,lastDate,',');
        getline(f,status);
        int day1=(firstDate[0]-'0')*10+(firstDate[1]-'0');
        int month1=(firstDate[3]-'0')*10+(firstDate[4]-'0');
        int year1=(firstDate[6]-'0')*1000+(firstDate[7]-'0')*100+(firstDate[8]-'0')*10+(firstDate[9]-'0');
        Date dd1(day1,month1,year1);
        int day2=(lastDate[0]-'0')*10+(lastDate[1]-'0');
        int month2=(lastDate[3]-'0')*10+(lastDate[4]-'0');
        int year2=(lastDate[6]-'0')*1000+(lastDate[7]-'0')*100+(lastDate[8]-'0')*10+(lastDate[9]-'0');
        Date dd2(day2,month2,year2);
        Discount dis(idDiscount,discount,level,quantity,dd1,dd2,status);
        this->dataDiscount.addLast(dis);
    }
}
List<Discount>& Data::getDataDiscount(){
    return this->dataDiscount;
}

void Data::readFileDetailOrder(){
    ifstream f;
    f.open("DetailOrder.txt",ios::in);
    while(!f.eof()){
        string idOrder;
        string nameBook;
        int quantityBook;
        getline(f,idOrder,',');
        getline(f,nameBook,',');
        f>>quantityBook;
        f.ignore(1);
        DetailOrder detail(idOrder,nameBook,quantityBook);
        this->dataDetailOrder.addLast(detail);
    }
    f.close();
}
List<DetailOrder>& Data::getDataDetailOrder(){
    return this->dataDetailOrder;
}
void Data::decreaseQuantityOfBook(string idBook, int quantity){
    for(int i=0;i<this->dataBook.size_list();i++){
        if(this->dataBook[i].getIDBook()==idBook){
            this->dataBook[i].decreaseQuantity(quantity);
            break;
        }
    }
}
void Data::updateDiscount(int index, Discount dis){
    this->dataDiscount[index]=dis;
}
