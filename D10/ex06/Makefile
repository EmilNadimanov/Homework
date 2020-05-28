SHELL 	:= /bin/sh

NAME 	:= do-op

CC 		:= gcc

FLAGS 	:=  -Wall -Wextra -Werror

SRCS 	:= ${wildcard srcs/*.c}

.PHONY: clean, fclean, re

all: lib ${NAME}

lib:
	@${CC} ${FLAGS} -c ${SRCS}
	@ar rc libft.a *.o
	@ranlib libft.a

${NAME}:
	@gcc -o ${NAME} ${NAME}.c ${FLAGS} -L. -lft

clean:
	@rm -f *.o

fclean: clean
	@rm -f ${NAME}

libclean:
	@rm -f lib*.a

re: fclean all
