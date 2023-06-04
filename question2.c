#include <stdio.h>

int main()
{
    int arr[1000], n;
    printf("Enter the size of an array\n");
    scanf("%d", &n);
    printf("Enter the values of an array\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int max = arr[0], min = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    printf("%d is maximum and\n %d is minimum\n", max, min);

    return 0;
}