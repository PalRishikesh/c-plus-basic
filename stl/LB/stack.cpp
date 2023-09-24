#include<iostream>
#include<stack>

using namespace std;

int main(){
    stack<string> s;
    s.push("Pal");
    s.push("Rishikesh");
    s.push("Arjun");
    cout<<"Top Element "<<s.top()<<endl;
    s.pop();
    cout<<"Top Element "<<s.top()<<endl;
    cout<<"Size : "s.size()<<endl;
    cout<<"Empty : "s.empty()<<endl;
}