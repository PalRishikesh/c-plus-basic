#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){

    set<int> mySet;

    mySet.insert(10);
    mySet.insert(50);
    mySet.insert(40);
    mySet.insert(30);
    mySet.insert(90);
    mySet.insert(50);

mySet.erase(30);
  int element = 40;

    auto it2 = mySet.find(element);
    // if we got the data then delete it
    if(it2 !=mySet.end()){
        mySet.erase(element);
    }
    set<int>::iterator it;
    for (it = mySet.begin();it!=mySet.end(); it++)
    {
        cout<<*it<<" ";
    }
    
  
    
}