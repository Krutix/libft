OUT_DIR =	./out

INC_DIR =	./include

SRCS	= $(shell find . -name "ft_*.c")

OBJS	= ${SRCS:.c=.o}


NAME	= libft.a

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -O3
H_INC	= -I ${INC_DIR}

RM		= rm -f

.c.o:
			${CC} ${CFLAGS} ${H_INC} -c $< -o ${<:.c=.o} -MD

include (wildcard ${D_FILES})

${NAME}:	${OBJS}
			@ar rcs ${NAME} $?

all:		${NAME}

out:		${NAME}
			@mkdir ${OUT_DIR}; cp -r ${INC_DIR} ${NAME} ${OUT_DIR}

clean:
			@${RM} ${OBJS}

fclean:		clean
			@${RM} ${NAME} -r ${OUT_DIR}

re:			fclean all

so:
			@${CC} ${CFLAGS} -fPIC -c ${SRCS}
			@${CC} -shared -Wl,-soname,libft.so -o libft.so *.o

.PHONY:		all fclean re clean