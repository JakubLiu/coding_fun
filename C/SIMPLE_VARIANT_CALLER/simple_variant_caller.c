#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define N_SEQUENCES 4     // Number of sequences (including reference)
#define MAX_SEQUENCE_LENGTH 104  // Maximum length of each sequence


int main() {
    FILE *allignment_file;
    /*
    2D array to store the sequences, each sequence is a row,
    each nucleotide is a column.
    */
    char sequences_raw[N_SEQUENCES][MAX_SEQUENCE_LENGTH];
    char sequences_clean[N_SEQUENCES][MAX_SEQUENCE_LENGTH];
    int current_sequence = 0;
    int i,j,k,n_bases_in_ref,REF,ALT;
    char var[4];

    allignment_file = fopen("example_file_no_insert.txt", "r");
    

    // Read each sequence and store it in the current row of the 2D array
    while (fgets(sequences_raw[current_sequence], MAX_SEQUENCE_LENGTH, allignment_file) != NULL) {
        /*
        strcspn() find the index of the 1st occurence of a given character,
        so here we find the colum which has a newline and end the string there.
        */
        sequences_raw[current_sequence][strcspn(sequences_raw[current_sequence], "\n")] = '\0';

        current_sequence = current_sequence + 1;

        if (current_sequence > N_SEQUENCES) {
            printf("Reached maximum number of lines.\n");
            break;
        }
    }

    // remove the sequence identifiers
    for(i=0;i<N_SEQUENCES;i++){
        k = 5;
        for(j=0;j<MAX_SEQUENCE_LENGTH;j++){
            sequences_clean[i][j] = sequences_raw[i][k];
            k = k + 1;
        }
    }


    // count the number of bases in the reference, based on that we will construct an allocatable array for further usage
    n_bases_in_ref = 0;
    for(i=0;i<MAX_SEQUENCE_LENGTH;i++){
        if(sequences_clean[0][i] == 'A' || sequences_clean[0][i] == 'T' || sequences_clean[0][i] == 'C' || sequences_clean[0][i] == 'G'){
            n_bases_in_ref = n_bases_in_ref + 1;
        }
    }


    //create the allocatable array
    //first declare a pointer to the rows/sequences of the array 
    int **sequences_int = (int **)malloc(N_SEQUENCES * sizeof(int *));

    //allocate memory for each row/sequence
    for (int i = 0; i < N_SEQUENCES; i++) {
        sequences_int[i] = (int *)malloc(n_bases_in_ref * sizeof(int));
    }

    //Populate the array
    /*
    A --> 0     T --> 1     C --> 2     G --> 3     - --> -9
    */
    for (int i = 0; i < N_SEQUENCES; i++) {
        for (int j = 0; j < n_bases_in_ref; j++) {
            if(sequences_clean[i][j] == 'A'){
                sequences_int[i][j] = 0;
            }
            else if(sequences_clean[i][j] == 'T'){
                sequences_int[i][j] = 1;
            }
            else if(sequences_clean[i][j] == 'C'){
                sequences_int[i][j] = 2;
            }
            else if(sequences_clean[i][j] == 'G'){
                sequences_int[i][j] = 3;
            }
            else{
                sequences_int[i][j] = -9;
            }
        }
    }
    printf("Sequences:   (sequence 0 is the reference)\n");
    for (int i = 0; i < N_SEQUENCES; i++) {
        for (int j = 0; j < n_bases_in_ref; j++) {
            printf("%c ", sequences_clean[i][j]);
        }
        printf("\n");
    }

    // Close the file
    fclose(allignment_file);

    //call the variants
    for(i=1;i<N_SEQUENCES;i++){         //iterate over the sequences
        for(j=0;j<n_bases_in_ref;j++){   // iterate over the bases of the current sequence
            if(sequences_int[i][j] != sequences_int[0][j]){
                REF = sequences_int[0][j];
                ALT = sequences_int[i][j];
                if(ALT == -9){strcpy(var, "del");}
                if(REF == 0 && ALT == 1){strcpy(var,"A>T");}
                if(REF == 0 && ALT == 2){strcpy(var,"A>C");}
                if(REF == 0 && ALT == 3){strcpy(var,"A>G");}
                if(REF == 1 && ALT == 0){strcpy(var,"T>A");}
                if(REF == 1 && ALT == 2){strcpy(var,"T>C");}
                if(REF == 1 && ALT == 3){strcpy(var,"T>G");}
                if(REF == 2 && ALT == 0){strcpy(var,"C>A");}
                if(REF == 2 && ALT == 1){strcpy(var,"C>T");}
                if(REF == 2 && ALT == 3){strcpy(var,"C>G");}
                if(REF == 3 && ALT == 0){strcpy(var,"G>A");}
                if(REF == 3 && ALT == 1){strcpy(var,"C>T");}
                if(REF == 3 && ALT == 2){strcpy(var,"G>C");}

                printf("Variant %s in sequence %d\n", var,i);
            }
        }
    }


    return(0);
}
