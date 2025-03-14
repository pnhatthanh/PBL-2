#include "Menu.h"


//Chinh sua menu nhan chu la nhap lai

void Menu::mainMenu(Data &data)
{
    int choice;
    do
    {
        system("cls");
        data.Logo();
        g.tab(77); cout<< "QUAN LI CUA HANG BAN SACH" << endl;
        g.downLine(1);
        g.tab(57);cout << "=============================================================" << endl;
        g.tab(57);cout << "|                  1. Quan li khach hang                    |" << endl;
        g.tab(57);cout << "|                  2. Quan li sach                          |" << endl;
        g.tab(57);cout << "|                  3. Quan li hoa don                       |" << endl;
        g.tab(57);cout << "|                  4. Quan li giam gia                      |" << endl;
        g.tab(57);cout << "|                  5. Thong ke                              |" << endl;
        g.tab(57);cout << "|                  0. Nhap '0' de ket thuc                  |" << endl;
        g.tab(57);cout << "=============================================================" << endl;
        g.downLine(1);
        g.tab(76);cout << "--->Nhap lua chon: ";
        cin >> choice;
        switch (choice)
        {
            case 1:
                this->customerMenu(data);
                break;
            case 2:
                this->bookMenu(data);
                break;
            case 3:
                this->orderMenu(data);
                break;
            case 4:
                this->discountMenu(data);
                break;
            case 5:
                this->statisticsMenu(data);
                break;
        }
    } while (choice != 0);
}
void Menu::customerMenu(Data &data)
{
    CustomerManagement customer;   
    int choice1;
    do
    {
        system("cls");
        g.tab(80);cout<< "QUAN LI KHACH HANG" << endl;
        g.downLine(1);
        g.tab(57);cout << "=============================================================" << endl;
        g.tab(57);cout << "|                1. Tim kiem khach hang                     |" << endl;
        g.tab(57);cout << "|                2. Xoa khach hang                          |" << endl;
        g.tab(57);cout << "|                3. Hien thi danh sach khach hang           |" << endl;
        g.tab(57);cout << "|                0. Nhap '0' de quay tro lai                |" << endl;
        g.tab(57);cout << "=============================================================" << endl;
        g.downLine(1);
        g.tab(76);cout << "--->Nhap lua chon: ";
        cin >> choice1;
        switch (choice1)
        {
            case 1:
                system("cls");
                customer.searchCustomer(data);
                g.downLine(1);
                g.tab(70); cout<<"Nhan 'Enter' de quay tro lai!!!";
                cin.ignore();
                break;
            case 2:
                system("cls");
                customer.deleteCustomer(data);
                g.downLine(1);
                g.tab(71); cout<<"Nhan 'Enter' de quay tro lai!!!";
                cin.ignore();
                break;
            case 3:
                cin.ignore();
                system("cls");
                customer.showCustomer(data);
                g.downLine(1);
                g.tab(75); cout<<"Nhan 'Enter' de quay tro lai!!!";
                cin.ignore();
                break;
        }
    } while (choice1 != 0);
}
void Menu::bookMenu(Data &data)
{
    BookManagement book;
    int choice;
    do{
        system("cls");
        g.tab(82);cout<< "QUAN LI SACH" << endl;
        g.downLine(1);
        g.tab(57);cout << "=============================================================" << endl;
        g.tab(57);cout << "|                 1. Them sach                               |" << endl;
        g.tab(57);cout << "|                 2. Xoa sach                                |" << endl;
        g.tab(57);cout << "|                 3. Cap nhat gia sach                       |" << endl;
        g.tab(57);cout << "|                 4. Hien thi danh sach sach                 |" << endl;
        g.tab(57);cout << "|                 5. Hien thi danh sach theo the loai        |" << endl;
        g.tab(57);cout << "|                 6. Hien thi danh sach theo tac gia         |" << endl;
        g.tab(57);cout << "|                 0. Nhap '0' de quay tro lai                |" << endl;
        g.tab(57);cout << "=============================================================" << endl;
        g.downLine(1);
        g.tab(76);cout << "--->Nhap lua chon: ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            system("cls");
            book.addbook(data);
            cin.ignore(1);
            g.downLine(1);
            g.tab(72); cout<<"Nhan 'Enter' de quay tro lai!!!";
            cin.ignore(1);
            break;
        case 2:
            system("cls");
            book.deleteBook(data);
            g.downLine(1);
            g.tab(72); cout<<"Nhan 'Enter' de quay tro lai!!!";
            cin.ignore(1);
            break;
        case 3:
            system("cls");
            book.editPriceBook(data);
            g.downLine(1);
            g.tab(72); cout<<"Nhan 'Enter' de quay tro lai!!!";
            cin.ignore();
            break;
        case 4:
            system("cls");
            book.showBook(data);
            cin.ignore();
            g.downLine(1);
            g.tab(72); cout<<"Nhan 'Enter' de quay tro lai!!!";
            cin.ignore(1);
            break;
        case 5:
            system("cls");
            book.showBookByCategory(data);
            g.downLine(1);
            g.tab(72); cout<<"Nhan 'Enter' de quay tro lai!!!";
            cin.ignore(1);
            break;
        case 6:
            system("cls");
            book.searchByAuthor(data);
            g.downLine(1);
            g.tab(72); cout<<"Nhan 'Enter' de quay tro lai!!!";
            cin.ignore(1);
            break;
        }
    }while(choice!=0);
}
void Menu::orderMenu(Data &data)
{
    OrderManagement order;
    
    int choice;
    do
    {
        system("cls");
        g.tab(79);cout<< "QUAN LI HOA DON" << endl;
        g.downLine(1);
        g.tab(57);cout << "=============================================================" << endl;
        g.tab(57);cout << "|               1. Tao don hang moi                         |" << endl;
        g.tab(57);cout << "|               2. Danh sach hoa don cua khach hang         |" << endl;
        g.tab(57);cout << "|               3. Xoa hoa don                              |" << endl;
        g.tab(57);cout << "|               0. Nhap '0' de quay tro lai                 |" << endl;
        g.tab(57);cout << "=============================================================" << endl;
        g.downLine(1);
        g.tab(76);cout << "--->Nhap lua chon: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            system("cls");
            order.creatOrder(data);
            g.downLine(1);
            g.tab(67); cout<<"Nhan 'Enter' de quay tro lai!!!";
            cin.ignore(1);
            break;
        case 2:
            system("cls");
            order.listOrder(data);
            g.downLine(1);
            g.tab(67); cout<<"Nhan 'Enter' de quay tro lai!!!";
            cin.ignore(1);
            break;
        case 3:
            system("cls");
            order.deleteOrder(data);
            g.downLine(1);
            g.tab(67); cout<<"Nhan 'Enter' de quay tro lai!!!";
            cin.ignore(1);
            break;
        }
    } while (choice != 0);
}
void Menu::statisticsMenu(Data &data)
{
    Statistics statistics;
    int choice;
    do
    {
        system("cls");
        g.tab(83);cout<< "THONG KE" << endl;
        g.downLine(1);
        g.tab(57);cout << "=============================================================" << endl;
        g.tab(57);cout << "|               1. Thong ke so luong ton kho                |" << endl;
        g.tab(57);cout << "|               2. Thong ke sach ban chay nhat              |" << endl;
        g.tab(57);cout << "|               3. Thong ke doanh thu cua cua hang          |" << endl;
        g.tab(57);cout << "|               0. Nhap '0' de quay tro lai                 |" << endl;
        g.tab(57);cout << "=============================================================" << endl;
        g.downLine(1);
        g.tab(76);cout << "--->Nhap lua chon: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            system("cls");
            statistics.inventoryNumber(data);
            g.downLine(1);
            cin.ignore();
            g.tab(72); cout<<"Nhan 'Enter' de quay tro lai!!!";
            cin.ignore(1);
            break;
        case 2:
            system("cls");
            statistics.listBestSeller(data);
            g.downLine(1);
            cin.ignore();
            g.tab(72); cout<<"Nhan 'Enter' de quay tro lai!!!";
            cin.ignore(1);
            break;
        case 3:
            system("cls");
            statistics.sales(data);
            g.downLine(1);
            g.tab(72); cout<<"Nhan 'Enter' de quay tro lai!!!";
            cin.ignore(1);
            break;
        }
    } while (choice != 0);
}
void Menu::discountMenu(Data &data)
{
    DiscountManagement discount;
    int choice;
    do
    {
        system("cls");
        g.tab(77);cout<<"QUAN LI MA GIAM GIA" << endl;
        g.downLine(1);
        g.tab(57);cout << "=============================================================" << endl;
        g.tab(57);cout << "|           1. Them moi ma giam gia                         |" << endl;
        g.tab(57);cout << "|           2. Xoa ma giam gia                              |" << endl;
        g.tab(57);cout << "|           3. Hien thi thong tin tat ca ma giam gia        |" << endl;
        g.tab(57);cout << "|           4. Chinh sua ma giam gia                        |" << endl;
        g.tab(57);cout << "|           0. Nhap '0' de quay tro lai                     |" << endl;
        g.tab(57);cout << "=============================================================" << endl;
        g.downLine(1);
        g.tab(76);cout << "--->Nhap lua chon: ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            system("cls");
            discount.addDisscount(data);
            g.downLine(1);
            g.tab(72); cout<<"Nhan 'Enter' de quay tro lai!!!";
            cin.ignore(1);
            break;
        case 2:
            system("cls");
            discount.deleteDiscount(data);
            g.downLine(1);
            g.tab(72); cout<<"Nhan 'Enter' de quay tro lai!!!";
            cin.ignore(1);
            break;
        case 3:
            system("cls");
            discount.showDiscount(data);
            g.downLine(1);
            cin.ignore();
            g.tab(72); cout<<"Nhan 'Enter' de quay tro lai!!!";
            cin.ignore(1);
            break;
        case 4:
            system("cls");
            discount.editDiscount(data);
            g.downLine(1);
            g.tab(72); cout<<"Nhan 'Enter' de quay tro lai!!!";
            cin.ignore(1);
            break;
        }
    } while (choice != 0);
}