#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <ctype.h>
#define MAX_LINE_LEN 10000

// define the custom return type of the GetFileDim function
typedef struct {
    int num_rows;
    int num_cols;
} dim;


dim GetFileDim(char file_name[]){
	FILE *file_ptr;
	int n_rows = 0;
    	int n_cols = 0;
    	char line[MAX_LINE_LEN];
	char* splitted_line;
	dim result;

    	file_ptr = fopen(file_name, "r"); // open file


	// Get the first line to count columns
    	if (fgets(line, MAX_LINE_LEN, file_ptr) != NULL) {
        	// Count the number of words (columns) in the first line
        	splitted_line = strtok(line, " \t\n"); // split the current line by possible delimiters
        					       // here possible delimiters are: " ", "\t", "\n"
		while(splitted_line != NULL){
            		n_cols = n_cols + 1;

            	splitted_line = strtok(NULL, " \t\n");
        	}
    	}

    	// iterate over the rows to get the row count
    	while(!feof(file_ptr)){
        	fgets(line, MAX_LINE_LEN, file_ptr);
        	n_rows = n_rows + 1;
    	}

    result.num_rows = n_rows;
    result.num_cols = n_cols;
    fclose(file_ptr);
    return(result);
}


int main(){
	dim Dims = GetFileDim("example_char_file.txt");
	int rows = Dims.num_rows;
	int cols = Dims.num_cols;
	printf("%d   %d\n", rows, cols);
}
