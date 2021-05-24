/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/14 12:36:42 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/05/24 17:14:43 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>

typedef struct s_node {
	struct s_node	*prev;
	int32_t			value;
	size_t			index;
	struct s_node	*next;
}	t_node;

typedef struct s_data {
	size_t	total_len;
	t_node	*stack_a;
	t_node	*stack_b;
	t_node	*sorted;
}	t_data;

void	ps_init(t_data *data, int32_t argc, char **argv);
void	*ps_calloc(size_t size);
void	ps_error(void);
void	ps_sorted_check(t_node **stack_a, t_node **stack_b);
void	ps_ints_swap(int32_t *a, int32_t *b);
int		ps_atoi(char *s);

#endif