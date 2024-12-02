#include <stdio.h>
#include <string.h>

void removeChar(char * buffer, char * letter, char * new_buffer)
{
	char * token = strtok(buffer, letter); // strtok expects two arguments: the string to tokenize, and the string delimiter which is used in the tokenization. 
	// strtok returns a pointer to the first token in the list of tokens. if there are no tokens that can be created from the delimiter, then strtok would return NULL
	// if strtok did NOT return NULL, then the token variable refers to the first token!
	// if we want to go through the list of  tokens with the same delimeter, we need to have a loop with the condiiton to terminate on being token != NULL because strtok will return NULL if there are no tokens available to examine
	while(token != NULL)
	{
		strcat(new_buffer, token); // we can use strcat to concatenate the token thaa was returned from strtok into the new_buffer array	
		token = strtok(NULL, letter); // once we are done with the token, we want the next available token so we call strtok again with the first argument being NULL, and the second being the delimeter to use. token will then refer to the next token in the list of tokens if any
	}
}


int main()
{
	char buffer[50]; // buffer to will hold the string typed in by the user
	printf("Enter a string: ");
	fgets(buffer, 50, stdin);
	char new_buffer[strlen(buffer)+1]; // create a second buffer which we will pass into removeChaf that will 
    //contain all characters in the original buffer above that are NOT the character to remove
	new_buffer[0] = 0; // this line puts the NULL character at the 0th index of the array which is 
    //necessary for proper usage when using strcat as strcat uses the location of the null character to start the concatenation
	removeChar(buffer, " ", new_buffer); // remember when we pass an array into a function, it decays 
    //into the address of its 0th element (i.e. a pointer). the array is passed in by reference so we can directly update it from removeChar
	printf("%s\n", new_buffer); // print out the string that does not contain the characters that were removed


}