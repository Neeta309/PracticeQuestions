#include <stdio.h>

int main()
{
    int rows, cols, num_non_zero, i, j, k;

    // Get the number of rows, columns, and non-zero elements for the first matrix
    printf("Enter the number of rows for the first matrix: ");
    scanf("%d", &rows);
    printf("Enter the number of columns for the first matrix: ");
    scanf("%d", &cols);
    printf("Enter the number of non-zero elements for the first matrix: ");
    scanf("%d", &num_non_zero);

    // Declare and initialize the first matrix
    int matrix1[num_non_zero][3];
    printf("Enter each non-zero element in the first matrix (row, column, value):\n");
    for (i = 0; i < num_non_zero; i++)
    {
        scanf("%d %d %d", &matrix1[i][0], &matrix1[i][1], &matrix1[i][2]);
    }

    // Get the number of non-zero elements for the second matrix
    printf("Enter the number of non-zero elements for the second matrix: ");
    scanf("%d", &num_non_zero);

    // Declare and initialize the second matrix
    int matrix2[num_non_zero][3];
    printf("Enter each non-zero element in the second matrix (row, column, value):\n");
    for (i = 0; i < num_non_zero; i++)
    {
        scanf("%d %d %d", &matrix2[i][0], &matrix2[i][1], &matrix2[i][2]);
    }

    // Declare and initialize the resulting matrix
    int result[num_non_zero][3];
    int result_size = 0;

    // Calculate the sum of the two matrices
    i = 0;
    j = 0;
    while (i < num_non_zero && j < num_non_zero)
    {
        if (matrix1[i][0] < matrix2[j][0])
        {
            result[result_size][0] = matrix1[i][0];
            result[result_size][1] = matrix1[i][1];
            result[result_size][2] = matrix1[i][2];
            result_size++;
            i++;
        }
        else if (matrix1[i][0] > matrix2[j][0])
        {
            result[result_size][0] = matrix2[j][0];
            result[result_size][1] = matrix2[j][1];
            result[result_size][2] = matrix2[j][2];
            result_size++;
            j++;
        }
        else
        {
            if (matrix1[i][1] < matrix2[j][1])
            {
                result[result_size][0] = matrix1[i][0];
                result[result_size][1] = matrix1[i][1];
                result[result_size][2] = matrix1[i][2];
                result_size++;
                i++;
            }
            else if (matrix1[i][1] > matrix2[j][1])
            {
                result[result_size][0] = matrix2[j][0];
                result[result_size][1] = matrix2[j][1];
                result[result_size][2] = matrix2[j][2];
                result_size++;
                j++;
            }
            else
            {
                result[result_size][0] = matrix1[i][0];
                result[result_size][1] = matrix1[i][1];
                result[result_size][2] = matrix1[i][2] + matrix2[j][2];
                result_size++;
                i++;
                j++;
            }
        }
    }

    // Copy the remaining elements from matrix1
    while (i < num_non_zero)
    {
        result[result_size][0] = matrix1[i][0];
        result[result_size][1] = matrix1[i][1];
        result[result_size][2] = matrix1[i][2];
        result_size++;
        i++;
    }
    // Copy the remaining elements from matrix2
    while (j < num_non_zero)
    {
        result[result_size][0] = matrix2[j][0];
        result[result_size][1] = matrix2[j][1];
        result[result_size][2] = matrix2[j][2];
        result_size++;
        j++;
    }

    // Print the resulting matrix
    printf("The resulting matrix is:\n");
    for (k = 0; k < result_size; k++)
    {
        printf("%d %d %d\n", result[k][0], result[k][1], result[k][2]);
    }

    return 0;
}