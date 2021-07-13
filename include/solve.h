/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/24 15:16:53 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/07/10 20:57:20 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVE_H
# define SOLVE_H

# include "structs.h"

# define ROTATE 0
# define REV_ROTATE 1
# define SOLVED 0

void	solve_extra_small(t_node **stack_a);
void	solve_small(t_node **stack_a);
void	solve_medium(t_data *data);
void	solve_huge(t_data *data);

size_t	find_lowest_index_of_stack(t_node **head);
size_t	find_highest_index_of_stack(t_node **head);
void	rotate_a_to_index(t_node **stack_a, size_t index, size_t stack_len);
int		calculate_fastest_route_to_index(t_node **stack, size_t index, \
										size_t stack_len);
void	push_top_b_to_a(t_data *data);

#endif