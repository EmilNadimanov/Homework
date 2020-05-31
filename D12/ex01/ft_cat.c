#include <sys/types.h> //size_t
#include <sys/stat.h>  //modes of various kinds
#include <fcntl.h> //open and flags
#include "allfunc.h"

# define BUFSIZE 5000

void		ft_putstr(char *str)
{
	while(*str)
		write(1, str++, 1);
}

void		empty(char buf[]) //разобраться с памятью.
{
	int		ret;

	while(1)
	{
		ret = read(0, buf, BUFSIZE);
		write(1, buf, ret);
	}
}

void		error(char *filename)
{
	ft_putstr("cat: ");
	ft_putstr(filename);
	ft_putstr(": No such file or directory\n");
}

int			main(int argc, char **argv)
{
	int		fd;
	int		files;
	char	buf[BUFSIZE];
	int		ret;

	if (argc == 1)
	{
		empty(buf);
		return 0;
	}
	files = 0;
	while (++files < argc)
	{
		fd = open(argv[files], O_RDONLY);
		if (fd == -1)
			error(argv[files]);
		ret = read(fd, buf, BUFSIZE);
		write(1, buf, ret);
		close(fd);
	}
	return 0;
}