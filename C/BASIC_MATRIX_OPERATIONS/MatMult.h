#include<stdio.h>
#include<stdlib.h>

// multiply integer matrices
int** MatMult_int(int* A, int* B, int dimA[2], int dimB[2]){
        int nrowA = dimA[0];
        int ncolA = dimA[1];
        int nrowB = dimB[0];
        int ncolB = dimB[1];
        int matrixA[nrowA][ncolA];
        int matrixB[nrowB][ncolB];
        int i,j,k,row_idx,col_idx,sum;
        int rowA[ncolA], colB[ncolB];

	if(ncolA != ncolB){
		printf("Error: Matrix dimensions do not match.\n");
		exit(1);
	}

	printf("Output matrix dimensions: %d x %d\n", nrowA, ncolB);

        //populate matrices based on pointers
        //then on these matrixes we will do the multiplication, because it is easier to do it on them than on pointers
        for(i=0;i<nrowA;i++){
                for(j=0;j<ncolA;j++){
                        matrixA[i][j] = A[i*ncolA + j];
                }
        }

        for(i=0;i<nrowB;i++){
                for(j=0;j<ncolB;++j){
                        matrixB[i][j] = B[i*ncolB + j];
                }
        }


        // here the multiplication occurs
        int** result = (int**)malloc(nrowA * sizeof(int*)); // allocate space for an array of pointers

        for(i=0;i<nrowA;i++){
                result[i] = (int*)malloc(ncolB * sizeof(int)); // allocate space for each row

                for(j=0;j<ncolB;j++){

                        for(k=0;k<ncolA;k++){
                                rowA[k] = matrixA[i][k];
                                colB[k] = matrixB[k][j];
                        }

                        sum = 0;
                        for(k=0;k<ncolA;k++){
                                sum = sum + rowA[k]*colB[k];
                        }

                        result[i][j] = sum;
                }


        }
        return(result);
}



// multiply float matrices
float** MatMult_float(float* A, float* B, int dimA[2], int dimB[2]){
        int nrowA = dimA[0];
        int ncolA = dimA[1];
        int nrowB = dimB[0];
        int ncolB = dimB[1];
        float matrixA[nrowA][ncolA];
        float matrixB[nrowB][ncolB];
        int i,j,k,row_idx,col_idx,sum;
        float rowA[ncolA], colB[ncolB];

        if(ncolA != ncolB){
                printf("Error: Matrix dimensions do not match.\n");
                exit(1);
        }

        printf("Output matrix dimensions: %d x %d\n", nrowA, ncolB);

        //populate matrices based on pointers
        //then on these matrixes we will do the multiplication, because it is easier to do it on them than on pointers
        for(i=0;i<nrowA;i++){
                for(j=0;j<ncolA;j++){
                        matrixA[i][j] = A[i*ncolA + j];
                }
        }

        for(i=0;i<nrowB;i++){
                for(j=0;j<ncolB;++j){
                        matrixB[i][j] = B[i*ncolB + j];
		}
	}

        // here the multiplication occurs
        float** result = (float**)malloc(nrowA * sizeof(float*)); // allocate space for an array of pointers

        for(i=0;i<nrowA;i++){
                result[i] = (float*)malloc(ncolB * sizeof(float)); // allocate space for each row

                for(j=0;j<ncolB;j++){

                        for(k=0;k<ncolA;k++){
                                rowA[k] = matrixA[i][k];
                                colB[k] = matrixB[k][j];
                        }

                        sum = 0;
                        for(k=0;k<ncolA;k++){
                                sum = sum + rowA[k]*colB[k];
                        }

                        result[i][j] = sum;
                }


        }
        return(result);
}
