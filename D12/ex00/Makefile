SHELL	:= /bin/sh

NAME	:= ft_display_file

COMPIL	:= gcc

FLAGS	:= -Wall -Wextra -Werror

.PHONY: clean, fclean, re

all: ${NAME}

${NAME}:
	@${COMPIL} -o ${NAME} *.c ${FLAGS}

clean:
	@rm -f *.o

fclean: clean
	@rm -f ${NAME}

re: fclean all
