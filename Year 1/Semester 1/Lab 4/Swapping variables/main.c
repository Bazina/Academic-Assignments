#include <stdio.h>
#include <stdlib.h>

int main() {
	int a, b;
	printf("Enter a & b: ");
	scanf("%d %d", &a, &b);

    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

	printf("\nThe Swap: %d %d", a, b);
	return 0;
}
