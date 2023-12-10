#include "main.h"

/**
 * val_loc - function to return the 
 * 	     path of the command that was passed.
 *
 * Return: On success a pointer to the value 
 * 	   in the environment or NULL if there is 
 * 	   no match.
 */

char *val_loc(char *value){
       char *path, *path_cpy, *path_tok, *file_path;
	int value_len, dir_len;
	struct stat buf;

	path = getenv("PATH");
	path_cpy = strdup("path");

	if (path){
		/* Duplicating the path string */
		path_cpy = strdup(path);

		/* get length of the command value */
		value_len = strlen(value);

		/* break the path variable and get all the available directories */
		path_tok = strtok(path_cpy, ":");

		while(path_tok != NULL){
			/*  get the length of the directory */
			dir_len = strlen(path_tok);

			/* allocating memory to store the command name including the directory name */
			file_path = malloc(value_length + dir_len + 2); /* we need space in memory for slash  and NULL  */
			/* building the path for the command */
			strcpy(file_path, path_token);
			strcat(file_path, "/");
			strcat(file_path, value);
			strcat(file_path, "\0");

			/* testing if the file path actually exists; return on success or
			 * otherwise try the next directory*/

			if (stat(file_path, &buf) == 0){
				/* it returns 0 on success; valid file path */

				free(path_copy);

				return (file_path);
			}
			else{
				/* file path is freed so we can check for another path */
				free(file_path);
				path_tok = strtok(NULL, ":");
			}
		}

		/* No file path exist for the command, NULL is returned and memory is freed */
		free(path_cpy);

		/* checking is file path exists */
		if (stat(value, &buf) == 0)
		{
			return (value);
		}

		return (NULL);

	}

	return (NULL);
		
}
