/*
Convert each character randomly to upper or lowercase.
*/

#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>  // for rand()

int main(){
    int ch;
    int random_number;

    while((ch = getchar()) != EOF){ 

        if(ch == '\n'){    // if the user presses 'enter' then don't treat the new line character as an input character
            continue;
        }

        /*
        Be default the rand() function generates a random integer from the range [0, RAND_MAX),
        to ensure that it is between [0,1], we need to calculate its modulo 2 (even or odd).
        */
        random_number = rand()%2;
        
        if(random_number == 0){
            putchar(toupper(ch)); // if random number is 0 then toupper
            printf("\n");
        }
        else{
            putchar(tolower(ch));   // if random number is 1 then tolower
            printf("\n");
        }
    }
    
    return(0);

}