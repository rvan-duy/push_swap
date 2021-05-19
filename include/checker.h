/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/14 12:36:42 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/05/19 17:45:48 by rvan-duy      ########   odam.nl         */
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

typedef struct s_data {
	size_t	element_count;
	t_node	*stack_a;
	t_node	*stack_b;
}	t_data;

void	ps_init(t_data *data, int32_t argc, char **argv);
void	*ps_calloc(size_t size);
void	ps_error(void);
void	ps_sorted_check(t_node **stack_a, t_node **stack_b);
void	ps_ints_swap(int32_t *a, int32_t *b);

#endif