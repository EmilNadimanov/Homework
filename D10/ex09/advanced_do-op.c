/*
• Create a program called do-op.
• The progam will be executed with three arguments: do-op value1 operateur value2
• Example :  $>./do-op 42 "+" 21
		      63
			  $>
• The operator character corresponds to the appropriate function within an array  !!!!
of pointers to function. 														   !!!!
• Your directory should contain a Makefile with the all and clean rules.
• In the case of an invalid argument such as ./do-op foo devide bar, the program
returns 0.
• If the number of arguments is invalid, do-op doesn’t display anything.
*/
#include "allfunc.h"

void		advanced_do_op(int a, int (*op)(int, int), int b)
{
	ft_putnbr(op(a, b));
}

int			main(int argc, char **argv)
{
	int		i;

	if (argc < 4)
		return 0;
	i = -1;
	while (++i < 6)
	{
		if (!ft_strcmp(argv[2], g_opptab[i].oper) && i != 5)
		{
			advanced_do_op(ft_atoi(argv[1]), g_opptab[i].func, ft_atoi(argv[3]));
			break;
		}
		if (i == 5)
		{
			i = -1;
			ft_putstr("only [ ");
			while (++i < 5)
			{
				ft_putstr(g_opptab[i].oper);
				ft_putstr(" ");
			}
			ft_putstr("] are accepted.");
		}
	}
	ft_putchar('\n');
	return 0;
}

