#include <iostream>
using namespace std;

int main()
{

    int n;
    cin >> n;

    int row = 1;

    while (row <= n)
    {
        // start print
        int space = n-row + 1;
        while (space)
        {
            cout << "*";
            space--;
        }
        
        row++;
        cout <<endl;
    }
} 