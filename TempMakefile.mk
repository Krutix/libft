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

PRETTY_STATUS	= "%b%b%b ${COLOR_YELLOW}%b${COLOR_RESET} %b\n"

NAME			?= -


# Compiler setup
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

#######################################################
#
# Real build
#

TARGET_OS = ${shell uname}
#ifeq (${TARGET_OS}, Linux)
#endif
#ifeq (${TARGET_OS}, Darwin)
#endif

BUILD_DIR			?= .objs/
BUILD_TARGET_NAME	?= no_target_name
BUILD_TARGET		?= ${BUILD_DIR}${BUILD_TARGET_NAME}

BUILD_SRCS		=
BUILD_OBJS		= ${BUILD_SRCS:%.c=${BUILD_DIR}%.o}
BUILD_D_FILES	= ${BUILD_SRCS:%.c=${BUILD_DIR}%.d}
include ${wildcard ${BUILD_D_FILES}}

BUILD_TASKS			=

BUILD_INC_DIRS		?=
BUILD_LIBS			?=
BUILD_LIBS_DIRS		?=
BUILD_TEST_FLAGS	?=

BUILD_I_DIRS		= ${addprefix -I, ${BUILD_INC_DIRS}}
BUILD_L_DIRS		= ${addprefix -L, ${BUILD_LIBS_DIRS}}
BUILD_INCLUDE_FLAGS	= 

BUILD_NAME			?= -
PRETTY_BUILD_NAME	= [${COLOR_CYAN}${BUILD_NAME}${COLOR_RESET}]
PRETTY_TARGET_NAME	= [${COLOR_CYAN}${BUILD_TARGET_NAME}${COLOR_RESET}]

# auto build directories
.PRECIOUS: ${BUILD_DIR}/. ${BUILD_DIR}%/.
${BUILD_DIR}/.:
	mkdir -p $@
${BUILD_DIR}%/.:
	mkdir -p $@

.SECONDEXPANSION:
${BUILD_DIR}%.o:	%.c | $${@D}/.
			@${CC} ${CFLAGS} ${BUILD_FLAGS} ${BUILD_I_DIRS} -c $< -o $@ -MD || \
			{	printf ${PRETTY_STATUS}		"${PRETTY_FAIL}" "${PRETTY_TARGET_NAME}" "${PRETTY_BUILD_NAME}" "$<" "compile" ; exit 1;	}

${BUILD_TARGET}: ${BUILD_TASKS}

.PHONY:	build
build:		${BUILD_TARGET}

.PHONY:	b_exe
b_exe:		${BUILD_OBJS}
			@${CC} ${CFLAGS} ${BUILD_OBJS} ${BUILD_FLAGS} ${BUILD_I_DIRS} ${BUILD_L_DIRS} ${BUILD_LIBS} -o ${BUILD_TARGET} && \
				printf ${PRETTY_STATUS}		"${PRETTY_DONE}" "${PRETTY_BUILD_NAME}" "${PRETTY_TARGET_NAME}" "${NAME}" "compile" || \
			{	printf ${PRETTY_STATUS}		"${PRETTY_FAIL}" "${PRETTY_BUILD_NAME}" "${PRETTY_TARGET_NAME}" "${NAME}" "compile" ; exit 1;	}

.PHONY:	b_lib
b_lib:		${BUILD_OBJS}
			@${AR} ${BUILD_TARGET} $? && \
				printf ${PRETTY_STATUS}		"${PRETTY_DONE}" "${PRETTY_BUILD_NAME}" "${NAME}" "arrangement" || \
			{	printf ${PRETTY_STATUS}		"${PRETTY_FAIL}" "${PRETTY_BUILD_NAME}" "${NAME}" "arrangement" ; exit 1;	}

FTST_PATH =
include ${FTST_PATH}
FTST_DIR	= libft/ftst/
FTST_INC	+= ${BUILD_INC_DIRS}
FTST_LIBS	+= ${BUILD_LIBS} -lm
FTST_LIB_DIRS += ${BUILD_LIBS_DIRS}
FTST_TARGET = ${BUILD_OBJS}
.PHONY:	b_test
b_test:		${FTST_EXE}
			@./${FTST_EXE} && \
				printf ${PRETTY_STATUS}		"${PRETTY_DONE}" "${PRETTY_BUILD_NAME}" "${PRETTY_TARGET_NAME}" "${NAME}" "test" || \
			{	printf ${PRETTY_STATUS}		"${PRETTY_FAIL}" "${PRETTY_BUILD_NAME}" "${PRETTY_TARGET_NAME}" "${NAME}" "test" ; exit 1;	}

.PHONY:	b_clean
b_clean:
			-${RM}	${BUILD_OBJS} ${BUILD_D_FILES}

.PHONY:	b_fclean
b_fclean:	b_clean
			-${RM}	-rd ${BUILD_DIR} ${BUILD_TARGET}

.PHONY:	b_re
b_re:		b_fclean build

.PHONY:	b_norms
b_norms:
			@${NORMINETTE} ${BUILD_SRCS} ${INC_DIR}*.h >> /dev/null && \
				printf ${PRETTY_STATUS}		"${PRETTY_DONE}" "${PRETTY_BUILD_NAME}" "${PRETTY_TARGET_NAME}" "${NAME}" "norminette" || \
			{	printf ${PRETTY_STATUS}		"${PRETTY_FAIL}" "${PRETTY_BUILD_NAME}" "${PRETTY_TARGET_NAME}" "${NAME}" "norminette" ; exit 1;	}

# | grep -v 'OK'
.PHONY:	b_norm
b_norm:
			@${NORMINETTE} ${BUILD_SRCS} ${INC_DIR}*.h && \
				printf ${PRETTY_STATUS}		"${PRETTY_DONE}" "${PRETTY_BUILD_NAME}" "${PRETTY_TARGET_NAME}" "${NAME}" "norminette" || \
			{	printf ${PRETTY_STATUS}		"${PRETTY_FAIL}" "${PRETTY_BUILD_NAME}" "${PRETTY_TARGET_NAME}" "${NAME}" "norminette" ; exit 1;	}
