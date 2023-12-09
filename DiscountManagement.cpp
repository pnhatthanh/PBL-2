#include"DiscountManagement.h"
void DiscountManagement::addDisscount(Data& data){
    g.tab(65);cout<<"---------------------------------------------" << endl;
    g.tab(65);cout<<"|             THEM MA GIAM GIA              |" << endl;
    g.tab(65);cout<<"---------------------------------------------" << endl;
    g.downLine(2);
    g.tab(77);
    cout<<"Thong tin ma giam gia"<<endl;
    cin.ignore(1);
    string idDiscount;
    do{
        bool check=1;
        g.tab(66);
        cout << "Ma giam gia:              "; 
        getline(cin,idDiscount);
        for(int i=0;i<data.getDataDiscount().size_list();i++){
            if(idDiscount==data.getDataDiscount()[i].getIDDiscount()){
                check=0;
            }
        }
        if(check==0){
            g.tab(70);cout<<"Ma giam gia da ton tai!!!"<<endl;
        }else{
            break;
        }
    }while(true);
    double discount;
    do{
        g.tab(66);
        cout << "Muc giam gia(VND):        ";
        cin>>discount;
        if(discount<0){
            g.tab(70);
            cout<<"Muc giam gia khong hop le!"<<endl;
        }
    }while(discount<0);
    double level;
    do{
        g.tab(66);
        cout << "So tien toi thieu(VND):   ";
        cin>>level;
        if(level<0){
            g.tab(70);
            cout<<"So tien toi thieu khong hop le!"<<endl;
        }
    }while(level<0);
    int quantity;
    do{
        g.tab(66);
        cout << "So luong ma giam gia:     ";
        cin>>quantity;
        if(quantity<0){
            g.tab(70);
            cout<<"So luong ma giam gia khong hop le!"<<endl;
        }
    }while(quantity<0);
    cin.ignore();
    Date firstDate;
    Date lastDate;
    do{
      g.tab(77);cout<<"Moc thoi gian"<<endl;
      g.tab(66);
      cout<<"*Ngay bat dau"<<endl;
      firstDate.setDate();
      g.tab(66);
      cout<<"*Ngay ket thuc: "<<endl;
      lastDate.setDate();
      if(firstDate<=lastDate){
        break;
      }else{
        g.tab(70);
        cout<<"Moc thoi gian khong hop le!"<<endl;
      }
   }while(true);
    string status;
    if(quantity>0){
        status="Con";
    }else{
        status="Het";
    }
    int flag=1;
    Discount dis(idDiscount,discount,level,quantity,firstDate,lastDate,status,flag);
    data.getDataDiscount().addLast(dis);
    data.writeFileDiscount(data.getDataDiscount());
    g.downLine(1);
    g.tab(64);
    cout << "--------THEM MA GIAM GIA THANH CONG!!!--------" << endl;
}
void DiscountManagement::deleteDiscount(Data& data){
    g.tab(65);cout<<"---------------------------------------------" << endl;
    g.tab(65);cout<<"|             XOA MA GIAM GIA               |" << endl;
    g.tab(65);cout<<"---------------------------------------------" << endl;
    g.downLine(1);
    List<Discount> &ld=data.getDataDiscount();
    g.tab(65);
    cout<<"Nhap ma giam gia ban muon xoa: ";
    string nameDiscount;
    cin.ignore(1);
    getline(cin,nameDiscount);
    int index=-1;
    for(int i=0;i<ld.size_list();i++){
        if(ld[i].getIDDiscount()==nameDiscount&&ld[i].getFlag()==1){
            index=i;
        }
    }
    g.downLine(1);
    if(index<0){
        g.tab(71);cout<<"Ma giam gia khong ton tai!!!"<<endl;
        return;
    }
    g.tab(75);
    cout<<"THONG TIN MA GIAM GIA"<<endl;    
    g.tab(68);
    cout << "Muc giam gia(VND):       "<<ld[index].getDiscount()<<" VND"<<endl;
    g.tab(68);
    cout << "So tien toi thieu(VND):  "<<ld[index].getLevel()<<" VND"<<endl;
    g.tab(68);
    cout << "So luong ma giam gia:    "<<ld[index].getQuantity()<<endl;
    g.tab(68);
    cout << "Ngay bat dau:            "<<ld[index].getFirstDate()<<endl;
    g.tab(68);
    cout << "Ngay ket thuc:           "<<ld[index].getLastDate()<<endl;
    g.tab(68);
    cout << "Trang thai ma giam gia:  "<<ld[index].getStatus()<<endl;
    g.tab(61);cout<<"Ban co chac chan muon xoa ma giam gia nay khong (y/n)? "<<endl;
    g.tab(80);cout<<"1. Yes"<<endl;
    g.tab(80);cout<<"2. No"<<endl;
    int n;
    g.tab(74);cout<<"Nhap lua chon: ";cin>>n;
    if(n==1){
        data.getDataDiscount()[index].setFlag(0);
        data.writeFileDiscount(data.getDataDiscount());
        g.tab(60);cout << "--------------XOA MA GIAM GIA THANH CONG!--------------" << endl;
    }
    cin.ignore();
}

void DiscountManagement::showDiscount(Data &data){
    //Lay danh sach ma giam gia
    List<Discount> &ld=data.getDataDiscount();
    g.tab(65);cout<<"---------------------------------------------" << endl;
    g.tab(65);cout<<"|            DANH SACH MA GIAM GIA          |" << endl;
    g.tab(65);cout<<"---------------------------------------------" << endl;
    g.downLine(1);
    g.tab(30);cout << " ============================================================================================================" << endl;
    g.tab(30);cout << " |Ma giam gia |Muc giam gia(VND) |So tien toi thieu(VND) |So luong |Ngay bat dau |Ngay ket thuc |Tinh trang |" << endl;
    g.tab(30);cout << " ------------------------------------------------------------------------------------------------------------" << endl;
    for(int i=0;i<ld.size_list();i++){
        if(ld[i].getFlag()==1){
            g.tab(30);cout<<" |" << left << setw(12) << ld[i].getIDDiscount() << "|" << left << setw(18) << ld[i].getDiscount()
            << "|"<< left << setw(23) <<ld[i].getLevel()<< "|" << left << setw(9) <<ld[i].getQuantity()
            << "|" << left <<ld[i].getFirstDate() << "   "<<"|" << left <<ld[i].getLastDate() << "    "
            << "|" << left << setw(11) <<ld[i].getStatus()<< "|" <<endl;
        }
    }
    g.tab(30);cout << " ============================================================================================================" << endl;
}
void DiscountManagement::editDiscount(Data &data){
    //Lay danh sach ma giam gia
    List<Discount> &ld=data.getDataDiscount();
    g.tab(65);cout<<"---------------------------------------------" << endl;
    g.tab(65);cout<<"|            CHINH SUA MA GIAM GIA          |" << endl;
    g.tab(65);cout<<"---------------------------------------------" << endl;
    g.downLine(1);
    cin.ignore(1);
    g.tab(68);
    cout<<"Nhap ma giam gia: ";
    string nameDiscount;
    getline(cin,nameDiscount);
    int index=-1;
    for(int i=0;i<ld.size_list();i++){
        if(ld[i].getIDDiscount()==nameDiscount&&ld[i].getFlag()==1){
            index=i;
            break;
        }
    }
    g.downLine(1);
    if(index<0){
        g.tab(75);
        cout<<"Ma giam gia khong ton tai!!!"<<endl;
        return;
    }
    g.tab(75);
    cout<<"THONG TIN MA GIAM GIA"<<endl;    
    g.tab(68);
    cout << "Muc giam gia(VND):       "<<ld[index].getDiscount()<<" VND"<<endl;
    g.tab(68);
    cout << "So tien toi thieu(VND):  "<<ld[index].getLevel()<<" VND"<<endl;
    g.tab(68);
    cout << "So luong ma giam gia:    "<<ld[index].getQuantity()<<endl;
    g.tab(68);
    cout << "Ngay bat dau:            "<<ld[index].getFirstDate()<<endl;
    g.tab(68);
    cout << "Ngay ket thuc:           "<<ld[index].getLastDate()<<endl;
    g.tab(68);
    cout << "Trang thai ma giam gia:  "<<ld[index].getStatus()<<endl;
    g.downLine(1);
    double discount, level;
    int quantity;
    Date firstDate, lastDate;
    string status;
    g.tab(77);
    cout<<"CHINH SUA MA GIAM GIA"<<endl;
    g.tab(66);cout<<"Note: Nhan 'y' de chinh sua- Nhan 'Enter' de bo qua"<<endl;
    g.downLine(1);
    g.tab(68);
    string c;
    cout << "Muc giam gia(VND)        ";getline(cin,c);
    if(c=="y"){
        g.tab(75);
        cout<<"Nhap muc giam gia:      ";
        cin>>discount;
        cin.ignore(1);
    }else{
        discount=ld[index].getDiscount();
    }
    g.tab(68);
    cout << "So tien toi thieu(VND):  ";getline(cin,c);
    if(c=="y"){
        g.tab(75);
        cout<<"Nhap so tien toi thieu: ";
        cin>>level;
        cin.ignore(1);
    }else{
        level=ld[index].getLevel();
    }
    g.tab(68);
    cout << "So luong ma giam gia:    ";getline(cin,c);
    if(c=="y"){
        g.tab(75);
        cout<<"Nhap so luong ma giam gia: ";
        cin>>quantity;
        cin.ignore(1);
    }else{
        quantity=ld[index].getQuantity();
    }
    g.tab(68);
    cout << "Ngay bat dau:            ";getline(cin,c);
    if(c=="y"){
        cin.ignore();
        g.tab(12);firstDate.setDate();
        cin.ignore(1);
    }else{
        firstDate=ld[index].getFirstDate();
    }
    g.tab(68);
    cout << "Ngay ket thuc:           ";getline(cin,c);
    if(c=="c"){
        cin.ignore();
        g.tab(12);lastDate.setDate();
        cin.ignore(1);
    }else{
        lastDate=ld[index].getLastDate();
    }
    Date local;
    local.localDate();
    if(quantity>0&&local>=firstDate&&local<=lastDate){
        status="Con";
    }else{
        status="Het";
    }
    g.tab(68);cout<<"Trang thai ma giam gia:  "<<status<<endl;
    int flag=1;
    Discount dis(nameDiscount,discount,level,quantity,firstDate,lastDate,status,flag);
    data.updateDiscount(index,dis);
    data.writeFileDiscount(data.getDataDiscount());
    g.downLine(1);
    g.tab(64);
    cout << "--------CAP NHAT MA GIAM GIA THANH CONG!!!--------" << endl;
}