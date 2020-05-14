#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int    ft_countchars(int argc, char **argv)
{
	int i;
	int str;
	int chr;

	str = 1;
	i = 0;
	while (str < argc)
	{
		chr = 0;
		while (argv[str][chr++])
			i++;
		i++;
		str++;
	}
	return i;
}

char    *ft_concat_params(int argc, char **argv)
{
	char *result;
	char *result_save;
	int str;
	int chr;
	
	result = malloc(sizeof(char) * ft_countchars(argc, argv));
	if (!result)
		return NULL;
	result_save = result;
	str = 1;
	while (str < argc)
	{
		chr = 0;
		while (argv[str][chr])
			*result++ = argv[str][chr++];
		*result++ = '\n';
		str++;
	}
	*--result = '\0';
	return result_save;
}

int main(int argc, char **argv)
{
	printf("%s", ft_concat_params(argc, argv));
	return 0;
}
