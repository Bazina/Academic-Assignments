#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int y;
    printf("Enter a year: ");
    scanf("%d", &y);
    if (y <= 100000 && y>=0){
        if (y%400 == 0) {
            printf("Leap");
        }
        else if (y%100 == 0) {
            printf("Not Leap");
        }
        else if (y%4 == 0) {
                printf("Leap");
        }
        else {
            printf("Not Leap");
        }
    }

    return 0;
}
