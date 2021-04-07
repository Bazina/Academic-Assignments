#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int x;
    int i,f=1;
    printf("\nEnter Number: ");
    scanf("%d",&x);

    int h=x;
    if (x==0){
        printf("%d is a palindrome number",x);
    }
    else {
        if (x<0){
            h=(-1)*x;
        }

        int n= log10(h)+1;
        int arr[n];

        for(i=0;i<n;i++,h/=10){
            arr[i]=h%10;
        }

        for(i=0;i<n/2;i++){
            if (arr[i]!=arr[n-1-i]){
                f=0;
            }
        }
        if (f==1){
            printf("%d is a palindrome number",x);
        }
        else {
            printf("%d is not a palindrome number",x);
        }
    }

    return 0;
}
