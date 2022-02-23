#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
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
void displaymatrix1(float **matrix1, int row, int col)
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
int main()
{
    /* -------------------------------------------------------------------------- */
    /*                                Preprocessing                               */
    /* -------------------------------------------------------------------------- */
    int row1;
    int col1;
    int row2;
    int col2;

    float **matrix1 = NULL;
    float **matrix2 = NULL;
    /* -------------------- Initilize Dimentions of Matrix 1 -------------------- */
    cout << "===== Enter Dimentations of Matrix 1 =====" << endl;
    srand(time(NULL));
    cout << "Enter Rows Number : ";
    cin >> row1;
    cout << "Enter Column Number  ";
    cin >> col1;
    /* ------------------- Initialize Dimentations of Matrix 2 ------------------ */
    cout << "===== Enter Dimentations of Matrix 2 =====" << endl;
    srand(time(NULL));
    cout << "Enter Rows Number : ";
    cin >> row2;
    cout << "Enter Column Number  ";
    cin >> col2;
    /* ------------- Check multiplication Competibility of Matrixes ------------- */
    if (col1 != row2)
    {
        cout << "\t\t\tError:->   These Matrixes Are Not Competible For Multiplication" << endl;
        return 0;
    }
    /* ------------------ Allocating Dynamic Memory ofMatrixes ------------------ */
    allocateDynamicMemory(matrix1, row1, col1);
    allocateDynamicMemory(matrix2, row2, col2);
    /* ----------------------------- Displaying Data ---------------------------- */

    int **resultantMatrix = NULL;
    assignRendomValues(matrix1, row1, col1);
    cout << "Before Assiging Values : " << endl;
    displaymatrix1(matrix1, row1, col1);
    cout << "After Assigning the Values : " << endl;
    displaymatrix1(matrix1, row1, col1);
    return 0;
}