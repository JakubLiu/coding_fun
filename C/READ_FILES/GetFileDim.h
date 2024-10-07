#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <ctype.h>
#define MAX_LINE_LEN 100

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
	float temp;
	dim result;

    	file_ptr = fopen(file_name, "r"); // open file

	/*
    	// iterate over the columns to get the column count
    	while(!feof(file_ptr)){

           if(!isspace(fgetc(file_ptr))){
                n_cols = n_cols + 1;

                if (fgetc(file_ptr) == '\n'){
                        break;
                }

            }
	   
    	}
	*/


	while (fscanf(file_ptr, "%f", &temp) == 1) {
        	n_cols = n_cols + 1;
        if (fgetc(file_ptr) == '\n') {
            break;  // Stop at the end of the first row
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
