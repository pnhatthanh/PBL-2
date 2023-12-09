#include "BookManagement.h"
void BookManagement::addbook(Data &data)
{
    string nameBook;
    string Category;
    string nameAuthor;
    int publishYear;
    int quantity;
    double price;
    g.tab(65);cout<<"---------------------------------------------" << endl;
    g.tab(65);cout<<"|                 THEM SACH                 |" <<endl;
    g.tab(65);cout<<"---------------------------------------------" << endl;
    g.downLine(2);
    g.tab(79);
    cout<<"Thong tin sach moi"<<endl;
    cin.ignore();
    int index=data.getDataBook().size_list()-1;
    string idBook=data.getDataBook()[index].getIDBook();
    index=(idBook[1]-'0')*100+(idBook[2]-'0')*10+(idBook[3]-'0')+1;
    idBook="S";
    if(index<10){
    	idBook+="00"+to_string(index);
	}else if(index>=10&&index<=99){
		idBook+="0"+to_string(index);
	}else{
		idBook+=to_string(index);
	}
    g.tab(73);
    cout << "Ma sach:        "<<idBook<<endl;
    g.tab(73);
    cout << "Ten sach:       ";
    getline(cin, nameBook);
    g.tab(73);
    cout << "The loai sach:  "<<endl;
    int i=0;
    for(i;i<data.getDataCategory().size_list();i++){
       g.tab(86); cout<<i<<". "<<data.getDataCategory()[i].getNameCategory()<<endl;
    }
    do{
        g.tab(77);cout<<"Nhap lua chon: ";
        cin>>i;
        if(i>=0&&i<data.getDataCategory().size_list()){
            Category=data.getDataCategory()[i].getIDCategory();
            break;
        }
    }while(true);
    cin.ignore();
    g.tab(73);
    cout << "Ten tac gia:    ";
    getline(cin, nameAuthor);
    do{
        g.tab(73);
        cout << "Nam xuat ban:   ";
        cin >> publishYear;
        if(publishYear<0){
            g.tab(77);
            cout<<"Nam xuat ban khong hop le!"<<endl;
        }
    }while(publishYear<=0);
    do{
        g.tab(73);
        cout << "So luong sach:  ";
        cin >> quantity;
        if(quantity<0){
            g.tab(77);
            cout<<"So luong khong hop le!"<<endl;
        }
    }while(quantity<0);
    do{
        g.tab(73);
        cout << "Gia sach(VND):  ";
        cin >> price;
        if(price<0){
            g.tab(77);
            cout<<"Gia sach khong hop le!"<<endl;
        }
    }while(price<0);
    int flag=1;
    Book b(idBook, nameBook, Category, nameAuthor, publishYear, quantity, price,flag);
    data.getDataBook().addLast(b);
    data.writeFileBook(data.getDataBook());
    g.downLine(1);
    g.tab(64);cout << "--------------THEM SACH THANH CONG!--------------" << endl;
}
void BookManagement::deleteBook(Data &data)
{
    List<Book> &book = data.getDataBook();
    g.tab(65);cout<<"---------------------------------------------" << endl;
    g.tab(65);cout<<"|                 XOA SACH                  |" << endl;
    g.tab(65);cout<<"---------------------------------------------" << endl;
    g.downLine(1);
    g.tab(67);
    cout << "Nhap ma sach ban muon xoa: ";
    cin.ignore(1);
    string idBook;
    getline(cin, idBook);
    g.downLine(2);
    int index = -1;
    for (int i = 0; i < book.size_list(); i++)
    {
        if (idBook == book[i].getIDBook()&&book[i].getFlag()==1)
        {
            index = i;
        }
    }
    if (index < 0)
    {
        g.tab(73);
        cout << "ID sach '" + idBook + "' khong ton tai!!!" << endl;
        return;
    }
    else
    {
        g.tab(80);
        cout<<"THONG TIN SACH"<<endl;
        g.tab(72);
        cout << "Ten sach:       " << data.getDataBook()[index].getNameBook() <<endl;
        g.tab(72);
        cout << "Tac gia:        " << data.getDataBook()[index].getNameAuthor() <<endl;
        g.tab(72);
        cout << "Nam xuat ban:   " << data.getDataBook()[index].getPublishYear() <<endl;
        g.tab(65);cout<<"Ban co chac chan muon xoa sach nay khong (y/n)? "<<endl;
        g.tab(84);cout<<"1. Yes"<<endl;
        g.tab(84);cout<<"2. No"<<endl;
        int n;
        g.tab(80);cout<<"Nhap lua chon: ";cin>>n;
        if(n==1){
            data.getDataBook()[index].setFlag(0);
            data.writeFileBook(data.getDataBook());
            g.tab(65);cout << "--------------XOA SACH THANH CONG!--------------" << endl;
        }
    }
    cin.ignore();
}
void BookManagement::showBook(Data &data)
{
    g.tab(65);cout<<"---------------------------------------------" << endl;
    g.tab(65);cout<<"|       DANH SACH SACH TRONG CUA HANG       |" <<endl;
    g.tab(65);cout<<"---------------------------------------------" << endl;
    g.downLine(2);
    g.tab(25);cout << "==============================================================================================";
    cout << "===============================" << endl;
    g.tab(25);cout << "|ID sach |Ten sach                                |The loai";
    cout << "                  |Ten tac gia         |Nam xuat ban  |Gia sach  |" << endl;
    g.tab(25);cout << "------------------------------------------------------------------------------------";
    cout << "-----------------------------------------" << endl;
    List<Book> &book = data.getDataBook();
    List<Category> &category = data.getDataCategory();
    for (int i = 0; i < book.size_list(); i++)
    {
        if(book[i].getFlag()==1){
            g.tab(25);cout << "|" << left << setw(8) << book[i].getIDBook() << "|" << left << setw(40) << book[i].getNameBook() << "|";
            for (int j = 0; j < category.size_list(); j++)
            {
                if (book[i].getIDCategory() == category[j].getIDCategory())
                {   
                    cout << left << setw(26) << category[j].getNameCategory() << "|";
                }
            }
            cout << left << setw(20) << book[i].getNameAuthor() << "|" << left << setw(14) << book[i].getPublishYear() << "|";
            cout << left << setw(10) << book[i].getPrice() << "|" << endl;
        }
    }
    g.tab(25);cout << "==============================================================================================";
    cout << "===============================" << endl;
}
void BookManagement::editPriceBook(Data &data)
{
    g.tab(65);cout<<"---------------------------------------------" << endl;
    g.tab(65);cout<<"|             CHINH SUA GIA SACH            |" << endl;
    g.tab(65);cout<<"---------------------------------------------" << endl;
    g.downLine(1);
    g.tab(71);
    cout << "Nhap ma sach: ";
    cin.ignore(1);
    string idBook;
    getline(cin, idBook);
    g.downLine(1);
    int index = -1;
    for (int i = 0; i < data.getDataBook().size_list(); i++)
    {
        if (idBook == data.getDataBook()[i].getIDBook()&&data.getDataBook()[i].getFlag()==1)
        {
            index = i;
            break;
        }
    }
    if (index < 0)
    {
        g.tab(68);
        cout << "ID sach : '" << idBook << "' khong ton tai!!" << endl;
        return;
    }
    g.tab(81);
    cout<<"THONG TIN SACH"<<endl;
    double new_Price;
    g.tab(73);
    cout << "TEN SACH:       " << data.getDataBook()[index].getNameBook() <<endl;
    g.tab(73);
    cout << "TAC GIA:        " << data.getDataBook()[index].getNameAuthor() <<endl;
    g.tab(73);
    cout << "NAM XUAT BAN:   " << data.getDataBook()[index].getPublishYear() <<endl;
    g.tab(73);
    cout << "GIA SACH CU:    " << data.getDataBook()[index].getPrice() << " VND" << endl;
    g.tab(73);
    cout << "Nhap gia sach moi(VND):   ";
    cin >> new_Price;
    data.getDataBook()[index].setPrice(new_Price);
    data.writeFileBook(data.getDataBook());
    g.downLine(1);
    g.tab(62);cout << "--------------SUA GIA SACH THANH CONG!--------------" << endl;
    cin.ignore();
}
void BookManagement::showBookByCategory(Data &data)
{
    g.tab(65);cout<<"---------------------------------------------" << endl;
    g.tab(65);cout<<"|        DANH SACH SACH THEO THE LOAI       |" << endl;
    g.tab(65);cout<<"---------------------------------------------" << endl;
    g.downLine(1);
    string idCategory;
    g.tab(72);
    cout << "The loai sach:  "<<endl;
    int i=0;
    for(i;i<data.getDataCategory().size_list();i++){
       g.tab(86); cout<<i<<". "<<data.getDataCategory()[i].getNameCategory()<<endl;
    }
    do{
        g.tab(77);cout<<"Nhap lua chon: ";
        cin>>i;
        if(i>=0&&i<data.getDataCategory().size_list()){
            idCategory=data.getDataCategory()[i].getIDCategory();
            break;
        }
    }while(true);
    cin.ignore(1);
    g.downLine(1);
    List<Book> &book = data.getDataBook();
    g.tab(74);cout<<"THE LOAI: '"<<data.getDataCategory()[i].getNameCategory()<<"'"<<endl;
    g.tab(45);
    cout << "=======================================================================================" << endl;
    g.tab(45);
    cout << "|ID sach     |Ten sach                                |Ma the loai    |Tac gia        |" << endl;
    g.tab(45);
    cout << "---------------------------------------------------------------------------------------" <<endl;
    for (int i = 0; i < book.size_list(); i++)
    {
        if (book[i].getIDCategory() == idCategory&&book[i].getFlag()==1)
        {
            g.tab(45);
            cout << "|" << left << setw(12) << book[i].getIDBook() << "|" << left << setw(40) << book[i].getNameBook();
            cout << "|" << left << setw(15) << book[i].getIDCategory() << "|" << left << setw(15) << book[i].getNameAuthor() << "|" << endl;
        }
    }
    g.tab(45);
    cout << "=======================================================================================" << endl;
}
void BookManagement::searchByAuthor(Data &data)
{
    g.tab(65);cout<<"---------------------------------------------" << endl;
    g.tab(65);cout<<"|         DANH SACH SACH THEO TAC GIA       |" << endl;
    g.tab(65);cout<<"---------------------------------------------" << endl;
    g.downLine(1);
    g.tab(63);
    cout << "Nhap ten tac gia: ";
    cin.ignore(1);
    string nameAuthor;
    getline(cin, nameAuthor);
    g.downLine(2);
    List<Book> &book = data.getDataBook();
    bool check = false;
    for (int i = 0; i < book.size_list(); i++)
    {
        if (book[i].getNameAuthor() == nameAuthor&&book[i].getFlag()==1)
        {
            check = true;
        }
    }
    if (check != true)
    {
        g.tab(68);
        cout << "Tac gia: " << nameAuthor << " khong ton tai!" << endl;
    }
    else
    {
        g.tab(40);
        cout << "===========================================================================================" << endl;
        g.tab(40);
        cout << "|ID sach     |Ten sach                                |Ma the loai   |Tac gia             |" << endl;
        for (int i = 0; i < book.size_list(); i++)
        {
            if (book[i].getNameAuthor() == nameAuthor&&book[i].getFlag()==1)
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
