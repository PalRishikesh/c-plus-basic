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
        int space = row -1;
        while (space)
        {
            cout << " ";
            space--;
        }
        
        int col = 1;
        int star = n-row+ 1;
        while (star)
        {
           cout <<row;
           star--;
        }
        
        
        row++;
        cout <<endl;
    }
} 