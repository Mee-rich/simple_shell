#include "main.h"

/**
 * get_hist_file - the history file is fetched
 * @comdat: struct parameters
 *
 * Return: string containg history file
 */

char *get_hist_file(com_d *comdat)
{
	char *buff, *dir;

	dir = _getenv(comdat, "HOME=");
	if (!dir)
		return (NULL);
	buff = malloc(sizeof(char) * (_strlen(dir) + _strlen(HIST_FILE) + 2));
	if (!buff)
		return (NULL);
	buff[0] = 0;
	_strcpy(buff, dir);
	_strcat(buff, "/");
	_strcat(buff, HIST_FILE);
	return (buff);
}

/**
 * wrt_hist - a file is created, or appends to an existing file
 * @comdat: the struct parameter
 *
 * Return: 1 on success, else -1
 */
int wrt_hist(com_d *comdat)
{
	ssize_t fd;
	char *filename = get_hist_file(comdat);
	list_h *node = NULL;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);
	if (fd == -1)
		return (-1);
	for (node = comdat->history; node; node = node->next)
	{
		_putsfd(node->str, fd);
		_putfd('\n', fd);
	}
	_putfd(BUF_FLUSH, fd);
	close(fd);
	return (1);
}

/**
 * rd_hist - reads history from file
 * @comdat: the struct parameter
 *
 * Return: histcount on success, 0 otherwise
 */
int rd_hist(com_d *comdat)
{
	int i, lst = 0, lineCount = 0;
	ssize_t fd, rdln, fsize = 0;
	struct stat st;
	char *buff = NULL, *filename = get_hist_file(comdat);

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);
	free(filename);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	buff = malloc(sizeof(char) * (fsize + 1));
	if (!buff)
		return (0);
	rdln = read(fd, buff, fsize);
	buff[fsize] = 0;
	if (rdln <= 0)
		return (free(buff), 0);
	close(fd);
	for (i = 0; i < fsize; i++)
		if (buff[i] == '\n')
		{
			buff[i] = 0;
			buildHist_list(comdat, buff + lst, lineCount++);
			lst = i + 1;
		}
	if (lst != i)
		buildHist_list(comdat, buff + lst, lineCount++);
	free(buff);
	comdat->histcount = linecount;
	while (comdat->histcount-- >= HIST_MAX)
		delete_node_at_index(&(com->history), 0);
	renumber_history(comdat);
	return (comdat->histcount);
}

/**
 * buildHist_list - history linked list new entry
 * @comdat: Struct containing potential args
 * @buff: buffer
 * @lineCount: the history linecount, histcount
 *
 * Return: Always 0
 */
int buildHist_list(comdat *info, char *buff, int lineCount)
{
	list_h *node = NULL;

	if (comdat->history)
		node = comdat->history;
	add_node_end(&node, buff, lineCount);

	if (!comdat->history)
		comdat->history = node;
	return (0);
}

/**
 * renumber_hist - the history renumbered linked list after changes
 * @comdat: Struct containing potential args
 *
 * Return: new histcount
 */
int renumber_hist(com_d *comdat)
{
	list_h *node = comdat->history;
	int i = 0;

	while (node)
	{
		node->num = i++;
		node = node->next;
	}
	return (comdat->histcount = i);
}
