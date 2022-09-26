HT_SRCS	=	ft_ht_construct.c \
			ft_ht_find.c \
			ft_ht_insert.c \
			ft_ht_rehash.c \
			ft_hash.c \
			ft_ht_remove.c \
			ft_ht_insert_or_assign.c

HT_FTST	=	ft_hashtable.ftst.c

HT_DIR		= srcs/data_structure/hashtable/

SRCS += ${addprefix ${HT_DIR}, ${HT_SRCS}}
FTST_SRCS += ${addprefix ${HT_DIR}ftst/, ${HT_FTST}}
