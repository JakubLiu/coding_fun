#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

# define MAX_QUERY_LEN 100 // define the longest permisable query length as a constant

int main(){
	const char *reference[] = {   // an array of pointers to char (an array of strings)
 				"Alfa", "Bravo", "Charlie", "Delta", "Echo", "Foxtrot",
				"Golf", "Hotel", "India", "Juliett", "Kilo", "Lima",
				"Mike", "November", "Oscar", "Papa", "Quebec", "Romeo",
				"Sierra", "Tango", "Uniform", "Victor", "Whiskey",
				"Xray", "Yankee", "Zulu"	
 				};
	char query[MAX_QUERY_LEN]; // an array of chars (a string)
	char query_character;
	int i, index;

	printf("Enter query word or sentence:\n");
	fgets(query, MAX_QUERY_LEN, stdin); // store MAX_QUERY_LEN chars from stdin into the variable query
	printf("Query ---> Translation\n");

	i = 0;
	while(query[i]){ // if the sentinel (/0) is reached then this expression will be false
		query_character = toupper(query[i]); // convert character to uppercase

		if(isalpha(query_character)){
			index = query_character - 'A'; // the output of this in an integer (character arithmetic)
			printf("%c ---> %s\n", query_character, reference[index]);
		}
		
		i = i + 1;

		if(i==MAX_QUERY_LEN){ // if the input query is too large, break
			break;
		}
	}
	return(0);
}
