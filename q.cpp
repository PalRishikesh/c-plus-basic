#include <iostream>  
using namespace std;  
int main()  
{  

    int n=121;
    int r,temp, sum=0;
    temp = n;
    while (n>0)
    {
        // cout<<n<<endl;
        // cout<<"S 1 :" <<sum<<endl;
        // r = r%10;
        // cout<<"r1 :" <<r<<endl;

        // sum = r;
        // n = n/10;
        
        cout<<"S :" <<sum<<endl;
    }
    cout<<" Temp "<<temp<<" S:"<<sum<<endl;
    if(temp == sum){
        cout<<" Number is palindaroim";
    }
    else{
        cout<<" Not";
    }
    return 0;
}