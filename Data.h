#pragma once
#include<iostream>
#include<iomanip>
#include<fstream>
#include"List.cpp"
#include"Category.h"
#include"Customer.h"
#include"Order.h"
#include"Discount.h"
#include"DetailOrder.h"
#include"Graphics.h"
using namespace std;
class Data{
    private:
        List<Customer> dataCustomer;
        List<Category> dataCategory;
        List<Book> dataBook;
        List<Order> dataOrder;
        List<Discount> dataDiscount;
        List<DetailOrder> dataDetailOrder;
    public:
        void readFileCategory();
        void readFileCustomer();
        void readFileBook();
        void readFileOrder();
        void readFileDiscount();
        void readFileDetailOrder();
        List<Customer>& getDataCustomer();
        List<Book>& getDataBook();
        List<Order>& getDataOrder();
        List<Discount>& getDataDiscount();
        List<DetailOrder>& getDataDetailOrder();
        List<Category>& getDataCategory();
        void decreaseQuantityOfBook(string,int);
        void updateDiscount(int, Discount);
};