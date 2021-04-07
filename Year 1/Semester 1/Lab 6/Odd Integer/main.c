#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int i, n, odd = 0;

    printf("\n\nEnter size of Array: ");
	scanf("%d", &n);
	int arr[n];
	printf("Enter Array elements: ");
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		odd ^= arr[i];
	}
	printf("Odd Integer: %d\n", odd);
    return 0;
}
