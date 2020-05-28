SHELL		:= /bin/sh
NAME		:= libft.a
CC			:= gcc
HEADERS		:= $(wildcard includes/*.h)
OPTS		:= -Wall -Wextra -Werror -c
OBJS		:= ${wildcard ./*.o}
SRCS		:= ${wildcard srcs/*.c}

.PHONY: clean, fclean, re

all: ${NAME}

${NAME}:
	${CC} -I ${HEADERS} ${OPTS} ${SRCS}
	ar rc ${NAME} ${OBJS}
	ranlib ${NAME}

clean:
	rm -f *.o

fclean: clean
	rm -f ${NAME}

re: fclean all

#• Create the Makefile that’ll compile your libft.a.
#• The Makefile will get its source files from the "srcs" directory.
#• The Makefile will get its header files from the "includes" directory.
#• The lib will be at the root of the exercise.
#• The Makefile should also implement the following rules: clean, fclean and re as
#  well as all.
#• fclean does the equivalent of a make clean and also erases the binary created
#  during the make. re does the equivalent of a make fclean followed by a make.
#• We’ll only fetch your Makefile and test it with our files. For this exercise, only
#  the following 5 mandatory functions of your lib have to be handled : (ft_putchar,
#  ft_putstr, ft_strcmp, ft_strlen and ft_swap).