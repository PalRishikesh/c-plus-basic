#include <bits/stdc++.h>
using namespace std;

int main(){
int arr[] = {10,20,30,40,50};
   

//

int* ptr1;
int* ptr2;

ptr1 = &arr[0];
ptr2 = &arr[4];

cout <<ptr1<< " "<<ptr2 <<endl;

cout << ptr1 - ptr2<< endl; // ptr subtracing give the lement 


    return 0;
    }
