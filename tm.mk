.DEFAULT_GOAL  := all
# External programms
PYTHON          = python3
NORMINETTE      = norminette
RM              = rm -f
AR              = ar rcs
MKDIR           = mkdir -p


# Pretty print
COLORED        = 1
ifeq (${COLORED}, 1)
COLOR_RED      = \x1b[31m
COLOR_GREEN    = \x1b[32m
COLOR_YELLOW   = \x1b[33m
COLOR_BLUE     = \x1b[34m
COLOR_MAGENTA  = \x1b[35m
COLOR_CYAN     = \x1b[36m
COLOR_RESET    = \x1b[0m
RESET_LINE     = \033[A\033[2K
endif

PRETTY_DONE     = [${COLOR_GREEN}✓${COLOR_RESET}]
PRETTY_FAIL     = [${COLOR_RED}✕${COLOR_RESET}]

PRETTY_STATUS   = "%b%b%b ${COLOR_YELLOW}%b${COLOR_RESET} %b\n"

NAME           ?= -

# Compiler setup
CC             ?= gcc
CFLAGS          = -Wall -Wextra -Werror

#######################################################
#
# Real build
#

TARGET_OS = ${shell uname}
#ifeq (${TARGET_OS}, Linux)
#endif
#ifeq (${TARGET_OS}, Darwin)
#endif

BUILD_DIR          ?= .objs/
BUILD_TARGET_NAME  ?= no_target_name
BUILD_TARGET       ?= ${BUILD_DIR}${BUILD_TARGET_NAME}

BUILD_SRCS          =
BUILD_OBJS          = ${BUILD_SRCS:%.c=${BUILD_DIR}%.o}
BUILD_D_FILES       = ${BUILD_SRCS:%.c=${BUILD_DIR}%.d}
include ${wildcard ${BUILD_D_FILES}}

BUILD_TASKS         =

BUILD_INC_DIRS         ?=
BUILD_LIBS             ?=
BUILD_LIBS_DIRS        ?=
BUILD_TEST_FLAGS       ?=
BUILD_ADDITION_RULES   ?=

BUILD_I_DIRS            = ${addprefix -I, ${BUILD_INC_DIRS}}
BUILD_L_DIRS            = ${addprefix -L, ${BUILD_LIBS_DIRS}}
BUILD_INCLUDE_FLAGS     =

BUILD_NAME             ?= -
PRETTY_BUILD_NAME       = [${COLOR_CYAN}${BUILD_NAME}${COLOR_RESET}]
PRETTY_TARGET_NAME      = [${COLOR_CYAN}${basename ${BUILD_TARGET_NAME}}${COLOR_RESET}]

BUILD_TARGET_TYPE      ?= exe
# TARGET TYPES: exe lib

BUILD_DEPEND_FILES ?=

# auto build directories
# root src files must start with "./"
.PRECIOUS: ${BUILD_DIR}/. ${BUILD_DIR}%/.
${BUILD_DIR}/.:
	mkdir -p $@
${BUILD_DIR}%/.:
	mkdir -p $@

.SECONDEXPANSION:
${BUILD_DIR}%.o:	%.c ${BUILD_DEPEND_FILES} ${realpath ./tm.mk} | $${@D}/.
			${CC} ${CFLAGS} ${BUILD_FLAGS} ${BUILD_I_DIRS} -c $< -o $@ -MD || \
			{	printf ${PRETTY_STATUS}		"${PRETTY_FAIL}" "${PRETTY_TARGET_NAME}" "${PRETTY_BUILD_NAME}" "$<" "compile" ; exit 1;	}

.PHONY:	build
build:		${BUILD_TARGET}

debug:
		echo ${BUILD_DIR}

${BUILD_TARGET}: debug ${BUILD_OBJS} ${FTST_SRCS} ${BUILD_DEPEND_FILES} ${realpath ./tm.mk}
ifeq (${BUILD_TARGET_TYPE}, exe)
			${CC} ${CFLAGS} ${BUILD_OBJS} ${BUILD_FLAGS} ${BUILD_I_DIRS} ${BUILD_L_DIRS} ${BUILD_LIBS} -o ${BUILD_TARGET} && \
				printf ${PRETTY_STATUS}		"${PRETTY_DONE}" "${PRETTY_BUILD_NAME}" "${PRETTY_TARGET_NAME}" "${NAME}" "compile" || \
			{	printf ${PRETTY_STATUS}		"${PRETTY_FAIL}" "${PRETTY_BUILD_NAME}" "${PRETTY_TARGET_NAME}" "${NAME}" "compile" ; exit 1;	}
endif
ifeq (${BUILD_TARGET_TYPE}, lib)
			${AR} ${BUILD_TARGET} ${BUILD_OBJS} && \
				printf ${PRETTY_STATUS}		"${PRETTY_DONE}" "${PRETTY_BUILD_NAME}" "${PRETTY_TARGET_NAME}" "${NAME}" "arrangement" || \
			{	printf ${PRETTY_STATUS}		"${PRETTY_FAIL}" "${PRETTY_BUILD_NAME}" "${PRETTY_TARGET_NAME}" "${NAME}" "arrangement" ; exit 1;	}
endif

.PHONY:	clean
clean:
			-${RM}	${BUILD_OBJS} ${BUILD_D_FILES}

.PHONY:	fclean
fclean:	clean
			-${RM}	-rd ${BUILD_DIR} ${BUILD_TARGET}

.PHONY:	re
re:		fclean build


INCLUDE_FILES = ${sort ${foreach src, ${BUILD_SRCS}, ${dir ${src}}} ${BUILD_INC_DIRS}}
# TODO remove unused paths

.PHONY:	norm
norm:
			${NORMINETTE} ${BUILD_SRCS} ${INCLUDE_FILES} && \
				printf ${PRETTY_STATUS}		"${PRETTY_DONE}" "${PRETTY_BUILD_NAME}" "${PRETTY_TARGET_NAME}" "${NAME}" "norminette" || \
			{	printf ${PRETTY_STATUS}		"${PRETTY_FAIL}" "${PRETTY_BUILD_NAME}" "${PRETTY_TARGET_NAME}" "${NAME}" "norminette" ; exit 1;	}
