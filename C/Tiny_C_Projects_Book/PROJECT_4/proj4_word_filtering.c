/*
This programme takes whole words as input and prints them out
each word in its own line.

Example usage:

input: Noovera jest bardzo śmieszna

output:
    Noovera
    jest
    bardzo
    śmieszna
*/

#include<stdio.h>
#include<ctype.h>
#define WORDSIZE 64   // define how many characters can maximally make up a word

int main(){
    char word[WORDSIZE];
    int ch, offset, i, run;
    int runs[WORDSIZE];
    int positions[WORDSIZE];

    offset = 0; // this will be the index of the character in the word

    while((ch = getchar()) != EOF){
        
        /*
        if the input is a newline, then end the word here and print it out.'
        Then the offset gets reset to 0, because we start with a new word.
        */
        if(isspace(ch)){
            word[offset] = '\0';  // remember that in C each strings ends with the sentinel '/0'
            if(offset > 0){
                printf("%s\n", word);
                
                run = 0;
                for(i=1;i<offset;i++){
                    if(word[i] == word[i-1]){
                        run = run + 1;
                        printf("%c, %c True, run = %d\n", word[i], word[i-1], run);
                    }
                    else{
                        run = 0;
                        printf("%c, %c False, run = %d\n", word[i], word[i-1], run);
                    }
                    runs[i] = run;
                }
            }
            offset = 0;
        }
        
        /*
        Add the current character to the word and increment the offset.
        */
        else{
            word[offset] = ch;
            offset = offset + 1;

        /*
        If the maximum word size is reached, end the word, print is out and reset the offset.
        */
            if(offset == WORDSIZE+1){
                word[offset] = '\0';
                printf("%s\n", word);
                offset = 0;
            }
        }
    }



    return(0);
}