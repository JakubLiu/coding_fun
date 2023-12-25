#include <stdio.h>

int recursive_fibonacci(int n){

	if (n <= 1)
		return n;
	else
		return(recursive_fibonacci(n-1) + recursive_fibonacci(n-2));

}


int interative_fibonacci(int n){

	long fib_1 = 1, fib_2 = 0, fib_prev;
	int i;

	for (i = 0; i < n; i++){
		fib_prev = fib_2;
		fib_2 = fib_2 + fib_1;
		fib_1 = fib_prev;
	};

	return fib_2;

}


int main(void){

	int n, i;
	printf("Up to when do you want to calculate the fibonacci sequence?: ");
	scanf("%d", &n);

	for (i = 0; i < n; i++)
		printf("N = %d\tFibonacci recursive\t%d\tFibonacci iterative\t%d", i, recursive_fibonacci(i), interative_fibonacci(i));

	return 0;

}
