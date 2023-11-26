#include <iostream>
#include <bits/stdc++.h>
#include<map>
using namespace std;

int majoritiyElement(int arr[],int size){
    map<int,int>mpp;
    for (int i = 0; i < size; i++)
    {
        // Assing key with value increment in map short form...
        mpp[arr[i]]++;
    }
    for(auto it: mpp){
        cout<<it.first<<" "<<it.second<<endl;
    }

}

int main(){
    int arr[] = {2,2,5,8,9,2,2,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    majoritiyElement(arr, size);
    return 0;
}

