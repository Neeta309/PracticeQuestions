#include <stdio.h>

int main()
{
    int rows, cols, numNonZero, i, j;

    // prompt user for matrix dimensions
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);
    printf("Enter the number of non-zero elements: ");
    scanf("%d", &numNonZero);

    // create array to store sparse matrix
    int sparseMatrix[numNonZero][3];

    // prompt user for each non-zero element
    printf("Enter each non-zero element in the sparse matrix:\n");
    for (i = 0; i < numNonZero; i++)
    {
        printf("Enter row index: ");
        scanf("%d", &sparseMatrix[i][0]);
        printf("Enter column index: ");
        scanf("%d", &sparseMatrix[i][1]);
        printf("Enter value: ");
        scanf("%d", &sparseMatrix[i][2]);
    }

    // create array to store transpose of sparse matrix
    int transpose[numNonZero][3];

    // initialize transpose matrix with row and column switched
    for (i = 0; i < numNonZero; i++)
    {
        transpose[i][0] = sparseMatrix[i][1];
        transpose[i][1] = sparseMatrix[i][0];
        transpose[i][2] = sparseMatrix[i][2];
    }

    // print transpose matrix
    printf("Transpose of sparse matrix:\n");
    for (i = 0; i < cols; i++)
    {
        for (j = 0; j < numNonZero; j++)
        {
            if (transpose[j][1] == i)
            {
                printf("%d ", transpose[j][2]);
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }

    return 0;
}
