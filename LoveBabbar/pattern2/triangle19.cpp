#include <iostream>
using namespace std;

int main()
{

    int n;
    cin >> n;

    int row = 1;

    while (row <= n)
    {
        // space print
        int space = n - row;
        while (space)
        {
            cout << " ";
            space--;
        }
        
        int col = 1;
        while (col <= row)
        {
           cout <<row;
           col++;
        }
        
        
        row++;
        cout <<endl;
    }
} 