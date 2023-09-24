#include<iostream>
#include<queue>

using namespace std;

int main(){
    // Max Heap
        priority_queue<int> maxi;

    // Min Heap
        priority_queue<int, vector<int>, greater<int>> mini;

        maxi.push(1);
        maxi.push(5);
        maxi.push(2);
        maxi.push(4);
        int n = maxi.size();
        for(int i =0;i<n; i++){
            cout<<maxi.top()<<" ";
            maxi.pop();
        }
        cout<<"--"<<endl;

        mini.push(1);
        mini.push(5);
        mini.push(2);
        mini.push(4);
        int size = mini.size();
        for(int i =0;i<size; i++){
            cout<<mini.top()<<" ";
            mini.pop();
        }
        cout<<endl;

        cout<<"Is empty "<<maxi.empty()<<endl;


}