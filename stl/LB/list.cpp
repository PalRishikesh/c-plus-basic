#include<iostream>
#include<list>

using namespace std;

int main(){
    list<int> l;
    l.push_back(1);
    l.push_front(2);
    //Copy
    list<int> n(l);
    list<int> p(5,100);

    for(int i:p){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"After erase"<<endl;
    l.erase(l.begin());
    for(int i:l){
        cout<<i<<" ";
    }
    //l.pop_back();
    cout<<"Size: "<<l.size()<<endl;

}