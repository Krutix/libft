STR_SRCS	=	ft_atoi_base.c \
				ft_atoi.c \
				ft_bzero.c \
				ft_calloc.c \
				ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_isspace.c \
				ft_itoa.c \
				ft_memccpy.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memset.c \
				ft_sort_str_tab.c \
				ft_split.c \
				ft_strcat.c \
				ft_strchr.c \
				ft_strcmp.c \
				ft_strcpy.c \
				ft_strdup.c \
				ft_strlcat.c \
				ft_strlcpy.c \
				ft_strlen.c \
				ft_strnlen.c \
				ft_strmapi.c \
				ft_strncmp.c \
				ft_strrchr.c \
				ft_strstr.c \
				ft_strnstr.c \
				ft_strtrim.c \
				ft_substr.c \
				ft_tolower.c \
				ft_toupper.c \
				ft_ulen.c \
				ft_utob_bt.c \
				ft_utob.c \
				ft_wchar.c

STR_FTST	=	ft_strlen.ftst.c \
				ft_memccpy.ftst.c \
				ft_atoi.ftst.c \
				ft_ulen.ftst.c \
				ft_ito_str.ftst.c \
				ft_strchr.ftst.c \
				ft_wchar.ftst.c

STR_DIR			=	string/

SRCS			+=	${addprefix ${STR_DIR}, ${STR_SRCS}}
FTST_SRCS		+=	${addprefix ${STR_DIR}ftst/, ${STR_FTST}}