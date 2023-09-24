#include <iostream>
#include <math.h>
#include <climits>
using namespace std;




int getSum(int num[], int n){
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
       sum = sum+ num[i];
    }
      
    //returing max value
    return sum;
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
    
    int sumValue = getSum(num,size);
    cout <<" Sum value "<<sumValue<<endl;
    return 0;
} 