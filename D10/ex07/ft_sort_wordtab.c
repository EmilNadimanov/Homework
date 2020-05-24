#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
/*
Create the function ft_sort_wordtab, which sorts words obtained with ft_split_whitespaces
by ascii order.
• The sorting will be performed by exchanging the array’s pointers.
*/

int 		ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2++)
	{
		if (*s1++ == 0)
			return 0;
	}
	return (*s1 - *--s2);
}

void 		ft_sort_wordtab(char **tab)
{
	int 	index;
	int 	i;
	int 	j;
	int		min;
	char 	*temp;

	index = 0;
	while (tab[index])
		index++;
	i = 0;
	while (i < index - 1)
	{
		j = i;
		min = j;
		while (++j < index)
			if (ft_strcmp(tab[j], tab[min]) < 0)
				min = j;
		temp = tab[i];
		tab[i++] = tab[min];
		tab[min] = temp;
	}	
}

int main (int argc, char **argv)
{
	ft_sort_wordtab(argv + 1);
	int i = 1;
	while(i < argc)
		printf("%s\n", argv[i++]);
}
