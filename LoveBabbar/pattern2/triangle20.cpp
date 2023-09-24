#include <iostream>
using namespace std;

int main()
{

    int n;
    cin >> n;

    int row = 1;

    while (row <= n)
    {
     
        int col = 1;

        // while ( n-row)
        // {
        //     cout << "!";
        // }
        
        while (col <=n )
        {
            if(row > col){ // greater than
                cout <<" ";
            }
            else{
                cout <<col;

            }
            col++;
        }
        
        row++;
        cout <<endl;
    }
} 