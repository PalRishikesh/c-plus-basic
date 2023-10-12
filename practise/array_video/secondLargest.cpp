#include<iostream>
#include <limits.h>
using namespace std;

void findSecondLargest(int arr[], int size){
    int large =  INT_MIN;
    int secondLarge =  INT_MIN;
    for (int i = 0; i < size; i++)
    {
        if(arr[i] > large){
            secondLarge = large;
            large = arr[i];
        }
        else if(arr[i] > secondLarge && large != arr[i] ){
            secondLarge = arr[i];
        }
    }
    cout<<" Large value is "<<large << " 2nd Large "<<secondLarge;
}
int main(){

    int arr[] = {1,5,5,5,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    // Better take 2 loop
    // findSecondLargest(arr, size);
    return 0;
}

// int sLargest(vector<int> a, int n){
//     int largest = a[0];
//     int secondLargest = INT_MIN;
//     for(int i=1;i < n;i++){
//         if(a[i] > largest){
//             secondLargest = largest;
//             largest = a[i];
//         }
//         else if(a[i]> secondLargest){
//             secondLargest = a[i];
//         }
//     }
//     return secondLargest;
// }
// int sSmallest(vector<int> a, int n){
//     int smallest = a[0];
//     int secondSmallest = INT_MAX;
//     for(int i=1;i < n;i++){
//         if(a[i] < smallest){
//             secondSmallest = smallest;
//             smallest = a[i];
//         }
//         else if(a[i] < secondSmallest){
//             secondSmallest = a[i];
//         }
//     }
//     return secondSmallest;
// }

// vector<int> getSecondOrderElements(int n, vector<int> a) {
//     int secondLargestValue = sLargest(a,n);
//     int secondSmallestValue = sSmallest(a,n);
//     return {
//         secondLargestValue,
//         secondSmallestValue
//     };
// }
