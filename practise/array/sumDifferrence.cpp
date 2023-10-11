#include<iostream>
using namespace std;

void findPair(int arr[], int size, int value){
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if( i == j){
                continue;
            }
            if(arr[i] - arr[j] == value){
                cout<<"Value : "<<value<<" 1: "<<arr[i]<<" 2: "<<arr[j]<<endl;
            }
        }
        
    }
    
}

void findPairBinary(int arr[], int size, int value){
    int i=0;
    int j=0;
    while (i < size && j < size)
    {
        if(i!=j && (arr[j] - arr[i] == value || arr[i] - arr[j] == value)){
            cout<<" Pair found "<<arr[i]<<", "<<arr[j]<<endl;
            j++;
            i++;
        }
        else if(arr[j] - arr[i] < value){
            j++;
        }
        else{
            i++;
        }
    }
    
}
int main(){
    
    int arr[] = { 1, 8, 30, 40, 100 };
    int n = sizeof(arr)/sizeof(arr[0]);
    int diff = -60;
       
      // Function call
    // findPair(arr, n, diff);
    findPairBinary(arr, n, diff);
    return 0;
}