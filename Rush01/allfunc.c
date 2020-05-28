#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void			ft_putchar(char c)
{
	write (1, &c, 1);
}

void			ft_putstr(char *str)
{
	while (*str != '\0')
		ft_putchar(*str++);
}

int 			line_is_valid(char *str)
{
	int 		ch;

	ch = 0;
	while (str[ch])
	{
		if ((str[ch] <= 48 || str[ch] > 57 ) && str[ch] != '.')
			return 0;
		ch++;
	}
	return 1;
}

int 			ft_strlen(char *str)
{
    int 		count = 0;
    while (*(str + count) != '\0')
        count++;
    return count;
}

int				findrow(char **tab)
{	
	int			row;
	int			square;

	row = 0;
	while (row < 9)
	{
		square = 0;
		while (square < 9)
		{
			if (tab[row][square++] == '.')
				return row;
		}
		row++;
	}
	return 0;
}

int				findsquare(char **tab, int row)
{
	int			square;
	
	square = 0;
	while (square < 9)
	{
		if (tab[row][square] == '.')
			break;
		square++;
	}
	return square;
}

void			printtab(char **tab)
{
	int			row;
	int			square;

	row = 0;
	while (row < 9)
	{
		square = 0;
		while (square < 9)
		{
			ft_putchar(tab[row][square]);
			if (square != 8)
				ft_putchar(' ');
			square++;
		}
		ft_putchar('\n');
		row++;
	}
}