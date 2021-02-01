//
// Created by 18382 on 2021/1/25.
//

#ifndef MAIN_CPP_CAMMAND_USER_H
#define MAIN_CPP_CAMMAND_USER_H
#include "nodelist.h"
#define reportfinancefile "reportfinance.dat"
#define reportemployeefile "reportemployee.dat"
#define LOGfile "log.dat"
#define totlemoneyfile "totalmoney.dat"
#define transactionfile "transaction.dat"//记录每一笔交易
#define bookfile "book_file.dat"//记录书的文件
#define USER "user.dat"
#define useridfile "user_id.dat"
#define isbnfile "isbn.dat"
#define authorfile "author.dat"
#define namefile "name.dat"
#define keyfile "keyword.dat"



using namespace std;
class user{
public:
    int priority = -1;
    char user_id[31];
    char password[31];
    char name[31];
    int select = -1;
    user(){};
    user(const string&userid,const string &pass,const string &name, int pri);
};

void login(const string &userid1,string password = "");


bool checkauthor(const string &a);

bool checkname(const string & a);

bool checkuser_id(const string &a);


bool checkpasswd(const string &a);

bool checkpasswd2(const string &a);

bool checkeyword(const string&a);

bool havekeyword(const string &a,const string & key);

bool checkisbn(const string &a);

void logout();


void register_(user &U);


void addacount(user &a);

void deleteaccount(string userid);

void changepassword(const char* user_id,const char * newpas,const char* oldpas = "");


void selectbook(const string & ISBN1);


void import(int quantity, double totleprice);


void buy(const string &ISBN1,int quantity1);


void showfinance();


void showfinancetime(int times);


void show();


void show(const string &key,nodelist &a);


void modifyISBN(const string &key);



void modifyNAME(const string &key);



void modifyAUTHOR(const string &key);




void modifyKEYWORD(const string &key);




void modifyPRICEC(double price);


void Run_Program(string &a);


void splitkey(string str,vector<string>&a);



void clear();


int getselect();


template <class T>
T my_read(const string&  filename,int offset){
    fstream fin;
    fin.open(filename,ios::in|ios::binary);
    if(!fin)throw("error");
    T tmp;
    fin.seekg(offset);
    fin.read(reinterpret_cast<char*>(&tmp),sizeof(T));
    fin.close();
    return tmp;
}

template <class T>
int my_write(const string& filename,T &o,int offset = -1){
    fstream fin;
    fin.open(filename,ios::in | ios::binary | ios::out);
    if(!fin)throw("cannot open the file(my_write)");
    if(offset < 0){
        fin.seekg(0,ios::end);
        offset = fin.tellg();
    }else{
        fin.seekg(offset);
    }
    fin.write(reinterpret_cast<char *>(&o),sizeof(T));
    fin.close();
    return offset;
}







#endif //MAIN_CPP_CAMMAND_USER_H
