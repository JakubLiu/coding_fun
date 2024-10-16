#include<stdio.h>

/*
Don't print values who have hexadecimal representations longer than 5 symbols.
The 1st decimal symbol, who's hexadecimal representation is longer than 5 is 10dec.
*/

int main(){
    int ch;
    int wrap = 0;

    while((ch = getchar()) != EOF){
        
            printf("%02X", ch);
            wrap = wrap + 3;

            if(wrap > 77 || ch == '\n'){
                putchar('\n');
                wrap = 0;
            }
       
    }
    return(0);
}