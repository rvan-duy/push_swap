/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_node_last_get.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/19 14:04:18 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/05/20 13:43:11 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"

t_node	*ps_node_last_get(t_node **head)
{
	t_node	*tmp;

	tmp = *head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}
