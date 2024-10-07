#include <stdio.h>
#include <time.h>
#include <string.h>

int main()
{
	time_t now;
	struct tm *clock;
	int hour, minute, second;
	char daytime[20];
	time(&now);
	clock = localtime(&now);
	hour = clock->tm_hour;
	minute = clock->tm_min;
	second = clock->tm_sec;

	if(hour < 12){
		strcpy(daytime, "morning");
		printf("Good %s, its %d:%d:%d\n",daytime, hour, minute, second);
	}
	else if(hour < 18){
		strcpy(daytime, "afternoon");
		printf("Good %s, its %d:%d:%d\n", daytime, hour, minute, second);
	}
	else{
		strcpy(daytime, "evening");
		printf("Good %s, its %d:%d:%d\n", daytime, hour, minute, second);
	}
	return(0);
}
