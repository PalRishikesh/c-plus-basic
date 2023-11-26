#include <iostream>
using namespace std;
const int rows = 2, columns = 2, colARows = 2;
void addMatrix(int matrixA[rows][columns], int matrixB[rows][columns], int matrixC[rows][columns])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            matrixC[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}
void subtractMatrix(int matrixA[rows][columns], int matrixB[rows][columns], int matrixC[rows][columns])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            matrixC[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
}

void multiplicationMatrix(int matrixA[rows][columns], int matrixB[rows][columns], int matrixC[rows][columns])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            for (int k = 0; k < colARows; k++)
            {
                matrixC[i][j] += matrixA[i][k] * matrixB[k][j];  
            }
        }
    }
}

int main()
{

    int matrixA[rows][columns] = {
        {1, 2},
        {3, 4}};
    int matrixB[rows][columns] = {
        {5,6},
        {7,8}};

    int matrixC[rows][columns]={{0, 0}, {0, 0}};

    // addMatrix(matrixA, matrixB, matrixC);
    // subtractMatrix(matrixA, matrixB, matrixC);
    multiplicationMatrix(matrixA, matrixB, matrixC);
    cout << "hi" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {

            cout << matrixC[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}