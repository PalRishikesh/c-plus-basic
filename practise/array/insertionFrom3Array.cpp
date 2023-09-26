#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> mergeTwoArrayWithNaive(int arr1[], int arr2[], int size1, int size2)
{
    vector<int> mergeVector;

    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            if (arr1[i] == arr2[j])
            {
                mergeVector.push_back(arr1[i]);
            }
        }
    }
    return mergeVector;
}
vector<int> mergeTwoArrayWithNaiveWith3D(int arr1[], int arr2[], int arr3[], int size1, int size2, int size3)
{
    vector<int> mergeVector;

    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            for (int k = 0; k < size3; k++)
            {
                if (arr1[i] == arr2[j] && arr1[i] == arr3[k])
                {
                    mergeVector.push_back(arr1[i]);
                }
            }
        }
    }
    return mergeVector;
}


int main()
{
    int arr1[] = {1, 2, 3, 4, 5, 8};
    int arr2[] = {2, 3, 5, 6, 8};
    int arr3[] = {2, 3, 4, 6, 7};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    vector<int> mergeArray;
    vector<int> mergeArray3;
    for (int i : arr1)
    {
        cout << i << " ";
    }
    cout << endl;
    // mergeArray = mergeTwoArrayWithNaive(arr1, arr2, size1, size2);
    // for (int i = 0; i < mergeArray.size(); i++)
    // {
    //     cout << mergeArray[i] << " ";
    // }
    // cout << endl;
    // mergeArray3 = mergeTwoArrayWithNaiveWith3D(arr1, arr2, arr3, size1, size2, size3);
    // for (int i = 0; i < mergeArray3.size(); i++)
    // {
    //     cout << mergeArray3[i] << " ";
    // }
    

    return 1;
}