#include "main.h"

/**
 * main - program to create a shell
 * 
 * Return: always 0 on success
 */
int main(int ac, char **argv)
{
    char *prompt = " $ ";
    char *line_ptr = NULL, *line_cpy = NULL;
    size_t len = 0;
    ssize_t n_read;
    const char *delim = " \n";
    int nums_token = 0;
    char *token;
    int i;

    /* declaration of void variables */
    (void)ac;

    /* creating a loop to keep the shell on */
    while (1) {
        printf("%s", prompt);
        n_read = getline(&line_ptr, &len, stdin);

        /* checking if the getline function failed
	 * or reached EOF or user use CTRL + D */ 
        if (n_read == -1){
            printf("Exiting shell....\n");
            return (-1);
        }

        /* creating an n_read data type to
	 * store a copy of line_ptr content */
        line_cpy = malloc(sizeof(char) * n_read);
        if (line_cpy== NULL){
            perror("tsh: memory allocation error");
            return (-1);
        }
        /* copy lineptr to lineptr_copy */
        strcpy(line_cpy, line_ptr);

        /*splitting the line_ptr into tokens  */
        
        token = strtok(line_ptr, delim);

        while (token != NULL){
            nums_token++; /* counting the number of tokens */
            token = strtok(NULL, delim);
        }
        nums_token++;

        /* Allocate space to hold the array of strings */
        argv = malloc(sizeof(char *) * nums_token);

        /* Store each token into the argv array */
        token = strtok(line_cpy, delim);

        for (i = 0; token != NULL; i++){
            argv[i] = malloc(sizeof(char) * strlen(token));
            strcpy(argv[i], token);

            token = strtok(NULL, delim);
        }
        argv[i] = NULL;

        /* Now to execute the command from the argv array */
        exe_cmd(argv);

    } 


    /* Ensuring the memory space is freed after use */ 
    free(line_cpy);
    free(line_ptr);

    return (0);
}
