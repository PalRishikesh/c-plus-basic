#include <iostream>
#include <limits.h>
#include <set>
using namespace std;

void remvoeDuplicateWithSet(int arr[], int size){
    set<int> mySet;
    int index = 0;
    for (int i = 0; i < size; i++)
    {
        mySet.insert(arr[i]);
    }

    for(auto it: mySet){
        
        arr[index] = it;
        index++;
    }

    for (int i = 0; i < mySet.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    
    
}

int main(){
    int arr[] = {1, 2, 3, 5, 6, 8, 9,9,8,6};
    int size = sizeof(arr) / sizeof(arr[0]);
    remvoeDuplicateWithSet(arr, size);
    return 0;
}