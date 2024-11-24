#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

//#define N_SEQUENCES 4     // Number of sequences (including reference)
//#define MAX_SEQUENCE_LENGTH 104  // Maximum length of each sequence


int main(int argc, char *argv[]) {
    FILE *allignment_file, *output_file;
    /*
    2D array to store the sequences, each sequence is a row,
    each nucleotide is a column.
    */
    char* input_filename;  // -i flag for input filename
    char* output_filename; // -o flag for output filename
    int N_SEQUENCES;     // -nseq flag for N_SEQUENCES
    int MAX_SEQUENCE_LENGTH;  // -max_seq_len flag for MAX_SEQUENCE_LENGTH

    int i;

    // iterate over the command line arguments, but start from i=1, because the 1st command line argument is always the programme name
    for(i=1;i<argc;i++){

        if(strcmp(argv[i], "-i") == 0 && i + 1 < argc){ // look for the "-i" flag
            input_filename = argv[i+1];  // if flag is found the next argument will be the filename itself
            i = i + 1;  // increment i, because the next argument is the filename
        }

        else if(strcmp(argv[i], "-o") == 0 && i + 1 < argc){
            output_filename = argv[i+1];
            i = i + 1;
        }

        else if(strcmp(argv[i], "-nseq") == 0 && i + 1 < argc){
            N_SEQUENCES = atoi(argv[i+1]);   // we need to convert to integer
            i = i + 1;
        }

        else if(strcmp(argv[i], "-max_seq_len") == 0 && i + 1 < argc){
            MAX_SEQUENCE_LENGTH = atoi(argv[i+1]);
            i = i + 1;
        }

        else{
            printf("No such flag is recognized.");
        }
    }





    char sequences_raw[N_SEQUENCES][MAX_SEQUENCE_LENGTH];
    char sequences_clean[N_SEQUENCES][MAX_SEQUENCE_LENGTH];
    int current_sequence;
    int j,k,n_bases_in_ref,REF,ALT,variant_num;
    char var[4];
    char line[100];

    allignment_file = fopen(input_filename, "r");
    
    current_sequence = 0;
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

    //open the empty output file
    output_file = fopen(output_filename, "w");
    fprintf(output_file, "VARIANT_NUM,SEQUENCE,POSITION,TYPE\n");


    //call the variants
    variant_num = 0;
    for(i=1;i<N_SEQUENCES;i++){         //iterate over the sequences
        for(j=0;j<n_bases_in_ref;j++){   // iterate over the bases of the current sequence
            if(sequences_int[i][j] != sequences_int[0][j]){
                variant_num = variant_num + 1;
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

                fprintf(output_file, "%d,%d,%d,%s\n",variant_num,i,j+1,var);
            }
        }
    }

    //printf("Output in: output.txt\n");
    printf("Output in %s\n", output_filename);
    return(0);
}
