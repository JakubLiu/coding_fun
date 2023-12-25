/*
The goal is to write a programme that prints all the factors of a given number.

The quickest way to find the factors of a number is to divide it by the smallest prime number (bigger than 1) that goes into it evenly with no remainder. Continue this process with each number you get, until you reach 1.

QBA LIU 2023 ---------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>

int prime(int num){
        // return 1 if num is prime
        // return 0 if num us not prime
        int out = 1, i;
        for (i = 2; i <= 1000 && i != num; ++i){
                if (num%i == 0){
                        out = 0;
                };
        }
        return out;
}

int main(void){
	
	int mynum, mynum_orig, i;
	printf("Enter a number: \n");
	scanf("%d", &mynum);
	mynum_orig = mynum;
	printf("The factors of %d are:\n", mynum);
	printf("-------------------------------\n");

	for (i = 2; i <= mynum_orig; ++i){
		if (prime(i) == 1){
			if (mynum%i == 0){
				while (mynum%i == 0){
					printf("%d\n", i);
					mynum = mynum/i;
				}
			}
		}
	}

	return 0;
}
