#include <iostream>
using namespace std;

int main()
{

    int n;
    cin >> n;

    int row = 1;

    while (row <= n)
    {

        int column = 1;
        while (column <= row)
        {
            // cout <<row + column -1;
           char ch = 'A'+row + column -2;
            cout << ch;
            column++;
        }
        row++;
        cout << endl;
    }
}