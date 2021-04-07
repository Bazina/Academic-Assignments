#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int y;
    printf("Enter a year: ");
    scanf("%d", &y);

    if ((y%400 == 0)||(y%4 == 0 && y%100 != 0)){
        printf("Leap");
    }
    else {
        printf("Not Leap");
    }

    return 0;
}
