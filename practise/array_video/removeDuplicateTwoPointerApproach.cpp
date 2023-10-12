#include <iostream>
#include <limits.h>
#include <set>
using namespace std;

void remvoeDuplicateWithPointer(int arr[], int size){
    int a=0;
    int b=1;
    while (b < size)
    {
        if(arr[a] == arr[b] ){
            b++;
            continue;;
        }
        a++;
        arr[a] = arr[b];
        
    }

    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    
    
}

void remvoeDuplicateWithPointerBetter(int arr[], int size){
    int a=0;
    for (int j = 0; j < size; j++)
    {
        if(arr[a] != arr[j]){
            arr[a+1] = arr[j];
            a++;
        }
    }
      for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    
}
int main(){
    int arr[] = {1, 2, 3, 5, 6, 8, 9,9,8,6};
    int size = sizeof(arr) / sizeof(arr[0]);
    // remvoeDuplicateWithPointer(arr, size);
    remvoeDuplicateWithPointerBetter(arr, size);
    return 0;
}