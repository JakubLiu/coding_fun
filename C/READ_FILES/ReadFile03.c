#include <stdio.h>
#include <stdlib.h>
#include "GetFileDim.h"

int* ReadFile_int(char filename[]){
	dim Dims = GetFileDim(filename);
	int rows = Dims.num_rows;
	int columns = Dims.num_cols;
	FILE *file_ptr; // pointer to file
    	int number; // each scalar value read from the file will be stored here !!!!!!!!!
    	int row = 0;
    	int col = 0;
	int* array = malloc((rows * columns) * sizeof(int));

	file_ptr = fopen(filename, "r"); // open file

	// error message if file opening was unsuccessful
    	if (file_ptr == NULL) {
        	perror("Error opening file");
    	}

	// read opened file line by line
    	while (!feof(file_ptr)){
        	fscanf(file_ptr, "%d", &number); // store each scalar value to a variable of type integer ('%d')
        	array[row][col] = number;   // write that variable to the array
        	col = col + 1;  // move to the next column

        	if (fgetc(file_ptr) == '\n') {  // if end of line is reached, move to new row and return to first column
            	row = row + 1;
            	col = 0;
        	}
    	}

    	fclose(file_ptr); // close the file
	return(array);
}


//int main(){
//	int* myarray = ReadFile_int("example_int_file.csv");
//	return(0);
//}
