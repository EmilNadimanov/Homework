#include <stdlib.h>
#include <unistd.h>
/*
• Create a function that displays the content of the array 
you created in the last excercise’s function.
• One word per line.
• Each word will be followed by a "\n", including the last one.
• This exercise will be compiled with your ft_split_whitespaces.c
• Watch out not to have multiple define.
*/
void ft_putchar(char c);

void ft_print_words_tables(char **tab)
{
	int str;
	int chr;

	str = 0;
	while (tab[str])
	{
		chr = 0;
		while (tab[str][chr])
			ft_putchar(tab[str][chr++]);
		ft_putchar('\n');
		str++;
	}
}
