OBJ_DIR =	obj/

INC_DIR =	include/

SRCS	= 
include string/Makefile
include math/Makefile
include io/Makefile
include data_structure/vector/Makefile
include data_structure/list/Makefile

OBJS		= ${SRCS:.c=.o}
OBJS_REAL	:= ${foreach obj, ${OBJS}, ${dir ${obj}}${OBJ_DIR}${notdir ${obj}}}

NAME	= libft.a

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -O2
H_INC	= ${addprefix -I , ${INC_DIR}}

RM		= rm -f

%.o:	%.c
			mkdir -p ${dir $<}${OBJ_DIR}
			${CC} ${CFLAGS} ${H_INC} -c $< -o ${dir $@}${OBJ_DIR}${notdir $@}

${NAME}:	${OBJS}
			ar rcs ${NAME} ${OBJS_REAL}

all:
			${MAKE} -j 16 ${NAME}

clean:
			@${RM} ${OBJS_REAL}

fclean:		clean
			@${RM} ${NAME}

re:			fclean all

so:
			@${CC} ${CFLAGS} -fPIC -c ${SRCS}
			@${CC} -shared -Wl,-soname,libft.so -o libft.so *.o

.PHONY:		all fclean re clean