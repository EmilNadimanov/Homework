#ifndef __ALLFUNC_H__
# define __ALLFUNC_H__

#include <stdlib.h>
#include <unistd.h>
void			ft_putchar(char c);
void			ft_putnbr(int nb);
void			ft_putstr(char *c);
int				ft_strcmp(char *s1, char *s2);
int				ft_atoi(char *str);
int				ft_add(int a, int b);
int				ft_sub(int a, int b);
int				ft_mul(int a, int b);
int				ft_div(int a, int b);
int				ft_mod(int a, int b);
int				ft_usage(int a, int b);
typedef struct 	zhuk 
{
	char		oper[10];
	int			(*func)(int, int);
} t_opp;
#include "ft_opp.h"
#endif