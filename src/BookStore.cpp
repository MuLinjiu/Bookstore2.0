//
// Created by 18382 on 2021/1/25.
//
#include <cstring>
#include "BookStore.h"
#include <fstream>

extern nodelist useridlist;

Book::Book() = default;


Book::Book(double price1, const string &name1, const string &ISBN1, const string &author1, const string &key1,int quantity1) {
    strcpy(name,name1.c_str());
    strcpy(ISBN,ISBN1.c_str());
    strcpy(author,author1.c_str());
    strcpy(key,key1.c_str());
    price = price1;
    quantity = quantity1;
}

bool Book::operator<(Book &a) {
    int c = strcmp(this->ISBN,a.ISBN);
    if(c < 0)return true;
    else return false;
}



void Book::show() const {
    cout<<ISBN<<"\t"<<name<<"\t"<<author<<"\t"<<key<<"\t";
    printf("%.2lf\t%d\n",price,quantity);

}



transaction::transaction() = default;

transaction::transaction(const string & ISBN1,const string & userid1,int quant, double price){
    strcpy(ISBN,ISBN1.c_str());
    strcpy(user_id,userid1.c_str());
    quantity = quant;
    totalprice = price;
}

totlemoney::totlemoney() {
    expense = 0;
    benefit = 0;
}


void initialize(){
//注意初始化totlemoney进入文件
    fstream fin,fout;
    fin.open(useridfile,ios::in);
    if(!fin){
        fin.open(useridfile,ios::out);
        fin.close();
        fin.open(USER,ios::out);
        fin.close();
        fin.open(totlemoneyfile,ios::out);
        fin.close();
        fin.open(transactionfile,ios::out);
        fin.close();
        fin.open(bookfile,ios::out);
        fin.close();
        fin.open(isbnfile,ios::out);
        fin.close();
        fin.open(authorfile,ios::out);
        fin.close();
        fin.open(namefile,ios::out);
        fin.close();
        fin.open(keyfile,ios::out);
        fin.close();
        fin.open(reportemployeefile,ios::out);
        fin.close();
        fin.open(reportfinancefile,ios::out);
        fin.close();
        fin.open(LOGfile,ios::out);
        fin.close();
        user root("root","sjtu","root",7);
        int offset = my_write<user>(USER,root);
        node tmp(offset,"root");
        useridlist.addnode(tmp);



        totlemoney tmpq;
        fout.open(totlemoneyfile,ios::in | ios ::out | ios::binary);
        fout.seekp(0);
        fout.write(reinterpret_cast<char*>(&tmpq),sizeof(totlemoney));
        fout.close();
    }else{
        fin.close();
    }
}


reporte::reporte() = default;


reporte::reporte(const string& name1,const string& action1,double mo){
    strcpy(name,name1.c_str());
    strcpy(action,action1.c_str());
    money = mo;
}


reportf::reportf() = default;



reportf::reportf(const string &a,double n) {
    strcpy(action,a.c_str());
    money = n;
}


LOG::LOG() = default;
LOG::LOG(const string& na,const string& ac, double mo) {
    strcpy(name,na.c_str());
    strcpy(action,ac.c_str());
    money = mo;
}