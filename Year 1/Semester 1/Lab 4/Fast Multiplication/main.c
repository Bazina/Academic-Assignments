#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int x, y, z;
    printf("Enter x & y: ");
    scanf("%d %d", &x, &y);

    if (x<=1000 && x>=-1000 && y<=11 && y>=0){
        z = x<<y;
        printf("%d", z);
    }
    else {
        printf("Enter x between 1000 & -1000\n");
        printf("Enter y between 0 & 11\n");
    }

    return 0;
}
