#include<iostream>
#include<queue>

using namespace std;

int main(){
    queue<string> q;
    q.push("Rishikesh");
    q.push("Arjun");
    q.push("Pal");

    cout<<"First Element: "<<q.front()<<endl;
    q.pop();
    cout<<"First Element: "<<q.front()<<endl;
    cout<<"Size: "<<q.size();

}