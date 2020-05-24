#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
/*
• Create the function ft_advanced_sort_wordtab which sorts, depending on the re-
turn of the function given as argument, words obtained with ft_split_whitespaces.
• The sorting will be performed by exchanging the array’s pointers.
*/

void 		ft_advanced_sort_wordtab(char **tab, int(*cmp)(char *, char *))
{
	int 	index;
	int 	i;
	int 	j;
	int 	min;
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
			if (cmp(tab[j], tab[min]) < 0)
				min = j;
		temp = tab[i];
		tab[i++] = tab[min];
		tab[min] = temp;
	}	
}

int my_reverse_strcmp(char* s1, char* s2)
{
	while (*s1 == *s2 && *s1 != 0)
	{
		s1++;
		s2++;
	}
	return *s2 - *s1;
}

int main(int argc, char** argv)
{
	if (argc < 1)
		return 1;
	ft_advanced_sort_wordtab(argv + 1, my_reverse_strcmp);
	
	for (char** iter = argv + 1; *iter != 0; iter++)
		printf("%s,", *iter);
}