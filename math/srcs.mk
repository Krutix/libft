SRCS_MATH	=	ft_abs.c \
				ft_find_next_prime.c \
				ft_is_prime.c \
				ft_max_min.c \
				ft_max_minf.c \
				ft_pow.c \
				ft_sqrt.c \
				ft_v2f.c

FTST_MATH	=	ft_abs.ftst.c \
				ft_max_min.ftst.c \
				ft_v2f.ftst.c

MATH_DIR	= math/

SRCS		+= ${addprefix ${MATH_DIR}, ${SRCS_MATH}}
FTST_SRCS	+= ${addprefix ${MATH_DIR}ftst/, ${FTST_MATH}}