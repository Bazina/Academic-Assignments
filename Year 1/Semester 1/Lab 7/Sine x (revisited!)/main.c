#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#define M_PI 3.14159265358979323846

double radian(double ang){
    double rang = (ang * M_PI) / 180;
    return (rang);
}

long double fact(int num){
    long double f = 1;
    for (int i = 1; i <= num; ++i){
        f *= i;
    }
    return (f);
}

double power(double angle, int p){
    double p_term = 1;
    while (p != 0) {
        p_term *= angle;
        --p;
    }
    return (p_term);
}

double calc_sine(double deg, int nterms){
    int sign = -1;
    double term = 0, ans = 0;
    double rad_ang = radian(deg);
    for (int i = 1; i <= nterms*2; i += 2){
        sign = -1 * sign;
        term = sign * power(rad_ang, i)/fact(i);
        ans = ans + term;
	}
    return (ans);
}

int main() {
    double x, answer = 0;
    int n;
    printf("\nEnter angle & terms: ");
    scanf("%lf %d", &x, &n);

    answer = calc_sine(x, n);

   	printf("calculated %.10lf expected %.10lf\n", answer, sin(radian(x)));

   	return 0;
}
