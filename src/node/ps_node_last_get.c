/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_node_last_get.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/19 14:04:18 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/05/19 14:26:14 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"

t_node	*ps_node_last_get(t_node **node)
{
	t_node	*tmp;

	tmp = *node;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}
