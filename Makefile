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

PRETTY_STATUS	= "%b%b ${COLOR_YELLOW}%b${COLOR_RESET} %b\n"


# FTST test setup
FTST_TEST_GENERATOR	=	ftst/gen_test_main.py
FTST_TEST_RUNNER_SRC =	ftst_test_runner.c
FTST_INC			=	ftst/include/
FTST_H_INC			=	${addprefix -I , ${FTST_INC}}
FTST_SILENT_MODE	?=	1
FTST_SILENT			=	-D FTST_SILENT=${FTST_SILENT_MODE} 
FTST_FLAGS			=	-ldl -D FTST_ALLOC_TEST=1 ${FTST_SILENT} ${FTST_H_INC}
FTST_EXE			=	ftst.out

.INTERMEDIATE: ${FTST_TEST_RUNNER_SRC}
${FTST_TEST_RUNNER_SRC}: ${FTST_SRCS}
			@${PYTHON} ${FTST_TEST_GENERATOR} ${FTST_SRCS}

.INTERMEDIATE: ${FTST_EXE}
${FTST_EXE}:	${FTST_TEST_RUNNER_SRC} ${BUILD_LIB}
			@${CC} ${BUILD_TEST_FLAGS} ${H_INC} ${FTST_SRCS} ${FTST_TEST_RUNNER_SRC} ${FTST_FLAGS} ${BUILD_LIB} -o ${FTST_EXE} || \
			{	printf ${PRETTY_STATUS}		"${PRETTY_FAIL}" "${PRETTY_BUILD_NAME}" "$<" "compile" ; exit 1;	}

# include source files from sub dirs
FTST_SRCS	=
SRCS		=
include string/srcs.mk
include math/srcs.mk
include io/srcs.mk
include data_structure/vector/srcs.mk
include data_structure/list/srcs.mk

INC_DIR =	include/
NAME	=	libft.a


# Compiler setup
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
H_INC	= ${addprefix -I , ${INC_DIR}}

#######################################################
#
# Real build
#
BUILD_DIR		?= objs
BUILD_LIB		= ${BUILD_DIR}${NAME}
BUILD_OBJS		= ${SRCS:%.c=${BUILD_DIR}%.o}
BUILD_D_FILES	= ${SRCS:%.c=${BUILD_DIR}%.d}
include ${wildcard ${BUILD_D_FILES}}

BUILD_FLAGS			?=
BUILD_TEST_FLAGS	?=

BUILD_NAME		?= 
PRETTY_BUILD_NAME = [${COLOR_CYAN}${BUILD_NAME}${COLOR_RESET}]

${BUILD_DIR}%.o:	%.c
			@${MKDIR} ${dir $@}
			@${CC} ${CFLAGS} ${BUILD_FLAGS} ${H_INC} -c $< -o $@ -MD || \
			{	printf ${PRETTY_STATUS}		"${PRETTY_FAIL}" "${PRETTY_BUILD_NAME}" "$<" "compile" ; exit 1;	}

.PHONY:	build_test
build_test:	${FTST_EXE} ${BUILD_LIB}
			./${FTST_EXE} && \
				printf ${PRETTY_STATUS}		"${PRETTY_DONE}" "${PRETTY_BUILD_NAME}" "${NAME}" "test" || \
			{	printf ${PRETTY_STATUS}		"${PRETTY_FAIL}" "${PRETTY_BUILD_NAME}" "${NAME}" "test" ; exit 1;	}

${BUILD_LIB}:	${BUILD_OBJS}
			@${AR} ${BUILD_LIB} $? && \
				printf ${PRETTY_STATUS}		"${PRETTY_DONE}" "${PRETTY_BUILD_NAME}" "${NAME}" "build" || \
			{	printf ${PRETTY_STATUS}		"${PRETTY_FAIL}" "${PRETTY_BUILD_NAME}" "${NAME}" "archive" ; exit 1;	}
			${MAKE} build_test -s

.PHONY:	build
build:
			@${MAKE} -j 16 ${BUILD_LIB} -s

.PHONY:	b_clean
b_clean:
			${RM}	${BUILD_OBJS} ${BUILD_D_FILES}

.PHONY:	b_fclean
b_fclean:	b_clean
			${RM}	${BUILD_LIB} -rd ${BUILD_DIR}

.PHONY:	b_re
b_re:		b_fclean build

#######################################################
#
# Debug build
#
DEBUG_DIR		= debug/

DEBUG_FLAGS	= -O0 -g3
DEBUG_TEST_FLAGS = 

DEBUG_SETUP	= BUILD_DIR=${DEBUG_DIR} ${addprefix BUILD_FLAGS+=, ${DEBUG_FLAGS}} BUILD_NAME=debug

.PHONY: db
db:
		@${MAKE} build ${DEBUG_SETUP} -s

.PHONY: tdb
tdb:
		@${MAKE} build_test ${DEBUG_SETUP} -s

.PHONY: cleandb
cleandb:
		@${MAKE} b_clean ${DEBUG_SETUP} -s

.PHONY: fcleandb
fcleandb:
		@${MAKE} b_fclean ${DEBUG_SETUP} -s

.PHONY: redb
redb:
		@${MAKE} b_re ${DEBUG_SETUP} -s

#######################################################
#
# Release build
#
RELEASE_DIR		= release/

RELEASE_FLAGS	= -O2 -fomit-frame-pointer

RELEASE_SETUP	= BUILD_DIR=${RELEASE_DIR} ${addprefix BUILD_FLAGS+=, ${RELEASE_FLAGS}} BUILD_NAME=release

.PHONY: rl
rl:
		@${MAKE} build ${RELEASE_SETUP} -s

.PHONY: trl
trl:
		@${MAKE} build_test ${RELEASE_SETUP} -s

.PHONY: cleanrl
cleanrl:
		@${MAKE} b_clean ${RELEASE_SETUP} -s

.PHONY: fcleanrl
fcleanrl:
		@${MAKE} b_fclean ${RELEASE_SETUP} -s

.PHONY: rerl
rerl:
		@${MAKE} b_re ${RELEASE_SETUP} -s

#######################################################

.PHONY:	all
all:		rl

${NAME}:	rl

.PHONY:	norm
norm:
			@${NORMINETTE} ${SRCS} ${INC_DIR} >> /dev/null && \
				printf ${PRETTY_STATUS}		"${PRETTY_DONE}" "${PRETTY_BUILD_NAME}" "${NAME}" "norminette" || \
			{	printf ${PRETTY_STATUS}		"${PRETTY_FAIL}" "${PRETTY_BUILD_NAME}" "${NAME}" "norminette" ; exit 1;	}

.PHONY:	clean
clean:		cleanrl		cleandb

.PHONY:	fclean
fclean:		fcleanrl	fcleandb

.PHONY:	re
re:			rerl

#so:
#			@${CC} ${CFLAGS} -fPIC -c ${SRCS}
#			@${CC} -shared -Wl,-soname,libft.so -o libft.so *.o