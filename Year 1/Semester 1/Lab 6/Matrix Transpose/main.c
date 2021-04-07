#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int m, n, i, j;
    printf("Enter Matrix Dim n & m: ");
    scanf("%d %d", &n, &m);
    int mat[n][m], trans[m][n];
    printf("Enter Matrix Elements: ");
    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            scanf("%d", &mat[i][j]);
            trans[j][i] = mat[i][j];
        }
    }
    printf("Transpose: \n");
    for (i = 0; i < m; i++){
        for (j = 0; j < n; j++){
            printf("%d ", trans[i][j]);
            if (j == n-1){
                printf("\n");
            }
        }
    }
    return 0;
}
