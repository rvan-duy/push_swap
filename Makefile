# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rvan-duy <rvan-duy@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/05/14 12:41:42 by rvan-duy      #+#    #+#                  #
#    Updated: 2021/05/19 14:47:56 by rvan-duy      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	= checker
CC		= gcc
FLAGS	= -g -fsanitize=address -Wall -Wextra -Werror
UNUSED  = -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function
HEADER	= -I include
CHECKER	= checker/main.c \
			checker/ps_init.c \
			checker/ps_utils_1.c \
			operations/ps_operation_push.c \
			operations/ps_operation_rotate.c \
			operations/ps_operation_switch.c \
			operations/ps_operation_reverse_rotate.c \
			node/ps_node_back_add.c \
			node/ps_node_front_add.c \
			node/ps_node_last_get.c \
			node/ps_node_new.c \
			node/ps_node_print.c \
			node/ps_node_unlink.c
LIBFT 	= libft/libft.a

NOCOLOR = \033[0m
COLOR = \033[33m

OBJ_DIR	= \
	obj \
	obj/checker \
	obj/operations \
	obj/node

SRC		= $(addprefix src/, $(CHECKER))
OBJ		= $(SRC:src/%.c=obj/%.o)

all: $(NAME)

obj/%.o: src/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(UNUSED) $(HEADER) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(UNUSED) $(HEADER) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "$(COLOR)Creating object files and the executable. ($(NAME))$(NOCOLOR)"

.PHONY:	clean fclean re

clean:
	@/bin/rm -f $(OBJ)
	@/bin/rm -f .DS_Store
	@/bin/rm -f a.out
	@echo "$(COLOR)Removing object files.$(NOCOLOR)"

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -rf $(OBJ_DIR)
	@echo "$(COLOR)Removing executable and object directories.$(NOCOLOR)"

re: fclean all

test: clean all
	@echo "$(COLOR)Testing with basic test case.$(NOCOLOR)"
	./$(NAME) 0 1 2 3