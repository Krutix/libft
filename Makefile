SRCS	= $(shell find . -maxdepth 1 -name "*.c" ! -name "*_bonus.c")
SRCS_B	= $(shell find . -maxdepth 1 -name "*_bonus.c")

OBJS	= ${SRCS:.c=.o}
OBJS_B	= ${SRCS_B:.c=.o}

NAME	= libft.a

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

RM		= rm -f

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			@ar rc ${NAME} ${OBJS}

all:		${NAME}

bonus:		${NAME} ${OBJS_B}
			@ar rc ${NAME} ${NAME} ${OBJS_B}

clean:
			@${RM} ${OBJS} ${OBJS_B}

fclean:		clean
			@${RM} ${NAME}

re:			fclean all

so:
			@gcc -fPIC -c ${SRCS} ${SRCS_B}
			@gcc -shared -Wl,-soname,libft.so -o libft.so *.o


.PHONY:		all fclean re clean