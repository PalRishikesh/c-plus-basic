#include<iostream>
#include<climits>
using namespace std;

// NextLeap
// int secondLargest(vector<int>& nums) {
// 		int maxElement = nums[0];
// 		int n = nums.size();
// 		for(int i=0;i<n;i++){
// 			if(nums[i] > maxElement) maxElement = nums[i];
// 		}
		
// 		int secondMax = INT_MIN;
// 		for(int i=0;i<n;i++){
// 			if(nums[i] == maxElement) continue;
// 			if(nums[i] > secondMax) secondMax = nums[i];
// 		}

// 		return secondMax;
// 	}


int findMaxValue(int arr[], int size){
    int maxValue, secondMaxValue;
    if(arr[0] > arr[1]){
        maxValue = arr[0];
        secondMaxValue = arr[1];
    }
    else{
         maxValue = arr[1];
        secondMaxValue = arr[0];
    }

    for (int i = 2; i < size; i++)
    {
        if(arr[i] >= maxValue){
            secondMaxValue = maxValue;
            maxValue = arr[i];
        }
        else if(arr[i] >= secondMaxValue){
            secondMaxValue = arr[i];
        }
    }
   
   cout <<" Max: "<<maxValue <<" "<< secondMaxValue;
}

int secondLargest(int arr[], int n) {
		int larg1 = INT_MIN;
		int larg2 = INT_MIN;
		for(int i=0;i < n; i++){
			int  currentValue = arr[i];
			if(currentValue > larg1){
				larg2 = larg1;
				larg1 = currentValue;
			}
			else if(currentValue>larg2 && currentValue != larg1){
				larg2=currentValue;
			}
		}
        cout << "L1: "<<larg1<<" L2: "<<larg2;
		return larg2;
	}

int main(){
int arr[5] = {1,10,9,10,7};
// findMaxValue(arr,5);
int sLargest = secondLargest(arr,5);
cout << endl<< sLargest;
return 0;
}
