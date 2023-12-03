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
    g.tab(72);cout << "TIM KIEM KHACH HANG" << endl;
    g.downLine(1);
    g.tab(55);cout << "Nhap ho ten khach hang ban muon tim kiem: ";
    cin.ignore();
    string tmp;
    getline(cin, tmp);
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
        g.downLine(1);
        g.tab(63);cout << "Khach hang ban tim kiem khong ton tai!!" << endl;
    }
    else
    {
        g.downLine(1);
        g.tab(72);cout<<"Thong tin khach hang"<<endl;
        g.tab(60);cout<<"--------------------------------------------"<<endl;
        g.tab(60);
        cout << "|Ma khach hang:  |";  cout << left << setw(25)<< lc[index].getIDCustomer() <<"|" <<endl;
        g.tab(60);
        cout << "|Ten khach hang: |"; cout << left << setw(25) << lc[index].getFullName() <<"|" << endl;
        g.tab(60);
        cout << "|Dia chi:        |"; cout<< left << setw(25) << lc[index].getAddress()<<"|"  << endl;
        g.tab(60);
        cout << "|So dien thoai:  |";  cout<< left << setw(25) << lc[index].getPhoneNumber() <<"|" << endl;
        g.tab(60);
        cout << "|Email:          |";  cout<< left << setw(25) << lc[index].getEmail()<<"|"  << endl;
        g.tab(60);cout<<"--------------------------------------------"<<endl;
    }
}
void CustomerManagement::deleteCustomer(Data &data)
{
    List<Customer> &lc = data.getDataCustomer();
    string tmp;
    g.tab(72);cout << "XOA KHACH HANG" << endl;
    g.tab(55);cout << "Nhap ho ten khach hang ban muon xoa: ";
    cin.ignore();
    getline(cin, tmp);
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
        g.tab(62);
        cout << "Khach hang ban muon xoa khong ton tai!!" << endl;
    }
    else
    {
        cout<<"\n";
        g.tab(68);cout << "Thong tin khach hang"<<endl; g.downLine(1);
        g.tab(60);cout << "Ho ten khach hang:   " << lc[index].getFullName() << endl;
        g.tab(60);cout << "Dia chi:             " << lc[index].getAddress() << endl;
        g.tab(60);cout << "So dien thoai:       " << lc[index].getPhoneNumber() << endl;
        g.tab(60);cout << "Email:               " << lc[index].getEmail()<<endl;
        g.tab(56);cout<<"Ban co chac chan muon xoa khach hang nay khong (y/n)? "<<endl;
        g.tab(76);cout<<"1. Yes"<<endl;
        g.tab(76);cout<<"2. No"<<endl;
        int n;
        g.tab(71);cout<<"Nhap lua chon: ";cin>>n;
        if(n==1){
            for(int i=0;i<data.getDataOrder().size_list();i++){
                if(lc[index].getIDCustomer()==data.getDataOrder()[i].getIDCustomer()){
                    for(int j=0;j<data.getDataDetailOrder().size_list();j++){
                        if(data.getDataDetailOrder()[j].getIDOrder()==data.getDataOrder()[i].getIDOrder()){
                            data.getDataDetailOrder().remove(j);
                            j--;
                        }
                    }
                    data.getDataOrder().remove(i);
                    break;
                }
            }
            lc.remove(index);
            data.writeFileOrder(data.getDataOrder());
            data.writeFileDetailOrder(data.getDataDetailOrder());
            data.writeFileCustomer(lc);
            g.tab(55);cout << "--------------XOA KHACH HANG THANH CONG!--------------" << endl;
           
        }
        cin.ignore();
    }
}
void CustomerManagement::showCustomer(Data &data)
{
    g.tab(72);cout<<"DANH SACH KHACH HANG CUA CUA HANG" <<endl;
    g.tab(40);
    cout << "================================================================================================" << endl;
    g.tab(40);
    cout << "|ID khach hang  |Ten khach hang          |Dia chi      |So dien thoai  |Email                  |" << endl;
    List<Customer> &lc = data.getDataCustomer();
    for (int i = 0; i < lc.size_list(); i++)
    {
        g.tab(40);
        cout << "|" << left << setw(15) << lc[i].getIDCustomer() << "|" << left << setw(24) << lc[i].getFullName() << "|" << left << setw(13) << lc[i].getAddress() << "|" << left << setw(15) << lc[i].getPhoneNumber()<<"|" << left << setw(23) << lc[i].getEmail() << "|" << endl;
    }
    g.tab(40);
    cout << "================================================================================================" << endl;
}
