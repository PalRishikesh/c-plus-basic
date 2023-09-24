#include<iostream>
#include<math.h>
using namespace std;

int main(){

    int n;
    cout <<" Please enter Number "<<endl;
    cin>>n;
   // If output is 0 means even or 1 is odd
    // int r = n&1;
    //     cout <<r<<endl;
    // }


    int ans = 0;
    int i=0;

    int answer = 0;


    while(n!=0){
        int bit = n & 1;
        cout << i<<" ----- "<<bit<<endl; 
        answer = (bit * pow(10,i)) + answer;

        n = n>>1;
        i++;
    }
   cout <<" Answer is "<<answer<<endl;
}