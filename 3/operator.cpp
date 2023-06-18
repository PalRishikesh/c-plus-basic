#include<iostream>
#include<string>
using namespace  std;
int main(){
    // int a = 5.5;
    // int b = 2;
    // double c = (double) a/b;
    // cout << c;
    // % moudler operator we have to use int only
    // int a = 5.5;
    // int b = 2;
    // double c =  a%b;
    // cout << c;

    // increment

    // int a = 5;
    // ++a;
    // cout <<a; // 6
    
    // int a = 5;
    // cout<<a++ <<"\n"; // 5
    // cout <<a; // 6


//   int a = 5;
//     cout<<a-- <<"\n"; // 5
//     cout <<a; // 4


// cout<< (4<5);
// cout << (8.0 == 8);
// cout << ("8" == 8); // we do not compare this

// logical

// cout<< (1&&0); // 0
// cout << (5>1) || 0; // 1
// cout << (1);

// bitwise

    // int a = 3;
    // int b = 4;
    // int c = a&b;
    // cout <<c;
    //   int a = 3;
    // int b = 4;
    // int c = a|b;

    // OR opertaor mind check
    //  int a = 3;
    // int b = 4;
    // int c = a||b;
    // cout <<c; // Return as true as both have value other than 0

// XOR
// int c = (2^3^2);
// cout <<c;

// string s;
// s = "Hello";
// cout <<s<<endl;
// cout <<s[1]<<endl;
// cout <<s[10]<<endl; // Garbage
// cout <<"----"<<endl;
// s[2]='F';
// cout <<s;
// char s2[]={'G','O','O','D','\0'};
// cout <<s2;


// string s;
// cout <<"Enter somethign";
// cin>>s;
// cout <<s;


// char s4[50];

// cin.get(s4,9); //will take char till 9


// 
// string s1 = "Goood";
// string s2 = "evening";
// string s3="New String";
// s1.append(s2);
// s1.append(" ");
// s1.append(s3);
// cout <<s1;


// check size,length and capacity


// string s1 = "Good";
// string s2 = "Evening";
// cout<< s1<<" "<<s2<<endl;
// s1.swap(s2);
// cout<< s1<<" "<<s2<<endl;

// push_back, pop_back()
// push_back, pop_back()
// string s1 = "Good";
// s1.push_back('E');
// s1.push_back('N');
// cout<<s1<<endl;

//remove
// s1.pop_back();
// cout<<s1;



// string s1="AB";
// s1.insert(0,"CD");
// cout<<s1<<endl; // CDAB

// cout<<s1.empty(); // return if string is empty or not
// cout<<s1.clear();// clear the string


string s1="AB";
string s2="AA";
// int k = s1.compare(s2); // +ve

string s3="AB";
// int k = s1.compare(s3); // 0

// string s4="AC";
// int k = s1.compare(s4); // -1

// cout<<k;



    return 0;
}