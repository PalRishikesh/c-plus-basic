#include<iostream>
#include<string>
using namespace  std;
int main(){
    int n=7;
    if(n%3==0){ // Will return false (1), than whole if statment will be ignore
        if(n<5){
            cout << "A"<<endl;
        }
        else if(n<10){
            cout << "B"<<endl;
        }
    }
    if(n%2 ==0 ){ // will return false (1) than whole if statment will be ignore
            cout << "C"<<endl;
    }
    else{
        if(n%5==2){ // Will return true (2) and will exectute
            cout << "D"<<endl;
        }
        else if(n==7){ // Altough this is also true but once if statement is execture else part will be ignore
            cout << "E"<<endl;
        }
        else{ // Ignore by default else part
            cout << "F"<<endl;
        }
    }


    return 0;
}