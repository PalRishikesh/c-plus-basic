#include<iostream>
using namespace std;

void printArray(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        cout<< arr[i] <<" ";
    }
    cout<<endl;
    
}


void customSwap(int arr[],int arrValue1, int arrValue2, int position1){
    int temp  = arrValue2;
    arr[position1 + 1] = arrValue1;
    arr[position1] = temp; 
}

void swapAlternate(int arr[], int size){
    for (int i = 0; i < size; i+=2)
    {
        if(i+1 < size){
            // swap(arr[i],arr[i+1]);
            customSwap(arr,arr[i],arr[i+1], i );
        }
    }
    
}

int main(){

    int even[8]= {5,2,9,4,7,6,1,0};
    int odd[5] = {11,33,9,76,43}; 

swapAlternate(even,8);
swapAlternate(odd,5);
printArray(even,8);
printArray(odd,5);

    return 0;
}