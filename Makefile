include make/tm.mk

PROJECT_NAME  = libft
NAME          = libft

CC            = clang
CXX           = c++
LD            = c++
CFLAGS        = -Wall -Wextra -Werror
CXXFLAGS      = -Wall -Wextra -Werror -pedantic --std=c++98
LDFLAGS       = -pthread
ARFLAGS       = rcs
DEP           = ./Makefile
INC           = ./include/

BUILD        ?= debug

######## include source files from sub dirs ###########
include string/srcs.mk
include algorithm/srcs.mk
include math/srcs.mk
include io/srcs.mk
include data_structure/vector/srcs.mk
include data_structure/list/srcs.mk
include data_structure/dlist/srcs.mk
include data_structure/hashtable/srcs.mk
include error/srcs.mk
include exit/srcs.mk
#######################################################

$(call add/project,$(PROJECT_NAME))

######################## DEBUG ########################
$(call add/subproj,$(PROJECT_NAME),debug)
DEBUG_SANS =    -fsanitize=address \
                -fsanitize=undefined
debug_CXXFLAGS       += -O0 -g3 $(DEBUG_SANS)
debug_CFLAGS         += -O0 -g3 $(DEBUG_SANS)
debug_LDFLAGS        +=         $(DEBUG_SANS)
$(call add/lib,debug,$(NAME).a)
#######################################################

####################### RELEASE #######################
$(call add/subproj,$(PROJECT_NAME),release)
release_CFLAGS       += -O2
release_CXXFLAGS     += -O2
$(call add/lib,release,$(NAME).a)
#######################################################

.PHONY: all clean fclean re
all: $(debug_BUILD) $(release_BUILD)

clean:  debug/clean  release/clean
fclean: debug/fclean release/fclean
re: $(BUILD)/re

$(call add/header_dep)

