#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

void printArray(int arr[], int size){
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}
int rotateOneLeft(int arr[], int size){
    int tempArrayFirstValue = arr[0];
    for (int i = 1; i < size; i++)
    {
        arr[i-1] = arr[i];
    }
    arr[size-1] = tempArrayFirstValue;
    // return arr;
    printArray(arr, size);
    
}
int main(){
    int arr[] = {1, 2, 3, 5, 6, 8, 9,9,8,6};
    int size = sizeof(arr) / sizeof(arr[0]);
    rotateOneLeft(arr, size);    
   

    return 0;
}