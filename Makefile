.DEFAULT_GOAL := all
# External programms
PYTHON		= python3
NORMINETTE	= norminette
RM			= rm -f
AR			= ar rcs
MKDIR		= mkdir -p


# Pretty print
COLOR_RED		= \x1b[31m
COLOR_GREEN		= \x1b[32m
COLOR_YELLOW	= \x1b[33m
COLOR_BLUE		= \x1b[34m
COLOR_MAGENTA	= \x1b[35m
COLOR_CYAN		= \x1b[36m
COLOR_RESET		= \x1b[0m
RESET_LINE		= \033[A\033[2K

PRETTY_DONE		= [${COLOR_GREEN}✓${COLOR_RESET}]
PRETTY_FAIL		= [${COLOR_RED}✕${COLOR_RESET}]
PRETTY_RELEASE	= [${COLOR_CYAN}r${COLOR_RESET}]
PRETTY_DEBUG	= [${COLOR_CYAN}d${COLOR_RESET}]

PRETTY_STATUS	= "%b ${COLOR_YELLOW}%b${COLOR_RESET} %-10b %b\n"


# FTST test setup
FTST_TEST_GENERATOR	=	ftst/gen_test_main.py
FTST_TEST_RUNNER_SRC =	ftst_test_runner.c
FTST_INC			=	ftst/include/
FTST_H_INC			=	${addprefix -I , ${FTST_INC}}
FTST_SILENT_MODE	?=	1
FTST_SILENT			=	-D FTST_SILENT=${FTST_SILENT_MODE} 
FTST_FLAGS			=	-ldl -D FTST_ALLOC_TEST=1 ${FTST_SILENT} ${FTST_H_INC}

${FTST_TEST_RUNNER_SRC}:
			@${PYTHON} ${FTST_TEST_GENERATOR} ${FTST_SRCS}


# include source files from sub dirs
FTST_SRCS	=
SRCS		=
include string/Makefile
include math/Makefile
include io/Makefile
#include data_structure/vector/Makefile
#include data_structure/list/Makefile

INC_DIR =	include/
NAME	=	libft.a


# Compiler setup
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
H_INC	= ${addprefix -I , ${INC_DIR}}


#######################################################
#
# Debug build
#
DEBUG_DIR		= debug/
DEBUG_LIB		= ${DEBUG_DIR}${NAME}
DEBUG_OBJS		= ${SRCS:%.c=${DEBUG_DIR}%.o}
DEBUG_D_FILES	= ${SRCS:%.c=${DEBUG_DIR}%.d}
include ${wildcard ${DEBUG_D_FILES}}

DEBUG_FLAGS	= -O0 -g3 -fsanitize=undefined -fsanitize=address
DEBUG_TEST_FLAGS = -static-libubsan -static-libasan

${DEBUG_DIR}%.o:	%.c
			@${MKDIR} ${dir $@}
			@${CC} ${CFLAGS} ${H_INC} -c $< -o $@ -MD

.PHONY:	debug_test
debug_test:	${FTST_TEST_RUNNER_SRC} ${DEBUG_LIB}
			@${CC} ${DEBUG_TEST_FLAGS} ${H_INC} ${FTST_SRCS} ${FTST_TEST_RUNNER_SRC} ${FTST_FLAGS} ${DEBUG_LIB}
			@./a.out
			@${RM} ./a.out ${FTST_TEST_RUNNER_SRC}
			printf ${PRETTY_STATUS}		"${PRETTY_DEBUG}" "${NAME}" "test" "${PRETTY_DONE}"

${DEBUG_LIB}:	${DEBUG_OBJS}
			@${AR} ${DEBUG_LIB} ${DEBUG_OBJS}
			printf ${PRETTY_STATUS}		"${PRETTY_DEBUG}" "${NAME}" "compile" "${PRETTY_DONE}"

.PHONY:	debug
debug:
			@${MAKE} -j 16 ${DEBUG_LIB} -s
			@${MAKE} debug_test FTST_SILENT_MODE=1 -s

#######################################################
#
# Release build
#
RELEASE_DIR		= release/
RELEASE_LIB		= ${RELEASE_DIR}${NAME}
RELEASE_OBJS	= ${SRCS:%.c=${RELEASE_DIR}%.o}

RELEASE_D_FILES	= ${SRCS:%.c=${RELEASE_DIR}%.d}
include ${wildcard ${RELEASE_D_FILES}}

RELEASE_FLAGS	= -O2 -fomit-frame-pointer

${RELEASE_DIR}%.o:	%.c
			@${MKDIR} ${dir $@}
			@${CC} ${CFLAGS} ${RELEASE_FLAGS} ${H_INC} -c $< -o $@ -MD

.PHONY:	rel_test
rel_test:	${FTST_TEST_RUNNER_SRC} release
			@${CC} ${RELEASE_FLAGS} ${H_INC} ${FTST_SRCS} ${FTST_TEST_RUNNER_SRC} ${FTST_FLAGS} ${RELEASE_LIB}
			@./a.out
			@${RM} ./a.out ${FTST_TEST_RUNNER_SRC}
			printf ${PRETTY_STATUS}		"${PRETTY_RELEASE}" "${NAME}" "test" "${PRETTY_DONE}"

${RELEASE_LIB}:	${RELEASE_OBJS}
			@${AR} ${RELEASE_LIB} ${RELEASE_OBJS}
			printf ${PRETTY_STATUS}		"${PRETTY_RELEASE}" "${NAME}" "compile" "${PRETTY_DONE}"

.PHONY:	rel
rel:
			@${MAKE} -j 16 ${RELEASE_LIB} -s
			@${MAKE} rel_test -s

#######################################################

.PHONY:	all
all:		rel
${NAME}:	rel

.PHONY:	norm
norm:
			${NORMINETTE} ${SRCS} ${INC_DIR}

.PHONY:	clean
clean:
			@${RM} ${RELEASE_OBJS} ${DEBUG_OBJS}

.PHONY:	fclean
fclean:		clean
			@${RM} -r ${DEBUG_DIR} -r ${RELEASE_DIR}

re:			fclean all

.PHONY:	redb
redb:		fclean debug

#so:
#			@${CC} ${CFLAGS} -fPIC -c ${SRCS}
#			@${CC} -shared -Wl,-soname,libft.so -o libft.so *.o