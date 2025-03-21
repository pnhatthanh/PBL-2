#include "CustomerManagement.h"
CustomerManagement::CustomerManagement()
{
}
CustomerManagement::~CustomerManagement()
{
}
void CustomerManagement::searchCustomer(Data &data)
{
    List<Customer> &lc = data.getDataCustomer();
    g.tab(65);cout<<"---------------------------------------------" << endl;
    g.tab(65);cout<<"|            TIM KIEM KHACH HANG            |" << endl;
    g.tab(65);cout<<"---------------------------------------------" << endl;
    g.downLine(1);
    g.tab(57);cout << "Nhap ho ten khach hang ban muon tim kiem: ";
    cin.ignore();
    string tmp;
    getline(cin, tmp);
    g.downLine(2);
    int index = -1;
    for (int i = 0; i < lc.size_list(); i++)
    {
        string tmp1 = lc[i].getFullName();
        if (tmp == tmp1)
        {
            index = i;
            g.tab(76);cout<<"Thong tin khach hang"<<endl;
            g.tab(65);cout<<"--------------------------------------------"<<endl;
            g.tab(65);
            cout << "|Ma khach hang:  |";  cout << left << setw(25)<< lc[index].getIDCustomer() <<"|" <<endl;
            g.tab(65);
            cout << "|Ten khach hang: |"; cout << left << setw(25) << lc[index].getFullName() <<"|" << endl;
            g.tab(65);
            cout << "|Dia chi:        |"; cout<< left << setw(25) << lc[index].getAddress()<<"|"  << endl;
            g.tab(65);
            cout << "|So dien thoai:  |";  cout<< left << setw(25) << lc[index].getPhoneNumber() <<"|" << endl;
            g.tab(65);
            cout << "|Email:          |";  cout<< left << setw(25) << lc[index].getEmail()<<"|"  << endl;
            g.tab(65);cout<<"--------------------------------------------"<<endl;
            g.downLine(1);
        }
    }
    if (index < 0){
        g.tab(68);cout << "Khach hang ban tim kiem khong ton tai!" << endl;
    }
}
void CustomerManagement::deleteCustomer(Data &data)
{
    List<Customer> &lc = data.getDataCustomer();
    List<Order> &lo=data.getDataOrder();
    List<DetailOrder> &ld=data.getDataDetailOrder();
    string tmp;
    g.tab(65);cout<<"---------------------------------------------" << endl;
    g.tab(65);cout<<"|              XOA KHACH HANG               |" << endl;
    g.tab(65);cout<<"---------------------------------------------" << endl;
    g.downLine(1);
    g.tab(62);cout << "Nhap ho ten khach hang ban muon xoa: ";
    cin.ignore();
    getline(cin, tmp);
    g.downLine(2);
    int index = -1;
    for (int i = 0; i < lc.size_list(); i++)
    {
        string tmp1 = lc[i].getFullName();
        if (tmp == tmp1)
        {
            index = i;
        }
    }
    if (index < 0){
        g.tab(68);
        cout << "Khach hang ban muon xoa khong ton tai!" << endl;
    }
    else
    {
        g.tab(78);cout << "Thong tin khach hang"<<endl; g.downLine(1);
        g.tab(70);cout << "Ho ten khach hang:   " << lc[index].getFullName() << endl;
        g.tab(70);cout << "Dia chi:             " << lc[index].getAddress() << endl;
        g.tab(70);cout << "So dien thoai:       " << lc[index].getPhoneNumber() << endl;
        g.tab(70);cout << "Email:               " << lc[index].getEmail()<<endl;
        g.tab(66);cout<<"Ban co chac chan muon xoa khach hang nay khong (y/n)? "<<endl;
        g.tab(85);cout<<"1. Yes"<<endl;
        g.tab(85);cout<<"2. No"<<endl;
        int n;
        g.tab(81);cout<<"Nhap lua chon: ";cin>>n;
        if(n==1){
            for(int i=0;i<lo.size_list();i++){
                if(lc[index].getIDCustomer()==lo[i].getIDCustomer()){
                    for(int j=0;j<ld.size_list();j++){
                        if(ld[j].getIDOrder()==lo[i].getIDOrder()){
                            ld.remove(j);
                            j--;
                        }
                    }
                    lo.remove(i);
                    break;
                }
            }
            lc.remove(index);
            data.writeFileOrder(lo);
            data.writeFileDetailOrder(ld);
            data.writeFileCustomer(lc);
            g.tab(65);cout << "--------------XOA KHACH HANG THANH CONG!--------------" << endl;
           
        }
        cin.ignore();
    }
}
void CustomerManagement::showCustomer(Data &data)
{
    g.tab(67);cout<<"---------------------------------------------" << endl;
    g.tab(67);cout<<"|     DANH SACH KHACH HANG CUA CUA HANG     |" <<endl;
    g.tab(67);cout<<"---------------------------------------------" << endl;
    g.downLine(2);
    g.tab(45);
    cout << "================================================================================================" << endl;
    g.tab(45);
    cout << "|ID khach hang  |Ten khach hang          |Dia chi      |So dien thoai  |Email                  |" << endl;
    g.tab(45);
    cout << "------------------------------------------------------------------------------------------------" <<endl;
    List<Customer> &lc = data.getDataCustomer();
    for (int i = 0; i < lc.size_list(); i++)
    {
        g.tab(45);
        cout << "|" << left << setw(15) << lc[i].getIDCustomer() << "|" << left << setw(24) << lc[i].getFullName() << "|" << left << setw(13) << lc[i].getAddress() << "|" << left << setw(15) << lc[i].getPhoneNumber()<<"|" << left << setw(23) << lc[i].getEmail() << "|" << endl;
    }
    g.tab(45);
    cout << "================================================================================================" << endl;
}
