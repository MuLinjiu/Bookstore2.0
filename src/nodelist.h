//
// Created by 18382 on 2021/1/25.
//
#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#ifndef MAIN_CPP_NODELIST_H
#define MAIN_CPP_NODELIST_H
using namespace std;
class node{
public:
    int offset = -1;
    char key[80];
    explicit node(int offset1 = -1, const string& key1 = "");
    node(const node &a);
    node &operator = (const node &a);
};

class square{
public:
    int next = -1;
    int pre = -1;
    int lenth = 0;
    node nodearray[300];
    square();
};


class nodelist{
public:
    char file[100];
    nodelist(const string &a);
    void addnode(node &a);
    void deletenode(node &a);
    void findnode(string key,vector<int>&possibleoffset);
    void merge(int cur1,int cur2);
    void split(int cur);
    int nextsq(int offset);
};
#endif //MAIN_CPP_NODELIST_H
