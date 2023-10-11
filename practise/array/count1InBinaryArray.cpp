#include <iostream>
using namespace std;

int naiveCount(int arr[], int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == 1)
        {
            count++;
        }
        else
        {
            break;
        }
    }
    return count;
}
int binaryCount(int arr[], int low, int high)
{

    if (high >= low)
    {
        int mid = low + (high - low) / 2;
        cout << "Low: " << low << " High: " << high << " Mid: " << mid << endl;
        if ((mid == high && arr[mid] == 1) || arr[mid] == 1 && arr[mid + 1] == 0)
        {
            return mid + 1;
        }
        if (arr[mid] == 1)
        {
            return binaryCount(arr, (mid + 1), high);
        }
        return binaryCount(arr, low, (mid - 1));
        return mid;
    }

    return 0;
}

int binaryCountIteratively(int arr[], int low, int high, int size)
{
    while (low < high)
    {
        int mid = (low + high)/2;
        if(arr[mid] < 1){
            high = mid -1;
        }
        else if(arr[mid] > 1){
            low = mid+1;
        }
        else{
            if(mid == size-1 || arr[mid+1] !=1){
                return mid+1;
            }
            else{
                low = mid +1;
            }
        }
    }
    
}
int main()
{
    int arr[] = {1, 1, 1, 1, 1, 0, 0};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Size: " << size << endl;
    // int counts = naiveCount(arr, size);
    // int counts = binaryCount(arr, 0, size - 1);
    int counts = binaryCountIteratively(arr, 0, size - 1, size);
    cout << " Count is " << counts;

    return 0;
}