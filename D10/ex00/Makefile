NAME := libft.a
SHELL = /bin/sh
CC := gcc
HEADERS := $(wildcard includes/*.h)
OPTS := -Wall -Wextra -Werror -c -I ${HEADERS}
OBJS := ${wildcard ./*.o}
SRCS := ${wildcard srcs/*.c}

.SUFFIXES: #    The first line clears out the suffix list, the second introduces all 
.SUFFIXES: .c .o # suffixes which may be subject to implicit rules in this Makefile.
.PHONY: clean, fclean, re

all: ${NAME}
${NAME}:
	gcc ${OPTS} ${SRCS}
	ar rc ${NAME} ${OBJS}
clean:
	rm -f *.o *.a
fclean:
	rm -f ${NAME}
re: fclean all
