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
int main(){
    int arr[] = {1,3,4,5,6,8,9,10};
    int size = sizeof(arr)/sizeof(arr[0]);
    int misingValue;
    misingValue = findMissingNumber(arr,size);
    cout<<"Missing Value is : "<<misingValue<<endl;
    
    return 1;
}