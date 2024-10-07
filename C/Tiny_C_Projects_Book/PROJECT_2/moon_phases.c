#include <stdio.h>
#include <time.h>
#include <string.h>

//algorithm to determine the moon phase based on year, day and month
//it returns an integer in the rage (0,7) corresponding to the moon phase
int moon_phase(int year,int month,int day)
{
	int d,g,e;
 	d = day;
	
	if(month == 2){
 		d += 31;
	}
 	
	else if(month > 2){
 		d += 59+(month-3)*30.6+0.5;
 		g = (year-1900)%19;
 		e = (11*g + 29) % 30;
	}
 	
	if(e == 25 || e == 24){
 		++e;
	}
 	
	return ((((e + d)*6+5)%177)/22 & 7);
}

int main(){
	// here they declare an array of pointers to char (an array of pointers, where each pointer points to a character type)
	// each pointer points to the 1st character of each string
	// If we want to declare a single string, than this string is an array of chars (not an array of pointer to chars)
	// if we want to declare a whole array of strings (like in time02.c), than this array must be an array of pointers to chars
	char *phase[8] = {"waxing crescent", "at first quarter",
 			"waxing gibbous", "full", "waning gibbous",
 			"at last quarter", "waning crescent", "new"};
	time_t now;
	struct tm *clock;
	int moon_phase_int;

	time(&now);
	clock = localtime(&now);
	moon_phase_int = moon_phase(clock->tm_year+1900, clock->tm_mon+1, clock->tm_mday);
	printf("The current moon phase is: %s\n", phase[moon_phase_int]);
	return(0);
}


