#include "OrderManagement.h"
void OrderManagement::creatOrder(Data &data)
{
    g.tab(65);cout<<"---------------------------------------------" << endl;
    g.tab(65);cout<<"|               TAO DON HANG                |" << endl;
    g.tab(65);cout<<"---------------------------------------------" << endl;
    g.downLine(1);
    g.tab(78);cout << "THONG TIN KHACH HANG" << endl;
    cin.ignore();
    string idCustomer;
    g.tab(70);cout << "Ma khach hang:      ";
    getline(cin,idCustomer);
    int check=-1;
    for(int i=0;i<data.getDataCustomer().size_list();i++){
        if(idCustomer==data.getDataCustomer()[i].getIDCustomer()){
            check=i;
        }
    }
    if(check>=0){
        g.tab(70);cout << "Ho ten khach hang:  "<<data.getDataCustomer()[check].getFullName()<<endl;
        g.tab(70);cout << "Dia chi:            "<<data.getDataCustomer()[check].getAddress()<<endl;
        g.tab(70);cout << "So dien thoai:      "<<data.getDataCustomer()[check].getPhoneNumber()<<endl;
        g.tab(70);cout << "Email:              "<<data.getDataCustomer()[check].getEmail()<<endl;
    }else{
        g.tab(70);cout << "Ho ten khach hang:  ";
        string name;
        getline(cin, name);
        g.tab(70);cout << "Dia chi:            ";
        string address;
        getline(cin, address);
        g.tab(70);cout << "So dien thoai:      ";
        string phone;
        getline(cin, phone);
        g.tab(70);cout << "Email:              ";
        string email;
        getline(cin,email);
        Customer cs(idCustomer, name, address, phone, email);
        data.getDataCustomer().addLast(cs);
        data.writeFileCustomer(data.getDataCustomer());
    }
    g.downLine(1);
    g.tab(78);cout << "THONG TIN DON HANG" << endl;
    int index=data.getDataOrder().size_list()-1;
    string idOrder=data.getDataOrder()[index].getIDOrder();
    index=(idOrder[2]-'0')*100+(idOrder[3]-'0')*10+(idOrder[4]-'0')+1;
    idOrder="DH";
    if(index<10){
    	idOrder+="00"+to_string(index);
	}else if(index>=10&&index<=99){
		idOrder+="0"+to_string(index);
	}else{
		idOrder+=to_string(index);
	}
    g.tab(70);cout << "Ma don hang:   "<<idOrder<<endl;
    double totalPrice = 0;
    List<Book> &lb = data.getDataBook();
    while (true)
    {
        g.tab(70);cout << "Ten sach:      ";
        string nameBook;
        getline(cin, nameBook);
        int index = -1;
        for (int i = 0; i < lb.size_list(); i++)
        {
            if (nameBook == lb[i].getNameBook()&&lb[i].getFlag()==1)
            {
                index = i;
            }
        }
        if (index < 0)
        {
            g.tab(75);cout << "Sach khong ton tai!!!" << endl;
            continue;
        }
        g.tab(70);cout << "So luong       ";
        int quantity;
        cin >> quantity;
        if (quantity > lb[index].getQuantity())
        {
            g.tab(75);cout << "So luong ton kho khong du!!!";
            continue;
        }
        string idBook = lb[index].getIDBook();
        data.decreaseQuantityOfBook(idBook, quantity);
        data.writeFileBook(data.getDataBook()); 
        DetailOrder detailOrder(idOrder, nameBook, quantity);
        data.getDataDetailOrder().addLast(detailOrder);
        data.writeFileDetailOrder(data.getDataDetailOrder());
        g.tab(74);cout << "--> Them sach thanh cong! <--" << endl;
        totalPrice += lb[index].getPrice() * quantity;
        int choice;
        g.tab(65);cout << "Nhap '1' de tiep tuc them sach- Nhan '0' de dung: ";
        cin >> choice;
        cin.ignore();
        if (choice == 0)
            break;
    }
    g.tab(70);cout << "Thoi gian khoi tao don hang: ";
    Date d;
    d.localDate();
    cout<<d<<endl;
    while (true)
    {
        g.tab(70);cout<<"Ma giam gia:   ";
        string idDiscount="";
        getline(cin,idDiscount);
        if (idDiscount=="")
        {
            idDiscount = "0";
            Order od(idOrder, idCustomer, d, idDiscount, totalPrice);
            g.tab(70);cout<<"--->Tong tien: "<<totalPrice<<" VND"<<endl;
            data.getDataOrder().addLast(od);
            data.writeFileOrder(data.getDataOrder());
            g.tab(65);
            cout << "--------TAO DON HANG THANH CONG!!!--------" << endl;
            break;
        }
        else
        {
            int index = -1;
            List<Discount> &ld = data.getDataDiscount();
            for (int i = 0; i < ld.size_list(); i++)
            {
                string tmp=ld[i].getIDDiscount();
                if (idDiscount == tmp&&ld[i].getFlag()==1)
                {
                    index = i;
                }
            }
            if (index < 0)
            {
                g.tab(75);cout << "Ma giam gia khong ton tai!" << endl;
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
                        g.tab(70);cout<<"--->Tong tien: "<<totalPrice<<" VND"<<endl;
                        data.getDataOrder().addLast(od);
                        data.writeFileOrder(data.getDataOrder());
                        g.tab(65);
                        cout << "--------TAO DON HANG THANH CONG!!!--------" << endl;
                        break;
                    }
                    else
                    {
                        g.tab(75);cout << "Ma giam gia khong hop le!!!" << endl;
                    }
                }
                else
                {
                    g.tab(75);cout << "Ma giam gia het han!!!" << endl;
                }
            }
        }
    }
}
void OrderManagement::listOrder(Data &data){
    g.tab(65);cout<<"---------------------------------------------" << endl;
    g.tab(65);cout<<"|             DANH SACH HOA DON             |" << endl;
    g.tab(65);cout<<"---------------------------------------------" << endl;
    List<Order> order=data.getDataOrder();
    g.downLine(1);
    g.tab(50);cout<<"====================================================================="<<endl;
    g.tab(50);cout<<"|Ma don hang   |Ma khach hang   |Ngay mua hang   |Tong tien(VND)    |"<<endl;
    g.tab(50);cout<<"---------------------------------------------------------------------"<<endl;
    for(int i=0;i<order.size_list();i++){
        g.tab(50);cout<<"|"<<left<<setw(14)<<order[i].getIDOrder()<<"|"<<left<<setw(16)<<order[i].getIDCustomer();
        cout<<"|"<<order[i].getDate()<<"      |"<<left<<setw(18)<<order[i].getTotalPrice()<<"|"<<endl;
    }
    g.tab(50);cout<<"====================================================================="<<endl;
    g.tab(56);cout<<"Ban co chac chan muon xem chi tiet don hang khong (y/n)? "<<endl;
    g.tab(76);cout<<"1. Yes"<<endl;
    g.tab(76);cout<<"2. No"<<endl;
    int n;
    g.tab(71);cout<<"Nhap lua chon: ";cin>>n;
    if(n==1){
        g.downLine(1);
        this->showOrder(data);
        return;
    }
    cin.ignore();
}
void OrderManagement::showOrder(Data &data)
{
    g.tab(71); cout << "CHI TIET DON HANG" << endl;
    g.tab(68); cout << "Nhap ma hoa don: ";
    cin.ignore();
    string idOrder;
    getline(cin, idOrder);
    int index=-1;
    List<Order>& order = data.getDataOrder();
    for (int i = 0; i < order.size_list(); i++)
    {
        if (idOrder == order[i].getIDOrder())
        {
            index = i;
            break;
        }
    }
    if (index < 0)
    {
        g.tab(64);cout << "Ma don hang: " <<"'"<<idOrder<<"'"<< " khong ton tai!" << endl;
        return;
    }
    int index2=-1;
    List<Customer> customer=data.getDataCustomer();
    for(int i=0;i<customer.size_list();i++){
        if(order[index].getIDCustomer()==customer[i].getIDCustomer()){
            index2=i;
            break;
        }
    }
    if(index2<0){
        g.tab(64);cout<<"Khach hang khong ton tai!"<<endl;
        return;
    }
    g.downLine(1);
    g.tab(68);cout << "Thong tin khach hang"<<endl; 
    g.tab(60);cout << "Ho ten khach hang:   " << customer[index2].getFullName() << endl;
    g.tab(60);cout << "Dia chi:             " << customer[index2].getAddress() << endl;
    g.tab(60);cout << "So dien thoai:       " << customer[index2].getPhoneNumber() << endl;
    g.downLine(1);
    g.tab(68);cout << "Thong tin don hang" << endl;
    g.tab(65);cout << "Ngay mua sach: "<< order[index].getDate()<<endl;
    g.tab(45);cout << "=================================================================" << endl;
    g.tab(45);cout << "|Ten sach                           |Don gia(VND)   |So luong   |" << endl;
    g.tab(45);cout << "-----------------------------------------------------------------" << endl;
    List<DetailOrder>& detail=data.getDataDetailOrder();
    List<Book>& book=data.getDataBook();
    for(int i=0;i<detail.size_list();i++){
        if(order[index].getIDOrder()==detail[i].getIDOrder()){
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
        if(data.getDataDiscount()[i].getIDDiscount()==order[index].getIDDiscount()){
            g.tab(81);cout<<"Giam gia:  "<<data.getDataDiscount()[i].getDiscount()<<" VND"<<endl;
            break;
        }
    }
    g.tab(81);cout << "Tong tien: " << order[index2].getTotalPrice() << " VND" << endl;
}