#include "main.h"

int main(int ac, char **argv)
{
	char *prompt = "(hsh$) ";
	char *line_ptr = NULL, *line_cpy = NULL;
	size_t len = 0;
	ssize_t n_reads;
	const chr *delim = " \n";
	int nums_token = 0;
	char *token;
	int i;


	/* void variables declaration */
	(void)ac;
	
	/* an infinite loop that makes the 
	 * shell prompt after every usage */

	while (1){
	 printf("%s", prompt);
	 n_reads = getline(&line_ptr, &len, stdin);

	 /* checking if getline function failed 
	  * or EOF
	  *or user pressed CTRL + D
	  */
	if (n_reads == -1){
		printf("Exiting shell...\n");
		return(-1);
	}

	/* allocation pf space for a copy of the line_ptr */
	line_cpy = malloc(sizeof(char) *n_reads);
	if (line_cpy == NULL){
		perror("hsh: memory allocation error");
		return (-1);
	}
	/* a copy of line_ptr to line_cpy */
	strcpy(line_cpy, line_ptr);

	/* splitting the string into an array of words */
	/* total number of tokens calculated */

	token = strtok(line_cpy, delim);

	while (token != NULL){
		nums_token++;
		token = strtok(NULL, delim);
	}
	nums_token++;

	/* allocation of space to hold the array of strings */
	argv = malloc(sizeof(char *) *nums_token);

	/* storing each token in the argv array*/
	token = strtok(line_cpy, delim);

	for (i = 0; token != NULL; i++){
		argv[i] = malloc(sizeof(char) * strlen(token));
		strcpy(argv[i], token);

		token = strtok(NULL, delim);
	}
	argv[i] = NULL;


	printf("%s\n", line_ptr);
	}
	
	free(line_ptr);
	return (0);
}
		

