SRCS_IO		=	ft_print_memory.c \
				ft_putchar_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_base_fd.c \
				ft_putnbr_fd.c \
				ft_putstr_fd.c \
				ft_read_next_line.c

IO_FTST		=	ft_read_next_line.ftst.c

IO_DIR	= io/

SRCS += ${addprefix ${IO_DIR}, ${SRCS_IO}}
FTST_SRCS += ${addprefix ${IO_DIR}ftst/, ${IO_FTST}}