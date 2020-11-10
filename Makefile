OUT_DIR =	./out

INC_DIR =	./include
INC_F	=	$(shell find ${INC_DIR} -name "*.h")

SRCS	= $(shell find . -name "ft_*.c")

OBJS	= ${SRCS:.c=.o}


NAME	= libft.a

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -O3
H_INC	= -I ${INC_DIR}

RM		= rm -f

.c.o:
			${CC} ${CFLAGS} ${H_INC} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			@ar rc ${NAME} ${OBJS}

all:		${NAME}

out:		${NAME}
			mkdir ${OUT_DIR}
			cp ${SRCS} ${INC_F} ${NAME} Makefile ${OUT_DIR}

clean:
			@${RM} ${OBJS}

fclean:		clean
			@${RM} ${NAME}

re:			fclean all

so:
			@${CC} ${CFLAGS} -fPIC -c ${SRCS}
			@${CC} -shared -Wl,-soname,libft.so -o libft.so *.o

.PHONY:		all fclean re clean