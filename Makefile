# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rvan-duy <rvan-duy@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/05/14 12:41:42 by rvan-duy      #+#    #+#                  #
#    Updated: 2021/05/19 17:55:39 by rvan-duy      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CHECKER		= checker
PUSH_SWAP	= push_swap
CC			= gcc
FLAGS		= -g -fsanitize=address -Wall -Wextra -Werror
UNUSED		= -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function
HEADER		= -I include
SRC_CHECKER	= checker/main.c
SRC_PUSH_SWAP = push_swap.c
SRC_BOTH	= checker/ps_init.c checker/ps_utils_1.c operations/ps_operation_push.c \
				operations/ps_operation_rotate.c operations/ps_operation_switch.c operations/ps_operation_reverse_rotate.c \
				node/ps_node_back_add.c node/ps_node_front_add.c node/ps_node_last_get.c node/ps_node_new.c \
				node/ps_node_print.c node/ps_node_unlink.c
LIBFT 	= libft/libft.a

NOCOLOR = \033[0m
COLOR = \033[33m

OBJ_DIR	= \
	obj \
	obj/checker \
	obj/operations \
	obj/node

SRC		=	$(addprefix src/, $(SRC_CHECKER))
SRCS_PUSH_SWAP = $(addprefix src/, $(SRC_PUSH_SWAP))
OBJ		= $(SRC:src/%.c=obj/%.o)
OBJ_PUSH_SWAP = $(SRCS_PUSH_SWAP:src/%.c=obj/%.o)

all: $(CHECKER)

obj/%.o: src/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(UNUSED) $(HEADER) -c $< -o $@

$(CHECKER): $(OBJ)
	@$(CC) $(UNUSED) $(HEADER) $(OBJ) $(LIBFT) -o $(CHECKER)
	@echo "$(COLOR)Creating object files and the executable. ($(CHECKER))$(NOCOLOR)"

$(PUSH_SWAP): $(OBJ_PUSH_SWAP)
	$(CC) $(UNUSED) $(HEADER) $(OBJ_PUSH_SWAP) $(LIBFT) -o $(PUSH_SWAP)

.PHONY:	clean fclean re

clean:
	@/bin/rm -f $(OBJ)
	@/bin/rm -f .DS_Store
	@/bin/rm -f a.out
	@echo "$(COLOR)Removing object files.$(NOCOLOR)"

fclean: clean
	@/bin/rm -f $(CHECKER)
	@/bin/rm -rf $(OBJ_DIR)
	@echo "$(COLOR)Removing executable and object directories.$(NOCOLOR)"

re: fclean all

test: clean all
	@echo "$(COLOR)Testing with basic test case.$(NOCOLOR)"
	./$(CHECKER) 0 1 2 3

push_swap: $(PUSH_SWAP)