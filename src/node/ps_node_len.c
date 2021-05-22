/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_node_len.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/20 13:38:10 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/05/20 14:12:28 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"

size_t	ps_node_len(t_node **head)
{
	t_node	*tmp;
	size_t	i;

	tmp = *head;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
