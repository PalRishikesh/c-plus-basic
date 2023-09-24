#include<iostream>
#include<set>

using namespace std;

int main(){
    set<int> s;
    s.insert(5);
    s.insert(1);
    s.insert(1);
    s.insert(3);
    s.insert(4);

    for(auto i:s){
        cout<<i<<endl;
    }
    set<int>::iterator it = s.begin();
    it++;
    s.erase(it);


    cout<<"---"<<endl;
    for(auto i:s){
        cout<<i<<endl;
    }
    cout<<"Count :"<<s.count(1)<<endl;
    set<int>::iterator itr = s.find(3);
    cout<<"Value present at itr: "<<*itr<<endl;
    for(auto it=itr;it!=s.end();it++){
        cout<<*it<<" ";
    }
}