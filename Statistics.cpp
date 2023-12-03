#include"Statistics.h"
void Statistics::inventoryNumber(Data &data){
    g.downLine(1);
    g.tab(71);
    cout << " ------------------------" << endl;
    g.tab(71);
    cout << "|    SO LUONG TON KHO   |" << endl;
    g.tab(71);
    cout << " ------------------------" << endl;
    List<Book> dataBook=data.getDataBook();
    g.tab(47);cout << " =======================================================================" << endl;
    g.tab(47);cout << " |Ma sach |Ten Sach                                |So luong |Gia sach |" << endl;
    g.tab(47);cout << " -----------------------------------------------------------------------" << endl;
    for(int index=0;index<dataBook.size_list();index++){
      g.tab(47);cout<<" |" << left << setw(8) <<dataBook[index].getIDBook()<<"|" << left << setw(40) <<dataBook[index].getNameBook()
      <<"|" << left << setw(9) <<dataBook[index].getQuantity()<<"|" << left << setw(9) <<dataBook[index].getPrice()<<"|"<<endl;
    }
    g.tab(47);cout << "=========================================================================" << endl;
}
void Statistics::sales(Data& data){
    g.downLine(1);
    g.tab(71);
    cout << " --------------------" << endl;
    g.tab(71);
    cout << "| THONG KE DOANH THU |" << endl;
    g.tab(71);
    cout << " --------------------" << endl;
    cin.ignore();
    g.downLine(1);
   Date d1, d2;
   bool check=true;
   do{
      g.tab(73);cout<<"Moc thoi gian"<<endl;
      g.tab(57);
      cout<<"*Ngay bat dau"<<endl;
      d1.setDate();
      g.tab(57);
      cout<<"*Ngay ket thuc: "<<endl;
      d2.setDate();
      if(d1<=d2){
         check=false;
      }
      if(check==true){
         g.tab(57);
         cout<<"Moc thoi gian khong hop le. Vui long nhap lai!!!"<<endl;
      }
   }while(check);
   List<Order> dataOrder=data.getDataOrder();
   g.downLine(1);
   g.tab(72);
   cout<<"DANH SACH HOA DON"<<endl;
   g.tab(56);cout << "==============================================" << endl;
   g.tab(56);cout << "| Ma Hoa Don |Ma Khach Hang |Tong Tien(VND)  |"<<endl;
   g.tab(56);cout << "----------------------------------------------" << endl;
   double total=0;
   for(int index=0;index<dataOrder.size_list();index++){
      Date tmp=dataOrder[index].getDate();
      if(d1<=tmp&& d2>=tmp){
         g.tab(56);cout<< "| " << left << setw(11)<<dataOrder[index].getIDOrder()<<"|" <<left << setw(14) 
         <<dataOrder[index].getIDCustomer()<<"|" << left << setw(15)<<dataOrder[index].getTotalPrice() << " |" <<endl;
         total+=dataOrder[index].getTotalPrice();
      }
   }
   g.tab(56);cout << "==============================================" << endl;
   g.tab(66);cout<<"--->Tong doanh thu: "<<total<<" VND"<<endl;
}
void Statistics::listBestSeller(Data &data){
   g.downLine(1);
   g.tab(71);
   cout << " -------------------------" << endl;
   g.tab(71);
   cout << "| DANH SACH SACH BAN CHAY |" << endl;
   g.tab(71);
   cout << " -------------------------" << endl;
   List<MapBook> map;
   List<DetailOrder> detail=data.getDataDetailOrder();
   for(int i=0;i<detail.size_list();i++){
      bool check=false;
      for(int j=0;j<map.size_list();j++){
         string nameb=detail[i].getNameBook();
         if(nameb==map[j].getBook()){
            check=true;
            map[j].getCount()=map[j].getCount()+detail[i].getQuantityBook();
         }
      }
      if(check==false){
         string nameBook=detail[i].getNameBook();
         int count=detail[i].getQuantityBook();
         MapBook mb(nameBook,count);
         map.addLast(mb);
      }
   }
   for(int i=0;i<map.size_list()-1;i++){
      for(int j=i+1;j<map.size_list();j++){
         if(map[i]<map[j]){
            MapBook tmp=map[i];
            map[i]=map[j];
            map[j]=tmp;
         }
      }
      
   }
   g.tab(57);cout << " ====================================================" << endl;
   g.tab(57);cout << " |Ten sach                                |So luong |"<<endl;
   g.tab(57);cout << " ----------------------------------------------------" << endl;
   for(int i=0;i<map.size_list();i++){
      g.tab(57);cout<< " |" << left << setw(40) <<map[i].getBook()<<"|" << left << setw(9) <<map[i].getCount() <<"|"<<endl;
   }
   g.tab(57);cout << " ====================================================" << endl;
}
