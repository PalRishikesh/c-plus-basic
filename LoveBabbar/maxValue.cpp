#include<iostream>
using namespace std;

int findMaxValue(int arr[], int size){
    int maxValueSoFar = arr[0];
    for (int i = 0; i < size; i++)
    {
       if(arr[i] > maxValueSoFar){
        maxValueSoFar = arr[i];
       } 
    }
    // cout << " Max Value : "<<maxValueSoFar;
    return maxValueSoFar;
}

int main(){
int arr[5] = {1,5,9,8,7};
int maxValue = findMaxValue(arr,5);
cout <<" Max : "<<maxValue;
return 0;
}