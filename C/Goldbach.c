/*
The aim of this programme is to proove that any (of the tested) even integer number can be represented as a sum of two prime numbers

QBA LIU 2023 ------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#define START  100
#define END  1000

int prime(int num){
	// return 1 if num is prime
	// return 0 if num us not prime
	
	int out = 1;
	int i;

	for (i = 2; i <= 100 && i != num; ++i){
		if (num%i == 0){
			out = 0;
		};
	}

	return out;
}

int even(int num){
	// return 1 if num is even
	// retrun 0 if num is odd
	int out = 1;
	int i;

	if (num%2 != 0){
		out = 0;
	}

	return out;
}

int main(void){
	
	printf("Every even number greater than 2 is the sum of two prime numbers.\n");
	printf("-----------------------------------------------------------------\n");

	int i;
	int a, b;

	for (i = START; i <= END; ++i){		// loop through i
		if (even(i) == 1){
			for (a = 2; a <= i/2; ++a){		// loop through a
				if (prime(a) == 1){
					for (b = 2; b <= i - a; ++b){       // loop through b
						if (prime(b) == 1){
							if ( a + b == i){
								printf("%d = %d + %d\n",i, a, b);
								break;
							}
						}
					}
				}
	
			}
	
		}

	}


	return 0;
}

