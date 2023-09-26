#include<iostream>
#include<vector>
#include<map>

using namespace std;
vector<int> unionWithMap(int arr1[], int arr2[], int size1, int size2)
{
   map<int,int> mapData;
   for (int i = 0; i < size1; i++)
   {
        if(mapData.find(arr1[i]) != mapData.end()){
            mapData[arr1[i]]++;
        }
        else{
            mapData[arr1[i]]=1;
        }
   }
    for (int i = 0; i < size2; i++)
   {
        if(mapData.find(arr2[i]) != mapData.end()){
            mapData[arr2[i]]++;
        }
        else{
            mapData[arr2[i]]=1;
        }
   }

    vector<int> list;
   for(auto i:mapData){
    // cout<<i.first<<" ";
    list.push_back(i.first);
   }
   return list;
   
}

int main(){
      int arr1[] = {1, 2, 3, 4, 5, 8,8,4,5};
    int arr2[] = {2, 3, 5, 6,7, 8};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    vector<int> uni = unionWithMap(arr1, arr2, size1, size2);
    for(auto i:uni){
        cout<<i<<" ";
    }
    return 0;
}