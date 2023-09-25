#include <iostream>
using namespace std;

int findPosition(int arr[], int size, int value)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == value)
        {
            return i;
        }
    }
    return -1;
}
int deleteUnsorted(int arr[], int size, int value)
{
    int position = findPosition(arr, size, value);
    cout << "Position :" << position << endl;
    for (int i = position; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    return size - 1;
}
int main()
{

    int arr[] = {1, 5, 9, 8, 2, 3, 4};
    int deleteValue = 8;
    int size = sizeof(arr) / sizeof(arr[0]);
    int newSize;
    cout << "\nBefore deleting array" << endl;
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    newSize = deleteUnsorted(arr, size, deleteValue);
    cout << "\nAfter deleting array" << endl;
    for (int i = 0; i < newSize; i++)
    {
        cout << arr[i] << " ";
    }
    return 1;
}