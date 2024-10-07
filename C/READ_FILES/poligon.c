#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <ctype.h>
#include "ReadFileMod.h"

int main(){
	float** res;
	int i,j;
	res = ReadFile_float("example_float_file.txt");

	for(i=0;i<2;++i){
		for(j=0;j<3;++j){	
			printf("%f ", res[i][j]);
		}
		
		printf("\n");

	}
	return(0);
}
