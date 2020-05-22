#include <stdlib.h>
#include <unistd.h>

int ft_any(char **tab, int(*f)(char*))
{
	while (*tab)
		if (f(*tab++))
			return 1;
	return 0;
}
