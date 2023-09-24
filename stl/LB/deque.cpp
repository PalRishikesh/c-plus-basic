#include<iostream>
#include<deque>

using namespace std;

int main(){

    deque<int> d;
    d.push_back(1);
    d.push_front(2);
    for(int i:d){
        cout<<i<<" ";
    }
    cout<<endl;
    // d.pop_back();
    // d.pop_front();
    // for(int i:d){
    //     cout<<i<<" ";
    // }

    cout<<" First Element Value: "<<d.at(0)<<endl;
    cout<<" Front "<<d.front()<<endl;
    cout<<" Back "<<d.back()<<endl;
    cout<<" Empty "<<d.empty()<<endl;

    cout<<"Befor size:"<<d.size()<<endl;
    d.erase(d.begin(),d.begin()+1);
    cout<<"After size:"<<d.size()<<endl;
     for(int i:d){
        cout<<i<<" ";
    }
}