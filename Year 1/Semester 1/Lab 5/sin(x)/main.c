#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#define M_PI 3.14159265358979323846

long double fact(int num){
    long double f = 1;
    for (int i = 1; i <= num; ++i){
        f *= i;
    }
    return (f);
}

int main() {

	double x, term = 0;
	int n, sign = -1;
	printf("\nEnter Angle in Degree & The Wanted Term: ");
	scanf("%lf %d", &x, &n);

	x = (x * M_PI) / 180;
	double ans = 0;

	for (int j = 1; j <= n*2; j= j + 2){
        sign = -1 * sign;
        term = sign * pow(x,j)/fact(j);
        ans = ans + term;
	}

	printf("calculated %.10lf expected %.10lf\n", ans, sin(x));

	return 0;
}
