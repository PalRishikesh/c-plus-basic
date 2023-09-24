#include<iostream>
using namespace std;

int findDuplicate(vector<int> &arr) 
{
        int ans=0;

    for(int i=0; i < arr.size();i++){
        ans =ans ^ arr[i];
    }

    for(int i=1; i < arr.size();i++){
        ans =ans ^ i;
    }
    return ans;
	
}




int main(){

    int arr[6]={1,4,0,5,-2,15};
    int brr[5] = {2,6,3,9,4};



    return 0;
}