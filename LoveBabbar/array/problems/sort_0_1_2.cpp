#include<iostream>
using namespace std;

void printArray(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        cout << arr[i]<< " ";
    }
    cout <<endl;
}

void sortArray(int arr[], int n){
   int left = 0;
   int right = n-1;
   while (left < right)
   {
    cout << " left: "<< arr[left]<<endl;
    cout << " right: "<< arr[right]<<endl;

    if(arr[left] < arr[right] ){
        swap(arr[left], arr[right]);
       
    }
        left++;
        right--; 
   }
   
    
}

int main(){
    int arr[6] = {1,0,1,0,1,2};   
    sortArray(arr, 6);
    printArray(arr,6);




    return 1;
}