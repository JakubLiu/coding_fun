/*
Next improvements:
	- read in a csv file
	- read in a file which's dimensions aren't known a priori
	- wrap this into a function
*/

#include <stdio.h>
#include <stdlib.h>

// the number of rows and columns in the file must be known a priori (improve)
#define N_ROWS 4
#define N_COLS 3

int main() {
    FILE *file_ptr; // pointer to file
    int number; // each scalar value read from the file will be stored here
    int row = 0;
    int col = 0;
    int numbers[N_ROWS][N_COLS] = {0}; // a 2D array to which the scalar values will be written (initalize all its elements to 0)

    file_ptr = fopen("example_int_file.csv", "r"); // open file
    
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
    for (int i = 0; i < N_ROWS; i++) {
        for (int j = 0; j < N_COLS; j++) {
                printf("%d ", numbers[i][j]);
            }
	printf("\n");
        }

    return(0);
}


