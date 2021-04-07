#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX 256

int main() {
    char word[MAX], line[MAX];
    int cIndex = 0, cTimes = 0, t, i, j, i1;
    printf("Enter a statement: ");
    fgets(line, MAX, stdin);
    printf("Enter the key word: ");
    scanf("%s", word);
    int lenWord = strlen(word);
    int lenLine = strlen(line);

    for (i1 = 0; i1 < lenLine; i1++){
        cIndex = 0;
        for (j = 0, i = i1; j < lenWord && line[i] == word[j]; j++, i++){
            cIndex++;
        }
        if (cIndex == lenWord){
            t = i - lenWord;
            cTimes++;
            printf("Occurrence at index %d\n", t);
            cIndex = 0;
        }
    }
    printf("Total number of occurrences = %d\n", cTimes);

    return 0;
}
