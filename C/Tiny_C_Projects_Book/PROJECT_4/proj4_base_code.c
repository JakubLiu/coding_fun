#include<stdio.h>

int main(){
    int ch;    // this must be an integer, because while reading/writing
                // characters we are in fact operating on integers (their ASCII codes)

    while((ch = getchar()) != EOF){    // ch = getchar() --> assign the char from stdin to the variable ch
        putchar(ch);      // pring ch to stdout
    }
    
    return(0);

}