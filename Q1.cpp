#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
float **serialMultiplication(float **mat1, float **mat2, int row, int col);
void assignRendomValues(float **&matrix, int row, int col, int range);
void allocateDynamicMemory(float **&matrix, int row, int col);
void displayMatrix(float **matrix1, int row, int col);
int main()
{
    /* -------------------------------------------------------------------------- */
    /*                                Preprocessing                               */
    /* -------------------------------------------------------------------------- */
    int row;
    int col;

    float **matrix1 = NULL;
    float **matrix2 = NULL;
    float **resultantMatrix = NULL;
    /* -------------------- Initilize Dimentions of Matrix 1 -------------------- */
    cout << "===== Enter Dimentations of Matrixes=====" << endl;
    srand(time(NULL));
    cout << "Enter Dimention Of Matrix : ";
    cin >> row;
    col = row;
    /* ------------------ Allocating Dynamic Memory ofMatrixes ------------------ */
    allocateDynamicMemory(matrix1, row, col);
    allocateDynamicMemory(matrix2, row, col);
    /* ----------------------------- Displaying Data ---------------------------- */
    assignRendomValues(matrix1, row, col, 10);
    assignRendomValues(matrix2, row, col, 10);
    cout << "Matrix 1 : " << endl;
    displayMatrix(matrix1, row, col);
    cout << "Matrix 2 : " << endl;
    displayMatrix(matrix2, row, col);
    resultantMatrix = serialMultiplication(matrix1, matrix2, row, col);
    cout << "Resultant Matrix : " << endl;
    displayMatrix(resultantMatrix, row, col);
    return 0;
}
float **serialMultiplication(float **mat1, float **mat2, int row, int col)
{
    float **resultant = NULL;
    allocateDynamicMemory(resultant, row, col);

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            resultant[i][j] = 0;

            for (int k = 0; k < row; k++)
            {
                resultant[i][j] += mat1[i][k] * mat2[k][j];
            }

            cout << resultant[i][j] << "\t";
        }

        cout << endl;
    }
    displayMatrix(resultant, row, col);
    return resultant;
}
void assignRendomValues(float **&matrix, int row, int col, int range = 10)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            matrix[i][j] = rand() % range;
        }
    }
}
void allocateDynamicMemory(float **&matrix, int row, int col)
{
    matrix = new float *[row];
    for (int i = 0; i < row; i++)
    {
        matrix[i] = new float[col];
    }
}
void displayMatrix(float **matrix1, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << matrix1[i][j] << " ";
        }
        cout << endl;
    }
}