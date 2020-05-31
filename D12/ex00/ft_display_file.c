#include <sys/types.h> //size_t
#include <sys/stat.h>  //modes of various kinds
#include <fcntl.h> //open and flags
#include "allfunc.h"

# define BUFSIZE 15

void		ft_putstr(char *str)
{
	while (*str != '\0')
		ft_putchar(*str++);
}

void		ft_putstr_fd(char *str, int size)
{
	write(1, str, size);
}

int			main(int argc, char **argv)
{
	int		fd;
	char	buf[BUFSIZE + 1];
	int		ret;

	if (argc != 2)
	{
		ft_putstr((argc > 2) ? "Too many arguments.\n" :
				  "File name missing.\n");
		return -1;
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("open() failed.\n");
		return -1;
	}
	while ((ret = read(fd, buf, BUFSIZE)))
		ft_putstr_fd(buf, ret);
	fd = close(fd);
	if (fd == -1)
	{
		ft_putstr("close() failed.\n");
		return -1;
	}
}
