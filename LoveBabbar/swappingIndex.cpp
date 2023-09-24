#include<iostream>
using namespace std;

void printArray(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        cout << arr[i]<<" ";
    }
    cout<< endl;
}

void sortingIndexing(int arr[], int n){

   for (int i = 0; i < n; i++)
   {
    //  cout<<arr[i]<< " ";
    //  swap(arr[arr[i]])
    if(arr[i] !=i){
    swap(arr[arr[i]],arr[i]);
        i--;
    }
   }
   cout <<endl;
   

    
}


int main(){

    int arr[6] = {0,3,5,1,2,4};
    printArray(arr,6);

    sortingIndexing(arr,6);
    printArray(arr,6);

    return 0;
}