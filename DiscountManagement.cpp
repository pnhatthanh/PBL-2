#include"DiscountManagement.h"
void DiscountManagement::addDisscount(Data& data){
    g.downLine(1);
    g.tab(71);
    cout << " ------------------" << endl;
    g.tab(71);
    cout << "| THEM MA GIAM GIA |" << endl;
    g.tab(71);
    cout << " ------------------" << endl;
    g.tab(57);
    cout<<"Ma giam gia: "; string idDiscount;
    cin.ignore(1);
    getline(cin,idDiscount);
    g.tab(57);
    cout<<"Muc giam gia(VND): ";double discount;
    cin>>discount;
    g.tab(57);
    cout<<"So tien toi thieu(VND): ";double level;
    cin>>level;
    g.tab(57);
    cout<<"So luong ma giam gia: ";int quantity;
    cin>>quantity;
    g.tab(57);
    cout<<"Ngay bat dau: " << endl;Date firstDate;
    firstDate.setDate();
    g.tab(57);
    cout<<"Ngay ket thuc: " << endl;Date lastDate;
    lastDate.setDate();
    string status;
    if(quantity>0){
        status="Ok";
    }else{
        status="Empty";
    }
    Discount dis(idDiscount,discount,level,quantity,firstDate,lastDate,status);
    data.getDataDiscount().addLast(dis);
    g.tab(57);
    cout<<"Them ma giam gia thanh cong!!!"<<endl;
}

void DiscountManagement::deleteDiscount(Data& data){
    List<Discount> &ld=data.getDataDiscount();
    g.tab(57);
    cout<<"Nhap ma giam gia ban muon xoa: ";
    string nameDiscount;
    cin.ignore(1);
    getline(cin,nameDiscount);
    int index=-1;
    for(int i=0;i<ld.size_list();i++){
        if(ld[i].getIDDiscount()==nameDiscount){
            index=i;
        }
    }
    if(index<0){
        cout<<"Ma giam gia khong ton tai!!!"<<endl;
        return;
    }
    data.getDataDiscount().remove(index);
    g.tab(57);
    cout << "Xoa ma giam gia thanh cong!!!" << endl;
}

void DiscountManagement::showDiscount(Data &data){
    //Lay danh sach ma giam gia
    List<Discount> &ld=data.getDataDiscount();
    g.downLine(1);
    g.tab(71);
    cout << " -----------------------" << endl;
    g.tab(71);
    cout << "| DANH SACH MA GIAM GIA |" << endl;
    g.tab(71);
    cout << " -----------------------" << endl;
    g.downLine(1);
    g.tab(30);cout << " ============================================================================================================" << endl;
    g.tab(30);cout << " |Ma giam gia |Muc giam gia(VND) |So tien toi thieu(VND) |So luong |Ngay bat dau |Ngay ket thuc |Tinh trang |" << endl;
    g.tab(30);cout << " ------------------------------------------------------------------------------------------------------------" << endl;
    for(int i=0;i<ld.size_list();i++){
        g.tab(30);cout<<" |" << left << setw(12) << ld[i].getIDDiscount() << "|" << left << setw(18) << ld[i].getDiscount()
        << "|"<< left << setw(23) <<ld[i].getLevel()<< "|" << left << setw(9) <<ld[i].getQuantity()
        << "|" << left <<ld[i].getFirstDate() << "   "<<"|" << left <<ld[i].getLastDate() << "    "
        << "|" << left << setw(11) <<ld[i].getStatus()<< "|" <<endl;
    }
    g.tab(30);cout << " ============================================================================================================" << endl;
}
void DiscountManagement::editDiscount(Data &data){
    //Lay danh sach ma giam gia
    List<Discount> &ld=data.getDataDiscount();
    g.downLine(1);
    g.tab(71);
    cout << " ----------------------" << endl;
    g.tab(71);
    cout << "| CHINH SUA MA GIAM GIA |" << endl;
    g.tab(71);
    cout << " ----------------------" << endl;
    g.tab(57);
    cout<<"Nhap ma giam gia: ";
    cin.ignore(1);
    string nameDiscount;
    getline(cin,nameDiscount);
    int index=-1;
    for(int i=0;i<ld.size_list();i++){
        if(ld[i].getIDDiscount()==nameDiscount){
            index=i;
            break;
        }
    }
    if(index<0){
        g.tab(57);
        cout<<"Ma giam gia khong ton tai!!!"<<endl;
        return;
    }    
    g.tab(57);
    cout<<"Muc giam gia(VND): ";double discount;
    cin>>discount;
    g.tab(57);
    cout<<"So tien toi thieu(VND): ";double level;
    cin>>level;
    g.tab(57);
    cout<<"So luong ma giam gia: ";int quantity;
    cin>>quantity;
    g.tab(57);
    cout<<"Ngay bat dau:" << endl;Date firstDate;
    firstDate.setDate();
    g.tab(57);
    cout<<"Ngay ket thuc:" << endl;Date lastDate;
    lastDate.setDate();
    string status;
    if(quantity>0){
        status="Ok";
    }else{
        status="Empty";
    }
    Discount dis(nameDiscount,discount,level,quantity,firstDate,lastDate,status);
    data.updateDiscount(index,dis);
    g.tab(57);
    cout<<"Cap nhat ma giam gia thanh cong!!!"<<endl;
}