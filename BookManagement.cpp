#include "BookManagement.h"
void BookManagement::addbook(Data &data)
{
    string idBook;
    string nameBook;
    string Category;
    string nameAuthor;
    int publishYear;
    int quantity;
    double price;
    g.downLine(1);
    g.tab(71);
    cout << " THEM SACH " <<endl;
    g.downLine(2);
    g.tab(68);
    cout<<"Thong tin sach moi"<<endl;
    g.downLine(1);
    cin.ignore();
    do{
        bool check=1;
        g.tab(60);
        cout << "Ma sach:        ";
        getline(cin,idBook);
        for(int i=0;i<data.getDataBook().size_list();i++){
            if(idBook==data.getDataBook()[i].getIDBook()){
                check=0;
            }
        }
        if(check==0){
            g.tab(64);
            cout<<"Ma sach da ton tai!"<<endl;
        }
        if(check==1){
            break;
        }
    }while(true);
    g.tab(60);
    cout << "Ten sach:       ";
    getline(cin, nameBook);
    g.tab(60);
    cout << "The loai sach:  "<<endl;
    int i=0;
    for(i;i<data.getDataCategory().size_list();i++){
       g.tab(73); cout<<i<<". "<<data.getDataCategory()[i].getNameCategory()<<endl;
    }
    do{
        g.tab(64);cout<<"Nhap lua chon: ";
        cin>>i;
        if(i>=0&&i<data.getDataCategory().size_list()){
            Category=data.getDataCategory()[i].getIDCategory();
            break;
        }
    }while(true);
    cin.ignore();
    g.tab(60);
    cout << "Ten tac gia:    ";
    getline(cin, nameAuthor);
    do{
        g.tab(60);
        cout << "Nam xuat ban:   ";
        cin >> publishYear;
        if(publishYear<0){
            g.tab(64);
            cout<<"Nam xuat ban khong hop le!"<<endl;
        }
    }while(publishYear<=0);
    do{
        g.tab(60);
        cout << "So luong sach:  ";
        cin >> quantity;
        if(quantity<0){
            g.tab(64);
            cout<<"So luong khong hop le!"<<endl;
        }
    }while(quantity<0);
    do{
        g.tab(60);
        cout << "Gia sach(VND):  ";
        cin >> price;
        if(price<0){
            g.tab(64);
            cout<<"Gia sach khong hop le!"<<endl;
        }
    }while(price<0);
    Book b(idBook, nameBook, Category, nameAuthor, publishYear, quantity, price);
    data.getDataBook().addLast(b);
    g.downLine(1);
    g.tab(55);
    cout << "--------THEM SACH THANH CONG!!!--------" << endl;
}
void BookManagement::deleteBook(Data &data)
{
    List<Book> &book = data.getDataBook();
    g.downLine(1);
    g.tab(71);
    cout << " ----------" << endl;
    g.tab(71);
    cout << "| XOA SACH |" << endl;
    g.tab(71);
    cout << " ----------" << endl;
    g.tab(57);
    cout << "Nhap ten sach ban muon xoa: ";
    cin.ignore(1);
    string nameBook;
    getline(cin, nameBook);
    int index = -1;
    for (int i = 0; i < book.size_list(); i++)
    {
        if (nameBook == book[i].getNameBook())
        {
            index = i;
        }
    }
    if (index < 0)
    {
        g.tab(57);
        cout << "Sach " + nameBook + " khong ton tai!!!" << endl;
        return;
    }
    else
    {
        data.getDataBook().remove(index);
        g.tab(57);
        cout << "Xoa sach thanh cong!" << endl;
    }
}
void BookManagement::showBook(Data &data)
{
    g.tab(72);cout<<"DANH SACH SACH TRONG CUA HANG"<<endl;
    g.downLine(1);
    g.tab(18);cout << "==============================================================================================";
    cout << "===============================================" << endl;
    g.tab(18);cout << "|ID sach |Ten sach                                |The loai";
    cout << "                  |Ten tac gia         |Nam xuat ban  |So luong sach  |Gia sach  |" << endl;
    g.tab(18);cout << "------------------------------------------------------------------------------------";
    cout << "---------------------------------------------------------" << endl;
    List<Book> &book = data.getDataBook();
    List<Category> &category = data.getDataCategory();
    for (int i = 0; i < book.size_list(); i++)
    {

        g.tab(18);cout << "|" << left << setw(8) << book[i].getIDBook() << "|" << left << setw(40) << book[i].getNameBook() << "|";
        for (int j = 0; j < category.size_list(); j++)
        {
            if (book[i].getIDCategory() == category[j].getIDCategory())
            {
                cout << left << setw(26) << category[j].getNameCategory() << "|";
            }
        }
        cout << left << setw(20) << book[i].getNameAuthor() << "|" << left << setw(14) << book[i].getPublishYear() << "|";
        cout << left << setw(15) << book[i].getQuantity() << "|" << left << setw(10) << book[i].getPrice() << "|" << endl;
    }
    g.tab(18);cout << "==============================================================================================";
    cout << "===============================================" << endl;
}
void BookManagement::editPriceBook(Data &data)
{
    g.tab(71);
    cout << " --------------------" << endl;
    g.tab(71);
    cout << "| CHINH SUA GIA SACH |" << endl;
    g.tab(71);
    cout << " --------------------" << endl;
    g.downLine(1);
    g.tab(60);
    cout << "Nhap ma sach: ";
    cin.ignore(1);
    string idBook;
    getline(cin, idBook);
    g.downLine(1);
    int index = -1;
    for (int i = 0; i < data.getDataBook().size_list(); i++)
    {
        if (idBook == data.getDataBook()[i].getIDBook())
        {
            index = i;
            break;
        }
    }
    if (index < 0)
    {
        g.tab(60);
        cout << "ID sach : '" << idBook << "' khong ton tai!!" << endl;
        return;
    }
    g.tab(68);
    cout<<"Thong tin sach "<<endl;
    double new_Price;
    g.tab(60);
    cout << "Ten sach:       " << data.getDataBook()[index].getNameBook() <<endl;
    g.tab(60);
    cout << "Tac gia:        " << data.getDataBook()[index].getNameAuthor() <<endl;
    g.tab(60);
    cout << "Nam xuat ban:   " << data.getDataBook()[index].getPublishYear() <<endl;
    g.tab(60);
    cout << "Gia sach cu:    " << data.getDataBook()[index].getPrice() << "VND" << endl;
    g.tab(60);
    cout << "Nhap gia sach moi(VND): ";
    cin >> new_Price;
    data.getDataBook()[index].setPrice(new_Price);
    g.downLine(1);
    g.tab(55);
    cout << "--------SUA GIA SACH THANH CONG!--------" << endl;
}
void BookManagement::showBookByCategory(Data &data)
{
    g.downLine(1);
    g.tab(71);
    cout << " ------------------------------" << endl;
    g.tab(71);
    cout << "| DANH SACH SACH THEO THE LOAI |" << endl;
    g.tab(71);
    cout << " ------------------------------" << endl;
    g.tab(63);
    cout << "Nhap the loai sach: ";
    cin.ignore(1);
    string nameCategory;
    getline(cin, nameCategory);
    List<Category> &category = data.getDataCategory();
    string idCategory;
    bool check = false;
    for (int i = 0; i < category.size_list(); i++)
    {
        if (category[i].getNameCategory() == nameCategory)
        {
            check = true;
            idCategory = category[i].getIDCategory();
        }
    }
    if (check != true)
    {
        g.tab(57);
        cout << "The loai: " << nameCategory << " khong ton tai!!" << endl;
        return;
    }
    List<Book> &book = data.getDataBook();
    g.tab(43);
    cout << "=======================================================================================" << endl;
    g.tab(43);
    cout << "|ID sach     |Ten sach                                |Ma the loai    |Tac gia        |" << endl;
    for (int i = 0; i < book.size_list(); i++)
    {
        if (book[i].getIDCategory() == idCategory)
        {
            check = true;
            g.tab(43);
            cout << "|" << left << setw(12) << book[i].getIDBook() << "|" << left << setw(40) << book[i].getNameBook();
            cout << "|" << left << setw(15) << book[i].getIDCategory() << "|" << left << setw(15) << book[i].getNameAuthor() << "|" << endl;
        }
    }
    g.tab(43);
    cout << "=======================================================================================" << endl;
}
void BookManagement::searchByAuthor(Data &data)
{
    g.downLine(1);
    g.tab(71);
    cout << " -----------------------------" << endl;
    g.tab(71);
    cout << "| DANH SACH SACH THEO TAC GIA |" << endl;
    g.tab(71);
    cout << " -----------------------------" << endl;
    g.tab(63);
    cout << "Nhap ten tac gia: ";
    cin.ignore(1);
    string nameAuthor;
    getline(cin, nameAuthor);
    List<Book> &book = data.getDataBook();
    bool check = false;
    for (int i = 0; i < book.size_list(); i++)
    {
        if (book[i].getNameAuthor() == nameAuthor)
        {
            check = true;
        }
    }
    if (check != true)
    {
        g.tab(57);
        cout << "Tac gia " << nameAuthor << " khong ton tai!" << endl;
    }
    else
    {
        g.tab(40);
        cout << "===========================================================================================" << endl;
        g.tab(40);
        cout << "|ID sach     |Ten sach                                |Ma the loai   |Tac gia             |" << endl;
        for (int i = 0; i < book.size_list(); i++)
        {
            if (book[i].getNameAuthor() == nameAuthor)
            {
                g.tab(40);
                cout << "|" << left << setw(12) << book[i].getIDBook() << "|" << left << setw(40) << book[i].getNameBook();
                cout << "|" << left << setw(14) << book[i].getIDCategory() << "|" << left << setw(20) << book[i].getNameAuthor() << "|" << endl;
            }
        }
        g.tab(40);
        cout << "===========================================================================================" << endl;
    }
}
