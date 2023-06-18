#include<iostream>
#include<string>
#include<limits.h>

using namespace std;
int main()
{  
    // cout << CHAR_MIN << " "<< CHAR_MAX;
    // cout << sizeof(unsigned int);
    int u_a;
    int a = 20;
    float b = 6.7;
    double c = 4.21;
    bool d = true;
    char e = '@';
    string s = "rishikesh";
    s = "rishi";
    int _aa = 10;
    const int k = 20;

    // int 1_a = 20; name is not valid
  
    // cout << s ;

    // type casting

    int a1 = 5;
    double b1 = a1; // implicit done by compiler 
    // cout << b1 << " "<< a1 << endl;

    double a2 = 6.54;
    int b2 = (int)a2;
    cout << b2 << endl;

    double a3 = 65;
    char b3 = (char)a3; // converting asci value of 65 ie Captial A;
    cout << a3 <<" "<<b3 << "\n";
  
    cout << "\n" << endl;
    cout << "new" << endl;

      //  int string
    int z1 = 45;
    string z2 = to_string(z1);
    int z3 = stoi(z2);
    cout << z1 << " " << z2 << " "<< z3;

    // take input from user
    // cout << "Enter a"<< endl;
    // cin>> u_a;
    // cout << u_a;
    return 0;
}
