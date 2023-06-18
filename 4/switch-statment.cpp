#include<iostream>
#include<string>
using namespace  std;
int main(){
    char ch;
    string s;
    cin>>ch;
    int a = 7,b=5;
    switch (s)
    {
    case "add":
        cout<<(a+b);
        break;
    case '-':
        cout<<(a-b);
        break;
    case '*':
        cout<<(a*b);
        break;
    case '/':
        cout<<(a/b);
        break;
    
    default:
        cout << "No input";
        break;
    }


    return 0;
}