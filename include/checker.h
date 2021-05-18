/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/14 12:36:42 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/05/18 16:21:01 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <stdio.h>

typedef struct s_node {
	struct s_node	*prev;
	int32_t			value;
	struct s_node	*next;
}	t_node;

// Node utils
t_node	*ps_stack_new(int32_t number);
void	ps_stack_front_add(t_node **head, t_node *new);
void	ps_stack_back_add(t_node **head, t_node *new);
t_node	*ps_stack_last_get(t_node **node);
void	ps_stack_print(t_node **head);
t_node	*ps_stack_unlink(t_node **head, t_node *node);

typedef struct s_data {
	size_t	element_count;
	t_node	*stack_a;
	t_node	*stack_b;
}	t_data;

void	ps_init(t_data *data, int32_t argc, char **argv);
void	*ps_calloc(size_t size);
void	ps_error(void);
void	ps_sorted_check(t_node **head);
void	ps_ints_swap(int32_t *a, int32_t *b);

// Operations
void	ps_operation_switch(t_node **head);
void	ps_operation_switch_both(t_node **dst, t_node **src);
void	ps_operation_push(t_node **dst, t_node **src);
void	ps_operation_rotate(t_node **head);
void	ps_operation_rotate_both(t_node **head1, t_node **head2);

#endif