#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){

    vector<int> vec;
    vec.push_back(10);
    vec.push_back(80);
    vec.push_back(20);
    vec.push_back(5);
    vec.push_back(30);
    vec.push_back(40);
    vec.push_back(50);
    vec.push_back(10);
    vector<int>::iterator it;
    vector<int>::iterator itRever;
    // cout <<*vec.begin()<<endl;
    sort(vec.begin(),vec.end());
    vec.pop_back();// remove last element
    // reverse(vec.begin(), vec.end());
    // for(itRever=vec.rbegin(); itRever != vec.rend(); ++itRever){
        // cout<<*itRever<<" ";
    // }
    auto findElement = find(vec.begin(), vec.end(),5);
    // cout <<" "<<endl;
    // if(findElement != vec.end()){
    //     cout << " Found element "<< distance(vec.begin(),findElement)<<endl;
    // }
    // else{
    //     cout <<" Element not found "<<endl;
    // }

    // vec.insert(vec.begin(),150);// Specified index

    int counts = count(vec.begin(),vec.end(),10);
    cout<< "Count: "<<counts<<endl;
    vec.erase(vec.begin()+1);

    int max= *max_element(vec.begin(),vec.end());
    int min= *min_element(vec.begin(),vec.end());
    cout<<"Max: "<<max<< " Min: "<<min<<endl; 
}