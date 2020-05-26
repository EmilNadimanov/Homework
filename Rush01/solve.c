#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "allfunc.h"

int 			is_complete(char **tab)
{
	int 		row;
	int 		square;

	row = 0;
	while(row < 9)
	{	
		square = 0;
		while (square < 9)
		{
			if (tab[row][square] == '.')
				return 0;
			square++;
		}
		row++;
	}
	return 1;
}

void 			check_sector(char **tab, int row, int square, int *possib)
{
	int			sect1;
	int			sect2;
	int			i;
	int			j;
	
	sect1 = (row / 3) * 3;
	i = sect1 + 3;
	while (sect1 < i)
	{
		sect2 = (square / 3) * 3;
		j = sect2 + 3;
		while (sect2 < j)
			{
				if (tab[sect1][sect2] != '.')
					possib[(int)tab[sect1][sect2] - 49] = 0;
				sect2++;
			}
		sect1++;
	}
}

int				*all_possibilities(char **tab, int row, int square)
{	
	int			*possib;
	int			leftright;
	int			updown;
	int			i;

	i = -1;
	possib = malloc(sizeof(int) * 9);
	if (!possib)
		ft_putstr("\n Malloc failed!\n\n");
	if (!possib)
		return NULL;
	while (++i < 9)
		possib[i] = 1;
	updown =  -1;
	while (++updown < 9)
		if (tab[updown][square] != '.')
			possib[(int)tab[updown][square] - 49] = 0;
	leftright = -1;
	while (++leftright < 9)
		if (tab[row][leftright] != '.')
			possib[(int)tab[row][leftright] - 49] = 0;
	check_sector(tab, row, square, possib);
	return possib;
}

int				sudoku(char **tab)
{
	int			row;
	int			square;
	int			num;
	int 		*possib;
	static int 	a = 0;
	
	row = findrow(tab);
	square = findsquare(tab, row);
	possib = all_possibilities(tab, row, square);
	if (!possib)
		return -1;
	num = -1;	
	while (++num < 9)
		if (possib[num])
		{
			tab[row][square] = (char)(num + 49);
			a++;
			sudoku(tab);
			if (is_complete(tab))
				break;
			a--;
		}
	free(possib);
	if (is_complete(tab))
		return 1;
	tab[row][square] = '.';
	if (a == 0)
		return 0;
}

int				main(int argc, char **argv)
{
	int 		i;
	int 		result;

	i = 0;
	while (i < argc - 1 || argc == 1)
	{
		i++;
		if (argc < 10 || !line_is_valid(argv[i]) ||
			ft_strlen(argv[i]) != 9)
		{
			ft_putstr("Input error\n");
			return -1;
		}
	}
	result = sudoku(argv + 1);
	if (result == 1)
		printtab(argv + 1);
	else if (result == -1)
		return -1;
	else if (result == 0)
		ft_putstr("ERROR! Sudoku unsolvable\n");
	return 0;
}
