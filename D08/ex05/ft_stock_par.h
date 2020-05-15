#ifndef __FT_STOCK_PAR_H__
# define __FT_STOCK_PAR_H__
typedef struct	s_stock_par
{
	int			size_param;
	char		*str;
	char		*copy;
	char		**tab;
}				t_stock_par;
#endif
/*
◦ size_param being the length of the argument ;
◦ str being the address of the argument ;
◦ copy being the copy of the argument ;
◦ tab being the array returned by ft_split_whitespaces
*/