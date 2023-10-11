#include<iostream>
using namespace std;

void naiveFindClosestZero(int arr[], int size){
    int num1 = arr[0];
    int num2 = arr[1];
    int smallValue = arr[0] + arr[1];

    for (int i = 0; i < size-1; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if(abs(arr[i] +arr[j]) < abs(smallValue)){
                smallValue = arr[i]+ arr[j];
                num1 = arr[i];
                num2 = arr[j];
            }
        }
        
    }
    cout<<" Value : "<<smallValue<<" Num 1: "<<num1<<" Num 2: "<<num2<<endl;
}

int main(){

    int arr[]= {1,60,-10,70,-80,85};
    int size = sizeof(arr)/sizeof(arr[0]);
    naiveFindClosestZero(arr, size);
    return 0;
}