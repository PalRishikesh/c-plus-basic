#include<iostream>
using namespace std;

int main(){

    char ch;
    int key;
    cout << " Please enter any character or number"<<endl;
    cin>>ch;
    key = (int)ch;
    cout << "Enter key is : "<<ch<<endl;
    cout << "Enter key ASCII is : "<<key<<endl;

    if(key >=48 && key <= 57){
        cout << "Enter key is Numeric "<<key<<endl;
    }
    else if(key >=65 && key <= 90){
        cout << "Enter key is Upper Case"<<key<<endl;
    }
     else if(key >= 97 && key <= 122){
        cout << "Enter key is Upper Case"<<key<<endl;
    }


}