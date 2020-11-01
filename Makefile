INC_DIR =	./includes \
			./collection/btree/includes \
			./collection/list/includes \
			./collection/vector/includes \
			./math/includes \
			./string/includes \
			./memory/includes \

SRCS	= $(shell find . -name "ft_*.c")

OBJS	= ${SRCS:.c=.o}

NAME	= libft.a

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

RM		= rm -f

.c.o:
			${CC} ${CFLAGS} -I ${INC_DIR} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			@ar rc ${NAME} ${OBJS}

all:		${NAME}

clean:
			@${RM} ${OBJS}

fclean:		clean
			@${RM} ${NAME}

re:			fclean all

so:
			@gcc -fPIC -c ${SRCS}
			@gcc -shared -Wl,-soname,libft.so -o libft.so *.o


.PHONY:		all fclean re clean