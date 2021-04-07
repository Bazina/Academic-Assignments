#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(){
    int m, n, i, j, pos = 1;
    printf("Enter Matrix Dim n & m: ");
    scanf("%d %d", &n, &m);
    int mat[n][m], rsum[n];
    printf("Enter Matrix Elements: \n");
    for (i = 0; i < n; i++){
        rsum[i] = 0;
        for (j = 0; j < m; j++){
            scanf("%d", &mat[i][j]);
            rsum[i] = rsum[i] + mat[i][j];
        }
    }
    for (i = 0; i < n; i++){
        if (rsum[i] > rsum[pos]){
            pos = i;
        }
    }
    for (i = 0; i < m; i++){
        int temp = mat[pos][i];
        mat[pos][i] = mat[0][i];
        mat[0][i] = temp;
    }

    printf("\nNew Matrix: \n");
    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            printf("%d ", mat[i][j]);
            if (j == m-1){
                printf("\n");
            }
        }
    }

    return 0;
}
