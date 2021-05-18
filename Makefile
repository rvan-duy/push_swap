# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rvan-duy <rvan-duy@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/05/14 12:41:42 by rvan-duy      #+#    #+#                  #
#    Updated: 2021/05/17 16:11:43 by rvan-duy      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	= checker
CC		= gcc
FLAGS	= -g -fsanitize=address -Wall -Wextra -Werror
UNUSED  = -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function
HEADER	= -I include
CHECKER	= main.c \
			ps_init.c \
			ps_utils_1.c \
			ps_node_utils.c \
			ps_operations_1.c
LIBFT 	= libft/libft.a

NOCOLOR = \033[0m
COLOR = \033[33m

SRC_DIR	= \
		$(addprefix checker/, $(CHECKER))

OBJ_DIR	= \
	obj \
	obj/checker

SRC		= $(addprefix src/, $(SRC_DIR))
OBJ		= $(SRC:src/%.c=obj/%.o)

all: $(NAME)

obj/%.o: src/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(UNUSED) $(HEADER) -c $< -o $@

$(NAME): $(OBJ)
	@$(CC) $(UNUSED) $(HEADER) $(OBJ) $(LIBFT) -o $(NAME)
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