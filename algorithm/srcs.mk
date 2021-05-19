SRCS_ALG	=	ft_qsort.c

ALG_FTST	=	ft_qsort.ftst.c

ALG_DIR	= algorithm/

SRCS += ${addprefix ${ALG_DIR}, ${SRCS_ALG}}
FTST_SRCS += ${addprefix ${ALG_DIR}ftst/, ${ALG_FTST}}