#include<iostream>
using namespace std;



bool searchValue (int arr[], int size, int value){

    for (int i = 0; i < size; i++)
    {
        if(arr[i] == value){
            return 1;
        }
    }
    return 0;
    
}

int main(){
    // 1 is present or not
   int arr[10]= {5,7,-2,10,22,-2,0,5,22,1};
    
    

    cout << " Enter the element to search for "<<endl;
    int searchKey;
    cin >> searchKey;

    bool isFound = searchValue(arr,10,searchKey);

    if(isFound){
        cout << " Key is present "<<endl;
    }
    else{
        cout << "Key is not present"<<endl; 
    }
    return 0;
   }