#include<iostream>
#include<set>

using namespace std;
void unionWithSet(int arr1[], int arr2[], int size1, int size2)
{
    set<int> mergeSet;
    for (int i = 0; i < size1; i++)
    {
        mergeSet.insert(arr1[i]);
    }
    for (int i = 0; i < size2; i++)
    {
        mergeSet.insert(arr2[i]);
    }
    for (auto i : mergeSet)
    {
        cout << i << " ";
    }
}

int main(){
      int arr1[] = {1, 2, 3, 4, 5, 8};
    int arr2[] = {2, 3, 5, 6, 8};
    int arr3[] = {2, 3, 4, 6, 7};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    unionWithSet(arr1, arr2, size1, size2);
    return 0;
}