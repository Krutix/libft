SRCS_IO		=	ft_print_memory.c \
				ft_putchar_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_base_fd.c \
				ft_putnbr_fd.c \
				ft_putstr_fd.c

IO_DIR	= io/

SRCS += ${addprefix ${IO_DIR}, ${SRCS_IO}}