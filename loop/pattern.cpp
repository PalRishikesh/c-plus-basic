#include <iostream>
#include <string>
using namespace std;
int main()
{

    // Square pattern
    // int n = 4;
    // for (int i = 0; i <= n; i++)
    // {
    //    for (int j = 0; j <= n; j++)
    //    {
    //      cout<<"*";
    //    }
    //    cout <<endl;
    // }

    // Using single loop
    //  for(int i=1; i<=n*n; i++){
    //     cout <<"*";
    //     if(i % n == 0){
    //         cout << endl;
    //     }
    // }

    // Hollow square pattern
    int n = 5;
    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j <= n; j++)
    //     {
    //         if(i==0 || i==n || j==0 | j==n){
    //             cout << "*";
    //         }
    //         else{
    //             cout << " ";
    //         }
    //     }
    //     cout <<endl;
    // }

    // Nested Loop with ternary operator
    // for(int i=0; i<= n; i++){
    //     for(int j=0; j<=n; j++){
    //         cout <<(i==0 || i==n || j==0 || j ==n ? "*": " ");
    //     }
    //     cout <<endl;
    // }

    // Using Single Loop
    //  for(int i=1; i<=n *n; i++){
    //     if( i<= n || i%n == 1 || i%n == 0 || i > n*(n-1)){
    //     cout <<"*";
    //     }
    //     else{
    //         cout << " ";
    //     }
    //     if(i % n == 0){
    //         cout << endl;
    //     }
    // }
    // Explanation
    // i should be less then number taken here is 5 means first row will print
    // i%n ==1 means firt columns will also print
    // i%n ==0 means condition will be satisfied with last position with modular and print *
    // i > (n*(n-1)) means number taken subtract 1 means we should give space for last rows and fill that with *

    // Using Single Loop using ternary operator
    //  for(int i=1; i<=n *n; i++){
    //     cout<< (i<= n || i%n == 1 || i%n == 0 || i > n*(n-1)  ? "*": " ");
    //     if(i % n == 0){
    //         cout << endl;
    //     }
    // }

    // Left traingle pattern
    // for(int i=1; i<= n; i++){
    //     for (int j = 1; j <= i; j++)
    //     {
    //         cout <<"*";
    //     }
    //     cout << endl;
    // }

    // Single loop
    // int currentCount = 0;
    //  for(int i=0; i<= n*n; i++){
    //     //i > (n*(n-1)) ||
    //     if( i%n <= currentCount-1){
    //         cout << "*";
    //     }
    //     if(i%n ==0){
    //         currentCount++;
    //         cout << endl;
    //     }
    // }

    // Right side triangle pattern
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         if(n-i < j){ // Printing in reverse order
    //             cout <<"*";
    //         }
    //         else{
    //             cout <<" ";
    //         }
    //     }
    //    cout << endl;
    // }
    // Right side triangle pattern by single loop
    // int counter = 1;
    // for (int i = 1; i <= n*n; i++)
    // {
    //     // example first row (4*1)-1= 3 (till 3 No there space), next (4*2)-2= 6 (till 6 number there  space),(4*3)-3 = 9,(4*4)-4=12
    //    if( i <= (n*counter) - counter){
    //     cout <<" ";
    //    }
    //    else{
    //     cout <<"*";
    //    }
    //    if(i%n == 0){
    //     counter++;
    //     cout << endl;
    //    }
    // }

    //

    return 0;
}