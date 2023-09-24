#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    int size;
    cin>>size;
    vector<int> vec;
    for (int i=0; i< size; i++) {
        int value;
        cin>>value;
        vec.push_back(value);
    }
    sort(vec.begin(),vec.end());
    vector<int>::iterator it;
    for(it=vec.begin(); it!=vec.end(); it++){
        cout <<*it<<" ";
    }
    return 0;
}
