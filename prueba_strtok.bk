

#include <stdio.h>
#include <string.h>
#include "simple_shell.h"


int main()
{
	char message[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.";
	char* word;

	/* get the first word from the message, seperated by
	 * space character */
	word = _strtok(message, " ");
	printf("1st word: %s\n", word);

	/* get the second word from the message, NULL must be
	 * used to get tokens from the previous string now */
	word = _strtok(NULL, " ");
	printf("2nd word: %s\n", word);

	/* the following loop gets the rest of the words until the
	 * end of the message */
	while ((word = _strtok(NULL, " ")) != NULL)
		printf("Next: %s\n", word);

	return 0;
}
