#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

// int rotateOneLeft(int arr[], int size, int rotateNumber)
// {
//     vector<int> tempArray;
//     for (int i = 0; i < rotateNumber; i++)
//     {
//        tempArray.push_back(arr[i]);
//     }
    
//     for (int i = rotateNumber; i < size - rotateNumber; i++)
//     {
//         arr[i- rotateNumber] = arr[i];
//     }

//     // int a=0;
//     // for (int j = size - rotateNumber; j < size; j++)
//     // {
//     //     arr[j]=tempArray[a];
//     //     a++;
//     // }
//     for (int j = size - rotateNumber; j < size; j++)
//     {
//         arr[j]=tempArray[j - (size - rotateNumber)];
//     }
//     printArray(arr, size);
    
// }
void reverse(int arr[],int i,int j){
    // int i=0;
    // int j=arr.size()-1;

    while(i<j){
        swap(arr[i],arr[j]);
        i++;
        j--;
    }
}

void rotateWithReverse(int arr[], int n, int d){
    reverse(arr, 0, d);
    reverse(arr, d, n);
    reverse(arr, 0,n);
    printArray(arr, n);
}

int main()
{
    int arr[] = {1, 2, 3, 5, 6, 8, 9, 10, 8, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    int rotateNumber = 3;
    // rotateOneLeft(arr, size, rotateNumber);

    // reverse(a, a+d);
    // reverse(a+d,n);
    // reverse(a,n)

    rotateWithReverse(arr, size , rotateNumber);
    return 0;
}
// Use right rotate