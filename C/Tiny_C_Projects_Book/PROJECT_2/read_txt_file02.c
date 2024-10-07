/*
 Modification in contrast to read_txt_file01.c

	- added 'entry' allocatable pointer array
	- added counter 'num_lines_read', of how many lines were read

	The logic behind the intorduction of the 'entry' array is that sometimes the size of
	a line in the txt file is smaller than BSIZE and it is an overkill to allocate BSIZE memory for it.


	entry = (char *)malloc(sizeof(char) * strlen(buffer)+1);

		- The array 'buffer' holds the current line (plus some emtpy space up to BSIZE).
		- strlen(buffer) is just the number of chars in the line (+1) because of the sentinel.
		- sizeof(char) * strlen(buffer)+1 allocates the number of bits needed for a char * the number of chars.
		- (char *) casts the output of malloc to the desired type.
		- so, entry is a pointer which points to the 1st memoty address of the allocated memory chunk
	 
	strcpy(entry, buffer);
		
		- all this above was just to allocate space in memory
		- this line copies the contents of buffer (only the chars) to the allocated memory space
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>  // this header file needs to be included

#define BSIZE 256 // define a constant buffer size

int main()
{
	// constant array of characters to hold the path to the input file
	const char filename[] = "/mnt/c/Users/Qba Liu/Documents/NAUKA_WLASNA/C/TINY_C_PROJECTS/PROJECT_1/demo_textfile.txt";
	char buffer[BSIZE]; // in this array each line of the file will be stored
	char *r; // a pointer for diagnostic purposes (will be made clear below)
	FILE *fp; // this pointer is of type FILE and will point to the specified text file
	char *entry;
	int num_lines_read = 0;

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
		
		entry = (char *)malloc(sizeof(char) * strlen(buffer)+1); // see explanation above
		if(entry == NULL){
			fprintf(stderr, "Unable to allocate memory.\n");
		}
		strcpy(entry, buffer); // see explanation above
		printf("%s\n", entry);

		if(r == NULL){
			break;
		}
		num_lines_read = num_lines_read + 1;

	}

	fclose(fp);  // when the end of file is reached, close the file
	printf("\n\n\nNumber of lines read: %d\n", num_lines_read);

	return(0);
}
