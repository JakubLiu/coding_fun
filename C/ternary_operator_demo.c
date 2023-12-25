/*
Code to demonstrate the use of ternary operators.
 */

#include <stdio.h>

int main()
{
int age;
printf("Enter your age: ");
scanf("%d", &age);
age = (age < 0)? (1) : (age < 18)? (2) : (age <= 70)? (3) : (4);
switch (age)
{
	case 1: printf("Wrong input\n");break;
	case 2: printf("You are a child\n");break;
	case 3: printf("You are an adult\n");break;
	case 4: printf("You are a senior\n");break;
}
return 0;
}
