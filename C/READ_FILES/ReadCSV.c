#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

#define MAXCHAR 1000

int main(){

    FILE *fp;
    char row[MAXCHAR];
    char *entry;
    int row_num = 0;

    fp = fopen("/mnt/c/Users/Qba Liu/Documents/NAUKA_WLASNA/C/TINY_C_PROJECTS/genes_by_sig_unique.csv","r");


    while (feof(fp) != true)
    {
        fgets(row, MAXCHAR, fp);
        entry = strtok(row, ",");
	printf("row: %d __________\n", row_num);
	row_num = row_num + 1;

        while(entry != NULL)
        {
            printf("entry: %2.2f\n",strtod(entry,NULL));
            entry = strtok(NULL, ",");
        }

    }
    

    return 0;

}

