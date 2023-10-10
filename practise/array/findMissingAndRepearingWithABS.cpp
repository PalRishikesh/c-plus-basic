#include <iostream>
#include <set>
using namespace std;

void printTwoElements(int arr[], int size)
{
    cout << "The Repeating Number " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << abs(arr[i]) << " ";
    }
    cout << endl;

    // By this loop making chaning current position with index value
    for (int i = 0; i < size; i++)
    {
        cout << arr[abs(arr[i]) - 1] << " ";
    }

    cout << endl;

    for (int i = 0; i < size; i++)
    {

        // cout<<"\nAA: "<<arr[abs(arr[i])-1] <<" AA:"<<endl;
        if (arr[abs(arr[i]) - 1] > 0)
        {
            // cout<<"-- "<<arr[abs(arr[i])-1]<<"--"<<endl;
            // It alway making value as negative (-1) for next
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
        }
        else
        {
            cout << " Value  " << abs(arr[i]) << endl;
        }
    }

    // For self checking
    for (int i = 0; i < size; i++)
    {
        cout << "\n Value " << arr[i] << " ";
    }
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > 0)
        {
            cout << "\n Missing Value" << (i + 1);
        }
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
