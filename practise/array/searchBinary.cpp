#include <iostream>
using namespace std;

int binarySearch(int arr[], int low, int high, int value)
{

    while (low <= high)
    {
        int mid = (low + high ) / 2;
        cout << "Mid: " << mid << endl;
        cout << "Low: " << low << " High: " << high << endl;
        // low++;
        // high--;
        if (arr[mid] == value)
        {
            return mid;
        }
        if (value > arr[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int arr[] = {1, 3, 4, 5, 8, 9, 15, 20};
    int x = 15;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, 0, n-1, x);
    cout << "\nFound at value : " << result << endl;
}