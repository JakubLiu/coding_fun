#include<stdio.h>
#include<stdlib.h>

int palindrome(char word[], int n_chars){
	int out = 1;               // return 0 if word is not a palindrome, else return 1
	int i, j, k, a;
	char array1[n_chars], array2[n_chars];

	// array in the 'standard' direction
	for (i = 0; i <= (n_chars-1); ++i){
		array1[i] = word[i];
	}
	
	//array in the opposite direction
	for (j = 0, k = (n_chars-1); j <= (n_chars-1), k >= 0; ++j, k--){
		array2[k] = array1[j];
	}

	//if at least one pair of elements at corresponding positions are different, then the word is no palindrome
	for (a = 0; a <= (n_chars-1); ++a){
		if (array1[a] != array2[a]){
			out = 0;
		}
	}
	
	return out;
}

int main(void){

	printf("Check if your word is a palindrome. First enter the number of characters that make up your word and then type in the word. 1 means your word is a palindrome, 0 means your word is no palindrome.\n");
	printf("....................................................................\n");

	int SIZE, n_chars;
	// allocate memory for array of characters
	printf("Enter number of characters in your word: \n");
	scanf("%d", &n_chars);
	SIZE = n_chars + 1;
	char string[SIZE];
	// fill the array of characters
	printf("Please enter word: \n");
	scanf("%s", string);
	printf("%d\n", palindrome(string, n_chars));
	return 0;
}
