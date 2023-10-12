#include <iostream>
#include <limits.h>
using namespace std;

bool isSorotedArray(int arr[], int size)
{

    // for (int i = 0; i < size-1; i++)
    // {
    //     if(arr[i] >= arr[i+1]){

    //         return false;

    //     }
    // }
    for (int i = 1; i < size ; i++)
    {
        if (arr[i-1] >= arr[i])
        {

            return false;
        }
    }

    return true;
}

int main()
{
    int arr[] = {1, 2, 3, 5, 6, 8, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    bool isSoroted = isSorotedArray(arr, size);

    cout << "Array is sorted : " << isSoroted << endl;
    return 0;
}