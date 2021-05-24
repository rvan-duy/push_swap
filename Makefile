# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rvan-duy <rvan-duy@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/05/14 12:41:42 by rvan-duy      #+#    #+#                  #
#    Updated: 2021/05/24 14:39:18 by rvan-duy      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CHECKER		= checker
PUSH_SWAP	= push_swap
CC			= gcc
FLAGS		= -g -fsanitize=address -Wall -Wextra -Werror
UNUSED		= -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function
HEADER		= -I include
SRC_CHECKER	= checker.c
SRC_PUSH_SWAP = push_swap.c
SRC_BOTH	= utilities/ps_init.c utilities/ps_utils_1.c operations/ps_operation_push.c \
				operations/ps_operation_rotate.c operations/ps_operation_switch.c operations/ps_operation_reverse_rotate.c \
				node/ps_node_back_add.c node/ps_node_front_add.c node/ps_node_last_get.c node/ps_node_new.c node/ps_node_sortedstack_add.c \
				node/ps_node_print.c node/ps_node_unlink.c node/ps_node_len.c node/ps_node_inbetween_add.c operations/ps_operation_generate.c
LIBFT 	= libft/libft.a

NOCOLOR = \033[0m
COLOR = \033[32m

OBJ_DIR	= \
	obj \
	obj/utilities \
	obj/operations \
	obj/node

SRCS_CHECKER	= $(addprefix src/, $(SRC_CHECKER))
SRCS_PUSH_SWAP	= $(addprefix src/, $(SRC_PUSH_SWAP))
SRCS_BOTH		= $(addprefix src/, $(SRC_BOTH))
OBJ_CHECKER		= $(SRCS_CHECKER:src/%.c=obj/%.o)
OBJ_PUSH_SWAP 	= $(SRCS_PUSH_SWAP:src/%.c=obj/%.o)
OBJ_BOTH		= $(SRCS_BOTH:src/%.c=obj/%.o)

all: $(CHECKER) $(PUSH_SWAP)

obj/%.o: src/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) $(HEADER) -c $< -o $@

$(CHECKER): $(OBJ_CHECKER) $(OBJ_BOTH)
	@$(CC) $(FLAGS) $(HEADER) $(OBJ_CHECKER) $(OBJ_BOTH) $(LIBFT) -o $(CHECKER)
	@echo "$(COLOR)Creating object files and the executable. ($(CHECKER))$(NOCOLOR)"

$(PUSH_SWAP): $(OBJ_PUSH_SWAP) $(OBJ_BOTH)
	@$(CC) $(FLAGS) $(HEADER) $(OBJ_PUSH_SWAP) $(OBJ_BOTH) $(LIBFT) -o $(PUSH_SWAP)
	@echo "$(COLOR)Creating object files and the executable. ($(PUSH_SWAP))$(NOCOLOR)"

.PHONY:	all clean fclean re debug

clean:
	@/bin/rm -f $(OBJ)
	@/bin/rm -f .DS_Store
	@/bin/rm -f a.out
	@echo "$(COLOR)Removing object files.$(NOCOLOR)"

fclean: clean
	@/bin/rm -f $(CHECKER) $(PUSH_SWAP)
	@/bin/rm -rf $(OBJ_DIR)
	@echo "$(COLOR)Removing executable and object directories.$(NOCOLOR)"

re: fclean all

test: clean all
	@echo "$(COLOR)Testing with basic test case.$(NOCOLOR)"
	./$(PUSH_SWAP) 0 1 2 3