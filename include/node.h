/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   node.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/19 13:55:52 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/05/19 14:26:50 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_H
# define NODE_H

# include "checker.h"

t_node	*ps_node_new(int32_t number);
t_node	*ps_node_last_get(t_node **node);
t_node	*ps_node_unlink(t_node **head, t_node *node);
void	ps_node_front_add(t_node **head, t_node *new);
void	ps_node_back_add(t_node **head, t_node *new);
void	ps_node_print(t_node **head);

#endif