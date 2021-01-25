#include <iostream>
#include <iostream>
#include "BookStore.h"
using namespace std;
int main() {
    initialize();
    string command;
    while(getline(cin,command)){
        try{
            Run_Program(command);
        }catch (...){
            cout<<"Invalid\n";
        }
    }
    return 0;
}