//
// Created by 18382 on 2021/1/25.
//
#include <iostream>
#include <string>
#include "Cammand(user).h"
#ifndef MAIN_CPP_BOOKSTORE_H
#define MAIN_CPP_BOOKSTORE_H
using namespace std;
class Book{
public:
    double price = 0;
    char name[60] = "";
    char ISBN[20] = "";
    char author[60] = "";
    char key[60] = "";
    int quantity = 0;
    Book();
    Book(double price1,const string &name,const string & ISBN,const string &author,const string & key,int quantity);
    bool operator < (Book &a);
    void show()const;
};

class transaction{
public:
    char user_id[30] = {0};
    char ISBN[30] = {0};
    int quantity = 0;
    double totalprice = 0;//正数为收入，负数为支出
    transaction();
    transaction(const string & ISBN_,const string & user_id_,int quant, double price);

};


class totlemoney{
public:
    double benefit = 0;
    double expense = 0;
    totlemoney();
};


void initialize();


#endif //MAIN_CPP_BOOKSTORE_H
