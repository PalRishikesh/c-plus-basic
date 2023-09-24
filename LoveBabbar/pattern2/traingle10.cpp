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
        while (column <= n)
        {
            // cout << row + (column-1);
            // char ch = 'A'+row-1 + (column-1); // Or
            char ch = 'A' + row + (column - 2);
            cout << ch;
            ch++;
            column++;
        }
        row++;
        cout << endl;
    }
}