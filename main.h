#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait>
#include <sys/types.h>
#include <unistd.h>
#include <limits.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>

/* to read and write buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* for convert_num () */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/*1 if using system getline() */
#define USE_GETLINE	0
#define USE_STRTOK	0

#define HIST_FILE 	".history_simple_shell"
#define HIST_MAX	4096

extern char **environ;

/* for command chaining */
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3


/* *
 * struct strList - singly linked list
 * @num: the number field
 * @str: a string
 * @nxt: a ponter to next node
 */
typedef struct strList
{
	int num;
	char *str;
	struct strList *next;
} list_h;

/**
 * struct comDat - the created linked list
 * @arg: getline generated string containing arguments
 * @argv: an array of strings generated from arg
 * @path: string path for the command
 * @argc: the argument count (command line)
 * @lineCount: the error count
 * @errNum: the error code for exits
 * @lineCountFlag: if on count this line of input
 * @fname: the program filename
 * @env: local copy of environ linked lit
 * @environ: custom modified copy of environ from LL env
 * @history: the history node
 * @alias: the alias node
 * @envChanged: on if this environ was changed
 * @status: the return status of the last executed command
 * @cmdBuf: address of pointer to cmdBuf, on if chaining
 * @cmdBufType: CMDtype ||, &&, ;
 * @readfd: the fd from which to read line input
 * @histCount: the history line number count
 */
typedef struct command_data
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int lineCount;
	int errNum;
	int lineCountFlag;
	char *fname;
	list_h *env;
	list_h *history;
	list_h *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmdBuf; /* pointer to cmd; chain buffer, for memory management */
	int cmdBufType; /* CMDtype ||, &&, ; */
	int readfd;
	inf histCount;
} com_d;

#define COMD_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL,
	/, 0, 0, 0}

/**
 * struct builtin - cotains a builtin string and released function
 * @type: the bultin command flag
 * @func: the function
 */
typedef	struct builtin
{
	char *type;
	int (*func)(com_d *);
} builtin_list;


/* shloop.c */
int hsh(com_d *, char **);
int find_builtin(com_d *);
void find_cmd(com_d *);
void fork_cmd(com_d *);


/* my_parser.c */
int is_cmd(com_d char *);
char *dup_chars(char *, int, int);
char *find_path(com_d *, char *, char *);


/* shell (hsh) loop */
int loophsh(char **);

/* my_errors.c */
int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);


/* string1.c_untouch */
char *_strcpy(char *, char *);
char *_stdup(const char *);
void _puts(char *);
int _putchar(char);


/* exits.c_untouch */
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strnchr(char *, char);


/* tokenizer.c_untouch */
char **strtow(char *, char *);
char **strtow2(char *, char *);


/* realloc_untouch */
char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);


/* memory _untouch*/
int bfree(void **);


/* atoi.c */
int interact (com_d *);
int is_delim (char, char *);
int _alpha(int);
int atoi(char *);


/* errors1.c */
int _erratoi(char *);
void print_error(com_d *, char *);
int print_d(int, int);
char *convert_number(long int, int , int);
void rem_comments(char *);


/* built_in.c_done */
int myexit(com_d *);
int _cd(com_d *);
int _pchnge(com_d *);


/* built2_in.c */
int _hist(com_d *);
int _alias(com_d *);


/* getLine_in.c */
ssize_t input_getter(com_d *);
int _getline(com_d *, char **, size_t *);
void sig_hanInt(int);

/* getinfo.c */
void clear_info(com_d *);
void set_info(com_d *, char **);
void free_info(com_d *, int);

/* environ.c */
char *_getenv(com_d *, const char *);
int _myenv(com_d *);
int _mysetenv(com_d *);
int _myunsetenv(com_d *);
int fill_envList(com_d *);

/* getenv.c */
char **get_environ(com_d *);
int _unsetenv(com_d *, char *, char *);
int _setenv(com_d *, char *, char *);

/* history.c */
char *get_history_file(com_d *comdat);
int write_history(com_d *comdat);
int read_history(com_d *comdat);
int buildHist__list(com_d *comdat, char *buff, int lineCount);
int renumber_history(com_d *comdat);


/* my_lists.c */
list_h *add_node(list_h **, const char *, int);
list_h *add_node_end(list **, const char *, int);
size_t print_list_str(const list_h *);
int delete_node_at_index(list_h **, unsigned int);
void free_list(list_h **);

/* my_lists1.c */
size_t list_len(const list_h *);
char **list_to_strings(list_h *);
size_t *node_starts_with(list_h *, char *, char);
ssize_t get_node_index(list_h *, list_h *);

/* my_vars.c */
int is_chn(com_d *, char *, size_t *);
void chk_chain(com_d *, char *, size_t *, size_t, size_t);
int replace_alias(com_d *);
int replace_vars(com_d *);
int replace_string(char **, char *);

#endif
