#include "OrderManagement.h"
void OrderManagement::creatOrder(Data &data)
{
    cout << "TAO DON HANG" << endl;
    cout << "THONG TIN DON HANG" << endl;
    cout << "Ma don hang: ";
    string idOrder;
    cin>>idOrder;
    cout << "Ma khach hang: ";
    string idCustomer;
    cin>>idCustomer;
    cout << "Ho ten khach hang: ";
    cin.ignore(1);
    string name;
    getline(cin, name);
    cout << "Dia chi: ";
    string address;
    getline(cin, address);
    cout << "So dien thoai: ";
    string phone;
    getline(cin, phone);
    cout << "Email: ";
    string email;
    getline(cin,email);
    cout<<idCustomer<<" "<<name<<" "<<address<<" "<<phone<<" "<<email<<endl;
    Customer cs(idCustomer, name, address, phone, email);
    List<Customer> &customer=data.getDataCustomer();
    bool check=false;
    for(int i=0;i<customer.size_list();i++){
        if(customer[i].getFullName()==cs.getFullName()&&customer[i].getPhoneNumber()==cs.getPhoneNumber()){
            check=true;            
        }
    }
    if(check==false){
        data.getDataCustomer().addLast(cs);
    } 
    cout << "DON HANG" << endl;
    double totalPrice = 0;
    List<Book> &lb = data.getDataBook();
    while (true)
    {
        cout << "Ten sach: ";
        string nameBook;
        getline(cin, nameBook);
        int index = -1;
        for (int i = 0; i < lb.size_list(); i++)
        {
            if (nameBook == lb[i].getNameBook())
            {
                index = i;
            }
        }
        if (index < 0)
        {
            cout << "Sach khong ton tai!!!" << endl;
            continue;
        }
        cout << "So luong";
        int quantity;
        cin >> quantity;
        if (quantity > lb[index].getQuantity())
        {
            cout << "So luong ton kho khong du!!!";
            continue;
        }
        string idBook = lb[index].getIDBook();
        data.decreaseQuantityOfBook(idBook, quantity);
        DetailOrder detailOrder(idOrder, nameBook, quantity);
        data.getDataDetailOrder().addLast(detailOrder);
        cout << "Them sach thanh cong!" << endl;
        totalPrice += lb[index].getPrice() * quantity;
        int choice;
        cout << "Nhap '1' de tiep tuc them sach- Nhan '0' de dung: ";
        cin >> choice;
        if (choice == 0)
            break;
    }
    cout << "Thoi gian khoi tao don hang " << endl;
    Date d;
    d.setDate();
    while (true)
    {
        cout<<"Nhap ma giam gia: ";
        string idDiscount;
        cin>>idDiscount;
        if (idDiscount=="0")
        {
            idDiscount = "null";
            Order od(idOrder, idCustomer, d, idDiscount, totalPrice);
            data.getDataOrder().addLast(od);
            cout << "TAO DON HANG THANH CONG!!!" << endl;
            break;
        }
        else
        {
            int index = -1;
            List<Discount> &ld = data.getDataDiscount();
            for (int i = 0; i < ld.size_list(); i++)
            {
                string tmp=ld[i].getIDDiscount();
                if (idDiscount == tmp)
                {
                    index = i;
                }
            }
            if (index < 0)
            {
                cout << "Ma giam gia khong ton tai!" << endl;
            }else{
                Date firstDate = ld[index].getFirstDate();
                Date lastDate = ld[index].getLastDate();
                if (d >= firstDate && d <= lastDate)
                {
                    double minimum = ld[index].getLevel();
                    if (totalPrice >= minimum)
                    {
                        double dis = ld[index].getDiscount();
                        totalPrice = totalPrice - dis;
                        Order od(idOrder, idCustomer, d, idDiscount, totalPrice);
                        data.getDataOrder().addLast(od);
                        cout << "TAO DON HANG THANH CONG!!!" << endl;
                        break;
                    }
                    else
                    {
                        cout << "Ma giam gia khong hop le!!!" << endl;
                    }
                }
                else
                {
                    cout << "Ma giam gia het han!!!" << endl;
                }
            }
        }
    }
}
void OrderManagement::showOrder(Data &data)
{
    g.tab(71); cout << "HOA DON KHACH HANG" << endl;
    g.tab(57); cout << "Nhap ho ten khach hang: ";
    cin.ignore();
    string name;
    getline(cin, name);
    g.downLine(1);
    int index = -1;
    List<Customer>& customer = data.getDataCustomer();
    for (int i = 0; i < customer.size_list(); i++)
    {
        if (name == customer[i].getFullName())
        {
            index = i;
        }
    }
    if (index < 0)
    {
        g.tab(64);cout << "Khach hang khong ton tai" << endl;
        return;
    }
    string id = customer[index].getIDCustomer();
    int index2 = -1;
    List<Order>& order = data.getDataOrder();
    for (int i = 0; i < order.size_list(); i++)
    {
        if (id == order[i].getIDCustomer())
        {
            index2 = i;
        }
    }
    if (index2 < 0)
    {
        g.tab(64);cout << "Don hang cua khac hang: " << customer[index].getFullName() << " khong ton tai!" << endl;
        return;
    }
    g.tab(68);cout << "Thong tin khach hang"<<endl; g.downLine(1);
    g.tab(60);cout << "Ho ten khach hang:   " << customer[index].getFullName() << endl;
    g.tab(60);cout << "Dia chi:             " << customer[index].getAddress() << endl;
    g.tab(60);cout << "So dien thoai:       " << customer[index].getPhoneNumber() << endl;
    g.downLine(1);
    g.tab(68);cout << "Thong tin don hang" << endl;
    g.tab(45);cout << "=================================================================" << endl;
    g.tab(45);cout << "|Ten sach                           |Don gia(VND)   |So luong   |" << endl;
    g.tab(45);cout << "-----------------------------------------------------------------" << endl;
    List<DetailOrder>& detail=data.getDataDetailOrder();
    List<Book>& book=data.getDataBook();
    for(int i=0;i<detail.size_list();i++){
        if(order[index2].getIDOrder()==detail[i].getIDOrder()){
            g.tab(45);cout<<"|"<<left<<setw(35)<<detail[i].getNameBook();
            for(int j=0;j<book.size_list();j++){
                if(detail[i].getNameBook()==book[j].getNameBook()){
                    cout<<"|"<<left<<setw(15)<<book[j].getPrice();
                }
            }
            cout<<"|"<<setw(11)<<detail[i].getQuantityBook()<<"|"<<endl;
        }
    }
    g.tab(45);cout << "=================================================================" << endl;
    for(int i=0;i<data.getDataDiscount().size_list();i++){
        if(data.getDataDiscount()[i].getIDDiscount()==order[index2].getIDDiscount()){
            g.tab(81);cout<<"Giam gia:  "<<data.getDataDiscount()[i].getDiscount()<<"VND"<<endl;
            break;
        }
    }
    g.tab(81);cout << "Tong tien: " << order[index2].getTotalPrice() << "VND" << endl;
}