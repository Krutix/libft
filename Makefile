OUT_DIR =	./out

INC_DIR =	./include \
			./collection/btree/include \
			./collection/list/include \
			./collection/vector/include \
			./string/include \
			./memory/include

INC_FILES = $(shell find . -name "*.h")

SRCS	= $(shell find . -name "ft_*.c")

OBJS	= ${SRCS:.c=.o}

NAME	= libft.a

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -O3

RM		= rm -f

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			@ar rc ${NAME} $?

all:		${NAME}

clean:
			@${RM} ${OBJS}

fclean:		clean
			@${RM} ${NAME}

re:			fclean all

so:
			@${CC} ${CFLAGS} -fPIC -c ${SRCS}
			@${CC} -shared -Wl,-soname,libft.so -o libft.so *.o


.PHONY:		all fclean re clean