#include<stdio.h>
#include<stdlib.h>

int** Transpose_int(int* mat, int dim_in[2]){

	int nrow_in = dim_in[0];
	int ncol_in = dim_in[1];
	int nrow_out = ncol_in;
	int ncol_out = nrow_in;
	int matrix_in[nrow_in][ncol_in];

	int i,j;

	// populate the matrix based on the pointer from the input
	for(i=0;i<nrow_in;i++){
                for(j=0;j<ncol_in;j++){
                        matrix_in[i][j] = mat[i*ncol_in + j];
                }
        }

	int** matrix_out = (int**)malloc(nrow_out * sizeof(int*));

	for(i=0;i<nrow_in;i++){

		matrix_out[j] = (int*)malloc(ncol_out * sizeof(int));

		for(j=0;j<ncol_in;j++){
		
			matrix_out[j][i] = matrix_in[i][j];	
			printf("%d ", matrix_out[j][i]);
		}
		printf("\n");
	}

	return(matrix_out);
}
