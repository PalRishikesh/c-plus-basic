#include<iostream>
using namespace std;

// Without pointer
// void fun(int &x){
//     x=50;
//     cout <<x <<endl; // 50
// }

// int main(){
//     int x=20;
//     fun(x);
//     cout <<x<<endl; // 20

//     return 0;
//     }

// With pointer
// void fun(int *x){
//     *x=50;
//     cout <<*x <<endl; // 50
// }

// int main(){
//     int x=20;
//     fun(&x);
//     cout <<x<<endl; // 20

//     return 0;


void fun(int arr[5]){
    arr[0]=10;
}

int main(){
    int arr[5]={20,30,40,50,60};
    fun(arr);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i]<< " ";
    }
    

    return 0;


    }
