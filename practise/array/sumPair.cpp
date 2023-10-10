#include<iostream>
using namespace std;

void findSumPair(int arr[], int size, int value){
    for (int i = 0; i < size; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if(arr[i] + arr[j] == value){
                cout<<"Value: "<<arr[i]<<" "<<arr[j]<<" Key: "<<i<<" "<<j<<endl;
            }
        }
        
    }
    
}
int main(){
    int arr[] = {1,3,4,5,6,8,9,10};
    int size = sizeof(arr)/sizeof(arr[0]);

    int val = 15;
    findSumPair(arr,size, val);
    return 1;
}