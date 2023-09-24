#include <iostream>
using namespace std;

int main()
{

    int n;
    cin >> n;
    int row=1;
    while(row <= n){

        //Print space (1st triangle)
        int space = n-row;
        while (space)
        {
           cout <<" ";
           space--;
        }
        

        // Print 2nd triangle
        int col = 1;
        while(col <= row){
            cout << col;
            col++;
        } 


        // Print 3rd triangle
        int start = row-1;
        while(start){
            cout <<start;
            start--;
        }
        row++;
        cout <<endl;


    }




}