#include <stdlib.h>
#include <unistd.h>

int 		ft_is_num(char *str)
{
	int 	ch;

	ch = 0;
	while (str[ch])
	{
		if (str[ch] < 48 || str[ch] > 57)
			return 0;
		ch++;
	}
	return 1;
}

void		ft_putstr(char *str)
{
	while(*str)
		write(1, str++, 1);
}

int			error(char *filename, int errno)
{
	if (errno == 1)
	{
		ft_putstr("tail: cannot open '");
		ft_putstr(filename);
		ft_putstr("' for reading: No such file or directory\n");
	}
	else if (errno == 2)
	{
		ft_putstr("tail: option requires an argument -- 'c'\n");
		ft_putstr("Try 'tail --help' for more information.\n");
	}
	else if (errno == 3)
	{
		ft_putstr("tail: invalid option -- not 'c'\n");
		ft_putstr("Try 'tail --help' for more information and only use '-c'.\n");
	}
	else if (errno == 4)
	{
		ft_putstr("tail: invalid number of bytes: ’");
		ft_putstr(filename);
		ft_putstr("’\n");
	}
	else if (errno == 5)
		ft_putstr("No file to read! Abort! Enter at least 1 file.\n");
	return -1;
}

int			ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2++)
	{
		if (*s1++ == 0)
			return 0;
	}
	return (*s1 - *--s2);
}

int			is_num(char *str)
{
	while (*str)
		if (*str < '0' || *str++ > '9')
			return 0;
	return 1;
}


int			get_bytes(char *str, int merged)
{
	int		bytes;
	int		i;

	if (merged)
	{
		if (str[0] == 'c')
			str++;
		else if (str[0] < '0' || str[0] > '9')
			return error("err", 3);
	}
	bytes = 0;
	i = 0;
	while(str[i])
	{
		if (str[i] == 'c')
			break;
		else if (str[i] < '0' || str[i] > '9')
			return error(str, 4);
		bytes = 10 * bytes + str[i] - 48;
		i++;
	}
	return bytes;
}