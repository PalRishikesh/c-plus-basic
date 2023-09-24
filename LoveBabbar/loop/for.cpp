#include<iostream>
using namespace std;

int main(){

    int n;
    cout << "Enter the value of n"<<endl;
    cin>>n;

    cout<<"Pring count from 1 to n "<<endl;

    // for(int i=1; i<=n;i++){
    //     cout <<i<<endl;
    // }

    //Optional
    // int i=1;
    //  for(; ;){
    //     if(i<=n){
    //     cout <<i<<endl;
    //     }
    //     else{
    //         break;
    //     }
    //     i++;
    // }


    // Multiple 
    //  for(int a=0, b=1, c= 2; a>=0, b>=1, c<=2;a--,b--,c++){
    //     cout <<a << " " <<b<<" "<<c<<endl;
    // }

    int sum=0;
    for(int i=1; i<=n;i++){
        sum +=i;
    }
    cout <<sum<<endl;
}