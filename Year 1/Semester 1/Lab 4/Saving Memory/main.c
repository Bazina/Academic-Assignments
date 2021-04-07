#include <stdio.h>
#include <stdlib.h>

int main()
{
	int x, y, xchar;
	printf("Enter x & y: ");
	scanf("%d %d", &x, &y);
	char z;

	if (x<=15 && x>=0 && y>=0 && y<=15){
        xchar = x<<4;
        z = xchar|y;
        printf("\nThe Answer %d\n", z);
	}
	else{
        printf("\nError");
	}
    return 0;
}
