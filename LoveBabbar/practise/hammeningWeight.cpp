#include<iostream>
#include<bitset>
using namespace std;
const int N_DIGITS = 8;
int main(){

    unsigned long ninaryNumber =  8ul; // == 1000 in binary form  -- Binary input
    // int n[8] = {0, 0, 0, 1, 0, 0, 1, 1};
    bitset<N_DIGITS> n(ninaryNumber);
    int count = 0;

    while (n!=0)
    {
        if(n&1){
            count++;
        }
        n = n>>1;
    }
    cout <<" Count : "<<count;
  

}