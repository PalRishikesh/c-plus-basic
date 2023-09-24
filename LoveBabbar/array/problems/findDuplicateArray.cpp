#include<iostream>
using namespace std;
// https://leetcode.com/problems/find-all-duplicates-in-an-array/
 vector<int> findDuplicateArray(int arr[], int size) 
{
    int ans=0;
//   std::vector< int > arr;

    vector<int> vectorArray;
    for(int i=0; i < size; i++){
        for (int j = i+1; j < size; j++)
        {
            if(arr[i] == arr[j]){
                cout << arr[i]<<" "; 
                vectorArray.push_back(arr[i]);
            }
        }
        
    }

    // for(int i=1; i < arr.size();i++){
    //     ans =ans ^ i;
    // }
    // return ans;
	return 1;
}




int main(){

    int arr[6]={1,2,1,3,4,3};
    vector<int>  ans = findDuplicateArray(arr,6);
    // cout<< "ANs: "<<ans<<endl;

    return 0;
}