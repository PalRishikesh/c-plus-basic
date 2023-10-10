#include<iostream>
#include<set>
using namespace std;

int elementNaive(int arr[], int size){
    for (int i = 0; i < size; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if(arr[i] == arr[j]){
                return i;
            }
        }
        
    }
    return -1;
    
}

int elementWithSet(int arr[], int size){
    int find=0;
    set<int> mySet;
    for (int i = 0; i < size; i++)
    {
       if(mySet.find(arr[i]) != mySet.end()){
        find = i;
       }
       else{
        mySet.insert(arr[i]);
       }
        
    }
    return find;
    
}
int main(){

    int arr[] = {10, 8, 4, 3, 5, 6};
    int size = sizeof(arr)/sizeof(arr[0]);
    // int findElement = elementNaive(arr,size);
    int findElement = elementWithSet(arr,size);
    if(findElement){
        cout<<" Found element at position at :"<<findElement;
    }
    else{
        cout<<" Not found"<<endl;
    }
    return 1;
}

