#include "main.h"

/**
 * myexit - shell exits
 * @comdat: struct contains potential arguments.
 *
 * Return: exits showing the given argument
 */
int myexit(com_d *comdat)
{
	exitchk;
	if (comda->argv[1]) /* if argument exits */
	{
		exitchk = _erratoi(comdat->argv[1]);
		if (exitchk == -1)
		{
			comdat->status = 2;
			print_err(comdat, "Illegal num: ");
			_eputs(comdat->argv[1]);
			_eputchar('\n');
			return (1);
		}
		comdat->err_num = _erratoi(comdat->argv[1]);
		return (-2);
	}
	comdat->err_num = -1;
	return (-2);
}

/**
 * _cd - changes the current dir of the process
 * @comdat: the struct containing potential args. 
 *
 * Return: Always 0
 */
int _cd(com_d *comdat)
{
	char *r, *dir, buff[1024];
	int ret_chdir;

	r = getcwd(buff, 1024);
	if (!r)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!comdat->argv[1])
	{
		dir = _getenv(info, "HOME=");
		if (!dir)
			ret_chdir = chdir(dir);
	}
	else if (_strcmp(comdat->argv[1], "-") == 0)
	{
		if (!_getenv(comdat, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(comdat, "OLDPWD=")), _putchar('\n');
		ret_chdir = chdir((dir = _getenv(comdat, "OLDPWD=")) ? dir : "/")
	}
	else
		ret_chdir = chdir(comdat->argv[1]);
	if (ret_chdir == -1)
	{
		print_err(comdat, "can't cd to");
		_eputs(comdat->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(comdat, "OLDPWD", _getenv(comdat, "PWD="));
		_setenv(comdat, "PWD", getcwd(buff, 1024));
	}
	return (0);
}


/**
 * _pchnge - the directory of the process changes
 * @comdat: struct conatining potential args
 *
 * Return: Always 0
 */
int _pchnge(com_d *comdat)
{
	char **arg_arr;

	arg_arr = comdat->argv;
	_puts("Function not found \n");
	if (0)
		_puts(*arg_arr);
	return (0);
}
