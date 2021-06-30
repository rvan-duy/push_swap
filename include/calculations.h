/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calculations.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/24 15:16:53 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/06/30 16:50:11 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CALCULATIONS_H
# define CALCULATIONS_H

# include "structs.h"

void	ps_calculate_extra_small(t_node **stack_a);
void	ps_calculate_small(t_node **stack_a);
void	ps_calculate_medium(t_data *data);
void	ps_calculate_huge(t_data *data);

// Utilities
void	ps_calculate_rotate_bits(t_node **head, size_t len);
size_t	find_lowest_index_of_stack(t_node **head);
size_t	find_highest_index_of_stack(t_node **head);

#endif