#include<iostream>
#include<string>
using namespace std;

int main(){
    int arr[]= {4,6,2,1,7};
    int arr2[5];
    char arr3[]={'A','C','@','#'};
    // cout<<"Using for lpoop"<<endl;

    // for(int i=0;i<5;i++){
    //     cout << arr[i]<<" ";
    // }

    // cout<<endl<<"Using for lpoop"<<endl;
    // for(int element:arr){
    //     cout <<element<<" ";
    // }

    // for(int element:arr2){
    //     cin>>element;
    // }

    // int customArraySize = sizeof(arr)/sizeof(int);
    int customArraySize = sizeof(arr3)/sizeof(char);
    cout <<" Size is "<<customArraySize<<endl;
  for(int i=0;i< customArraySize;i++){
        // cout << arr[i]<<" ";
        cout << arr3[i]<<" ";
    }
    
    return 0;
    }
