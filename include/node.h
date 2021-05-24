/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   node.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/19 13:55:52 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/05/24 17:03:21 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODEE_H
# define NODEE_H

# include "checker.h"

t_node	*ps_node_new(int32_t number);
t_node	*ps_node_last_get(t_node **head);
t_node	*ps_node_unlink(t_node **head, t_node *node);
void	ps_node_front_add(t_node **head, t_node *new);
void	ps_node_back_add(t_node **head, t_node *new);
void	ps_node_inbetween_add(t_node *before, t_node *after, t_node *new);
void	ps_node_sortedstack_add(t_node **head, t_node *new);
void	ps_node_print(t_node **head);
size_t	ps_node_len(t_node **head);

#endif