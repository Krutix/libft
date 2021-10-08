TM_FILE         = ./tm.mk
.DEFAULT_GOAL  := all

# include source files from sub dirs
FTST_SRCS	=
SRCS		=
include string/srcs.mk
include algorithm/srcs.mk
include math/srcs.mk
include io/srcs.mk
include data_structure/vector/srcs.mk
include data_structure/list/srcs.mk
include data_structure/dlist/srcs.mk
include data_structure/hashtable/srcs.mk
include error/srcs.mk
include exit/srcs.mk

INC_DIR =	include/
NAME	=	libft

DEPEND_FILES = ${realpath ./Makefile}
SETUP         = ${addprefix BUILD_SRCS+=, ${SRCS}} \
				${addprefix FTST_SRCS+=, ${FTST_SRCS}} \
				${addprefix INC_DIR+=, ${INC_DIR}} \
				${addprefix DEPEND_FILES+=, ${DEPEND_FILES}}

#######################################################
#
# Release build
#
RELEASE_MAKE = release.mk

rl/%:
		${MAKE} -f ${RELEASE_MAKE} ${@:rl/%=%} ${SETUP}

#######################################################
#
# Debug build
#
DEBUG_MAKE = debug.mk

db/%:
		${MAKE} -f ${DEBUG_MAKE} ${@:db/%=%} ${SETUP}


#######################################################

.PHONY:	all
all:		rl/build

${NAME}:	rl/build

include docs/doxygen.mk
.PHONY: docs
docs:	doxygen

.PHONY:	clean
clean:		rl/clean db/clean

.PHONY:	fclean
fclean:		rl/fclean db/fclean

.PHONY: norm
norm:		rl/norm

.PHONY:	re
re:			rl/re db/re

#so:
#			@${CC} ${CFLAGS} -fPIC -c ${SRCS}
#			@${CC} -shared -Wl,-soname,libft.so -o libft.so *.o
