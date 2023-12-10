#include "main.h"

/**
 * exe_cmd - function to handle the execution of
 *  	the commands in the argv array.
 * argv: pointer to an array of arguments. 
 *
 * Return: Always 0 on success.
 */

void exe_cmd(char **argv)
{
	char *value = NULL;

	if (argv){
		
		/* get the command */
		value = argv[0];

		/* execute the command with execve */
		if (execve(value, argv, NULL) == -1){
			perror("Error:");
		}
	}
}
