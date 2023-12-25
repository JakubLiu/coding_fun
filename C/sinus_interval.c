
/*

   - the builtin abs() function needs an int as an argument, but the variable interval is a double
   - the builtin function fabs() accepts doubles as arguments
   - use fabs() instead of abs() in this case
*/



#include<stdio.h>
#include<math.h> /* has  sin(), abs(), and fabs() */
int main(void)
{ 
	double interval;
	int i;
	for(i = 0; i <30; i++)
	{
		 interval = i/10.0;
		 printf("sin( %lf ) = %lf \t", interval, fabs(sin(interval)));
	}


	printf("\n+++++++\n");
	return 0;
}
