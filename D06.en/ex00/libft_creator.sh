#! /bin/sh
gcc -c ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c
ar rc libft.a ft_putchar.o ft_swap.o ft_putstr.o ft_strlen.o ft_strcmp.o ft_strcpy.o ft_strncpy.o ft_strcat.o ft_strncat.o
ranlib libft.a
rm *.o