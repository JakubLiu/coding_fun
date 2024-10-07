/*
Next improvements:
	- read in a csv file
	- read in a file which's dimensions aren't known a priori
	- wrap this into a function
*/

#include <stdio.h>
#include <stdlib.h>
#include "GetFileDim.h"

int ReadFile_int(char filename[]){
	dim file_dimensions = GetFileDim(filename); // get file dimensions as custom struct
	int N_rows = file_dimensions.num_rows;      // extract struct attribute as int
	int N_cols = file_dimensions.num_cols;	    // extract struct attribute as int
	int numbers[N_rows][N_cols];           // initialize array to hold values of the input file
	FILE *file_ptr; // pointer to file
    	int number; // each scalar value read from the file will be stored here !!!!!!!!!
    	int row = 0;
    	int col = 0;

	file_ptr = fopen(filename, "r"); // open file

	// error message if file opening was unsuccessful
    	if (file_ptr == NULL) {
        	perror("Error opening file");
		return(1);
    	}

	// read opened file line by line
    	while (!feof(file_ptr)){
        	fscanf(file_ptr, "%d", &number); // store each scalar value to a variable of type integer ('%d')
        	numbers[row][col] = number;   // write that variable to the array
        	col = col + 1;  // move to the next column

        	if (fgetc(file_ptr) == '\n') {  // if end of line is reached, move to new row and return to first column
            	row = row + 1;
            	col = 0;
        	}
    	}

    	fclose(file_ptr); // close the file

    	// print the array
    	for (int i = 0; i < N_rows; i++) {
        	for (int j = 0; j < N_cols; j++) {
                	printf("%d ", numbers[i][j]);
            	}
        	printf("\n");
        }
	return(0);
}


int main(){
	ReadFile_int("example_int_file.csv");
	return(0);
}
