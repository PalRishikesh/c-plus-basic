#include <iostream>
#include <math.h>
#include <climits>
using namespace std;


int getMax(int num[], int n){
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if(num[i] > max){
            max = num[i];
        }
    }
      
    //returing max value
    return max;
}

int getMin(int num[], int n){
    int min = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if(num[i] < min){
            min = num[i];
        }
    }
      
    //returing max value
    return min;
}
int main()
{
    int size;
    cin>>size;

    int num[size];

    // Taking input
    for (int i = 0; i < size; i++)
    {
        cin>>num[i];
    }
    
    int maxValue = getMax(num,size);
    int minValue = getMin(num,size);
    cout <<" Max Value : "<<maxValue<<endl;
    cout <<" min Value : "<<minValue<<endl;

    return 0;
} 