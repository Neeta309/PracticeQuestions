#include <stdio.h>

int main()
{
    int n;
    printf("Enter the size of an array\n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter values of an array\n ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Entered elements are\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }

    for (int i = 0; i < n / 2; i++)
    {
        int temp = arr[n - 1 - i];
        arr[n - 1 - i] = arr[i];
        arr[i] = temp;
    }
    printf("Reversed elements are\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }
    return 0;
}