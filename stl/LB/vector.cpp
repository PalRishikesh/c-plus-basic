#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> v;
    vector<int> a(5,1); // 5 is size and default value for all is 1
    vector<int> b(a); // Copy all a vector to b vector
    cout <<"Capacity : "<<v.capacity()<<endl;
    v.push_back(1);
    cout <<"Capacity : "<<v.capacity()<<endl;
    v.push_back(2);
    cout <<"Capacity : "<<v.capacity()<<endl;
    v.push_back(3);
    cout <<"Capacity : "<<v.capacity()<<endl;
    cout <<"Size : "<<v.size()<<endl;
    cout <<"Element : "<<v.at(2)<<endl;
    cout <<"Front : "<<v.front()<<endl;
    cout <<"back : "<<v.back()<<endl;

    for(int i:b){
        cout<<i<<" ";
    }
    cout<<endl;
    v.pop_back();
     for(int i:v){
        cout<<i<<" ";
    }
    cout<<"Size :"<<v.size()<<endl;
    v.clear();
    cout<<"Size :"<<v.size()<<endl;
}