#include <stdio.h>

#define MAX_TERMS 100

typedef struct
{
    int row;
    int col;
    int value;
} Element;

void read_sparse_matrix(Element a[], int *num_rows, int *num_cols, int *num_terms)
{
    printf("Enter the number of rows, columns and non-zero terms: ");
    scanf("%d %d %d", num_rows, num_cols, num_terms);

    printf("Enter the row, column and value of each non-zero term:\n");
    for (int i = 0; i < *num_terms; i++)
    {
        scanf("%d %d %d", &a[i].row, &a[i].col, &a[i].value);
    }
}

void print_sparse_matrix(Element a[], int num_terms)
{
    printf("\nRow\tColumn\tValue\n");
    for (int i = 0; i < num_terms; i++)
    {
        printf("%d\t%d\t%d\n", a[i].row, a[i].col, a[i].value);
    }
}

void sparse_matrix_product(Element a[], Element b[], Element c[], int num_rows, int num_cols, int num_terms_a, int num_terms_b, int *num_terms_c)
{
    // Initialize c with all elements having value 0
    for (int i = 0; i < num_rows; i++)
    {
        for (int j = 0; j < num_cols; j++)
        {
            c[i * num_cols + j].row = i;
            c[i * num_cols + j].col = j;
            c[i * num_cols + j].value = 0;
        }
    }

    // Calculate c as the product of a and b
    *num_terms_c = 0;
    for (int i = 0; i < num_terms_a; i++)
    {
        for (int j = 0; j < num_terms_b; j++)
        {
            if (a[i].col == b[j].row)
            {
                int row = a[i].row;
                int col = b[j].col;
                int value = a[i].value * b[j].value;

                // Add this element to c
                int k;
                for (k = *num_terms_c - 1; k >= 0; k--)
                {
                    if (c[k].row == row && c[k].col == col)
                    {
                        c[k].value += value;
                        break;
                    }
                }
                if (k < 0)
                {
                    c[*num_terms_c].row = row;
                    c[*num_terms_c].col = col;
                    c[*num_terms_c].value = value;
                    (*num_terms_c)++;
                }
            }
        }
    }
}

int main()
{
    Element a[MAX_TERMS], b[MAX_TERMS], c[MAX_TERMS];
    int num_rows_a, num_cols_a, num_terms_a;
    int num_rows_b, num_cols_b, num_terms_b;
    int num_terms_c;

    read_sparse_matrix(a, &num_rows_a, &num_cols_a, &num_terms_a);
    read_sparse_matrix(b, &num_rows_b, &num_cols_b, &num_terms_b);

    printf("\nSparse Matrix A:\n");
    print_sparse_matrix(a, num_terms_a);

    printf("\nSparse Matrix B:\n");
    print_sparse_matrix(b, num_terms_b);

    if (num_cols_a != num_rows_b)
    {
        printf("\nError: Matrix dimensions incompatible for multiplication.\n");
        return 1;
    }

    sparse_matrix_product(a, b, c, num_rows_a, num_cols_b, num_terms_a, num_terms_b, &num_terms_c);

    printf("\nProduct of A and B:\n");
    print_sparse_matrix(c, num_terms_c);

    return 0;
}
