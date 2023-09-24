#include <iostream>
#include <string>
using namespace std;
int main()
{

    // int N = -83532;
    // int rev = 0;
    // while (N!=0)
    // {
    //     int digit = N%10;
    //     rev = rev*10 + digit;
    //     cout << rev <<endl;
    //     N = N/10;
    // }

    // int N = 121;
    // int temp = N;
    // int rev = 0;
    // while (N!=0)
    // {
    //     int digit = N%10;
    //     rev = rev*10 + digit;
    //     N = N/10;
    // }

    // if(temp == rev){
    //     cout << "Yes, it is palindrome";
    // }
    // else{
    //     cout <<" No it is not palindrom";
    // }

    int a = 5;
    int b = 5;

    int *ptr = &a;
    // cout <<endl;
    // cout <<ptr; // Addres of a
    // cout <<*ptr; // Value of a
    // cout <<&ptr; // Address of ptr

    cout << endl;
    cout << ptr << endl;
    cout << ptr+2 << endl;
    cout << &ptr << endl;
    int **ptr2 = &ptr;
    cout << ptr2+1;

    return 0;
}