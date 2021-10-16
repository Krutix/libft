SRCS_EXIT	=	ft_exit.c

EXIT_FTST	=	

EXIT_DIR	= exit/

SRCS += ${addprefix ${EXIT_DIR}, ${SRCS_EXIT}}
FTST_SRCS += ${addprefix ${EXIT_DIR}ftst/, ${EXIT_FTST}}
