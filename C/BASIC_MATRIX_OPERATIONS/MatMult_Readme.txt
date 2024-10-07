int main(){

        int mat1[4] = {1,2,3,4};   // input matrices must be defined as 1D arrays
        int mat2[4] = {1,2,3,4};

        int* ptr_mat1 = mat1;      // initialize pointers to these arrays
        int* ptr_mat2 = mat2;

        int dim_mat1[2] = {2,2};   // 1D arrays of length two denoting the sizes of the input matrices must be provided
        int dim_mat2[2] = {2,2};

        int** res;                 // the result will be a 2D array of pointers

        res = MatMult_int(ptr_mat1, ptr_mat2, dim_mat1, dim_mat2);    // call the function


        for(int i=0;i<2;i++){				// print the resulting matrix
                for(int j=0;j<2;j++){
                        printf("%d ", res[i][j]);
                }
                printf("\n");
        }
        return(0);
}
