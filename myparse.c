#include "main.h"

/**
 * _acmd - checks if a file is an executable command
 * @comdat: struct parameters
 * @pth: the file path
 *
 * Return: 1 if true, 0 otherwise
 */
int _acmd(com_d *comdat, char *pth)
{
	struct stat sta;

	(void) comdat;
	if (!pth || stat(pth, &sta))
		return (0);

	if (sta.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * _charsDup - character duplicator
 * @pthstr: the PATH 
 * @strt: index to start
 * @stp: index to stop
 *
 * Return: new buffer pointer
 */
char *_charsDup(char *pthstr, int strt, int stp)
{
	static char buff[1024];
	int j = 0, l = 0;

	for (l = 0, j = start; j < stop; j++)
		if (pthstr[j] != ':')
			buff[l++] = pthstr[j];
	buff[l] = 0;
	return (buff);
}

/**
 * fnd_pth - finds this cmd in the PATH string
 * @comdat: the comdat struct
 * @pthstr: the PATH 
 * @cmd: command to find
 *
 * Return: complete cmd path if found or NULL
 */
char *fnd_pth(com_d *comdat, char *pthstr, char *cmd)
{
	int i = 0, c_pos = 0;
	char *pth;

	if (!pthstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (_acmd(comdat, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pthstr[i] || pthstr[i] == ':')
		{
			path = _charsDups(pathstr, curr_pos, i);
			if (!*pth)
				_strcat(pth, cmd);
			else
			{
				_strcat(pth, "/");
				_strcat(pth, cmd);
			}
			if (_acmd(info, path))
				return (path);
			if (!pathstr[i])
				break;
			c_pos = i;
		}
		i++;
	}
	return (NULL);
}
