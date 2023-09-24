#include<iostream>
using namespace std;

void printArray(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        cout << arr[i]<<" ";
    }
    cout<< endl;
}

void removeDuplicate(int arr[], int n){
    int index = 1;

   for (int i = 1; i < n; i++)
   {
     if(arr[i] != arr[index]){
        index++;
        arr[index] = arr[i];
     }
   }
   
   cout <<" Arry length : "<<index+1;

   cout <<endl;
   
    
}


int main(){

    int arr[6] = {1,2,2,3,3,5};
    removeDuplicate(arr,6);
    printArray(arr,6);
    return 0;
}