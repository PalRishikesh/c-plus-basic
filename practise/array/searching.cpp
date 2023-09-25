#include <iostream>
using namespace std;

int findElement(int arr[], int n, int key){
    int i;
    for ( i = 0; i < n; i++)
    {
        if(arr[i] == key){
            return i;
        }
    }
    return -1;
    
}
int binarySearch(int arr[], int key, int low, int high){
    int mid = (low + high)/2;
    // cout<<"Low High "<<low<<" "<<high<<endl;
    // cout<<"Mid is "<<mid<<endl;
    if(high < low){
        return -1;
    }
    if(arr[mid] == key){
        // cout<<" Found value at index : "<<mid<<endl;
        return mid;
    }
    if(key > arr[mid]){
        return binarySearch(arr, key, mid+1, high);
    }
    else{
        return binarySearch(arr,key,low, high-1);
    }

    return 1;
}


// int main(){
//     int arr[] = {12,13,5,16,10};
//     int n= sizeof(arr)/sizeof(arr[0]);
//     int key = 13;

//     int valuePosition = findElement(arr,n,key);
//     if(valuePosition){
//         cout<<" Value is present at position :"<<valuePosition<<endl;
//     }
//     else{
//         cout<<" Value is not present"<<endl;
//     }
//     return 0;
// }

int main(){
    int arr[] = {2,5,6,8,9,10,11,13};
    int n= sizeof(arr)/sizeof(arr[0]);
    int key = 6;
    int low = 0;
    int high = n-1;
    cout<<"Size: "<<n<<endl;
    int valuePosition = binarySearch(arr,key,low,high);
    if(valuePosition){
        cout<<"Value is present at position :"<<valuePosition<<endl;
    }
    else{
        cout<<"Value is not present"<<endl;
    }
    return 0;
}