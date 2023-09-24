#include <iostream>
using namespace std;

int main()
{

    int a = 4;
    int b = 6;

    cout <<" a&b "<< (a&b) << endl;
    cout <<" a|b "<< (a|b) << endl;
    cout <<" ~a "<< (~a) << endl;
    cout <<" ~b "<< (~b) << endl;
    cout <<" a^b "<< (a^b) << endl;

    cout <<">> 1 "<< (17>>1) <<endl;
    cout <<">> 2 "<< (17>>2) <<endl;
    cout <<"<< 1 "<< (21<<1) <<endl;
    cout <<"<< 2 "<< (21<<2) <<endl;

    int i=7;

    cout << (++i)<<endl;
    // 8
    cout << (i++)<<endl;
    // 8, i=9
    cout << (i--)<<endl;
    // 9, i=8
    cout << (--i)<<endl;
    // 7, i=7
}