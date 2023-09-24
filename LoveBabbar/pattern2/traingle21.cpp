#include <iostream>
using namespace std;

int main()
{

    int n;
    cin >> n;

    int row = 1;
    int value = 1;
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
           cout <<value;
           value++;
           col++;
        }
        
        
        row++;
        cout <<endl;
    }
} 