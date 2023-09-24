#include <iostream>
#include <math.h>
using namespace std;

void printArray(int arr[],int size)
{
    cout << " printing the array"<< endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
    cout << " printing Done !!!"<< endl;

}

int main()
{

    int arr[100] = {0}; // This will only work with 0 values
    int arrCustomValue[100];
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    int arrSizeCustom = sizeof(arrCustomValue) / 4;
    // cout << arrSize<<endl ;
    // cout << sizeof(arr)<<endl ;
    // cout << sizeof(arr[0])<<endl ;
    // cout << arrSizeCustom<<endl ;
    // for (int i = 0; i < arrSize; i++)
    // {
    //    cout << arr[i];
    // }

    // Defining custom value for each element in array
    // for (int i = 0; i < arrSizeCustom; i++)
    // {
    //    arrCustomValue[i]=5;
    // }

    // for (int i = 0; i < arrSizeCustom; i++)
    // {
    //    cout << arrCustomValue[i];
    // }

    int thirdArray[15] = {2, 7};
    int n = 15;
    int thirdSize = sizeof(thirdArray)/sizeof(int);
    // cout << sizeof(thirdArray)<< endl;
    // Other value take a zero
    // for (int i = 0; i < n; i++)
    // {
    //     cout << thirdArray[i] << endl;
    // }

    // Printing from function
    // printArray(thirdArray,thirdSize);

    //

    char ch[5] = {'a','b','c','p'}; 
    cout << ch[3];
    double firstDouble[5];
    float firstFloat[5];
    bool firstBool[2];

    }