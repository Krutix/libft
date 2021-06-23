SRCS_RE		=	re2post.c \
				re2reir.c \
				post2nfa.c \
				regex_match.c \
				ft_regex.c

RE_FTST		=	re2post.ftst.c \
				ft_regex.ftst.c

RE_DIR	= regex/

SRCS += ${addprefix ${RE_DIR}, ${SRCS_RE}}
FTST_SRCS += ${addprefix ${RE_DIR}ftst/, ${RE_FTST}}