#include <iostream>
using namespace std;

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int findUniqueArray(int arr[], int size)
{
    int ans = 0;
    for (int i = 0; i < size; i++)
    {
        ans = ans ^ arr[i];
    }
    return ans;
}

int main()
{

    int arr[9] = {5, 7, 7, 8, 5, 8, 1, 1, 11};

    int ans = findUniqueArray(arr, 9);
    // printArray(arr,9);
    cout << "ANS :" << ans << endl;
    return 0;
}