#include <stdio.h>

int main()
{
    int arr[1000], n, sum = 0;
    printf("Enter the size of an array\n");
    scanf("%d", &n);
    printf("Enter the values of an array\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
        {
            sum += arr[i];
        }
    }
    printf("\n%d is the sum of even numbers", sum);
    return 0;
}