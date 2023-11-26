#include <iostream>  
using namespace std;  
int main()  
{  

    int n=121;
    int r,temp, sum=0;
    temp = n;
    while (n>0)
    {
     r=n%10;    
 sum=(sum*10)+r;    
 n=n/10;    
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