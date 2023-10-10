#include<iostream>
using namespace std;
int findMissingNumber(int arr[], int size){
    int tempArray[size+1];
    int ans;
    // Initialize all value to 0 in Temp Array
    for (int i = 0; i < size+1; i++)
    {
        tempArray[i]=0;
    }
    // Initialize all value to 1
    for (int i = 0; i < size; i++)
    {
        tempArray[arr[i]-1]=1;
    }
    for (int i = 0; i < size+1; i++)
    {
        if(tempArray[i] == 0){
            return ans = i+1;
           
        }
    } 

    
}

int missingNoWithSum(int arr[], int size){
    int N = size + 1;
    int total = (N)*(N+1)/2;
    for (int i = 0; i < size; i++)
    {
        total -=arr[i];
    }
    cout<<"total: "<<total<<endl;
    return total;
}
int missingNoWithTotalAnd2(int arr[], int size){
    int total = 1;
    for (int i = 2; i < size+1 ; i++)
    {
        total +=i;
        total -= arr[i-2];
    }
    cout<<"total: "<<total<<endl;
    return total;
}
int main(){
    int arr[] = {1,3};
    int size = sizeof(arr)/sizeof(arr[0]);
    int misingValue;
    // misingValue = findMissingNumber(arr,size);
    // misingValue = missingNoWithSum(arr,size);
    misingValue = missingNoWithTotalAnd2(arr,size);
    cout<<"Missing Value is : "<<misingValue<<endl;
    
    return 1;
}