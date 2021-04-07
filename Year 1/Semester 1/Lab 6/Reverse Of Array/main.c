#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int n, i;
    printf("\nEnter size of Array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter Array elements: ");
    for (i = 0; i < n; i++){
        scanf("%d", &arr[n-i-1]);
    }
    printf("Reversed Array: ");
    for (i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
