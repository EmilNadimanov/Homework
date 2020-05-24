#include "allfunc.h"

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
void		do_op(int a, int (*op)(int, int), int b)
{
	ft_putnbr(op(a, b));
}

int			main(int argc, char **argv)
{
	int		(*op[5])(int, int) = {plus, minus, multiply, divide, modulus};

	if (argc < 4)
		return 0;
	if (!ft_strcmp(argv[2], "+"))
		do_op(ft_atoi(argv[1]), op[0], ft_atoi(argv[3]));
	else if (!ft_strcmp(argv[2], "-"))
		do_op(ft_atoi(argv[1]), op[1], ft_atoi(argv[3]));
	else if (!ft_strcmp(argv[2], "*"))
		do_op(ft_atoi(argv[1]), op[2], ft_atoi(argv[3]));
	else if (!ft_strcmp(argv[2], "/"))
		do_op(ft_atoi(argv[1]), op[3], ft_atoi(argv[3]));
	else if (!ft_strcmp(argv[2], "\%"))
		do_op(ft_atoi(argv[1]), op[4], ft_atoi(argv[3]));
	else ft_putchar('0');
	ft_putchar('\n');
	return 0;
}

