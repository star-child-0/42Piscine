CC=gcc
CFLAGS=-Wall -Wextra -Werror 
NAME=bsq
FILES=str_to_matrix.c functions.c file_to_str.c main.c
OBJS = ${FILES:.c=.o}

all: ${NAME}

${NAME}: 
	${CC} ${CFLAGS} -c ${NAME} $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS}

clean:
	rm -f ${NAME}

fclean: clean
	rm -f ${OBJS}

re: fclean all

.PHONY: all clean fclean re
