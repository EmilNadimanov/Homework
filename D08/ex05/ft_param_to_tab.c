#include <unistd.h>
#include <stdlib.h>
#include "ft_stock_par.h"

char		**ft_split_whitespaces(char* str);

char		*ft_strdup(char *src)
{
	char	*str;
	int		i;
	int 	n;

	n = -1;
	i = -1;
	while (src[++i])
		;
	str = malloc(i * sizeof(char));
	if (!str)
		return NULL;
	while (++n <= i)
		str[n] = src[n];
	return str;
}

struct		s_stock_par *ft_param_to_tab(int ac, char **av)
{
	int		arg;
	int		symb;
	t_stock_par *result;

	arg = -1;
	result = malloc(sizeof(*result) * (ac + 1)); //динамический массив экземпляров структуры??? Как тут вообще память работает 
	if (!result)
		return NULL;
	while (++arg < ac)
	{
		symb = 0;
		while (av[arg][symb])
			symb++;
		result[arg].size_param = symb;
		result[arg].str = av[arg];
		result[arg].copy = ft_strdup(av[arg]);
		result[arg].tab = ft_split_whitespaces(av[arg]);
	}
	result[arg].str = (void*)0;
	return result;
}
