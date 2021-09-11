LIBFT_DIR ?= libft/
LIBFT_INC = ${realpath ${LIBFT_DIR}/include/}

LIBFT_BUILD_DIR = .release/
LIBFT_LIB_DIR = ${realpath ${LIBFT_DIR}${LIBFT_BUILD_DIR}}

LIBFT_DB_BUILD_DIR = .debug/
LIBFT_DB_LIB_DIR = ${realpath ${LIBFT_DIR}${LIBFT_DB_BUILD_DIR}}

LIBFT_LIB = -lft

lft/%:
	make -C ${LIBFT_DIR} rl/${@:lft/%=%}

lftdb/%:
	make -C ${LIBFT_DIR} db/${@:lft/%=%}
