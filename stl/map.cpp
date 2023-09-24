#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    map<int,string> myMap;
    myMap[101]='A';
    myMap[105]='B';
     myMap[102]='C';
    myMap[103]='E';
    myMap[101]='D';
    map<int,string>::iterator it;
    for ( it = myMap.begin(); it !=myMap.end(); it++)
    {
        cout<< " Key: "<<it->first<<" Value: "<<it->second<<endl;
    }
    
    auto it2=max_element(myMap.begin(),myMap.end());
     cout<< " Key 2: "<<it2->first<<" Value2: "<<it2->second<<endl;
     auto it3=min_element(myMap.begin(),myMap.end());
     cout<< " Key 3: "<<it3->first<<" Value3: "<<it3->second<<endl;
     //Access value
     int key=102;
     cout<<myMap[key]<<endl;

     int k =101;
     auto it4 = myMap.find(k);
     if(it4 != myMap.end()){
        cout<<it4->first<< " "<<it4->second<<endl;
     }
     else{
        cout << "Key is not found"<<endl;
     }

     auto it6 = find_if(myMap.begin(), myMap.end(),[](const pair<integer,string> &p){
        return p.second == "B";
     });
     if(it6 != myMap.end()){
        cout<< "Element found"<<endl;
     }
     else{
        cout<<" Not Found "<<endl;

     }
}