#include<stdio.h>
#define PI 3.14159
int main(void)
{ 
	 int radius;
	 double volume;
	 printf("Enter radius:");
	 scanf("%d", &radius);
	 volume = 4*radius*radius*radius/3;
	 printf("volume is : %f \n", volume);
	 return 0;
}
