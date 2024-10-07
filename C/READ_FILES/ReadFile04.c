#include<stdio.h>
#include<stdlib.h>
#include"GetFileDim.h"

int** ReadFile_int(char filename[]){
	dim Dims = GetFileDim(filename);
	int rows = Dims.num_rows;
	int columns = Dims.num_cols;
	FILE *file_ptr;
	int number;
	int i,j;

	file_ptr = fopen(filename, "r");

	// allocate memory for an array of pointers
	int** array = (int**)malloc(rows * sizeof(int*));
		
	for(i=0;i<rows;i++){
		array[i] = (int*)malloc(columns * sizeof(int)); // allocate memory for each row

		for(j=0;j<columns;j++){
			fscanf(file_ptr, "%d", &number);
			array[i][j] = number;            // write the number into the array
			}
	}

	fclose(file_ptr);
	printf("Output array dimensions:\nrows: %d\ncolumns: %d\n", i, j);
	return(array);
}


int main(){
	int** result_array;
	int i,j;
	result_array = ReadFile_int("example_int_file.txt");

	for(i = 0;i<5;++i){
		for(j=0; j<3; ++j){
			printf("%d ", result_array[i][j]);
		}
		printf("\n");
	}
	return(0);
}
