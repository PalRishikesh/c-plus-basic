#include <iostream>
#include <math.h>
#include <climits>
using namespace std;




int update(int num[], int n){
    cout << "Entry function"<<endl;

    // update array first element value
      num[0] = 120;
    for (int i = 0; i < n; i++)
    {
      cout<< num[i]<< " ";
    }
    cout<<endl;
      
    cout << "Exit function"<<endl;

}
int main()
{
    int arr[3]={1,3,5};


   update(arr,3);

     cout << "Main function"<<endl;
    for (int i = 0; i < 3; i++)
    {
      cout<< arr[i]<< " ";
    }
    cout<<endl;
      
    return 0;
} 