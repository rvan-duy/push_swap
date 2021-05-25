/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/19 13:14:22 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/05/25 16:55:35 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "checker.h"

void	ps_operation_generate(t_data *data);

void	ps_operation_swap(t_node **head);
void	ps_operation_swap_both(t_node **dst, t_node **src);
void	ps_operation_push(t_node **dst, t_node **src);
void	ps_operation_rotate(t_node **head);
void	ps_operation_rotate_both(t_node **head1, t_node **head2);
void	ps_operation_reverse_rotate(t_node **head);
void	ps_operation_reverse_rotate_both(t_node **head1, t_node **head2);

#endif