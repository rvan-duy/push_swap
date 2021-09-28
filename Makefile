# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rvan-duy <rvan-duy@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/05/14 12:41:42 by rvan-duy      #+#    #+#                  #
#    Updated: 2021/09/28 20:19:07 by rvan-duy      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CHECKER		= checker
PUSH_SWAP	= push_swap
CC			= gcc
FLAGS		= -Wall -Wextra -Werror -g -fsanitize=address
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
	@printf "$(COLOR)Creating object files and the executable. ($(CHECKER))$(NOCOLOR)\n"
	@make -C libft
	@$(CC) $(FLAGS) $(HEADER) $(OBJ_CHECKER) $(OBJ_BOTH) $(LIBFT) -o $(CHECKER)
	@printf "$(COLOR)Done.$(NOCOLOR)\n"

$(PUSH_SWAP): $(OBJ_PUSH_SWAP) $(OBJ_BOTH)
	@printf "$(COLOR)Creating object files and the executable. ($(PUSH_SWAP))$(NOCOLOR)\n"
	@make -C libft
	@$(CC) $(FLAGS) $(HEADER) $(OBJ_PUSH_SWAP) $(OBJ_BOTH) $(LIBFT) -o $(PUSH_SWAP)
	@printf "$(COLOR)Done.$(NOCOLOR)\n"

.PHONY:	all clean fclean re debug

clean:
	@/bin/rm -f $(OBJ)
	@/bin/rm -f .DS_Store
	@/bin/rm -f a.out
	@printf "$(COLOR)Removing object files.$(NOCOLOR)\n"

fclean: clean
	@/bin/rm -f $(CHECKER) $(PUSH_SWAP)
	@/bin/rm -rf $(OBJ_DIR)
	@make fclean -C libft
	@printf "$(COLOR)Removing executable and object directories.$(NOCOLOR)\n"

re: fclean all

test: all
	@printf "$(COLOR)Testing...$(NOCOLOR)\n"
	./$(PUSH_SWAP) 0 1 2 | ./$(CHECKER) 0 1 2

py10: all
	python3 ./tester/pyviz.py `ruby -e "puts (0..98).to_a.shuffle.join(' ')"`
