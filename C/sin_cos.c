#include<stdio.h>
#include<math.h>
int main(void)
{
	double i;
	double sinus;
	double cosinus;
	for(i = 0.00; i <= 1.00;)
	{
		sinus = sin(i);
		cosinus = cos(i);
		printf("Sinus of %lf is %lf\n", i, sinus);
		printf("Cosinus of %lf is %lf\n", i, cosinus);
		i += 0.01;
	}

return 0;
}
