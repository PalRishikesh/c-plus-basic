#include <iostream>
using namespace std;

int insertValue(int arr[], int n, int key, int capacity)
{
    if (n >= capacity)
    {
        return n;
    }
    arr[n] = key;
    return (n + 1);
}

int insertElement(int arr[], int n, int x, int pos)
{
    for (int i = n - 1; i >= pos; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[pos] = x;
    return n + 1;
}
int insertSorted(int arr[],int n, int key, int capacity){
    int currentPosition = n;
    if(n>=capacity){
        return n;
    }
    for (int i = n-1; i >= 0 && arr[i] > key; i--)
    {
        cout<<arr[i]<<" ";
        currentPosition--;
        arr[i+1]=arr[i];
    }
    arr[currentPosition]=key;
    cout<<endl<<"Current Position "<<currentPosition<<endl;
    return n+1;
    
}
// int main()
// {

//     int arr[20] = {10, 15, 20, 25, 30, 40, 50};
//     int capacity = sizeof(arr) / sizeof(arr[0]);
//     cout << sizeof(arr) << endl;
//     cout << sizeof(arr[0]) << endl;
//     cout << "Capacity: " << capacity << endl;

//     int n = 7, m;
//     int i, key = 26;

//     cout << "\nBefore Insertion" << endl;
//     for (i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//     }

//     m = insertValue(arr, n, key, capacity);
//     cout << "\nAfter Insertion" << endl;
//     for (i = 0; i < m; i++)
//     {
//         cout << arr[i] << " ";
//     }

//     return 1;
// }
// int main()
// {

//     int arr[20] = {10, 15, 20, 25, 30};
//     int i,m,n = 5;
//     int x=10, pos = 2;
//     cout << "\nBefore Insertion" << endl;
//     for (i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout<<endl;
//     m = insertElement(arr, n, x, pos);
//     cout << "\nAfter Insertion" << endl;
//     for (i = 0; i < m; i++)
//     {
//         cout << arr[i] << " ";
//     }

//     return 1;
// }


int main()
{

    int arr[20] = {10, 15, 20, 25, 30, 40, 60, 70};
    int capacity = sizeof(arr) / sizeof(arr[0]);
    int n = 8;
    int i,m, key = 26;

    cout << "\nBefore Insertion" << endl;
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    m = insertSorted(arr, n, key, capacity);

    cout << "\nAfter Insertion" << endl;
    for (i = 0; i < m; i++)
    {
        cout << arr[i] << " ";
    }

    return 1;
}