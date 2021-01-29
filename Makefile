# External programms
PYTHON		= python3
NORMINETTE	= norminette
RM			= rm -f
AR			= ar rcs
MKDIR		= mkdir -p


# FTST test setup
FTST_TEST_GENERATOR	=	ftst/gen_test_main.py
FTST_TEST_RUNNER_SRC =	ftst_test_runner.c
FTST_INC			=	ftst/include/
FTST_H_INC			=	${addprefix -I , ${FTST_INC}}
FTST_SILENT_MODE	?=	1
FTST_SILENT			=	-D FTST_SILENT=${FTST_SILENT_MODE} 
FTST_FLAGS			=	-ldl -D FTST_ALLOC_TEST=1 ${FTST_SILENT} ${FTST_H_INC}


# include source files from sub dirs
FTST_SRCS	=
SRCS		=
include string/Makefile
include math/Makefile
include io/Makefile
#include data_structure/vector/Makefile
include data_structure/list/Makefile

OBJ_DIR		= obj/
OBJS		= ${SRCS:%.c=${OBJ_DIR}%.o}

INC_DIR =	include/

NAME	= libft.a

# Compiler setup
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -O2
H_INC	= ${addprefix -I , ${INC_DIR}}


${OBJ_DIR}%.o:	%.c
			${MKDIR} ${dir $@}
			${CC} ${CFLAGS} ${H_INC} -c $< -o $@

all:
			@${MAKE} -j 16 ${NAME} -s
			@${MAKE} test -s

${NAME}:	${OBJS}
			@${AR} ${NAME} $?

.PHONY:		norm
norm:
			${NORMINETTE} ${SRCS} ${INC_DIR}

.PHONY:		test
test:		${NAME}
			@${PYTHON} ${FTST_TEST_GENERATOR} ${FTST_SRCS}
			@${CC} ${H_INC} ${FTST_SRCS} ${FTST_TEST_RUNNER_SRC} ${FTST_FLAGS} ${NAME}
			@./a.out
			@${RM} ./a.out ${FTST_TEST_RUNNER_SRC}

clean:
			@${RM} -r ${OBJ_DIR}

fclean:		clean
			@${RM} ${NAME}

re:			fclean all

so:
			@${CC} ${CFLAGS} -fPIC -c ${SRCS}
			@${CC} -shared -Wl,-soname,libft.so -o libft.so *.o

.PHONY:		all fclean re clean