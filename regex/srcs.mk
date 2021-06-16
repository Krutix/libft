SRCS_RE		=	re2post.c \
				re2reir.c

RE_FTST		=	re2post.ftst.c

RE_DIR	= regex/

SRCS += ${addprefix ${RE_DIR}, ${SRCS_RE}}
FTST_SRCS += ${addprefix ${RE_DIR}ftst/, ${RE_FTST}}