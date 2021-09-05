TM_FILE = ./tm.mk
FTST_MAKE = ./ftst/ftst.mk

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
                ${addprefix BUILD_TARGET_TYPE=, ${TARGET_TYPE}}

#FTST_SETUP = ${addprefix FTST_SRCS+=, ${FTST_SRCS}} \
#             ${addprefix FTST_INC+=, ${INC_DIR}} \
#             FTST_TARGET=${PATH_EXE} \
#             FTST_DIR=${dir ${FTST_MAKE}}

build:
		${MAKE} -f ${TM_FILE} $@ ${SETUP}
#		${MAKE} -f ${FTST_MAKE} test ${FTST_SETUP}

%:
		${MAKE} -f ${TM_FILE} $@ ${SETUP}
