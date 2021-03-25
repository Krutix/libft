DLIST_SRCS	=	ft_create_dlist.c \
				ft_dlist_push_back.c \
				ft_dlist_push_front.c \
				ft_dlist_sort.c \
				ft_dlist_sort_insert.c \
				ft_dlist_remove_node.c

DLIST_FTST	=	ft_create_dlist.ftst.c \
				ft_dlist_iter.ftst.c \
				ft_dlist_sort.ftst.c

DLIST_DIR	=	data_structure/dlist/

SRCS += ${addprefix ${DLIST_DIR}, ${DLIST_SRCS}}
FTST_SRCS += ${addprefix ${DLIST_DIR}ftst/, ${DLIST_FTST}}