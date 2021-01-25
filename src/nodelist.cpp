//
// Created by 18382 on 2021/1/25.
//

#include "nodelist.h"
node::node(const node &a) {
    offset = a.offset;
    strcpy(key,a.key);
}


node::node(int offset1, const string& key1) {
    offset = offset1;
    strcpy(key,key1.c_str());
}

node &node::operator=(const node &a){
    if(this == &a)return *this;
    else {
        offset = a.offset;
        strcpy(key,a.key);
        return *this;
    }
}


square::square() = default;

int nodelist::nextsq(int offset) {
    fstream fin;
    fin.open(file,ios::in|ios::out|ios::binary);
    square tmp;
    fin.seekg(offset);
    fin.read(reinterpret_cast<char*>(&tmp), sizeof(square));
    return tmp.next;
}



nodelist::nodelist(const string &a){
    strcpy(file,a.c_str());
}

//void nodelist::addnode(node &o) {
//    fstream fin,fout;
//    fin.open(file,ios::in | ios :: binary);
//    fout.open(file,ios::in | ios::out | ios::binary);
//    if(!fin || !fout)throw("error");
//    fin.seekg(0,ios::end);
//    int a = fin.tellg();
//    if(a == 0){
//        square square_first;
//        fout.seekp(0);
//        fout.write(reinterpret_cast<char *>(&square_first),sizeof(square));
//    }
//    int cur = 0;
//    int next = nextsq(cur);
//    while(next != -1){
//        square tmp ;
//        fin.seekg(next);
//        fin.read(reinterpret_cast<char *>(&tmp),sizeof(square));
//        if(strcmp(o.key,tmp.nodearray[0].key) < 0){
//            break;
//        }
//        cur = next;
//        next = nextsq(cur);
//    }
//    fin.seekg(cur);
//    square tmp;
//    fin.read(reinterpret_cast<char*>(&tmp),sizeof(square));
//    bool flag = false;
//    int x;
//    fin.seekg(cur);
//    fin.read(reinterpret_cast<char*>(&tmp),sizeof(square));
//    for (int i = 0; i < tmp.lenth; i++) {
//        if (o.key < tmp.nodearray[i].key) {
//            x = i;
//            flag = true;
//            break;
//        }
//    }
//    if(!flag) x = tmp.lenth;
//    for(int i = tmp.lenth; i >= x + 1 ; i--)//递减（防止覆盖）
//    {
//        tmp.nodearray[i] = tmp.nodearray[i - 1];
//    }
//    tmp.nodearray[x] = o;
//    tmp.lenth++;
//    fout.seekp(cur);
//    fout.write(reinterpret_cast<char*>(&tmp),sizeof(square));
//    fin.close();
//    fout.close();
//    if(tmp.lenth >= 300){
//        split(cur);
//    }
//}

void nodelist::addnode(node &a){
    fstream fin,fout;
    fin.open(file,ios::in | ios::binary);
    fout.open(file,ios::in | ios::out | ios::binary);
    if(!fin || !fout)throw"e";
    fin.seekg(0,ios::end);
    int x = fin.tellg();
    if(x == 0){
        square tmp;
        fout.seekp(0);
        fout.write(reinterpret_cast<char*>(&tmp),sizeof(square));
    }
    int cur = 0;
    int next = nextsq(cur);
    while(next != -1){
        square b;
        fin.seekg(next);
        fin.read(reinterpret_cast<char*>(&b),sizeof(square));
        if(strcmp(a.key,b.nodearray[0].key) < 0)break;
        cur = next;
        next = nextsq(cur);
    }
    int p = -1;
    bool flag = false;
    fin.seekg(cur);
    square s;
    fin.read(reinterpret_cast<char*>(&s),sizeof(square));
    for(int i = 0 ; i < s.lenth ; i++)
    {
        if(strcmp(a.key,s.nodearray[i].key) < 0){
            p = i;
            flag = true;
            break;
        }
    }
    if(!flag)p = s.lenth;
    for(int i = s.lenth; i >= p + 1 ; i--)//递减（防止覆盖）
    {
        s.nodearray[i] = s.nodearray[i - 1];
    }
    s.nodearray[p] = a;
    s.lenth++;
    fout.seekp(cur);
    fout.write(reinterpret_cast<char*>(&s),sizeof(square));
    fin.close();
    fout.close();
    if(s.lenth >= 290){
        split(cur);
    }
}

void nodelist::deletenode(node &a) {
    fstream fin,fout;
    fin.open(file,ios::in | ios::binary);
    fout.open(file,ios::in | ios::out | ios::binary);
    if(!fin || !fout)throw"e";
    fin.seekg(0,ios::end);
    int x = fin.tellg();
    if(x == 0){
        return;
    }
    int cur = 0;
    int next = nextsq(cur);
    while(next != -1){
        square b;
        fin.seekg(next);
        fin.read(reinterpret_cast<char*>(&b),sizeof(square));
        if(strcmp(a.key,b.nodearray[0].key) < 0)break;
        cur = next;
        next = nextsq(cur);
    }
    bool flag = true;
    int p ;
        fout.seekg(cur);
        square s;
        fout.read(reinterpret_cast<char*>(&s),sizeof(square));
        for(int i = 0 ; i < s.lenth ; i++)
        {
            if(strcmp(a.key,s.nodearray[i].key) == 0 && a.offset == s.nodearray[i].offset){
                p = i;
                flag = false;
                break;
            }
        }
    if(flag)return;
    for(int i = p ; i <= s.lenth - 2; i++)
    {
        s.nodearray[i] = s.nodearray[i + 1];
    }
    s.lenth--;
    fout.seekp(cur);
    fout.write(reinterpret_cast<char*>(&s),sizeof(square));
    fin.seekg(cur);
    square c;
    fin.read(reinterpret_cast<char*>(&c),sizeof(square));
    next = c.next;
    int nextlen = 0;
    if(next != -1) {
        square az;
        fin.seekg(next);
        fin.read(reinterpret_cast<char *>(&az), sizeof(square));
        nextlen = az.lenth;
    }
    fin.close();
    fout.close();
    if(s.lenth + nextlen <= 280 && next != -1)merge(cur,next);
}


void nodelist::merge(int offset1,int offset2) {
    fstream fin,fout;
    fin.open(file,ios::in | ios::binary);
    fout.open(file,ios::out | ios :: in | ios ::binary);
    if(!fin || !fout)throw("error");
    square square1,square2 ;
    fout.open(file,ios::out | ios :: in | ios ::binary);
    fout.seekg(offset1);
    fout.read(reinterpret_cast<char *>(&square1),sizeof(square));
    fout.seekg(offset2);
    fout.read(reinterpret_cast<char *>(&square2),sizeof(square));
    square1.next = square2.next;
    for(int i = 0 ; i < square2.lenth ; i++){
        square1.nodearray[i + square1.lenth] = square2.nodearray[i];
    }
    square1.lenth += square2.lenth;
    if(square2.next > 0){//还有块
        fin.seekp(square2.next + sizeof(int));//第二块后一块的previous
        fin.write(reinterpret_cast<char *>(&offset1),sizeof(int));
    }
    fin.seekp(offset1);
    fin.write(reinterpret_cast<char *>(&square1),sizeof(square));
    fin.close();
    fout.close();
}


void nodelist::split(int cur) {
    fstream fin,fout;
    fin.open(file,ios::in | ios::binary);
    fout.open(file,ios::out | ios :: in | ios ::binary);
    if(!fin || !fout)throw("error");
    square square1,square2,square_tmp;
    fout.seekg(cur);
    fout.read(reinterpret_cast<char *>(&square_tmp),sizeof(square));
    for(int i = 0 ; i <square_tmp.lenth ; i++)
    {
        if(i < 150 ){
            square1.nodearray[i] = square_tmp.nodearray[i];
        }
        else{
            square2.nodearray[i - 150] = square_tmp.nodearray[i];
        }
    }
    square1.lenth = 150;
    square2.lenth = square_tmp.lenth - 150;
    fin.seekg(0,ios::end);
    int offset2 = fin.tellg();
    if(square_tmp.next >= 0) {
        fout.seekp(square_tmp.next + sizeof(int));
        fout.write(reinterpret_cast<char *>(&offset2), sizeof(int));
    }
    square2.next = square_tmp.next;
    square2.pre = cur;
    square1.next = offset2;
    square1.pre = square_tmp.pre;
    fout.seekp(cur);
    fout.write(reinterpret_cast<char*>(&square1),sizeof(square));
    fout.seekp(offset2);
    fout.write(reinterpret_cast<char *>(&square2),sizeof(square));
    fin.close();
    fout.close();
}



void nodelist::findnode(string key,vector<int>&possibleoffset) {
    fstream fin,fout;
    fin.open(file,ios::in | ios::out | ios::binary);
    fout.open(file,ios::in | ios::out | ios::binary);
    if(!fin || !fout)throw"e";
    fin.seekg(0,ios::end);
    int x = fin.tellg();
    if(x == 0){
        square tmp;
        fout.seekp(0);
        fout.write(reinterpret_cast<const char *>(&tmp), sizeof(square));
        fout.close();
        return;
    }
    square tmp;
    int cur = 0;
    fin.seekg(cur);
    fin.read(reinterpret_cast<char*>(&tmp),sizeof(square));
    int next = tmp.next;
    int pre = 0;
    while(next != -1){
        square b;
        fin.seekg(next);
        fin.read(reinterpret_cast<char*>(&b),sizeof(square));
        if(strcmp(key.c_str(),b.nodearray[0].key) < 0)break;
        fin.seekg(cur);
        fin.read(reinterpret_cast<char*>(&b),sizeof(square));
        if(strcmp(key.c_str(),b.nodearray[0].key) > 0)pre = cur;
        cur = next;
        square tmp1;
        fin.seekg(cur);
        fin.read(reinterpret_cast<char*>(&tmp1),sizeof(square));
        next = tmp1.next;
    }
    while(true){
        fout.seekg(pre);
        square s;
        fout.read(reinterpret_cast<char*>(&s),sizeof(square));
        for(int i = 0 ; i < s.lenth ; i++)
        {
            if(strcmp(key.c_str(),s.nodearray[i].key) == 0){
                possibleoffset.push_back(s.nodearray[i].offset);
            }
        }
        if(pre == next)break;
        pre = s.next;
    }
    fin.close();
    fout.close();
}