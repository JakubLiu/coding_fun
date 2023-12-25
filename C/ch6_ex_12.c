#include<stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 5       // maximum degree of polynomial


double eval(double x){

	double sum = 0.00;     // value of polynomial at x
	double polynom[N+1];   // define polynomial
	int i, k;
	double j;

	for (k = 0; k <= N; ++k){              // populate polynomial
		polynom[k] = rand()%100;
	}

	for (i = 0, j = 0; i <= N, j <= N; ++i, ++j){  // calculate value of polynomial at x
		sum = sum + polynom[i]*pow(x,j);
	}

	return sum;
}

int main(void){

	double x;
	printf("%lf\n", eval(x));

	return 0;
}
