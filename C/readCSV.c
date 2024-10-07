#include <stdio.h>
#define ROWS 5
#define COLUMNS 3

int main(void){
	int array[ROWS][COLUMNS];
	FILE *file;
	file = fopen("example.txt", "r");

	if (file == NULL){
		printf("Error opening file.\n");
		return 1;
	}

	int row = 0;
	while (!feof(file)){
		
		if (ferror(file)){
			printf("Error reading file.\n");
			return 1;
		}

		for (int i = 0; i < COLUMNS; i++){
			if (fscanf(file, "%d", &array[row][i]) == EOF)
				break;
		}
		
		row++;

		if(row == ROWS) break;
	}

	fclose(file);


	for(int i = 0; i < ROWS; i++){
		for(int j = 0; j < COLUMNS; j++){
			printf("%d", array[i][j]);
			printf("\n");
		}
	}


	return 0;
}
