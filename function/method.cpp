#include<iostream>
using namespace std;

void fun(int a){
    cout<<"Hello"<<endl;
}

int fun(double a){
    cout << "Good Morning";
    return a;
}
int main(){
    fun(3); // Hello
    fun(3.0); // Good Morning
    return 0;
    
}