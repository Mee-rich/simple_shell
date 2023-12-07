#include "main.h"

int main(int ac, char **argv)
{
	char *prompt = "(hsh$) ";
	char *line_ptr;
	size_t len = 0;
	ssize_t n_reads;

	/* void variables declaration */
	(void)ac,  (void)argv;
	
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

	 printf("%s\n", line_ptr);
	}
	
	free(line_ptr);
	return (0);
}
		

