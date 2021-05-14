/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/14 12:36:42 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/05/14 18:50:22 by rvan-duy      ########   odam.nl         */
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
t_node	*ps_stack_last(t_node *stack);
void	ps_stack_front_add(t_node **stack, t_node *new);
void	ps_stack_print(t_node **stack);

typedef struct s_data {
	size_t	element_count;
	t_node	*stack_a;
	t_node	*stack_b;
}	t_data;

void	ps_init(t_data *data, int32_t argc, char **argv);
void	*ps_calloc(void *ptr, size_t size);
void	ps_error(void);
void	ps_sorted_check(t_node **stack);

#endif