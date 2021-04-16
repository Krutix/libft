VEC_SRCS	=	ft_vec_create.c \
				ft_vec_destructor.c \
				ft_vec_fetch_array.c \
				ft_vec_at.c \
				ft_vec_pop_back.c \
				ft_vec_push_reserv.c \
				ft_vec_push_back.c \
				ft_vec_realloc.c \
				ft_vec_remove_at.c

VEC_FTST	=	ft_vec_create.ftst.c

VEC_DIR		= data_structure/vector/

SRCS += ${addprefix ${VEC_DIR}, ${VEC_SRCS}}