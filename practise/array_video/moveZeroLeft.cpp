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

void moveZeroRight(int arr[], int size)
{
    vector<int> tempArray;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] != 0)
        {
            tempArray.push_back(arr[i]);
        }
    }
    int tSize = tempArray.size();
    for (int i = 0; i < tSize; i++)
    {
        arr[i] = tempArray[i];
    }
    for (int i = tSize; i < size; i++)
    {
        arr[i] = 0;
    }
}
void moveZeroRightOptimal(int arr[], int size)
{
    int j = -1;
    for (int i = 0; i < size; i++)
    {
        if(arr[i] == 0){
            j = i;
            break;
        }
    }
    for (int i = j+1 ; i < size; i++)
    {
       if(arr[i] !=0){
        swap(arr[i],arr[j]);
        j++;
       }
    }
   
    
}
int main()
{
    int arr[] = {1, 2, 0, 0, 6, 8, 9, 0, 8, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    // moveZeroRight(arr, size);
    moveZeroRightOptimal(arr, size);
    printArray(arr, size);
    return 1;
}