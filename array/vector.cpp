#include <bits/stdc++.h>
using namespace std;

int main(){

    vector <int> vec= {2,5,6,7};
    vec.erase(vec.begin()+1);

    for(int i=0;i < vec.size();i++){
        cout <<vec[i]<<" ";
    }


    return 0;
    }
