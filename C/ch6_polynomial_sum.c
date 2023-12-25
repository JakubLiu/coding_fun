/*
This programme takes two polynomials and adds them at a given value of x.
QBA LIU 2023 -------------------------------------------------------------------------------------------------------------------
*/


#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define N 2        // maximum degree of both polynomials to be added

double polynom_add(double x){
	double polynom1[N+1], polynom2[N+1], sum = 0.00, k;
	int i, j;

	// defining the coefficients of the two polyniamls (a0 + a1x^1 + a2x^2 ...)
	for (i = 0; i <= N; ++i){
		printf("Enter coefficient for x%d for polyomial 1:\n", i);
		scanf("%lf", &polynom1[i]);
		printf("Enter coefficient for x%d for polyomial 2:\n", i);
		scanf("%lf", &polynom2[i]);
	}

	// summing the two polynomials at x
	for (j = 0, k = 0; j <= N, k <= N; ++j, ++k){
		sum = sum + ((polynom1[j]*pow(x,k)) + polynom2[j]*pow(x,k));
	}

	printf("The sum of the two polynomials at x is: \n");
	return sum;
}

int main(void){
	
	double x;
	printf("Enter x: ");
	scanf("%lf", &x);
	printf("%lf\n", polynom_add(x));
	return 0;
}
