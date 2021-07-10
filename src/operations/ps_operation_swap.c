/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_operation_swap.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/19 13:22:24 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/07/10 19:04:56 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "libft.h"

/** 
 * Switches the first 2 nodes of head, does nothing
 * if there are only 1 or 0 nodes in head
 */
void	ps_operation_swap(t_node **head, char *msg)
{
	t_node	*tmp;

	if (!*head || !(*head)->next)
		return ;
	tmp = (*head)->next;
	(*head)->next = (*head)->next->next;
	(*head)->next->prev = (*head);
	(*head)->prev = (*head)->next;
	tmp->prev = NULL;
	tmp->next = (*head);
	(*head) = tmp;
	if (msg != NULL)
		ft_putendl_fd(msg, 1);
}

/** 
 * Switches the first 2 nodes of head1 and head2, does nothing
 * if there are only 1 or 0 nodes in either one of the heads
 */
void	ps_operation_swap_both(t_node **head1, t_node **head2, char *msg)
{
	ps_operation_swap(head1, NULL);
	ps_operation_swap(head2, NULL);
	if (msg != NULL)
		ft_putendl_fd(msg, 1);
}
