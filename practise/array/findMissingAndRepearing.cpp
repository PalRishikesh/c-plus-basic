#include <iostream>
#include <set>
using namespace std;

void printTwoElements(int arr[], int size)
{
    int temp[size] = {};
    int repeatingNumber = -1;
    int missingNumber = -1;

    // for (int i = 0; i < size; i++)
    // {
    //     temp[i]=0;
    // }
    //  for (int i = 0; i < size; i++)
    // {
    //     temp[arr[i]-1] = 1;
    // }
    //  for (int i = 0; i < size; i++)
    // {
    //     if(temp[i] == 0){
    //     cout<<" Position: "<<i<<" Value :"<<i+1<<endl;
    //     }
    // }

    for (int i = 0; i < size; i++)
    {
        // Sortest form to assing value 0 and increment
        temp[arr[i] - 1]++;
        if(temp[arr[i] - 1] > 1){
        cout<<" Position: "<<i<<" Repeating Value :"<<arr[i]<<endl;

        }
    }

     for (int i = 0; i < size; i++)
    {
        cout<<" Position: "<<i<<" Value :"<<temp[i]<<endl;
    }
}

int main()
{

    int arr[] = {7, 3, 4, 5, 5, 6, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Size: " << size << endl;
    printTwoElements(arr, size);

    return 0;
}
