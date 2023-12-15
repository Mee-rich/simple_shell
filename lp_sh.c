#include "main.h"

/**
 * hsh - main shell loop
 * @comdat: struct parameter
 * @argv: the args vector 
 *
 * Return: 0 on success, 1 on error
 */
int hsh(com_d *comdat, char **argv)
{
	ssize_t t = 0;
	int r_builtin = 0;

	while (t != -1 && r_builtin != -2)
	{
		clr_com(comdat);
		if (interact(comdat))
			_puts("$ ");
		_eputchar(BUF_FLUSH);
		t = get_input(comdat);
		if (t != -1)
		{
			set_com(com, argv);
			r_builtin = find_builtin(comdat);
			if (r_builtin == -1)
				find_cmd(comdat);
		}
		else if (interact(comdat))
			_putchar('\n');
		free_com(comdat, 0);
	}
	wrt_hist(comdat);
	free_com(comdat, 1);
	if (!interact(comdat) && comdat->status)
		exit(comdat->status);
	if (r_builtin == -2)
	{
		if (comdat->err_num == -1)
			exit(comdat->status);
		exit(comdat->err_num);
	}
	return (r_builtin);
}

/**
 * find_builtin - looks for the input command
 * @comdat: com_d struct
 *
 * Return: -1 if builtin not found,
 *			0 if builtin executed successfully,
 *			1 if builtin found but not successful,
 *			-2 if builtin signals exit()
 */
int find_builtin(com_d *comdat)
{
	int i, built_ret = -1;
	builtin_list builtintl[] = {
		{"exit", myexit},
		{"env", _myenv},
		{"help", _pchge},
		{"history", _myhistory},
		{"setenv", _mysetenv},
		{"unsetenv", _myunsetenv},
		{"cd", _cd},
		{"alias", _alias},
		{NULL, NULL}
	};

	for (i = 0; builtintl[i].type; i++)
		if (_strcmp(comdat->argv[0], builtintl[i].type) == 0)
		{
			comdat->line_count++;
			built_ret = builtintl[i].func(comdat);
			break;
		}
	return (built_ret);
}

/**
 * find_cmd - seeks a command in PATH
 * @comdat: the parameter & return info struct
 *
 * Return: void
 */
void find_cmd(com_d *comdat)
{
	char *path = NULL;
	int i, k;

	comdat->path = comdat->argv[0];
	if (comdat->lineCountFlag == 1)
	{
		comdat->linCount++;
		comdat->lineCountFlag = 0;
	}
	for (i = 0, k = 0; comdat->arg[i]; i++)
		if (!is_delim(comdat->arg[i], " \t\n"))
			k++;
	if (!k)
		return;

	path = find_path(info, _getenv(comdat, "PATH="), comdat->argv[0]);
	if (path)
	{
		comdat->path = path;
		fork_cmd(comdat);
	}
	else
	{
		if ((interact(comdat) || _getenv(comdat, "PATH=")
			|| comdat->argv[0][0] == '/') && _acmd(comdat, info->argv[0]))
			fork_cmd(comdat);
		else if (*(comdat->arg) != '\n')
		{
			comdat->status = 127;
			print_err(comdat, "not found\n");
		}
	}
}

/**
 * fork_cmd - a new fork of an exec thread to run cmd
 * @comdat: struct parameter
 *
 * Return: void
 */
void fork_cmd(com_d *comdat)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(comdat->path, comdat->argv, get_env(comdat)) == -1)
		{
			free_com(comdat, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}

	}
	else
	{
		wait(&(comdat->status));
		if (WIFEXITED(comdat->status))
		{
			comdat->status = WEXITSTATUS(comdat->status);
			if (comdat->status == 126)
				print_err(comdat, "Permission denied\n");
		}
	}
}
