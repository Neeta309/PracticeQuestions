#include <stdio.h>
#define MAX_SIZE 100

int determinant(int mat[MAX_SIZE][3], int n)
{
    int det = 0;
    if (n == 1)
    {
        return mat[0][2];
    }
    else
    {
        int cofactor[MAX_SIZE][3], sign = 1;
        for (int k = 0; k < n; k++)
        {
            int submat[MAX_SIZE][3], subsize = 0;
            for (int i = 0; i < n; i++)
            {
                if (i != 0 && mat[i][1] != k)
                {
                    int j = 0;
                    while (j < subsize && mat[i][0] > submat[j][0])
                    {
                        j++;
                    }
                    for (int l = subsize - 1; l >= j; l--)
                    {
                        submat[l + 1][0] = submat[l][0];
                        submat[l + 1][1] = submat[l][1];
                        submat[l + 1][2] = submat[l][2];
                    }
                    submat[j][0] = mat[i][0];
                    submat[j][1] = mat[i][1] < k ? mat[i][1] : mat[i][1] - 1;
                    submat[j][2] = mat[i][2];
                    subsize++;
                }
            }
            det += sign * mat[k][2] * determinant(submat, subsize);
            sign = -sign;
        }
        return det;
    }
}

int main()
{
    int n, m, nnz, mat[MAX_SIZE][3];
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    printf("Enter the number of columns: ");
    scanf("%d", &m);
    printf("Enter the number of non-zero elements: ");
    scanf("%d", &nnz);
    printf("Enter the non-zero elements (in row-column-value format):\n");
    for (int i = 0; i < nnz; i++)
    {
        scanf("%d%d%d", &mat[i][0], &mat[i][1], &mat[i][2]);
        mat[i][0]--;
        mat[i][1]--;
    }
    int det = determinant(mat, n);
    printf("The determinant of the sparse matrix is %d.\n", det);
    return 0;
}
