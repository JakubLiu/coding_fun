#include<stdio.h>

int main(){
    char actual_password[8] = {'n', 'o', 'o', 'v', 'e', 'r', 'a'};
    int i;
    char c;

    // loop over the letters in the character
    for(i=0;i<7;i++){     // we loop untill less than 7, if we loop to <8, then we catch something weird at the end
        
        c = 'a';
        while(c != actual_password[i] && c <= 'z'){ // loop over all lowercase characters and compare them to the current password character
            c = c + 1;
        }
        printf("%c\n", c);
    }
    return(0);
}