#include<iostream>
using namespace std;

int main(){


    int n;
    cin>>n;
    int i=1;
    int sum=0;
    // while(i<=n){
    //    sum =sum+i;
    //    i = i+2;
    //    cout <<i<<endl;
    // }
     while(i<=n){
        if(i%2 == 0){
         sum =sum+i;
        }
       i = i++;
       cout <<i<<endl;
    }
    cout <<" The Sum is : "<<sum<<endl;

}
