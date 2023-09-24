#include<iostream>
using namespace std;

void printArray(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        cout << arr[i]<<" ";
    }
    cout<< endl;
}

void sumSubArrayMax(int arr[], int n){
    int bag = 0;
   int max = arr[0];
   for (int i = 1; i < n; i++)
   {
    bag += arr[i];
    if(bag > max){
        max = bag;
    }
    if(bag < 0){
        bag =0;
    }
   }
   cout <<"Max:"<<max<<endl;
   

    
}


int main(){

    int arr[6] = {-15,-3,-5,-1,-10,-4};
    // printArray(arr,6);

    sumSubArrayMax(arr,6);
    // printArray(arr,6);

    return 0;
}