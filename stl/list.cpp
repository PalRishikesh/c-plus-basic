#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    list<int> myList;
    myList.push_back(10);
    myList.push_back(50);
    myList.push_back(40);
    myList.push_back(20);
    myList.push_back(30);

    list<int>::iterator it;
    myList.sort(); // sorting
    myList.reverse(); // sorting
    myList.push_back(50);
 myList.insert(myList.begin(),60);// at beginning
 // Ad random index
 auto it4 = myList.begin();
 advance(it4,3);
 myList.insert(it4,500);
 //Deleting
    auto it5 = myList.begin();
    advance(it5,1);
    myList.erase(it5);
    for (it = myList.begin(); it!=myList.end(); it++)
    {
       cout <<*it<<" ";
    }

    int element=200;
    auto it2 = find(myList.begin(),myList.end(),element);
    if(it2!=myList.end()){
        cout <<element<<" Found "<<endl;
    }

    int mx = *max_element(myList.begin(),myList.end());
    int mn = *min_element(myList.begin(),myList.end());
   cout <<"MAx : "<<mx<<endl;
   cout <<"mn : "<<mn<<endl;
   
    
}