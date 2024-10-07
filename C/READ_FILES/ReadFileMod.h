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

// get dimensions of an integer file
dim GetFileDim_int(char file_name[]){
        FILE *file_ptr;
        int n_rows = 0;
        int n_cols = 0;
        char line[MAX_LINE_LEN];
        dim result;

        file_ptr = fopen(file_name, "r"); // open file

        // iterate over the columns to get the column count
        while(!feof(file_ptr)){

           if(!isspace(fgetc(file_ptr))){
                n_cols = n_cols + 1;
                if (fgetc(file_ptr) == '\n'){
                    break;
                }
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



// get dimensions of a float file
dim GetFileDim_float(char file_name[]){
        FILE *file_ptr;
        int n_rows = 0;
        int n_cols = 0;
        char line[MAX_LINE_LEN];
	float float_num;
        dim result;

        file_ptr = fopen(file_name, "r"); // open file

	// iterate over the 1st row to get the number of columns
	while(fscanf(file_ptr, "%f", &float_num) == 1) {
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



// read the file as integers

int** ReadFile_int(char filename[]){
        dim Dims = GetFileDim_int(filename);
        int rows = Dims.num_rows;
        int columns = Dims.num_cols;
        FILE *file_ptr;
        char* token;
	char line[1025];
        int i,j;
	char list_of_delimiters[7] = " ,;\t\n";   // these are the possible delimiters in the input files

        file_ptr = fopen(filename, "r");

        // allocate memory for an array of pointers
        int** array = (int**)malloc(rows * sizeof(int*));

        for(i=0;i<rows;i++){
		array[i] = (int*)malloc(columns * sizeof(int));
                fgets(line, sizeof(line), file_ptr); // Read a line from the file
    		token = strtok(line, list_of_delimiters); // Tokenize the line based on list of delimiters
    		j = 0;
    		while(token != NULL && j < columns){
        		array[i][j] = atoi(token); // Convert token to integer and store it in the array
        		token = strtok(NULL, list_of_delimiters); // Get the next token
        		j = j + 1;
        	}
	}

        fclose(file_ptr);
        printf("Output array dimensions:\nrows: %d\ncolumns: %d\n", i, j);
        return(array);
}


// read a file as floats
float** ReadFile_float(char filename[]){
        dim Dims = GetFileDim_float(filename);
        int rows = Dims.num_rows;
        int columns = Dims.num_cols;
        FILE *file_ptr;
        char* token;
	char line[1025];
        int i,j;
	char list_of_delimiters[7] = " ,;\t\n";   // these are the possible delimiters in the input files

        file_ptr = fopen(filename, "r");

        // allocate memory for an array of pointers
        float** array = (float**)malloc(rows * sizeof(float*));

        for(i=0;i<rows;i++){
                array[i] = (float*)malloc(columns * sizeof(float)); // allocate memory for each row
		fgets(line, sizeof(line), file_ptr); // Read a line from the file
                token = strtok(line, list_of_delimiters); // Tokenize the line based on list of delimiters
                j = 0;
                while(token != NULL && j < columns){
                        array[i][j] = atof(token); // Convert token to integer and store it in the array
                        token = strtok(NULL, list_of_delimiters); // Get the next token
                        j = j + 1;
                }
	}
        fclose(file_ptr);
        printf("Output array dimensions:\nrows: %d\ncolumns: %d\n", i, j);
        return(array);
}


