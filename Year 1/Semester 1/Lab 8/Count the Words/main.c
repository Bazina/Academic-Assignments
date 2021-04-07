#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 256

int main(){
    char line[MAX];
    int count = 0, i;
    printf("Enter a statement: ");
    fgets(line, MAX, stdin);
    int lenLine = strlen(line);
    for (i = 0; i < lenLine; i++){
        if(!isalnum(line[i+1]) && isalnum(line[i])){
            count++;
        }
    }
    printf("%d words\n", count);
    return 0;
}
