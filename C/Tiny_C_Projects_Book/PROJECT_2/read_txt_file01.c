#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BSIZE 256 // define a constant buffer size

int main()
{
	// constant array of characters to hold the path to the input file
	const char filename[] = "/mnt/c/Users/Qba Liu/Documents/NAUKA_WLASNA/C/TINY_C_PROJECTS/PROJECT_2/demo_textfile.txt";
	char buffer[BSIZE]; // in this array each line of the file will be stored
	char *r; // a pointer for diagnostic purposes (will be made clear below)
	FILE *fp; // this pointer is of type FILE and will point to the specified text file

	fp = fopen(filename, "r"); // point the fp pointer to our file ('r' is for reading mode)

	if(fp == NULL){
		fprintf(stderr, "Unable to open file!");
		exit(1);
	}

	while(!feof(fp)){ // iterate untill the end of file is not reached
		/*
		fgets(destination, n, file) n characters from 'file' to 'destination'.
		In out case fgets() stores BSIZE characters from the file pointed to by fp to the buffer array.
		Actually we only assign the output of fgets to the variable r for diagnostic purposes.
		*/
		r = fgets(buffer, BSIZE, fp);

		if(r == NULL){
			break;
		}

		printf("%s\n", buffer);
	}

	fclose(fp);  // when the end of file is reached, close the file

	return(0);
}
