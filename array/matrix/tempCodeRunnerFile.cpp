#include <iostream>
using namespace std;
const int rows = 2, columns = 3;

void transposeMatrix(int matrixA[rows][columns], int transposedMatrix[columns][rows]){
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            transposedMatrix[j][i] = matrixA[i][j];
        }
    }
}
int main()
{

    int matrixA[rows][columns] = {
        {1, 2,3},
        {4,5,6}
        };
  int transposedMatrix[columns][rows];
    transposeMatrix(matrixA, transposedMatrix);
    cout << "hi" << endl;
    for (int i = 0; i < columns; i++)
    {
        for (int j = 0; j < rows; j++)
        {

            cout << transposedMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}