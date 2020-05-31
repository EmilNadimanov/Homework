#include <sys/types.h> //size_t
#include <sys/stat.h>  //modes of various kinds
#include <fcntl.h> //open and flags
#include "allfunc.h"
#include <stdio.h>

# define BUFSIZE 10

int			check_for_option(char **argv)
{
	int		bytes;
	int		ar;

	bytes = 0;
	ar = 0;
	while(argv[ar])
	{
		if (!ft_strcmp(argv[ar], "-c"))
		{
			if (!argv[ar + 1])
				return error("err", 2);
			if (is_num(argv[ar + 1]))
				bytes = get_bytes(argv[ar + 1], 0);
			else
				return error(argv[ar + 1], 4);
		}
		else if (argv[ar][0] == '-')
			bytes = get_bytes(argv[ar] + 1, 1);
		if (bytes == -1)
			return -1;
		ar++;
	}
	return bytes;
}
void		write_last_lines(int fd, char *buf, int ret)
{
	int		a;
	int 	i;
	int		newlines;
	int		file_len;
	int		file_cur;

	file_len = lseek(fd, 0, SEEK_END);
	a = 1;
	while (file_len)
	{
		newlines = 0;
		file_cur = lseek(fd, -1 * a++, SEEK_CUR);
		buf = malloc(1 + sizeof(char) * (file_len - file_cur));
		ret = read(fd, buf, file_len - file_cur);
		i = 0;
		buf[ret] = 0;
		while (buf[i])
			if (buf[i++] == '\n' && buf[i + 1] != 0)
				newlines++;
		if (newlines == 10 || file_cur == 0)
		{
			write(1, ++buf, ret);
			return;
		}
		free(buf);
	}
}

void		write_one_file(int fd, int bytes, int files)
{
	int		ret;
	char	*buf;

	if (bytes)
	{
		lseek(fd, -1 * bytes, SEEK_END);
		buf = malloc(sizeof(char) * bytes);
		ret = read(fd, buf, bytes);
		write(1, buf, ret);
		free(buf);
	}
	else
	{
		write_last_lines(fd, buf, ret);
	}
	if (files > 0)
		ft_putstr("\n");
}

void		write_files(char **argv, int bytes, int files)
{
	int		fd;
	int		i;
	int		lastfile_flag_format;

	i = 0;
	lastfile_flag_format = 0;
	while (argv[i])
	{
		if (argv[i][0] != '-')
		{
			if (files > 1)
			{
				ft_putstr("==> ");
				ft_putstr(argv[i]);
				ft_putstr(" <==\n");
			}
			fd = open(argv[i], O_RDONLY);
			lastfile_flag_format++;
			if (fd == -1)
				error(argv[i], 1);
			else
				write_one_file(fd, bytes, files - lastfile_flag_format);
			close(fd);
		}
		if (!ft_strcmp(argv[i], "-c"))
			i++;
		i++;	
	}
}

int			main(int argc, char **argv)
{
	int		bytes;
	int		files;
	int		i;

	bytes = check_for_option(argv + 1);
	if (bytes == -1)
		return -1;
	i = 1;
	files = 0;
	while (argv[i])
	{
		if (argv[i][0] != '-')
			files++;
		if (!ft_strcmp(argv[i], "-c"))
			i++;
		i++;	
	}
	if (!files)
		return error("err", 5);
	write_files(argv + 1, bytes, files);
	return argc;
}
