#include<iostream>
using namespace std;
// https://www.codingninjas.com/studio/problems/triplets-with-given-sum_893028?source=youtube&campaign=LoveBabbar_Codestudiovideo1&utm_source=youtube&utm_medium=affiliate&utm_campaign=LoveBabbar_Codestudiovideo1
int main(){
int arr[] = {1,5,9,4,2,3,7,10};

for (int i = 0; i < 8 ; i++)
{
    for (int j = i+1; j < 8; j++)
    {
       for (int k = j+1; k < 8; k++)
       {
        cout << arr[i] <<" "<< arr[j] << " "<< arr[k] <<endl;
       }
       
    }
    
}


    return 0;
}