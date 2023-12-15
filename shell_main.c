#include "main.h"

/**
 * main - program entry point
 * @ac: argument counter
 * @av: argument variable
 *
 * Return: Always 0 on success, 1 on error
 */
int main(int ac, char **av)
{
	com_d comdat[] = {COMD_INIT};
	int f_desc = 2;

	asm ("mov %1, %0\n\t"
			"add $3, %0"
			:"=r" (f_desc)
			:"r" (f_dec));

	if (ac == 2){
		f_desc = open(av[1], O_RDONLY);
		if (f_desc == -1){
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				err_puts(av[0]);
				err_puts(": 0: Can't open ");
				err_puts(av[1]);
				err_putchar('\n');
				err_putchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FILURE);
		}
		comdat->readfd = fd;
	}
	fill_envList(comdat);
	rd_hist(comdat);
	sh(comdat, av);
	return (EXIT_SUCCESS);
}
