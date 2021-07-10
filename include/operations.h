/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/19 13:14:22 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/07/10 20:28:03 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "structs.h"

void	operation_generate(t_data *data);

void	operation_swap(t_node **head, char *msg);
void	operation_swap_both(t_node **head1, t_node **head2, char *msg);
void	operation_push(t_node **dst, t_node **src, char *msg);
void	operation_rotate(t_node **head, char *msg);
void	operation_rotate_both(t_node **head1, t_node **head2, char *msg);
void	operation_rev_rotate(t_node **head, char *msg);
void	operation_rev_rotate_both(t_node **head1, t_node **head2, char *msg);

#endif