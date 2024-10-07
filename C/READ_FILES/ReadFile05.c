#include<stdio.h>
#include<stdlib.h>
#include"GetFileDim.h"

float** ReadFile_float(char filename[]){
	dim Dims = GetFileDim(filename);
	int rows = Dims.num_rows;
	int columns = Dims.num_cols;
	FILE *file_ptr;
	float number;
	int i,j;
	printf("%d %d\n", rows, columns);

	file_ptr = fopen(filename, "r");

	// allocate memory for an array of pointers
	float** array = (float**)malloc(rows * sizeof(float*));
		
	for(i=0;i<rows;i++){
		array[i] = (float*)malloc(columns * sizeof(float)); // allocate memory for each row

		for(j=0;j<columns;j++){
			fscanf(file_ptr, "%f", &number);
			array[i][j] = number;            // write the number into the array
			}
	}

	fclose(file_ptr);
	printf("Output array dimensions:\nrows: %d\ncolumns: %d\n", i, j);
	return(array);
}


int main(){
	float** result_array;
	int i,j;
	result_array = ReadFile_float("example_float_file.txt");

	for(i = 0;i<2;++i){
		for(j=0; j<3; ++j){
			printf("%f ", result_array[i][j]);
		}
		printf("\n");
	}
	return(0);
}
