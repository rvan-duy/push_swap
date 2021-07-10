/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calculations.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/24 15:16:53 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/07/10 20:28:03 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CALCULATIONS_H
# define CALCULATIONS_H

# include "structs.h"

void	calculate_extra_small(t_node **stack_a);
void	calculate_small(t_node **stack_a);
void	calculate_medium(t_data *data);
void	calculate_huge(t_data *data);

// Utilities
void	calculate_rotate_bits(t_node **head, size_t len);
size_t	find_lowest_index_of_stack(t_node **head);
size_t	find_highest_index_of_stack(t_node **head);

#endif