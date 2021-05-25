/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_operation_swap.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/19 13:22:24 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/05/25 17:39:46 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

/** 
 * Switches the first 2 nodes of head, does nothing
 * if there are only 1 or 0 nodes in head
 */
void	ps_operation_swap(t_node **head)
{
	t_node	*tmp;

	if (!*head || !(*head)->next)
		return ;
	tmp = (*head)->next;
	(*head)->next = tmp->next;
	tmp->next = *head;
	tmp->prev = (*head)->prev;
	(*head)->prev = tmp;
	*head = tmp;
}

/** 
 * Switches the first 2 nodes of head1 and head2, does nothing
 * if there are only 1 or 0 nodes in either one of the heads
 */
void	ps_operation_swap_both(t_node **head1, t_node **head2)
{
	ps_operation_swap(head1);
	ps_operation_swap(head2);
}
