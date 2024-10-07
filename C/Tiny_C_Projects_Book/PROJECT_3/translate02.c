#include<stdio.h>
#include<ctype.h>

# define LINE_SIZE 1000
int main()
{
    FILE *fp; // file pointer
    const char *reference[] = {   // an array of pointers to char (an array of strings)
                                "Alfa", "Bravo", "Charlie", "Delta", "Echo", "Foxtrot",
                                "Golf", "Hotel", "India", "Juliett", "Kilo", "Lima",
                                "Mike", "November", "Oscar", "Papa", "Quebec", "Romeo",
                                "Sierra", "Tango", "Uniform", "Victor", "Whiskey",
                                "Xray", "Yankee", "Zulu"
                                };
    char query[LINE_SIZE];
    int i, index;
    char query_character;
    
    fp=fopen("/mnt/c/Users/Qba Liu/Documents/NAUKA_WLASNA/C/TINY_C_PROJECTS/PROJECT_3/example_file.txt","r");// opening of file

    if (!fp){// checking for error while reading file
    	perror("Error while reading file.");
	return(1);
    }

    // while the fgets() command doesnt output 0, read the file line by line and print each line
    // fgets stores LINE_SIZE characters from the file (pointed to by fp) to the variable contents
    while(fgets(query, LINE_SIZE, fp)){
	printf("%s\n", query);
	i = 0;

	while(query[i]){
		query_character = toupper(query[i]);

		if(isalpha(query_character)){
			index = query_character - 'A';
			printf("%c ---> %s\n", query_character, reference[index]);
		}
		i = i + 1;
	}
    }

    fclose(fp); // closing file
    return(0);
}

