SRCS_ERR	=	ftE_perror.c

ERR_FTST	=	

ERR_DIR	= error/

SRCS += ${addprefix ${ERR_DIR}, ${SRCS_ERR}}
FTST_SRCS += ${addprefix ${ERR_DIR}ftst/, ${ERR_FTST}}