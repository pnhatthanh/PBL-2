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
        void Logo();
        void readFileCategory();
        void readFileCustomer();
        void readFileBook();
        void readFileOrder();
        void readFileDiscount();
        void readFileDetailOrder();
        void writeFileCustomer(List<Customer>&);
        void writeFileBook(List<Book>&);
        void writeFileCategory(List<Category>&);
        void writeFileDetailOrder(List<DetailOrder>&);
        void writeFileDiscount(List<Discount>&);
        void writeFileOrder(List<Order>&);
        List<Customer>& getDataCustomer();
        List<Book>& getDataBook();
        List<Order>& getDataOrder();
        List<Discount>& getDataDiscount();
        List<DetailOrder>& getDataDetailOrder();
        List<Category>& getDataCategory();
        void decreaseQuantityOfBook(string,int);
        void updateDiscount(int, Discount);
};