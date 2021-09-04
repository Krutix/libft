TM_FILE = ./tm.mk

#######################################################
#
# Release build
#
NAME            = libft
BUILD_NAME      = release
BUILD_DIR       = .release/
NAME_EXE        = libft.a
PATH_EXE        = ${BUILD_DIR}${NAME_EXE}
TARGET_TYPE     = lib
INC_DIR         =
FLAGS          += -O2 -fomit-frame-pointer
LIBS           +=
LIBS_DIRS      +=
SRCS           +=
IS_FTST         = 0
FTST_SRCS      +=


SETUP    =      ${addprefix BUILD_FLAGS+=, ${FLAGS}} \
                ${addprefix NAME=, ${NAME}} \
                ${addprefix BUILD_NAME=, ${BUILD_NAME}} \
                ${addprefix BUILD_TARGET_NAME=, ${NAME_EXE}} \
                ${addprefix BUILD_TARGET=, ${PATH_EXE}} \
                ${addprefix BUILD_DIR=, ${BUILD_DIR}} \
                ${addprefix BUILD_SRCS+=, ${SRCS}} \
                ${addprefix BUILD_INC_DIRS+=, ${INC_DIR}} \
                ${addprefix BUILD_LIBS_DIRS+=, ${LIBS_DIRS}} \
                ${addprefix BUILD_LIBS+=, ${LIBS}} \
                ${addprefix BUILD_IS_FTST=, ${IS_FTST}} \
                ${addprefix BUILD_DEPEND_FILES+=, ${DEPEND_FILES} ${realpath ./release.mk}} \
                ${addprefix FTST_SRCS+=, ${FTST_SRCS}} \
                ${addprefix BUILD_TARGET_TYPE=, ${TARGET_TYPE}}

%:
		${MAKE} -f ${TM_FILE} $@ ${SETUP}
