#include <stdio.h>

typedef struct matrix
{
    int row, column;
    int matrix[100][100];
} Matrix;

void inputMatrix(Matrix *A, Matrix *B)
{
    printf("Enter dimension of the first matrix: ");
    scanf("%d %d", &A->row, &A->column);
    printf("Enter dimension of the second matrix: ");
    scanf("%d %d", &B->row, &B->column);

    printf("Enter elements of the first matrix:\n");
    for (int i = 0; i < A->row; i++)
    {
        for (int j = 0; j < A->column; j++)
        {
            printf("Enter element[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &A->matrix[i][j]);
        }
    }

    printf("Enter elements of the second matrix:\n");
    for (int i = 0; i < B->row; i++)
    {
        for (int j = 0; j < B->column; j++)
        {
            printf("Enter element[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &B->matrix[i][j]);
        }
    }
}

void printMatrix(Matrix A)
{
    printf("\n");
    for (int i = 0; i < A.row; i++)
    {
        for (int j = 0; j < A.column; j++)
            printf("%d ", A.matrix[i][j]);
        printf("\n");
    }
    printf("\n");
}

void addMatrix(Matrix A, Matrix B, Matrix *C)
{
    if (A.row != B.row && A.column != B.column)
    {
        C->row = C->column = 0;
        return;
    }
    C->row = A.row, C->column = A.column;
    for (int i = 0; i < C->row; i++)
    {
        for (int j = 0; j < C->column; j++)
            C->matrix[i][j] = A.matrix[i][j] + B.matrix[i][j];
    }
}

void multiplyMatrix(Matrix A, Matrix B, Matrix *C)
{
    if (A.column != B.row)
    {
        C->row = C->column = 0;
        return;
    }
    C->row = A.row, C->column = B.column;
    for (int i = 0; i < C->row; i++)
    {
        for (int j = 0; j < C->column; j++)
        {
            C->matrix[i][j] = 0;
            for (int k = 0; k < A.column; k++)
            {
                C->matrix[i][j] += A.matrix[i][k] * B.matrix[k][j];
            }
        }
    }
}

int main()
{
    Matrix A, B, Sum, Prod;
    inputMatrix(&A, &B);
    printf("\nMatrix A =");
    printMatrix(A);
    printf("\nMatrix B =");
    printMatrix(B);

    addMatrix(A, B, &Sum);
    multiplyMatrix(A, B, &Prod);

    if (Sum.row)
    {
        printf("Sum of the Matrices is: ");
        printMatrix(Sum);
    }
    else
        printf("Sum Not defined!\n");
    if (Prod.row)
    {
        printf("Product of the Matrices is:");
        printMatrix(Prod);
    }
    else
        printf("Sum not defined!\n");
    return 0;
}