/*
This function multiplies two polynomials and returns a value of this product at a given value of x.
For example:
	(2x^2 + 2x + 2) * (2x + 2) at x = 1 has the value of 24

QBA LIU 2023 ----------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

double polynom_multi(double x, int N){
        double polynom1[N+1], polynom2[N+1], sum = 0.00, k, kk, exponent1, exponent2;
        int i, j, ii, jj;

        // defining the coefficients of the two polyniamls (a0 + a1x^1 + a2x^2 ...)
        for (i = 0; i <= N; ++i){
                printf("Enter coefficient for x%d for polyomial 1:\n", i);
                scanf("%lf", &polynom1[i]);
                printf("Enter coefficient for x%d for polyomial 2:\n", i);
                scanf("%lf", &polynom2[i]);
        }

	// multiplying the two polynomials
	for (j = 0, k = 0; j <= N, k <= N; ++j, ++k){
		exponent1 = k;

		for (jj = 0, kk = 0; jj <= N, kk <= N; ++jj, ++kk){
			exponent2 = k + kk;
			sum = sum + (polynom1[j]*pow(x,exponent1)) * (polynom2[jj]*pow(x,exponent2));
		}
	}

        printf("The product of the two polynomials at x is: \n");
        return sum;
}

int main(void){
	int N;
        double x;
	printf("Enter maximum degree of x: \n");
	scanf("%d", &N);
        printf("Enter x: \n");
        scanf("%lf", &x);
        printf("%lf\n", polynom_multi(x, N));
        return 0;
}
