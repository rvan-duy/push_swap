# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rvan-duy <rvan-duy@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/05/14 12:41:42 by rvan-duy      #+#    #+#                  #
#    Updated: 2021/07/30 15:59:06 by rvan-duy      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CHECKER		= checker
PUSH_SWAP	= push_swap
CC			= gcc
FLAGS		= -Wall -Wextra -Werror -g
HEADER		= -I include
SRC_CHECKER	= checker.c
SRC_PUSH_SWAP = push_swap.c
SRC_BOTH	= utilities/init.c utilities/utils_1.c utilities/utils_2.c operations/operation_push.c \
				operations/operation_rotate.c operations/operation_swap.c operations/operation_rev_rotate.c \
				node/node_back_add.c node/node_front_add.c node/node_get_last.c node/node_new.c node/node_sortedstack_add.c \
				node/node_print.c node/node_unlink.c node/node_len.c node/node_inbetween_add.c operations/operation_generate.c \
				solve/solve_small.c solve/solve_extra_small.c solve/solve_huge.c \
				solve/solve_utilities_1.c solve/solve_medium.c solve/solve_utilities_2.c
LIBFT 	= libft/libft.a

NOCOLOR = \033[0m
COLOR = \033[32m

OBJ_DIR	= \
	obj \
	obj/utilities \
	obj/operations \
	obj/node \
	obj/solve

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
	@echo "$(COLOR)Creating object files and the executable. ($(CHECKER))$(NOCOLOR)"
	@make -C libft
	@$(CC) $(FLAGS) $(HEADER) $(OBJ_CHECKER) $(OBJ_BOTH) $(LIBFT) -o $(CHECKER)

$(PUSH_SWAP): $(OBJ_PUSH_SWAP) $(OBJ_BOTH)
	@echo "$(COLOR)Creating object files and the executable. ($(PUSH_SWAP))$(NOCOLOR)"
	@make -C libft
	@$(CC) $(FLAGS) $(HEADER) $(OBJ_PUSH_SWAP) $(OBJ_BOTH) $(LIBFT) -o $(PUSH_SWAP)

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

py10: all
	python3 ./tester/pyviz.py `ruby -e "puts (0..7).to_a.shuffle.join(' ')"`