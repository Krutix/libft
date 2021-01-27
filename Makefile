INC_DIR =	include/

PYTHON	= python

FTST	=
SRCS	= 
include string/Makefile
include math/Makefile
include io/Makefile
include data_structure/vector/Makefile
include data_structure/list/Makefile

OBJ_DIR =	obj/
OBJS		= ${SRCS:%.c=${OBJ_DIR}%.o}

NAME	= libft.a

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -O2
H_INC	= ${addprefix -I , ${INC_DIR}}

RM		= rm -f

${OBJ_DIR}%.o:	%.c
			mkdir -p ${dir $@}
			${CC} ${CFLAGS} ${H_INC} -c $< -o $@

${NAME}:	${OBJS}
			ar rcs ${NAME} $?

.PHONY:		test
test:		${NAME}
			@${PYTHON} ./gettests.py ${FTST}
			@${CC} ${H_INC} -I ftst/include/ ${FTST} ftst_test_runner.c ${NAME} -D FTST_SILENT=1
			@./a.out
			@${RM} ./a.out


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